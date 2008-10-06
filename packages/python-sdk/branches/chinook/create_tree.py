#!/usr/bin/python
# Copyright (C) 2006 INdT.
#
# Contact: Luciano Miguel Wolf <luciano.wolf@indt.org.br>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA

''' create source tree & build pymaemo packages '''
__revision__ = 'r'+'$Revision$'

from ConfigParser import ConfigParser
from optparse import OptionParser
from commands import getstatusoutput
from types import ListType
import os, sys, re, urllib, urlparse, tarfile, zipfile, shutil
from cStringIO import StringIO

#Some global definitions
config_file = 'packages.ini'
sources_dir = 'source_packages/'
debs_dir = 'deb_packages'
quiltrc = '.quiltrc'
tmp_dir = sources_dir+'tmp_dir/'

# return codes
OK               =  0
ERR_UNKNOWN_NAME =  1

class BuildException(Exception):
    ''' Handles build exceptions '''

    def __init__(self, msg, code):
        ''' Constructor. Stores error message. '''
        Exception.__init__(self)
        self.msg = msg
        self.code = code

    def __str__(self):
        ''' Returns the message '''
        return self.msg

    def exitcode(self):
        ''' Returns exeption code '''
        return self.code


def get_build_depends(directory):
    ''' Returns unmet build dependencies. '''

    controlfile = os.path.join(directory, 'debian', 'control')
    status, message = getstatusoutput('dpkg-checkbuilddeps %s' % controlfile)
    message = message[message.rfind(':')+2:]
    
    return re.findall('\s*(\w[\.\w-]*)(?:\s\(.*?\))?', message)

def is_installable(packagename):
    status, message = getstatusoutput('apt-cache show %s' % packagename)
    return not ('No packages found' in message or message == '')

def install_system_packages(packagelist):
    pkgs = ' '.join([pkg for pkg in packagelist if is_installable(pkg)])
    run_command('fakeroot apt-get --yes --force-yes install %s' % pkgs)

def run_command(command, directory = None, force = False):
    ''' Runs command. Chdir to directory if specified '''

    if directory:
        savedir = os.getcwd()
        os.chdir(directory)

    status = getstatusoutput(command)

    if directory:
        os.chdir(savedir)

    if status[0] and not force:
        print status[1]
        raise BuildException('Error running command %s\nExit code: %d' 
                % (command, status[0]), status[0])

def chksectlst(lst, sections):
    '''Check if list contains valid section names'''

    unknown = [sect for sect in lst if sect not in sections]
    if unknown:
        raise BuildException('Unknown section name[s]: %s' % \
                ', '.join(unknown), ERR_UNKNOWN_NAME)

def read_cfg_file(conf_file, options):
    '''Read ini file that contains all the packages to be generated, 
    ordered by dependencies.'''

    config = ConfigParser()
    config.read(conf_file)

    config.special = ['build-order']

    if options.skip:
        skiplist = [name.strip() for name in options.skip.split(',')]
        chksectlst(skiplist, config.sections())
        [config.remove_section(section) for section in skiplist]

    if options.only:
        onlylist = [name.strip() for name in options.only.split(',')]
        chksectlst(onlylist, config.sections())
        [config.remove_section(section) for section in config.sections() \
                 if section not in onlylist and section not in config.special]

    return config

def read_name_and_version(module):
    '''Read debian/changelog file to get module name and version'''

    chlog = open(os.path.join(module, 'debian', 'changelog'))
    result = re.match('([^ ]+) \(([^)]+)\).*', chlog.readline())
    chlog.close()

    module_name = result.group(1)
    module_version = result.group(2)

    return module_name, module_version

def download_from_svn(config, section):
    '''Download all necessary information from svn repository. Modules can 
    contain only patches or the entire source tree (only projects without
    source.tar.gz in another site - e.g.: python-hildon). After downloading, 
    the directory is moved inside source tree (if its just patch) or the 
    directory is renamed to the correct module name.'''

    if config.has_option(section, 'source_url'):
        old_dir_name = 'debian'
        path_to_test = os.path.join(section, 'debian', 'patches')
    else:
        old_dir_name = 'trunk'
        path_to_test = section

    if os.path.exists(path_to_test):
        print 'Running svn update inside %s module' % (section)
        run_command('svn up ' + path_to_test)
    else:
        if old_dir_name == 'trunk':
            target = section
        else:
            target = section + '/debian'

        svn_url = config.get(section, 'svn_url')
        print 'Running svn checkout of %s module' % (section)
        run_command('svn co %s %s' % (svn_url, target))

def extract( filename, dir ):
    '''Extracts zip file 'filename' to 'dir'. This function is a copy/paste from Python Cookbook: 
       http://aspn.activestate.com/ASPN/Cookbook/Python/Recipe/465649'''
    zf = zipfile.ZipFile( filename )
    namelist = zf.namelist()
    dirlist = filter( lambda x: x.endswith( '/' ), namelist )
    filelist = filter( lambda x: not x.endswith( '/' ), namelist )
    # make base
    pushd = os.getcwd()
    if not os.path.isdir( dir ):
        os.mkdir( dir )
    os.chdir( dir )
    # create directory structure
    dirlist.sort()
    for dirs in dirlist:
        dirs = dirs.split( '/' )
        prefix = ''
        for dir in dirs:
            dirname = os.path.join( prefix, dir )
            if dir and not os.path.isdir( dirname ):
                os.mkdir( dirname )
            prefix = dirname
    # extract files
    for fn in filelist:
        out = open( fn, 'wb' )
        buffer = StringIO( zf.read( fn ))
        buflen = 2 ** 20
        datum = buffer.read( buflen )
        while datum:
            out.write( datum )
            datum = buffer.read( buflen )
        out.close()
    os.chdir( pushd )

def download_source_package(config, section):
    '''Download tar.gz files from websites listed in config file 
       and put them into source_packages directory'''

    url = config.get(section, 'source_url')
    tarball = os.path.basename(urlparse.urlparse(url)[2])
    tarballpath = sources_dir + tarball

    '''Verify if the source file is a .zip'''
    extension = tarball[-4:]

    #replace the last '-' character with '_'
    origtarball = re.sub('(.*)-', '\\1_', section)+'.orig.tar.gz'

    if not os.access(tarballpath, os.R_OK):
        print 'Downloading %s ...' % tarball
        urllib.urlretrieve(url, tarballpath)
    else:
        print 'file %s already downloaded, skipping' % tarball

    if not os.path.exists(origtarball):
        if (extension == '.zip'):
            '''Extract the .zip and compact as .tar.gz'''
            if os.path.isdir(tmp_dir):
                shutil.rmtree(tmp_dir)
            os.mkdir(tmp_dir)
            extract(tarballpath, tmp_dir)
            tarf = tarfile.open(tarballpath[:-5] + 'tar.gz', 'w:gz')
            pushd = os.getcwd()
            os.chdir(tmp_dir)
            for member in os.listdir("."):
                tarf.add(member)
            tarf.close()
            os.chdir(pushd)
            shutil.rmtree(tmp_dir)
            tarball = tarball[:-5] + 'tar.gz'
            tarballpath = sources_dir + tarball
        shutil.copy(tarballpath, origtarball)

    # unpack only if not unpacked yet
    if not os.path.isdir(section):
        tarf = tarfile.open(origtarball)
        for member in tarf:
            tarf.extract(member)
        os.rename(tarf.getnames()[0], section)
        tarf.close()

def download_debsrc_package(config, section):
    dscurl = config.get(section, 'debsrc_url')
    dscfile = os.path.basename(urlparse.urlsplit(dscurl)[2])

    result = re.match('([^ ]+)-(.+).dsc', dscfile)
    pkgname = result.group(1)
    revision = result.group(2)

    tarfile = '%s.orig.tar.gz' % pkgname
    difffile = '%s-%s.diff.gz' % (pkgname, revision)

    for f in (dscfile, tarfile, difffile):
        if not os.access(sources_dir + f, os.R_OK):
            print 'Downloading %s ...' % f
            urllib.urlretrieve(urlparse.urljoin(dscurl, f), sources_dir + f)
        else:
            print 'file %s already downloaded, skipping' % f
        shutil.copy(sources_dir + f, f)

    print 'Running dpkg-source on %s module' % (section)
    run_command('dpkg-source -x %s' % dscfile)

def apply_patches(package_name):
    '''reapply the patches'''

    run_command('quilt pop -a --quiltrc ../'+quiltrc, package_name, force = True)
    run_command('quilt push -a --quiltrc ../'+quiltrc, package_name)

def get_debs(control, arch, version):
    '''Get debian package names from control file'''

    if type(control) != ListType:
        controlf = open(control)
        control = controlf.readlines()
        controlf.close()

    debs = []
    for line in control:
        if line.find('Package:') > -1:
            package = line.replace('Package:', '').strip()
        elif line.find('Architecture:') > -1:
            file_arch = line.replace('Architecture:', '').strip()
            if file_arch == 'any':
                package_arch = arch
            else:
                package_arch = 'all'
            deb_file = '_'.join([package, version, package_arch])+'.deb'
            if os.path.exists(deb_file):
                debs.append(deb_file.strip())

    return debs

def build_packages(config):
    '''Create all deb files'''

    status = getstatusoutput('dpkg-architecture -qDEB_BUILD_ARCH')
    if status[0]:
        raise BuildException(
                'Error determining dpkg architecture, errcode = %d' % \
                status[0], status[0])
    arch = status[1]

    targetdir = os.path.join(debs_dir, arch)

    if not os.path.exists(targetdir):
        os.makedirs(targetdir)

    build_order = config.get('build-order', 'order').split(',')

    for module in build_order:

        if module not in config.sections():
            continue

        print '\n===== Building module %s ======' % module
        if os.path.exists(module+'-'+arch+'-stamp'):
            print 'module is already built, skipping'
            continue

        dependencies = get_build_depends(module)
        if dependencies:
            print '* installing build dependencies'
            install_system_packages(dependencies)

        print '* building module'
        if arch == 'armel':
            run_command(
            'dpkg-buildpackage -rfakeroot -sa -tc -I.pc -i.pc -us -uc',
            module)
        else:
            run_command(
            'dpkg-buildpackage -rfakeroot -B -sa -tc -I.pc -i.pc -us -uc',
            module)

        module_name, module_version = read_name_and_version(module)

        name_version = '_'.join([module_name, module_version])
        changes = '_'.join([name_version, arch]) + '.changes'

        # get list of deb files
        files = get_debs(os.path.join(module, 'debian', 'control'),
                         arch, module_version)

        # install them
        run_command('fakeroot dpkg -i -G ' + ' '.join(files))

        # add .dsc, and source tarball/diff.gz to the list
        files.append(name_version + '.dsc')
        files.append(changes)

        orig_file = '_'.join([module_name, \
                            module_version.split('-')[0]])+'.orig.tar.gz'
        if os.path.exists(orig_file):
            shutil.copy(orig_file, targetdir)
            files.append(name_version+'.diff.gz')
        else:
            files.append(name_version+'.tar.gz')

        # move package files to deb_packages directory
        for fname in files:
            if os.path.exists(fname):
                shutil.move(fname, targetdir)

        # touch stamp
        open(module+'-'+arch+'-stamp', 'w').close()

def create_tree(config):
    '''Process all packages listed in config file, to create 
    and patch the source tree.'''

    if not os.path.exists(sources_dir):
        os.mkdir(sources_dir)

    for section in config.sections():
        if section not in config.special:
            print '\n==== section %s ====' % section
            if config.has_option(section, 'debsrc_url'):
                download_debsrc_package(config, section)
                continue

            if config.has_option(section, 'source_url'):
                download_source_package(config, section)

            if config.has_option(section, 'svn_url'):
                download_from_svn(config, section)

            if config.has_option(section, 'source_url') and \
               os.path.isdir(os.path.join(section, 'debian', 'patches')):
                apply_patches(section)

def parsecommandline(argv):
    ''' Commandline parser '''

    parser = OptionParser(usage = '%prog [options]')

    parser.add_option('--only-create', action='store_true', dest='onlycreate',
             help='only create source tree, don\'t build packages')
    parser.add_option('--only-build', action='store_true', dest='onlybuild',
             help='only build packages, don\'t create/update source tree')
    parser.add_option('--skip', type='string', dest='skip',
             help='skip section[s]', metavar='<list>')
    parser.add_option('--only', type='string', dest='only',
             help='process only specified section[s]', metavar='<list>')

    (opts, _) = parser.parse_args(argv)

    return opts

def main(argv = None):
    '''Construct python for maemo source tree, with all modules 
    contained in packages.ini config file'''

    if argv is None:
        argv = sys.argv

    # Parsing commandline
    options = parsecommandline(argv)

    try:
        config = read_cfg_file(config_file, options)

        if not options.onlybuild:
            create_tree(config)

        if not options.onlycreate:
            build_packages(config)

    except BuildException, exobj:
        print exobj
        return exobj.exitcode()

    return OK

if __name__ == '__main__':
    sys.exit(main())

# vim:ts=4:sw=4:et:sm:ai

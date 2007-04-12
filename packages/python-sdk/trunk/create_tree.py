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
import os, sys, re, urllib, urlparse, tarfile, shutil

#Some global definitions
config_file = 'packages.ini'
sources_dir = 'source_packages/'
debs_dir = 'deb_packages'
quiltrc = '.quiltrc'
OK     =  0

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

def read_cfg_file(conf_file):
    '''Read ini file that contains all the packages to be generated, 
    ordered by dependencies.'''

    config = ConfigParser()
    config.read(conf_file)

    return config

def download_from_svn(config, section):
    '''Download all necessary information from svn repository. Modules can 
    contain only patches or the entire source tree (only projects without
    source.tar.gz in another site - e.g.: python-hildon). After downloading, 
    the directory is moved inside source tree (if its just patch) or the 
    directory is renamed to the correct module name.'''

    if config.has_option(section, 'source_url'):
        old_dir_name = 'debian'
        path_to_test = section+'/debian/patches'
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
            target = section+'/debian'

        svn_url = config.get(section, 'svn_url')
        print 'Running svn checkout of %s module' % (section)
        run_command('svn co %s %s' % (svn_url, target))

def download_source_package(config, section):
    '''Download tar.gz files from websites listed in config file 
       and put them into source_packages directory'''

    url = config.get(section, 'source_url')
    tarball = os.path.basename(urlparse.urlparse(url)[2])
    tarballpath = sources_dir + tarball
    origtarball = section+'.orig.tar.gz'#includes release, tar.gz and tgz
    origtarball = origtarball.replace('-', '_')

    if not os.access(tarballpath, os.R_OK):
        print 'Downloading %s ...' % tarball
        urllib.urlretrieve(url, tarballpath)
    else:
        print 'file %s already downloaded, skipping' % tarball

    if not os.path.exists(origtarball):
        shutil.copy(tarballpath, origtarball)

    # unpack only if not unpacked yet
    if not os.path.isdir(section):
        tarf = tarfile.open(origtarball)
        for member in tarf:
            tarf.extract(member)
        os.rename(tarf.getnames()[0], section)
        tarf.close()

def apply_patches(package_name):
    '''reapply the patches'''
    run_command('quilt pop -a --quiltrc ../'+quiltrc, package_name, force = True)
    run_command('quilt push -a --quiltrc ../'+quiltrc, package_name)

def build_packages(config):
    '''Create all deb files'''

    status = getstatusoutput('dpkg-architecture -qDEB_BUILD_ARCH')
    if status[0]:
        raise BuildException(
                'Error determining dpkg architecture, errcode = %d' % \
                status[0], status[0])
    arch = status[1]

    targetdir = debs_dir+'/'+arch

    if not os.path.exists(targetdir):
        os.makedirs(targetdir)

    build_order = config.get('build-order', 'order').split(',')

    for module in build_order:
        print '\n===== Building module %s ======' % module
        if os.path.exists(module+'-'+arch+'-stamp'):
            print 'module is already built, skipping'
            continue
        if arch == 'armel':
            run_command(
            'dpkg-buildpackage -rfakeroot -sa -tc -I.pc -i.pc -us -uc'\
            , module)
        else:
            run_command(
            'dpkg-buildpackage -rfakeroot -B -sa -tc -I.pc -i.pc -us -uc'\
            , module)

        # get package name and version from last changelog entry           
        chlog = open(module+'/debian/changelog')
        result = re.match('([^ ]+) \(([^)]+)\).*', chlog.readline())
        chlog.close()

        # make name of changes file
        changes = '_'.join([result.group(1), result.group(2), arch])+'.changes'
        changesf = open(changes)
        lines = changesf.readlines()
        changesf.close()

        # check if it contains section 'Files:'
        if not [line for line in lines if line.strip() == 'Files:']:
            all_arch_file = 'python2.5-'+(changes.replace('i386','all')).replace('changes','deb')
            lines = ['Files:', all_arch_file]
            if not os.path.exists(all_arch_file):
                continue

        # Put section 'Files:' on top of the list
        lines.reverse()

        debs_to_install = ''
        for line in lines:
            if line.strip() == 'Files:':
                break
            else:
                # process 'Files:' section
                fname = line.strip().split(' ')[-1]
                if fname.endswith('.deb'):
                    debs_to_install += fname+' '
                elif not fname.endswith('.orig.tar.gz'):
                    shutil.move(fname, targetdir)
                else:
                    shutil.copy(fname, targetdir)

        run_command('fakeroot dpkg -i ' + debs_to_install)
        files = debs_to_install.strip().split()
        for file in files:
            shutil.move(file, targetdir)

        shutil.move(changes, targetdir)

        # touch stamp
        open(module+'-'+arch+'-stamp', 'w').close()

def create_tree(config):
    '''Process all packages listed in config file, to create 
    and patch the source tree.'''

    if not os.path.exists(sources_dir):
        os.mkdir(sources_dir)

    for section in config.sections():
        print '\n==== section %s ====' % section
        if config.has_option(section, 'source_url'):
            download_source_package(config, section)

        if config.has_option(section, 'svn_url'):
            download_from_svn(config, section)

        if config.has_option(section, 'source_url'):
            apply_patches(section)

def parsecommandline(argv):
    ''' Commandline parser '''

    parser = OptionParser (usage = '%prog [options]')

    parser.add_option('--only-create', action='store_true', dest='onlycreate',
             help='only create source tree, don\'t build packages')
    parser.add_option('--only-build', action='store_true', dest='onlybuild',
             help='only build packages, don\'t create/update source tree')

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
        config = read_cfg_file(config_file)
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

from ConfigParser import *
import string
import os
import sys

#Some global definitions
config_file = 'packages.ini'
sources_dir = 'source_packages'
debs_dir = 'deb_packages'

#TODO: - verify error conditions

def read_cfg_file(config_file):
    '''Read ini file that contains all the packages to be generated, ordered by dependencies.'''

    config = ConfigParser()
    config.read(config_file)
    return config

def download_from_svn(config, section):
    '''Download all necessary information from svn repository. Modules can contain only patches or the
       entire source tree (only projects without source.tar.gz in another site - e.g.: python-hildon).
       After downloading, the directory is moved inside source tree (if its just patch) or the directory
       is renamed to the correct module name.'''

    if config.has_option(section, 'source_url'):
        old_dir_name = 'debian'
        path_to_test = section+'/debian/patches'
    else:
        old_dir_name = 'trunk'
        path_to_test = section
        
    if os.path.exists(path_to_test):
        print 'Running svn update inside %s module' % (section)
        status = os.popen('cd '+path_to_test+' && svn up')
        print status
        return

    svn_url = config.get(section, 'svn_url')
    print 'Running svn checkout of %s module' % (section)
    status = os.popen('svn co ' + svn_url)
    print status.read()

    new_dir_name = section
    status = os.popen('mv ' + old_dir_name + ' ' + new_dir_name)
    print status.read()

def download_source_package(config, section):
    '''Download tar.gz files from websites listed in config file and put them in source_packages directory'''

    package_name = config.get(section, 'package_name')
    source_url = config.get(section, 'source_url') + package_name
    old_dir_name = config.get(section, 'source_dir_name')
    new_dir_name = section

    #TODO: Improve this. It runs tar xf and only checks if its possible to move after this.
    status = os.popen('cd '+sources_dir+' && wget -c -nc '+source_url+' && tar xf '+package_name+' && mv '+old_dir_name+' ../'+new_dir_name)
    print status.read()
    if os.path.exists(sources_dir+'/'+old_dir_name):
        status = os.popen('rm -rf '+sources_dir+'/'+old_dir_name)
        print status

def apply_patches(package_name):
    '''Apply the patches when necessary'''

    status = os.popen('cd '+package_name+' && quilt push -a --quiltrc ../quiltrc')
    print status

def compile(config):
    '''Create all deb files'''

    status = os.popen('dpkg-architecture -qDEB_BUILD_ARCH')
    arch_dir = status.read()

    if not os.path.exists(debs_dir+'/'+arch_dir):
        status = os.popen('mkdir -p ' + debs_dir + '/' + arch_dir)
        print status.read()
        
    build_order = config.get('build-order', 'order').split(',')
    
    for module in build_order:
        status = os.popen('cd '+module+' && dpkg-buildpackage -rfakeroot -sa -tc -I.pc -i.svn -us -uc')
        print status.read()
        status = os.popen('dpkg -i *.deb')
        print status.read()
        status = os.popen('mv *.dsc *.changes *.tar.gz *.deb '+debs_dir+'/'+arch_dir)
        print status.read()
    #TODO: Test if deb package has been generated. If not, stop the 'for' loop.

def create_tree(config):
    '''Process all packages listed in config file, to create the source tree, patch it and generate debian packages.'''

    if not os.path.exists(sources_dir):
        status = os.popen('mkdir '+sources_dir)
        print status

    for section in config.sections():
        print section
        if section != 'build-order':
            apply = 'No'
            if config.has_option(section, 'source_url'):
                download_source_package(config, section)
                apply = 'Yes'
            download_from_svn(config, section)
            if apply == 'Yes':
                apply_patches(section)

def main():
    '''Construct python for maemo source tree, with all modules contained in packages.ini config file'''

    config = read_cfg_file(config_file)
    create_tree(config)
    compile(config)

if __name__ == '__main__':
    main()

# vim:ts=4:sw=4:et:sm:ai

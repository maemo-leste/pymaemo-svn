from ConfigParser import *
import string
import os
import sys

#TODO: verify error conditions

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

    if os.path.exists(section):
        print 'There is a(n) section package already created!'
        return

    svn_url = config.get(section, 'svn_url')
    status = os.popen('svn co ' + svn_url)
    print status.read()

    if config.has_option(section, 'source_url'):
        old_dir_name = 'debian'
    else:
        old_dir_name = 'trunk'
    new_dir_name = section
    status = os.popen('mv ' + old_dir_name + ' ' + new_dir_name)
    print status.read()

def download_source_package(config, section):
    '''Download tar.gz files from websites listed in config file.'''

    package_name = config.get(section, 'package_name')
    source_url = config.get(section, 'source_url') + package_name
    old_dir_name = config.get(section, 'source_dir_name')
    new_dir_name = section

    status = os.popen('wget -c -nc '+source_url+' && tar xf '+package_name+' && mv '+old_dir_name+' '+new_dir_name)
#    status = os.popen('mv '+package_name+' sources && ln -s sources/+'package_name'+' orig')

def apply_patches(package_name):
    '''Apply the patches when necessary'''

    status = os.popen('cd '+package_name+' && quilt push -a --quiltrc ../quiltrc')

def compile(config):
    '''Create all deb files'''

    for section in config.sections():
        status = os.popen('cd '+section+' && echo dpkg && dpkg-buildpackage -rfakeroot -sa -tc -I.pc -i.svn -us -uc')
        print status.read()

def create_tree(config):
    '''Process all packages listed in config file, to create the source tree, patch it and generate debian packages.'''

    status = os.popen('mkdir sources')
    for section in config.sections():
        print section
        apply = 'No'
        if config.has_option(section, 'source_url'):
            download_source_package(config, section)
            apply = 'Yes'
        download_from_svn(config, section)
        if apply == 'Yes':
            apply_patches(section)

def main():
    '''Construct python for maemo source tree, with all modules contained in packages.ini config file'''

    config = read_cfg_file('packages.ini')   
    create_tree(config)
    compile(config)

if __name__ == '__main__':
    main()

# vim:ts=4:sw=4:et:sm:ai

from ConfigParser import *
import string
import os
import sys

def read_cfg_file(config_file):
    config = ConfigParser()
    config.read(config_file)
    return config

def download_from_svn(config, section):
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
    package_name = config.get(section, 'package_name')
    source_url = config.get(section, 'source_url') + package_name
    old_dir_name = config.get(section, 'source_dir_name')
    new_dir_name = section

    status = os.popen('wget -c -nc '+source_url+' && tar xf '+package_name+' && mv '+old_dir_name+' '+new_dir_name)
#    status = os.popen('mv '+package_name+' sources && ln -s sources/+'package_name'+' orig')

def apply_patches(package_name):
    status = os.popen('cd '+package_name+' && quilt push -a --quiltrc ../quiltrc')

#def compile():
#    dpkg-buildpackage -rfakeroot -sa -tc -I.pc -us -uc (armel)

def create_tree(config):
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
    config = read_cfg_file("packages.ini")   
    create_tree(config)

if __name__ == "__main__":
    main()

# vim:ts=4:sw=4:et:sm:ai

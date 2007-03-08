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

    if config.has_option(section, 'package_url'):
        old_dir_name = config.get(section, 'package_url') 
    else:
        old_dir_name = 'trunk'
    new_dir_name = section
    status = os.popen('mv ' + old_dir_name + ' ' + new_dir_name)
    print status.read()

def create_tree(config):
    for section in config.sections():
        print section
        if config.has_option(section, 'package_url'):
            for option in config.options(section):
                print ' ', option, '=', config.get(section, option)
        else:
            download_from_svn(config, section)

def main():
    config = read_cfg_file("packages.ini")   
    create_tree(config)

if __name__ == "__main__":
    main()

# vim:ts=4:sw=4:et:sm:ai

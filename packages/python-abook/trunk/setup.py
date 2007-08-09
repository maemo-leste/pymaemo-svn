from distutils.core import setup, Extension
from distutils.command.build import build
from distutils.cmd import Command
import subprocess
import os
import sys

datadir = '/usr/share'
defsdir = datadir+'/pygtk/2.0/defs'
includedir = '/usr/include'

def get_includes(package_name):
    """
    Use to get a list of include dirs from pkg-config

    Arguments:
    package_name - The name of the target package

    Returns:
    A list of strings with the include directories.
    """

    args = ["pkg-config", "--cflags", package_name]
    proc = subprocess.Popen(
        args,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    
    cmdresult = proc.stdout
    error = proc.stderr
    
    if cmdresult:
        result = cmdresult.read()
        includes = [x[2:] for x in result.split()] # Strip the -I
        return includes
        
    return []

def gen_auto_file(filename, subproc_args):
    proc = subprocess.Popen(
        subproc_args,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    #cmdresult = proc.stdout
    #error = proc.stderr
    cmdresult, error = proc.communicate()
    #Print disabled to avoid problems with scratchbox
    print error
    if cmdresult:
        new_file = open(filename, 'w')
        new_file.write(cmdresult)
        new_file.close()


class PyABookBuild(build):
    def run(self):
        # Generate enum/flags run-time information

        # TODO Replace conic headers with abook ones
        prefix = includedir+'/osso-addressbook-1.0/libosso-abook/'
        ABOOK_TYPE_FILES = [ prefix + x for x in os.listdir(prefix)]
        gen_auto_file('abook/abook-types.h.in', ['/bin/sh', './gen-enum-h']+ABOOK_TYPE_FILES)
        gen_auto_file('abook/abook-types.c.in', ['/bin/sh', './gen-enum-c']+ABOOK_TYPE_FILES)

        # Creation of ".c" files, using pygtk-codegen-2.0
        override_filename = 'abook/abook.override'
        defs_filename = 'abook/abook.defs'

        parameter = [
            '--register', defsdir+'/gdk.defs',
            '--register', defsdir+'/gtk-types.defs',
            '--register', '/usr/share/evolution-python/defs/ebook.defs',
            '--register', defsdir+'/pango-types.defs',
            '--register', defsdir+'/galago.defs',
            '--override', override_filename,
            '--prefix', 'pyabook',
            defs_filename,
        ] 
        gen_auto_file('abook/abook.c', ['/bin/sh', 'pygtk-codegen-2.0']+parameter)

        build.run(self)
        
compile_args = [
        '-Os',
        '-DXTHREADS',
        '-DXUSE_MTSAFE_API',
#        '-ansi',
#        '-pedantic',
#        '-Wno-long-long',
#        '-g',
#        '-rdynamic',
]

# Using get_includes plus pygtk headers
abook = Extension('abook',
    sources = [
        'abook/abook.c',
        'abook/abookmodule.c',
        'abook/abook-types.c',
    ],
    libraries = [
        'osso-abook-1.0',
        'dbus-1',
                'dbus-glib-1',
                'glib-2.0',
                'gobject-2.0',
    ],
    include_dirs = get_includes("osso-addressbook-1.0") +
                    ["/usr/include/pygtk-2.0"],
    extra_compile_args=compile_args,
)

setup(
    name = 'abook',
    version = '0.1',
    description = 'Python bindings for libosso-addressbook components.',
    author = 'Lauro Moura Maranhao Neto',
    author_email = 'lauro.neto@indt.org.br',
    url = 'http://pymaemo.garage.maemo.org',
    ext_modules = [abook],
    cmdclass={
        'build': PyABookBuild,
        #'build_doc': PyConicDocBuild
    }
)
# vim:ts=4:sw=4:et:

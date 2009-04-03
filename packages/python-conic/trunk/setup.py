from distutils.core import setup, Extension
from distutils.command.build import build
from distutils.command.install import install
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

def get_conic_version():
    input = open('/usr/lib/pkgconfig/conic.pc','r')

    for line in input:
        result = line.split()
        if result:
            if result[0] == 'Version:':
                raw_version = result[-1]

    input.close()
    conic_version = tuple([ int(x) for x in raw_version.split('.') ])
    return conic_version
conic_version = get_conic_version()

def gen_auto_file(filename, subproc_args):
    proc = subprocess.Popen(
        subproc_args,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    #cmdresult = proc.stdout
    #error = proc.stderr
    cmdresult = proc.communicate()[0]
    #Print disabled to avoid problems with scratchbox
    #print error.read()
    if cmdresult:
        new_file = open(filename, 'w')
        new_file.write(cmdresult)
        new_file.close()

    #proc.wait()

class PyConicBuild(build):
    def run(self):
        """Create the temporary files used to compile the conic module:
        -conic.c
        -conic-types.h.in
        -conic-types.c.in"""
        # Generate enum/flags run-time information
        CONIC_TYPE_FILES = [
            includedir+'/conic/conic.h',
            includedir+'/conic/conicconnection.h',
            includedir+'/conic/conicconnectionevent.h',
            includedir+'/conic/conicevent.h',
            includedir+'/conic/coniciap.h',
            includedir+'/conic/conicstatisticsevent.h',
        ]
        
        gen_auto_file('conic-types.h.in', ['/bin/sh', './gen-enum-h']+CONIC_TYPE_FILES)
        gen_auto_file('conic-types.c.in', ['/bin/sh', './gen-enum-c']+CONIC_TYPE_FILES)

        # Creation of ".c" files, using pygtk-codegen-2.0
        override_filename = 'conic.override'
        defs_filename = 'conic.defs'

        parameter = [
            '--register', defsdir+'/gdk.defs',
            '--register', defsdir+'/gtk-types.defs',
            '--override', override_filename,
            '--prefix', 'pyconic',
            defs_filename,
        ] 
        gen_auto_file('conic.c', ['/bin/sh', 'pygtk-codegen-2.0']+parameter)

        build.run(self)
        

class PyConicDocBuild(Command):
    description = "Build Docbook HTML documentation"

    user_options = []

    def initialize_options(self):
        pass


    def finalize_options(self):
        pass
    
    
    def run(self):
        print "Building documentation"

        #FIXME: Hardcoded path
        pygobj_data_dir = "/home/lmoura/python/dev/python-sdk/python-gobject-2.12-2"
        html_style = "/home/lmoura/python/dev/python-sdk/python-gobject-2.12.2/docs/xsl/ref-html-style.xsl"

        #html_style = pygobj_data_dir + "/docs/xsl/ref-html-style.xsl"

        html_dir = "docs/html/"
        refs_dir = "docs/reference/"

        xslt_args = [
            "--nonet",
            "--xinclude",
            "--output", html_dir,
            "--path", refs_dir,
            "--stringparam", "conic.bookname", "\"conic\"",
            "--stringparam", "conic.version", "0.1",
            html_style,
            refs_dir + "conic-docs.xml"
        ]
        
        print xslt_args
        subprocess.call(['xsltproc'] + xslt_args)
        return True

class PyConicInstall(install):
    def run(self):
        # Workaround for scratchbox bug where LD_PRELOAD components are
        # separated by commas and not by colons as they should be.
        os.environ['LD_PRELOAD'] = os.environ['SBOX_PRELOAD'].replace(',',':')

        install.run(self)

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
conic = Extension('conic',
    sources = [
        'conic.c',
        'conicmodule.c',
        'conic-types.c',
    ],
    libraries = [
        'conic',
        'dbus-1',
                'dbus-glib-1',
                'glib-2.0',
                'gobject-2.0',
    ],
    include_dirs = [
        '/usr/include/conic',
        '/usr/include/dbus-1.0',
        '/usr/lib/dbus-1.0/include',
        '/usr/include/glib-2.0',
        '/usr/lib/glib-2.0/include',
        '/usr/include/pygtk-2.0',
    ],    
    extra_compile_args=compile_args,
)

setup(
    name = 'conic',
    version = '0.1',
    description = 'Python bindings for libconic components.',
    author = 'Lauro Moura Maranhao Neto',
    author_email = 'lauro.neto@indt.org.br',
    url = 'http://pymaemo.garage.maemo.org',
    ext_modules = [conic],
    cmdclass={
        'build': PyConicBuild,
        'build_doc': PyConicDocBuild,
        'install': PyConicInstall
    }
)
# vim:ts=4:sw=4:et:

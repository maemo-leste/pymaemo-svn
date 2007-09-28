from distutils.core import setup, Extension
from distutils.command.build import build
import subprocess
import os
import sys

datadir = '/usr/share'
defsdir = datadir+'/pygtk/2.0/defs'
includedir = '/usr/include'

def get_hildon_version():
    input = open('/usr/lib/pkgconfig/hildon-1.pc','r')

    for line in input:
        result = line.split()
        if result:
            if result[0] == 'Version:':
                raw_version = result[-1]

    input.close()
    hildon_version = tuple([ int(x) for x in raw_version.split('.') ])
    print hildon_version
    return hildon_version
hildon_version = get_hildon_version()

def gen_auto_file(filename, subproc_args):
    proc = subprocess.Popen(
        subproc_args,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    tmp = proc.communicate()
    cmdresult = tmp[0]
    error = tmp[1]
    print error
#   Print disabled to avoid problems with scratchbox
#    print >>sys.sdterr, error.read()
    if cmdresult:
        new_file = open(filename, 'w')
        new_file.write(cmdresult)
        new_file.close()

class PyHildonBuild(build):
    def run(self):
        """Create the temporary files used to compile the hildon module:
        -hildon.c
        -hildon-types.h.in
        -hildon-types.c.in"""
        # Generate enum/flags run-time information
        HILDON_TYPE_FILES = [
            includedir+'/hildon-fm-2/hildon/hildon-file-chooser-dialog.h',
            includedir+'/hildon-fm-2/hildon/hildon-file-details-dialog.h',
            includedir+'/hildon-fm-2/hildon/hildon-file-selection.h',
            includedir+'/hildon-fm-2/hildon/hildon-file-system-common.h',
            includedir+'/hildon-fm-2/hildon/hildon-file-system-info.h',
            includedir+'/hildon-fm-2/hildon/hildon-file-system-model.h',
            includedir+'/hildon-fm-2/hildon/hildon-fm1-compat.h',
            includedir+'/hildon-1/hildon/hildon-date-editor.h',
            includedir+'/hildon-1/hildon/hildon-font-selection-dialog.h',
            includedir+'/hildon-1/hildon/hildon-number-editor.h',
            includedir+'/hildon-1/hildon/hildon-time-editor.h',
            includedir+'/glib-2.0/glib/gdate.h',
        ]

        gen_auto_file('hildon-types.h.in', ['/bin/sh', './gen-enum-h']+HILDON_TYPE_FILES)
        gen_auto_file('hildon-types.c.in', ['/bin/sh', './gen-enum-c']+HILDON_TYPE_FILES)

        # Creation of ".c" files, using pygtk-codegen-2.0
        override_filename = 'hildon.override'
        if hildon_version > (0, 14, 0):
            defs_filename = 'hildon-0.14.defs'
        else:
            defs_filename = 'hildon.defs'

        parameter = [
            '--register', defsdir+'/gdk.defs',
            '--register', defsdir+'/gtk-types.defs',
            '--register', defsdir+'/gtk.defs',
            '--register', defsdir+'/gtk-base.defs',
            '--register', defsdir+'/pango-types.defs',
            '--register', 'defs/missing-types.defs',
            '--override', 'hildon.override',
            '--prefix', 'pyhildon',
            defs_filename,
        ]
        gen_auto_file('hildon.c', ['/bin/sh', 'pygtk-codegen-2.0']+parameter)

        build.run(self)


compile_args = [
        '-Os',
        '-DXTHREADS',
        '-DXUSE_MTSAFE_API',
        '-DHILDON_DISABLE_DEPRECATED',
        '-DMAEMO_CHANGES',
        '-DHILDON_ENABLE_UNSTABLE_API',
#        '-ansi',
#        '-pedantic',
#        '-Wno-long-long',
#        '-g',
#        '-rdynamic',
]

if hildon_version > (0, 14, 0):
    compile_args.append("-DHILDON_0_14")

hildon = Extension('hildon',
    sources = [
        'hildon.c',
        'hildonmodule.c',
        'hildon-extra.c',
        'hildon-types.c',
    ],
    libraries = [
        'hildon-1',
        'hildonfm',
        'dbus-1',
        'dbus-glib-1',
        'glib-2.0',
        'gobject-2.0',
        'gmodule-2.0',
        'atk-1.0',
        'pangoxft-1.0',
        'pangox-1.0',
        'pango-1.0',
        'gdk-x11-2.0',
        'gdk_pixbuf-2.0',
        'cairo',
    ],
    include_dirs=[
        '/usr/include',
        '/usr/include/freetype2',
        '/usr/include/dbus-1.0',
        '/usr/include/glib-2.0',
        '/usr/include/atk-1.0',
        '/usr/include/pango-1.0',
        '/usr/include/gtk-2.0',
        '/usr/include/pygtk-2.0',
        '/usr/include/hildon-fm-2/hildon',
        '/usr/include/hildon-widgets',
        '/usr/include/cairo',
        '/usr/lib/dbus-1.0/include',
        '/usr/lib/glib-2.0/include',
        '/usr/lib/gtk-2.0/include',
        '/usr/X11R6/include',
    ],
    extra_compile_args=compile_args,
)

setup(
    name = 'hildon',
    version = '0.1',
    description = 'Python bindings for libhildon components.',
    author = 'Osvaldo Santana Neto',
    author_email = 'osvaldo.santana@indt.org.br',
    url = 'http://www.maemo.org',
    ext_modules = [hildon],
    cmdclass={'build': PyHildonBuild}
)

from distutils.core import setup, Extension
from distutils.command.build import build
import subprocess
import os
import sys

datadir = '/usr/share' #FIXME Get this from pygtk.pc's  'datadir' variable
defsdir = datadir+'/pygtk/2.0/defs'

PYGTK_SUFFIX="2.0"
CODEGEN_DIR    = os.path.join('/', 'usr', 'share', 'pygtk', PYGTK_SUFFIX)
sys.path.append(CODEGEN_DIR)

from dsextras import BuildExt, TemplateExtension, Template, pkgc_version_check

extensions = []

hildon = TemplateExtension(name='hildon', pkc_name='hildon-1',
                           pkc_version="1.99.0",
                           pygobject_pkc=('hildon-fm-2', 'pygobject-2.0'),
                           sources=['hildonmodule.c', 'hildon.c',
                                    'hildon-types.c'],
                           register=['hildon-types.defs',
                                     defsdir+'/gtk-types.defs',
                                     defsdir+'/gtk.defs',
                                     defsdir+'/gdk.defs',
                                     defsdir+'/gtk-base.defs',
                                     'defs/missing-types.defs',
                                     ],
                           override='hildon.override',
                           defs='hildon.defs',py_ssize_t_clean=True,
                           extra_compile_args=['-Os',
                                               '-DXTHREADS',
                                               '-DXUSE_MTSAFE_API',
                                               '-DHILDON_DISABLE_DEPRECATED',
                                               '-DMAEMO_CHANGES',
                                               '-DHILDON_ENABLE_UNSTABLE_API'
                           ])

extensions.append(hildon)

hildonhelp = TemplateExtension(name='hildonhelp', pkc_name='hildon-help',
                                   pkc_version="1.9.6",
                                   pygobject_pkc=('gtk+-2.0',
                                                  'pygobject-2.0',
                                                  'dbus-1',
                                                  'dbus-glib-1'),
                                   sources=['help/hildonhelpmodule.c',
                                            'help/hildonhelp.c'],
                                   register=['help/hildonhelp-types.defs',
                                             defsdir+'/gtk-types.defs',
                                             defsdir+'/gtk.defs',
                                             defsdir+'/gtk-base.defs',
                                             ],
                                   override='help/hildonhelp.override',
                                   defs='help/hildonhelp.defs',py_ssize_t_clean=True,
                                   extra_compile_args=['-Os',
                                                       '-DXTHREADS',
                                                       '-DXUSE_MTSAFE_API',
                                                       '-DHILDON_DISABLE_DEPRECATED',
                                                       '-DMAEMO_CHANGES',
                                                       '-DHILDON_ENABLE_UNSTABLE_API'
                                   ])
extensions.append(hildonhelp)

setup(
    name = 'hildon',
    version = '0.1',
    description = 'Python bindings for libhildon components.',
    author = 'Osvaldo Santana Neto',
    author_email = 'osvaldo.santana@indt.org.br',
    url = 'http://www.maemo.org',
    ext_modules = extensions,
    cmdclass={'build_ext': BuildExt}
)

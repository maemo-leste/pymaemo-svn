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

import codegen

from dsextras import BuildExt, TemplateExtension, Template

hildon = TemplateExtension(name='hildon', pkc_name='hildon-libs',
                           pkc_version="1.99.0",
                           pygobject_pkc=('hildon-fm', 'hildon-base-lib',
                                          'pygobject-2.0'),
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
                           defs='hildon.defs',
                           py_ssize_t_clean=True,
                           extra_compile_args=['-Os',
                                               '-DXTHREADS',
                                               '-DXUSE_MTSAFE_API',
                                               '-DHILDON_DISABLE_DEPRECATED',])

setup(
    name = 'hildon',
    version = '0.1',
    description = 'Python bindings for libhildon components.',
    author = 'Osvaldo Santana Neto',
    author_email = 'osvaldo.santana@indt.org.br',
    url = 'http://www.maemo.org',
    ext_modules = [hildon],
    cmdclass={'build_ext': BuildExt}
)

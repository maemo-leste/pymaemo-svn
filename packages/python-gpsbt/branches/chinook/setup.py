from distutils.core import setup, Extension
from Pyrex.Distutils import build_ext

#Common attributes to be used by Extension
common_compile_args = ['-Os',
#                       '-ansi',
                       '-DXTHREADS',
                       '-DXUSE_MTSAFE_API',
#                       '-pedantic',
#                       '-Wno-long-long',
#                       '-g',
#                       '-rdynamic',
                      ]

common_include_dirs = ['/usr/include',
                       '/usr/include/glib-2.0', '/usr/lib/glib-2.0/include']

common_libraries = ['gpsbt',
                    'gpsmgr',
                    'gps',
                    'glib-2.0']

#Modules to be built
gps_modules = [ Extension('gpsbt', sources = ['src/gpsbt.pyx'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
              ]

setup(
        name = 'gpsbt',
        version = '0.1',
        description = 'Python bindings for libgpsbt.',
        author = 'Luciano Miguel Wolf',
        author_email = 'luciano.wolf@indt.org.br',
        url = 'http://www.maemo.org',
        ext_modules = gps_modules,
        cmdclass = {'build_ext': build_ext}
)

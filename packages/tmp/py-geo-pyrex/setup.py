from distutils.core import setup, Extension
from Pyrex.Distutils import build_ext

#Common attributes to be used by Extension
common_compile_args = ['-Os',
#                       '-ansi',
                       '-DXTHREADS',
                       '-DXUSE_MTSAFE_API',
                       '-DGTK_DISABLE_DEPRECATED',
#                       '-pedantic',
#                       '-Wno-long-long',
#                       '-g',
#                       '-rdynamic',
                      ]

common_include_dirs = ['/usr/include','/usr/include/geoclue',
                      '/usr/include/dbus-1.0', '/usr/lib/dbus-1.0/include',
                       '/usr/include/glib-2.0', '/usr/lib/glib-2.0/include',
                       '/usr/include/pygtk-2.0',
                       '/usr/include/gtk-2.0', '/usr/lib/gtk-2.0/include']

common_libraries = ['geoclue',
                    'dbus-1',
                    'glib-2.0',
                    'gtk-x11-2.0']

#Modules to be built
gps_modules = [ Extension('position', sources = ['src/gps.position.pyx'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
              ]

setup(
        name = 'gps',
        version = '0.1',
        description = 'Python bindings for geoclue gps components.',
        author = 'Luciano Miguel Wolf',
        author_email = 'luciano.wolf@indt.org.br',
        url = 'http://www.maemo.org',
        py_modules=["gps/__init__"],
        ext_package = 'gps',
        ext_modules = gps_modules,
        cmdclass = {'build_ext': build_ext}
)

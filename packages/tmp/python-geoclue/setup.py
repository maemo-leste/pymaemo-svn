from distutils.core import setup, Extension

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

common_include_dirs = ['/usr/include',
                       '/usr/include/dbus-1.0', '/usr/lib/dbus-1.0/include',
                       '/usr/include/glib-2.0', '/usr/lib/glib-2.0/include',
                       '/usr/include/pygtk-2.0',
                       '/usr/include/gtk-2.0', '/usr/lib/gtk-2.0/include']

common_libraries = ['dbus-1',
                    'glib-2.0',
                    'gtk-x11-2.0']

#Modules to be built
gps_modules = [ Extension('find', sources = ['src/gps-find.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
#                Extension('geocode', sources = ['src/gps-geocode.c'],
#                            libraries = common_libraries,
#                            include_dirs = common_include_dirs,
#                            extra_compile_args = common_compile_args),
#                Extension('map', sources = ['src/gps-map.c'],
#                            libraries = common_libraries,
#                            include_dirs = common_include_dirs,
#                            extra_compile_args = common_compile_args),
#                Extension('map_gtk', sources = ['src/gps-map_gtk.c'],
#                            libraries = common_libraries,
#                            include_dirs = common_include_dirs,
#                            extra_compile_args = common_compile_args),
#                Extension('map_gtk_layout', sources = ['src/gps-map_gtk_layout.c'],
#                            libraries = common_libraries,
#                            include_dirs = common_include_dirs,
#                            extra_compile_args = common_compile_args),
                Extension('position', sources = ['src/gps-position.c'],
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
        ext_modules = gps_modules
)

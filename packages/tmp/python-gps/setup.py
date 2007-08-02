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

common_include_dirs = ['/usr/include']

common_libraries = ['glib-2.0']

#Modules to be built
gps = Extension('manager',
                sources = ['src/gpsmgr.c'],# 'src/gpsbt.c'],
                libraries = common_libraries,
                include_dirs = common_include_dirs,
                extra_compile_args = common_compile_args)
setup(
        name = 'gps',
        version = '0.1',
        description = 'Python bindings for gps components.',
        author = 'Luciano Miguel Wolf',
        author_email = 'luciano.wolf@indt.org.br',
        url = 'http://www.maemo.org',
        py_modules=["gps/__init__"],
        ext_package = 'gps',
        ext_modules = [gps]
)

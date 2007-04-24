from distutils.core import setup, Extension

#Attributes to be used by Extension
compile_args = ['-Os',
#               '-ansi',
                '-DXTHREADS',
                '-DXUSE_MTSAFE_API',
                '-DGTK_DISABLE_DEPRECATED',
#               '-pedantic',
#               '-Wno-long-long',
#               '-g',
#               '-rdynamic',
               ]

include_dirs = ['/usr/include',
                '/usr/include/glib-2.0', '/usr/lib/glib-2.0/include']

libraries = ['cst']

#Modules to be built
certman_modules = [ Extension('certman', sources = ['src/cst-main.c'],
                              libraries = libraries,
                              include_dirs = include_dirs,
                              extra_compile_args = compile_args)
                  ]

setup(
        name = 'certman',
        version = '0.1',
        description = 'Python bindings for X.509 certificate manager library.',
        author = "Daniel d'Andrada T. de Carvalho",
        author_email = 'daniel.carvalho@indt.org.br',
        url = 'http://www.maemo.org',
        py_modules=["certman/__init__"],
        ext_package = 'certman',
        ext_modules = certman_modules
)

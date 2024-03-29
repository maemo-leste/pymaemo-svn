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
                       '/usr/include/atk-1.0',
                       '/usr/include/dbus-1.0', '/usr/lib/dbus-1.0/include',
                       '/usr/include/glib-2.0', '/usr/lib/glib-2.0/include',
                       '/usr/include/pygtk-2.0',
                       '/usr/include/gtk-2.0', '/usr/lib/gtk-2.0/include',
                       '/usr/include/pango-1.0']

common_libraries = ['osso',
                    'atk-1.0',
                    'dbus-1',
                    'glib-2.0',
                    'gtk-x11-2.0',
                    'pango-1.0']

mime_include_dirs = ['/usr/include/gnome-vfs-2.0']

mime_libraries = ['ossomime']

#Modules to be built
osso_modules = [ Extension('application', sources = ['src/osso-application.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('autosave', sources = ['src/osso-autosave.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('context', sources = ['src/osso-context.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('device_state', sources = ['src/osso-device-state.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('mime', sources = ['src/osso-mime.c', 'src/osso-helper.c'],
                            libraries = common_libraries + mime_libraries,
                            include_dirs = common_include_dirs + mime_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('misc', sources = ['src/osso-misc.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('plugin', sources = ['src/osso-plugin.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('rpc', sources = ['src/osso-rpc.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('state_saving', sources = ['src/osso-state-saving.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('statusbar', sources = ['src/osso-statusbar.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('system_note', sources = ['src/osso-system-note.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
                 Extension('time_notification', sources = ['src/osso-time-notification.c', 'src/osso-helper.c'],
                            libraries = common_libraries,
                            include_dirs = common_include_dirs,
                            extra_compile_args = common_compile_args),
               ]

setup(
        name = 'osso',
        version = '0.1',
        description = 'Python bindings for libosso components.',
        author = 'Osvaldo Santana Neto',
        author_email = 'osvaldo.santana@indt.org.br',
        url = 'http://www.maemo.org',
        py_modules=["osso/__init__"],
        ext_package = 'osso',
        ext_modules = osso_modules
)

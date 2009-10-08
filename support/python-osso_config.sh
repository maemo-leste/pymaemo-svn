# pkg-config module name
pkgconfig="libosso"

# extra pkg-config modules for the Python extension
pkgconfig_extra="pygtk-2.0 gtk+-2.0"

# extra CFLAGS for the Python extension
cflags_extra="-I/usr/include/python2.5 -Wno-write-strings -include /usr/include/glib-2.0/glib/gmain.h"

# command the will return the list of C files for Python API
#py_api_cmd='find $PWD/src -name "*.c" | egrep -v "/osso-(mime|misc).c$"'
py_api_cmd='find $PWD/osso -name "*.c"'

# list of C files for C API (usually headers)
#headers=$(dpkg -L libosso-dev | grep '\.h$')
headers=/usr/include/libosso.h

# directory where object files for built extension can be found
object_dir="build/temp.linux-i686-2.5/osso"

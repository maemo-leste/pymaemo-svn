#!/bin/bash
# Calculate approximated API coverage for a Python binding, compared to the
# original C API.
set -e -u

tmp=$(mktemp -d)
trap "echo Removing temporary files... >&2; rm -rf $tmp" EXIT

base_dir=$(dirname $0)
# pkg-config module name
pkgconfig="libosso"
# extra pkg-config modules for the Python extension
pkgconfig_extra="pygtk-2.0 gtk+-2.0"
# extra CFLAGS for the Python extension
cflags_extra="-I/usr/include/python2.5 -Wno-write-strings -include /usr/include/glib-2.0/glib/gmain.h"
# command the will return the list of C files for Python API
#py_api_cmd='find $HOME/workspace/python-osso/python-osso-0.3/src -name "*.c" | egrep -v "/osso-(mime|misc).c$"'
py_api_cmd='find /tmp/python-osso/python-osso-0.4/osso -name "*.c"'
# list of C files for C API (usually headers)
#headers=$(dpkg -L libosso-dev | grep '\.h$')
headers=/usr/include/libosso.h

function dehydra_run()
{
    script=$1; shift
    file=$1; shift

    $base_dir/gcc4.3/bin/g++ \
        -fplugin=$base_dir/dehydra-r491/gcc_dehydra.so \
        -fplugin-arg=$script \
        -o /dev/null \
        -c "$@" $file
}

function create_c_plugin()
{
    # Plugin to collect C API
    cat > $tmp/from_c.js << EOF
function process_decl(decl) {
    var headers = new Array();
    var i = 0;
EOF
    for h in $@; do
        echo "    headers[i++] = \"$h\";" >> $tmp/from_c.js
    done
cat >> $tmp/from_c.js << EOF
    for each(h in headers) {
        if (decl.isFunction && decl.loc.file == h)
            print(decl.shortName);
    }
}
EOF
}

function create_python_plugin()
{
    file=$(readlink -f $1); shift

    # Plugin to collect Python API
    cat > $tmp/from_python.js << EOF
function handle_function_call(fn, stmt)
{
    var headers = new Array();
    var i = 0;
EOF
    for h in $@; do
        echo "    headers[i++] = \"$h\";" >> $tmp/from_python.js
    done
cat >> $tmp/from_python.js << EOF
    for each(h in headers) {
        if (stmt.loc.file == h && fn.loc.file == "$file")
            _print(stmt.shortName);
    }
}

function handle_assign(fn, stmt)
{
    for each(s in stmt.assign) {
        if (s.isFcall)
            handle_function_call(fn, s);
    }
}

function handle_statement(fn, stmt)
{
    if (stmt.assign)
        handle_assign(fn, stmt);
    else if (stmt.isFcall)
        handle_function_call(fn, stmt);
}

function process_function(decl, body) {
    for each(i in body) {
        for each(j in i.statements) {
            handle_statement(decl, j);
        }
    }
}

/*
function process(vars, state) {
    for each(v in vars) {
        if (v.assign)
            handle_assign(v);
        else if (v.isFcall)
            handle_function_call(v);
    }
}
*/
EOF
}

# Ignore list
cat > $tmp/ignore.txt << EOF
# - has variable argument list
# - reimplemented using osso_rpc_run_with_argfill()
osso_rpc_run

# - has variable argument list
# - reimplemented using osso_rpc_run_system_with_argfill()
osso_rpc_run_system

# - has variable argument list
# - reimplemented using osso_rpc_run_with_argfill()
osso_rpc_run_with_defaults

# - has variable argument list
# - reimplemented using osso_rpc_async_run_with_argfill()
osso_rpc_async_run

# - has variable argument list
# - reimplemented using osso_rpc_async_run_with_argfill()
osso_rpc_async_run_with_defaults

# Resource deallocation functions, not necessary in Python
osso_rpc_free_val
osso_rpc_set_cb_f_with_free
osso_rpc_set_default_cb_f_with_free

# Deprecated API
osso_application_set_top_cb
osso_application_unset_top_cb
EOF

# Collect C API
create_c_plugin $headers
for f in $headers; do
    dehydra_run $tmp/from_c.js $f `pkg-config --cflags $pkgconfig` $cflags_extra
done | sort -u > $tmp/c_api.txt

# Collect Python API
eval $py_api_cmd | while read f; do
    create_python_plugin $f $headers
    dehydra_run $tmp/from_python.js $f \
        `pkg-config --cflags $pkgconfig $pkgconfig_extra` $cflags_extra
done | sort -u > $tmp/called_functions.txt

# List missing API
egrep -v -e '^$' -e '^#' $tmp/ignore.txt |
grep -x -F -f $tmp/called_functions.txt -f- -v $tmp/c_api.txt > $tmp/missing.txt
cat $tmp/missing.txt

# Print some statistics
n_miss=$(wc -l < $tmp/missing.txt)
n_total=$(wc -l < $tmp/c_api.txt)
echo "Coverage (functions): $(perl -e "printf('%0.2f%%', ($n_total-$n_miss)/$n_total*100)") ($n_miss/$n_total missing)" >&2

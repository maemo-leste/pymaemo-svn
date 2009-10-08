#!/bin/bash
# Calculate approximated API coverage for a Python binding, compared to the
# original C API.
set -e -u

if [ $# -ne 2 ]; then
    echo "Usage: $0 <config.sh> <ignore.txt>" >&2
    exit 1
fi
base_dir=$(dirname $0)
config=$1
ignore=$2

if [ ! -f $ignore ]; then
    ignore=$base_dir/$ignore
fi
if [ ! -f $ignore ]; then
    echo "Ignore file not found: $ignore" >&2
    exit 1
fi

tmp=$(mktemp -d)
trap "echo Removing temporary files... >&2; rm -rf $tmp" EXIT

if [ -f $config ]; then
    . $config
else
    . $base_dir/$config
fi

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
    cat << EOF
function process_decl(decl) {
    var headers = new Array();
    var i = 0;
EOF
    for h in $@; do
        echo "    headers[i++] = \"$h\";"
    done
    cat << EOF
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
    cat << EOF
function handle_function_call(fn, stmt)
{
    var headers = new Array();
    var i = 0;
EOF
    for h in $@; do
        echo "    headers[i++] = \"$h\";"
    done
    cat << EOF
    for each(h in headers) {
        if (stmt.loc.file == h && fn.loc.file == "$file")
            _print(stmt.shortName);
    }
}

function handle_assign(fn, stmt)
{
    for each(s in stmt.assign) {
        if (s.isFcall) {
            handle_function_call(fn, s);
            for each(a in s.arguments) {
                if (a.isFcall)
                    handle_function_call(fn, a);
            }
        }
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

# Collect C API
create_c_plugin $headers > $tmp/from_c.js
for f in $headers; do
    dehydra_run $tmp/from_c.js $f `pkg-config --cflags $pkgconfig` $cflags_extra
done | sort -u > $tmp/c_api.txt

# Collect Python API
eval $py_api_cmd | while read f; do
    create_python_plugin $f $headers > $tmp/from_python.js
    dehydra_run $tmp/from_python.js $f \
        `pkg-config --cflags $pkgconfig $pkgconfig_extra` $cflags_extra
done | sort -u > $tmp/called_functions.txt

# List missing API
egrep -v -e '^$' -e '^#' $ignore |
grep -x -F -f $tmp/called_functions.txt -f- -v $tmp/c_api.txt > $tmp/missing.txt
cat $tmp/missing.txt

# Print some statistics
n_miss=$(wc -l < $tmp/missing.txt)
n_total=$(wc -l < $tmp/c_api.txt)
echo "Coverage (functions): $(perl -e "printf('%0.2f%%', ($n_total-$n_miss)/$n_total*100)") ($n_miss/$n_total missing)" >&2

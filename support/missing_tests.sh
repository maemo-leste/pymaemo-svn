#!/bin/bash
# Measure approximate API test coverage using dehydra + gcov
set -e -u

if [ $# -ne 1 ]; then
    echo "Usage: $0 <config.sh>" >&2
    exit 1
fi
base_dir=$(dirname $0)
config=$1

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

function create_python_plugin()
{
    file=$(readlink -f $1); shift

    # Plugin to collect Python API
    cat << EOF
function handle_function_call(caller, stmt)
{
    var headers = new Array();
    var i = 0;
EOF
    for h in $@; do
        echo "    headers[i++] = \"$h\";"
    done
cat << EOF
    for each(h in headers) {
        if (stmt.loc.file == h && caller.loc.file == "$file")
            _print(stmt.shortName + ":" + caller.loc.line);
    }
}

function handle_assign(caller, stmt)
{
    for each(s in stmt.assign) {
        if (s.isFcall) {
            handle_function_call(caller, s);
            for each(a in s.arguments) {
                if (a.isFcall)
                    handle_function_call(caller, a);
            }
        }
    }
}

function handle_statement(caller, stmt)
{
    if (stmt.assign)
        handle_assign(caller, stmt);
    else if (stmt.isFcall)
        handle_function_call(caller, stmt);
}

function process_function(decl, body) {
    for each(i in body) {
        for each(j in i.statements) {
            handle_statement(i, j);
        }
    }
}
EOF
}

> $tmp/c_api.txt
> $tmp/missing.txt
eval $py_api_cmd | while read f; do
    create_python_plugin $f $headers > $tmp/c_api_calls.js
    gcov -o $object_dir $f
    dehydra_run $tmp/c_api_calls.js $f \
        `pkg-config --cflags $pkgconfig $pkgconfig_extra` \
        $cflags_extra | while read l; do
        fname=$(echo $l | cut -d: -f1)
        line=$(echo $l | cut -d: -f2)
        echo $fname >> $tmp/c_api.txt
        if ! grep -q ": *$line:" $(basename $f).gcov; then
            echo "*** Line $line not found in $f ($fname)"
            continue
        fi
        if grep -q "^ *#####: *$line:" $(basename $f).gcov; then
            echo "*** Function \"$fname\" not covered by any unit test"
            echo $fname >> $tmp/missing.txt
        fi
    done
    echo
    rm $(basename $f).gcov
done

# Print some statistics
n_miss=$(wc -l < $tmp/missing.txt)
n_total=$(wc -l < $tmp/c_api.txt)
echo "Test coverage (functions): $(perl -e "printf('%0.2f%%', ($n_total-$n_miss)/$n_total*100)") ($n_miss/$n_total missing)" >&2

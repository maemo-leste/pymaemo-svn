#!/bin/bash
# Generates .defs and helper .c/.h files from installed -dev packages
# Author: Anderson Lizardo <anderson.lizardo@indt.org.br>
set -e

dev_packages="libhildon1-dev libhildonfm2-dev"
codegen_dir="$(pkg-config --variable=codegendir pygtk-2.0)"
# contains some enums used in HildonWeekdayPicker
extra_headers="/usr/include/glib-2.0/glib/gdate.h"

mkdir -p defs

headers=""
for p in $dev_packages; do
	headers="$(dpkg -L $p | grep '\.h$') $headers"
done

echo Parsing .h files and creating .defs...
# Create empty hildon-includes.h (or empty existing one)
> hildon-includes.h
for h in $headers; do
	$codegen_dir/h2def.py -f hildon-ignore.defs $h > defs/$(basename $h .h).defs
	echo "#include \"$h\"" >> hildon-includes.h
done
$codegen_dir/createdefs.py hildon.defs defs/*.defs

# Apply some transformations to the generated .defs
function set_null_ok()
{
	defs_file=$1
	method=$2
	param=$3
	sed -i.bak "/^(define-method $method\$/,/^)/{/^  (parameters/{N;s/\\n.*\"$param\"/& (null-ok) (default \"NULL\")/}}" $defs_file
	diff -u $defs_file.bak $defs_file || true
	rm $defs_file.bak
}

set_null_ok defs/hildon-window.defs set_main_menu menu
set_null_ok defs/hildon-window.defs set_app_menu menu

echo Generating hildon-types.c and hildon-types.h...
glib-mkenums --template hildon-types-template.h $headers $extra_headers > hildon-types.h
glib-mkenums --template hildon-types-template.c $headers $extra_headers > hildon-types.c

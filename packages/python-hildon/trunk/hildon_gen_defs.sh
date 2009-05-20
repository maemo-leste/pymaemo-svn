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
cat > defs/hildon-extras.defs << "EOF"
; There is no "hildon_note_new" function. That declaration is here just to be overrided.
(define-function hildon_note_new
  (c-name "hildon_note_new")
  (is-constructor-of "HildonNote")
  (return-type "GtkWidget*")
  (parameters
    '("GtkWindow*" "parent")
    '("const-gchar*" "description")
  )
)

; There is no "hildon_file_system_model_new" function. That declaration is here just to be overrided.
(define-function hildon_file_system_model_new
  (c-name "hildon_file_system_model_new")
  (is-constructor-of "HildonFileSystemModel")
  (return-type "HildonFileSystemModel*")
  (parameters
    '("GtkWidget*" "ref_widget")
    '("const-gchar*" "root_dir")
  )
)

EOF
$codegen_dir/createdefs.py hildon.defs defs/*.defs

# Apply some transformations to the generated .defs
function set_null_ok()
{
	defs_file=$1
	method=$2
	param=$3
	sed -i.bak "/^(define-\(method\|function\) $method\$/,/^)/{/^  (parameters/{:l;N;s/\\n.*\"$param\"/& (null-ok) (default \"NULL\")/;Tl}}" $defs_file
	diff -u $defs_file.bak $defs_file && echo "WARNING: $defs_file is unchanged" || true
	rm $defs_file.bak
}

set_null_ok defs/hildon-window.defs set_main_menu menu
set_null_ok defs/hildon-window.defs set_app_menu menu
set_null_ok defs/hildon-wizard-dialog.defs hildon_wizard_dialog_new parent
set_null_ok defs/hildon-font-selection-dialog.defs hildon_font_selection_dialog_new title
set_null_ok defs/hildon-caption.defs hildon_caption_new group
set_null_ok defs/hildon-caption.defs hildon_caption_new icon

echo Generating hildon-types.c and hildon-types.h...
glib-mkenums --template hildon-types-template.h $headers $extra_headers > hildon-types.h
glib-mkenums --template hildon-types-template.c $headers $extra_headers > hildon-types.c

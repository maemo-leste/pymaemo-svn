#!/bin/bash
# Generates .defs and helper .c/.h files from installed -dev packages
# Author: Anderson Lizardo <anderson.lizardo@indt.org.br>
set -e

pkg_name="mafw"
dev_packages="libmafw0-dev libmafw-shared0-dev"
codegen_dir="$(pkg-config --variable=codegendir pygtk-2.0)"
# contains some enums used in HildonWeekdayPicker
#extra_headers="/usr/include/glib-2.0/glib/gdate.h"

mkdir -p defs

headers=""
for p in $dev_packages; do
	headers="$(dpkg -L $p | grep '\.h$') $headers"
done

echo Parsing .h files and creating .defs...
# Create empty pkg_name-includes.h (or empty existing one)
> $pkg_name-includes.h
for h in $headers; do
	$codegen_dir/h2def.py $h > defs/$(basename $h .h).defs
	echo "#include \"$h\"" >> $pkg_name-includes.h
done
$codegen_dir/createdefs.py $pkg_name.defs $pkg_name-extras.defs defs/*.defs

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
function set_constructor()
{
	defs_file=$1
	method=$2
	module=$3
	sed -i.bak "/^(define-\(method\|function\) $method\$/,/^)/{/^  (c-name \"$method\".*/{s//&\n  (is-constructor-of \"$module\")/}}" $defs_file
	diff -u $defs_file.bak $defs_file && echo "WARNING: $defs_file is unchanged" || true
	rm $defs_file.bak
}
function to_method()
{
	defs_file=$1
	fn=$2
	meth=$3
	module=$4
	sed -i.bak "s/^(define-function $fn$/(define-method $meth\n  (of-object \"$module\")/" $defs_file
	diff -u $defs_file.bak $defs_file && echo "WARNING: $defs_file is unchanged" || true
	rm $defs_file.bak
}

#set_null_ok defs/hildon-window.defs set_main_menu menu
#set_null_ok defs/hildon-window.defs set_app_menu menu
#set_null_ok defs/hildon-wizard-dialog.defs hildon_wizard_dialog_new parent
#set_null_ok defs/hildon-font-selection-dialog.defs hildon_font_selection_dialog_new title
#set_null_ok defs/hildon-caption.defs hildon_caption_new group
#set_null_ok defs/hildon-caption.defs hildon_caption_new icon
#set_null_ok defs/hildon-button.defs hildon_button_new_with_text title
#set_null_ok defs/hildon-button.defs hildon_button_new_with_text value
#set_constructor defs/hildon-button.defs hildon_button_new_with_text HildonButton
#set_constructor defs/hildon-edit-toolbar.defs hildon_edit_toolbar_new_with_text HildonEditToolbar
#set_constructor defs/hildon-gtk.defs hildon_gtk_radio_button_new_from_widget HildonGtkRadioButton
#set_constructor defs/hildon-touch-selector-entry.defs hildon_touch_selector_entry_new_text HildonTouchSelectorEntry
#to_method defs/hildon-window-stack.defs hildon_window_stack_get_default get_default HildonWindowStack

echo Generating mafw-types.c and mafw-types.h...
glib-mkenums --template $pkg_name-types-template.h $headers $extra_headers > $pkg_name-types.h
glib-mkenums --template $pkg_name-types-template.c $headers $extra_headers > $pkg_name-types.c

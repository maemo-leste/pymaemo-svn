#!/bin/bash
# Generates .defs and helper .c/.h files from installed -dev packages
# Author: Anderson Lizardo <anderson.lizardo@indt.org.br>
set -e

pkg_name="mafw"
dev_packages="libmafw0-dev libmafw-shared0-dev"
codegen_dir="$(pkg-config --variable=codegendir pygtk-2.0)" || \
{ echo "Could not find codegen. Make sure that python-gtk2-dev is installed"; exit 1; }
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


cat >> mafw.defs << "EOF"

(define-function mafw_extension_new
  (c-name "mafw_extension_new")
  (is-constructor-of "MafwExtension")
  (return-type "MafwExtension")
)

(define-function mafw_renderer_new
  (c-name "mafw_renderer_new")
  (is-constructor-of "MafwRenderer")
  (return-type "MafwRenderer")
)

(define-function mafw_source_new
  (c-name "mafw_source_new")
  (is-constructor-of "MafwSource")
  (return-type "MafwSource")
)

EOF

# show modifications in diff format
function show_changes()
{
	defs_file=$1
	diff -u $defs_file.bak $defs_file && echo "WARNING: $defs_file is unchanged" || true
	rm $defs_file.bak
}
# mark parameter as optional
function set_null_ok()
{
	defs_file=$1
	method=$2
	param=$3
	sed -i.bak "/^(define-\(method\|function\) $method\$/,/^)/{/^  (parameters/{:l;N;s/\\n.*\"$param\"/& (null-ok) (default \"NULL\")/;Tl}}" $defs_file
	show_changes $defs_file
}
# set function or method as a class constructor
function set_constructor()
{
	defs_file=$1
	method=$2
	module=$3
	sed -i.bak "/^(define-\(method\|function\) $method\$/,/^)/{/^  (c-name \"$method\".*/{s//&\n  (is-constructor-of \"$module\")/}}" $defs_file
	show_changes $defs_file
}
# transform a function into a method
function to_method()
{
	defs_file=$1
	fn=$2
	meth=$3
	module=$4
	sed -i.bak "s/^(define-function $fn$/(define-method $meth\n  (of-object \"$module\")/" $defs_file
	show_changes $defs_file
}
# mark a object as implementor of a interface
function implements()
{
	defs_file=$1
	object=$2
	module=$3
	implements=$4
	sed -i.bak "/^(define-object $object\$/,/^)/{s/^  (in-module \"$module\")$/&\n  (implements \"$implements\")/}" $defs_file
	show_changes $defs_file
}
# transform a object into a interface
function to_interface()
{
	defs_file=$1
	object=$2
	sed -i.bak "/^(define-object $object\$/,/^)/{s/^(define-object /(define-interface /;s/^  (parent /  (prerequisite /}" $defs_file
	show_changes $defs_file
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
to_method defs/mafw-registry.defs mafw_registry_get_instance get_instance MafwRegistry
to_method defs/mafw-playlist-manager.defs mafw_playlist_manager_get get MafwPlaylistManager
to_interface defs/mafw-playlist.defs Playlist
implements defs/mafw-proxy-playlist.defs ProxyPlaylist Mafw MafwPlaylist

echo Generating mafw-types.c and mafw-types.h...
glib-mkenums --template $pkg_name-types-template.h $headers $extra_headers > $pkg_name-types.h
glib-mkenums --template $pkg_name-types-template.c $headers $extra_headers > $pkg_name-types.c

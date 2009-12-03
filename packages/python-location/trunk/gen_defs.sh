#!/bin/bash
# Generates .defs and helper .c/.h files from installed -dev packages
# Author: Anderson Lizardo <anderson.lizardo@openbossa.org>
set -e -u

module="location"
dev_packages="liblocation-dev"
codegen_dir="$(pkg-config --variable=codegendir pygtk-2.0)" || \
    { echo "This script requires python-gtk2-dev"; exit 1 ;}
extra_headers=""

mkdir -p defs

headers=""
for p in $dev_packages; do
	headers="$(dpkg -L $p | sort | grep '\.h$') $headers"
done

echo Parsing .h files and creating .defs...
# Create empty *-includes.h (or empty existing one)
> $module-includes.h
for h in $headers; do
	$codegen_dir/h2def.py $h > defs/$(basename $h .h).defs
	echo "#include \"$h\"" >> $module-includes.h
done
$codegen_dir/createdefs.py $module.defs $module-extras.defs defs/*.defs

# Apply some transformations to the generated .defs

# Remove duplicate class definitions
function remove_duplicate_object()
{
    defs_file=$1
    class=$2
    type_id=$3
    sed -i.bak "/^(define-object $class\$/,/^)/{:x; N; s/.*(gtype-id \"$type_id\")\n)//; Tx; :y; N; s/.*(gtype-id \"$type_id\")\n)/&/; Ty }" $defs_file
    diff -u $defs_file.bak $defs_file && echo "WARNING: $defs_file is unchanged" || true
    rm $defs_file.bak
}

# Turn a function into a method of a class
function to_method()
{
    defs_file=$1
    fn=$2
    meth=$3
    class=$4
    sed -i.bak "s/^(define-function $fn$/(define-method $meth\n  (of-object \"$class\")/" $defs_file
    diff -u $defs_file.bak $defs_file && echo "WARNING: $defs_file is unchanged" || true
    rm $defs_file.bak
}

# Add a field to a object definition
function add_field
{
    defs_file=$1
    class=$2
    c_type=$3
    name=$4
    sed -i.bak "/^(define-object $class\$/{:x; N; s/\n)/&/; Tx; s/\n  (fields/&\n   '(\"$c_type\" \"$name\")/; t end; s/\n)/\n  (fields\n   '(\"$c_type\" \"$name\")\n  )&/; :end }" $defs_file
    diff -u $defs_file.bak $defs_file && echo "WARNING: $defs_file is unchanged" || true
    rm $defs_file.bak
}

# Strip module name from functions
function strip_module_prefix
{
    defs_file=$1
    mod=$2
    sed -i.bak "/^(define-function/s/ ${mod}_/ /" $defs_file
    diff -u $defs_file.bak $defs_file && echo "WARNING: $defs_file is unchanged" || true
    rm $defs_file.bak
}

remove_duplicate_object defs/location-gps-device.defs GPSDevice LOCATION_TYPE_GPS_DEVICE
remove_duplicate_object defs/location-gpsd-control.defs GPSDControl LOCATION_TYPE_GPSD_CONTROL
to_method defs/location-gpsd-control.defs location_gpsd_control_get_default get_default LocationGPSDControl
add_field defs/location-gps-device.defs GPSDevice gboolean online
add_field defs/location-gps-device.defs GPSDevice LocationGPSDeviceStatus status
add_field defs/location-gps-device.defs GPSDevice 'LocationGPSDeviceFix*' fix
add_field defs/location-gps-device.defs GPSDevice int satellites_in_view
add_field defs/location-gps-device.defs GPSDevice int satellites_in_use
# FIXME: not supported yet
#add_field defs/location-gps-device.defs GPSDevice 'GPtrArray*' satellites
#add_field defs/location-gps-device.defs GPSDevice 'LocationCellInfo*' cell_info
strip_module_prefix defs/location-misc.defs $module
strip_module_prefix defs/location-distance-utils.defs $module

#echo Generating $module-types.c and $module-types.h...
## It is necessary to create some enum introspection declarations missing from headers.
glib-mkenums --template $module-types-template.h $headers $extra_headers > $module-types.h
glib-mkenums --template $module-types-template.c $headers $extra_headers > $module-types.c

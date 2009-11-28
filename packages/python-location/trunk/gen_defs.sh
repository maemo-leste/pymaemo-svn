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

remove_duplicate_object defs/location-gps-device.defs GPSDevice LOCATION_TYPE_GPS_DEVICE
remove_duplicate_object defs/location-gpsd-control.defs GPSDControl LOCATION_TYPE_GPSD_CONTROL

#echo Generating $module-types.c and $module-types.h...
## It is necessary to create some enum introspection declarations missing from headers.
glib-mkenums --template $module-types-template.h $headers $extra_headers > $module-types.h
glib-mkenums --template $module-types-template.c $headers $extra_headers > $module-types.c

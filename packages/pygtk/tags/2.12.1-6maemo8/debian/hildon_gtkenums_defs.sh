#!/bin/bash
set -e

tmp_h=$(mktemp -t)

trap "rm -rf $tmp_h" EXIT

sed -n '/^#ifdef MAEMO_CHANGES/,/^#endif/p' /usr/include/gtk-2.0/gtk/gtkenums.h > $tmp_h
./codegen/h2def.py --onlyenums $tmp_h

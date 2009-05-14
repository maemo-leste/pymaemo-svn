#!/bin/sh

set -e

mkdir -p /tmp/python-gtk2-tests
cp /usr/share/python-gtk2-tests/gtk_baseline.txt /tmp/python-gtk2-tests
cd /tmp/python-gtk2-tests
python2.5 /usr/share/python-gtk2-tests/api_dump.py gtk
cd -
cmp -s /tmp/python-gtk2-tests/gtk.txt /tmp/python-gtk2-tests/gtk_baseline.txt

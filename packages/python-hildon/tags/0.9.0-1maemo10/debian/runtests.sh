#!/bin/sh

set -e

mkdir -p /tmp/python-hildon-tests
cd /usr/share/python-hildon-tests 
python2.5 test_all.py > /tmp/python-hildon-tests/testresults.txt 2>&1
cd -

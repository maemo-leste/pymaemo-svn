#!/bin/sh

set -e

mkdir -p /tmp/python-mafw-tests
cd /usr/share/python-mafw-tests 
python2.5 test_all.py > /tmp/python-mafw-tests/testresults.txt 2>&1
cd -

#!/bin/sh
set -e

mkdir -p /tmp/python-xml-tests
python2.5 /usr/share/python-xml-tests/test/regrtest.py -v > /tmp/python-xml-tests/testresults.log 2>&1

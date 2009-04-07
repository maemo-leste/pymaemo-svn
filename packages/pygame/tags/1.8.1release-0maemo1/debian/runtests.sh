#!/bin/sh
set -e

mkdir -p /tmp/python-pygame-tests
python2.5 /usr/share/python-pygame-tests/run_tests.py > /tmp/python-pygame-tests/testresults.log 2>&1

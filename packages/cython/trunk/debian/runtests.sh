#!/bin/sh
set -e

mkdir -p /tmp/cython-tests

python2.5 /usr/share/cython-tests/runtests.py -vv > /tmp/cython-tests/testresults.log 2>&1
python2.5 /usr/share/python-support/cython/Cython/Compiler/Tests/TestTreeFragment.py > temp.txt 2>&1
echo >> /tmp/cython-tests/testresults.log; \
   echo "/usr/share/python-support/cython/Cython/Compiler/Tests/TestTreeFragment.py" >> /tmp/cython-tests/testresults.log; \
   cat temp.txt >> /tmp/cython-tests/testresults.log; \
   rm temp.txt

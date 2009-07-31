#!/bin/sh
set -e

mkdir -p /tmp/python-conic-tests

echo conic_monitor.py >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/conic_monitor.py > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log
echo test_automatic_events.py >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/test_automatic_events.py  > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log
echo test_connect.py  >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/test_connect.py  > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log
echo test_connect_by_id.py  >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/test_connect_by_id.py  > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log
echo test_disconnect.py  >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/test_disconnect.py  > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log
echo test_iap.py  >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/test_iap.py  > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log
echo test_proxies.py  >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/test_proxies.py  > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log
echo test_statistics.py  >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/test_statistics.py  > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log
echo test_two_objects.py  >> /tmp/python-conic-tests/testresults.log; python2.5 /usr/share/python-conic-tests/test_two_objects.py  > temp.txt 2>&1; cat temp.txt >> /tmp/python-conic-tests/testresults.log


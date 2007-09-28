#!/usr/bin/python2.5 

"""
Prints information about available IAPs.

Lauro Moura <lauro.neto@indt.org.br>, 2007
"""

import conic
import dbus
import dbus.glib
import gobject


def test_all_iaps(connection, loop):
    """ Tries to get info about all available IAPs """

    print "connection.get_all_iaps():"

    iaps = connection.get_all_iaps()

    assert iaps, 'Invalid list returned by connection.get_all_iaps()'
    print iaps

    for iap in iaps:
        print iap
        iap_id = iap.get_id()
        iap_name = iap.get_name()
        iap_bearer = iap.get_bearer_type()

        print "%s (%s) %s" % (iap_id, iap_name, iap_bearer)

    loop.quit()


def test_get_iap(connection):
    """ Tries to get info about one specific IAP"""

    print "connection.get_iap:"
    iap_name = "OSMTCAPN01"
    iap = connection.get_iap(iap_name)
    
    assert iap, "Invalid iap returned by connection.get_iap(\"%s\")" % iap_name
    
    iap_id = iap.get_id()
    iap_name = iap.get_name()
    iap_bearer = iap.get_bearer_type()

    print "get IAP osso.net: %s (%s) %s" % (iap_id, iap_name, iap_bearer)


def start(loop):
    
    print "(start)"
    connection = conic.Connection()
    
    test_all_iaps(connection, loop)
    test_get_iap(connection)
    
    return False


if __name__ == "__main__":

    loop = gobject.MainLoop()
    bus = dbus.SystemBus(private=True)
    
    gobject.idle_add(start, loop)
    
    loop.run()

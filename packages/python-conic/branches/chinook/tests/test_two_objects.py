#!/usr/bin/python2.5 

"""
Test automatic-connection-events

Lauro Moura <lauro.neto@indt.org.br>, 2007
"""

import conic
import dbus
import dbus.glib
import gobject

def connection_cb(connection, event, data):
    print "connection_cb(%s, %s, %x)" % (connection, event, data)
    
    status = event.get_status()
    error = event.get_error()
    iap_id = event.get_iap_id()
    bearer = event.get_bearer_type()
    
    if status == conic.STATUS_CONNECTED:
        print "1: (CONNECTED (%s, %s, %i, %i)" % (iap_id, bearer, status, error)
    elif status == conic.STATUS_DISCONNECTED:
        print "1: (DISCONNECTED (%s, %s, %i, %i)" % (iap_id, bearer, status, error)
    elif status == conic.STATUS_DISCONNECTING:
        print "1: (DISCONNECTING (%s, %s, %i, %i)" % (iap_id, bearer, status, error)


def connection_cb2(connection, event, data):
    print "connection_cb2(%s, %s, %x)" % (connection, event, data)
    
    status = event.get_status()
    error = event.get_error()
    iap_id = event.get_iap_id()
    bearer = event.get_bearer_type()
    
    if status == conic.STATUS_CONNECTED:
        print "2: (CONNECTED (%s, %s, %i, %i)" % (iap_id, bearer, status, error)
    elif status == conic.STATUS_DISCONNECTED:
        print "2: (DISCONNECTED (%s, %s, %i, %i)" % (iap_id, bearer, status, error)
    elif status == conic.STATUS_DISCONNECTING:
        print "2: (DISCONNECTING (%s, %s, %i, %i)" % (iap_id, bearer, status, error)


def connect1(loop):
    print "connect1"
    
    connection = conic.Connection()
    connection.connect("connection-event", connection_cb, 0xAA55)
    connection.set_property("automatic-connection-events", True)
    
    return False


def connect2(loop):
    print "connect2"
    
    connection = conic.Connection()
    connection.connect("connection-event", connection_cb2, 0xFAE0)    
    connection.request_connection(conic.CONNECT_FLAG_NONE)
    
    return False
    

if __name__ == "__main__":

    loop = gobject.MainLoop()
    bus = dbus.SystemBus(private=True)
    
    gobject.idle_add(connect1, loop)
    gobject.idle_add(connect2, loop)
    
    loop.run()

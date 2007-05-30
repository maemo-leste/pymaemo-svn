#!/usr/bin/python2.5 

"""
Simple example of Python-ConIC. Just creates a connection and connects it.

If the device isn't already connected, it will try to connect to the default
connection or will popup the connection selection dialog.

Author: Lauro Moura <lauro.neto@indt.org.br>, 2007
"""


import dbus
import gobject
import dbus.glib
import conic

magic = 0xAA55

def connection_cb(connection, event, magic):
    print "connection_cb(%s, %s, %x)" % (connection, event, magic)

    status = event.get_status()
    error = event.get_error()
    iap_id = event.get_iap_id()
    bearer = event.get_bearer_type()
    
    if status == conic.STATUS_CONNECTED:
        print "(CONNECTED (%s, %s, %i, %i)" % \
            (iap_id, bearer, status, error)
    elif status == conic.STATUS_DISCONNECTED:
        print "(DISCONNECTED (%s, %s, %i, %i)" % \
            (iap_id, bearer, status, error)
    elif status == conic.STATUS_DISCONNECTING:
        print "(DISCONNECTING (%s, %s, %i, %i)" % \
            (iap_id, bearer, status, error)


def connect():
    global magic
    print "connect():"

    # Creates the connection object and attach the handler.
    connection = conic.Connection()
    connection.connect("connection-event", connection_cb, magic)
    
    # The request_connection method should be called to initialize
    # some fields of the instance
    assert(connection.request_connection(conic.CONNECT_FLAG_NONE))

    return False


if __name__ == "__main__":

    loop = gobject.MainLoop()
    bus = dbus.SystemBus(private=True)
    
    gobject.idle_add(connect)
    
    loop.run()


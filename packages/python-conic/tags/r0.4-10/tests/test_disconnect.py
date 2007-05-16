#!/usr/bin/python2.5 

"""
Simple example of Python-ConIc: Disconnecting the current program.

NOTE: The disconnect method currently disconnects just the connection
instance. See the link below for more info on disconnecting the device.

http://maemo.org/pipermail/maemo-developers/2007-April/009462.html

Lauro Moura <lauro.neto@indt.org.br>, 2007
"""

import conic
import dbus
import gobject
import dbus.glib

magic = 0xacdcacdc

def disconnect(connection):
    print "disconnect(%s)" % connection

    # Disconnects this instance. Does *not* disconnects the device if there
    # are other applications connected.
    connection.disconnect()
    return False
    

def connection_cb(connection, event, magic, loop):
    print "connection_cb(%s, %s, %x)" % (connection, event, magic)
    
    status = event.get_status()
    error = event.get_error()
    iap_id = event.get_iap_id()
    bearer = event.get_bearer_type()
    
    if status == conic.STATUS_CONNECTED:
        print "(CONNECTED (%s, %s, %i, %i)" % (iap_id, bearer, status, error)
        gobject.timeout_add(2000, disconnect, connection)
    elif status == conic.STATUS_DISCONNECTED:
        print "(DISCONNECTED (%s, %s, %i, %i)" % (iap_id, bearer, status, error)
        loop.quit()
    elif status == conic.STATUS_DISCONNECTING:
        print "(DISCONNECTING (%s, %s, %i, %i)" % (iap_id, bearer, status, error)


def connect(loop):
    global magic
    
    connection = conic.Connection()
    connection.connect("connection-event", connection_cb, magic, loop)

    # Needed to associate the instance to the current connection
    assert(connection.request_connection(conic.CONNECT_FLAG_NONE))
    
    return False


if __name__ == "__main__":

    loop = gobject.MainLoop()
    bus = dbus.SystemBus(private=True)
    
    gobject.idle_add(connect, loop)

    loop.run()

#!/usr/bin/python2.5 

"""
Print ConIc 'connection-event' signals

Lauro Moura <lauro.neto@indt.org.br>, 2007
"""

import conic
import dbus
import dbus.glib
import gobject


def connection_cb(connection, event, magic):
    print "connection_cb(%s, %s, %x)" % (connection, event, magic)
    
    status = event.get_status()
    error = event.get_error()
    iap_id = event.get_iap_id()
    bearer = event.get_bearer_type()
    
    if status == conic.STATUS_CONNECTED:
        print "(CONNECTED (%s, %s, %i, %i)" % (iap_id, bearer, status, error)
    elif status == conic.STATUS_DISCONNECTED:
        print "(DISCONNECTED (%s, %s, %i, %i)" % (iap_id, bearer, status, error)
    elif status == conic.STATUS_DISCONNECTING:
        print "(DISCONNECTING (%s, %s, %i, %i)" % (iap_id, bearer, status, error)


def connect():
    
    connection = conic.Connection()
    connection.connect("connection-event", connection_cb)
    assert(connection.request_connection(conic.CONNECT_FLAG_NONE))
    
    return False


if __name__ == "__main__":

    loop = gobject.MainLoop()
    bus = dbus.SystemBus(private=True)
    
    gobject.idle_add(connect)
    
    loop.run()

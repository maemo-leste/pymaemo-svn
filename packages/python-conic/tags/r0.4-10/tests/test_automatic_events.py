#!/usr/bin/python2.5 

"""
Test automatic events. From the api:

"If set to true, application will receive connection-events automatically as
connections are established and tore down. Normally events are only sent when
applications request for a connection, with this all events are received
constantly. This makes it possible, for example, to create an application
which executes something from the network every time a connection is
established."

Lauro Moura <lauro.neto@indt.org.br>, 2007
"""

import conic
import dbus
import gobject
import dbus.glib

def start():
    print "start():"
    connection = conic.Connection()
    connection.connect("connection-event", connection_cb)
    connection.set_property("automatic-connection-events", True)
    
    return connection

    
def stop(connection, loop):
    print "start():"
    connection.set_property("automatic-connection-events", False)
    loop.quit()
    

def connection_cb(connection, event):
    print "connection_cb(%s, %s)" % (connection, event)
    
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
   

if __name__ == "__main__":

    loop = gobject.MainLoop()
    bus = dbus.SystemBus(private=True)
    
    connection = start()
    loop.run()
    stop(connection, loop)

#!/usr/bin/python2.5 

"""
 Tests conic.Connection.get_proxy_*

 Lauro Moura <lauro.neto@indt.org.br>, 2007
"""

import conic
import dbus
import dbus.glib
import gobject


def test_proxies(connection, loop):

    print "proxy_mode=%i" % connection.get_proxy_mode()

    print "HTTP proxy_host=%s" % connection.get_proxy_host(conic.PROXY_PROTOCOL_HTTP)
    print "HTTP proxy_port=%i" % connection.get_proxy_port(conic.PROXY_PROTOCOL_HTTP)

    print "HTTPS proxy_host=%s" % connection.get_proxy_host(conic.PROXY_PROTOCOL_HTTPS)
    print "HTTPS proxy_port=%i" % connection.get_proxy_port(conic.PROXY_PROTOCOL_HTTPS)

    print "FTP proxy_host=%s" % connection.get_proxy_host(conic.PROXY_PROTOCOL_FTP)
    print "FTP proxy_port=%i" % connection.get_proxy_port(conic.PROXY_PROTOCOL_FTP)

    print "RTSP proxy_host=%s" % connection.get_proxy_host(conic.PROXY_PROTOCOL_RTSP)
    print "RTSP proxy_port=%i" % connection.get_proxy_port(conic.PROXY_PROTOCOL_RTSP)

    print "SOCKS proxy_host=%s" % connection.get_proxy_host(conic.PROXY_PROTOCOL_SOCKS)
    print "SOCKS proxy_port=%i" % connection.get_proxy_port(conic.PROXY_PROTOCOL_SOCKS)

    print "autoconfig_url=%s" % connection.get_proxy_autoconfig_url()

    loop.quit()


def connection_cb(connection, event, loop):
    status = event.get_status()
    
    if status == conic.STATUS_CONNECTED:
        test_proxies(connection, loop)


def start(loop):
    
    print "(start)"
    connection = conic.Connection()
    connection.connect("connection-event", connection_cb, loop)
    connection.request_connection(conic.CONNECT_FLAG_NONE)
    
    return False


if __name__ == "__main__":

    loop = gobject.MainLoop()
    bus = dbus.SystemBus(private=True)
    
    gobject.idle_add(start, loop)
    
    loop.run()

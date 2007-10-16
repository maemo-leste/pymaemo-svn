#!/usr/bin/env python2.5

import gtk
import hildon

def cb(*args, **kargs):
    print args
    print kwargs

def foo(menu):
    print menu
    x, y = menu.get_pointer()

    return (x+10, y+10,False)

def main():
    print "gtk.Widget tap and hold members: "
    print [x for x in dir(gtk.Widget) if 'tap' in x]

    window = hildon.Window()
    window.connect("destroy", gtk.main_quit)

    menu = gtk.Menu()
    for i in range(3):
        item = gtk.MenuItem("Item %d" % i)
        menu.append(item)
        item.connect("activate", cb)
        item.show()

    menu.show()

    label = gtk.Button("Tap test")

    label.tap_and_hold_setup(menu=menu, callback=foo)
    print menu.get_attach_widget()
    window.add(label)

    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()

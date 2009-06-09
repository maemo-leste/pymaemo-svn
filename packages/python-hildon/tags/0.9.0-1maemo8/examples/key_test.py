#!/usr/bin/env python2.5

import hildon
import gtk

def key_pressed_cb(widget, event, label):
    if event.keyval == hildon.KEY_UP:
        label.set_text("Up")
    elif event.keyval == hildon.KEY_DOWN:
        label.set_text("Down")
    elif event.keyval == hildon.KEY_LEFT:
        label.set_text("Left")
    elif event.keyval == hildon.KEY_RIGHT:
        label.set_text("Right")
    elif event.keyval == hildon.KEY_SELECT:
        label.set_text("SELECT")
    elif event.keyval == hildon.KEY_MENU:
        label.set_text("Menu")
    elif event.keyval == hildon.KEY_HOME:
        label.set_text("Home")
    elif event.keyval == hildon.KEY_ESC:
        label.set_text("Esc")
    elif event.keyval == hildon.KEY_FULLSCREEN:
        label.set_text("Fullscreen")
    elif event.keyval == hildon.KEY_INCREASE:
        label.set_text("Increase")
    elif event.keyval == hildon.KEY_DECREASE:
        label.set_text("Decrease")

def main():
    window = hildon.Window()
    window.connect("destroy", gtk.main_quit)

    label = gtk.Label("press any key")
    window.add(label)
    
    window.connect("key-press-event", key_pressed_cb, label)

    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()

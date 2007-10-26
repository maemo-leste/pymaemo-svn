#!/usr/bin/env python2.5

import gtk
import hildon

class ColorButtonExample:

    def __init__(self):
        self.window = hildon.Window()
        self.window.connect("destroy", gtk.main_quit)

        hbox = gtk.HBox()
        self.button = gtk.Button("Selected Color")
        self.button.connect("clicked", self.check_color)
        self.evtBox = gtk.EventBox()
        self.evtBox.add(self.button)
        hbox.pack_start(self.evtBox)

        self.colorbutton = hildon.ColorButton()
        hbox.pack_start(self.colorbutton)

        self.window.add(hbox)
        self.window.show_all()

    def check_color(self, button):
        color = self.colorbutton.get_color()
        print "Color %s as Red: %d, Green %d, Blue %d" % (color, color.red, color.green, color.blue)



def main():
    gtk.main()

if __name__ == "__main__":
    cbe = ColorButtonExample()
    main()

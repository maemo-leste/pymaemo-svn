#!/usr/bin/env python2.5

import gtk 
import hildon

window = hildon.Window()
window.connect("destroy", gtk.main_quit)
label = gtk.Label("Hello World!")
window.add(label)

label.show()
window.show()

gtk.main()
#!/usr/bin/env python2.5
import gtk
import hildon

class HelloWorldApp(hildon.Program):
  def __init__(self):
    hildon.Program.__init__(self)

    self.window = hildon.Window()
    self.window.connect("destroy", gtk.main_quit)
    self.add_window(self.window)

    label = gtk.Label("Hello World!")
    self.window.add(label)
    label.show()

  def run(self):
    self.window.show_all()
    gtk.main()

app = HelloWorldApp()
app.run()
#!/usr/bin/env python2.5

import gtk
import hildon
import hildonhelp
import osso

class HelpTest:
    def __init__(self):
        self.context = osso.Context("example_hildon_help", "0.1", False)
        self.window = hildon.Window()
        self.window.connect("delete-event", gtk.main_quit)

        self.vbox = gtk.VBox()

        self.btn_show = gtk.Button("hildon help show")
        self.btn_show.connect("clicked", self.show_help)
        self.vbox.pack_start(self.btn_show)

        self.btn_dlg = gtk.Button("hildon help dialog help enable")
        self.btn_dlg.connect("clicked", self.show_diag)
        self.vbox.pack_start(self.btn_dlg)
        
        self.window.add(self.vbox)

        self.window.show_all()

    def show_help(self, button, data=None):
        topic = "//chess/a/1"
        hildonhelp.help_show(self.context, topic, 0)
        
    def show_diag(self, button, data=None):
        dialog = gtk.Dialog("Help Dialog", self.window,
                            0,
                            (gtk.STOCK_CANCEL, gtk.RESPONSE_REJECT,
                             gtk.STOCK_OK, gtk.RESPONSE_ACCEPT))
        topic = "//chess/a/1"
        dialog.vbox.pack_start(gtk.Label("Test Label"))
        dialog.vbox.show_all()
        print hildonhelp.help_dialog_help_enable(dialog,topic, self.context)
        
        dialog.run()
        dialog.destroy()

if __name__ == "__main__":
    prog = HelpTest()
    gtk.main()

#!/usr/bin/python2.5

import gtk
import abook
import osso
import evolution.ebook as evo
import hildon

class CanBlockAndRequestAuthExample(hildon.Program):
    """
    Small test for abook.contact_can_block and abook.contact_can_request_auth
    """
    def __init__(self):
        hildon.Program.__init__(self)

        # Init
        self.context = osso.Context("showcontacts", "0.0.1", False)
        abook.init("showcontacts", self.context)

        # Window
        self.window = hildon.Window()
        self.window.connect("destroy", gtk.main_quit)
        self.add_window(self.window)

        # Evolution stuff
        self.book = evo.open_addressbook("default")
        query = evo.EBookQuery.field_exists(evo.CONTACT_FULL_NAME)

        self.bookview = self.book.get_book_view(query)
        self.bookview.start()

        self.model = abook.ContactModel(self.bookview)
        self.view = abook.ContactSelector(self.model)

        self.bar = abook.AlphaBar(self.view)
        btbar = self.bar.create_button_row()

        button = gtk.Button("Check contact permission")
        button.connect("clicked", self.check_contact)

        vbox = gtk.VBox()
        vbox.pack_start(self.view)
        vbox.pack_start(btbar)
        vbox.pack_start(button)

        # Menu stuf...

        self.window.add(vbox)

        self.window.show_all()

    def run(self):
        gtk.main()

    def check_contact(self, item):
        contacts = self.view.get_extended_selection()

        if len(contacts) == 0:
            return

        contact = contacts[0]

        canblock = abook.contact_can_block(contact)
        canauth = abook.contact_can_request_auth(contact)

        dialog = gtk.Dialog()
        dialog.add_button(gtk.STOCK_CLOSE, 0)

        dialog.vbox.pack_start(gtk.Label("Contact can block: "+str(canblock)))
        dialog.vbox.pack_start(gtk.Label("Contact can request auth: "+str(canauth)))

        dialog.vbox.show_all()
        dialog.run()
        dialog.destroy()

if __name__ == "__main__":
    prog = CanBlockAndRequestAuthExample()

    prog.run()

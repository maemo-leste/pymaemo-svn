#!/usr/bin/python2.5

import gtk
import abook
import osso
import evolution.ebook as evo
import hildon

class ShowContacts(hildon.Program):
    """
    Simple test of abook.ContactModel.get_iter.
    """
    def __init__(self):
        hildon.Program.__init__(self)

        self.context = osso.Context("showcontacts", "0.0.1", False)
        abook.init("showcontacts", self.context)

        self.window = hildon.Window()
        self.window.connect("destroy", gtk.main_quit)
        self.add_window(self.window)
        self.book = evo.open_addressbook("default")
        query = evo.EBookQuery.field_exists(evo.CONTACT_FULL_NAME)

        self.bookview = self.book.get_book_view(query)
        self.bookview.start()

        self.model = abook.ContactModel(self.bookview)
        self.view = abook.ContactView(self.model)
        self.view.connect("contact-activated", self.contact_activated)

        self.bar = abook.AlphaBar(self.view)
        btbar = self.bar.create_button_row()

        vbox = gtk.VBox()

        vbox.pack_start(self.view)
        vbox.pack_start(btbar, False, False)

        self.window.add(vbox)

        self.window.show_all()

    def run(self):
        gtk.main()

    def contact_activated(self, view, contact):
        print "Contact-activated()"
        uid = contact.get_uid()
        iter = self.model.get_iter(uid)
        cont = self.model.get(iter, abook.CONTACT_MODEL_COL_CONTACT)[0]
        print cont.get_uid()
        print contact.get_uid()


if __name__ == "__main__":
    prog = ShowContacts()

    prog.run()

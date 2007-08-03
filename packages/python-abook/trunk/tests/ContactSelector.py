#!/usr/bin/python2.5

import gtk
import abook
import osso
import evolution.ebook as evo
import hildon

class ContactSelectorExample(hildon.Program):
    """
    Example class for ContactSelector, which derives from ContactView.

    In order to get the checked contacts, use ContactSelector.get_extended_selection.
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

        button = gtk.Button("Delete selected contacts")
        button.connect("clicked", self.delete_contacts)

        vbox = gtk.VBox()
        vbox.pack_start(self.view)
        vbox.pack_start(btbar)
        vbox.pack_start(button)

        # Menu stuf...

        self.window.add(vbox)

        self.window.show_all()

    def run(self):
        gtk.main()

    def delete_contacts(self, item):
        contacts = self.view.get_extended_selection()
        abook.delete_contacts_dialog_run(self.window,
                                         self.bookview,
                                         contacts)

if __name__ == "__main__":
    prog = ContactSelectorExample()

    prog.run()

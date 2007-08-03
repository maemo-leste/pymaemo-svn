#!/usr/bin/python2.5

import gtk
import gobject
import abook
import osso
import evolution.ebook as evo
import hildon

class ContactEditorExample(hildon.Program):
    """
    Example class for abook.ContactEditor, with callback for new contacts.
    """
    def __init__(self):
        hildon.Program.__init__(self)

        self.context = osso.Context("filtermodelexample", "0.0.1", False)
        abook.init("filtermodelexample", self.context)

        self.window = hildon.Window()
        self.window.connect("destroy", gtk.main_quit)
        self.add_window(self.window)

        self.book = evo.open_addressbook("default")
        query = evo.EBookQuery.field_exists(evo.CONTACT_FULL_NAME)

        self.bookview = self.book.get_book_view(query)
        self.bookview.start()

        self.model = abook.ContactModel(self.bookview)
        self.view = abook.ContactView(self.model)

        button = gtk.Button("Edit contact")
        button.connect("clicked", self.edit_contact)

        vbox = gtk.VBox()
        vbox.pack_start(self.view)
        vbox.pack_start(button, expand=False, padding=5)

        self.window.add(vbox)
        self.window.show_all()

    def run(self):
        gtk.main()

    def edit_contact(self, button):
        contacts = self.view.get_selection()

        if len(contacts) == 0:
            return

        contact = contacts[0]

        dialog = abook.ContactEditor()
        dialog.set_book_view(self.bookview)
        dialog.set_contact(contact)
        dialog.run()
        dialog.destroy()


if __name__ == "__main__":
    prog = ContactEditorExample()
    prog.run()

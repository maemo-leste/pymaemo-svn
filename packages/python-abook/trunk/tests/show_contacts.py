#!/usr/bin/python2.5

import gtk
import abook
import osso
import evolution.ebook as evo
import hildon

class ShowContacts(hildon.Program):
    """
    Example class for ContactModel/View, AlphaBar, ContactStarter
    and Dialog classes.
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
        vbox.pack_start(btbar)

        # Menu stuf...

        self.menu = gtk.Menu()

        item_add = gtk.MenuItem("Add Account To Contact")
        self.menu.append(item_add)
        item_add.connect("activate", self.add_to_contact)

        item_block = gtk.MenuItem("Block Manager")
        self.menu.append(item_block)
        item_block.connect("activate", self.block_manager)

        item_edit = gtk.MenuItem("Edit Contact")
        self.menu.append(item_edit)
        item_edit.connect("activate", self.edit_contact)

        item_new = gtk.MenuItem("New Contact")
        self.menu.append(item_new)
        item_new.connect("activate", self.edit_contact, True)

        item_edit_group = gtk.MenuItem("Edit Contact Groups")
        self.menu.append(item_edit_group)
        item_edit_group.connect("activate", self.edit_groups)

        item_auth = gtk.MenuItem("Request Auth")
        self.menu.append(item_auth)
        item_auth.connect("activate", self.request_auth)

        self.window.set_menu(self.menu)
        self.window.add(vbox)

        self.window.show_all()

    def run(self):
        gtk.main()

    def add_to_contact(self, item):
        print "add_to_contact()"

        contact = self.view.get_selection()[0]
        accounts = abook.contact_get_accounts(contact)
        dialog = abook.AddToContactsDialog(self.model, accounts[0])
        dialog.run()
        dialog.destroy()

    def block_manager(self, item):
        print "block_manager()"
        dialog = abook.BlockManager(self.model)
        dialog.run()
        dialog.destroy()

    def contact_activated(self, view, contact):
        print "Contact-activated()"
        starter = abook.ContactStarter()
        starter.set_book_view(self.bookview)
        starter.set_contact(contact)
        starter.run()
        starter.destroy()

    def edit_contact(self, item, new=False):
        print "edit_contact()"
        dialog = abook.ContactEditor()
        dialog.set_book_view(self.bookview)

        if not new:
            try:
                contact = self.view.get_selection()[0]
                dialog.set_contact(contact)
            except IndexError:
                return

        dialog.run()
        dialog.destroy()

    def edit_groups(self, item):
        print "edit_groups()"
        dialog = abook.ContactGroupEditor()

        try:
            contact = self.view.get_selection()[0]
            dialog.set_contact(contact)
        except IndexError:
            return

        dialog.run()

        # Needed to save the modifications.
        if contact:
            self.book.commit_contact(contact)

        dialog.destroy()

    def request_auth(self, item):
        print "request_auth()"
        dialog = abook.RequestAuthDialog()

        try:
            contact = self.view.get_selection()[0]
            dialog.set_contact(contact)
        except IndexError:
            return

        print dialog.run()
        dialog.destroy()

if __name__ == "__main__":
    prog = ShowContacts()

    prog.run()

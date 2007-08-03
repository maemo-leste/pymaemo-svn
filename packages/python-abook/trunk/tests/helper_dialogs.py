#!/usr/bin/python2.5

import gtk
import abook
import osso
import evolution.ebook as evo
import hildon

class HelperDialogs(hildon.Program):
    """
    Example class for ContactModel/View, GroupModel/View and helper
    dialogs.
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
        self.view = abook.ContactView(self.model)
        self.view.connect("contact-activated", self.contact_activated)

        self.bar = abook.AlphaBar(self.view)
        btbar = self.bar.create_button_row()

        self.groupmodel = abook.GroupModel()
        self.groupview = abook.GroupView(self.groupmodel)

        hbox = gtk.HBox()
        hbox.pack_start(self.view)
        hbox.pack_start(self.groupview)

        vbox = gtk.VBox()
        vbox.pack_start(hbox)
        vbox.pack_start(btbar)

        # Menu stuf...

        self.menu = gtk.Menu()

        item = gtk.MenuItem("Delete Contact")
        self.menu.append(item)
        item.connect("activate", self.delete_contact)

        item = gtk.MenuItem("Delete All Contacts")
        self.menu.append(item)
        item.connect("activate", self.delete_all_contacts)

        item = gtk.MenuItem("Add a contact")
        self.menu.append(item)
        item.connect("activate", self.add_contact)

        item = gtk.MenuItem("Block contact")
        self.menu.append(item)
        item.connect("activate", self.block_contact)

        item = gtk.MenuItem("New group")
        self.menu.append(item)
        item.connect("activate", self.new_group)

        item = gtk.MenuItem("Rename group")
        self.menu.append(item)
        item.connect("activate", self.rename_group)

        item = gtk.MenuItem("Delete group")
        self.menu.append(item)
        item.connect("activate", self.delete_group)

        item = gtk.MenuItem("Choose email")
        self.menu.append(item)
        item.connect("activate", self.choose_email)

        item = gtk.MenuItem("Choose IM")
        self.menu.append(item)
        item.connect("activate", self.choose_im)

        self.window.set_menu(self.menu)
        self.window.add(vbox)

        self.window.show_all()

    def run(self):
        gtk.main()

    def delete_contact(self, item):
        contact = self.view.get_selection()[0]

        abook.delete_contact_dialog_run(self.window, self.bookview,
                                        contact)

    def delete_all_contacts(self, item):
        citer = self.model.get_iter_first()
        contacts = []

        while citer != None:
            contact, = self.model.get(citer,
                         int(self.model.get_property("contact_column")))
            contacts.append(contact)
            citer = self.model.iter_next(citer)

        abook.delete_contacts_dialog_run(self.window,
                                         self.bookview,
                                         contacts)

    def add_contact(self, item):
        abook.add_contact_dialog_run(self.window, self.bookview)

    def block_contact(self, item):
        contact = self.view.get_selection()[0]
        abook.block_contact_dialog_run(self.window, self.bookview,
                                       contact)

    def new_group(self, item):
        abook.new_group_dialog_run(self.window)

    def rename_group(self, item):
        group = self.groupview.get_focus()
        if group:
            abook.rename_group_dialog_run(self.window, self.model,
                                      group)

    def delete_group(self, item):
        group = self.groupview.get_focus()
        if group:
            abook.delete_group_dialog_run(self.window, self.model,
                                      group)

    def choose_email(self, item):
        contact = self.view.get_selection()[0]
        print abook.choose_email_dialog_run(self.window, contact)

    def choose_im(self, item):
        contact = self.view.get_selection()[0]
        print abook.choose_im_dialog_run(self.window, contact,
                                         abook.ACCOUNT_TYPE_CHAT)

    def contact_activated(self, view, contact):
        print "Contact-activated()"
        starter = abook.ContactStarter()
        starter.set_book_view(self.bookview)
        starter.set_contact(contact)
        starter.run()
        starter.destroy()

if __name__ == "__main__":
    prog = HelperDialogs()

    prog.run()

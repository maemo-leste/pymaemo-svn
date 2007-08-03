#!/usr/bin/python2.5

import gtk
import abook
import osso
import evolution.ebook as evo
import hildon

class GroupSelectorExample(hildon.Program):
    """
    Example class for GroupSelector, which derives from GroupSelector.

    In order to get the checked groups, use ContactSelector.get_extended_selection.
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

        self.model = abook.GroupModel()
        self.view = abook.GroupSelector(self.model)

        button = gtk.Button("Show contacts")
        button.connect("clicked", self.show_group)

        vbox = gtk.VBox()
        vbox.pack_start(self.view)
        vbox.pack_start(button)

        # Menu stuf...

        self.window.add(vbox)

        self.window.show_all()

    def run(self):
        gtk.main()

    def show_group(self, item):
        groups = self.view.get_extended_selection()

        dialog = gtk.Dialog()
        for i in groups:
            dialog.vbox.pack_start(gtk.Label(i.get_display_name()))

        dialog.vbox.show_all()

        dialog.add_button(gtk.STOCK_CLOSE, 0)

        dialog.run()
        dialog.destroy()


if __name__ == "__main__":
    prog = GroupSelectorExample()

    prog.run()

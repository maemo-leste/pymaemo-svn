#!/usr/bin/python2.5

import gtk
import abook
import osso
import evolution.ebook as evo
import hildon

class ShowAccounts(hildon.Program):
    def __init__(self):
        hildon.Program.__init__(self)

        self.context = osso.Context("showaccounts", "0.0.1", False)
        abook.init("showaccounts", self.context)

        self.window = hildon.Window()
        self.window.connect("destroy", gtk.main_quit)
        self.add_window(self.window)

        self.book = evo.open_addressbook("default")
        query = evo.EBookQuery.field_exists(evo.CONTACT_FULL_NAME)

        self.bookview = self.book.get_book_view(query)
        self.bookview.start()

        # Needs to set the bookview after creating the model
        self.model = abook.AccountModel(abook.ACCOUNT_TYPE_ALL)
        self.model.set_book_view(self.bookview)

        self.view = abook.AccountSelector(self.model)
        self.window.add(self.view)

        self.window.show_all()

    def run(self):
        gtk.main()


if __name__ == "__main__":
    prog = ShowAccounts()
    prog.run()

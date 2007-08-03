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

        self.model = abook.AccountModel(abook.ACCOUNT_TYPE_ALL)

        self.view = abook.AccountView(self.model)
        self.window.add(self.view)

        self.window.show_all()

    def run(self):
        gtk.main()


if __name__ == "__main__":
    prog = ShowAccounts()
    prog.run()

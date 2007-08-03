#!/usr/bin/python2.5

import gtk
import abook
import osso
import evolution.ebook as evo

def main():
    context = osso.Context("selectdialog", "0.0.1", False)
    abook.init("selectdialog", context)

    book = evo.open_addressbook("default")
    query = evo.EBookQuery.field_exists(evo.CONTACT_FULL_NAME)

    bookview = book.get_book_view(query)
    bookview.start()

    model = abook.ContactModel(bookview)
    view = abook.ContactView(model)

    dialog = abook.SelectDialog(tree_view=view, new_contact=True)
    dialog.run()
    dialog.destroy()

if __name__ == "__main__":
    main()

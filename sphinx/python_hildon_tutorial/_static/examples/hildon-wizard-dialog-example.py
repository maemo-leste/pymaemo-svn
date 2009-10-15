# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 2.5, "Example of a Hildon wizard dialog"

import sys

import gtk
import hildon

def on_page_switch(notebook, page, num, dialog):
    print >>sys.stderr, "Page %d" % num
    return True

def some_page_func(nb, current, userdata):
    # Validate data only for the third page.
    if current == 2:
        entry = nb.get_nth_page(current)
        return len(entry.get_text()) != 0
    else:
        return True

def main():
    # Create a notebook
    notebook = gtk.Notebook()

    # Create widgets to palce into the notebook's pages
    label_1 = gtk.Label("Page 1")
    label_2 = gtk.Label("Page 2")

    entry_3 = hildon.Entry(gtk.HILDON_SIZE_AUTO)
    entry_3.set_placeholder("Write something to continue")

    label_4 = gtk.Label("Page 4")

    # Append pages
    notebook.append_page(label_1, None)
    notebook.append_page(label_2, None)
    notebook.append_page(entry_3, None)
    notebook.append_page(label_4, None)

    # Create wizard dialog
    dialog = hildon.WizardDialog(None, "Wizard", notebook)

    # Set a handler for "switch-page" signal
    notebook.connect("switch-page", on_page_switch, dialog)

    # Set a function to decide if user can go to next page
    dialog.set_forward_page_func(some_page_func)

    dialog.show_all()
    dialog.run()

if __name__ == "__main__":
    main()

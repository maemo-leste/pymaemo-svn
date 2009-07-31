# Example of a Hildon wizard dialog
# Based on C example from Hildon Tutorial (example 2.5)
import sys

import gtk
import hildon

def main():
    notebook = gtk.Notebook()
    label_1 = gtk.Label("Page 1")
    label_2 = gtk.Label("Page 2")

    entry_3 = hildon.Entry(gtk.HILDON_SIZE_AUTO)
    entry_3.set_placeholder("Write something to continue")

    label_4 = gtk.Label("Page 4")

    notebook.append_page(label_1, None)
    notebook.append_page(label_2, None)
    notebook.append_page(entry_3, None)
    notebook.append_page(label_4, None)

    dialog = hildon.WizardDialog(None, "Wizard", notebook)

    def on_page_switch(n, p, num, d):
        print >>sys.stderr, "Page %d" % num
        return True

    def some_page_func(n, current, userdata):
        if current == 2:
            entry = n.get_nth_page(current)
            return len(entry.get_text()) != 0
        return True

    notebook.connect("switch-page", on_page_switch, dialog)

    dialog.set_forward_page_func(some_page_func)

    dialog.show_all()
    dialog.run()

if __name__ == "__main__":
    main()

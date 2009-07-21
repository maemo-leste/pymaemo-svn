# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 4.1, "Using a Find Toolbar"

import sys

import gobject
import gtk
import hildon

def on_history_append(toolbar, user_data):
    # Get last added index
    index = toolbar.get_last_index()

    # Get the inner list
    list = toolbar.get("list")

    # Get the item
    iter = list.get_iter_from_string("%d" % index)

    item, = list.get(iter, 0)

    print >>sys.stderr, "ADDED TO THE LIST : %s" % item

def main():
    program = hildon.Program.get_instance()
    window = hildon.Window()

    program.add_window(window)

    # Create and populate history list model
    store = gtk.ListStore(gobject.TYPE_STRING)

    iter = store.append()
    store.set(iter, 0, "Foo")

    iter = store.append()
    store.set(iter, 0, "Bar")

    iter = store.append()
    store.set(iter, 0, "Baz")

    # Create find toolbar
    toolbar = hildon.FindToolbar("Find", store, 0)

    # Set item on index 0 as the current active
    toolbar.set_active(0)

    # Attach a callback to handle "history-append" signal
    toolbar.connect_after("history-append", on_history_append, None)

    # Attach toolbar to window
    window.add_toolbar(toolbar)

    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()

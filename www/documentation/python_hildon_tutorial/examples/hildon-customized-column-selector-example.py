# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 6.2 "Example of a selector with a custom column"

import gtk
import hildon
import gobject

def selection_changed(selector, user_data):
    current_selection = selector.get_current_text()
    print "Current selection : %s" % (current_selection)

def create_customized_selector():
    # Create a touch selector 
    selector = hildon.TouchSelector()

    # Stock icons will be used for the example
    icon_list = gtk.stock_list_ids()

    # Create model to store selector's items 
    store_icons = gtk.ListStore(gobject.TYPE_STRING);

    # Populate model
    for item in icon_list:
        new_iter = store_icons.append()
        store_icons.set(new_iter, 0, item)

    # Create and set up a pixbuf renderer to use in the selector 
    renderer = gtk.CellRendererPixbuf() 
    renderer.set_fixed_size(-1, 100)

    # Add the column to the selector
    column = selector.append_column(store_icons, renderer, stock_id=0)

    # Set the selection mode
    selector.set_column_selection_mode(hildon.TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE)

    # Set the property "text-column" that indicates the column
    # of the model to get the string from
    column.set_property("text-column", 0)

    return selector

def app_quit(widget, data=None):
    gtk.main_quit()

def main():
    program = hildon.Program.get_instance()
    gtk.set_application_name("hildon-touch-selector example program")

    window = hildon.StackableWindow()
    program.add_window(window)

    # Create touch selector
    selector = create_customized_selector()
    window.add(selector)

    window.connect("destroy", app_quit)

    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()

# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 6.3, "Example of a Hildon picker button"

import gtk
import hildon
import gobject

def on_picker_value_changed(button, user_data=None):
    print "Newly selected value: %s\n" % button.get_value()

def app_quit(widget, data=None):
    gtk.main_quit()

def create_customized_selector():
    # Create a touch selector 
    selector = hildon.TouchSelector()

    # Stock icons will be used for the example
    icon_list = gtk.stock_list_ids()

    # Create model to store selector's items 
    store_icons = gtk.ListStore(gobject.TYPE_STRING)

    # Populate model
    for item in icon_list:
        new_iter = store_icons.append()
        store_icons.set(new_iter, 0, item)

    # Create and set up a pixbuf renderer to use in the selector 
    renderer = gtk.CellRendererPixbuf() 
    renderer.set_fixed_size(-1, 100)


    # Add the column to the selector
    # FIXME: bug 4646
    column = selector.append_column(store_icons, renderer, "stock-id", 0)

    # Set the selection mode
    selector.set_column_selection_mode(hildon.TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE)

    # Set the property "text-column" that indicates the column
    # of the model to get the string from
    column.set_property("text-column", 0)

    return selector

def main ():
    program = hildon.hildon_program_get_instance()
    gtk.set_application_name("hildon-touch-selector example program")

    window = hildon.StackableWindow()
    program.add_window(window)

    # Create touch selector
    selector = create_customized_selector()
    window.add(selector)

    # Create a picker button
    picker_button = hildon.PickerButton(hildon.SIZE_AUTO,
                                        hildon.BUTTON_ARRANGEMENT_VERTICAL)

    # Set a title to the button 
    picker_button.set_title("Select an item")

    # Attach the touch selector to the picker button
    picker_button.set_selector(selector)

    
    # Attach callback to the "value-changed" signal
    picker_button.connect("value-changed", on_picker_value_changed)

    # Add button to main window
    window.add(picker_button)

    window.connect("destroy", app_quit)
    window.show_all()
    gtk.main()

if __name__ == "__main__":
    main()

# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 5.6, "Example of a single-column selector"

import gtk
import hildon

def selection_changed(selector, user_data):
    current_selection = selector.get_current_text()
    print "Current selection : %s" % (current_selection)

def create_simple_selector():
    #Create a HildonTouchSelector with a single text column
    # selector = hildon.TouchSelector()
    selector = hildon.hildon_touch_selector_new_text()

    # Set selection mode to allow multiple selection
    selector.set_column_selection_mode(hildon.TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE)

    # Set a handler to "changed" signal 
    selector.connect("changed", selection_changed)

    # Populate selector 
    for i in range(10):
        label = "Item %d" % i
        # Add item to the column 
        selector.append_text(label)

    return selector

def app_quit(widget, data=None):
    gtk.main_quit()

def main():
    program = hildon.hildon_program_get_instance()
    gtk.set_application_name("hildon-touch-selector example program")

    window = hildon.StackableWindow()
    program.add_window(window)

    # Create touch selector
    selector = create_simple_selector()
    window.add(selector)

    window.connect("destroy", app_quit)

    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()

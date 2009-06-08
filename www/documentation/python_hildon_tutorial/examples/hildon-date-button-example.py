# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 6.5, "Example of a Hildon date button"

import gtk
import hildon

def app_quit(widget, data=None):
    gtk.main_quit()

def main ():
    program = hildon.hildon_program_get_instance()
    gtk.set_application_name("hildon-touch-selector example program")

    window = hildon.StackableWindow()
    program.add_window(window)

    # Create a date picker
    date_button = hildon.DateButton(gtk.HILDON_SIZE_AUTO,
                                    hildon.BUTTON_ARRANGEMENT_VERTICAL)

    # Set a title to the button
    date_button.set_title("Select an item")

    # Add button to main window 
    window.add(date_button)

    
    window.connect("destroy", app_quit)
    window.show_all()
    gtk.main()

if __name__ == "__main__":
    main()

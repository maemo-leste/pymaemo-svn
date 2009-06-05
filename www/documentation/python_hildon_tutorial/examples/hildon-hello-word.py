# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 1.2, "Hildon Hello World program"

import gtk
import hildon

# This is a callback function. The data arguments are ignored in this example.
def hello(widget, data):
    print "Hello World!"

def main():
    # Get an instance of HildonProgram. It is an object used to represent an
    # application running in the Hildon framework.
    program = hildon.hildon_program_get_instance()

    # create a new hildon window
    window = hildon.Window()

    # Registers a window as belonging to the program
    program.add_window(window)

    # When the window is given the "delete_event" signal (this is given by the
    # window manager, usually by the "close" option, or on the titlebar), we
    # ask it to call the delete_event () function as defined above. The data
    # passed to the callback function is None and is ignored in the callback
    # function.
    window.connect("delete_event", gtk.main_quit, None)

    button = hildon.Button(gtk.HILDON_SIZE_AUTO, hildon.BUTTON_ARRANGEMENT_VERTICAL, "Hello world!")

    # When the button is given the "clicked" signal, we ask it to call the
    # hello () function as defined above. The data passed to the callback
    # function is None and is ignored in the callback function.
    button.connect("clicked", hello, None)

    # This packs the button into the window (a GTK+ container).
    window.add(button)

    # The final step is to display this newly created widget and all widgets it
    # contains.
    window.show_all()

    # All GTK+ applications must have a gtk_main(). Control ends here and waits
    # for an event to occur (like a key press or mouse event).
    gtk.main()

if __name__ == "__main__":
    main()

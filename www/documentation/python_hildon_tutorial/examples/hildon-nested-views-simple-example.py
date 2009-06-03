import gtk
import hildon

def show_new_window(widget):
    # Create the main window
    win = hildon.StackableWindow()
    win.set_title("Subview")

    # Setting a label in the new window
    label = gtk.Label("This is a subview")

    vbox = gtk.VBox(False, 0)
    vbox.pack_start(label, True, True, 0)

    win.add(vbox)

    # FIXME: probably unnecessary. See MB#4633
    #win.connect("destroy", test, None)

    # This call show the window and also add the window to the stack
    win.show_all()

def main():
    program = hildon.hildon_program_get_instance()

    # Create the main window
    win = hildon.StackableWindow()
    win.set_title("Main window")

    button = gtk.Button("Go to subview")
    win.add(button)

    button.connect("clicked", show_new_window)

    # FIXME: probably unnecessary. See MB#4633
    #win.connect("destroy", test, None)

    win.connect("destroy", gtk.main_quit, None)

    # This call show the window and also add the window to the stack
    win.show_all()
    gtk.main()

if __name__ == "__main__":
    main()

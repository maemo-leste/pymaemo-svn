import hildon
import gtk

def normal_zoom_cb():
    # Code to set normal zoom...
    hildon.hildon_window_stack_get_default().pop_1()

def view_subview():
    view_window = hildon.StackableWindow()
    view_window.set_title("View")

    normal_zoom_button = hildon.GtkButton(gtk.HILDON_SIZE_FINGER_HEIGHT |
                                          gtk.HILDON_SIZE_AUTO_WIDTH)
    normal_zoom_button.set_label("Normal Zoom")
    normal_zoom_button.connect("clicked", normal_zoom_cb)

    highlight_selector = hildon.touch_selector_new_text ()
    highlight_selector.append_text("C")
    highlight_selector.append_text("JAVA")
    highlight_selector.append_text("Python")

    highlight_picker = hildon.PickerButton(hildon.SIZE_THUMB_HEIGHT |
                                           hildon.SIZE_HALFSCREEN_WIDTH,
                                           hildon.BUTTON_ARRANGEMENT_VERTICAL)
    highlight_picker.set_title("Syntax highlight:")
    
    highlight_picker.set_selector(highlight_selector)
    highlight_picker.set_active(0)

    contents = gtk.VBox(12, False)
    contents.pack_end(highlight_picker, False, False, 0)
    contents.pack_end(normal_zoom_button, False, False, 0)

    view_window.add(contents)
    view_window.show_all()

def help_contents_cb(widget, data):
    # Code to set show help contents...
    hildon.hildon_window_stack_get_default().pop_1()

def help_about_cb(widget, data):
    # Code to set show about information...
    hildon.hildon_window_stack_get_default().pop_1()

def help_subview():
    view_window = hildon.StackableWindow()
    view_window.set_title("Help")

    help_contents_button = hildon.GtkButton(gtk.HILDON_SIZE_FINGER_HEIGHT |
                                            gtk.HILDON_SIZE_AUTO_WIDTH)
    help_contents_button.set_label("Contents")
    help_contents_button.connect("clicked", help_contents_cb)


    help_about_button = hildon.GtkButton(gtk.HILDON_SIZE_FINGER_HEIGHT |
                                         gtk.HILDON_SIZE_AUTO_WIDTH)
    help_about_button.set_label("About")
    help_about_button.connect("clicked", help_about_cb) 

    contents = gtk.VBox(12, False)
    contents.pack_end(help_contents_button, False, False, 0)
    contents.pack_end(help_about_button, False, False, 0)
    
    view_window.add(contents)
    view_window.show_all()

def build_menu():
    button_size = gtk.HILDON_SIZE_FINGER_HEIGHT | gtk.HILDON_SIZE_AUTO_WIDTH
    menu = hildon.AppMenu()

    # Menus like New, Open, etc that would open new dialogs (no submenus)
    # are not assigned any action in this example
    labels = ["New", "Open", "Save As", "Preferences", "View", "Help"]

    for lbl in labels:
        button = hildon.GtkButton(button_size)
        button.set_label(lbl)
        menu.append(button)
        if lbl == "View":
            button.connect("clicked", view_subview)
        elif lbl == "Help":
            button.connect("clicked", help_subview)

    # FIXME: missing class GtkRadioButton
    my_filter = hildon.GtkRadioButton(button_size, None)
    my_filter.set_label("Indentation: Spaces")
    menu.add_filter(my_filter)
    my_filter.set_mode(False)

    my_filter = hildon.GtkRadioButton(button_size, None)
    my_filter.set_label("Indentation: Tabs")
    menu.add_filter(my_filter)
    my_filter.set_mode(False)

    return menu

def main():
    window = hildon.StackableWindow()
    window.set_title("Editor")

    menu = build_menu()
    window.set_main_menu(menu)

    contents = gtk.Label("This example shows how an app menu could be "
                         "divided.\nMenus that would open new dialogs "
                         "are not assigned any action.")
    window.add(contents)

    # ... other widgets in the application
    window.connect("destroy", gtk.main_quit, None)
    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()



import gtk
import hildon

def normal_zoom_cb(widget, data=None):
    hildon.WindowStack.get_default().pop_1()

def view_subview(widget, data=None):
    view_window = hildon.StackableWindow()
    view_window.set_title('View')

    normal_zoom_button = hildon.GtkButton(
                gtk.HILDON_SIZE_FINGER_HEIGHT | gtk.HILDON_SIZE_AUTO_WIDTH)
    normal_zoom_button.set_label('Normal Zoom')
    normal_zoom_button.connect('clicked', normal_zoom_cb)

    highlight_selector = hildon.TouchSelector()
    # Differs from C as we should pass a TreeModel explicitly.
    # This will be improved in a future release
    col = highlight_selector.append_text_column(gtk.ListStore(str), True)
    col.set_property("text-column", 0)
    highlight_selector.append_text('C')
    highlight_selector.append_text('Java')
    highlight_selector.append_text('Python')
    highlight_picker = hildon.PickerButton(
                gtk.HILDON_SIZE_THUMB_HEIGHT | gtk.HILDON_SIZE_HALFSCREEN_WIDTH,
                hildon.BUTTON_ARRANGEMENT_VERTICAL)
    highlight_picker.set_title('Syntax highlight:')
    highlight_picker.set_selector(highlight_selector)
    highlight_picker.set_active(0)

    contents = gtk.VBox(False, 12)
    contents.pack_end(highlight_picker, False, False)
    contents.pack_end(normal_zoom_button, False, False)

    view_window.add(contents)

    view_window.show_all()


def help_contents_cb(widget, data=None):
    hildon.WindowStack.get_default().pop_1()

def help_about_cb(widget, data=None):
    hildon.WindowStack.get_default().pop_1()

def help_subview(widget, data=None):
    view_window = hildon.StackableWindow()
    view_window.set_title('Help')

    help_contents_button = hildon.GtkButton(
                gtk.HILDON_SIZE_FINGER_HEIGHT | gtk.HILDON_SIZE_AUTO_WIDTH)
    help_contents_button.set_label('Contents')
    help_contents_button.connect('clicked', help_contents_cb)

    help_about_button = hildon.GtkButton(
                gtk.HILDON_SIZE_FINGER_HEIGHT | gtk.HILDON_SIZE_AUTO_WIDTH)
    help_about_button.set_label('About')
    help_about_button.connect('clicked', help_about_cb)

    contents = gtk.VBox(False, 12)
    contents.pack_end(help_contents_button, False, False)
    contents.pack_end(help_about_button, False, False)

    view_window.add(contents)

    view_window.show_all()

def build_menu():
    button_size = gtk.HILDON_SIZE_FINGER_HEIGHT | gtk.HILDON_SIZE_AUTO_WIDTH
    menu = hildon.AppMenu()

    # Menus like New, Open, etc that would open new dialogs (no submenus)
    # are not assigned any action in this example

    button = hildon.GtkButton(button_size)
    button.set_label('New')
    menu.append(button)

    button = hildon.GtkButton(button_size)
    button.set_label('Open')
    menu.append(button)

    button = hildon.GtkButton(button_size)
    button.set_label('Save As')
    menu.append(button)

    button = hildon.GtkButton(button_size)
    button.set_label('Preferences')
    menu.append(button)

    button = hildon.GtkButton(button_size)
    button.set_label('View')
    button.connect('clicked', view_subview)
    menu.append(button)

    filt = hildon.GtkRadioButton(button_size)
    filt.set_label('Indentation: Spaces')
    menu.add_filter(filt)
    filt.set_mode(False)

    button = hildon.GtkButton(button_size)
    button.set_label('Help')
    button.connect('clicked', help_subview)
    menu.append(button)

    filt = hildon.GtkRadioButton(button_size, filt) #, filt)
    filt.set_label('Indentation: Tabs')
    menu.add_filter(filt)
    filt.set_mode(False)

    return menu


def main():
    window = hildon.StackableWindow()
    window.set_title('Editor')

    menu = build_menu()
    window.set_main_menu(menu)

    contents = gtk.Label('''This examples shows how an app menu could be
                            divided.\nMenus that would open new dialogs
                            are not assigned any action.''')

    window.add(contents)

    window.connect('destroy', gtk.main_quit)

    window.show_all()

    gtk.main()

if __name__ == '__main__':
    main()

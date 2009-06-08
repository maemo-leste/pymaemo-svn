# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 6.4, "Hildon picker button with a selector entry"

import gtk
import hildon

def app_quit(widget, data=None):
    gtk.main_quit()

def main ():
    artists = [
        "AC/DC",
        "Aerosmith",
        "Alice in Chains",
        "Black Sabbath",
        "Carcass",
        "Danzig",
        "Deep Purple",
        "Dream Theater",
        "Eric Clapton",
    ]

    program = hildon.hildon_program_get_instance()
    gtk.set_application_name("hildon-touch-selector example program")

    window = hildon.StackableWindow()
    program.add_window(window)

    # Create a picker button
    picker_button = hildon.PickerButton(gtk.HILDON_SIZE_AUTO,
                                        hildon.BUTTON_ARRANGEMENT_VERTICAL)

    # Set a title to the button 
    picker_button.set_title("Pick a band!")

    # Create a touch selector entry */
    # FIXME: bug 4647
    selector = hildon.hildon_touch_selector_entry_new_text()
    
    # Populate the selector
    for artist in artists:
        selector.append_text(artist)

    # Attach the touch selector to the picker button
    picker_button.set_selector(selector)

    # Add button to main window
    window.add(picker_button)

    window.connect("destroy", app_quit)
    window.show_all()
    gtk.main()

if __name__ == "__main__":
    main()

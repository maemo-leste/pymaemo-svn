# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Migration Example, "Migrating choice widgets"

import gtk
import hildon

def main():
    window = hildon.Window()
    window.set_title("Preferences")
    window.connect("destroy", gtk.main_quit)

    picker = hildon.PickerButton(gtk.HILDON_SIZE_THUMB_HEIGHT |
                                 gtk.HILDON_SIZE_HALFSCREEN_WIDTH,
                                 hildon.BUTTON_ARRANGEMENT_VERTICAL)

    picker.set_title("Proxy preferences:")

    selector = hildon.touch_selector_new_text()
    picker.set_selector(selector)   
    selector.append_text("None")
    selector.append_text("Auto")
    selector.append_text("Manual")
    picker.set_active(0)

    contents = gtk.VBox(12, False)
    # ... other widgets placed here
    contents.pack_end(picker, False, False, 0)
    window.add(contents)

    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()

# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Migration Example, "Migrating a notebook"

import gtk
import hildon

def new_preferences_window (title):
    pref_window = hildon.StackableWindow()
    pref_window.set_title(title)
    content = gtk.Label("Set the %s Preferences" % title)
    content.show()
    pref_window.add(content)

    return pref_window


def button_clicked_cb (button, title):
    sw = new_preferences_window (title)
    sw.show_all()

def main():
    window = hildon.StackableWindow()
    window.set_title("Preferences")

    contents = gtk.VBox(True, 12)
 
    labels = ["General", "Colors", "Tools"]
    for lbl in labels:
        pref_button = hildon.GtkButton(gtk.HILDON_SIZE_AUTO_HEIGHT)
        pref_button.set_label(lbl)
        pref_button.connect("clicked", button_clicked_cb, lbl)
        contents.add(pref_button)

    window.add(contents)
    window.connect("destroy", gtk.main_quit, None)
    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()

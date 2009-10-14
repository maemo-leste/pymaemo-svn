#!/usr/bin/env python2.5

import gtk
import hildon

def new_preferences_window(title):
    pref_window = hildon.StackableWindow()
    pref_window.set_title(title)
    content = gtk.Label("Set the %s preferences" % title)
    content.show()
    pref_window.add(content)

    return pref_window

def button_clicked_cb(widget, title=None):
    sw = new_preferences_window(title)

    sw.show_all()

def main():
    window = hildon.StackableWindow()
    window.set_title('Preferences')

    general_pref_button = hildon.GtkButton(gtk.HILDON_SIZE_AUTO_HEIGHT)
    general_pref_button.set_label('General')
    general_pref_button.connect('clicked', button_clicked_cb, 'General')

    colors_pref_button = hildon.GtkButton(gtk.HILDON_SIZE_AUTO_HEIGHT)
    colors_pref_button.set_label('Colors')
    colors_pref_button.connect('clicked', button_clicked_cb, 'Colors')

    tools_pref_button = hildon.GtkButton(gtk.HILDON_SIZE_AUTO_HEIGHT)
    tools_pref_button.set_label('Tools')
    tools_pref_button.connect('clicked', button_clicked_cb, 'Tools')

    contents = gtk.VBox(12, True)

    contents.add(general_pref_button)
    contents.add(colors_pref_button)
    contents.add(tools_pref_button)

    window.add(contents)

    window.connect('destroy', gtk.main_quit)

    window.show_all()

    gtk.main()

if __name__ == '__main__':
    main()

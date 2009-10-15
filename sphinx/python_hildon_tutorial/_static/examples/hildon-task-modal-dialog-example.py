# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 2.6, "Application modal dialog example"

import gtk
import hildon

def main():
    win = hildon.StackableWindow()

    win.show()

    dialog = gtk.Dialog()

    dialog.set_transient_for(win)

    dialog.set_title("Hello!")

    dialog.show_all()

    dialog.run()

if __name__ == "__main__":
    main()

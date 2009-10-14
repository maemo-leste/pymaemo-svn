# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 8.1, "Adding a progress indicator to a dialog"

import gtk
import hildon

def main():
    dialog = gtk.Dialog()
    dialog.set_title("Performing a long task")
    dialog.show_all()
    hildon.hildon_gtk_window_set_progress_indicator(dialog, 1)
    dialog.run()

if __name__ == "__main__":
    main()


# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 1.1, "Simple Hildon program"

import gtk
import hildon

def main():
    gtk.set_application_name("Simplest example")

    window = hildon.Window()
    window.show()

    gtk.main()

if __name__ == "__main__":
    main()

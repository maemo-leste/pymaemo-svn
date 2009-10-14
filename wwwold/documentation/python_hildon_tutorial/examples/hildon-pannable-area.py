# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 5.1, "Example of a pannable area"

import gtk
import hildon

def create_table():
    # create a table of 10 by 10 squares. 
    table = gtk.Table (10, 10, False)

    # set the spacing to 10 on x and 10 on y 
    table.set_row_spacings(10)
    table.set_col_spacings(10)

    table.show()

    # this simply creates a grid of toggle buttons on the table
    # to demonstrate the scrolled window. */
    for i in range(10):
        for j in range(10):
            data_buffer = "button (%d,%d)\n" % (i, j)
            button = gtk.ToggleButton(data_buffer)
            table.attach(button, i, i+1, j, j+1)

    return table

def app_quit(widget, data=None):
    gtk.main_quit()

def main():
    window = hildon.StackableWindow()

    window.connect("destroy", app_quit)

    pannable_area = hildon.PannableArea()

    table = create_table()

    # pack the table into the scrolled window 
    pannable_area.add_with_viewport(table)

    # Add the box into the window
    window.add(pannable_area)

    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()


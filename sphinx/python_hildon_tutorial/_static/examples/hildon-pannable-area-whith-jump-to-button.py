# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 5.2, "Example of a pannable area and a "jump-to" button"

import gtk
import hildon

# Pointer to the last clicked button
last_clicked_button = None

# Callabck to set last clicked button
def clicked(button):
    global last_clicked_button
    last_clicked_button = button

def go_to_last_clicked(button, pannable_area):
    pannable_area.scroll_to_child(last_clicked_button)

def create_table():

    # create a table of 10 by 10 squares.
    table = gtk.Table (10, 10, False)

    # set the spacing to 10 on x and 10 on y
    table.set_row_spacings(10)
    table.set_col_spacings(10)

    table.show()

    # this simply creates a grid of toggle buttons on the table
    # to demonstrate the scrolled window. 
    for i in range(10):
        for j in range(10):
            data_buffer = "button (%d,%d)\n" % (i, j)
            button = gtk.ToggleButton(data_buffer)
            button.connect("clicked", clicked)
            table.attach(button, i, i+1, j, j+1)

    return table
  
def app_quit(widget, data=None):
    gtk.main_quit()

def main():

    window = hildon.StackableWindow()
    pannable_area = hildon.PannableArea()

    window.connect("destroy", app_quit)

    pannable_area.set_property("mov-mode", hildon.MOVEMENT_MODE_BOTH)

    button = gtk.Button("Go to last clicked button")
    button.connect("clicked", go_to_last_clicked, pannable_area)

    table = create_table()

    # pack the table into the scrolled window 
    pannable_area.add_with_viewport(table)

    # Create a box and pack the widgets into it
    vbox = gtk.VBox(False, 0)

    vbox.pack_start(button, False, False, 0)
    vbox.pack_start(pannable_area, True, True, 0)

    # Add the box into the window
    window.add(vbox)

    window.show_all()
    gtk.main()

if __name__ == "__main__":
    main()


# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 4.3, "Using a GtkToolbar in a Hildon application"

import gtk
import hildon

def app_quit(widget, data=None):
    gtk.main_quit()

def on_clicked (toolbutton, index):
    print "Index of clicked item : %d" % index

def main():
    program = hildon.hildon_program_get_instance()
    gtk.set_application_name("hildon-touch-selector example program")

    window = hildon.StackableWindow()
    program.add_window(window)

    # Create a toolbar
    toolbar = gtk.Toolbar()

    # Add items to the toolbar
    toolitem = gtk.ToolButton(gtk.image_new_from_stock(gtk.STOCK_HOME,
                              gtk.ICON_SIZE_LARGE_TOOLBAR),
                              "Home")
    toolitem.connect("clicked", on_clicked, 0)
    toolbar.insert(toolitem, 0)

    toolitem = gtk.ToolButton(gtk.image_new_from_stock(gtk.STOCK_GO_BACK,
                              gtk.ICON_SIZE_LARGE_TOOLBAR),
                              "Back")
    toolitem.connect("clicked", on_clicked, 1)    
    toolbar.insert(toolitem, 1)


    toolitem = gtk.ToolButton(gtk.image_new_from_stock(gtk.STOCK_GO_FORWARD,
                              gtk.ICON_SIZE_LARGE_TOOLBAR),
                              "Forward")
    toolitem.connect("clicked", on_clicked, 2)    
    toolbar.insert(toolitem, 2)

    # Add toolbar to the window
    window.add_toolbar(toolbar)

    window.connect("destroy", app_quit)
    window.show_all()
    gtk.main()

if __name__ == "__main__":
    main()


# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 4.2, "Using an Edit Toolbar"

import gobject
import gtk
import hildon

store = None

def get_model():
    global store

    if store is not None:
        return store

    store = gtk.ListStore(gobject.TYPE_STRING)
    for i in xrange(50):
        str = "\nRow %d\n" % i
        store.insert(i, [str])

    return store

def create_treeview(tvmode):
    tv = hildon.GtkTreeView(tvmode)
    renderer = gtk.CellRendererText()
    col = gtk.TreeViewColumn("Title", renderer, text=0)

    tv.append_column(col)

    # Set multiple selection mode
    selection = tv.get_selection()
    selection.set_mode(gtk.SELECTION_MULTIPLE)

    model = get_model()

    tv.set_model(model)

    return tv

def delete_button_clicked(button, treeview):
    selection = treeview.get_selection()

    (model, selected_rows) = selection.get_selected_rows()

    row_references = []
    for path in selected_rows:
        ref = gtk.TreeRowReference(model, path)
        row_references.append(ref)

    for ref in row_references:
        path = ref.get_path()
        iter = model.get_iter(path)
        model.remove(iter)

def edit_window(button):
    window = hildon.StackableWindow()
    window.set_border_width(6)

    # Create a new edit toolbar
    toolbar = hildon.EditToolbar("Choose items to delete", "Delete")

    area = hildon.PannableArea()
    tree_view = create_treeview(gtk.HILDON_UI_MODE_EDIT)

    # Add toolbar to the window
    window.set_edit_toolbar(toolbar)

    area.add(tree_view)
    window.add(area)

    toolbar.connect("button-clicked", delete_button_clicked, tree_view)

    toolbar.connect_object("arrow-clicked", gtk.Window.destroy, window)

    window.show_all()

    # Set window to fullscreen
    window.fullscreen()

def main():
    window = hildon.StackableWindow()
    window.connect("destroy", gtk.main_quit)

    vbox = gtk.VBox(False, 10)
    area = hildon.PannableArea()

    tree_view = create_treeview(gtk.HILDON_UI_MODE_NORMAL)

    button = hildon.GtkButton(gtk.HILDON_SIZE_AUTO_WIDTH | gtk.HILDON_SIZE_FINGER_HEIGHT)
    button.set_label("Delete some items")

    area.add(tree_view)
    vbox.pack_start(area, True, True, 0)
    vbox.pack_start(button, False, False, 0)

    window.add(vbox)

    button.connect("clicked", edit_window)

    window.show_all()

    gtk.main()

if __name__ == "__main__":
    main()

#!/usr/bin/python2.5

import gtk
import gobject
import abook
import osso
import evolution.ebook as evo
import hildon

class TreeViewDragExample(hildon.Program):
    """
    Simple test for abook.TreeView.enable_drag_source
    """
    def __init__(self):
        hildon.Program.__init__(self)

        self.context = osso.Context("filtermodelexample", "0.0.1", False)
        abook.init("filtermodelexample", self.context)

        self.window = hildon.Window()
        self.window.connect("destroy", gtk.main_quit)
        self.add_window(self.window)

        self.book = evo.open_addressbook("default")
        query = evo.EBookQuery.field_exists(evo.CONTACT_FULL_NAME)

        self.bookview = self.book.get_book_view(query)
        self.bookview.start()

        self.model = abook.ContactModel(self.bookview)
        self.view = abook.ContactView(self.model)

        #self.view.drag_source_set(gtk.gdk.BUTTON1_MASK,
        #                          [("text/plain", 0, 42)], gtk.gdk.ACTION_COPY)

        self.view.enable_drag_source()
        tv = self.view.get_tree_view()
        tv.connect("drag-begin", self.drag_begin)


        self.label = gtk.Label("Drop here")
        self.label.connect("drag-data-received", self.drag_data_received)
        self.label.drag_dest_set(gtk.DEST_DEFAULT_ALL,
                                [(abook.CONTACT_DND_TYPE, gtk.TARGET_SAME_APP, 0)],
                                 gtk.gdk.ACTION_COPY)

        vbox = gtk.VBox()
        vbox.pack_start(self.label)
        vbox.pack_start(self.view)

        self.window.add(vbox)
        self.window.show_all()

    def run(self):
        gtk.main()

    def drag_begin(self, widget, context ):
        print "drag begin"
        print "Currently selected user uid: %s" % self.view.get_selection()[0].get_uid()

    def drag_data_received(self, widget, context, x, y, sel, info, time):
        print "data received callback"
        print sel.data
        user = self.book.get_contact(sel.data)
        print user
        self.label.set_text("User %s\nUid:%s" % (user.get_name(), user.get_uid()))


if __name__ == "__main__":
    prog = TreeViewDragExample()
    prog.run()

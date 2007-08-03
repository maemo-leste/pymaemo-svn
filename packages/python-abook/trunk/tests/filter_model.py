#!/usr/bin/python2.5

import gtk
import gobject
import abook
import osso
import evolution.ebook as evo
import hildon

class FilterModelExample(hildon.Program):
    """
    Example class for abook.FilterModel. Displays the contacts based on
    a text for query and group.
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
        self.filtermodel = abook.FilterModel(self.model)
        self.view = abook.ContactView(self.model, self.filtermodel)

        self.entry = gtk.Entry()
        button = gtk.Button("Set query")
        button.connect("clicked", self.update_query)

        self.groups = {}
        combo = self.create_combo()
        combo.connect("changed", self.update_group)

        hbox = gtk.HBox()
        hbox.pack_start(self.entry)
        hbox.pack_start(button, expand=False)

        vbox = gtk.VBox()
        vbox.pack_start(hbox, expand=False, padding=5)
        vbox.pack_start(combo, expand=False, padding=5)
        vbox.pack_start(self.view)

        self.window.add(vbox)
        self.window.show_all()

    def run(self):
        gtk.main()

    def update_query(self, button):
        query = self.entry.get_text()

        self.filtermodel.set_text(query)

    def update_group(self, combo):
        key = combo.get_active_text()

        print "Setting group to %s" % key
        if key:
            group = self.groups[key]
            self.filtermodel.set_group(group)

    def create_combo(self):
        combo = gtk.combo_box_new_text()
        manager = abook.manual_group_manager_get()

        #all
        self.groups["all"] = abook.all_group_get()

        #blocked
        self.groups["blocked"] = abook.blocked_group_get()

        #manual
        groups =  manager.get_groups()
        for i in groups:
            self.groups[i.get_display_name()] = i

        #online
        self.groups["online"] = abook.online_group_get()

        #recent
        self.groups["recent"] = abook.recent_group_get()

        #service??

        for k in self.groups:
            combo.append_text(k)

        return combo

if __name__ == "__main__":
    prog = FilterModelExample()
    prog.run()

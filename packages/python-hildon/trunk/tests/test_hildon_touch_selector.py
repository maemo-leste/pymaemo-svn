import unittest

import hildon
import gtk
import gobject

test_list = ["one", "two", "three"]

class TestHildonTouchSelector(unittest.TestCase):
    def test_append_column(self):
        ts = hildon.TouchSelector()
        store = gtk.ListStore(gobject.TYPE_STRING)
        for i in test_list:
            store.append([i])
        cell = gtk.CellRendererPixbuf()
        col = ts.append_column(store, cell, stock_id=0)
        self.assertTrue(isinstance(col, hildon.TouchSelectorColumn))
        self.assertEqual([i[0] for i in ts.get_model(0)], test_list)

    def test_get_selected_rows(self):
        ts = hildon.TouchSelector()
        store = gtk.ListStore(gobject.TYPE_STRING)
        for i in test_list:
            store.append([i])
        ts.append_column(store, gtk.CellRendererPixbuf())
        # First item is selected by default
        self.assertEqual(ts.get_selected_rows(0), [(0,)])
        # Select second item and see if get_selected_rows() reflects the change
        first = ts.get_model(0).get_iter_first()
        second = ts.get_model(0).iter_next(first)
        ts.select_iter(0, second, False)
        self.assertEqual(ts.get_selected_rows(0), [(1,)])

if __name__ == "__main__":
    unittest.main()

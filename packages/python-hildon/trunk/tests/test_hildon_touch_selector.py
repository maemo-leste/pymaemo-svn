#!/usr/bin/env python2.5

import unittest
from sys import getrefcount

import hildon
import gtk
import gobject

class TestHildonTouchSelector(unittest.TestCase):
    def test_append_column(self):
        ts = hildon.TouchSelector()
	
	store = gtk.ListStore(gobject.TYPE_STRING)
	i = store.append(["GTK_OK"])
	store.set(i, 0, "GTK_OK")
	
	cell = gtk.CellRendererPixbuf()
	col = ts.append_column(store, cell, stock_id=0)
	self.assertTrue(type(col) is hildon.TouchSelectorColumn)

	

if __name__ == "__main__":
    unittest.main()

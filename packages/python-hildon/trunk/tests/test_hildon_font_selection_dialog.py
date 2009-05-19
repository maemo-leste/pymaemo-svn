#!/usr/bin/env python2.5
import unittest

import gtk
import hildon

class TestHildonFontSelectionDialog(unittest.TestCase):
    def test_constructor(self):
        d = hildon.FontSelectionDialog(gtk.Window(), "Title")
        self.assertTrue(type(d) is hildon.FontSelectionDialog)
        d = hildon.FontSelectionDialog(gtk.Window())
        self.assertTrue(type(d) is hildon.FontSelectionDialog)
        d = hildon.FontSelectionDialog(gtk.Window(), None)
        self.assertTrue(type(d) is hildon.FontSelectionDialog)

if __name__ == "__main__":
    unittest.main()

#!/usr/bin/env python2.5
import unittest

import hildon
import gtk

class TestHildonWizardDialog(unittest.TestCase):
    def test_constructor_with_parent(self):
        w = gtk.Window()
        n = gtk.Notebook()
        x = hildon.WizardDialog(w, "xyz", n)
        self.assertTrue(x)

    def test_constructor_no_parent(self):
        n = gtk.Notebook()
        x = hildon.WizardDialog(None, "xyz", n)
        self.assertTrue(x)

if __name__ == "__main__":
    unittest.main()

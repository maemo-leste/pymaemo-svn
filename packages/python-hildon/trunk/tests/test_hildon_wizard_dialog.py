#!/usr/bin/env python2.5
import unittest

import gtk
import hildon

class TestHildonWizardDialog(unittest.TestCase):
    def test_constructor(self):
        d = hildon.WizardDialog(gtk.Window(), "Wizard", gtk.Notebook())
        self.assertTrue(type(d) is hildon.WizardDialog)
        d = hildon.WizardDialog(None, "Wizard", gtk.Notebook())
        self.assertTrue(type(d) is hildon.WizardDialog)

    def test_set_page_func(self):
        d = hildon.WizardDialog(None, "Wizard", gtk.Notebook())
        d.set_forward_page_func(lambda n,c,u: None)

    def test_set_page_destroy_not_implemented(self):
        d = hildon.WizardDialog(None, "Wizard", gtk.Notebook())
        self.assertRaises(NotImplementedError, d.set_forward_page_func, lambda n,c,u: None, None, lambda: None)

if __name__ == "__main__":
    unittest.main()

import unittest

import gtk
import hildon

class TestHildonFontSelectionDialog(unittest.TestCase):
    def test_constructor(self):
        d = hildon.FontSelectionDialog(gtk.Window(), "Title")
        self.assertTrue(isinstance(d, hildon.FontSelectionDialog))
        d = hildon.FontSelectionDialog(gtk.Window())
        self.assertTrue(isinstance(d, hildon.FontSelectionDialog))
        d = hildon.FontSelectionDialog(gtk.Window(), None)
        self.assertTrue(isinstance(d, hildon.FontSelectionDialog))

if __name__ == "__main__":
    unittest.main()

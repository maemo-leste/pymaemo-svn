import unittest

import gtk
import hildon

class TestHildonButton(unittest.TestCase):
    def test_constructor(self):
        self.assertRaises(TypeError, hildon.Button)
        b = hildon.Button(gtk.HILDON_SIZE_AUTO, hildon.BUTTON_ARRANGEMENT_VERTICAL)
        self.assertTrue(type(b) is hildon.Button)
        b = hildon.Button(gtk.HILDON_SIZE_AUTO, hildon.BUTTON_ARRANGEMENT_VERTICAL, "title")
        self.assertTrue(type(b) is hildon.Button)
        b = hildon.Button(gtk.HILDON_SIZE_AUTO, hildon.BUTTON_ARRANGEMENT_VERTICAL, "title", "value")
        self.assertTrue(type(b) is hildon.Button)

if __name__ == "__main__":
    unittest.main()

import unittest

import gobject
import gtk
import hildon

class TestHildonFindToolbar(unittest.TestCase):
    def test_constructor(self):
        t = hildon.FindToolbar("Label")
        self.assertTrue(isinstance(t, hildon.FindToolbar))

    def test_constructor_with_model(self):
        s = gtk.ListStore(gobject.TYPE_STRING)
        s.append(["Foo"])
        t = hildon.FindToolbar("Label", s, 0)
        self.assertTrue(isinstance(t, hildon.FindToolbar))
        self.assertRaises(ValueError, hildon.FindToolbar, "Label", s)
        self.assertRaises(ValueError, hildon.FindToolbar, "Label", s, -2)
        self.assertRaises(ValueError, hildon.FindToolbar, "Label", column=0)

if __name__ == "__main__":
    unittest.main()

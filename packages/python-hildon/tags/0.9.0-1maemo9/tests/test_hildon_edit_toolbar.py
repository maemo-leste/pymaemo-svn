import unittest

import gtk
import hildon

class TestHildonEditToolbar(unittest.TestCase):
    def test_constructor(self):
        t = hildon.EditToolbar()
        self.assertTrue(isinstance(t, hildon.EditToolbar))
        t = hildon.EditToolbar("Label", "Button")
        self.assertTrue(isinstance(t, hildon.EditToolbar))
        self.assertRaises(ValueError, hildon.EditToolbar, "Label")
        self.assertRaises(ValueError, hildon.EditToolbar, button="Button")

if __name__ == "__main__":
    unittest.main()

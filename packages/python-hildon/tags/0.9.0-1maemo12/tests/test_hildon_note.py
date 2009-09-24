import unittest

import hildon
import gtk

class TestHildonNote(unittest.TestCase):
    def test_constructor(self):
        w = hildon.Window()
        note = hildon.Note("confirmation", w, "xyz")
        self.assertTrue(isinstance(note, hildon.Note))
        note = hildon.Note("information", w, "xyz")
        self.assertTrue(isinstance(note, hildon.Note))
        note = hildon.Note("information", w, "xyz", icon_name="abc")
        self.assertTrue(isinstance(note, hildon.Note))
        note = hildon.Note("cancel", w, "xyz", progressbar=gtk.ProgressBar())
        self.assertTrue(isinstance(note, hildon.Note))
        self.assertRaises(TypeError, hildon.Note, "cancel", w, "xyz")

if __name__ == "__main__":
    unittest.main()

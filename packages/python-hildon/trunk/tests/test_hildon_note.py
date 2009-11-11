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

        note = hildon.Note(hildon.NOTE_TYPE_PROGRESSBAR, w, "xyz", progressbar=gtk.ProgressBar())
        self.assertTrue(isinstance(note, hildon.Note))
        note = hildon.Note(hildon.NOTE_TYPE_CONFIRMATION, w, "xyz")
        self.assertTrue(isinstance(note, hildon.Note))
        note = hildon.Note(hildon.NOTE_TYPE_INFORMATION, w, "xyz")
        self.assertTrue(isinstance(note, hildon.Note))

        self.assertRaises(ValueError, hildon.Note, "invalid_type", w, "xyz")
        self.assertRaises(ValueError, hildon.Note, ("invalid_type"), w, "xyz")
        self.assertRaises(TypeError, hildon.Note, "cancel")

if __name__ == "__main__":
    unittest.main()

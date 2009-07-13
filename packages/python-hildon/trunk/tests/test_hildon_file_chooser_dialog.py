import unittest

import gtk
import hildon

class TestHildonFileChooserDialog(unittest.TestCase):
    def test_constructor(self):
        m = hildon.FileSystemModel(root_dir="/")
        d = hildon.FileChooserDialog(gtk.Window(), gtk.FILE_CHOOSER_ACTION_OPEN, m)
        self.assertTrue(isinstance(d, hildon.FileChooserDialog))

if __name__ == "__main__":
    unittest.main()

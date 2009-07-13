import unittest

import gtk
import hildon

class TestHildonFileSystemModel(unittest.TestCase):
    def test_constructor(self):
        m = hildon.FileSystemModel()
        self.assertTrue(isinstance(m, hildon.FileSystemModel))
        m = hildon.FileSystemModel(gtk.Window())
        self.assertTrue(isinstance(m, hildon.FileSystemModel))
        m = hildon.FileSystemModel(gtk.Window(), "/some/dir")
        self.assertTrue(isinstance(m, hildon.FileSystemModel))
        m = hildon.FileSystemModel(None)
        self.assertTrue(isinstance(m, hildon.FileSystemModel))
        m = hildon.FileSystemModel(None, None)
        self.assertTrue(isinstance(m, hildon.FileSystemModel))

if __name__ == "__main__":
    unittest.main()

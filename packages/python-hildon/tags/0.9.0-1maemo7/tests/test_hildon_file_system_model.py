#!/usr/bin/env python2.5
import unittest

import gtk
import hildon

class TestHildonFileSystemModel(unittest.TestCase):
    def test_constructor(self):
        m = hildon.FileSystemModel()
        self.assertTrue(type(m) is hildon.FileSystemModel)
        m = hildon.FileSystemModel(gtk.Window())
        self.assertTrue(type(m) is hildon.FileSystemModel)
        m = hildon.FileSystemModel(gtk.Window(), "/some/dir")
        self.assertTrue(type(m) is hildon.FileSystemModel)
        m = hildon.FileSystemModel(None)
        self.assertTrue(type(m) is hildon.FileSystemModel)
        m = hildon.FileSystemModel(None, None)
        self.assertTrue(type(m) is hildon.FileSystemModel)

if __name__ == "__main__":
    unittest.main()

#!/usr/bin/env python2.5
import unittest

import gtk
import hildon

class TestHildonCaption(unittest.TestCase):
    def test_constructor(self):
        b = gtk.Button("Button")
        c = hildon.Caption(None, "Caption", b, None, hildon.CAPTION_OPTIONAL)
        self.assertTrue(type(c) is hildon.Caption)

if __name__ == "__main__":
    unittest.main()

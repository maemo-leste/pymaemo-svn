#!/usr/bin/env python2.5
import unittest

import hildon
from gtk.gdk import Color

class TestHildonDateButton(unittest.TestCase):
    def setUp(self):
        self.obj = hildon.ColorButton()
        self.obj.set_color(Color(1,2,3))

    def test_get_color(self):
        color = self.obj.get_color().to_string()
        self.assertEqual(color, Color(1,2,3).to_string())

if __name__ == "__main__":
    unittest.main()

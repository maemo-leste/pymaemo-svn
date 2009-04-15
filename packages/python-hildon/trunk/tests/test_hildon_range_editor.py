#!/usr/bin/env python2.5
import unittest

import hildon

class TestHildonRangeEditor(unittest.TestCase):
    def setUp(self):
        self.obj = hildon.RangeEditor()
        self.obj.set_range(1, 100)

    def test_get_range(self):
        range = self.obj.get_range()
        self.assertEqual(range, (1, 100))

if __name__ == "__main__":
    unittest.main()

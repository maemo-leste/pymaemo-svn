#!/usr/bin/env python2.5

import unittest

import gtk
import hildon

class TestSetDefault(unittest.TestCase):
    def setUp(self):
        self.window = hildon.StackableWindow()

    def tearDown(self):
        del self.window

    def testGetDefault(self):
        # TODO improve this check
        default_stack = hildon.WindowStack.get_default()
        self.assert_(isinstance(default_stack, hildon.WindowStack))

if __name__ == '__main__':
    unittest.main()


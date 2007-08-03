#!/usr/bin/python2.5

import gtk
import abook
import osso

import unittest

context = osso.Context("foo_bar", "0.0", False)
abook.init_with_name("foo_bar", context)

class TestContactModel(unittest.TestCase):

    def setUp(self):
        pass

    def test_create(self):
        tree = abook.ContactModel();

        self.assertNotEqual(None, tree)

if __name__ == "__main__":
    unittest.main()

import unittest

import gobject
import gtk
import hildon

class TestHildonGtkButton(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkButton(gtk.HILDON_SIZE_AUTO)
        self.assertTrue(type(t) is hildon.GtkButton)
        self.assertRaises(TypeError, hildon.GtkButton)
       
class TestHildonGtkButtonConstructor(unittest.TestCase):

    def setUp(self):
        self.size_policy = gtk.HILDON_SIZE_THUMB_HEIGHT
    
    def testBasic(self):
        a = hildon.GtkRadioButton(self.size_policy)
        self.assertTrue(type(a) is hildon.GtkRadioButton)
        self.assertRaises(TypeError, hildon.GtkRadioButton)

    def testGroupConstructor(self):
        first = hildon.GtkRadioButton(self.size_policy)
        second = hildon.GtkRadioButton(self.size_policy, first)
        

class TestHildonGtkTreeView(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkTreeView(gtk.HILDON_UI_MODE_NORMAL)
        self.assertTrue(type(t) is hildon.GtkTreeView)
        s = gtk.ListStore(gobject.TYPE_STRING)
        s.append(["Foo"])
        t = hildon.GtkTreeView(gtk.HILDON_UI_MODE_NORMAL, s)
        self.assertTrue(type(t) is hildon.GtkTreeView)
        self.assertRaises(TypeError, hildon.GtkTreeView)
        self.assertRaises(TypeError, hildon.GtkTreeView, gtk.HILDON_UI_MODE_NORMAL, None)

if __name__ == "__main__":
    unittest.main()

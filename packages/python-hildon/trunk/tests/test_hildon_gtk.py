import unittest

import gobject
import gtk
import hildon

class TestHildonGtkButton(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkButton(gtk.HILDON_SIZE_AUTO)
        self.assertTrue(isinstance(t, hildon.GtkButton))
        self.assertRaises(TypeError, hildon.GtkButton)

class TestHildonGtkMenu(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkMenu()
        self.assertTrue(type(t) is hildon.GtkMenu)

class TestHildonGtkHScale(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkHScale()
        self.assertTrue(type(t) is hildon.GtkHScale)

class TestHildonGtkVScale(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkVScale()
        self.assertTrue(type(t) is hildon.GtkVScale)

class TestHildonGtkToggleButton(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkToggleButton(gtk.HILDON_SIZE_AUTO)
        self.assertTrue(type(t) is hildon.GtkToggleButton)
        self.assertRaises(TypeError, hildon.GtkToggleButton)

class TestHildonGtkButtonConstructor(unittest.TestCase):
    def setUp(self):
        self.size_policy = gtk.HILDON_SIZE_THUMB_HEIGHT
    
    def testBasic(self):
        a = hildon.GtkRadioButton(self.size_policy)
        self.assertTrue(isinstance(a, hildon.GtkRadioButton))
        self.assertRaises(TypeError, hildon.GtkRadioButton)

    def testGroupConstructor(self):
        first = hildon.GtkRadioButton(self.size_policy)
        second = hildon.GtkRadioButton(self.size_policy, first)
        

class TestHildonGtkTreeView(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkTreeView(gtk.HILDON_UI_MODE_NORMAL)
        self.assertTrue(isinstance(t, hildon.GtkTreeView))
        s = gtk.ListStore(gobject.TYPE_STRING)
        s.append(["Foo"])
        t = hildon.GtkTreeView(gtk.HILDON_UI_MODE_NORMAL, s)
        self.assertTrue(isinstance(t, hildon.GtkTreeView))
        self.assertRaises(TypeError, hildon.GtkTreeView)
        self.assertRaises(TypeError, hildon.GtkTreeView, gtk.HILDON_UI_MODE_NORMAL, None)

class TestHildonGtkIconView(unittest.TestCase):
    def test_constructor(self):
        t = hildon.GtkIconView(gtk.HILDON_UI_MODE_NORMAL)
        self.assertTrue(type(t) is hildon.GtkIconView)
        s = gtk.ListStore(gobject.TYPE_STRING)
        s.append(["Foo"])
        t = hildon.GtkIconView(gtk.HILDON_UI_MODE_NORMAL, s)
        self.assertTrue(type(t) is hildon.GtkIconView)
        self.assertRaises(TypeError, hildon.GtkIconView)
        self.assertRaises(TypeError, hildon.GtkIconView, gtk.HILDON_UI_MODE_NORMAL, None)

if __name__ == "__main__":
    unittest.main()

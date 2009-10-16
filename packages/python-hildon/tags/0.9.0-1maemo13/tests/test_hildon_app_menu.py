import unittest
from sys import getrefcount

import hildon
import gtk

class TestHildonAppMenu(unittest.TestCase):
    def test_app_menu_ownership(self):
        w = hildon.Window()
        m = hildon.AppMenu()
        m_str = str(m)
        w.set_app_menu(m)
        self.assertEqual(w.get_app_menu(), m)
        # set_app_menu takes ownership of the passed menu
        # so this should not segfault
        del m
        self.assertEqual(str(w.get_app_menu()), m_str)

    def test_gtk_menu_ownership(self):
        w = hildon.Window()
        m = gtk.Menu()
        m_str = str(m)
        w.set_main_menu(m)
        self.assertEqual(w.get_main_menu(), m)
        del m
        self.assertEqual(str(w.get_main_menu()), m_str)

    def test_set_main_menu_implicitly_deleted(self):
        w = hildon.Window()
        m = gtk.Menu()
        w.set_main_menu(m)
        w.set_main_menu()
        # should not segfault
        m.append(gtk.MenuItem('test'))

    def test_set_main_menu(self):
        w = hildon.Window()
        m = gtk.Menu()
        self.assertEqual(getrefcount(m), 2)
        w.set_main_menu(m)
        self.assertEqual(getrefcount(m), 2)
        w.set_main_menu(m)
        self.assertEqual(getrefcount(m), 2)
        m2 = gtk.Menu()
        self.assertEqual(getrefcount(m2), 2)
        w.set_main_menu(m2)
        self.assertEqual(getrefcount(m), 2)
        self.assertEqual(getrefcount(m2), 2)

    def test_set_app_menu(self):
        w = hildon.Window()
        m = hildon.AppMenu()
        self.assertEqual(getrefcount(m), 2)
        w.set_app_menu(m)
        self.assertEqual(getrefcount(m), 3)
        w.set_app_menu(m)
        self.assertEqual(getrefcount(m), 3)
        m2 = hildon.AppMenu()
        self.assertEqual(getrefcount(m2), 2)
        w.set_app_menu(m2)
        self.assertEqual(getrefcount(m), 2)
        self.assertEqual(getrefcount(m2), 3)

    def test_set_app_menu_implicitly_deleted(self):
        w = hildon.Window()
        m = hildon.AppMenu()
        w.set_app_menu(m)
        w.set_app_menu()
        # should not segfault
        m.append(gtk.Button('test'))

    def test_get_items(self):
        m = hildon.AppMenu()
        self.assertEqual(set(m.get_items()), set([]))
        b1 = gtk.Button()
        b2 = gtk.Button()
        m.append(b1)
        m.append(b2)
        self.assertEqual(set(m.get_items()), set([b1, b2]))

    def test_get_filters(self):
        m = hildon.AppMenu()
        self.assertEqual(set(m.get_filters()), set([]))
        f1 = gtk.RadioButton()
        f2 = gtk.RadioButton()
        m.add_filter(f1)
        m.add_filter(f2)
        self.assertEqual(set(m.get_filters()), set([f1, f2]))

if __name__ == "__main__":
    unittest.main()

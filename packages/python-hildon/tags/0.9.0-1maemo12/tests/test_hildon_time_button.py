import unittest

import gtk
import hildon

class TestHildonTimeButton(unittest.TestCase):
    def setUp(self):
        self.obj = hildon.TimeButton(gtk.HILDON_SIZE_FINGER_HEIGHT,
                                     hildon.BUTTON_ARRANGEMENT_HORIZONTAL)
        self.obj.set_time(11, 22)

    def test_get_time(self):
        time = self.obj.get_time()
        self.assertEqual(time, (11, 22))

if __name__ == "__main__":
    unittest.main()

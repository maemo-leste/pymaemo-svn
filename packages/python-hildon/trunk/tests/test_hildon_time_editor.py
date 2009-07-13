import unittest

import hildon

class TestHildonTimeEditor(unittest.TestCase):
    def setUp(self):
        self.obj = hildon.TimeEditor()
        self.obj.set_time(11, 22, 33)
        self.obj2 = hildon.TimeEditor()
        self.obj2.set_duration_mode(True)
        self.obj2.set_duration_range(10, 59)

    def test_get_duration_range(self):
        duration = self.obj2.get_duration_range()
        self.assertEqual(duration, (10, 59))

    def test_get_time(self):
        time = self.obj.get_time()
        self.assertEqual(time, (11, 22, 33))

if __name__ == "__main__":
    unittest.main()

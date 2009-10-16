import unittest

import hildon

class TestHildonTimePicker(unittest.TestCase):
    def setUp(self):
        self.window = hildon.Window()
        self.obj = hildon.TimePicker(self.window)
        self.obj.set_time(11, 22)

    def test_get_time(self):
        time = self.obj.get_time()
        self.assertEqual(time, (11, 22))

if __name__ == "__main__":
    unittest.main()

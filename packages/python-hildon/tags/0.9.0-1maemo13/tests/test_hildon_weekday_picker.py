import unittest

import hildon

class TestHildonWeekdayPicker(unittest.TestCase):
    def setUp(self):
        self.obj = hildon.WeekdayPicker()

    def test_set_day(self):
        self.obj.set_day("monday")
        self.assertEqual(self.obj.isset_day("monday"), True)
        self.assertEqual(self.obj.isset_day("sunday"), False)

    def test_unset_day(self):
        self.obj.set_all()
        self.obj.unset_day("sunday")
        self.assertEqual(self.obj.isset_day("sunday"), False)
        self.assertEqual(self.obj.isset_day("monday"), True)

    def test_toggle_day(self):
        self.obj.unset_all()
        self.obj.toggle_day("sunday")
        self.assertEqual(self.obj.isset_day("sunday"), True)
        self.assertEqual(self.obj.isset_day("monday"), False)

if __name__ == "__main__":
    unittest.main()

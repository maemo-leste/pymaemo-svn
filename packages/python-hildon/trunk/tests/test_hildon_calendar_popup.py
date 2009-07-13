import unittest

import hildon

class TestHildonCalendarPopup(unittest.TestCase):
    def setUp(self):
        self.window = hildon.Window()
        self.obj = hildon.CalendarPopup(self.window, 2009, 4, 13)

    def test_get_date(self):
        date = self.obj.get_date()
        self.assertEqual(date, (2009, 4, 13))

if __name__ == "__main__":
    unittest.main()

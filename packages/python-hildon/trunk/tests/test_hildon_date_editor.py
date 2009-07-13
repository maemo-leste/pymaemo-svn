import unittest

import hildon

class TestHildonDateEditor(unittest.TestCase):
    def setUp(self):
        self.obj = hildon.DateEditor()
        self.obj.set_date(2009, 4, 12)

    def test_get_date(self):
        date = self.obj.get_date()
        self.assertEqual(date, (2009, 4, 12))

if __name__ == "__main__":
    unittest.main()

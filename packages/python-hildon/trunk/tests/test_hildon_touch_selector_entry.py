import unittest

import gtk
import hildon

class TestConstructor(unittest.TestCase):
    def testBasic(self):
        entry = hildon.TouchSelectorEntry()
        self.assert_(isinstance(entry, hildon.TouchSelectorEntry))
        self.assertEqual(entry.get_text_column(), -1)

    def testWithText(self):
        entry = hildon.TouchSelectorEntry(text=True)
        self.assert_(isinstance(entry, hildon.TouchSelectorEntry))
        self.assertEqual(entry.get_text_column(), 0)

if __name__ == '__main__':
    unittest.main()

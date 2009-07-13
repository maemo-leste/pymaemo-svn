import unittest

import hildon
import gtk

class TestHildonProgram(unittest.TestCase):
    def test_get_instance(self):
        hp = hildon.Program.get_instance()
        self.assertTrue(isinstance(hp, hildon.Program))

if __name__ == "__main__":
    unittest.main()

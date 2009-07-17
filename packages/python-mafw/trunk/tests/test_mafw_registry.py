import unittest

import mafw

class TestMafwRegistry(unittest.TestCase):
    def test_get_instance(self):
        reg = mafw.Registry.get_instance()
        self.assertTrue(isinstance(reg, mafw.Registry))

if __name__ == "__main__":
    unittest.main()

import unittest

import mafw

class TestMafwRegistry(unittest.TestCase):
    def test_get_instance(self):
        reg = mafw.Registry.get_instance()

	r1 = mafw.Source()
	r2 = mafw.Source()
	
	reg.add_extension(r1)
	reg.add_extension(r2)
	
        self.AssertTrue(registry.get_renderers(), [r1, r2])

if __name__ == "__main__":
    unittest.main()

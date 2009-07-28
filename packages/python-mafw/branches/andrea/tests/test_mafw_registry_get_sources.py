import unittest
import gobject
import mafw

class MySourcePlugin(mafw.Source):
    __gtype_name__ = 'MySourcePlugin'

class TestMafwRegistry(unittest.TestCase):
    def test_get_sources(self):
        reg = mafw.Registry.get_instance()
        		
	x1 = gobject.new(MySourcePlugin, uuid = 'MySourcePlugin1')
	x2 = gobject.new(MySourcePlugin, uuid = 'MySourcePlugin2')
	
	reg.add_extension(x1)
	reg.add_extension(x2)
	
        self.assertTrue(reg.get_sources(), [x1, x2])

if __name__ == "__main__":
    unittest.main()


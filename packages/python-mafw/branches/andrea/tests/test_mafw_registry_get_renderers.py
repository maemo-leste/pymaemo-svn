import unittest
import gobject
import mafw

class MyPlugin(mafw.Renderer):
	__gtype_name__ = 'MyPlugin'

class TestMafwRegistry(unittest.TestCase):
    def test_get_instance(self):
        reg = mafw.Registry.get_instance()

	x1 = gobject.new(MyPlugin, uuid = 'test1')
	x2 = gobject.new(MyPlugin, uuid = 'test2')
	
	reg.add_extension(x1)
	reg.add_extension(x2)
	
        self.assertTrue(reg.get_renderers(), [x1, x2])

if __name__ == "__main__":
    unittest.main()

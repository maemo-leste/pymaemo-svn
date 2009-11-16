import unittest
import gobject
import mafw
from uuid import uuid4

class MySourcePlugin(mafw.Source):
    __gtype_name__ = 'MySourcePlugin'

class MyRendererPlugin(mafw.Renderer):
    __gtype_name__ = 'MyRendererPlugin'

class TestMafwRegistry(unittest.TestCase):


    def tearDown(self):
        reg = mafw.Registry.get_instance()

        for extension in reg.get_sources() + reg.get_renderers():
            reg.remove_extension(extension)

    def test_get_instance(self):
        reg = mafw.Registry.get_instance()
        self.assertTrue(isinstance(reg, mafw.Registry))

    def test_get_sources(self):
        reg = mafw.Registry.get_instance()
        x1 = gobject.new(MySourcePlugin, name='source1', uuid = uuid4())
        x2 = gobject.new(MySourcePlugin, uuid = uuid4(), name='source2')
        reg.add_extension(x1)
        reg.add_extension(x2)
        self.assertEquals(set(reg.get_sources()), set([x1, x2]))

    def test_get_renderers(self):
        reg = mafw.Registry.get_instance()
        x1 = gobject.new(MyRendererPlugin, uuid = uuid4(), name='renderer1')
        x2 = gobject.new(MyRendererPlugin, uuid = uuid4(), name='renderer2')
        reg.add_extension(x1)
        reg.add_extension(x2)
        x = reg.get_renderers()
        self.assertEquals(set(x), set([x1, x2]))

    def test_list_plugins(self):
        reg = mafw.Registry.get_instance()
        x1 = gobject.new(MyRendererPlugin, uuid = uuid4(), name='list1')
        x2 = gobject.new(MySourcePlugin, uuid =uuid4(), name='list2')
        reg.add_extension(x1)
        reg.add_extension(x2)
        self.assertEquals(set(reg.list_plugins()), set([x1, x2]))

if __name__ == "__main__":
    unittest.main()

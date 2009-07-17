
import pygtk
pygtk.require('2.0')
import gobject

class Extension(gobject.GObject):

    __gproperties__ = {
        'name': (gobject.TYPE_STRING, 'extension name',
                'descriptive name',
                '',
                gobject.PARAM_READWRITE),
    }

    __gtype_name__ = 'Extension'

    def __init__(self, name):
        gobject.GObject.__init__(self)
        self.name = name

    def do_get_property(self, property):
        if property.name == 'name':
            return self.name
        else:
            raise AttributeError('unknown property %s' % property.name)

    def do_set_property(self, property, value):
        if property.name == 'name':
            self.name = value
        else:
            raise AttributeError('unknown property %s' % property.name)

    def get_name(self):
        return self.name

SOURCE_INVALID_BROWSE_ID = 0
METADATA_KEY_TITLE = 'title'
METADATA_KEY_ARTIST = 'artist'
METADATA_KEY_ALBUM = 'album'
METADATA_KEY_GENRE = 'genre'

class Source(Extension):
    __gtype_name__ = 'Source'

class Renderer(Extension):
    __gtype_name__ = 'Renderer'

gobject.type_register(Extension)
gobject.type_register(Source)
gobject.type_register(Renderer)

class Registry(gobject.GObject):
    _instance = None

    __gtype_name__ = 'Registry'

    # TODO Check argument types
    __gsignals__ = {
        'renderer_added':
            (gobject.SIGNAL_RUN_FIRST, gobject.TYPE_NONE,
                    (gobject.TYPE_OBJECT,)),
        'renderer_removed':
            (gobject.SIGNAL_RUN_FIRST, gobject.TYPE_NONE,
                    (gobject.TYPE_OBJECT,)),
        'source_added':
            (gobject.SIGNAL_RUN_FIRST, gobject.TYPE_NONE,
                    (gobject.TYPE_OBJECT,)),
        'source_removed':
            (gobject.SIGNAL_RUN_FIRST, gobject.TYPE_NONE,
                    (gobject.TYPE_OBJECT,)),
    }

    def __init__(self):
        gobject.GObject.__init__(self)

    def get_renderers(self):
        return [Extension('renderer1')]

    def get_sources(self):
        return [Extension('Mafw-Tracker-Source'), Extension('source2')]

    @classmethod
    def get_instance(klass):
        if not Registry._instance:
            Registry._instance = Registry()
        return Registry._instance



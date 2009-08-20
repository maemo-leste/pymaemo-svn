import sys
import os
import logging

import mafw
import gobject

WANTED_SOURCE = 'Mafw-Tracker-Source'

logging.basicConfig(level=logging.INFO)
gobject.threads_init()

class SourceBrowsing(object):
    def __init__(self, obj_id):
        self.app_source = None
        self.obj_id = obj_id
        self.mainloop = gobject.MainLoop()
        self.registry = mafw.Registry.get_instance()
        if not self.registry:
            logging.error('Failed to get MafwRegistry reference')
            raise RuntimeError, 'Failed to get MafwRegistry reference'
        try:
            mafw.mafw_shared_init(self.registry)
        except gobject.GError, message:
            logging.warning('Ext. discovery failed: %s' % message)

        self._register_signals()
        self._add_existing_ext()
        self._check_in_process_plugins()

    def run(self):
        self.mainloop.run()

    def _register_signals(self):
        """Connect to extension discovery signals. These signals will be
        emitted when new extensions are started or removed."""

        logging.info('Registering signals...')
        self.registry.connect('renderer_added', self.renderer_added_cb)
        self.registry.connect('renderer_removed', self.renderer_removed_cb)
        self.registry.connect('source_added', self.source_added_cb, self.obj_id)
        self.registry.connect('source_removed', self.source_removed_cb)

    def _add_existing_ext(self):
        """Check for already started extensions."""

        logging.info('Adding existing sources and renderers...')
        extension_list = self.registry.get_renderers()
        for extension in extension_list:
            logging.info('Renderer added...')
            self.renderer_added_cb(self.registry, extension)

        extension_list = self.registry.get_sources()
        for extension in extension_list:
            logging.info('Source added...')
            self.source_added_cb(self.registry, extension)

    def _check_in_process_plugins(self):
        """Start in-process plugin loading."""

        logging.info('Checking for in-process plugins...')
        try:
            plugins = os.environ['MAFW_INP_PLUGINS'].split(':')
        except KeyError:
            logging.info('No in-process plugins requested.')
            return

        for plugin in plugins:
            logging.info('Loading in-process plugin %s...' % plugin)
            try:
                self.registry.load_plugin(plugin)
            except gobject.GError, message:
                logging.warning('Plugin loading failed: Unable to load inp. ' +
                    'plugin %s: %s' % (plugin, message))

    # Callbacks
    def source_added_cb(self, registry, source, data=None):
        print "DEBUG: source added"
        name = source.get_name()
        logging.info('Source %s available' % name)
        
        if name == WANTED_SOURCE:
            logging.info('Wanted source found!')
            self.app_source = source
            gobject.timeout_add(1000, self.do_browse_request, data)

    def source_removed_cb(self, registry, source, data=None):
        print "DEBUG: source removed"
        logging.info('Source %s removed' % source.get_name())
        
        if source == sef.app_source:
            logging.error('Required source removed!\nExiting...')
            self.mainloop.quit()

    def renderer_added_cb(self, registry, renderer, data=None):
        print "DEBUG: renderer added"
        logging.info('Renderer %s added' % renderer.get_name())

    def renderer_removed_cb(self, registry, renderer, data=None):
        logging.info('Renderer %s removed' % renderer.get_name())

    def do_browse_request(self, data=None):
        logging.info('Browsing %s on %s.' % (self.obj_id, WANTED_SOURCE))

        keys = [mafw.METADATA_KEY_TITLE, mafw.METADATA_KEY_ARTIST,
                mafw.METADATA_KEY_ALBUM, mafw.METADATA_KEY_GENRE]

        #self.browse_id = self.app_source.browse(
        #    self.obj_id,
        #    recursive = False,
        #    filter = None,
        #    sorting = None,
        #    keys = keys,
        #    offset = 0,
        #    count = 30,
        #    callback = self.browse_request_cb,
        #    user_data = None)
        
        self.browse_id = self.app_source.browse(self.obj_id, mafw.METADATA_KEY_TITLE, self.browse_request_cb)

        if self.browse_id == mafw.SOURCE_ERROR_INVALID_BROWSE_ID:
            logging.warning('Incorrect browse request')

        return False

    def browse_request_cb(self,
                          source,
                          browse_id,
                          remaining,
                          index,
                          object_id,
                          metadata,
                          data = None,
                          error = None):
        if not (error is None):
            logging.info('Browse error: %s' % error.message)
            return

        if not object_id:
            logging.info('Sorry, no songs found!')
        else:
            logging.info('Got result %d:' % index)
            title = metadata.get(mafw.METADATA_KEY_TITLE, 'Unknown')
            artist = metadata.get(mafw.METADATA_KEY_ARTIST, 'Unknown')
            album = metadata.get(mafw.METADATA_KEY_ALBUM, 'Unknown')
            genre = metadata.get(mafw.METADATA_KEY_GENRE, 'Unknown')

            logging.info('Object ID: %s' % object_id)
            logging.info('Title: %s' % title)
            logging.info('Artist: %s' % artist)
            logging.info('Album: %s' % album)
            logging.info('Genre: %s' % genre)

        if remaining == 0:
            logging.info('Browse operaton finished. Exiting...')
            self.mainloop.quit()

def main():
    if len(sys.argv) < 2:
        sys.stderr.write('Missing object identifier for browsing.\n')
        sys.exit(1)
    
    obj_id = sys.argv[1]
    
    logging.info('Starting example...')
    app = SourceBrowsing(obj_id)
    logging.info('Example started')
    app.run()
    logging.info('Example end!')

if __name__ == '__main__':
    main()

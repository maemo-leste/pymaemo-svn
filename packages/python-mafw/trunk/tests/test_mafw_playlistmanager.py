import unittest

import mafw

class ManagerGet(unittest.TestCase):

    def testBasic(self):
        manager = mafw.PlaylistManager.get()
        self.assert_(isinstance(manager, mafw.PlaylistManager))

class CreatePlaylist(unittest.TestCase):

    def setUp(self):
        self.manager = mafw.PlaylistManager.get()

    def testNoName(self):
        self.assertRaises(TypeError, self.manager.create_playlist)

    def testWrongArg(self):
        self.assertRaises(TypeError, self.manager.create_playlist, 33)

    def testBasic(self):
        playlist = self.manager.create_playlist('dummy')
        self.assert_(isinstance(playlist, mafw.ProxyPlaylist))

class ManagerSignals(unittest.TestCase):

    def setUp(self):
        self.manager = mafw.PlaylistManager.get()

    def testPlaylistCreated(self):
        self.manager.connect('playlist-created', lambda :1)

class PlaylistCreation(unittest.TestCase):
    def setUp(self):
        self.manager = mafw.PlaylistManager.get()

    def testCreate(self):
        # remove any existing playlist named "dummy"
        pls = filter(lambda x: x.get_name() == 'dummy',
                     self.manager.get_playlists())
        if pls:
            self.manager.destroy_playlist(pls[0])

        old_size = len(self.manager.get_playlists())
        playlist = self.manager.create_playlist('dummy')
        self.assertEqual(len(self.manager.get_playlists()), old_size + 1)
        self.manager.destroy_playlist(playlist)

if __name__ == "__main__":
    unittest.main()

import unittest
import random

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
        #TODO improve this...
        name = 'temp' + str(random.randint(0, 1000))
        old_size = len(self.manager.get_playlists())
        self.manager.create_playlist(name)
        self.assertEqual(len(self.manager.get_playlists()), old_size+1)

        playlist = [x for x in self.manager.get_playlists if x.get_name() == name][0]
        self.manager.destroy_playlist(playlist)

        self.assertEqual(len(self.manager.get_playlists()), old_size)

if __name__ == "__main__":
    unittest.main()

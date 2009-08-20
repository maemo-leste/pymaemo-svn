import sys
import logging

import mafw
import gobject

logging.basicConfig(level=logging.INFO)

def find_playlist(manager, name):
	for playlist in manager.get_playlists():
		if playlist.get_name() == name:
		        return playlist
    	else:
        	raise LookupError

if __name__ == '__main__':
	manager = mafw.PlaylistManager.get()
	playlist = manager.create_playlist("PlayTest")
	mylist = find_playlist(manager, "Playtest")
	mylist.insert_item(0, object_id)


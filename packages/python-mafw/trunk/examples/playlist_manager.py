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

def create_playlist(manager, name):
    manager.create_playlist(name)

def remove_playlist(manager, name):
    playlist = find_playlist(manager, name)
    manager.destroy_playlist(playlist)

def show_playlist(manager, name):
    playlist = find_playlist(manager, name)
    print 'Showing contents for playlist %s...' % name

    #TODO check if we can make playlist an iterator
    size = playlist.get_size()

    if size > 0:
        for i in range(size):
            item = playlist.get_item(i)
            print "  %s %s" % (i, item)
    else:
        print 'Playlist is empty'

def add_to_playlist(manager, name, object_id):
    print 'add', name, object_id
    playlist = find_playlist(manager, name)
    playlist.insert_item(0, object_id)

def remove_from_playlist(manager, name, object_id):
    print 'remove', name, object_id
    playlist = find_playlist(manager, name)

    print 'Searching for %s in playlist %s' % (object_id, name)

    #TODO check if we can make playlist an iterator
    size = playlist.get_size()

    for i in range(size):
        item = playlist.get_item(i)
        if item == object_id:
            playlist.remove_item(i)
            print 'Element found at position %d' % i
            break
    else:
        print 'Element not found'


functions = {
    'create':create_playlist,
    'remove':remove_playlist,
    'show':show_playlist,
    'add-item':add_to_playlist,
    'remove-item':remove_from_playlist,
}

def dispatch(mainloop, args):
    manager = mafw.PlaylistManager.get()

    try:
        command = args[0]
        args = args[1:]
        functions[command](manager, *args)
    except (TypeError, IndexError, KeyError):
        print >>sys.stderr, ("Please, provide one of these sets of arguments:\n" +
                             "  create <playlist-name>\n" +
                             "  remove <playlist-name>\n" +
                             "  show <playlist-name>\n" +
                             "  add-item <playlist-name> <object-id>\n" +
                             "  remove-item <playlist-name> <object-id>\n")
    except LookupError:
        print >>sys.stderr, "Playlist \"%s\" not found" % args[0]

    mainloop.quit()

def main(args):
    mainloop = gobject.MainLoop()

    gobject.timeout_add(100, dispatch, mainloop, args)
    mainloop.run()

if __name__ == '__main__':
    main(sys.argv[1:])

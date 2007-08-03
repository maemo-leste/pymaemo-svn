#!/usr/bin/python2.5

import osso
import abook

def main():
    context = osso.Context("abook_test", "0.0.1", False)
    abook.init_with_name("abook_test", context)

    print "ABook and osso.Context initialized"
    abook.get_osso_context()

    dialog = abook.ContactEditor()

    dialog.run()

if __name__ == "__main__":
    main()


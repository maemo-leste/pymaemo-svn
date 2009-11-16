Python-OSSO examples
********************

This document shows some examples of the functionalities available in the python-osso package.

`Download all examples <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/osso_examples.tar.gz>`_

Application
-----------

This example shows how to bring an application to foreground using
osso.Application.application_top().

* `osso_test_app.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/application/osso_test_app.py>`_
  - Application that will be brought to foreground.
* `osso_test_app.service <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/application/osso_test_app.service>`_
  - Service file for the target application.
* `osso_test_sender.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/application/osso_test_sender.py>`_
  - Application that will call the OSSO service.

Auto-saving / State Saving
--------------------------

These examples show how to use the auto-saving and state saving features
from python-osso. Each file is a separate example.

* `osso_test_autosave.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/autosave/osso_test_autosave.py>`_
  - The same objects from the example below, but instead of calling the save
  function directly, any changes call user_data_changed, and when exiting
  force_autosave is called.
* `osso_test_statesaving.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/autosave/osso_test_statesaving.py>`_
  - Creates a gtk.Entry and a gtk.HScale. It saves the state when the
  application goes to background or exits, restoring the state on
  the next startup, unless the device resets or is turned off.

Device State
------------

These examples show how to interact with the display and the device.

* `osso_test_device_on.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/device-state/osso_test_device_on.py>`_
  - Requests to turn on the display.
* `osso_test_device_blank_pause.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/device-state/osso_test_device_blank_pause.py>`_
  - Requests to do not blank the screen. This will keep the screen on for
  60 seconds.
* `osso_test_device_state_cb.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/device-state/osso_test_device_state_cb.py>`_
  - Registers a callback for device state changes (Offline mode, etc...).

Help
----

These examples show how to use HELP and enable the "?" button in dialogs

* `osso_test_help.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/helplib/osso_test_help.py>`_
  - Shows two buttons: one to load a help topic and another to open a dialog
  with an "?" button in titlebar.

Mime
----

These examples show how use the MIME functions.

* `osso_test_mime_category.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/mime/osso_test_mime_category.py>`_
  - Prints the category the specified mime type is in.
* `osso_test_mime_default-app.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/mime/osso_test_mime_default-app.py>`_
  - Prints information about the current default application for the given mime type.
* `osso_test_mime_open.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/mime/osso_test_mime_open.py>`_
  - Opens an file using the default application for its mime type.
* `osso_test_mime_icons.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/mime/osso_test_mime_icons.py>`_
  - Shows icons associated with a given mime type.

Plugin
------

This example shows how to load plugins.

* `test_plugin_app.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/plugin/test_plugin_app.py>`_
  - Loads the test plugin.
* `testplugin.c <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/plugin/testplugin.c>`_
  - Test plugin.
* `testplugin.desktop <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/plugin/testplugin.desktop>`_
  - Desktop file for the test plugin.

RPC
---

These examples show how to make remote procedure calls using python-osso.

* `osso_test_sender.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/rpc/osso_test_sender.py>`_
  - GUI app that requests a service from the target app.
* `osso_test_receiver.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/rpc/osso_test_receiver.py>`_
  - Sample service that will be called by osso_test_sender.py

Status Bar
----------

This example shows how to send events to status bar applets.

* `osso_test_statusbar.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/statusbar/osso_test_statusbar.py>`_
  - Requests the display applet to change the display brightness.

System Note
-----------

These examples show how to use notification dialogs with applications
that run without gui.

* `osso_test_note_dialog.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/systemnote/osso_test_note_dialog.py>`_
  - Shows a dialog note.
* `osso_test_note_infoprint.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/systemnote/osso_test_note_infoprint.py>`_
  - Shows an information banner.

Time Notification
-----------------

This example registers a callback and tries to set the system time.
Notice: Currently this won't change the time. (Even in C).

* `osso_test_timenotification.py <https://garage.maemo.org/svn/pymaemo/wwwold/documentation/python_osso_examples/code/timenotification/osso_test_timenotification.py>`_

References
----------

* Debian New Maintainers' Guide:
  http://www.us.debian.org/doc/maint-guide


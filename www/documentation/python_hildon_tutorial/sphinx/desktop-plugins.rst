.. _desktop-plugins:

Writing Desktop Widgets
#######################

Desktop widgets are programs designed to provide a certain functionality from the desktop area. These programs are usually limited, in the sense that they are not complex applications, normally representing "small" utilities or an extension of an existing application.

Desktop widgets can be written as python module and need also to provide a desktop file that describes them. According to where they'll be placed there can be Status Menu widgets and Home Area widgets.

Applets need to have a .desktop file describing them. The file contents are fields that describe certain properties of the applet.

.. _desktop-plugins-home-plugins:

Home widgets
************

Home widgets are located in the Home Area of the desktop. Since Hildon 2.2, Home Area applets stopped being resizable.

To better show how to write a Home Area applet, consider an applet "TimeOut" that allows the user to choose an action to be performed at a given time.

Home pug-ins should inherit from libhildondesktop's HDHomePluginItem. The following example presents the python code  for the mentioned applet.

Source file for TimeOut applet: lib-timeout-home-applet.py
==========================================================

.. literalinclude:: ../examples/lib-timeout-home-applet.py
 
              
As you can see in the example above, the controls used in the applet (``build_ui`` function) should be added to "TimeOutPlugin". In this case, the applet works as a standalone application but it could just provide a widget to activate a program defined in another header and independent from the applet.

.. _desktop-applets-desktop-file:

The .desktop File
=================

Although other fields can be assigned in a .desktop file, the example bellow shows a simple .desktop file for the "TimeOut" applet. The "Name" field will be the applet's name in the list when the user is choosing applets to add to the desktop. The "X-Path" field should be set to the .so file that was previously generated.

A .desktop file for the TimeOut applet: timeout-applet.desktop
==============================================================

.. literalinclude:: ../examples/timeout-applet.desktop
                  
For Home Area applets, .desktop files should be placed in the directory outputed by the following command:

::
  
  pkg-config libhildondesktop-1 --variable=hildonhomedesktopentrydir --variable=homedesktopentrydir
  
              
.. _desktop-plugins-status-menu:

Status Menu widgets
*******************

Status Menu widgets are placed in the Status Menu and can be divided into three categories: permanent, conditional and temporary. Permanent widgets are shown all the time. Conditional and temporary widgets are shown when a certain condition is fulfilled.

The way to write a plug-in for the Status Menu is pretty similar to writing it for the Home Area. The plug-in should inherit from HDStatusMenuItem. The next examples present a Status Menu plug-in which only shows a message when clicked.

              
Source file for Example Status Menu Plug-in: lib-example-status-menu-applet.py
==============================================================================

.. literalinclude:: ../examples/lib-example-status-menu-applet.py
              
.. _desktop-applets-status-menu-desktop-file:

The .desktop File
=================

The .desktop file for the Status Menu is analogous to the Home Area one but should have also the "Category" field where the priority of the applet is set (permanent, conditional or temporary) and the "Icon" field to set the icon's name. If the "Category" key is not set, then it is considered as permanent.

A .desktop file for the Status Menu example applet: lib-example-applet.desktop
==============================================================================

  
.. literalinclude:: ../examples/lib-example-applet.desktop

                  
For Home Area applets, .desktop files should be placed in the directory outputed by the following command:

::

  pkg-config libhildondesktop-1 --variable=homedesktopentrydir
  
              
.. _desktop-applets-buildin-applets:

Intall Applets
**************

To use an applet, it needs to copy .py file to "/usr/lib/hildon-desktop/"

Now you need to add the newly installed home widget to the desktop. For that you can either manually add it to the ~/.config/hildon-desktop/home.plugins file, or follow these instructions to add it using the Hildon Desktop interface:

   1. Click anywhere on the Maemo desktop background.
   2. You should see a "engine" icon on the top right. Click on it.
   3. It will be shown a menu bar containing "Desktop menu" and "Done". Click on "Desktop menu".
   4. You should now see a menu with 4 buttons. Click on the "Add widget" button.
   5. A menu containing the list of installed widgets will appear. Select the one we installed.
   6. Finally, click on "Done". 


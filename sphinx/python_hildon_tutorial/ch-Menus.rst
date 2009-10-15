.. _ch-Menus:

Menus
#####

The use of menus in Hildon applications follows a very different approach from the traditional application menus.

There is no menu bar, each window has a menu attached which is activated when the user presses the title area of the window. And, secondly, unlike typical menus in desktop applications, view menus do not follow a hierarchical structure. This menu, attached to a view, is called Touch View Menu.

Additionally Hildon provides Context menus, although those should be avoided when possible.

This chapter will review this two types of menus.

Touch View Menu
***************

The widget which should be used as a menu in the windows of a Hildon application is hildon.Appmenu.

This widget opens from the top of the screen, obscuring the topmost window, and contains a number of entries organized in one or two columns, depending on the screen orientation. Besides entries, application menus can also contain a group of filter buttons.

The entries are gtk.Buttons. You should assign the proper action to the each menu item for when they are activated.

Filters are toggle buttons that can be used for presentation/sorting purposes. For example, sorting alphabetically a list of contacts or changing the size of icons in a list.

To create a hildon.AppMenu you can use:

::

  hildon.AppMenu()


Once the application menu is created you can add entries to the menu by using the following functions:

::

  def append(self, item)
  def prepend(self, item)
  def insert(self, item, position)


These functions allow you to append, prepend an entry or add it in a certain position (from 0 to N-1, where N is the number of menus).

It is important keep the UI simple, so you should try to keep the menu as small as possible, avoiding to add unnecessary options. An application menu with more that 10 items will probably not be well displayed.

To add filter buttons you can use:

::


  def add_filter(self, filter)


Again, you should be careful with the number of filters that you add to the application menu. More than 4 might not be well displayed, even less, depending on the length of the labels. Filters should be grouped and act as radio buttons, that is, for any filter, there should be at least another filter with a different/opposite action. Actually, gtk.RadioButtons can be easily used to accomplish this by having them grouped (using gtk.RadioButton(group) like the next example shows) and by not drawing their indicator -- with the function gtk.ToggleButton.set_mode().

Once the menu is properly created and filled up with entries and filters you can add the menu to a hildon.Window. You can use the following functions to set and retrieve a window's menu, respectively:

::


  def set_app_menu(self, menu)
  def get_app_menu(self)


The following example shows how to create and set up an application menu.

Example of a Hildon application menu
====================================

.. literalinclude:: _static/examples/hildon-app-menu-example.py


Each entry and filter button in this example is attached to a function that simply changes a label in the main window.

.. warning:: FIX THIS Note that the function used to attach handlers to the entries is g_signal_connect_after(). So the handler will be called after the default handler of the signal "clicked". The default handler for entries and filters closes the menu.

Application Menus and Views
***************************

In the previous example there is only one view, but in applications with several views you can attach a different menu to each view, adding only options relevant to the displayed view.

The function hildon_window_set_app_menu() allows to set a menu to an HildonWindow and its descendant hildon.StackableWindow widget.

::


  window.set_app_menu(menu)


Note that submenus are not supported by view menus. Usually, a menu item that in a desktop application would have suboptions implies a new subview in a Hildon application.

A callback function for a complex menu entry could create a new hildon.StackableWindow to accomplish the task that the option refers to. The new window could have a different view menu attached that holds buttons to perform the action or even have the buttons on the window's area should it make more sense.

Context Menu
************

Context menu is usually invoked via long press over an item on the screen, like holding a finger over an image thumbnail. The menu should contain commands directly related to the chosen item.

The use of context menus should be avoided since it is a hidden and inconvenient way of interacting with the UI. hildon.AppMenus should be used instead, when possible.



To create a GtkMenu in a Hildon application you should use the following function instead of gtk_menu_new():

::

  gtk.Menu()


This function creates a gtk.Menu that allows Hildon specific styling.

When you use a gtk.Menu in your Hildon application you should carefully select the number of menu items because it is limited to what fits on the screen at once. Besides that, take into account that submenus are not allowed in order to keep a clear and simple UI.


.. _ch-Toolbars:

Toolbars
########

Toolbars are usually used to group some number of widgets in order to simplify customization of their look and layout. Hildon framework provides two specialized toolbars: hildon.FindToolbar and hildon.EditToolbar that will be explained bellow. Apart from that you can also use GtkToolbars in your Hildon application.

Find Toolbars
*************

hildon.FindToolbar is a toolbar that contains a search entry and a dropdown list with previously searched strings. An internal gtk.ListStore stores the items in the dropdown list. This list is a property of the widget called "list"

To create a hildon.FindToolbar you can use:

::

  hildon.FindToolbar(label, model=None, column=-1)
  
      
In this functions the argument label will be used as label which be displayed as label for the dropdown box.

The the function above allows to set the model which will be used to store the dropdown box. It is also necessary to indicate which column the search will retrieve the string from.

If the toolbar is created by using the first function, it will be necessary to manually set up the properties "list" and "column".

This widget provides the following function f for set and retrieve the index in the model of the current active item on the combo. An index -1 indicates no active items in both functions.

::

  def set_active(self, index)
  def get_active(self)
  
      
To get the index of the most recently added item in the toolbar you can use the following function.

::

  def get_last_index(self) 
  
      
Alternatively, you can use a gtk.TreeIter to reference the current active item.

::

  def set_active_iter(self, iter)
  def get_active_iter(self)  
  
      
After create and properly set up the toolbar is necessary to attach it to any window. hildon.Window provides the following function to attach a toolbar:

::
  
  def add_toolbar(self, toolbar) 
  
      
In case you need to add a common toolbar to all windows in your program, hildon.Program provides the following function to set and retrtieve a common toolbar to each window registered into the curretn program:

::

  
  def set_common_toolbar(self, toolbar)
  def get_common_toolbar(self)
  
      
Here a simple example that shows how to deal with a hildon.FindToolbar.

Using a Find Toolbar
====================

.. literalinclude:: ../examples/hildon-find-toolbar-example.py
 
        
In the example above a callback is set to handle the signal "history-append", emitted by the toolbar when a new item is added to the history. There are other interesting signals such as "history-append" that could be handle to perform aditional actions when they will be emitted.

Apart from the property which stores the internal list, other properties are available such as "max-characters" , which set the maximum length of the search string. To a complete description of the signals and properties available read the Hildon reference manual.

Edit Toolbars
*************

Edit toolbars are implemented by the widget hildon.EditToolbar.This widget is a toolbar to be used as main control and navigation interface for the edit UI mode. This toolbar contains a label and two buttons, being one of them an arrow pointing backwards and the other a button to perform a certain action. It also display a label which explain to the users the action that will be performed by the button and could give intructions to user on how to perform the action properly.

A typical example could be a view to delete several items in a list. The label would advice user to select the items to delete and those items will be deleted by clicking the button.

Typically, this toolbar will be attached to a edit view, meaning a hildon.StackableWindow used in the program to perform a certain editing action.

The action to be performing by clicking the action button should be implemented in a callback to handle the signal "button-clicked", that will be show in the example.

To create a new hildon.EditToolbar you should use:

::

  
  hildon.EditToolbar(label = None, button = None)
  
      
The creation function allows to set the two labels of the widget. If you use the simple creation function, you should set the labels by using the following functions.

::

  
  def set_label(self, label)
  def set_button_label(self, label) 
  
      
Once the edit toolbar is configured you need to attach it to a window by using:

::

  def add_toolbar(self, toolbar) 
  
      
As was said, the action to be done by clicking the button should be mplemented in a callback attached to the signal "button-clicked". This widgets define also another signal, "arrow-clicked", emitted when users click the arrow. Typically, the callback for the signal "arrow-clicked" should destroy the current edit view.

The example bellow shows how to use an edit toolbar. This example builds a main window showing a list of items and a button to go to a edit view where users can select several items and deleted by clicking the action button of the toolbar.

Using an Edit Toolbar
=====================

.. literalinclude:: ../examples/hildon-edit-toolbar-example.py
 
        
The most of stuff related to hildon.EditToolbar is in the function edit_window. This function creates a edit view, meaning that a new hildon.StackableWindow is created showing a treeview in which users can select several items.

Note that the edit window is set to fullscreen, thus, the hildon.EditToolbar will be displayed obscuring the usual window controls.

Using gtk.Toolbars in Hildon applications
*****************************************

You can use the widget gtk.Toolbar as you would do in a GTK+ application but taking account the following that:

* gtk.Toolbars should be used when there is only one content item visible (e.g. when editing a single image or editing a single email).
* There should be no menu commands or settings for hiding or showing toolbar. The toolbar is always shown in the view where you decided to put it.

Like the others toolbars, a gtk.Toolbar should be attached to a window by using:

::

  def add_toolbar(self, toolbar)
  
      
The following example shows how to use a gtk.ToolBar. The use is very close to how it would be use in a normal GTK+ application.

Using a gtk.Toolbar in a Hildon application
===========================================

.. literalinclude:: ../examples/hildon-toolbar-in-hildon-application-example.py

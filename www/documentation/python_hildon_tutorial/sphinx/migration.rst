.. _migration:

Migration
#########

Since Hildon 2.2 takes a great step from its previous versions, there are a number of approaches in the development of your program graphical user interface that might need to be migrated to this new kind of interfaces.

.. _migration-menus:

Menus
*****

Hildon app menu represents a big difference from the normal menus. If your application is to be finger-friendly then it is mandatory to feature an app menu.

Since the app menu is simply done with buttons, you can easily add them with the functions that the original menu items were assigned. On top of that, given the menu limited size (ten items), the items to be added must be carefully divided. For example, consider an advanced text edition program. The original menu bar had the following menus:

Menu example
============

.. code-block:: python

  File
      \ New
      \ Open
      \ Save
      \ Save As
      \ Quit
  Edit
      \ Copy
      \ Paste
      \ Cut
      \ Indent Type
          \ Tabs
          \ Spaces
      \ Preferences
  View
      \ Zoom In
      \ Zoom Out
      \ Normal Size
      \ Highlight
          \ C
          \ Python
          \ JAVA
  Help
      \ Contents
      \ About
  
              
A few decisions of what menus to include and which ones to divide or leave out need to be taken. For example, the "File" menu is a mandatory one and should be accessible from the main window's menu. On the other hand, the "Quit" sub menu is not really necessary since the user can quit the application using the upper right corner's cross. Considering that the device has "+" and "-" keys, those can be assigned the functions of zooming in and out of the "View" menu. The "Copy", "Paste" and "Cut" actions from the "Edit" menu are also present in the application's toolbar as well as by using keyboard shortcuts so, they are not included in the menu. The "Indent Type" menu can be accomplished using app menu filters being, for this, removed from the "Edit" menu as well. This results in the "Edit" menu having only a sub menu "Preferences" which can be added to the app menu directly instead.

The following example shows the implementation of the menu following the above decisions. Figure @@IMAGE@@ shows the final result of the app menu. Figures @@IMAGE@@ and @@IMAGE@@ show the sub views activated by the menus "View" and "Help", respectively.

Migrating a menu
================

.. literalinclude:: ../examples/hildon-migration-example1.py

.. _migration-choices:

Choices
*******

Some widgets for choosing options also need to be adapted to the new Hildon way of designing interfaces. When having several radio buttons to express a choice, it is a good idea to replace those with a picker button.

Consider a dialog where, among other widgets, there's a frame labeled "Proxy Preferences" and three radio buttons: "None", "Auto" and "Manual", displayed vertically like :ref:`example-choices` shows. The following example shows how such task could be accomplished using a picker button. The frame label becomes the picker button's title and the three radio buttons' labels become the choices in the picker's touch selector. @@IMAGE@@ shows a screenshot of the resulting graphical user interface.

.. _example-choices:

.. figure:: ../../tutorial/images/choices.png
  :align: center

  Three radio buttons

Migrating choice widgets
========================

.. literalinclude:: ../examples/hildon-migration-example2.py
 
              
.. _migration-notebooks:

Notebooks
*********

Since the use of notebooks is not advised in Hildon, there's the need to replace this widget with something that accomplishes the same task.

Imagine a preferences dialog that has a notebook to divide the preferences in "General", "Colors" and "Tools" like depicted in :ref:`example-notebook` . The way to accomplish the same functionality without having a notebook is to have a window with buttons that open other windows as sub views. Each of the windows opened from the buttons should have the contents that the respective page in the notebook had.

.. _example-notebook:

.. figure:: ../../tutorial/images/notebook.png
  :align: center

  Typical Notebook

The example shows the code to produce a replacement for the notebook (see @@IMAGE@@).

Migrating a notebook
====================

.. literalinclude:: ../examples/hildon-migration-example3.py
 
              

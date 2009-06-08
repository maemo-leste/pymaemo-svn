.. _ch-Selectors:

Data Selection
##############

Hildon provides a set of widgets for data selection specially designed for touchscreens that allows to build simple and easy-to-use interfaces.

The key widget is a selector widget that allows users to select items from one to many predefined lists. It is similar to a combo box but allows several individual pannable columns.

In addition, Hildon also provides a specialized dialog and a specialized button to be used in combination with a selector.

Touch selector
**************

hildon.TouchSelector is the mentioned selector widget. This widget can display several pannable columns. Each column is represented by a GtkTreeModel and single or multiple selection is allowed.

[ SCREENSHOT ]

Text Columns Example
====================

Let us see the simplest possible example. A selector that shows a single text column.

Example of a single-column selector
===================================

.. literalinclude:: ../examples/hildon-single-column-selector-example.py
  
          
A hildon.TouchSelector with a single text column is created in this program using the following convenience constructor.

::
  
  hildon.touch_selector_new_text() 
  
        
To add text to a selector created by calling the constructor above you can simply use the function .

::

  def append(self, text):
  
        
Alternatively, you could use prepend_text() or insert_text() to add text to the selector in different positions.

The desired selection mode can be set with the function . In the example, the mode was set to allow multiple selection.

::

  def set_column_selection_mode(self, mode):
  
        
This example shows a very common use case of this widget. Next section shows how to build a more complex selector with several columns of different types.

Also a simple function was set as a handler for the "changed" signal. This signal is emitted each time the selected items change.

The callback retrieves a text representation of the currently selected items in the selector by calling get_current_text(). By default this function will return a concatenation of the items selected, separated by a comma.

To change how the text representation is generated you can set your own function. The function can set by calling set_print_func() and should have following signature.

::

  def user_function (selector):
  
        
Custom columns
==============

In the previous section, a selector with a text column was created. That is probably the most common use case of touch selectors. Convenience functions to deal with text columns was used. But you can also set other type of columns.

Since each column in this widget is basically a treeview, you can use the same display to different data and in different ways as you would do with a gtk.Treeview. Thus, you can use the gtk.CellRenderers available in GTK+ to display the data on each cell.

This section explains how to build a selector within a column displaying stock icons. Firstly, let us take a look on the function which will be used to append new columns to a touchable selector.

::

  def append_column(self, model, cell_renderer, ...):
  
        
This functions adds a new column to the widget, whose data will be obtained from the passed model. You should also pass a gtk.CellRenderer and a list of pairs property/value which will be set as attributes of the renderer.

This function basically adds a gtk.TreeView to the widget, so if you know how gtk.Treeviews work you do won't have problems with it, otherwise it is highly recommended that you check that GTK+ widget before (LINKS TO GTK TUTORIAL / REFERENCE )

Next example shows how to set a column to display images in a selector. To keep the example clear enough, only the function which creates the selector will be shown.

Example of a selector with a custom column
==========================================

.. literalinclude:: ../examples/hildon-customized-column-selector-example.py
  
          
The first step in the example is to create and populate a gtk.TreeModel. A gtk.ListStore is used in the example. In most use cases of the touchable selectors a gtk.ListStore fits well as selectors were designed to allow users to select from a list of items.

In this case, the model stores a list of GTK+ stock icons identifiers. The following call creates a list store with one column to store strings.

::

    store_icons = gtk.ListStore(G_TYPE_STRING);
  
        
The following loop appends all stock identifiers in the newly created model. The identifiers were previously retrieved using gtk_stock_list_ids().

::

    for item in icon_list:
      new_iter = store_icons.append()
      store_icons.set(new_iter, 0, item)
  
        
Next step is to set up the renderer which will render each row of the new column. We need a gtk.CellRendererPixbuf to display the stock icons.

::

    renderer = gtk.CellRendererPixbuf()
  
        
Finally, we create and append the new column, using the model and renderer previously created.

This call also sets the property "stock-id" of the gtk.CellrendererPixbuf. The value is set to 0 which is the number of the column in the gtk.TreeModel that stores the stock-id.

::
  
    column = column = selector.append_column(store_icons, renderer, "stock-id", 0)
  
        
Summarizing, setting a new custom column in a touchable selector is quite similar to setting a new column in a normal gtk.Treeview. It is necessary to create a model to store the data and a cell renderer to properly show this data in each row, and finally add the new column.

Picker Dialog and Picker buttons
********************************

Normally, you would use hildon.TouchSelector together with a hildon.PickerDialog activated from a button. For most common cases, you should use hildon.PickerButton.

This is the usual way to present a selector to the user. The picker button will open a dialog which presents the selector and properly manages user interaction.

Example
=======

Previous sections showed you how to create a touchable selector. In the most cases the following step would be to attach the selector to a hildon.PickerButton.

A hildon.PickerButton is a special gtk.Button which displays two labels, title and value, and brings up a hildon.PickerDialog. The user would choose one or several items. A string representation of the chosen items will be displayed in the value label of the picker button.

Below, a modified version of the previous main function is shown, in which you can check how a hildon.PickerButton is created and attached to a selector. Also a callback to catch the signal "value-changed" emitted is added.

Example of a Hildon picker button
=================================

.. literalinclude:: ../examples/hildon-picker-button-example.py
  
In the above example a picker button is created. The reference to the attached selector is stored in the property "touch-selector" of the picker button. You can use function get_selector() to retrieve the attached selector and set_selector() to attach the selector.

Note that you do not need to take care of the hildon.PickerDialog. The dialog is automatically brought up when users click the picker button and closed when the selection is done.

The dialog shows a button "Done" to allow users finish the selection when the touchable selector allows multiple selection. When the selector allows only single selection, the dialog does not show any button and closes when the user tap one item.

The label of the button "Done" can be set by using set_done_button_text() and retrieved by using get_done_button_text().

When users finish their selection, the value label on the button automatically changes to show a textual representation of the item or items selected.

In most cases you could want to perform any action when selection is finished. To do that you add a handler to the signal "value-changed" of the picker button. In this example the handler attached to "value-changed" signal retrieves the value label of the button and prints a debug message.

Touch Selector Entry
********************

The hildon.TouchSelectorEntry is a selector widget with a text entry that allows users to select an item from a predefined list or to enter a different one in a hildon.Entry. Items can also be searched and selected by typing in the entry.

An additional feature is that the hildon.Entry is auto-completed with the list's items as the user types their name.

Example
=======

Example above shows how to build a selector to pick a word in a list of words.

Example of a Hildon picker button with a selector entry
=======================================================

.. literalinclude:: ../examples/hildon-picker-button-with-selector-entry-example.py
 
          
As you can see in the example above, the use of this widget is closely similar to the use of a normal touchable selector.

You can also use custom columns in a hildon.TouchableEntry but always at least a column should be a text column. The text column is indicated by the property "text_column" which you should set with set_text_column().

Pre-built Selectors
*******************

The widgets hildon.DateButton and hildon.TimeButton are buttons displaying and allowing the selection of date and time, respectively. Developers could use them directly instead of building their own date or time selectors.

Both widgets are specialized picker buttons with a convenient touchable selector attached that you can directly use in your application.

Here a simple application using a hildon.DateButton.

Example of a Hildon date button
===============================

.. literalinclude:: ../examples/hildon-date-button-example.py
        

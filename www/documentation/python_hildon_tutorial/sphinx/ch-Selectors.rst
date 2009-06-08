.. _ch-Selectors:

Data Selection
##############

Hildon provides a set of widgets for data selection specially designed for touchscreens that allows to build simple and easy-to-use interfaces.

The key widget is a selector widget that allows users to select items from one to many predefined lists. It is similar to a combo box but allows several individual pannable columns.

In addition, Hildon also provides a specialized dialog and a specialized button to be used in combination with a selector.

Touch selector
**************

HildonTouchSelector is the mentioned selector widget. This widget can display several pannable columns. Each column is represented by a GtkTreeModel and single or multiple selection is allowed.

[ SCREENSHOT ]

Text Columns Example
====================

Let us see the simplest possible example. A selector that shows a single text column.

Example of a single-column selector
===================================

.. code-block:: python

  
  
  #include                                        <hildon/hildon.h>
  
  static void
  selection_changed (HildonTouchSelector * selector,
                     gpointer *user_data)
  {
    gchar *current_selection = NULL;
  
    current_selection = hildon_touch_selector_get_current_text (selector);
    g_debug ("Current selection : %s", current_selection);
  }
  
  static GtkWidget *
  create_simple_selector (void)
  {
    GtkWidget *selector;
    gint i;
  
    /* Create a HildonTouchSelector with a single text column */
    selector = hildon_touch_selector_new_text();
  
    /* Set selection mode to allow multiple selection */
    hildon_touch_selector_set_column_selection_mode (HILDON_TOUCH_SELECTOR (selector),
                                          HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE);
  
    /* Set a handler to "changed" signal */
    g_signal_connect (G_OBJECT (selector), "changed",
                      G_CALLBACK (selection_changed), NULL);
  
    /* Populate selector */
    for (i = 1; i <= 10 ; i++) {
      gchar *label = g_strdup_printf ("Item %d", i);
  
      /* Add item to the column */
      hildon_touch_selector_append_text (HILDON_TOUCH_SELECTOR (selector),
                                         label);
  
      g_free (label);
    }
  
    return selector;
  }
  
  int
  main (int argc, char **argv)
  {
    HildonProgram *program = NULL;
    GtkWidget *window = NULL;
    GtkWidget *selector = NULL;
  
    hildon_gtk_init (&argc, &argv);
  
    program = hildon_program_get_instance ();
    g_set_application_name ("hildon-touch-selector example program");
  
    window = hildon_stackable_window_new ();
    hildon_program_add_window (program, HILDON_WINDOW (window));
  
    /* Create touch selector */
    selector = create_simple_selector ();
    gtk_container_add (GTK_CONTAINER (window), selector);
  
    g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
  
    gtk_widget_show_all (GTK_WIDGET (window));
  
    gtk_main ();
  
    return 0;
  }
  
          
A HildonTouchSelector with a single text column is created in this program using the following convenience constructor.

::

  
  
  GtkWidget*  hildon_touch_selector_new_text  (void);
  
        
To add text to a selector created by calling the constructor above you can simply use the function .

::

  
  
  void        hildon_touch_selector_append_text (HildonTouchSelector *selector,
                                                 const gchar *text);
  
        
Alternatively, you could use hildon_touch_selector_prepend_text() or hildon_touch_selector_insert_text() to add text to the selector in different positions.

The desired selection mode can be set with the function . In the example, the mode was set to allow multiple selection.

::

  
  
  void        hildon_touch_selector_set_column_selection_mode
                                              (HildonTouchSelector *selector,
                                               HildonTouchSelectorSelectionMode mode);
  
        
This example shows a very common use case of this widget. Next section shows how to build a more complex selector with several columns of different types.

Also a simple function was set as a handler for the "changed" signal. This signal is emitted each time the selected items change.

The callback retrieves a text representation of the currently selected items in the selector by calling hildon_touch_selector_get_current_text(). By default this function will return a concatenation of the items selected, separated by a comma.

To change how the text representation is generated you can set your own function. The function can set by calling hildon_touch_selector_set_print_func() and should have following signature.

::

  
  
  gchar*      user_function (HildonTouchSelector *selector);
  
        
Custom columns
==============

In the previous section, a selector with a text column was created. That is probably the most common use case of touch selectors. Convenience functions to deal with text columns was used. But you can also set other type of columns.

Since each column in this widget is basically a treeview, you can use the same display to different data and in different ways as you would do with a GtkTreeview. Thus, you can use the GtkCellRenderers available in GTK+ to display the data on each cell.

This section explains how to build a selector within a column displaying stock icons. Firstly, let us take a look on the function which will be used to append new columns to a touchable selector.

::

  
  
  HildonTouchSelectorColumn* hildon_touch_selector_append_column
                                              (HildonTouchSelector *selector,
                                               GtkTreeModel *model,
                                               GtkCellRenderer *cell_renderer,
                                               ...);
  
        
This functions adds a new column to the widget, whose data will be obtained from the passed model. You should also pass a GtkCellRenderer and a list of pairs property/value which will be set as attributes of the renderer.

This function basically adds a GtkTreeView to the widget, so if you know how GtkTreeviews work you do won't have problems with it, otherwise it is highly recommended that you check that GTK+ widget before (LINKS TO GTK TUTORIAL / REFERENCE )

Next example shows how to set a column to display images in a selector. To keep the example clear enough, only the function which creates the selector will be shown.

Example of a selector with a custom column
==========================================

.. code-block:: python

  
  
  static GtkWidget *
  create_customized_selector()
  {
    GtkWidget *selector;
    GSList *icon_list = NULL;
    GtkListStore *store_icons = NULL;
    GSList *item = NULL;
    GtkCellRenderer *renderer = NULL;
    HildonTouchSelectorColumn *column = NULL;
  
    /* Create a touch selector */
    selector = hildon_touch_selector_new();
  
    /* Stock icons will be used for the example */
    icon_list = gtk_stock_list_ids();
  
    /* Create model to store selector's items */
    store_icons = gtk_list_store_new (1, G_TYPE_STRING);
  
    /* Populate model */
    for (item = icon_list; item; item = g_slist_next (item)) {
      GtkTreeIter iter;
      gchar *label = item->data;
  
      gtk_list_store_append (store_icons, &iter);
      gtk_list_store_set (store_icons, &iter, 0, label, -1);
      g_free (label);
    }
    g_slist_free (icon_list);
  
    /* Create and set up a pixbuf renderer to use in the selector */
    renderer = gtk_cell_renderer_pixbuf_new();
    gtk_cell_renderer_set_fixed_size (renderer, -1, 100);
  
    /* Add the column to the selector */
    column = hildon_touch_selector_append_column (HILDON_TOUCH_SELECTOR (selector),
                                                  GTK_TREE_MODEL (store_icons),
                                                  renderer,
                                                  "stock-id", 0,
                                                  NULL);
  
    /* Set the selection mode */
    hildon_touch_selector_set_column_selection_mode (HILDON_TOUCH_SELECTOR (selector),
                                      HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE);
  
    /* Set the property "text-column" that indicates the column
     * of the model to get the string from */
    g_object_set (G_OBJECT (column), "text-column", 0, NULL);
  
    return selector;
  }
  
          
The first step in the example is to create and populate a GtkTreeModel. A GtkListStore is used in the example. In most use cases of the touchable selectors a GtkListStore fits well as selectors were designed to allow users to select from a list of items.

In this case, the model stores a list of GTK+ stock icons identifiers. The following call creates a list store with one column to store strings.

::

  
  
    store_icons = gtk_list_store_new (1, G_TYPE_STRING);
  
        
The following loop appends all stock identifiers in the newly created model. The identifiers were previously retrieved using gtk_stock_list_ids().

::

  
  
    for (item = icon_list; item; item = g_slist_next (item)) {
      GtkTreeIter iter;
      gchar *label = item->data;
  
      gtk_list_store_append (store_icons, &iter);
      gtk_list_store_set (store_icons, &iter, 0, label, -1);
      g_free (label);
    }
    g_slist_free (icon_list);
  
        
Next step is to set up the renderer which will render each row of the new column. We need a GtkCellRendererPixbuf to display the stock icons.

::

  
  
    renderer = gtk_cell_renderer_pixbuf_new();
  
        
Finally, we create and append the new column, using the model and renderer previously created.

This call also sets the property "stock-id" of the GtkCellrendererPixbuf. The value is set to 0 which is the number of the column in the GtkTreeModel that stores the stock-id.

::

  
  
    column = hildon_touch_selector_append_column (HILDON_TOUCH_SELECTOR (selector),
  	                                        GTK_TREE_MODEL (store_icons),
                                                  renderer,
                                                  "stock-id", 0,
                                                  NULL);
  
        
Summarizing, setting a new custom column in a touchable selector is quite similar to setting a new column in a normal GtkTreeview. It is necessary to create a model to store the data and a cell renderer to properly show this data in each row, and finally add the new column.

Picker Dialog and Picker buttons
********************************

Normally, you would use HildonTouchSelector together with a HildonPickerDialog activated from a button. For most common cases, you should use HildonPickerButton.

This is the usual way to present a selector to the user. The picker button will open a dialog which presents the selector and properly manages user interaction.

Example
=======

Previous sections showed you how to create a touchable selector. In the most cases the following step would be to attach the selector to a HildonPickerButton.

A HildonPickerButton is a special GtkButton which displays two labels, title and value, and brings up a HildonPickerDialog. The user would choose one or several items. A string representation of the chosen items will be displayed in the value label of the picker button.

Below, a modified version of the previous main function is shown, in which you can check how a HildonPickerButton is created and attached to a selector. Also a callback to catch the signal "value-changed" emitted is added.

Example of a Hildon picker button
=================================

.. code-block:: python

  
  
  static void
  on_picker_value_changed (HildonPickerButton * button, gpointer data)
  {
    g_print ("Newly selected value: %s\n",
             hildon_button_get_value (HILDON_BUTTON (button)));
  }
  
  int
  main (int argc, char **argv)
  {
    HildonProgram *program;
    GtkWidget *window;
    GtkWidget *picker_button;
  
    hildon_gtk_init (&argc, &argv);
  
    program = hildon_program_get_instance ();
    g_set_application_name ("hildon-touch-selector example program");
  
    window = hildon_stackable_window_new ();
    hildon_program_add_window (program, HILDON_WINDOW (window));
  
    /* Create touch selector */
    selector = create_customized_selector ();
  
    /* Create a picker button */
    picker_button = hildon_picker_button_new (HILDON_SIZE_AUTO,
                                              HILDON_BUTTON_ARRANGEMENT_VERTICAL);
  
    /* Set a title to the button */
    hildon_button_set_title (HILDON_BUTTON (picker_button), "Select an item");
  
    /* Attach the touch selector to the picker button*/
    hildon_picker_button_set_selector (HILDON_PICKER_BUTTON (picker_button),
                                       HILDON_TOUCH_SELECTOR (selector));
  
    /* Attach callback to the "value-changed" signal*/
    g_signal_connect (G_OBJECT (picker_button), "value-changed",
                      G_CALLBACK (on_picker_value_changed), NULL);
  
  
    /* Add button to main window */
    gtk_container_add (GTK_CONTAINER (window), picker_button);
  
    g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
  
    gtk_widget_show_all (GTK_WIDGET (window));
  
    gtk_main ();
  
    return 0;
  }
  
          
In the above example a picker button is created. The reference to the attached selector is stored in the property "touch-selector" of the picker button. You can use function hildon_picker_button_get_selector() to retrieve the attached selector and hildon_picker_button_set_selector() to attach the selector.

Note that you do not need to take care of the HildonPickerDialog. The dialog is automatically brought up when users click the picker button and closed when the selection is done.

The dialog shows a button "Done" to allow users finish the selection when the touchable selector allows multiple selection. When the selector allows only single selection, the dialog does not show any button and closes when the user tap one item.

The label of the button "Done" can be set by using hildon_picker_button_set_done_button_text() and retrieved by using hildon_picker_button_get_done_button_text().

When users finish their selection, the value label on the button automatically changes to show a textual representation of the item or items selected.

In most cases you could want to perform any action when selection is finished. To do that you add a handler to the signal "value-changed" of the picker button. In this example the handler attached to "value-changed" signal retrieves the value label of the button and prints a debug message.

Touch Selector Entry
********************

The HildonTouchSelectorEntry is a selector widget with a text entry that allows users to select an item from a predefined list or to enter a different one in a HildonEntry. Items can also be searched and selected by typing in the entry.

An additional feature is that the HildonEntry is auto-completed with the list's items as the user types their name.

Example
=======

Example above shows how to build a selector to pick a word in a list of words.

Example of a Hildon picker button with a selector entry
=======================================================

.. code-block:: python

  
  
  #include        <hildon/hildon.h>
  
  static const gchar* artists [] = {
    "AC/DC",
    "Aerosmith",
    "Alice in Chains",
    "Black Sabbath",
    "Carcass",
    "Danzig",
    "Deep Purple",
    "Dream Theater",
    "Eric Clapton",
    NULL
  };
  
  int
  main (int argc, char **argv)
  {
    HildonProgram *program;
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *selector;
    gint i;
  
    hildon_gtk_init (&argc, &argv);
  
    program = hildon_program_get_instance ();
    g_set_application_name
      ("HildonTouchSelectorEntry example program");
  
    window = hildon_stackable_window_new ();
    hildon_program_add_window (program, HILDON_WINDOW (window));
  
    /* Create a picker button */
    button = hildon_picker_button_new (HILDON_SIZE_AUTO,
                                       HILDON_BUTTON_ARRANGEMENT_VERTICAL);
  
    hildon_button_set_title (HILDON_BUTTON (button), "Pick a band!");
  
    /* Create a touch selector entry */
    selector = hildon_touch_selector_entry_new_text ();
  
    /* Populate the selector */
    for (i = 0; artists [i] != NULL; i++) {
      hildon_touch_selector_append_text (HILDON_TOUCH_SELECTOR (selector),
                                         artists [i]);
    }
  
    /* Attach selector to the picker button */
    hildon_picker_button_set_selector (HILDON_PICKER_BUTTON (button),
                                       HILDON_TOUCH_SELECTOR (selector));
  
    gtk_container_add (GTK_CONTAINER (window), button);
    g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
    gtk_widget_show_all (GTK_WIDGET (window));
  
    gtk_main ();
  
    return 0;
  }
  
          
As you can see in the example above, the use of this widget is closely similar to the use of a normal touchable selector.

You can also use custom columns in a HildonTouchableEntry but always at least a column should be a text column. The text column is indicated by the property "text_column" which you should set with hildon_touch_selector_entry_set_text_column().

Pre-built Selectors
*******************

The widgets HildonDateButton and HildonTimeButton are buttons displaying and allowing the selection of date and time, respectively. Developers could use them directly instead of building their own date or time selectors.

Both widgets are specialized picker buttons with a convenient touchable selector attached that you can directly use in your application.

Here a simple application using a HildonDateButton.

Example of a Hildon date button
===============================

.. code-block:: python

  
  
  #include <hildon/hildon.h>
  
  int
  main (int argc, char **argv)
  {
    HildonProgram *program;
    GtkWidget *window;
    GtkWidget *selector;
  
    GtkWidget *date_button;
  
    hildon_gtk_init (&argc, &argv);
  
    program = hildon_program_get_instance ();
    g_set_application_name ("hildon-touch-selector example program");
  
    window = hildon_stackable_window_new ();
    hildon_program_add_window (program, HILDON_WINDOW (window));
  
    /* Create a date picker */
    date_button = hildon_date_button_new (HILDON_SIZE_AUTO,
                                            HILDON_BUTTON_ARRANGEMENT_VERTICAL);
  
    /* Set a title to the button*/
    hildon_button_set_title (HILDON_BUTTON (date_button), "Select an item");
  
    /* Add button to main window */
    gtk_container_add (GTK_CONTAINER (window), date_button);
  
    g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
  
    gtk_widget_show_all (GTK_WIDGET (window));
  
    gtk_main ();
  
    return 0;
  }
  
        

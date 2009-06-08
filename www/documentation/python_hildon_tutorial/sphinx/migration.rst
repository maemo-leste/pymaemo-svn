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

.. code-block:: python

  
  
  #include <hildon/hildon.h>
  
  static void
  normal_zoom_cb ()
  {
      /* Code to set normal zoom... */
  
      hildon_window_stack_pop_1 (hildon_window_stack_get_default());
  }
  
  static void
  view_subview ()
  {
      HildonStackableWindow *view_window;
      view_window = HILDON_STACKABLE_WINDOW (hildon_stackable_window_new ());
      gtk_window_set_title (GTK_WINDOW (view_window), "View");
  
      GtkButton *normal_zoom_button = GTK_BUTTON (hildon_gtk_button_new (
                                  HILDON_SIZE_FINGER_HEIGHT | HILDON_SIZE_AUTO_WIDTH));
      gtk_button_set_label (normal_zoom_button, "Normal Zoom");
      g_signal_connect (G_OBJECT (normal_zoom_button), "clicked",
                        G_CALLBACK (normal_zoom_cb), NULL);
  
      HildonTouchSelector *highlight_selector;
      highlight_selector = HILDON_TOUCH_SELECTOR (hildon_touch_selector_new_text ());
      hildon_touch_selector_append_text (highlight_selector, "C");
      hildon_touch_selector_append_text (highlight_selector, "JAVA");
      hildon_touch_selector_append_text (highlight_selector, "Python");
      HildonPickerButton *highlight_picker = HILDON_PICKER_BUTTON (hildon_picker_button_new (
                                      HILDON_SIZE_THUMB_HEIGHT | HILDON_SIZE_HALFSCREEN_WIDTH,
                                                  HILDON_BUTTON_ARRANGEMENT_VERTICAL));
      hildon_button_set_title (HILDON_BUTTON (highlight_picker), "Syntax highlight:");
      hildon_picker_button_set_selector (highlight_picker, highlight_selector);
      hildon_picker_button_set_active (highlight_picker, 0);
  
      GtkVBox *contents = GTK_VBOX (gtk_vbox_new (12, FALSE));
      gtk_box_pack_end (GTK_BOX (contents), GTK_WIDGET (highlight_picker), FALSE, FALSE, 0);
      gtk_box_pack_end (GTK_BOX (contents), GTK_WIDGET (normal_zoom_button), FALSE, FALSE, 0);
  
      gtk_container_add (GTK_CONTAINER (view_window), GTK_WIDGET (contents));
  
      gtk_widget_show_all (GTK_WIDGET (view_window));
  }
  
  static void
  help_contents_cb (GtkButton *widget, gpointer data)
  {
      /* Code to set show help contents... */
  
      hildon_window_stack_pop_1 (hildon_window_stack_get_default());
  }
  
  static void
  help_about_cb (GtkButton *widget, gpointer data)
  {
      /* Code to set show about information... */
  
      hildon_window_stack_pop_1 (hildon_window_stack_get_default());
  }
  
  static void
  help_subview ()
  {
      HildonStackableWindow *view_window;
      view_window = HILDON_STACKABLE_WINDOW (hildon_stackable_window_new ());
      gtk_window_set_title (GTK_WINDOW (view_window), "Help");
  
      GtkButton *help_contents_button = GTK_BUTTON (hildon_gtk_button_new (
                                  HILDON_SIZE_FINGER_HEIGHT | HILDON_SIZE_AUTO_WIDTH));
      gtk_button_set_label (help_contents_button, "Contents");
      g_signal_connect (G_OBJECT (help_contents_button), "clicked",
                        G_CALLBACK (help_contents_cb), NULL);
  
      GtkButton *help_about_button = GTK_BUTTON (hildon_gtk_button_new (
                                  HILDON_SIZE_FINGER_HEIGHT | HILDON_SIZE_AUTO_WIDTH));
      gtk_button_set_label (help_about_button, "About");
      g_signal_connect (G_OBJECT (help_about_button), "clicked",
                        G_CALLBACK (help_about_cb), NULL);
  
      GtkVBox *contents = GTK_VBOX (gtk_vbox_new (12, FALSE));
      gtk_box_pack_end (GTK_BOX (contents), GTK_WIDGET (help_contents_button), FALSE, FALSE, 0);
      gtk_box_pack_end (GTK_BOX (contents), GTK_WIDGET (help_about_button), FALSE, FALSE, 0);
  
      gtk_container_add (GTK_CONTAINER (view_window), GTK_WIDGET (contents));
  
      gtk_widget_show_all (GTK_WIDGET (view_window));
  }
  
  static HildonAppMenu *
  build_menu (void)
  {
      HildonSizeType button_size = HILDON_SIZE_FINGER_HEIGHT | HILDON_SIZE_AUTO_WIDTH;
      HildonAppMenu *menu = HILDON_APP_MENU (hildon_app_menu_new ());
      GtkButton *button;
      GtkRadioButton *filter;
  
      /* Menus like New, Open, etc that would open new dialogs (no submenus)
       * are not assigned any action in this example
       */
  
      button = GTK_BUTTON (hildon_gtk_button_new (button_size));
      gtk_button_set_label (button, "New");
      hildon_app_menu_append (menu, GTK_BUTTON (button));
  
      button = GTK_BUTTON (hildon_gtk_button_new (button_size));
      gtk_button_set_label (button, "Open");
      hildon_app_menu_append (menu, GTK_BUTTON (button));
  
      button = GTK_BUTTON (hildon_gtk_button_new (button_size));
      gtk_button_set_label (button, "Save As");
      hildon_app_menu_append (menu, GTK_BUTTON (button));
  
      button = GTK_BUTTON (hildon_gtk_button_new (button_size));
      gtk_button_set_label (button, "Preferences");
      hildon_app_menu_append (menu, GTK_BUTTON (button));
  
      button = GTK_BUTTON (hildon_gtk_button_new (button_size));
      gtk_button_set_label (button, "View");
      g_signal_connect (G_OBJECT (button), "clicked",
                        G_CALLBACK (view_subview), NULL);
      hildon_app_menu_append (menu, GTK_BUTTON (button));
  
      filter = GTK_RADIO_BUTTON (hildon_gtk_radio_button_new (button_size, NULL));
      gtk_button_set_label (GTK_BUTTON (filter), "Indentation: Spaces");
      hildon_app_menu_add_filter (menu, GTK_BUTTON (filter));
      gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (filter), FALSE);
  
      button = GTK_BUTTON (hildon_gtk_button_new (button_size));
      gtk_button_set_label (button, "Help");
      g_signal_connect (G_OBJECT (button), "clicked",
                        G_CALLBACK (help_subview), NULL);
      hildon_app_menu_append (menu, GTK_BUTTON (button));
  
      filter = GTK_RADIO_BUTTON (hildon_gtk_radio_button_new_from_widget (button_size,
                                      GTK_RADIO_BUTTON (filter)));
      gtk_button_set_label (GTK_BUTTON (filter), "Indentation: Tabs");
      hildon_app_menu_add_filter (menu, GTK_BUTTON (filter));
      gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (filter), FALSE);
  
      return menu;
  }
  
  int
  main (int argc, char **argv)
  {
      hildon_gtk_init (&argc, &argv);
  
      GtkWidget *window;
      window = hildon_stackable_window_new ();
      gtk_window_set_title (GTK_WINDOW (window), "Editor");
  
      HildonAppMenu *menu = build_menu ();
      hildon_stackable_window_set_main_menu (HILDON_STACKABLE_WINDOW (window), menu);
  
      GtkWidget *contents = gtk_label_new ("This example shows how an app menu could be "
                                           "divided.\nMenus that would open new dialogs "
                                           "are not assigned any action.");
      gtk_container_add (GTK_CONTAINER (window), contents);
  
      /* ... other widgets in the application */
  
      g_signal_connect (G_OBJECT (window), "destroy",
                        G_CALLBACK (gtk_main_quit), NULL);
  
      gtk_widget_show_all (window);
  
      gtk_main ();
      return 0;
  }
  
              
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

.. code-block:: python

  
  
  #include <hildon/hildon.h>
  
  int
  main (int argc, char **argv)
  {
      hildon_gtk_init (&argc, &argv);
  
      GtkWidget *window;
  
      window = hildon_window_new ();
      gtk_window_set_title (GTK_WINDOW (window), "Preferences");
      g_signal_connect (G_OBJECT (window), "destroy",
                        G_CALLBACK (gtk_main_quit), NULL);
  
      HildonPickerButton *picker = HILDON_PICKER_BUTTON (hildon_picker_button_new (
                              HILDON_SIZE_THUMB_HEIGHT | HILDON_SIZE_HALFSCREEN_WIDTH,
                                                  HILDON_BUTTON_ARRANGEMENT_VERTICAL));
      hildon_button_set_title (HILDON_BUTTON (picker), "Proxy preferences:");
  
      HildonTouchSelector *selector = HILDON_TOUCH_SELECTOR (hildon_touch_selector_new_text ());
      hildon_picker_button_set_selector (picker, selector);
      hildon_touch_selector_append_text (selector, "None");
      hildon_touch_selector_append_text (selector, "Auto");
      hildon_touch_selector_append_text (selector, "Manual");
      hildon_picker_button_set_active (picker, 0);
  
      GtkVBox *contents = GTK_VBOX (gtk_vbox_new (12, FALSE));
      /* ... other widgets placed here */
      gtk_box_pack_end (GTK_BOX (contents), GTK_WIDGET (picker), FALSE, FALSE, 0);
  
      gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (contents));
  
      gtk_widget_show_all (window);
  
      gtk_main ();
      return 0;
  }
  
              
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

.. code-block:: python

  
  
  #include <hildon/hildon.h>
  
  static HildonStackableWindow *
  new_preferences_window (gchar *title)
  {
      HildonStackableWindow *pref_window;
      pref_window = HILDON_STACKABLE_WINDOW (hildon_stackable_window_new ());
      gtk_window_set_title (GTK_WINDOW (pref_window), title);
      GtkWidget *content = gtk_label_new (g_strdup_printf ("Set the %s Preferences", title));
      gtk_widget_show (content);
      gtk_container_add (GTK_CONTAINER (pref_window), content);
      return pref_window;
  }
  
  static void
  button_clicked_cb (GtkWidget *button, gchar *title)
  {
      HildonStackableWindow *sw = new_preferences_window (title);
      gtk_widget_show_all (GTK_WIDGET (sw));
  }
  
  int
  main (int argc, char **argv)
  {
      hildon_gtk_init (&argc, &argv);
  
      GtkWidget *window;
      GtkButton *general_pref_button, *colors_pref_button, *tools_pref_button;
  
      window = hildon_stackable_window_new ();
      gtk_window_set_title (GTK_WINDOW (window), "Preferences");
  
      general_pref_button = GTK_BUTTON (hildon_gtk_button_new (HILDON_SIZE_AUTO_HEIGHT));
      gtk_button_set_label (general_pref_button, "General");
      g_signal_connect (general_pref_button, "clicked",
                          G_CALLBACK (button_clicked_cb), "General");
  
      colors_pref_button = GTK_BUTTON (hildon_gtk_button_new (HILDON_SIZE_AUTO_HEIGHT));
      gtk_button_set_label (colors_pref_button, "Colors");
      g_signal_connect (colors_pref_button, "clicked",
                          G_CALLBACK (button_clicked_cb), "Colors");
  
      tools_pref_button = GTK_BUTTON (hildon_gtk_button_new (HILDON_SIZE_AUTO_HEIGHT));
      gtk_button_set_label (tools_pref_button, "Tools");
      g_signal_connect (tools_pref_button, "clicked",
                          G_CALLBACK (button_clicked_cb), "Tools");
  
      GtkVBox *contents = GTK_VBOX (gtk_vbox_new (TRUE, 12));
      gtk_container_add (GTK_CONTAINER (contents), GTK_WIDGET (general_pref_button));
      gtk_container_add (GTK_CONTAINER (contents), GTK_WIDGET (colors_pref_button));
      gtk_container_add (GTK_CONTAINER (contents), GTK_WIDGET (tools_pref_button));
  
      gtk_container_add (GTK_CONTAINER (window), GTK_WIDGET (contents));
  
      g_signal_connect (G_OBJECT (window), "destroy",
                        G_CALLBACK (gtk_main_quit), NULL);
  
      gtk_widget_show_all (window);
  
      gtk_main ();
  
      return 0;
  }
  
              

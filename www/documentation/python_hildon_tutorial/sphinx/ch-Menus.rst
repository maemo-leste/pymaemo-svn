.. _ch-Menus:

Menus
#####

The use of menus in Hildon applications follows a very different approach from the traditional application menus.

There is no menu bar, each window has a menu attached which is activated when the user presses the title area of the window. And, secondly, unlike typical menus in desktop applications, view menus do not follow a hierarchical structure. This menu, attached to a view, is called Touch View Menu.

Additionally Hildon provides Context menus, although those should be avoided when possible.

This chapter will review this two types of menus.

Touch View Menu
***************

The widget which should be used as a menu in the windows of a Hildon application is HildonAppmenu.

This widget opens from the top of the screen, obscuring the topmost window, and contains a number of entries organized in one or two columns, depending on the screen orientation. Besides entries, application menus can also contain a group of filter buttons.

The entries are GtkButtons. You should assign the proper action to the each menu item for when they are activated.

Filters are toggle buttons that can be used for presentation/sorting purposes. For example, sorting alphabetically a list of contacts or changing the size of icons in a list.

To create a HildonAppMenu you can use:

::

  
  
  GtkWidget*  hildon_app_menu_new             (void);
  
      
Once the application menu is created you can add entries to the menu by using the following functions:

::

  
  
  void        hildon_app_menu_append          (HildonAppMenu *menu,
                                               GtkButton *item);
  void        hildon_app_menu_prepend         (HildonAppMenu *menu,
                                               GtkButton *item);
  void        hildon_app_menu_insert          (HildonAppMenu *menu,
                                               GtkButton *item,
                                               gint position);
  
      
These functions allow you to append, prepend an entry or add it in a certain position (from 0 to N-1, where N is the number of menus).

It is important keep the UI simple, so you should try to keep the menu as small as possible, avoiding to add unnecessary options. An application menu with more that 10 items will probably not be well displayed.

To add filter buttons you can use:

::

  
  
  void        hildon_app_menu_add_filter      (HildonAppMenu *menu,
                                               GtkButton *filter);
  
      
Again, you should be careful with the number of filters that you add to the application menu. More than 4 might not be well displayed, even less, depending on the length of the labels. Filters should be grouped and act as radio buttons, that is, for any filter, there should be at least another filter with a different/opposite action. Actually, GtkRadioButtons can be easily used to accomplish this by having them grouped (using gtk_radio_button_new_from_widget() like the next example shows) and by not drawing their indicator -- with the function gtk_toggle_button_set_mode().

Once the menu is properly created and filled up with entries and filters you can add the menu to a HildonWindow. You can use the following functions to set and retrieve a window's menu, respectively:

::

  
  
  void        hildon_window_set_app_menu      (HildonWindow *self,
                                               HildonAppMenu *menu);
  HildonAppMenu* hildon_window_get_app_menu   (HildonWindow *self);
  
      
The following example shows how to create and set up an application menu.

Example of a Hildon application menu
====================================

.. code-block:: python

  
  
  #include                                        <hildon/hildon.h>
  
  static void
  menu_button_clicked                             (GtkButton *button,
                                                   GtkLabel *label)
  {
    const char *buttontext = gtk_button_get_label (button);
    char *text = g_strdup_printf("Last option selected:\n%s", buttontext);
    gtk_label_set_text (label, text);
    g_free (text);
    g_debug ("Button clicked: %s", buttontext);
  }
  
  
  static HildonAppMenu *
  create_menu                                     (GtkWidget     *label)
  {
    int i;
    gchar *command_id;
    GtkWidget * button;
    HildonAppMenu *menu = HILDON_APP_MENU (hildon_app_menu_new ());
  
    for (i = 1; i < 6; i++) {
      /* Create menu entries */
      button = hildon_gtk_button_new (HILDON_SIZE_AUTO);
      command_id = g_strdup_printf ("Menu command %d", i);
      gtk_button_set_label (GTK_BUTTON (button), command_id);
  
      /* Attach callback to clicked signal */
      g_signal_connect_after (button, "clicked",
                              G_CALLBACK (menu_button_clicked),
                              label);
  
      /* Add entry to the view menu */
      hildon_app_menu_append (menu, GTK_BUTTON (button));
    }
  
    /* Create filters */
    button = hildon_gtk_radio_button_new (HILDON_SIZE_AUTO, NULL);
    gtk_button_set_label (GTK_BUTTON (button), "filter one");
    g_signal_connect_after (button, "clicked", G_CALLBACK (menu_button_clicked), label);
    hildon_app_menu_add_filter (menu, GTK_BUTTON (button));
    gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (button), FALSE);
  
    button = hildon_gtk_radio_button_new_from_widget (HILDON_SIZE_AUTO,
                                                      GTK_RADIO_BUTTON (button));
    gtk_button_set_label (GTK_BUTTON (button), "filter two");
    g_signal_connect_after (button, "clicked", G_CALLBACK (menu_button_clicked), label);
    hildon_app_menu_add_filter (menu, GTK_BUTTON (button));
    gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (button), FALSE);
  
    gtk_widget_show_all (GTK_WIDGET (menu));
  
    return menu;
  }
  
  int
  main                                            (int argc,
                                                   char **argv)
  {
    GtkWidget *win;
    GtkWidget *label;
    GtkWidget *label2;
    GtkBox *vbox;
    HildonAppMenu *menu;
  
    hildon_gtk_init (&argc, &argv);
  
    win = hildon_stackable_window_new ();
  
    /* Create and pack labels */
    label = gtk_label_new ("This is an example of the\nHildonAppMenu widget.\n\n"
                           "Click on the titlebar\nto pop up the menu.");
    label2 = gtk_label_new ("No menu option has been selected yet.");
  
    gtk_label_set_justify (GTK_LABEL (label), GTK_JUSTIFY_CENTER);
    gtk_label_set_justify (GTK_LABEL (label2), GTK_JUSTIFY_CENTER);
  
    vbox = GTK_BOX (gtk_vbox_new (FALSE, 10));
  
    gtk_box_pack_start (vbox, label, TRUE, TRUE, 0);
    gtk_box_pack_start (vbox, label2, TRUE, TRUE, 0);
  
    /* Create menu */
    menu = create_menu (label2);
  
    /* Attach menu to the window */
    hildon_window_set_app_menu (HILDON_WINDOW (win), menu);
  
    /* Add label's box to window */
    gtk_container_add (GTK_CONTAINER (win), GTK_WIDGET (vbox));
  
    g_signal_connect (win, "delete_event", G_CALLBACK (gtk_main_quit), NULL);
  
    gtk_widget_show_all (win);
  
    gtk_main ();
  
    return 0;
  }
  
        
Each entry and filter button in this example is attached to a function that simply changes a label in the main window.

Note that the function used to attach handlers to the entries is g_signal_connect_after(). So the handler will be called after the default handler of the signal "clicked". The default handler for entries and filters closes the menu.

Application Menus and Views
***************************

In the previous example there is only one view, but in applications with several views you can attach a different menu to each view, adding only options relevant to the displayed view.

The function hildon_window_set_app_menu() allows to set a menu to an HildonWindow and its descendant HildonStackableWindow widget.

::

  
  
  hildon_window_set_app_menu (HILDON_STACKABLE_WINDOW (win), menu);
  
      
Note that submenus are not supported by view menus. Usually, a menu item that in a desktop application would have suboptions implies a new subview in a Hildon application.

A callback function for a complex menu entry could create a new HildonStackableWindow to accomplish the task that the option refers to. The new window could have a different view menu attached that holds buttons to perform the action or even have the buttons on the window's area should it make more sense.

Context Menu
************

Context menu is usually invoked via long press over an item on the screen, like holding a finger over an image thumbnail. The menu should contain commands directly related to the chosen item.

The use of context menus should be avoided since it is a hidden and inconvenient way of interacting with the UI. HildonAppMenus should be used instead, when possible.



To create a GtkMenu in a Hildon application you should use the following function instead of gtk_menu_new():

::

  
  
  GtkWidget*  hildon_gtk_menu_new             (void);
  
      
This function creates a GtkMenu that allows Hildon specific styling.

When you use a GtkMenu in your Hildon application you should carefully select the number of menu items because it is limited to what fits on the screen at once. Besides that, take into account that submenus are not allowed in order to keep a clear and simple UI.


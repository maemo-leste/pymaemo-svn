.. _ch-Packing:

Navigation
##########

In previous examples only one widget was added to a window so we could simply use a gtk_container_add() to "pack" it into the window. To pack more than one widget into a window it is necessary to use container widgets.

To develop Hildon user interfaces, you can use any container widget provided by GTK+. For more details, `GTK+ 2.0 Tutorial <GTK+ 2.0 Tutorial>`_ includes a good introduction to this topic.

Apart from supporting those containers, the Hildon framework also provides a new container widget called HildonPannableArea, a scrolling widget designed for touch screens. This chapter will cover all that is necessary to properly use this widget.

Pannable Area
*************

HildonPannableArea is used to create an area with another widget inside which will be accessible regardless of the size using the touchscreen to scroll it. You may insert any type of widget into a pannable area, and it will be accessible by dragging on the area with the fingers.

This widget can be "panned" (scrolled) in any direction using the touchscreen with the fingers. One remarkable characteristic is that the scrolling is "kinetic", meaning that the motion will continue from the initial motion by gradually slowing down to stop.

The use of this widget is very similar to GTK+ scrolled windows. In fact, both widgets implement a similar concept and its APIs are very similar.

To create a new pannable area you can choose either of the following functions:

::

  
        
  GtkWidget*  hildon_pannable_area_new        (void);
  GtkWidget*  hildon_pannable_area_new_full   (gint mode,
                                               gboolean enabled,
                                               gdouble vel_min,
                                               gdouble vel_max,
                                               gdouble decel,
                                               guint sps);
        
      
The first one creates a new pannable area with the properties set to the default values. The second one allows you to set the value of the most important properties of this widget:

* mode : Used to change the behaviour of the pannable area allowing to choose whether to use the "kinetic" effect described above.
* enabled : Enable or disable finger-scroll.
* vel_min, vel_max : Allows developers to adjust how many pixels the child widget will be move per "frame".
* decel : Value for the deceleration property.
* sps : Amount of scroll events to generate per second.

For most applications, default values of these properties will be right and thus, the simpler constructor will be enough. In the Hildon reference manual you can read more about all pannable area's properties.

Once the area is created you can then place your object into the pannable window using the following function.

::

  
        
  void        hildon_pannable_area_add_with_viewport (HildonPannableArea *area,
                                                      GtkWidget *child);
        
      
That is a convenience function used to add a child to a GtkViewport, and add the viewport to the pannable area.

.. warning:: Widgets that have native scrolling should be added directly inside a pannable area. For example, widgets such as GtkTextView, GtkTreeView, GtkIconView and GtkLayout should be added by calling gtk_container_add(). Otherwise, panning could not work properly.

Pannable area example
*********************

Functions explained above are enough for a simple example. The following example packs a table with 100 toggle buttons into a pannable area.

Example of a pannable area
==========================

.. code-block:: python

  
  
  #include <stdio.h>
  #include <hildon/hildon.h>
  
  static GtkWidget *create_table ()
  {
  
    GtkWidget *hbox;
    GtkWidget *table;
    GtkWidget *button;
    char buffer[32];
    int i, j;
  
    /* create a table of 10 by 10 squares. */
    table = gtk_table_new (10, 10, FALSE);
  
    /* set the spacing to 10 on x and 10 on y */
    gtk_table_set_row_spacings (GTK_TABLE (table), 10);
    gtk_table_set_col_spacings (GTK_TABLE (table), 10);
  
    gtk_widget_show (table);
  
    /* this simply creates a grid of toggle buttons on the table
     * to demonstrate the scrolled window. */
    for (i = 1; i < 10; i++)
      for (j = 1; j < 10; j++) {
        sprintf (buffer, "button (%d,%d)\n", i, j);
        button = gtk_toggle_button_new_with_label (buffer);
  
        gtk_table_attach_defaults (GTK_TABLE (table), button,
                                   i, i+1, j, j+1);
      }
  
    return table;
  }
  
  int main( int   argc,
            char *argv[] )
  {
    static GtkWidget *window;
    GtkWidget *button;
    GtkWidget *pannable_area;
    GtkWidget *table;
  
    hildon_gtk_init (&argc, &argv);
  
    window = hildon_stackable_window_new ();
    g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (gtk_widget_destroy), NULL);
  
    pannable_area = hildon_pannable_area_new ();
  
    table = create_table ();
  
    /* pack the table into the scrolled window */
    hildon_pannable_area_add_with_viewport (
      HILDON_PANNABLE_AREA (pannable_area), table);
  
    /* Add the box into the window*/
    gtk_container_add (GTK_CONTAINER (window), pannable_area);
  
    gtk_widget_show_all (window);
  
    gtk_main ();
  
    return 0;
  }
  
      
In the example above you can see that the following two calls are enough to use a pannable area. The rest of the code of the example is no different to that used in a GTK+ application.

.. code-block:: python

  
  
    /* Create a new pannable area. */
    pannable_area = hildon_pannable_area_new ();
    /* Pack the table into the pannable area */
    hildon_pannable_area_add_with_viewport ( HILDON_PANNABLE_AREA (pannable_area), table);
  
          
To see all the buttons, users can scroll with the fingers. In this example, horizontal and vertical panning are activated as that is needed to allow users to be able to interact both all the widgets. The property "mov-mode" controls if the area can scroll horizontally, vertically (default value) or both, using HILDON_MOVEMENT_MODE_HORIZ, HILDON_MOVEMENT_MODE_VERT or HILDON_MOVEMENT_MODE_BOTH, respectively.

Additional features
*******************

Pannable areas provide a set of convenience functions that make it easier to move to a certain element inside the area without users interaction.

These functions allow to scroll or jump to a position which ensures that a certain point or a certain child widget is visible for the user.

For example, the first of the functions changes the current position on the pannable area to ensure position (x,y) is visible. The movement is a quick jump. The second function performs a smoothly scroll towards the selected position.

::

  
  
  void        hildon_pannable_area_jump_to    (HildonPannableArea *area,
                                               const gint x,
                                               const gint y);
  
  void        hildon_pannable_area_scroll_to  (HildonPannableArea *area,
                                               const gint x,
                                               const gint y);
  
      
It is also possible to jump or scroll to a certain descendent of the area using the following functions, the argument should be a reference to a descendent widget.

::

  
  
  void        hildon_pannable_area_jump_to_child (HildonPannableArea *area,
                                                  GtkWidget *child);
  
  void        hildon_pannable_area_scroll_to_child
                                              (HildonPannableArea *area,
                                               GtkWidget *child);
  
      
Here is a modified version of the previous example. The pannable area is packed into an GtkVBox and a new button is also added to navigate to the last clicked button.

Example of a pannable area and a "jump-to" button
=================================================

.. code-block:: python

  
  
  #include <stdio.h>
  #include <hildon/hildon.h>
  
  /* Pointer to the last clicked button*/
  GtkWidget *last_clicked_button;
  
  /* Callabck to set last clicked button */
  static void clicked (GtkButton *button,
                       gpointer   user_data)
  {
    last_clicked_button = GTK_WIDGET (button);
  }
  
  static void go_to_last_clicked (GtkButton *button,
                                  gpointer   user_data)
  {
    hildon_pannable_area_scroll_to_child (HILDON_PANNABLE_AREA (pannable_area),
                                          last_clicked_button);
  
  }
  
  static GtkWidget *create_table ()
  {
  
    GtkWidget *hbox;
    GtkWidget *table;
    GtkWidget *button;
    char buffer[32];
    int i, j;
  
    /* create a table of 10 by 10 squares. */
    table = gtk_table_new (10, 10, FALSE);
  
    /* set the spacing to 10 on x and 10 on y */
    gtk_table_set_row_spacings (GTK_TABLE (table), 10);
    gtk_table_set_col_spacings (GTK_TABLE (table), 10);
  
    gtk_widget_show (table);
  
    /* this simply creates a grid of toggle buttons on the table
     * to demonstrate the scrolled window. */
    for (i = 1; i < 10; i++)
      for (j = 1; j < 10; j++) {
        sprintf (buffer, "button (%d,%d)\n", i, j);
        button = gtk_toggle_button_new_with_label (buffer);
  
        /* Attach function cliecked to "clicked" signal of eeach button*/
        g_signal_connect (G_OBJECT (button),
                          "clicked",
                          G_CALLBACK (clicked),
                          NULL);
  
        gtk_table_attach_defaults (GTK_TABLE (table), button,
                                   i, i+1, j, j+1);
      }
  
    return table;
  }
  
  int main( int   argc,
            char *argv[] )
  {
    static GtkWidget *window;
    GtkWidget *button;
    GtkWidget *pannable_area;
    GtkWidget *vbox;
    GtkWidget *table;
  
    gtk_init (&argc, &argv);
  
    window = hildon_stackable_window_new ();
    g_signal_connect (G_OBJECT (window), "destroy",
                      G_CALLBACK (gtk_widget_destroy), NULL);
  
    pannable_area = hildon_pannable_area_new ();
    g_object_set (G_OBJECT (pannable_area),
                  "mov-mode", HILDON_MOVEMENT_MODE_BOTH );
  
    button = gtk_button_new_with_label ("Go to last clicked button");
    g_signal_connect (G_OBJECT (button),
                      "clicked",
                      G_CALLBACK (go_to_last_clicked),
                      NULL);
  
    table = create_table ();
  
    /* pack the table into the scrolled window */
    hildon_pannable_area_add_with_viewport (
      HILDON_PANNABLE_AREA (pannable_area), table);
  
  
    /* Create a box and pack the widgets into it */
    vbox = gtk_vbox_new (FALSE,0);
  
    gtk_container_add (GTK_CONTAINER (pannable_area), table);
  
    gtk_box_pack_start (GTK_BOX (vbox),
                        button,
                        FALSE,
                        FALSE,
                        0);
  
    gtk_box_pack_start (GTK_BOX (vbox),
                        pannable_area,
                        TRUE,
                        TRUE,
                        0);
  
    /* Add the box into the window*/
    gtk_container_add (GTK_CONTAINER (window), vbox);
  
    gtk_widget_show_all (window);
  
    gtk_main ();
  
    return 0;
  }
  
          
The example used a global variable to store a reference to the last clicked button. This reference will be used by the callback go_to_last_clicked to jump to it by calling one of the navigation functions. This is the function used as a handler for the signal "clicked" of the button outside the pannable area.

You can test the different navigation functions by just changing the call in the mentioned callback.

When you use the navigation functions that allow to navigate to a certain child, the widget must be already realized. You can check it with the GTK_WIDGET_REALIZED macro. If you want to call it during the initialization process you can use the navigation function inside a callback to the "realized" signal, connecting it using g_signal_connect_after().


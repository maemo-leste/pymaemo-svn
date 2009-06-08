.. _desktop-plugins:

Writing Desktop Widgets
#######################

Desktop widgets are programs designed to provide a certain functionality from the desktop area. These programs are usually limited, in the sense that they are not complex applications, normally representing "small" utilities or an extension of an existing application.

Desktop widgets are written as shared libraries and need also to provide a desktop file that describes them. According to where they'll be placed there can be Status Menu widgets and Home Area widgets.

Applets need to have a .desktop file describing them. The file contents are fields that describe certain properties of the applet.

.. _desktop-plugins-home-plugins:

Home widgets
************

Home widgets are located in the Home Area of the desktop. Since Hildon 2.2, Home Area applets stopped being resizable.

To better show how to write a Home Area applet, consider an applet "TimeOut" that allows the user to choose an action to be performed at a given time.

Home pug-ins should inherit from libhildondesktop's HDHomePluginItem. The following example presents a header file for the mentioned applet.

Header file for TimeOut applet: lib-timeout-home-applet.h
=========================================================

.. code-block:: python

  
  
  #ifndef TIME_OUT_PLUGIN_H
  #define TIME_OUT_PLUGIN_H
  
  #include <glib-object.h>
  
  #include <libhildondesktop/hildondesktop.h>
  
  G_BEGIN_DECLS
  
  typedef struct _TimeOutPlugin TimeOutPlugin;
  typedef struct _TimeOutPluginClass TimeOutPluginClass;
  
  #define TIME_OUT_TYPE_HOME_PLUGIN (time_out_home_plugin_get_type ())
  
  #define TIME_OUT_HOME_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
                          TIME_OUT_TYPE_HOME_PLUGIN, TimeOutHomePlugin))
  
  #define TIME_OUT_HOME_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), \
                          TIME_OUT_TYPE_HOME_PLUGIN, TimeOutHomePluginClass))
  
  #define TIME_OUT_IS_HOME_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
                          TIME_OUT_TYPE_HOME_PLUGIN))
  
  #define TIME_OUT_IS_HOME_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), \
                          TIME_OUT_TYPE_HOME_PLUGIN))
  
  #define TIME_OUT_HOME_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), \
                          TIME_OUT_TYPE_HOME_PLUGIN, TimeOutHomePluginClass))
  
  struct _TimeOutPlugin
  {
      HDHomePluginItem hitem;
  };
  
  struct _TimeOutPluginClass
  {
      HDHomePluginItemClass parent_class;
  };
  
  GType time_out_home_plugin_get_type(void);
  
  G_END_DECLS
  
  #endif
  
              
The first and more important function is ``HD_DEFINE_PLUGIN_MODULE``. This function receives three parameters to register the object that is supplied by the plug-in. The first argument should be the object type name in Camel case, the second is the type name in lowercase with underscores separating the words. The third is the GType of the object's parent. Apart from this macro, three other functions should be used. The name of the functions should be the name given as second argument to ``HD_DEFINE_PLUGIN_MODULE`` with the suffixes _init, _class_init and _class_finalize.

The following example shows the source code for "TimeOut" applet.

Source file for TimeOut applet: lib-timeout-home-applet.c
=========================================================

.. code-block:: python

  
  
  #include <gtk/gtk.h>
  #include <hildon/hildon.h>
  
  #include <libhildondesktop/libhildondesktop.h>
  
  #include "lib-timeout-home-applet.h"
  
  HD_DEFINE_PLUGIN_MODULE (TimeOutPlugin, time_out_plugin, HD_TYPE_HOME_PLUGIN_ITEM)
  
  static GtkWidget *
  build_ui (void)
  {
      GtkVBox *contents = GTK_VBOX (gtk_vbox_new (0, FALSE));
      GtkLabel *label = GTK_LABEL (gtk_label_new ("Time out applet."));
      HildonPickerButton *action;
      action = HILDON_PICKER_BUTTON (hildon_picker_button_new (HILDON_SIZE_FINGER_HEIGHT,
                                          HILDON_BUTTON_ARRANGEMENT_VERTICAL));
      HildonTouchSelector *action_selector;
      action_selector = HILDON_TOUCH_SELECTOR (hildon_touch_selector_new_text ());
      hildon_button_set_title (HILDON_BUTTON (action), "Action");
      hildon_touch_selector_append_text (action_selector, "Blank Screen");
      hildon_touch_selector_append_text (action_selector, "Suspend");
      hildon_touch_selector_append_text (action_selector, "Turn Off");
      hildon_picker_button_set_selector (action, action_selector);
      hildon_picker_button_set_active (action, 0);
  
      HildonTimeButton *time;
      time = HILDON_TIME_BUTTON (hildon_time_button_new (HILDON_SIZE_FINGER_HEIGHT,
                                          HILDON_BUTTON_ARRANGEMENT_VERTICAL));
      hildon_time_button_set_time (time, 22, 00);
  
      GtkHBox *buttons = GTK_HBOX (gtk_hbox_new (0, TRUE));
      gtk_container_add (GTK_CONTAINER (buttons), GTK_WIDGET (action));
      gtk_container_add (GTK_CONTAINER (buttons), GTK_WIDGET (time));
      
      gtk_box_pack_start (GTK_BOX (contents), GTK_WIDGET (label), FALSE, FALSE, 0);
      gtk_box_pack_end (GTK_BOX (contents), GTK_WIDGET (buttons), FALSE, FALSE, 0);
      gtk_widget_show_all (GTK_WIDGET (contents));
  
      return GTK_WIDGET (contents);
  }
  
  static void
  time_out_plugin_init (TimeOutPlugin *desktop_plugin)
  {
    GtkWidget *contents = build_ui ();
    gtk_container_add (GTK_CONTAINER (desktop_plugin), contents);
  }
  
  static void
  time_out_plugin_class_init (TimeOutPluginClass *class) {}
  
  static void
  time_out_plugin_class_finalize (TimeOutPluginClass *class) {}
  
              
As you can see in the example above, the controls used in the applet (``build_ui`` function) should be added to "TimeOutPlugin". In this case, the applet works as a standalone application but it could just provide a widget to activate a program defined in another header and independent from the applet.

.. _desktop-applets-desktop-file:

The .desktop File
=================

Although other fields can be assigned in a .desktop file, the example bellow shows a simple .desktop file for the "TimeOut" applet. The "Name" field will be the applet's name in the list when the user is choosing applets to add to the desktop. The "X-Path" field should be set to the .so file that was previously generated.

A .desktop file for the TimeOut applet: timeout-applet.desktop
==============================================================

.. code-block:: python

  
  
  [Desktop Entry]
  Name=TimeOut Applet
  Comment=Execute an action at a given time
  Type=default
  X-Path=lib-timeout-home-applet.so
  
                  
For Home Area applets, .desktop files should be placed in the directory outputed by the following command:

::

  
  
  pkg-config libhildondesktop-1 --variable=hildonhomedesktopentrydir --variable=homedesktopentrydir
  
              
.. _desktop-plugins-status-menu:

Status Menu widgets
*******************

Status Menu widgets are placed in the Status Menu and can be divided into three categories: permanent, conditional and temporary. Permanent widgets are shown all the time. Conditional and temporary widgets are shown when a certain condition is fulfilled.

The way to write a plug-in for the Status Menu is pretty similar to writing it for the Home Area. The plug-in should inherit from HDStatusMenuItem. The next examples present a Status Menu plug-in which only shows a message when clicked.

Header file for Example Status Menu Plug-in: lib-example-status-menu-applet.h
=============================================================================

.. code-block:: python

  
  
  #ifndef __EXAMPLE_STATUS_PLUGIN_H__
  #define __EXAMPLE_STATUS_PLUGIN_H__
  
  #include <libhildondesktop/libhildondesktop.h>
  
  G_BEGIN_DECLS
  
  #define TYPE_EXAMPLE_STATUS_PLUGIN            (example_status_plugin_get_type ())
  
  #define EXAMPLE_STATUS_PLUGIN(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
                                      TYPE_EXAMPLE_STATUS_PLUGIN, ExampleStatusPlugin))
  
  #define EXAMPLE_STATUS_PLUGIN_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), \
                                  TYPE_EXAMPLE_STATUS_PLUGIN, ExampleStatusPluginClass))
  
  #define IS_EXAMPLE_STATUS_PLUGIN(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
                                                      TYPE_EXAMPLE_STATUS_PLUGIN))
  
  #define IS_EXAMPLE_STATUS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), \
                                                      TYPE_EXAMPLE_STATUS_PLUGIN))
  
  #define EXAMPLE_STATUS_PLUGIN_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
                              TYPE_EXAMPLE_STATUS_PLUGIN, ExampleStatusPluginClass))
  
  #define STATUS_AREA_EXAMPLE_ICON_SIZE 22
  
  typedef struct _ExampleStatusPlugin        ExampleStatusPlugin;
  typedef struct _ExampleStatusPluginClass   ExampleStatusPluginClass;
  typedef struct _ExampleStatusPluginPrivate ExampleStatusPluginPrivate;
  
  struct _ExampleStatusPlugin
  {
      HDStatusMenuItem parent;
  
      ExampleStatusPluginPrivate *priv;
  };
  
  struct _ExampleStatusPluginClass
  {
      HDStatusMenuItemClass parent;
  };
  
  GType example_status_plugin_get_type (void);
  
  G_END_DECLS
  
  #endif
  
              
Source file for Example Status Menu Plug-in: lib-example-status-menu-applet.c
=============================================================================

.. code-block:: python

  
  
  #include <stdio.h>
  #include <stdlib.h>
  #include <gtk/gtk.h>
  #include <hildon/hildon.h>
  
  #include "lib-example-status-menu-applet.h"
  
  #define EXAMPLE_STATUS_PLUGIN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE (obj, \
                              TYPE_EXAMPLE_STATUS_PLUGIN, ExampleStatusPluginPrivate))
  
  struct _ExampleStatusPluginPrivate
  {
      GtkWidget *label;
      gpointer data;
  };
  
  HD_DEFINE_PLUGIN_MODULE (ExampleStatusPlugin, example_status_plugin, HD_TYPE_STATUS_MENU_ITEM);
  
  static void
  example_status_plugin_class_finalize (ExampleStatusPluginClass *klass) {}
  
  static void
  example_status_plugin_class_init (ExampleStatusPluginClass *klass)
  {
      g_type_class_add_private (klass, sizeof (ExampleStatusPluginPrivate));
  }
  
  static void
  example_status_plugin_init (ExampleStatusPlugin *plugin)
  {
      plugin->priv = EXAMPLE_STATUS_PLUGIN_GET_PRIVATE (plugin);
  
      GtkIconTheme *icon_theme = gtk_icon_theme_get_default ();
      GList *list = gtk_icon_theme_list_icons (icon_theme, NULL);
      GdkPixbuf *pixbuf = gtk_icon_theme_load_icon (icon_theme, "general_email",
                      STATUS_AREA_EXAMPLE_ICON_SIZE, GTK_ICON_LOOKUP_NO_SVG, NULL);
      hd_status_plugin_item_set_status_area_icon (HD_STATUS_PLUGIN_ITEM (plugin), pixbuf);
      g_object_unref (pixbuf);
  
      GtkWidget *b = gtk_label_new ("Example message");
      gtk_widget_show_all (b);
  
      plugin->priv->label = b;
  
      gtk_container_add (GTK_CONTAINER (plugin), plugin->priv->label);
  
      gtk_widget_show_all (plugin->priv->label);
  
      gtk_widget_show (GTK_WIDGET (plugin));
  }
  
              
.. _desktop-applets-status-menu-desktop-file:

The .desktop File
=================

The .desktop file for the Status Menu is analogous to the Home Area one but should have also the "Category" field where the priority of the applet is set (permanent, conditional or temporary) and the "Icon" field to set the icon's name. If the "Category" key is not set, then it is considered as permanent.

A .desktop file for the Status Menu example applet: lib-example-applet.desktop
==============================================================================

.. code-block:: python

  
  
  [Desktop Entry]
  Name=Example
  Icon=general_email
  Comment=An example status menu applet
  Category=permanent
  Type=default
  X-Path=lib-example-status-menu-applet.so
  
                  
For Home Area applets, .desktop files should be placed in the directory outputed by the following command:

::

  
  
  pkg-config libhildondesktop-1 --variable=homedesktopentrydir
  
              
.. _desktop-applets-buildin-applets:

Building Applets
****************

To use an applet, it needs to be built as a shared library. This is done by passing the -shared flag to gcc.

::

  
  
  gcc -shared `pkg-config hildon-1 libhildondesktop-1 --libs --cflags`
  applet.c -o lib-applet.so
  
          
Status Menu and Home Area applets binaries should be placed in the same directory, so, assign distinguishable names to them. For example, "lib-example-home-applet.so" and "lib-example-status-menu-applet.so" for the Home Area and Status Menu applets, respectively. The directory where the binary files should be copied to is given by the following command (which normally outputs "/usr/share/applications/hildon-desktop"):

::

  
  
  pkg-config libhildondesktop-1 --variable=hildondesktoplibdir
  
          

.. _ch-GtkAdditions:

Additions to GTK+
#################

A Hildon application might use any Gtk widget but in some cases could be needed to adapt those widgets to get that they fit perfectly.

Hildon provides a set of convenience functions to do that. Next sections explains these addictions

Hildon Size Types
*****************

Hildon defines the following sizes to be used as sizes for widgets such as buttons or entries in your Hildon application.

``HILDON_SIZE_AUTO_WIDTH``
  set to automatic width


``HILDON_SIZE_HALFSCREEN_WIDTH``
  set to 50% screen width


``HILDON_SIZE_FULLSCREEN_WIDTH``
  set to 100% screen width


``HILDON_SIZE_AUTO_HEIGHT``
  set to automatic height


``HILDON_SIZE_FINGER_HEIGHT``
  set to finger height


``HILDON_SIZE_THUMB_HEIGHT``
  set to thumb height


``HILDON_SIZE_AUTO``
  set to automatic width and automatic height


Hildon widgets allows to set their sizes in their construction functions, but in case you want to set the size of a GTK+ widget, Hildon also provides functions to do that:

::

  
  
  GtkWidget*  hildon_gtk_button_new           (HildonSizeType size);
  GtkWidget*  hildon_gtk_toggle_button_new    (HildonSizeType size);
  GtkWidget*  hildon_gtk_radio_button_new     (HildonSizeType size,
                                               GSList *group);
  GtkWidget*  hildon_gtk_radio_button_new_from_widget
                                              (HildonSizeType size,
                                               GtkRadioButton *radio_group_member);
  
      
UI Modes
********

Hildon defines two modes in the UI that change the way user interacts with certain widgets. The main purpose of these modes is to enable direct manipulation of items, while still allowing user to select single or multiple items, when it is necessary. Thw following modes are supported:

Normal mode
  It is the default mode. In lists and grids, tapping on an item causes a direct action. In views, this direct action could open a new subview to perform a certain action with the item.


Edit mode
  Edit mode is used in views. The purpose of this mode is providing multiple selection functionality in list or grid and providing standard UI for editing single content item.


Hildon provides the following functions to set mode for a treeview or icon view.

::

  
  
  GtkWidget*  hildon_gtk_tree_view_new            (HildonUIMode mode);
  GtkWidget*  hildon_gtk_tree_view_new_with_model (HildonUIMode mode,
                                                   GtkTreeModel *model);
  void        hildon_gtk_tree_view_set_ui_mode    (GtkTreeView *treeview,
                                                   HildonUIMode mode);
  GtkWidget*  hildon_gtk_icon_view_new            (HildonUIMode mode);
  GtkWidget*  hildon_gtk_icon_view_new_with_model (HildonUIMode mode,
                                                   GtkTreeModel *model);
  void        hildon_gtk_icon_view_set_ui_mode    (GtkIconView *iconview,
                                                   HildonUIMode mode);
  
      
The enum HildonUIMode defines the following flags:

``HILDON_UI_MODE_NORMAL``


``HILDON_UI_MODE_EDIT``


When you use a list or grid in edit mode inside a window you should use a HildonEditToolbar to control the edition and set the window to fullscreen, building an Edit subview. To know more about edit views you can check chapter toolbars. In that chapter you can check an example of HildonToolbar which uses the concepts explained above.

Seek bars
*********

The seek bars are useful to select a value from a range of predetermined values by adjusting the slider with a finger. These seek bars could be horizontal or vertical and are implemented using GtkVScale and GtkHScale. Thus, you can use this GTK+ widget in your Hildon application as seek bar but you should use following creation function instead of the GTK ones:

::

  
  
  GtkWidget*  hildon_gtk_hscale_new           (void);
  GtkWidget*  hildon_gtk_vscale_new           (void);
  
      
Scales created by using these constructors has a hildonized behavior, meaning that when user tap or click in a point of the bar immediately jumps to the desired position.

Progress indicators
*******************

A convenience way to inform the user that a long-term task is being performed is to show a progress indicator icon in the window or dialog title.

Hildon provides the following function to show a progress icon. This function applies to HildonWindow and GtkDialog.

::

  
  
  void        hildon_gtk_window_set_progress_indicator (GtkWindow *window,
                                                        guint state);
  
      
The argument state should be 1 to show the indicator and 0 to hide it.

Here, a little example that sets a progress indicator in a GtkDialog.

Adding a progress indicator to a dialog
=======================================

.. code-block:: python

  
  
  #include <hildon/hildon.h>
  
  int main( int   argc,
            char *argv[] )
  {
    GtkWidget *dialog;
  
    hildon_gtk_init (&argc, &argv);
  
    dialog = gtk_dialog_new ();
  
    gtk_window_set_title (GTK_WINDOW (dialog),
                          "Performing a long task");
  
    gtk_widget_show  (dialog);
  
    hildon_gtk_window_set_progress_indicator (GTK_WINDOW (dialog),
                                              1);
  
    gtk_dialog_run (GTK_DIALOG (dialog));
  
    return 0;
  }
  
        
Additionally, if you consider that aditional text information should be give to the user you could use an informational banner.

Another convenience way to indicate to users that a long opearion is being performed is using the GtkProgressBar widget. This is the usual way in GTK+ applications and you can use them like you would use them in a GTK+ application. This widget is specially useful if you need to show the status of the operation.


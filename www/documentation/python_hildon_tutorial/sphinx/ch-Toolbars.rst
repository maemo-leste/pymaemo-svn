.. _ch-Toolbars:

Toolbars
########

Toolbars are usually used to group some number of widgets in order to simplify customization of their look and layout. Hildon framework provides two specialized toolbars: HildonFindToolbar and HildonEditToolbar that will be explained bellow. Apart from that you can also use GtkToolbars in your Hildon application.

Find Toolbars
*************

HildonFindToolbar is a toolbar that contains a search entry and a dropdown list with previously searched strings. An internal GtkListStore stores the items in the dropdown list. This list is a property of the widget called "list"

To create a HildonFindToolbar you can use:

::

  
  
  GtkWidget*  hildon_find_toolbar_new            (const gchar *label);
  GtkWidget*  hildon_find_toolbar_new_with_model (const gchar *label,
                                                  GtkListStore *model,
                                                  gint column);
  
      
In both functions the argument label will be used as label which be displayed as label for the dropdown box.

The second function above allows to set the model which will be used to store the dropdown box. It is also necessary to indicate which column the search will retrieve the string from.

If the toolbar is created by using the first function, it will be necessary to manually set up the properties "list" and "column".

This widget provides the following function f for set and retrieve the index in the model of the current active item on the combo. An index -1 indicates no active items in both functions.

::

  
  
  void        hildon_find_toolbar_set_active  (HildonFindToolbar *toolbar,
                                               gint index);
  gint        hildon_find_toolbar_get_active  (HildonFindToolbar *toolbar);
  
      
To get the index of the most recently added item in the toolbar you can use the following function.

::

  
  
  gint32      hildon_find_toolbar_get_last_index (HildonFindToolbar *toolbar);
  
      
Alternatively, you can use a GtkTreeIter to reference the current active item.

::

  
  
  void        hildon_find_toolbar_set_active_iter (HildonFindToolbar *toolbar,
                                                   GtkTreeIter *iter);
  gboolean    hildon_find_toolbar_get_active_iter (HildonFindToolbar *toolbar,
                                                   GtkTreeIter *iter);
  
      
After create and properly set up the toolbar is necessary to attach it to any window. HildonWindow provides the following function to attach a toolbar:

::

  
  
  void        hildon_window_add_toolbar       (HildonWindow *self,
                                               GtkToolbar *toolbar);
  
      
In case you need to add a common toolbar to all windows in your program, HildonProgram provides the following function to set and retrtieve a common toolbar to each window registered into the curretn program:

::

  
  
  void        hildon_program_set_common_toolbar (HildonProgram *self,
                                                 GtkToolbar *toolbar);
  GtkToolbar* hildon_program_get_common_toolbar (HildonProgram *self);
  
      
Here a simple example that shows how to deal with a HildonFindToolbar.

Using a Find Toolbar
====================

.. code-block:: python

  
  
  #include                                        <hildon/hildon.h>
  gboolean
  on_history_append                               (HildonFindToolbar *toolbar,
                                                   gpointer           user_data)
  {
  
    gchar *item;
    GtkTreeIter iter;
    gint index ;
    GtkListStore *list;
  
    /* Get last added index */
    index = hildon_find_toolbar_get_last_index (toolbar);
  
    /* Get the inner list */
    g_object_get (G_OBJECT (toolbar),
                  "list",&list,
                  NULL);
  
    /* Get the item */
    gtk_tree_model_get_iter_from_string (GTK_TREE_MODEL (list) ,
                                         &iter,
                                         g_strdup_printf ("%d",index));
  
    gtk_tree_model_get (GTK_TREE_MODEL (list),
                        &iter,
                        0, &item,
                        -1);
  
    g_debug ("ADDED TO THE LIST : %s", item);
  
    return FALSE;
  }
  
  int
  main                                            (int argc,
                                                   char **argv)
  {
    HildonProgram *program;
    GtkWidget *window;
    GtkWidget *toolbar = NULL;
    GtkListStore *store;
    GtkTreeIter iter;
  
    hildon_gtk_init (&argc, &argv);
  
    program = hildon_program_get_instance ();
    window = hildon_window_new ();
  
    hildon_program_add_window (program, HILDON_WINDOW (window));
  
    /* Create and populate history list model */
    store = gtk_list_store_new (1, G_TYPE_STRING);
  
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter, 0, "Foo", -1);
  
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter, 0, "Bar", -1);
  
    gtk_list_store_append (store, &iter);
    gtk_list_store_set (store, &iter, 0, "Baz", -1);
  
  
    /* Create find toolbar */
    toolbar = hildon_find_toolbar_new_with_model ("Find", store, 0);
  
    /* Set item on index 0 as the current active*/
    hildon_find_toolbar_set_active (HILDON_FIND_TOOLBAR (toolbar), 0);
  
    /* Attach a callback to handle "history-append" signal */
    g_signal_connect_after (G_OBJECT (toolbar), "history-append", G_CALLBACK (on_history_append), NULL);
  
    /* Attach toolbar to window */
    hildon_window_add_toolbar (HILDON_WINDOW (window), GTK_TOOLBAR (toolbar));
  
    gtk_widget_show_all (GTK_WIDGET (window));
  
    gtk_main ();
    return 0;
  }
  
        
In the example above a callback is set to handle the signal "history-append", emitted by the toolbar when a new item is added to the history. There are other interesting signals such as "history-append" that could be handle to perform aditional actions when they will be emitted.

Apart from the property which stores the internal list, other properties are available such as "max-characters" , which set the maximum length of the search string. To a complete description of the signals and properties available read the Hildon reference manual.

Edit Toolbars
*************

Edit toolbars are implemented by the widget HildonEditToolbar.This widget is a toolbar to be used as main control and navigation interface for the edit UI mode. This toolbar contains a label and two buttons, being one of them an arrow pointing backwards and the other a button to perform a certain action. It also display a label which explain to the users the action that will be performed by the button and could give intructions to user on how to perform the action properly.

A typical example could be a view to delete several items in a list. The label would advice user to select the items to delete and those items will be deleted by clicking the button.

Typically, this toolbar will be attached to a edit view, meaning a HildonStackableWindow used in the program to perform a certain editing action.

The action to be performing by clicking the action button should be implemented in a callback to handle the signal "button-clicked", that will be show in the example.

To create a new HildonEditToolbar you should use:

::

  
  
  GtkWidget*  hildon_edit_toolbar_new           (void);
  GtkWidget*  hildon_edit_toolbar_new_with_text (const gchar *label,
                                                 const gchar *button);
  
      
The second creation function allows to set the two labels of the widget. If you use the simple creation function, you should set the labels by using the following functions.

::

  
  
  void        hildon_edit_toolbar_set_label        (HildonEditToolbar *toolbar,
                                                    const gchar *label);
  void        hildon_edit_toolbar_set_button_label (HildonEditToolbar *toolbar,
                                                    const gchar *label);
  
      
Once the edit toolbar is configured you need to attach it to a window by using:

::

  
  
  void        hildon_window_add_toolbar       (HildonWindow *self,
                                               GtkToolbar *toolbar);
  
      
As was said, the action to be done by clicking the button should be mplemented in a callback attached to the signal "button-clicked". This widgets define also another signal, "arrow-clicked", emitted when users click the arrow. Typically, the callback for the signal "arrow-clicked" should destroy the current edit view.

The example bellow shows how to use an edit toolbar. This example builds a main window showing a list of items and a button to go to a edit view where users can select several items and deleted by clicking the action button of the toolbar.

Using an Edit Toolbar
=====================

.. code-block:: python

  
  
  #include                                        <hildon/hildon.h>
  
  typedef enum
  {
    NORMAL_MODE,
    EDIT_MODE
  } TreeViewMode;
  
  enum { TEXT_COLUMN, N_COLUMNS };
  
  static GtkTreeModel *
  get_model                                       (void)
  {
    int i;
    static GtkListStore *store = NULL;
  
    if (store != NULL)
      return GTK_TREE_MODEL (store);
  
    store = gtk_list_store_new (1, G_TYPE_STRING);
  
    for (i = 0; i < 50; i++)
      {
        gchar *str;
  
        str = g_strdup_printf ("\nRow %d\n", i);
        gtk_list_store_insert_with_values (store, NULL, i, 0, str, -1);
        g_free (str);
      }
  
    return GTK_TREE_MODEL (store);
  }
  
  GtkWidget *
  create_treeview                                 (TreeViewMode tvmode)
  {
    GtkWidget *tv;
    GtkTreeViewColumn *col;
    GtkCellRenderer *renderer;
    GtkTreeModel *model;
    GtkTreeSelection *selection;
  
    tv = hildon_gtk_tree_view_new (tvmode);
    renderer = gtk_cell_renderer_text_new ();
    col = gtk_tree_view_column_new_with_attributes ("Title", renderer,
                                                    "text", TEXT_COLUMN, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW(tv), col);
  
    /* Set multiple selection mode*/
    selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (tv));
    gtk_tree_selection_set_mode (selection, GTK_SELECTION_MULTIPLE);
  
    model = get_model ();
  
    gtk_tree_view_set_model (GTK_TREE_VIEW (tv), model);
  
    return tv;
  }
  
  
  static void
  delete_button_clicked                           (GtkButton   *button,
                                                   GtkTreeView *treeview)
  {
    GtkTreeModel *model;
    GtkTreePath *path;
    GtkTreeIter iter;
    GtkTreeRowReference *ref;
    GtkTreeSelection *selection;
    GList *selected_rows, *list, *row_references = NULL;
  
    selection = gtk_tree_view_get_selection (treeview);
  
    selected_rows = gtk_tree_selection_get_selected_rows (selection,
                                                          &model);
  
    for (list = selected_rows; list; list = g_list_next(list)) {
  
      path = list->data;
  
      ref = gtk_tree_row_reference_new (model,
                                        path);
  
      row_references = g_list_append (row_references,
                                      ref);
    }
  
    for (list = row_references; list; list = g_list_next(list)) {
  
      path = gtk_tree_row_reference_get_path ((GtkTreeRowReference *) (list->data));
  
      gtk_tree_model_get_iter (model, &iter, path);
  
      gtk_list_store_remove (GTK_LIST_STORE (model), &iter);
  
      gtk_tree_path_free (path);
  
    }
  
    g_list_free (selected_rows);
    g_list_free (row_references);
    g_list_free (list);
  }
  
  static void
  edit_window                                     (void)
  {
    GtkWidget *window;
    GtkWidget *tree_view;
    GtkWidget *toolbar;
    GtkWidget *area;
  
    window = hildon_stackable_window_new ();
    gtk_container_set_border_width (GTK_CONTAINER (window), 6);
  
    /* Create a new edit toolbar */
    toolbar = hildon_edit_toolbar_new_with_text ("Choose items to delete",
                                                 "Delete");
    area = hildon_pannable_area_new ();
    tree_view = create_treeview (EDIT_MODE);
  
    /* Add toolbar to the window */
    hildon_window_set_edit_toolbar (HILDON_WINDOW (window),
                                    HILDON_EDIT_TOOLBAR (toolbar));
  
    gtk_container_add (GTK_CONTAINER (area), tree_view);
    gtk_container_add (GTK_CONTAINER (window), area);
  
    g_signal_connect (toolbar, "button-clicked",
                      G_CALLBACK (delete_button_clicked),
                      tree_view);
  
    g_signal_connect_swapped (toolbar, "arrow-clicked",
                              G_CALLBACK (gtk_widget_destroy),
                              window);
  
    gtk_widget_show_all (window);
  
    /* Set window to fullscreen */
    gtk_window_fullscreen (GTK_WINDOW (window));
  }
  
  int
  main                                            (int    argc,
                                                   char **argv)
  {
    GtkWidget *window;
    GtkWidget *tree_view;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *area;
  
    hildon_gtk_init (&argc, &argv);
  
    window = hildon_stackable_window_new ();
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
  
    vbox = gtk_vbox_new (FALSE, 10);
    area = hildon_pannable_area_new ();
  
    tree_view = create_treeview (NORMAL_MODE);
  
    button = hildon_gtk_button_new (HILDON_SIZE_AUTO_WIDTH | HILDON_SIZE_FINGER_HEIGHT);
    gtk_button_set_label (GTK_BUTTON (button), "Delete some items");
  
    gtk_container_add (GTK_CONTAINER (area), tree_view);
    gtk_box_pack_start (GTK_BOX (vbox), area, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);
  
    gtk_container_add (GTK_CONTAINER (window), vbox);
  
    g_signal_connect (button, "clicked", G_CALLBACK (edit_window), NULL);
  
    gtk_widget_show_all (window);
  
    gtk_main ();
  
    return 0;
  }
  
        
The most of stuff related to HildonEditToolbar is in the function edit_window. This function creates a edit view, meaning that a new HildonStackableWindow is created showing a treeview in which users can select several items.

Note that the edit window is set to fullscreen, thus, the HildonEditToolbar will be displayed obscuring the usual window controls.

Using GtkToolbars in Hildon applications
****************************************

You can use the widget GtkToolbar as you would do in a GTK+ application but taking account the following that:

* GtkToolbars should be used when there is only one content item visible (e.g. when editing a single image or editing a single email).
* There should be no menu commands or settings for hiding or showing toolbar. The toolbar is always shown in the view where you decided to put it.

Like the others toolbars, a GtkToolbar should be attached to a window by using:

::

  
  
  void        hildon_window_add_toolbar       (HildonWindow *self,
                                               GtkToolbar *toolbar);
  
      
The following example shows how to use a GtkToolBar. The use is very close to how it would be use in a normal GTK+ application.

Using a GtkToolbar in a Hildon application
==========================================

.. code-block:: python

  
  
  #include                                        <hildon/hildon.h>
  
  void on_clicked (GtkToolButton *toolbutton,
                   gint index)
  {
    g_debug ("Index of clicked item : %d", index);
  }
  
  int
  main                                            (int argc,
                                                   char **argv)
  {
    HildonProgram *program;
    GtkWidget *window;
    GtkWidget *toolbar;
    GtkToolItem *toolitem;
  
    hildon_gtk_init (&argc, &argv);
  
    program = hildon_program_get_instance ();
    window = hildon_window_new ();
  
    hildon_program_add_window (program, HILDON_WINDOW (window));
  
    /* Create a toolbar */
    toolbar = gtk_toolbar_new ();
  
    /* Add items to the toolbar */
    toolitem = gtk_tool_button_new (
      gtk_image_new_from_stock(GTK_STOCK_HOME, HILDON_ICON_PIXEL_SIZE_TOOLBAR),
      "Home");
  
    g_signal_connect (G_OBJECT (toolitem),
                      "clicked",
                      G_CALLBACK (on_clicked),
                      (gpointer) 0);
  
    gtk_toolbar_insert (GTK_TOOLBAR (toolbar),
                        toolitem,
                        0);
  
    toolitem = gtk_tool_button_new (
      gtk_image_new_from_stock(GTK_STOCK_GO_BACK, HILDON_ICON_PIXEL_SIZE_TOOLBAR),
      "Back");
  
    g_signal_connect (G_OBJECT (toolitem),
                      "clicked",
                      G_CALLBACK (on_clicked),
                      (gpointer) 1);
  
    gtk_toolbar_insert (GTK_TOOLBAR (toolbar),
                        toolitem,
                        1);
  
    toolitem = gtk_tool_button_new (
      gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD, HILDON_ICON_PIXEL_SIZE_TOOLBAR),
      "Forward");
  
    g_signal_connect (G_OBJECT (toolitem),
                      "clicked",
                      G_CALLBACK (on_clicked),
                      (gpointer) 2);
  
    gtk_toolbar_insert (GTK_TOOLBAR (toolbar),
                        toolitem,
                        2);
  
    /* Add toolbar to the window */
    hildon_window_add_toolbar (HILDON_WINDOW (window),
                               GTK_TOOLBAR(toolbar));
  
    gtk_widget_show_all (GTK_WIDGET (window));
  
    gtk_main ();
  
    return 0;
  }
  
        

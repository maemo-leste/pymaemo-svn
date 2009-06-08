.. _ch-Windows:

Windows and Dialogs
###################

When creating applications for hand-held devices, you should take into account several issues about usability and device limitations. One remarkable limitation is the screen size, thus, it is critical to keep a simple interface.

In contrast with GTK+ applications, Hildon applications have only one visible window at a time. A typical Hildon application will use several windows representing different views in a tree-like hierarchy.

:ref:`hello-world-example` (the Hello World) has already shown how a simple HildonWindow can be used and it is pretty similar to the use of a classical GTK+ window. Since the mentioned tree-like views represent a new concept introduced by Hildon, this section focuses in this type of windows.

To properly understand what views are, you can think of an application as a program that allows the user to perform one or more tasks. Each task can be broken down into several main activities.

Main activities in tasks should be done and presented in separate application views or windows, while assistance activities and steps to fulfill those tasks should be done in dialogs and menus on top of the currently displayed view.

Views work in a tree-like hierarchy - there is a Root View that acts as a "root" for the tree, while the subsequent Sub Views are branching down the hierarchy.

@@COMMENT@@ AN EXAMPLE OF VIEWS NAVIGATION (maybe an example of a real use case)

The view concept is implemented by the widget HildonStackableWindow. This widget allows to built a navigable hierarchy of windows with less code.

Stackable windows
*****************

The HildonStackableWindow is a GTK+ widget which represents a top-level window in the Hildon framework. As it was mentioned above, this widget should be used to represent views and subviews. Stackable windows can be organized in a hierarchical way.

A stack sets the hierarchical relationships between windows. Child windows will be on top of its parent window. That allows navigate to previous window by removing the topmost window.

Users can only see and interact with the window on the top of stack. All other windows are mapped and visible but they are obscured by the topmost one. And they can go back to a root view from a subview by clicking in the navigation button in the top right corner of the window.

Each application has a default stack, and windows are automatically added to it when they are shown using gtk_widget_show(). Most applications do not need to create extra stacks. Create more than one stack could make your UI too complex, so think twice before doing it.

Let's see a simple example to show the use of this widget. This simple program creates a stackable window with a button to navigate towards a subview, a new window on top of the stack.

Example of stackable windows
============================

.. code-block:: python

  
  
  #include                                        <hildon/hildon.h>
  
  static void
  show_new_window (void)
  {
      GtkWidget *win;
      GtkWidget *vbox;
      GtkWidget *label;
  
      /* Create the main window */
      win = hildon_stackable_window_new();
      gtk_window_set_title ( GTK_WINDOW (win), "Subview");
  
      /* Setting a label in the new window */
      label =  gtk_label_new ("This is a subview");
  
      vbox = gtk_vbox_new (FALSE, 0);
      gtk_box_pack_start (GTK_BOX (vbox),
                          label,
                          TRUE,
                          TRUE,
                          0);
  
      gtk_container_add (GTK_CONTAINER (win),
                         vbox);
  
      g_signal_connect (win, "destroy", G_CALLBACK (test), NULL);
  
      /* This call show the window and also add the window to the stack */
      gtk_widget_show_all (win);
  }
  
  
  int
  main (int argc,
        char **argv)
  {
      HildonProgram *program;
  
      GtkWidget *win;
      GtkWidget *button;
  
      hildon_gtk_init (&argc, &argv);
  
      program = hildon_program_get_instance ();
  
      /* Create the main window */
      win = hildon_stackable_window_new ();
      gtk_window_set_title ( GTK_WINDOW (win), "Main window");
  
      button =  gtk_button_new_with_label ("Go to subview");
      gtk_container_add ( GTK_CONTAINER (win),
                          button);
  
      g_signal_connect (button, "clicked", G_CALLBACK (show_new_window), NULL);
  
      g_signal_connect (win, "destroy", G_CALLBACK (test), NULL);
  
      g_signal_connect (win, "destroy", G_CALLBACK (gtk_main_quit), NULL);
  
      /* This call show the window and also add the window to the stack */
      gtk_widget_show_all (win);
      gtk_main();
  
      return 0;
  }
  
          
The function show_new_window() is set up as a handler for when the signal "clicked" is emitted. This function creates a new stackable window which will be added on top of the stack by calling gtk_widget_show().

When a stackable window is shown by calling gtk_widget_show() or gtk_widget_show_all(), it will be automatically added on top of the default stack.

Note that there is no extra code regarding navigation between views since the navigation button on top-right corner of the window allows users to go back from subviews. When the navigation button is pressed, the topmost window is destroyed, thus, the previous window becomes the topmost one.

In some applications it could be necessary to push and/or pop windows on the stack without destroying them, or even to build and handle extra windows' stacks. Next section explains how to do that.

Advanced stack handling
***********************

The object which represents a stack of windows in the Hildon framework is the HildonWindowStack. This object provides functions to push and/or pop windows on the stack, functions to access the topmost window or retrieve the current size of the stack are provided as well.

Usual operations
================

To access the default stack you can use the function hildon_window_stack_get_default(). Also, it is possible to access the stack which a particular window is on by calling hildon_stackable_window_get_stack().

::

  
  
  HildonWindowStack* hildon_window_stack_get_default          (void);
  
        
There are several function to push and/or pop windows on a stack. Below, you can see the currently available.

::

  
  
  void        hildon_window_stack_push              (HildonWindowStack *stack,
                                                     HildonStackableWindow *win1,
                                                     ...);
  void        hildon_window_stack_push_list         (HildonWindowStack *stack,
                                                     GList *list);
  void        hildon_window_stack_push_1            (HildonWindowStack *stack,
                                                     HildonStackableWindow *win);
  void        hildon_window_stack_pop               (HildonWindowStack *stack,
                                                     gint nwindows,
                                                     GList **popped_windows);
  GtkWidget*  hildon_window_stack_pop_1             (HildonWindowStack *stack);
  void        hildon_window_stack_pop_and_push      (HildonWindowStack *stack,
                                                     gint nwindows,
                                                     GList **popped_windows,
                                                     HildonStackableWindow *win1,
                                                     ...);
  void        hildon_window_stack_pop_and_push_list (HildonWindowStack *stack,
                                                     gint nwindows,
                                                     GList **popped_windows,
                                                     GList *list);
  
        
The example shows how to get the default stack and push a newly created window on the stack. (Note that you also can do the same in a single stack by calling gtk_widget_show()).

Pushing a new window into a stack
=================================

.. code-block:: python

  
  
      HildonWindowStack *stack = NULL;
      GtkWidget *window;
  
      window = hildon_stackable_window_new ();
  
      stack = hildon_window_stack_get_default ();
  
      hildon_window_stack_push_1 (stack, HILDON_STACKABLE_WINDOW (window));
  
          
The push functions also show the window, thus, it is unnecessary to call gtk_window_show() after performing a push operation.

There is also a function to push a list of windows in a single step. Windows will be stacked in the order of the list and users will only see the last pushed window.

Pushing a list of windows into a stack
======================================

.. code-block:: python

  
  
      GList *list = NULL;
      HildonWindowStack *stack = NULL;
      HildonStackableWindow *window;
      gint nwindows = 10;
  
      stack = hildon_stackable_window_get_stack (window);
  
      while (nwindows > 0) {
          parent = hildon_stackable_window_new ();
          list = g_list_append (list, window);
          nwindows--;
      }
      hildon_window_stack_push_list (stack, list);
      g_list_free (list);
  
        
There are similar functions to perform the pop operation. In the example, hildon_window_stack_pop_list() is used to pop N windows from the default stack and stores them in the list of arguments. Notice that the size of the stack is checked with hildon_stackable_window_size().

Popping a number of windows from a stack into a list
====================================================

.. code-block:: python

  
  
      GList *list = NULL;
      HildonWindowStack *stack;
      HildonStackableWindow *window;
      gint nwindows = 10;
  
      stack = hildon_stackable_window_get_default ();
  
      if (hildon_stackable_window_size (stack) > nwindows){
          hildon_window_stack_pop (stack, nwindows, list);
      }
  
        
HildonWindowStack object also provides more advanced functions to perform both pop and push operations at once such as hildon_window_stack_pop_and_push() or hildon_window_stack_pop_and_push_list(). These functions do everything in a single transition, so the user will only see the last pushed window.

When you perform push/pop operations you should take into account two things:

* All stacked windows are visible and all visible windows are stacked.
* Each window can only be in one stack at a time.

Due to the first one, a push operation always shows the window and a pop operation always hides the window. Functions gtk_widget_show() and gtk_window_hide() always push and remove the window from its current stack, respectively.

Regarding the second one, operation push will not take effect on windows which are already on a stack.

Multiple Stacks
===============

Most applications do not need more than the default stack. Although it is possible to use multiple stacks in one application, you should be aware that this could increase the complexity of the UI. So think twice before deciding to use several stacks.

To create a new stack just use hildon_window_stack_new(). New stacks will behave like a new application or task. Newly created stacks will be displayed on top of current stack. Users will need to use the task selector to change between stacks as they use to do to change between tasks (applications).

Once a new stack is created you can use the functions explained in the previous section to pop and/or push windows on the stack.

Dialogs
*******

Dialog boxes are a convenient way to prompt the user for a small amount of input, e.g. to display a message, ask a question, or anything else that does not require extensive effort on the user's part.

Hildon provides specialized widgets to cover the most common dialog's use cases: HildonNote and HildonBanner.

HildonNote is useful to ask users a question and HildonBanner is used to show textual information which automatically disappear after a certain period of time without user interaction. Both widgets will be deeply explained in :ref:`section-notification-widgets` .

Besides those widgets, Hildon provides also specialized GtkDialogs designed to cover different use cases: HildonPickerDialog and HildonWizardDialog.

The widget HildonPickerDialog is used along with HildonPickerButton and HildonTouchSelector to give a way to make data selections. :ref:`ch-Selectors` explains the use of such widgets.

To create a guided process which helps users accomplish complex task step by step, Hildon provide the HildonWizardDialog widget. Next section explains how to use this widget.

HildonWizardDialog
==================

HildonWizardDialog is a widget that allows one to create a guided process. The dialog has three standard buttons, previous, next and finish, and contains several pages. Users can close the dialog by tapping the dimmed area outside the dialog's window

A good example of a guided process which could be implemented with this widget is the setup of a new e-mail account in an e-mail client. Users would have to fill several entries through several steps to accomplish the setup of the new account. The process of installing an application is another example of how this widget could be used.

This widget uses a GtkNotebook that contains the actual wizard pages. The notebook widget is pointed by the property "wizard-notebook" of the wizard. You need to create the notebook as well as the pages that will be displayed. You can read more about GtkNotebook in `GTK+ Reference Manual <GTK+ Reference Manual>`_

To create a new wizard dialog you should call:

::

  
  
  GtkWidget*  hildon_wizard_dialog_new        (GtkWindow *parent,
                                               const char *wizard_name,
                                               GtkNotebook *notebook);
  
        
The parent window is usually the current visible view. The wizard name will be displayed as title in the wizard dialog.

Usually, you will want to validate user input to decide whether it should move to the next step or not. To do that you can set a user function by using:

::

  
  
  void        hildon_wizard_dialog_set_forward_page_func (HildonWizardDialog *wizard_dialog,
                                                          HildonWizardDialogPageFunc page_func,
                                                          gpointer data,
                                                          GDestroyNotify destroy);
  
        
The function above sets the function "page_func" to be used to decide whether users can go to the next page when they press the forward button. The function should have the following signature:

::

  
  
  gboolean    (*HildonWizardDialogPageFunc)   (GtkNotebook *notebook,
                                               gint current_page,
                                               gpointer data);
  
        
Here, an example of using a HildonWizardDialog

Example of a Hildon wizard dialog
=================================

.. code-block:: python

  
  
  #include                                        <stdio.h>
  #include                                        <stdlib.h>
  #include                                        <string.h>
  #include                                        <hildon/hildon.h>
  
  gboolean
  on_page_switch (GtkNotebook *notebook,
                  GtkNotebookPage *page,
                  guint num,
                  HildonWizardDialog *dialog)
  {
      g_debug ("Page %d", num);
  
      return TRUE;
  }
  
  static gboolean
  some_page_func (GtkNotebook *nb,
                  gint current,
                  gpointer userdata)
  {
    HildonEntry *entry;
  
    /* Validate data only for the third page. */
    switch (current) {
      case 2:
        entry = HILDON_ENTRY (gtk_notebook_get_nth_page (nb, current));
        return (strlen (hildon_entry_get_text (entry)) != 0);
      default:
        return TRUE;
    }
  }
  
  int
  main (int argc, char **argv)
  {
      hildon_gtk_init (&argc, &argv);
  
      GtkWidget *dialog, *notebook, *label_1, *label_2, *entry_3, *label_4;
  
      /* Create a notebook */
      notebook = gtk_notebook_new ();
  
      /* Create widgets to place into the notebook's pages */
      label_1 = gtk_label_new ("Page 1");
      label_2 = gtk_label_new ("Page 2");
  
      entry_3 = hildon_entry_new (HILDON_SIZE_AUTO);
      hildon_entry_set_placeholder (HILDON_ENTRY (entry_3),
                                    "Write something to continue");
  
      label_4 = gtk_label_new ("Page 4");
  
      /* Append pages */
      gtk_notebook_append_page (GTK_NOTEBOOK (notebook), label_1, NULL);
      gtk_notebook_append_page (GTK_NOTEBOOK (notebook), label_2, NULL);
      gtk_notebook_append_page (GTK_NOTEBOOK (notebook), entry_3, NULL);
      gtk_notebook_append_page (GTK_NOTEBOOK (notebook), label_4, NULL);
  
      /* Create wizard dialog */
      dialog = hildon_wizard_dialog_new (NULL, "Wizard",
                                         GTK_NOTEBOOK (notebook));
  
      /* Set a handler for "switch-page" signal */
      g_signal_connect (G_OBJECT (notebook),
                        "switch-page",
                        G_CALLBACK (on_page_switch),
                        dialog);
  
      /* Set a function to decide if user can go to next page */
      hildon_wizard_dialog_set_forward_page_func (HILDON_WIZARD_DIALOG (dialog),
                                                  some_page_func, NULL, NULL);
  
      gtk_widget_show_all (dialog);
      gtk_dialog_run (GTK_DIALOG (dialog));
  
      return 0;
  }
  
          
Apart from how to create and use a wizard dialog, this example also sets up a handler to catch the signal "switch-page" from the notepad. This signal is emitted by the widget GtkNotebook when the user or a function changes the current page.

Using GtkDialogs in Hildon applications
=======================================

In general you can use GtkDialog in a similar way as you would use it in a GTK+ application. But you have to take into account that:

* In Hildon applications, buttons "cancel", "reject" and "close" are allowed. However, buttons which emit the signal "response" with GTK_RESPONSE_CANCEL, GTK_RESPONSE_REJECT or GTK_RESPONSE_CLOSE as the response's identifier, will not be displayed. Therefore, if you need to deal with the action of closing a GtkDialog in a Hildon application, you would need to be aware of this detail and to handle the GTK_RESPONSE_DELETE_EVENT response identifier properly.
* Another detail to take care of is that GtkDialogs can work in two modalities in a Hildon application: task-modal or system-modal. A dialog will be task-modal if it is transient for the main window. That will be the case when the function gtk_window_set_transient_for() is used or the dialog was created by calling gtk_dialog_new_with_buttons() specifying a parent window. Otherwise, the dialog will be system-modal. If the dialog is task-modal, the Platform UI (Task button and Status area) will be visible on top and can be used normally to switch between tasks. If the dialog is system-modal, both the task button and status area are blurred and dimmed. They are not active while the dialog is open and until it is closed, task switching are not possible.

Here an example which create a task-modal dialog.

Application modal dialog example
================================

.. code-block:: python

  
  
  #include <hildon/hildon.h>
  
  int
  main                                            (int argc,
                                                   char **argv)
  {
    GtkWidget *dialog;
    GtkWidget *win;
  
    hildon_gtk_init (&argc, &argv);
  
    win = hildon_stackable_window_new () ;
  
    gtk_widget_show (win);
  
    dialog = gtk_dialog_new ();
  
    gtk_window_set_transient_for  (GTK_WINDOW (dialog),
                                   GTK_WINDOW (win));
  
    gtk_window_set_title (GTK_WINDOW (dialog), "Hello!");
  
    gtk_widget_show_all (GTK_WIDGET (dialog));
  
    gtk_dialog_run (GTK_DIALOG (dialog));
  
    return 0;
  }
  
          

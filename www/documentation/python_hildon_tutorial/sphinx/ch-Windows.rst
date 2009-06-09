.. _ch-Windows:

Windows and Dialogs
###################

When creating applications for hand-held devices, you should take into account several issues about usability and device limitations. One remarkable limitation is the screen size, thus, it is critical to keep a simple interface.

In contrast with GTK+ applications, Hildon applications have only one visible window at a time. A typical Hildon application will use several windows representing different views in a tree-like hierarchy.

:ref:`hello-world-example` (The Hello World) has already shown how a simple hildon.Window can be used and it is pretty similar to the use of a classical GTK+ window. Since the mentioned tree-like views represent a new concept introduced by Hildon, this section focuses in this type of windows.

To properly understand what views are, you can think of an application as a program that allows the user to perform one or more tasks. Each task can be broken down into several main activities.

Main activities in tasks should be done and presented in separate application views or windows, while assistance activities and steps to fulfill those tasks should be done in dialogs and menus on top of the currently displayed view.

Views work in a tree-like hierarchy - there is a Root View that acts as a "root" for the tree, while the subsequent Sub Views are branching down the hierarchy.

@@COMMENT@@ AN EXAMPLE OF VIEWS NAVIGATION (maybe an example of a real use case)

The view concept is implemented by the widget hildon.StackableWindow. This widget allows to build a navigable hierarchy of windows with less code.

Stackable windows
*****************

The hildon.StackableWindow is a GTK+ widget which represents a top-level window in the Hildon framework. As it was mentioned above, this widget should be used to represent views and subviews. Stackable windows can be organized in a hierarchical way.

A stack sets the hierarchical relationships between windows. Child windows will be on top of its parent window. That allows navigate to previous window by removing the topmost window.

Users can only see and interact with the window on the top of stack. All other windows are mapped and visible but they are obscured by the topmost one. And they can go back to a root view from a subview by clicking in the navigation button in the top right corner of the window.

Each application has a default stack, and windows are automatically added to it when they are shown using show_all(). Most applications do not need to create extra stacks. Create more than one stack could make your UI too complex, so think twice before doing it.

Let's see a simple example to show the use of this widget. This simple program creates a stackable window with a button to navigate towards a subview, a new window on top of the stack.

Example of stackable windows
============================

.. literalinclude:: ../examples/hildon-nested-views-simple-example.py
          
The function show_new_window(widget) is set up as a handler for when the signal "clicked" is emitted. This function creates a new stackable window which will be added on top of the stack by calling show_all().

When a stackable window is shown by calling gtk_widget_show() or gtk_widget_show_all(), it will be automatically added on top of the default stack.

Note that there is no extra code regarding navigation between views since the navigation button on top-right corner of the window allows users to go back from subviews. When the navigation button is pressed, the topmost window is destroyed, thus, the previous window becomes the topmost one.

In some applications it could be necessary to push and/or pop windows on the stack without destroying them, or even to build and handle extra windows' stacks. Next section explains how to do that.

Advanced stack handling
***********************

The object which represents a stack of windows in the Hildon framework is the hildon.WindowStack. This object provides functions to push and/or pop windows on the stack, functions to access the topmost window or retrieve the current size of the stack are provided as well.

Usual operations
================

To access the default stack you can use the function hildon_window_stack_get_default(). Also, it is possible to access the stack which a particular window is on by calling hildon_stackable_window_get_stack().

::

  
  
  hildon.hildon_window_stack_get_default()
  
        
There are several function to push and/or pop windows on a stack. Below, you can see the currently available.

::

  
  
  hildon.WindowStack.hildon_window_stack_push(stackablewindow,
                                              ...)
  hildon.WindowStack.hildon_window_stack_push_list(windows_list)
  hildon.WindowStack.hildon_window_stack_push_1(stackablewindow)
  hildon.WindowStack.hildon_window_stack_pop(nwindows,
                                             popped_windows_list)
  hildon.WindowStack.hildon_window_stack_pop_1();
  hildon.WindowStack.hildon_window_stack_pop_and_push(nwindows,
                                                      popped_windows_list,
                                                      stackablewindow,
                                                      ...);
  hildon.WindowStack.hildon_window_stack_pop_and_push_list(nwindows,
                                                           popped_windows_list,
                                                           windows_list);

The example shows how to get the default stack and push a newly created window on the stack. (Note that you also can do the same in a single stack by calling show_all()).

Pushing a new window into a stack
=================================

.. code-block:: python


      import hildon

      win = hildon.StackableWindow()
      stack = hildon.hildon_window_stack_get_default()
      stack.push_1(win) 


The push functions also show the window, thus, it is unnecessary to call show_all() after performing a push operation.

There is also a function to push a list of windows in a single step. Windows will be stacked in the order of the list and users will only see the last pushed window.

Pushing a list of windows into a stack
======================================

.. code-block:: python


      import hildon

      window = hildon.StackableWindow()
      window.show_all()
      stack = window.get_stack()

      nwindows = 10
      win_list = []

      while nwindows > 0:
          parent = hildon.StackableWindow()
          win_list.append(parent) 
          nwindows -= 1;

      #TODO: push_list must be implemented as an override
      stack.push_list(win_list)



There are similar functions to perform the pop operation. In the example, hildon_window_stack_pop_list() is used to pop N windows from the default stack and stores them in the list of arguments. Notice that the size of the stack is checked with hildon_stackable_window_size().

Popping a number of windows from a stack into a list
====================================================

.. code-block:: python


      import hildon

      stack = hildon.hildon_stackable_window_get_default()
      nwindows = 10
      win_list = []

      if stack.hildon_stackable_window_size() > nwindows :
          stack.hildon_window_stack_pop(nwindows, win_list)



HildonWindowStack object also provides more advanced functions to perform both pop and push operations at once such as hildon_window_stack_pop_and_push() or hildon_window_stack_pop_and_push_list(). These functions do everything in a single transition, so the user will only see the last pushed window.

When you perform push/pop operations you should take into account two things:

* All stacked windows are visible and all visible windows are stacked.
* Each window can only be in one stack at a time.

Due to the first one, a push operation always shows the window and a pop operation always hides the window. Functions show_all() and hide_all() always push and remove the window from its current stack, respectively.

Regarding the second one, operation push will not take effect on windows which are already on a stack.

Multiple Stacks
===============

Most applications do not need more than the default stack. Although it is possible to use multiple stacks in one application, you should be aware that this could increase the complexity of the UI. So think twice before deciding to use several stacks.

To create a new stack just use hildon_window_stack_new(). New stacks will behave like a new application or task. Newly created stacks will be displayed on top of current stack. Users will need to use the task selector to change between stacks as they use to do to change between tasks (applications).

Once a new stack is created you can use the functions explained in the previous section to pop and/or push windows on the stack.

Dialogs
*******

Dialog boxes are a convenient way to prompt the user for a small amount of input, e.g. to display a message, ask a question, or anything else that does not require extensive effort on the user's part.

Hildon provides specialized widgets to cover the most common dialog's use cases: hildon.Note and hildon.Banner.

hildon.Note is useful to ask users a question and hildon.Banner is used to show textual information which automatically disappear after a certain period of time without user interaction. Both widgets will be deeply explained in :ref:`section-notification-widgets` .

Besides those widgets, Hildon provides also specialized GtkDialogs designed to cover different use cases: hildon.PickerDialog and hildon.WizardDialog.

The widget hildon.PickerDialog is used along with hildon.PickerButton and hildon.TouchSelector to give a way to make data selections. :ref:`ch-Selectors` explains the use of such widgets.

To create a guided process which helps users accomplish complex task step by step, Hildon provide the hildon.WizardDialog widget. Next section explains how to use this widget.

hildon.WizardDialog
===================

hildon.WizardDialog is a widget that allows one to create a guided process. The dialog has three standard buttons, previous, next and finish, and contains several pages. Users can close the dialog by tapping the dimmed area outside the dialog's window.

A good example of a guided process which could be implemented with this widget is the setup of a new e-mail account in an e-mail client. Users would have to fill several entries through several steps to accomplish the setup of the new account. The process of installing an application is another example of how this widget could be used.

This widget uses a gtk.Notebook that contains the actual wizard pages. The notebook widget is pointed by the property "wizard-notebook" of the wizard. You need to create the notebook as well as the pages that will be displayed. You can read more about gtk.Notebook in `GTK+ Reference Manual <GTK+ Reference Manual>`_

To create a new wizard dialog you should call:

::

  
  
  hildon.WizardDialog(parent_window,
                      wizard_name,
                      gtk_notebook);
  
        
The parent window is usually the current visible view. The wizard name will be displayed as title in the wizard dialog.

Usually, you will want to validate user input to decide whether it should move to the next step or not. To do that you can set a user function by using:

::

  
  
  hildon.WizardDialog.set_forward_page_func(page_func,
                                            data,
                                            destroy_notify)
  
        
The function above sets the function "page_func" to be used to decide whether users can go to the next page when they press the forward button. The function should have the following signature:

::

 
  def some_page_func(notebook,
                     current_page_number,
                     user_data)
  
        
Here, an example of using a hildon.WizardDialog

Example of a Hildon wizard dialog
=================================

.. literalinclude:: ../examples/2.5
  
          
Apart from how to create and use a wizard dialog, this example also sets up a handler to catch the signal "switch-page" from the notepad. This signal is emitted by the widget gtk.Notebook when the user or a function changes the current page.

Using GtkDialogs in Hildon applications
=======================================

In general you can use gtk.Dialog in a similar way as you would use it in a GTK+ application. But you have to take into account that:

* In Hildon applications, buttons "cancel", "reject" and "close" are allowed. However, buttons which emit the signal "response" with gtk.RESPONSE_CANCEL, gtk.RESPONSE_REJECT or gtk.RESPONSE_CLOSE as the response's identifier, will not be displayed. Therefore, if you need to deal with the action of closing a gtk.Dialog in a Hildon application, you would need to be aware of this detail and to handle the gtk.RESPONSE_DELETE_EVENT response identifier properly.
* Another detail to take care of is that GtkDialogs can work in two modalities in a Hildon application: task-modal or system-modal. A dialog will be task-modal if it is transient for the main window. That will be the case when the function gtk.Window.set_transient_for() is used or the dialog was created by calling gtk.Dialog() specifying a parent window. Otherwise, the dialog will be system-modal. If the dialog is task-modal, the Platform UI (Task button and Status area) will be visible on top and can be used normally to switch between tasks. If the dialog is system-modal, both the task button and status area are blurred and dimmed. They are not active while the dialog is open and until it is closed, task switching are not possible.

Here an example which create a task-modal dialog.

Application modal dialog example
================================

.. literalinclude:: ../examples/2.6


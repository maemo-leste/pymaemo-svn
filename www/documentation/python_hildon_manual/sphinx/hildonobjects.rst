.. _hildonobjects:

Hildon Widgets and Objects
##########################

HildonWindow
************


Object Hierarchy
================

::


    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkWindow
                                         +----HildonWindow
                                               +----HildonStackableWindow

Implemented Interfaces
======================

HildonWindow implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Properties
==========

::

    is-topmost               bool              : Read
    markup                   str                : Read / Write

Style Properties
================

::

    borders                  GtkBorder*            : Read
    toolbar-borders          GtkBorder*            : Read


Signals
=======

::

    clipboard-operation                            : Run First


Description
===========

:class:`HildonWindow` is a GTK widget which represents a top-level window in the Hildon framework. It is derived from :class:`GtkWindow` and provides additional commodities specific to the Hildon framework.

:class:`HildonWindow` s can have a menu attached, which is toggled with a hardware key or by tapping on the window frame. This menu can be either a :class:`GtkMenu` or a :class:`HildonAppMenu` (set with :meth:`HildonWindow.set_main_menu` and :meth:`HildonWindow.set_app_menu` respectively). Only one type of menu can be used at the same time. In Hildon 2.2, :class:`HildonAppMenu` is the recommended menu to use.

Similarly, a :class:`HildonWindow` can have several toolbars attached. These can be added with `hildon_window_add_toolbar() <hildon-window-add-toolbar>`_ . In addition to those, a :class:`HildonWindow` can also have a :class:`HildonEditToolbar` . To add it to the window use `hildon_window_set_edit_toolbar() <hildon-window-set-edit-toolbar>`_ .

Creating a HildonWindow ======================= :: HildonWindow *window; GtkToolbar *toolbar; HildonAppMenu *menu; GdkPixbuf *icon_pixbuf; window = HILDON_WINDOW (hildon_window_new()); toolbar = create_toolbar(); menu = create_menu(); icon_pixbuf = create_icon(); hildon_window_set_app_menu (window, menu); hildon_window_add_toolbar (window, toolbar); // Can be used to set the window fullscreen gtk_window_fullscreen (GTK_WINDOW (window)); // Used to trigger the blinking of the window's icon in the task navigator gtk_window_set_urgency_hint (GTK_WINDOW (window), TRUE); // Change the window's icon in the task navigator gtk_window_set_icon (GTK_WINDOW (window), icon_pixbuf);




Details
=======

.. _HILDON-WINDOW-LONG-PRESS-TIME:CAPS:

.. :: HILDON_WINDOW_LONG_PRESS_TIME

::

  #define                                         HILDON_WINDOW_LONG_PRESS_TIME 800 /* in ms */
  



.. _HildonWindowClipboardOperation:

.. :: enum HildonWindowClipboardOperation

::

  typedef enum
  {
      HILDON_WINDOW_CO_COPY,
      HILDON_WINDOW_CO_CUT,
      HILDON_WINDOW_CO_PASTE
  }                                               HildonWindowClipboardOperation;
  



.. _HildonWindow-struct:

.. class:: HildonWindow

::

  typedef struct _HildonWindow HildonWindow;



.. _hildon-window-new:

.. function:: hildon_window_new ()

::

  GtkWidget*          hildon_window_new                   (void);

Creates a new :class:`HildonWindow` .



*Returns*:
  A :class:`HildonWindow` .


.. _hildon-window-add-with-scrollbar:

.. function:: hildon_window_add_with_scrollbar ()

::

  void                hildon_window_add_with_scrollbar    (HildonWindow *self,
                                                           GtkWidget *child);

Adds ``child`` to the :class:`HildonWindow` and creates a scrollbar for it. Similar to adding first a :class:`GtkScrolledWindow` and then ``child`` to it.



``self``:
  A :class:`HildonWindow`


``child``:
  A :class:`GtkWidget`


.. _hildon-window-set-main-menu:

.. function:: hildon_window_set_main_menu ()

::

  void                hildon_window_set_main_menu         (HildonWindow *self,
                                                           GtkMenu *menu);

Sets the menu to be used for this window. This menu overrides a program-wide menu that may have been set with `hildon_program_set_common_menu() <hildon-program-set-common-menu>`_ . Pass ```NULL`` <NULL:CAPS>`_ to remove the current menu. :class:`HildonWindow` takes ownership of the passed menu and you're not supposed to free it yourself anymore.

Note that if you're using a :class:`HildonAppMenu` rather than a :class:`GtkMenu` you should use :meth:`HildonWindow.set_app_menu` instead.



``self``:
  A :class:`HildonWindow`


``menu``:
  The :class:`GtkMenu` to be used for this :class:`HildonWindow`


.. _hildon-window-get-main-menu:

.. function:: hildon_window_get_main_menu ()

::

  GtkMenu*            hildon_window_get_main_menu         (HildonWindow *self);

Gets the :class:`GtkMenu` assigned to the :class:`HildonAppview` . Note that the window is still the owner of the menu.

Note that if you're using a :class:`HildonAppMenu` rather than a :class:`GtkMenu` you should use `hildon_window_get_app_menu() <hildon-window-get-app-menu>`_ instead.



``self``:
  a :class:`HildonWindow`


*Returns*:
  The :class:`GtkMenu` assigned to this application view.


Since 2.2

.. _hildon-window-set-app-menu:

.. function:: hildon_window_set_app_menu ()

::

  void                hildon_window_set_app_menu          (HildonWindow *self,
                                                           HildonAppMenu *menu);

Sets the menu to be used for this window. Pass ```NULL`` <NULL:CAPS>`_ to remove the current menu. Any reference to a previous menu will be dropped. :class:`HildonWindow` takes ownership of the passed menu and you're not supposed to free it yourself anymore.

Note that if you're using a :class:`GtkMenu` rather than a :class:`HildonAppMenu` you should use `hildon_window_set_main_menu() <hildon-window-set-main-menu>`_ instead.



``self``:
  a :class:`HildonWindow`


``menu``:
  a :class:`HildonAppMenu` to be used for this window


Since 2.2

.. _hildon-window-get-app-menu:

.. function:: hildon_window_get_app_menu ()

::

  HildonAppMenu*      hildon_window_get_app_menu          (HildonWindow *self);

Returns the :class:`HildonAppMenu` assigned to ``self``, or ```NULL`` <NULL:CAPS>`_ if it's unset. Note that the window is still the owner of the menu.

Note that if you're using a :class:`GtkMenu` rather than a :class:`HildonAppMenu` you should use `hildon_window_get_main_menu() <hildon-window-get-main-menu>`_ instead.



``self``:
  a :class:`HildonWindow`


*Returns*:
  a :class:`HildonAppMenu`


Since 2.2

.. _hildon-window-set-menu:

.. function:: hildon_window_set_menu ()

::

  void                hildon_window_set_menu              (HildonWindow *self,
                                                           GtkMenu *menu);

.. warning:: ``hildon_window_set_menu`` is deprecated and should not be used in newly-written code. Hildon 2.2: use `hildon_window_set_main_menu() <hildon-window-set-main-menu>`_

Sets the menu to be used for this window. This menu overrides a program-wide menu that may have been set with `hildon_program_set_common_menu() <hildon-program-set-common-menu>`_ . Pass ```NULL`` <NULL:CAPS>`_ to remove the current menu. HildonWindow takes ownership of the passed menu and you're not supposed to free it yourself anymore.

Note: `hildon_window_set_menu() <hildon-window-set-menu>`_ calls `gtk_widget_show_all() <gtk-widget-show-all>`_ for the :class:`GtkMenu` . To pass control about visibility to the application developer, `hildon_window_set_main_menu() <hildon-window-set-main-menu>`_ was introduced, which doesn't do this.



``self``:
  A :class:`HildonWindow`


``menu``:
  The :class:`GtkMenu` to be used for this :class:`HildonWindow`


.. _hildon-window-get-menu:

.. function:: hildon_window_get_menu ()

::

  GtkMenu*            hildon_window_get_menu              (HildonWindow *self);

.. warning:: ``hildon_window_get_menu`` is deprecated and should not be used in newly-written code. In Hildon 2.2 this function has been renamed to `hildon_window_get_main_menu() <hildon-window-get-main-menu>`_ for consistency





``self``:
  a :class:`HildonWindow`


*Returns*:
  a :class:`GtkMenu`


.. _hildon-window-add-toolbar:

.. function:: hildon_window_add_toolbar ()

::

  void                hildon_window_add_toolbar           (HildonWindow *self,
                                                           GtkToolbar *toolbar);

Adds a toolbar to the window. Note that the toolbar is not automatically shown. You need to call `gtk_widget_show_all() <gtk-widget-show-all>`_ on it to make it visible. It's also possible to hide the toolbar (without removing it) by calling `gtk_widget_hide() <gtk-widget-hide>`_



``self``:
  A :class:`HildonWindow`


``toolbar``:
  A :class:`GtkToolbar` to add to the :class:`HildonWindow`


.. _hildon-window-remove-toolbar:

.. function:: hildon_window_remove_toolbar ()

::

  void                hildon_window_remove_toolbar        (HildonWindow *self,
                                                           GtkToolbar *toolbar);

Removes a toolbar from the window. Note that this decreases the refference count on the widget. If you want to keep the toolbar alive call `g_object_ref() <g-object-ref>`_ before calling this function.



``self``:
  A :class:`HildonWindow`


``toolbar``:
  A :class:`GtkToolbar` to remove from the :class:`HildonWindow`


.. _hildon-window-set-edit-toolbar:

.. function:: hildon_window_set_edit_toolbar ()

::

  void                hildon_window_set_edit_toolbar      (HildonWindow *self,
                                                           HildonEditToolbar *toolbar);

Adds a :class:`HildonEditToolbar` to the window. Note that the toolbar is not automatically shown. You need to call `gtk_widget_show() <gtk-widget-show>`_ on it to make it visible. It's also possible to hide the toolbar (without removing it) by calling `gtk_widget_hide() <gtk-widget-hide>`_ .

A window can only have at most one edit toolbar at a time, so the previous toolbar (if any) is replaced after calling this function.



``self``:
  A :class:`HildonWindow`


``toolbar``:
  A :class:`HildonEditToolbar` , or ```NULL`` <NULL:CAPS>`_ to remove the current one.


Since 2.2

.. _hildon-window-get-is-topmost:

.. function:: hildon_window_get_is_topmost ()

::

  bool            hildon_window_get_is_topmost        (HildonWindow *self);

Returns whether the :class:`HildonWindow` is currenty activated by the window manager.



``self``:
  A :class:`HildonWindow`


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ if ``self`` is currently activated, ```FALSE`` <FALSE:CAPS>`_ otherwise.


.. _hildon-window-set-markup:

.. function:: hildon_window_set_markup ()

::

  void                hildon_window_set_markup            (HildonWindow *window,
                                                           const gchar *markup);

Sets the marked up title of ``window``. The accepted format is the one used in Pango (see :class:`PangoMarkupFormat` ) with the exception of span.

Note that you need support from the window manager for this title to be used. See `gtk_window_set_title() <gtk-window-set-title>`_ for the standard way of setting the title of a window.



``window``:
  a :class:`HildonWindow`


``markup``:
  the marked up title of the window, or ```NULL`` <NULL:CAPS>`_ to unset the current one


Since 2.2

.. _hildon-window-get-markup:

.. function:: hildon_window_get_markup ()

::

  const str        hildon_window_get_markup            (HildonWindow *window);

Gets the marked up title of the window title. See `hildon_window_set_markup() <hildon-window-set-markup>`_



``window``:
  a :class:`HildonWindow`


*Returns*:
  the marked up title of the window, or ```NULL`` <NULL:CAPS>`_ if none has been set explicitely. The returned string is owned by the widget and must not be modified or freed.


Since 2.2

.. _HildonWindow.property-details:

Property Details
================

.. _HildonWindow--is-topmost:

The ``is-topmost`` property

::

    is-topmost               bool              : Read

Whether the window is currently activated by the window manager.

Default value: FALSE

.. _HildonWindow--markup:

The ``markup`` property

::

    markup                   str                : Read / Write

Marked up text for the window title.

Default value: NULL

.. _HildonWindow.style-property-details:

Style Property Details
======================

.. _HildonWindow--borders:

The ``borders`` style property

::

    borders                  GtkBorder*            : Read

Size of graphical window borders.

.. _HildonWindow--toolbar-borders:

The ``toolbar-borders`` style property

::

    toolbar-borders          GtkBorder*            : Read

Size of graphical toolbar borders.

.. _HildonWindow.signal-details:

Signal Details
==============

.. _HildonWindow-clipboard-operation:

The ``clipboard-operation`` signal

::

  void                user_function                      (HildonWindow *hildonwindow,
                                                          int          arg1,
                                                          gpointer      user_data)         : Run First



``hildonwindow``:
  the object which received the signal.


``arg1``:
  


``user_data``:
  user data set when the signal handler was connected.


.. _HildonWindow.see-also:

See Also
========

:class:`HildonProgram` :class:`HildonStackableWindow` .. _HildonStackableWindow:

HildonStackableWindow
*********************

.. _HildonStackableWindow.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkWindow
                                         +----HildonWindow
                                               +----HildonStackableWindow
  

.. _HildonStackableWindow.implemented-interfaces:

Implemented Interfaces
======================

HildonStackableWindow implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonStackableWindow.description:

Description
===========

The :class:`HildonStackableWindow` is a GTK+ widget which represents a top-level window in the Hildon framework. It is derived from :class:`HildonWindow` . Applications that use stackable windows are organized in a hierarchical way so users can go from any window back to the application's root window.

The user can only see and interact with the window on top of the stack. Although all other windows are mapped and visible, they are obscured by the topmost one so in practice they appear as if they were hidden.

To add a window to the stack, just use `gtk_widget_show() <gtk-widget-show>`_ . The previous one will be obscured by the new one. When the new window is destroyed, the previous one will appear again.

Alternatively, you can remove a window from the top of the stack without destroying it by using `hildon_window_stack_pop() <hildon-window-stack-pop>`_ . The window will be automatically hidden and the previous one will appear.

For advanced details on stack handling, see :class:`HildonWindowStack`

Basic HildonStackableWindow example =================================== :: static void show_new_window (void) { GtkWidget *win; win = hildon_stackable_window_new (); // ... configure new window gtk_widget_show (win); } int main (int argc, char **argv) { GtkWidget *win; GtkWidget *button; gtk_init (argc, args); win = hildon_stackable_window_new (); gtk_window_set_title (GTK_WINDOW (win), "Main window); // ... add some widgets to the window g_signal_connect (button, "clicked", G_CALLBACK (show_new_window), NULL); g_signal_connect (win, "destroy", G_CALLBACK (gtk_main_quit), NULL); gtk_widget_show_all (win); gtk_main (); return 0; }



.. _HildonStackableWindow.details:

Details
=======

.. _HildonStackableWindow-struct:

.. class:: HildonStackableWindow

::

  typedef struct _HildonStackableWindow HildonStackableWindow;



.. _hildon-stackable-window-new:

.. function:: hildon_stackable_window_new ()

::

  GtkWidget*          hildon_stackable_window_new         (void);

Creates a new :class:`HildonStackableWindow` .



*Returns*:
  A :class:`HildonStackableWindow`


Since 2.2

.. _hildon-stackable-window-get-stack:

.. function:: hildon_stackable_window_get_stack ()

::

  HildonWindowStack*  hildon_stackable_window_get_stack   (HildonStackableWindow *self);

Returns the stack where window ``self`` is on, or ```NULL`` <NULL:CAPS>`_ if the window is not stacked.



``self``:
  a :class:`HildonStackableWindow`


*Returns*:
  a :class:`HildonWindowStack` , or ```NULL`` <NULL:CAPS>`_


Since 2.2

.. _hildon-stackable-window-set-main-menu:

.. function:: hildon_stackable_window_set_main_menu ()

::

  void                hildon_stackable_window_set_main_menu
                                                          (HildonStackableWindow *self,
                                                           HildonAppMenu *menu);

.. warning:: ``hildon_stackable_window_set_main_menu`` is deprecated and should not be used in newly-written code. Hildon 2.2: use :meth:`HildonWindow.set_app_menu`





``self``:
  a :class:`HildonStackableWindow`


``menu``:
  a :class:`HildonAppMenu` to be used for this window


.. _HildonStackableWindow.see-also:

See Also
========

:class:`HildonWindowStack` :class:`HildonProgram` :class:`HildonWindow` .. _HildonWindowStack:

HildonWindowStack
*****************

.. _HildonWindowStack.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----HildonWindowStack
  

.. _HildonWindowStack.properties:

Properties
==========

::

  
    window-group             GtkWindowGroup*       : Read / Write / Construct Only
  

.. _HildonWindowStack.description:

Description
===========

The :class:`HildonWindowStack` is an object used to represent a stack of windows in the Hildon framework.

Stacks contain all :class:`HildonStackableWindow` s that are being shown. The user can only interact with the topmost window from each stack (as it covers all the others), but all of them are mapped and visible from the Gtk point of view.

Each window can only be in one stack at a time. All stacked windows are visible and all visible windows are stacked.

Each application has a default stack, and windows are automatically added to it when they are shown with `gtk_widget_show() <gtk-widget-show>`_ .

Additional stacks can be created at any time using `hildon_window_stack_new() <hildon-window-stack-new>`_ . To add a window to a specific stack, use `hildon_window_stack_push_1() <hildon-window-stack-push-1>`_ (remember that, for the default stack, `gtk_widget_show() <gtk-widget-show>`_ can be used instead).

To remove a window from a stack use `hildon_window_stack_pop_1() <hildon-window-stack-pop-1>`_ , or simply `gtk_widget_hide() <gtk-widget-hide>`_ .

For more complex layout changes, applications can push and/or pop several windows at the same time in a single step. See `hildon_window_stack_push() <hildon-window-stack-push>`_ , `hildon_window_stack_pop() <hildon-window-stack-pop>`_ and `hildon_window_stack_pop_and_push() <hildon-window-stack-pop-and-push>`_ for more details.



.. _HildonWindowStack.details:

Details
=======

.. _HildonWindowStack-struct:

.. class:: HildonWindowStack

::

  typedef struct _HildonWindowStack HildonWindowStack;



.. _hildon-window-stack-get-default:

.. function:: hildon_window_stack_get_default ()

::

  HildonWindowStack*  hildon_window_stack_get_default     (void);

Returns the default window stack. This stack always exists and doesn't need to be created by the application.



*Returns*:
  the default :class:`HildonWindowStack`


Since 2.2

.. _hildon-window-stack-new:

.. function:: hildon_window_stack_new ()

::

  HildonWindowStack*  hildon_window_stack_new             (void);

Creates a new :class:`HildonWindowStack` . The stack is initially empty.



*Returns*:
  a new :class:`HildonWindowStack`


Since 2.2

.. _hildon-window-stack-size:

.. function:: hildon_window_stack_size ()

::

  int                hildon_window_stack_size            (HildonWindowStack *stack);

Returns the number of windows in ``stack``



``stack``:
  A :class:`HildonWindowStack`


*Returns*:
  Number of windows in ``stack``\


Since 2.2

.. _hildon-window-stack-get-windows:

.. function:: hildon_window_stack_get_windows ()

::

  GList*              hildon_window_stack_get_windows     (HildonWindowStack *stack);

Returns the list of windows on this stack (topmost first). The widgets in the list are not individually referenced. Once you are done with the list you must call `g_list_free() <g-list-free>`_ .



``stack``:
  a :class:`HildonWindowStack`


*Returns*:
  a newly-allocated list of :class:`HildonStackableWindow` s


Since 2.2

.. _hildon-window-stack-peek:

.. function:: hildon_window_stack_peek ()

::

  GtkWidget*          hildon_window_stack_peek            (HildonWindowStack *stack);

Returns the window on top of ``stack``. The stack is never modified.



``stack``:
  A ```HildonWindowStack`` <HildonWindowStack>`_


*Returns*:
  the window on top of the stack, or ```NULL`` <NULL:CAPS>`_ if the stack is empty.


Since 2.2

.. _hildon-window-stack-push:

.. function:: hildon_window_stack_push ()

::

  void                hildon_window_stack_push            (HildonWindowStack *stack,
                                                           HildonStackableWindow *win1,
                                                           ...);

Pushes all windows to the top of ``stack``, and shows them. Everything is done in a single transition, so the user will only see the last window. None of the windows must be already stacked.



``stack``:
  A ```HildonWindowStack`` <HildonWindowStack>`_


``win1``:
  The first window to push


``...``:
  A ```NULL`` <NULL:CAPS>`_ -terminated list of additional :class:`HildonStackableWindow` s to push.


Since 2.2

.. _hildon-window-stack-push-list:

.. function:: hildon_window_stack_push_list ()

::

  void                hildon_window_stack_push_list       (HildonWindowStack *stack,
                                                           GList *list);

Pushes all windows in ``list`` to the top of ``stack``, and shows them. Everything is done in a single transition, so the user will only see the last window in ``list`` during this operation. None of the windows must be already stacked.



``stack``:
  A ```HildonWindowStack`` <HildonWindowStack>`_


``list``:
  A list of ```HildonStackableWindow`` <HildonStackableWindow>`_ s to push


Since 2.2

.. _hildon-window-stack-push-1:

.. function:: hildon_window_stack_push_1 ()

::

  void                hildon_window_stack_push_1          (HildonWindowStack *stack,
                                                           HildonStackableWindow *win);

Adds ``win`` to the top of ``stack``, and shows it. The window must not be already stacked.



``stack``:
  A ```HildonWindowStack`` <HildonWindowStack>`_


``win``:
  A ```HildonStackableWindow`` <HildonStackableWindow>`_


Since 2.2

.. _hildon-window-stack-pop:

.. function:: hildon_window_stack_pop ()

::

  void                hildon_window_stack_pop             (HildonWindowStack *stack,
                                                           int nwindows,
                                                           GList **popped_windows);

Pops ``nwindows`` windows from ``stack``, and hides them. Everything is done in a single transition, so the user will not see any of the windows being popped in this operation.

If ``popped_windows`` is not ```NULL`` <NULL:CAPS>`_ , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.



``stack``:
  A ```HildonWindowStack`` <HildonWindowStack>`_


``nwindows``:
  Number of windows to pop


``popped_windows``:
  if non-```NULL`` <NULL:CAPS>`_ , the list of popped windows is stored here


Since 2.2

.. _hildon-window-stack-pop-1:

.. function:: hildon_window_stack_pop_1 ()

::

  GtkWidget*          hildon_window_stack_pop_1           (HildonWindowStack *stack);

Removes the window on top of ``stack``, and hides it. If the stack is empty nothing happens.



``stack``:
  A ```HildonWindowStack`` <HildonWindowStack>`_


*Returns*:
  the window on top of the stack, or ```NULL`` <NULL:CAPS>`_ if the stack is empty.


Since 2.2

.. _hildon-window-stack-pop-and-push:

.. function:: hildon_window_stack_pop_and_push ()

::

  void                hildon_window_stack_pop_and_push    (HildonWindowStack *stack,
                                                           int nwindows,
                                                           GList **popped_windows,
                                                           HildonStackableWindow *win1,
                                                           ...);

Pops ``nwindows`` windows from ``stack`` (and hides them), then pushes all passed windows (and shows them). Everything is done in a single transition, so the user will only see the last pushed window. None of the pushed windows must be already stacked.

If ``popped_windows`` is not ```NULL`` <NULL:CAPS>`_ , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.



``stack``:
  A ```HildonWindowStack`` <HildonWindowStack>`_


``nwindows``:
  Number of windows to pop.


``popped_windows``:
  if non-```NULL`` <NULL:CAPS>`_ , the list of popped windows is stored here


``win1``:
  The first window to push


``...``:
  A ```NULL`` <NULL:CAPS>`_ -terminated list of additional :class:`HildonStackableWindow` s to push.


Since 2.2

.. _hildon-window-stack-pop-and-push-list:

.. function:: hildon_window_stack_pop_and_push_list ()

::

  void                hildon_window_stack_pop_and_push_list
                                                          (HildonWindowStack *stack,
                                                           int nwindows,
                                                           GList **popped_windows,
                                                           GList *list);

Pops ``nwindows`` windows from ``stack`` (and hides them), then pushes all windows in ``list`` (and shows them). Everything is done in a single transition, so the user will only see the last window from ``list``. None of the pushed windows must be already stacked.

If ``popped_windows`` is not ```NULL`` <NULL:CAPS>`_ , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.



``stack``:
  A ```HildonWindowStack`` <HildonWindowStack>`_


``nwindows``:
  Number of windows to pop.


``popped_windows``:
  if non-```NULL`` <NULL:CAPS>`_ , the list of popped windows is stored here


``list``:
  A list of ```HildonStackableWindow`` <HildonStackableWindow>`_ s to push


Since 2.2

.. _HildonWindowStack.property-details:

Property Details
================

.. _HildonWindowStack--window-group:

The ``window-group`` property

::

    window-group             GtkWindowGroup*       : Read / Write / Construct Only

GtkWindowGroup that all windows on this stack belong to.

.. _HildonWindowStack.see-also:

See Also
========

:class:`HildonStackableWindow` .. _HildonButton:

HildonButton
************

.. _HildonButton.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkButton
                                         +----HildonButton
                                               +----HildonPickerButton
  

.. _HildonButton.implemented-interfaces:

Implemented Interfaces
======================

HildonButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonButton.properties:

Properties
==========

::

  
    arrangement              HildonButtonArrangement  : Write / Construct Only
    size                     HildonSizeType        : Write / Construct Only
    style                    HildonButtonStyle     : Read / Write
    title                    str                : Read / Write
    value                    str                : Read / Write
  

.. _HildonButton.style-properties:

Style Properties
================

::

  
    horizontal-spacing       int                 : Read
    vertical-spacing         int                 : Read
  

.. _HildonButton.description:

Description
===========

The :class:`HildonButton` is a GTK widget which represents a clickable button. It is derived from the :class:`GtkButton` widget and provides additional commodities specific to the Hildon framework.

The height of a :class:`HildonButton` can be set to either "finger" height or "thumb" height. It can also be configured to use halfscreen or fullscreen width. Alternatively, either dimension can be set to "auto" so it behaves like a standard :class:`GtkButton` .

The :class:`HildonButton` can hold any valid child widget, but it usually contains two labels, named title and value, and it can also contain an image. The contents of the button are packed together inside a :class:`GtkAlignment` and they do not expand by default (they don't use the full space of the button).

To change the alignment of both labels, use `gtk_button_set_alignment() <gtk-button-set-alignment>`_

To make them expand and use the full space of the button, use `hildon_button_set_alignment() <hildon-button-set-alignment>`_ .

To change the relative alignment of each label, use `hildon_button_set_title_alignment() <hildon-button-set-title-alignment>`_ and `hildon_button_set_value_alignment() <hildon-button-set-value-alignment>`_ .

In hildon-button-example.c included in the Hildon distribution you can see examples of how to create the most common button layouts.

If only one label is needed, :class:`GtkButton` can be used as well, see also `hildon_gtk_button_new() <hildon-gtk-button-new>`_ .

Creating a HildonButton ======================= :: void button_clicked (HildonButton *button, gpointer user_data) { const gchar *title, *value; title = hildon_button_get_title (button); value = hildon_button_get_value (button); g_debug ("Button clicked with title 's' and value 's'", title, value); } GtkWidget * create_button (void) { GtkWidget *button; GtkWidget *image; button = hildon_button_new (HILDON_SIZE_AUTO_WIDTH | HILDON_SIZE_FINGER_HEIGHT, HILDON_BUTTON_ARRANGEMENT_VERTICAL); hildon_button_set_text (HILDON_BUTTON (button), "Some title", "Some value"); image = gtk_image_new_from_stock (GTK_STOCK_INFO, GTK_ICON_SIZE_BUTTON); hildon_button_set_image (HILDON_BUTTON (button), image); hildon_button_set_image_position (HILDON_BUTTON (button), GTK_POS_RIGHT); gtk_button_set_alignment (GTK_BUTTON (button), 0.0, 0.5); g_signal_connect (button, "clicked", G_CALLBACK (button_clicked), NULL); return button; }



.. _HildonButton.details:

Details
=======

.. _HildonButton-struct:

.. class:: HildonButton

::

  typedef struct _HildonButton HildonButton;



.. _HildonButtonArrangement:

.. :: enum HildonButtonArrangement

::

  typedef enum {
     HILDON_BUTTON_ARRANGEMENT_HORIZONTAL,
     HILDON_BUTTON_ARRANGEMENT_VERTICAL
  }                                               HildonButtonArrangement;
  

Describes the arrangement of labels inside a :class:`HildonButton`



``HILDON_BUTTON_ARRANGEMENT_HORIZONTAL``
  Labels are arranged from left to right


``HILDON_BUTTON_ARRANGEMENT_VERTICAL``
  Labels are arranged from top to bottom


.. _HildonButtonStyle:

.. :: enum HildonButtonStyle

::

  typedef enum {
     HILDON_BUTTON_STYLE_NORMAL,
     HILDON_BUTTON_STYLE_PICKER
  }                                               HildonButtonStyle;
  

Describes the visual style of a :class:`HildonButton`



``HILDON_BUTTON_STYLE_NORMAL``
  The button will look like a normal :class:`HildonButton`


``HILDON_BUTTON_STYLE_PICKER``
  The button will look like a :class:`HildonPickerButton`


.. _hildon-button-new:

.. function:: hildon_button_new ()

::

  GtkWidget*          hildon_button_new                   (HildonSizeType size,
                                                           HildonButtonArrangement arrangement);

Creates a new :class:`HildonButton` . To set text in the labels, use `hildon_button_set_title() <hildon-button-set-title>`_ and `hildon_button_set_value() <hildon-button-set-value>`_ . Alternatively, you can add a custom child widget using `gtk_container_add() <gtk-container-add>`_ .



``size``:
  Flags to set the size of the button.


``arrangement``:
  How the labels must be arranged.


*Returns*:
  a new :class:`HildonButton`


Since 2.2

.. _hildon-button-new-with-text:

.. function:: hildon_button_new_with_text ()

::

  GtkWidget*          hildon_button_new_with_text         (HildonSizeType size,
                                                           HildonButtonArrangement arrangement,
                                                           const gchar *title,
                                                           const gchar *value);

Creates a new :class:`HildonButton` with two labels, ``title`` and ``value``.

If you just don't want to use one of the labels, set it to ```NULL`` <NULL:CAPS>`_ . You can set it to a non-```NULL`` <NULL:CAPS>`_ value at any time later using `hildon_button_set_title() <hildon-button-set-title>`_ or `hildon_button_set_value() <hildon-button-set-value>`_ .



``size``:
  Flags to set the size of the button.


``arrangement``:
  How the labels must be arranged.


``title``:
  Title of the button (main label), or ```NULL`` <NULL:CAPS>`_


``value``:
  Value of the button (secondary label), or ```NULL`` <NULL:CAPS>`_


*Returns*:
  a new :class:`HildonButton`


Since 2.2

.. _hildon-button-set-title:

.. function:: hildon_button_set_title ()

::

  void                hildon_button_set_title             (HildonButton *button,
                                                           const gchar *title);

Sets the title (main label) of ``button`` to ``title``.

This will clear any previously set title.

If ``title`` is set to ```NULL`` <NULL:CAPS>`_ , the title label will be hidden and the value label will be realigned.



``button``:
  a :class:`HildonButton`


``title``:
  a new title (main label) for the button, or ```NULL`` <NULL:CAPS>`_


Since 2.2

.. _hildon-button-set-value:

.. function:: hildon_button_set_value ()

::

  void                hildon_button_set_value             (HildonButton *button,
                                                           const gchar *value);

Sets the value (secondary label) of ``button`` to ``value``.

This will clear any previously set value.

If ``value`` is set to ```NULL`` <NULL:CAPS>`_ , the value label will be hidden and the title label will be realigned.



``button``:
  a :class:`HildonButton`


``value``:
  a new value (secondary label) for the button, or ```NULL`` <NULL:CAPS>`_


Since 2.2

.. _hildon-button-get-title:

.. function:: hildon_button_get_title ()

::

  const str        hildon_button_get_title             (HildonButton *button);

Fetches the text from the main label (title) of ``button``, as set by `hildon_button_set_title() <hildon-button-set-title>`_ or `hildon_button_set_text() <hildon-button-set-text>`_ . If the label text has not been set the return value will be ```NULL`` <NULL:CAPS>`_ . This will be the case if you create an empty button with `hildon_button_new() <hildon-button-new>`_ to use as a container.



``button``:
  a :class:`HildonButton`


*Returns*:
  The text of the title label. This string is owned by the widget and must not be modified or freed.


Since 2.2

.. _hildon-button-get-value:

.. function:: hildon_button_get_value ()

::

  const str        hildon_button_get_value             (HildonButton *button);

Fetches the text from the secondary label (value) of ``button``, as set by `hildon_button_set_value() <hildon-button-set-value>`_ or `hildon_button_set_text() <hildon-button-set-text>`_ . If the label text has not been set the return value will be ```NULL`` <NULL:CAPS>`_ . This will be the case if you create an empty button with `hildon_button_new() <hildon-button-new>`_ to use as a container.



``button``:
  a :class:`HildonButton`


*Returns*:
  The text of the value label. This string is owned by the widget and must not be modified or freed.


Since 2.2

.. _hildon-button-set-text:

.. function:: hildon_button_set_text ()

::

  void                hildon_button_set_text              (HildonButton *button,
                                                           const gchar *title,
                                                           const gchar *value);

Convenience function to change both labels of a :class:`HildonButton`



``button``:
  a :class:`HildonButton`


``title``:
  new text for the button title (main label)


``value``:
  new text for the button value (secondary label)


Since 2.2

.. _hildon-button-set-image:

.. function:: hildon_button_set_image ()

::

  void                hildon_button_set_image             (HildonButton *button,
                                                           GtkWidget *image);

Sets the image of ``button`` to the given widget. The previous image (if any) will be removed.



``button``:
  a :class:`HildonButton`


``image``:
  a widget to set as the button image


Since 2.2

.. _hildon-button-get-image:

.. function:: hildon_button_get_image ()

::

  GtkWidget*          hildon_button_get_image             (HildonButton *button);

Gets the widget that is currenty set as the image of ``button``, previously set with `hildon_button_set_image() <hildon-button-set-image>`_



``button``:
  a :class:`HildonButton`


*Returns*:
  a :class:`GtkWidget` or ```NULL`` <NULL:CAPS>`_ in case there is no image


Since 2.2

.. _hildon-button-set-image-position:

.. function:: hildon_button_set_image_position ()

::

  void                hildon_button_set_image_position    (HildonButton *button,
                                                           GtkPositionType position);

Sets the position of the image inside ``button``. Only ```GTK_POS_LEFT`` <GTK-POS-LEFT:CAPS>`_ and ```GTK_POS_RIGHT`` <GTK-POS-RIGHT:CAPS>`_ are currently supported.



``button``:
  a :class:`HildonButton`


``position``:
  the position of the image (```GTK_POS_LEFT`` <GTK-POS-LEFT:CAPS>`_ or ```GTK_POS_RIGHT`` <GTK-POS-RIGHT:CAPS>`_ )


Since 2.2

.. _hildon-button-set-alignment:

.. function:: hildon_button_set_alignment ()

::

  void                hildon_button_set_alignment         (HildonButton *button,
                                                           gfloat xalign,
                                                           gfloat yalign,
                                                           gfloat xscale,
                                                           gfloat yscale);

Sets the alignment of the contents of the widget. If you don't need to change ``xscale`` or ``yscale`` you can just use `gtk_button_set_alignment() <gtk-button-set-alignment>`_ instead.

Note that for this method to work properly the, child widget of ``button`` must be a :class:`GtkAlignment` . That's what :class:`HildonButton` uses by default, so this function will work unless you add a custom widget to ``button``.



``button``:
  a :class:`HildonButton`


``xalign``:
  the horizontal alignment of the contents, from 0 (left) to 1 (right).


``yalign``:
  the vertical alignment of the contents, from 0 (top) to 1 (bottom).


``xscale``:
  the amount that the child widget expands horizontally to fill up unused space, from 0 to 1


``yscale``:
  the amount that the child widget expands vertically to fill up unused space, from 0 to 1


Since 2.2

.. _hildon-button-set-title-alignment:

.. function:: hildon_button_set_title_alignment ()

::

  void                hildon_button_set_title_alignment   (HildonButton *button,
                                                           gfloat xalign,
                                                           gfloat yalign);

Sets the alignment of the title label. See also `hildon_button_set_alignment() <hildon-button-set-alignment>`_ to set the alignment of the whole contents of the button.



``button``:
  a :class:`HildonButton`


``xalign``:
  the horizontal alignment of the title label, from 0 (left) to 1 (right).


``yalign``:
  the vertical alignment of the title label, from 0 (top) to 1 (bottom).


Since 2.2

.. _hildon-button-set-value-alignment:

.. function:: hildon_button_set_value_alignment ()

::

  void                hildon_button_set_value_alignment   (HildonButton *button,
                                                           gfloat xalign,
                                                           gfloat yalign);

Sets the alignment of the value label. See also `hildon_button_set_alignment() <hildon-button-set-alignment>`_ to set the alignment of the whole contents of the button.



``button``:
  a :class:`HildonButton`


``xalign``:
  the horizontal alignment of the value label, from 0 (left) to 1 (right).


``yalign``:
  the vertical alignment of the value label, from 0 (top) to 1 (bottom).


Since 2.2

.. _hildon-button-set-image-alignment:

.. function:: hildon_button_set_image_alignment ()

::

  void                hildon_button_set_image_alignment   (HildonButton *button,
                                                           gfloat xalign,
                                                           gfloat yalign);

Sets the alignment of the image. See also `hildon_button_set_alignment() <hildon-button-set-alignment>`_ to set the alignment of the whole contents of the button.



``button``:
  a :class:`HildonButton`


``xalign``:
  the horizontal alignment of the image, from 0 (left) to 1 (right).


``yalign``:
  the vertical alignment of the image, from 0 (top) to 1 (bottom).


Since 2.2

.. _hildon-button-add-title-size-group:

.. function:: hildon_button_add_title_size_group ()

::

  void                hildon_button_add_title_size_group  (HildonButton *button,
                                                           GtkSizeGroup *size_group);

Adds the title label of ``button`` to ``size_group``.



``button``:
  a :class:`HildonButton`


``size_group``:
  A :class:`GtkSizeGroup` for the button title (main label)


Since 2.2

.. _hildon-button-add-value-size-group:

.. function:: hildon_button_add_value_size_group ()

::

  void                hildon_button_add_value_size_group  (HildonButton *button,
                                                           GtkSizeGroup *size_group);

Adds the value label of ``button`` to ``size_group``.



``button``:
  a :class:`HildonButton`


``size_group``:
  A :class:`GtkSizeGroup` for the button value (secondary label)


Since 2.2

.. _hildon-button-add-image-size-group:

.. function:: hildon_button_add_image_size_group ()

::

  void                hildon_button_add_image_size_group  (HildonButton *button,
                                                           GtkSizeGroup *size_group);

Adds the image of ``button`` to ``size_group``. You must add an image using `hildon_button_set_image() <hildon-button-set-image>`_ before calling this function.



``button``:
  a :class:`HildonButton`


``size_group``:
  A :class:`GtkSizeGroup` for the button image


Since 2.2

.. _hildon-button-add-size-groups:

.. function:: hildon_button_add_size_groups ()

::

  void                hildon_button_add_size_groups       (HildonButton *button,
                                                           GtkSizeGroup *title_size_group,
                                                           GtkSizeGroup *value_size_group,
                                                           GtkSizeGroup *image_size_group);

Convenience function to add title, value and image to size groups. ```NULL`` <NULL:CAPS>`_ size groups will be ignored.



``button``:
  a :class:`HildonButton`


``title_size_group``:
  A :class:`GtkSizeGroup` for the button title (main label), or ```NULL`` <NULL:CAPS>`_


``value_size_group``:
  A :class:`GtkSizeGroup` group for the button value (secondary label), or ```NULL`` <NULL:CAPS>`_


``image_size_group``:
  A :class:`GtkSizeGroup` group for the button image, or ```NULL`` <NULL:CAPS>`_


Since 2.2

.. _hildon-button-set-style:

.. function:: hildon_button_set_style ()

::

  void                hildon_button_set_style             (HildonButton *button,
                                                           HildonButtonStyle style);

Sets the style of ``button`` to ``style``. This changes the visual appearance of the button (colors, font sizes) according to the particular style chosen, but the general layout is not altered.

Use ```HILDON_BUTTON_STYLE_NORMAL`` <HILDON-BUTTON-STYLE-NORMAL:CAPS>`_ to make it look like a normal :class:`HildonButton` , or ```HILDON_BUTTON_STYLE_PICKER`` <HILDON-BUTTON-STYLE-PICKER:CAPS>`_ to make it look like a :class:`HildonPickerButton` .



``button``:
  A :class:`HildonButton`


``style``:
  A :class:`HildonButtonStyle` for ``button``\


Since 2.2

.. _hildon-button-get-style:

.. function:: hildon_button_get_style ()

::

  HildonButtonStyle   hildon_button_get_style             (HildonButton *button);

Gets the visual style of the button.



``button``:
  A :class:`HildonButton`


*Returns*:
  a :class:`HildonButtonStyle`


Since 2.2

.. _HildonButton.property-details:

Property Details
================

.. _HildonButton--arrangement:

The ``arrangement`` property

::

    arrangement              HildonButtonArrangement  : Write / Construct Only

How the button contents must be arranged.

Default value: HILDON_BUTTON_ARRANGEMENT_HORIZONTAL

.. _HildonButton--size:

The ``size`` property

::

    size                     HildonSizeType        : Write / Construct Only

Size request for the button.

.. _HildonButton--style:

The ``style`` property

::

    style                    HildonButtonStyle     : Read / Write

Visual style of the button.

Default value: HILDON_BUTTON_STYLE_NORMAL

.. _HildonButton--title:

The ``title`` property

::

    title                    str                : Read / Write

Text of the title label inside the button.

Default value: NULL

.. _HildonButton--value:

The ``value`` property

::

    value                    str                : Read / Write

Text of the value label inside the button.

Default value: NULL

.. _HildonButton.style-property-details:

Style Property Details
======================

.. _HildonButton--horizontal-spacing:

The ``horizontal-spacing`` style property

::

    horizontal-spacing       int                 : Read

Horizontal spacing between the title and value labels, when in horizontal mode.

Default value: 25

.. _HildonButton--vertical-spacing:

The ``vertical-spacing`` style property

::

    vertical-spacing         int                 : Read

Vertical spacing between the title and value labels, when in vertical mode.

Default value: 5

.. _HildonCheckButton:

HildonCheckButton
*****************

.. _HildonCheckButton.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkButton
                                         +----HildonCheckButton
  

.. _HildonCheckButton.implemented-interfaces:

Implemented Interfaces
======================

HildonCheckButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonCheckButton.style-properties:

Style Properties
================

::

  
    checkbox-size            int                 : Read
  

.. _HildonCheckButton.signals:

Signals
=======

::

  
    toggled                                        : Run First
  

.. _HildonCheckButton.description:

Description
===========

:class:`HildonCheckButton` is a button containing a label and a check box which will remain 'pressed-in' when clicked. Clicking again will make the check box toggle its state.

The state of a :class:`HildonCheckButton` can be set using `hildon_check_button_set_active() <hildon-check-button-set-active>`_ , and retrieved using `hildon_check_button_get_active() <hildon-check-button-get-active>`_ . The label can be set using `gtk_button_set_label() <gtk-button-set-label>`_ and retrieved using `gtk_button_get_label() <gtk-button-get-label>`_ .

.. note:: :class:`HildonCheckButton` does NOT support an image, so don't use `gtk_button_set_image() <gtk-button-set-image>`_ .

Using a Hildon check button =========================== :: void button_toggled (HildonCheckButton *button, gpointer user_data) { bool active; active = hildon_check_button_get_active (button); if (active) g_debug ("Button is active"); else g_debug ("Button is not active"); } GtkWidget * create_button (void) { GtkWidget *button; button = hildon_check_button_new (HILDON_SIZE_AUTO); gtk_button_set_label (GTK_BUTTON (button), "Click me"); g_signal_connect (button, "toggled", G_CALLBACK (button_toggled), NULL); return button; }



.. _HildonCheckButton.details:

Details
=======

.. _HildonCheckButton-struct:

.. class:: HildonCheckButton

::

  typedef struct _HildonCheckButton HildonCheckButton;



.. _hildon-check-button-new:

.. function:: hildon_check_button_new ()

::

  GtkWidget*          hildon_check_button_new             (HildonSizeType size);

Creates a new :class:`HildonCheckButton` .



``size``:
  Flags indicating the size of the new button


*Returns*:
  A newly created :class:`HildonCheckButton`


Since 2.2

.. _hildon-check-button-set-active:

.. function:: hildon_check_button_set_active ()

::

  void                hildon_check_button_set_active      (HildonCheckButton *button,
                                                           bool is_active);

Sets the status of a :class:`HildonCheckButton` . Set to ```TRUE`` <TRUE:CAPS>`_ if you want ``button`` to be 'pressed-in', and ```FALSE`` <FALSE:CAPS>`_ to raise it. This action causes the `"toggled" <HildonCheckButton-toggled>`_ signal to be emitted.



``button``:
  A :class:`HildonCheckButton`


``is_active``:
  new state for the button


Since 2.2

.. _hildon-check-button-get-active:

.. function:: hildon_check_button_get_active ()

::

  bool            hildon_check_button_get_active      (HildonCheckButton *button);

Gets the current state of ``button``.



``button``:
  A :class:`HildonCheckButton`


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ if ``button`` is active, ```FALSE`` <FALSE:CAPS>`_ otherwise.


Since 2.2

.. _hildon-check-button-toggled:

.. function:: hildon_check_button_toggled ()

::

  void                hildon_check_button_toggled         (HildonCheckButton *button);

Emits the `"toggled" <HildonCheckButton-toggled>`_ signal on the :class:`HildonCheckButton` . There is no good reason for an application ever to call this function.



``button``:
  A :class:`HildonCheckButton`


Since 2.2

.. _HildonCheckButton.style-property-details:

Style Property Details
======================

.. _HildonCheckButton--checkbox-size:

The ``checkbox-size`` style property

::

    checkbox-size            int                 : Read

Size of the check box.

Default value: 26

.. _HildonCheckButton.signal-details:

Signal Details
==============

.. _HildonCheckButton-toggled:

The ``toggled`` signal

::

  void                user_function                      (HildonCheckButton *arg0,
                                                          gpointer           user_data)      : Run First

Emitted when the :class:`HildonCheckButton` 's state is changed.



``user_data``:
  user data set when the signal handler was connected.


Since 2.2

.. _HildonPickerButton:

HildonPickerButton
******************

.. _HildonPickerButton.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkButton
                                         +----HildonButton
                                               +----HildonPickerButton
                                                     +----HildonDateButton
                                                     +----HildonTimeButton
  

.. _HildonPickerButton.implemented-interfaces:

Implemented Interfaces
======================

HildonPickerButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonPickerButton.properties:

Properties
==========

::

  
    done-button-text         str                : Read / Write
    touch-selector           HildonTouchSelector*  : Read / Write
  

.. _HildonPickerButton.signals:

Signals
=======

::

  
    value-changed                                  : Run Last / Action
  

.. _HildonPickerButton.description:

Description
===========

:class:`HildonPickerButton` is a widget that lets the user select a particular item from a list. Visually, it's a button with title and value labels that brings up a :class:`HildonPickerDialog` . The user can then use this dialog to choose an item, which will be displayed in the value label of the button.

You should create your own :class:`HildonTouchSelector` at convenience and set it to the :class:`HildonPickerButton` with `hildon_picker_button_set_selector() <hildon-picker-button-set-selector>`_ . For the common use cases of buttons to select date and time, you can use :class:`HildonDateButton` and :class:`HildonTimeButton` .

:: GtkWidget * create_selector (void) { GtkWidget *selector; selector = hildon_touch_selector_new_text (); hildon_touch_selector_append_text (HILDON_TOUCH_SELECTOR (selector), "America"); hildon_touch_selector_append_text (HILDON_TOUCH_SELECTOR (selector), "Europe"); hildon_touch_selector_append_text (HILDON_TOUCH_SELECTOR (selector), "Asia"); hildon_touch_selector_append_text (HILDON_TOUCH_SELECTOR (selector), "Africa"); hildon_touch_selector_append_text (HILDON_TOUCH_SELECTOR (selector), "Australia"); hildon_touch_selector_set_active (HILDON_TOUCH_SELECTOR (selector), 0, 2); return selector; } GtkWidget * create_button (HildonTouchSelector *selector) { GtkWidget *button; button = hildon_picker_button_new (HILDON_SIZE_AUTO, HILDON_BUTTON_ARRANGEMENT_VERTICAL); hildon_button_set_title (HILDON_BUTTON (button), "Continent"); hildon_picker_button_set_selector (HILDON_PICKER_BUTTON (button), HILDON_TOUCH_SELECTOR (selector)); return button; }



.. _HildonPickerButton.details:

Details
=======

.. _HildonPickerButton-struct:

.. class:: HildonPickerButton

::

  typedef struct _HildonPickerButton HildonPickerButton;



.. _hildon-picker-button-new:

.. function:: hildon_picker_button_new ()

::

  GtkWidget*          hildon_picker_button_new            (HildonSizeType size,
                                                           HildonButtonArrangement arrangement);

Creates a new :class:`HildonPickerButton` . See `hildon_button_new() <hildon-button-new>`_ for details on the parameters.



``size``:
  One of :class:`HildonSizeType` , specifying the size of the new button.


``arrangement``:
  one of :class:`HildonButtonArrangement` , specifying the placement of the labels.


*Returns*:
  a newly created :class:`HildonPickerButton`


Since 2.2

.. _hildon-picker-button-set-selector:

.. function:: hildon_picker_button_set_selector ()

::

  void                hildon_picker_button_set_selector   (HildonPickerButton *button,
                                                           HildonTouchSelector *selector);

Sets ``selector`` as the :class:`HildonTouchSelector` to be shown in the :class:`HildonPickerDialog` that ``button`` brings up.



``button``:
  a :class:`HildonPickerButton`


``selector``:
  a :class:`HildonTouchSelector`


Since 2.2

.. _hildon-picker-button-get-selector:

.. function:: hildon_picker_button_get_selector ()

::

  HildonTouchSelector* hildon_picker_button_get_selector  (HildonPickerButton *button);

Retrieves the :class:`HildonTouchSelector` associated to ``button``.



``button``:
  a :class:`HildonPickerButton`


*Returns*:
  a :class:`HildonTouchSelector`


Since 2.2

.. _hildon-picker-button-set-active:

.. function:: hildon_picker_button_set_active ()

::

  void                hildon_picker_button_set_active     (HildonPickerButton *button,
                                                           int index);

Sets the active item of the :class:`HildonTouchSelector` associated to ``button`` to ``index``. If the selector has several columns, only the first one is used.



``button``:
  a :class:`HildonPickerButton`


``index``:
  the index of the item to select, or -1 to have no active item


Since 2.2

.. _hildon-picker-button-get-active:

.. function:: hildon_picker_button_get_active ()

::

  int                hildon_picker_button_get_active     (HildonPickerButton *button);

Returns the index of the currently active item, or -1 if there's no active item. If the selector has several columns, only the first one is used.



``button``:
  a :class:`HildonPickerButton`


*Returns*:
  an integer which is the index of the currently active item, or -1 if there's no active item.


Since 2.2

.. _hildon-picker-button-get-done-button-text:

.. function:: hildon_picker_button_get_done_button_text ()

::

  const str        hildon_picker_button_get_done_button_text
                                                          (HildonPickerButton *button);

Gets the text used in the :class:`HildonPickerDialog` that is launched by ``button``. If no custom text is set, then ```NULL`` <NULL:CAPS>`_ is returned.



``button``:
  a :class:`HildonPickerButton`


*Returns*:
  the custom string to be used, or ```NULL`` <NULL:CAPS>`_ if the default `"done-button-text" <HildonPickerDialog-done-button-text>`_ is to be used.


Since 2.2

.. _hildon-picker-button-set-done-button-text:

.. function:: hildon_picker_button_set_done_button_text ()

::

  void                hildon_picker_button_set_done_button_text
                                                          (HildonPickerButton *button,
                                                           const gchar *done_button_text);

Sets a custom string to be used in the "done" button in :class:`HildonPickerDialog` . If unset, the default HildonPickerButton::done-button-text property value will be used.



``button``:
  a :class:`HildonPickerButton`


``done_button_text``:
  a string


Since 2.2

.. _hildon-picker-button-value-changed:

.. function:: hildon_picker_button_value_changed ()

::

  void                hildon_picker_button_value_changed  (HildonPickerButton *button);

Emits a "`"value-changed" <HildonPickerButton-value-changed>`_ " signal to the given :class:`HildonPickerButton`



``button``:
  a :class:`HildonPickerButton`


Since 2.2

.. _HildonPickerButton.property-details:

Property Details
================

.. _HildonPickerButton--done-button-text:

The ``done-button-text`` property

::

    done-button-text         str                : Read / Write

The text for the "done" button in the dialog launched.

Default value: NULL

.. _HildonPickerButton--touch-selector:

The ``touch-selector`` property

::

    touch-selector           HildonTouchSelector*  : Read / Write

HildonTouchSelector widget to be launched on button clicked.

.. _HildonPickerButton.signal-details:

Signal Details
==============

.. _HildonPickerButton-value-changed:

The ``value-changed`` signal

::

  void                user_function                      (HildonPickerButton *widget,
                                                          gpointer            user_data)      : Run Last / Action

The ::value-changed signal is emitted each time the user chooses a different item from the :class:`HildonTouchSelector` related, and the value label gets updated.



``widget``:
  the widget that received the signal


``user_data``:
  user data set when the signal handler was connected.


Since 2.2

.. _HildonPickerButton.see-also:

See Also
========

:class:`HildonTouchSelector` :class:`HildonPickerDialog` .. _HildonDateButton:

HildonDateButton
****************

.. _HildonDateButton.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkButton
                                         +----HildonButton
                                               +----HildonPickerButton
                                                     +----HildonDateButton
  

.. _HildonDateButton.implemented-interfaces:

Implemented Interfaces
======================

HildonDateButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonDateButton.description:

Description
===========

:class:`HildonDateButton` is a widget that shows a text label and a date, and allows the user to select a different date. Visually, it's a button that, once clicked, presents a :class:`HildonPickerDialog` containing a :class:`HildonDateSelector` . Once the user selects a different date from the selector, this will be shown in the button.



.. _HildonDateButton.details:

Details
=======

.. _HildonDateButton-struct:

.. class:: HildonDateButton

::

  typedef struct _HildonDateButton HildonDateButton;



.. _hildon-date-button-new:

.. function:: hildon_date_button_new ()

::

  GtkWidget*          hildon_date_button_new              (HildonSizeType size,
                                                           HildonButtonArrangement arrangement);

Creates a new :class:`HildonDateButton` . See `hildon_button_new() <hildon-button-new>`_ for details on the parameters.



``size``:
  One of :class:`HildonSizeType`


``arrangement``:
  one of :class:`HildonButtonArrangement`


*Returns*:
  a new :class:`HildonDateButton`


Since 2.2

.. _hildon-date-button-new-with-year-range:

.. function:: hildon_date_button_new_with_year_range ()

::

  GtkWidget*          hildon_date_button_new_with_year_range
                                                          (HildonSizeType size,
                                                           HildonButtonArrangement arrangement,
                                                           int min_year,
                                                           int max_year);

Creates a new :class:`HildonDateButton` with a specific valid range of years. See `hildon_date_selector_new_with_year_range() <hildon-date-selector-new-with-year-range>`_ for details on the range.



``size``:
  One of :class:`HildonSizeType`


``arrangement``:
  one of :class:`HildonButtonArrangement`


``min_year``:
  the minimum available year or -1 to ignore


``max_year``:
  the maximum available year or -1 to ignore


*Returns*:
  a new :class:`HildonDateButton`


Since 2.2

.. _hildon-date-button-get-date:

.. function:: hildon_date_button_get_date ()

::

  void                hildon_date_button_get_date         (HildonDateButton *button,
                                                           int *year,
                                                           int *month,
                                                           int *day);

Retrieves currently selected date from ``button``.



``button``:
  a :class:`HildonDateButton`


``year``:
  return location for the selected year


``month``:
  return location for the selected month


``day``:
  return location for the selected day


Since 2.2

.. _hildon-date-button-set-date:

.. function:: hildon_date_button_set_date ()

::

  void                hildon_date_button_set_date         (HildonDateButton *button,
                                                           int year,
                                                           int month,
                                                           int day);

Sets the date in ``button``. The date set will be displayed and will be the default selected option on the shown :class:`HildonDateSelector` .



``button``:
  a :class:`HildonDateButton`


``year``:
  the year to set.


``month``:
  the month number to set.


``day``:
  the day of the month to set.


Since 2.2

.. _HildonDateButton.see-also:

See Also
========

:class:`HildonPickerButton` :class:`HildonTimeButton` .. _HildonTimeButton:

HildonTimeButton
****************

.. _HildonTimeButton.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkButton
                                         +----HildonButton
                                               +----HildonPickerButton
                                                     +----HildonTimeButton
  

.. _HildonTimeButton.implemented-interfaces:

Implemented Interfaces
======================

HildonTimeButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonTimeButton.description:

Description
===========

:class:`HildonTimeButton` is a widget that shows a text label and a time, and allows the user to select a different time. Visually, it's a button that, once clicked, presents a :class:`HildonPickerDialog` containing a :class:`HildonTimeSelector` . Once the user selects a different time from the selector, this will be shown in the button.



.. _HildonTimeButton.details:

Details
=======

.. _HildonTimeButton-struct:

.. class:: HildonTimeButton

::

  typedef struct _HildonTimeButton HildonTimeButton;



.. _hildon-time-button-new:

.. function:: hildon_time_button_new ()

::

  GtkWidget*          hildon_time_button_new              (HildonSizeType size,
                                                           HildonButtonArrangement arrangement);

Creates a new :class:`HildonTimeButton` . See `hildon_button_new() <hildon-button-new>`_ for details on the parameters.



``size``:
  One of :class:`HildonSizeType`


``arrangement``:
  one of :class:`HildonButtonArrangement`


*Returns*:
  a new :class:`HildonTimeButton`


Since 2.2

.. _hildon-time-button-new-step:

.. function:: hildon_time_button_new_step ()

::

  GtkWidget*          hildon_time_button_new_step         (HildonSizeType size,
                                                           HildonButtonArrangement arrangement,
                                                           int minutes_step);

Creates a new :class:`HildonTimeButton` . See `hildon_button_new() <hildon-button-new>`_ for details on the parameters.



``size``:
  One of :class:`HildonSizeType`


``arrangement``:
  one of :class:`HildonButtonArrangement`


``minutes_step``:
  step between the minutes in the selector options


*Returns*:
  a new :class:`HildonTimeButton`


Since 2.2

.. _hildon-time-button-get-time:

.. function:: hildon_time_button_get_time ()

::

  void                hildon_time_button_get_time         (HildonTimeButton *button,
                                                           int *hours,
                                                           int *minutes);

Retrieves the time from ``button``.



``button``:
  a :class:`HildonTimeButton`


``hours``:
  return location for the hours of the time selected


``minutes``:
  return location for the minutes of the time selected


Since 2.2

.. _hildon-time-button-set-time:

.. function:: hildon_time_button_set_time ()

::

  void                hildon_time_button_set_time         (HildonTimeButton *button,
                                                           int hours,
                                                           int minutes);

Sets the time to be displayed in ``button``. This time will be selected by default on the :class:`HildonTimeSelector` .



``button``:
  a :class:`HildonTimeButton`


``hours``:
  the hours to be set


``minutes``:
  the time to be set


Since 2.2

.. _HildonTimeButton.see-also:

See Also
========

:class:`HildonPickerButton` :class:`HildonDateButton` .. _HildonCaption:

HildonCaption
*************

.. _HildonCaption.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkEventBox
                                         +----HildonCaption
  

.. _HildonCaption.implemented-interfaces:

Implemented Interfaces
======================

HildonCaption implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonCaption.properties:

Properties
==========

::

  
    icon                     GtkWidget*            : Read / Write
    icon-position            HildonCaptionIconPosition  : Read / Write
    label                    str                : Read / Write
    markup                   str                : Write
    separator                str                : Read / Write
    size-group               GtkSizeGroup*         : Read / Write
    status                   HildonCaptionStatus   : Read / Write
  

.. _HildonCaption.child-properties:

Child Properties
================

::

  
    expand                   bool              : Read / Write
  

.. _HildonCaption.signals:

Signals
=======

::

  
    activate                                       : Run First / Action
  

.. _HildonCaption.description:

Description
===========

:class:`HildonCaption` is a single-child container widget that precedes the contained widget with a field label and an optional icon. It allows grouping of several controls together. When a captioned widget has focus, both widget and caption label are displayed with active focus.



.. _HildonCaption.details:

Details
=======

.. _HildonCaptionStatus:

.. :: enum HildonCaptionStatus

::

  typedef enum
  {
      HILDON_CAPTION_OPTIONAL = 0,
      HILDON_CAPTION_MANDATORY
  }                                               HildonCaptionStatus;
  

Keys to set the :class:`HildonCaption` to be optional or mandatory.



``HILDON_CAPTION_OPTIONAL``
  Optional.


``HILDON_CAPTION_MANDATORY``
  Mandatory.


.. _HildonCaptionIconPosition:

.. :: enum HildonCaptionIconPosition

::

  typedef enum
  {
      HILDON_CAPTION_POSITION_LEFT = 0,
      HILDON_CAPTION_POSITION_RIGHT
  }                                               HildonCaptionIconPosition;
  

Keys to set the icon placement in :class:`HildonCaption` .



``HILDON_CAPTION_POSITION_LEFT``
  Show the icon on the left side.


``HILDON_CAPTION_POSITION_RIGHT``
  Show the icon on the right side.


.. _HildonCaption-struct:

.. class:: HildonCaption

::

  typedef struct _HildonCaption HildonCaption;



.. _hildon-caption-new:

.. function:: hildon_caption_new ()

::

  GtkWidget*          hildon_caption_new                  (GtkSizeGroup *group,
                                                           const gchar *value,
                                                           GtkWidget *control,
                                                           GtkWidget *icon,
                                                           HildonCaptionStatus flag);

Creates a new instance of hildon_caption widget, with a specific control and image. Note: Clicking on a focused caption will trigger the activate signal. The default behaviour for the caption's activate signal is to call gtk_widget_activate on it's control.



``group``:
  a :class:`GtkSizeGroup` for controlling the size of related captions, Can be NULL


``value``:
  the caption text to accompany the text entry. The widget makes a copy of this text.


``control``:
  the control that is to be captioned


``icon``:
  an icon to accompany the label - can be NULL in which case no icon is displayed


``flag``:
  indicates whether this captioned control is mandatory or optional


*Returns*:
  a :class:`GtkWidget` pointer of Caption


.. _hildon-caption-get-size-group:

.. function:: hildon_caption_get_size_group ()

::

  GtkSizeGroup*       hildon_caption_get_size_group       (const HildonCaption *caption);

Query given captioned control for the :class:`GtkSizeGroup` assigned to it.



``caption``:
  a :class:`HildonCaption`


*Returns*:
  a :class:`GtkSizeGroup`


.. _hildon-caption-set-size-group:

.. function:: hildon_caption_set_size_group ()

::

  void                hildon_caption_set_size_group       (const HildonCaption *caption,
                                                           GtkSizeGroup *new_group);

Sets a :class:`GtkSizeGroup` of a given captioned control.



``caption``:
  a :class:`HildonCaption`


``new_group``:
  a :class:`GtkSizeGroup`


.. _hildon-caption-is-mandatory:

.. function:: hildon_caption_is_mandatory ()

::

  bool            hildon_caption_is_mandatory         (const HildonCaption *caption);

Query :class:`HildonCaption` whether this captioned control is a mandatory one.



``caption``:
  a :class:`HildonCaption`


*Returns*:
  is this captioned control a mandatory one?


.. _hildon-caption-set-status:

.. function:: hildon_caption_set_status ()

::

  void                hildon_caption_set_status           (HildonCaption *caption,
                                                           HildonCaptionStatus flag);

Sets :class:`HildonCaption` status.



``caption``:
  a :class:`HildonCaption`


``flag``:
  one of the values from :class:`HildonCaptionStatus`


.. _hildon-caption-get-status:

.. function:: hildon_caption_get_status ()

::

  HildonCaptionStatus hildon_caption_get_status           (const HildonCaption *caption);

Gets :class:`HildonCaption` status.



``caption``:
  a :class:`HildonCaption`


*Returns*:
  one of the values from :class:`HildonCaptionStatus`


.. _hildon-caption-set-icon-position:

.. function:: hildon_caption_set_icon_position ()

::

  void                hildon_caption_set_icon_position    (HildonCaption *caption,
                                                           HildonCaptionIconPosition pos);

Sets :class:`HildonCaption` icon position.



``caption``:
  a :class:`HildonCaption`


``pos``:
  one of the values from :class:`HildonCaptionIconPosition`


.. _hildon-caption-get-icon-position:

.. function:: hildon_caption_get_icon_position ()

::

  HildonCaptionIconPosition hildon_caption_get_icon_position
                                                          (const HildonCaption *caption);

Gets :class:`HildonCaption` icon position.



``caption``:
  a :class:`HildonCaption`


*Returns*:
  one of the values from :class:`HildonCaptionIconPosition` .


.. _hildon-caption-set-icon-image:

.. function:: hildon_caption_set_icon_image ()

::

  void                hildon_caption_set_icon_image       (HildonCaption *caption,
                                                           GtkWidget *icon);

Sets the icon image widget to be used by this hildon_caption widget.



``caption``:
  a :class:`HildonCaption`


``icon``:
  the :class:`GtkImage` to use as the icon. calls gtk_widget_show on the icon if !GTK_WIDGET_VISIBLE(icon)


.. _hildon-caption-get-icon-image:

.. function:: hildon_caption_get_icon_image ()

::

  GtkWidget*          hildon_caption_get_icon_image       (const HildonCaption *caption);

Gets icon of :class:`HildonCaption`



``caption``:
  a :class:`HildonCaption`


*Returns*:
  the :class:`GtkImage` widget that is being used as the icon by the hildon_caption, or NULL if no icon image is in use.


.. _hildon-caption-set-label:

.. function:: hildon_caption_set_label ()

::

  void                hildon_caption_set_label            (HildonCaption *caption,
                                                           const gchar *label);

Sets the label text that appears before the control. Separator character is added to the end of the label string. By default the separator is ":".



``caption``:
  a :class:`HildonCaption`


``label``:
  the text to use


.. _hildon-caption-get-label:

.. function:: hildon_caption_get_label ()

::

  str              hildon_caption_get_label            (const HildonCaption *caption);

Gets label of :class:`HildonCaption`



``caption``:
  a :class:`HildonCaption`


*Returns*:
  the text currently being used as the label of the caption control. The string is owned by the label and the caller should never free or modify this value.


.. _hildon-caption-set-separator:

.. function:: hildon_caption_set_separator ()

::

  void                hildon_caption_set_separator        (HildonCaption *caption,
                                                           const gchar *separator);

Sets the separator character that appears after the label. The default seaparator character is ":" separately.



``caption``:
  a :class:`HildonCaption`


``separator``:
  the separator to use


.. _hildon-caption-get-separator:

.. function:: hildon_caption_get_separator ()

::

  str              hildon_caption_get_separator        (const HildonCaption *caption);

Gets separator string of :class:`HildonCaption`



``caption``:
  a :class:`HildonCaption`


*Returns*:
  the text currently being used as the separator of the caption control. The string is owned by the caption control and the caller should never free or modify this value.


.. _hildon-caption-set-label-alignment:

.. function:: hildon_caption_set_label_alignment ()

::

  void                hildon_caption_set_label_alignment  (HildonCaption *caption,
                                                           gfloat alignment);

Sets the vertical alignment to be used for the text part of the caption. Applications need to align the child control themselves.



``caption``:
  a :class:`HildonCaption` widget


``alignment``:
  new vertical alignment


.. _hildon-caption-get-label-alignment:

.. function:: hildon_caption_get_label_alignment ()

::

  gfloat              hildon_caption_get_label_alignment  (HildonCaption *caption);

Gets current vertical alignment for the text part.



``caption``:
  a :class:`HildonCaption` widget


*Returns*:
  vertical alignment


.. _hildon-caption-set-child-expand:

.. function:: hildon_caption_set_child_expand ()

::

  void                hildon_caption_set_child_expand     (HildonCaption *caption,
                                                           bool expand);

Sets child expandability.



``caption``:
  a :class:`HildonCaption`


``expand``:
  bool to determine if the child is expandable


.. _hildon-caption-get-child-expand:

.. function:: hildon_caption_get_child_expand ()

::

  bool            hildon_caption_get_child_expand     (const HildonCaption *caption);

Gets childs expandability.



``caption``:
  a :class:`HildonCaption`


*Returns*:
  wheter the child is expandable or not.


.. _hildon-caption-set-label-markup:

.. function:: hildon_caption_set_label_markup ()

::

  void                hildon_caption_set_label_markup     (HildonCaption *caption,
                                                           const gchar *markup);

Sets the label markup text that appears before the control. It acts like `hildon_caption_set_label <hildon-caption-set-label>`_ but is using the markup text that allows to specify text properties such as bold or italic.



``caption``:
  a :class:`HildonCaption`


``markup``:
  the markup text to use


.. _HildonCaption.property-details:

Property Details
================

.. _HildonCaption--icon:

The ``icon`` property

::

    icon                     GtkWidget*            : Read / Write

The icon shown on the caption area.



.. _HildonCaption--icon-position:

The ``icon-position`` property

::

    icon-position            HildonCaptionIconPosition  : Read / Write

If the icon is positioned on the left or right side.



Default value: HILDON_CAPTION_POSITION_RIGHT

.. _HildonCaption--label:

The ``label`` property

::

    label                    str                : Read / Write

Caption label.



Default value: NULL

.. _HildonCaption--markup:

The ``markup`` property

::

    markup                   str                : Write

Caption markup. Mutually exclusive with label.



Default value: NULL

.. _HildonCaption--separator:

The ``separator`` property

::

    separator                str                : Read / Write

The current separator.



Default value: "ecdg_ti_caption_separator"

.. _HildonCaption--size-group:

The ``size-group`` property

::

    size-group               GtkSizeGroup*         : Read / Write

Current size group the caption is in.

.. _HildonCaption--status:

The ``status`` property

::

    status                   HildonCaptionStatus   : Read / Write

Mandatory or optional status.



Default value: HILDON_CAPTION_OPTIONAL

.. _HildonCaption.child-property-details:

Child Property Details
======================

.. _HildonCaption--expand:

The ``expand`` child property

::

    expand                   bool              : Read / Write

Same as GtkBox expand. Wheter the child should be expanded or not.

Default value: FALSE

.. _HildonCaption.signal-details:

Signal Details
==============

.. _HildonCaption-activate:

The ``activate`` signal

::

  void                user_function                      (HildonCaption *hildoncaption,
                                                          gpointer       user_data)          : Run First / Action



``hildoncaption``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonBanner:

HildonBanner
************

.. _HildonBanner.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkWindow
                                         +----HildonBanner
  

.. _HildonBanner.implemented-interfaces:

Implemented Interfaces
======================

HildonBanner implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonBanner.properties:

Properties
==========

::

  
    is-timed                 bool              : Read / Write / Construct Only
    parent-window            GtkWindow*            : Read / Write / Construct Only
    timeout                  int                 : Read / Write / Construct Only
  

.. _HildonBanner.description:

Description
===========

:class:`HildonBanner` is a small, pop-up window that can be used to display a short, timed notification or information to the user. It can communicate that a task has been finished or that the application state has changed.

Hildon provides convenient funtions to create and show banners. To create and show information banners you can use `hildon_banner_show_information() <hildon-banner-show-information>`_ , `hildon_banner_show_informationf() <hildon-banner-show-informationf>`_ or `hildon_banner_show_information_with_markup() <hildon-banner-show-information-with-markup>`_ .

Two more kinds of banners are maintained for backward compatibility but are no longer recommended in Hildon 2.2. These are the animated banner (created with `hildon_banner_show_animation() <hildon-banner-show-animation>`_ ) and the progress banner (created with `hildon_banner_show_progress() <hildon-banner-show-progress>`_ ). See `hildon_gtk_window_set_progress_indicator() <hildon-gtk-window-set-progress-indicator>`_ for the preferred way of showing progress notifications in Hildon 2.2.

Information banners dissapear automatically after a certain period. This is stored in the `"timeout" <HildonBanner--timeout>`_ property (in miliseconds), and can be changed using `hildon_banner_set_timeout() <hildon-banner-set-timeout>`_ .

Note that :class:`HildonBanner` s should only be used to display non-critical pieces of information.



.. _HildonBanner.details:

Details
=======

.. _HildonBanner-struct:

.. class:: HildonBanner

::

  typedef struct _HildonBanner HildonBanner;



.. _hildon-banner-show-information:

.. function:: hildon_banner_show_information ()

::

  GtkWidget*          hildon_banner_show_information      (GtkWidget *widget,
                                                           const gchar *icon_name,
                                                           const gchar *text);

This function creates and displays an information banner that automatically goes away after certain time period. For each window in your application there can only be one timed banner, so if you spawn a new banner before the earlier one has timed out, the previous one will be replaced.



``widget``:
  the :class:`GtkWidget` that is the owner of the banner


``icon_name``:
  since Hildon 2.2 this parameter is not used anymore and any value that you pass will be ignored


``text``:
  Text to display


*Returns*:
  The newly created banner


.. _hildon-banner-show-informationf:

.. function:: hildon_banner_show_informationf ()

::

  GtkWidget*          hildon_banner_show_informationf     (GtkWidget *widget,
                                                           const gchar *icon_name,
                                                           const gchar *format,
                                                           ...);

A helper function for `hildon_banner_show_information <hildon-banner-show-information>`_ with string formatting.



``widget``:
  the :class:`GtkWidget` that is the owner of the banner


``icon_name``:
  since Hildon 2.2 this parameter is not used anymore and any value that you pass will be ignored


``format``:
  a printf-like format string


``...``:
  arguments for the format string


*Returns*:
  the newly created banner


.. _hildon-banner-show-information-with-markup:

.. function:: hildon_banner_show_information_with_markup ()

::

  GtkWidget*          hildon_banner_show_information_with_markup
                                                          (GtkWidget *widget,
                                                           const gchar *icon_name,
                                                           const gchar *markup);

This function creates and displays an information banner that automatically goes away after certain time period. For each window in your application there can only be one timed banner, so if you spawn a new banner before the earlier one has timed out, the previous one will be replaced.



``widget``:
  the :class:`GtkWidget` that wants to display banner


``icon_name``:
  since Hildon 2.2 this parameter is not used anymore and any value that you pass will be ignored


``markup``:
  a markup string to display (see `Pango markup format <PangoMarkupFormat>`_ )


*Returns*:
  the newly created banner


.. _hildon-banner-show-animation:

.. function:: hildon_banner_show_animation ()

::

  GtkWidget*          hildon_banner_show_animation        (GtkWidget *widget,
                                                           const gchar *animation_name,
                                                           const gchar *text);

.. warning:: ``hildon_banner_show_animation`` is deprecated and should not be used in newly-written code. Hildon 2.2: use `hildon_gtk_window_set_progress_indicator() <hildon-gtk-window-set-progress-indicator>`_ instead.

Shows an animated progress notification. It's recommended not to try to show more than one progress notification at a time, since they will appear on top of each other. You can use progress notifications with timed banners. In this case the banners are located so that you can somehow see both.

Please note that banners are destroyed automatically once the window they are attached to is closed. The pointer that you receive with this function does not contain additional references, so it can become invalid without warning (this is true for all toplevel windows in gtk). To make sure that the banner does not disappear automatically, you can separately ref the return value (this doesn't prevent the banner from disappearing, just the object from being finalized). In this case you have to call both `gtk_widget_destroy() <gtk-widget-destroy>`_ followed by `g_object_unref() <g-object-unref>`_ (in this order).



``widget``:
  the :class:`GtkWidget` that wants to display banner


``animation_name``:
  since Hildon 2.2 this parameter is not used anymore and any value that you pass will be ignored


``text``:
  the text to display.


*Returns*:
  a :class:`HildonBanner` widget. You must call `gtk_widget_destroy() <gtk-widget-destroy>`_ once you are done with the banner.


.. _hildon-banner-show-progress:

.. function:: hildon_banner_show_progress ()

::

  GtkWidget*          hildon_banner_show_progress         (GtkWidget *widget,
                                                           GtkProgressBar *bar,
                                                           const gchar *text);

.. warning:: ``hildon_banner_show_progress`` is deprecated and should not be used in newly-written code. Hildon 2.2: use `hildon_gtk_window_set_progress_indicator() <hildon-gtk-window-set-progress-indicator>`_ instead.

Shows progress notification. See `hildon_banner_show_animation <hildon-banner-show-animation>`_ for more information.



``widget``:
  the :class:`GtkWidget` that wants to display banner


``bar``:
  Progressbar to use. You usually can just pass ```NULL`` <NULL:CAPS>`_ , unless you want somehow customized progress bar.


``text``:
  text to display.


*Returns*:
  a :class:`HildonBanner` widget. You must call `gtk_widget_destroy <gtk-widget-destroy>`_ once you are done with the banner.


.. _hildon-banner-set-text:

.. function:: hildon_banner_set_text ()

::

  void                hildon_banner_set_text              (HildonBanner *self,
                                                           const gchar *text);

Sets the text that is displayed in the banner.



``self``:
  a :class:`HildonBanner` widget


``text``:
  a new text to display in banner


.. _hildon-banner-set-markup:

.. function:: hildon_banner_set_markup ()

::

  void                hildon_banner_set_markup            (HildonBanner *self,
                                                           const gchar *markup);

Sets the text with markup that is displayed in the banner.



``self``:
  a :class:`HildonBanner` widget


``markup``:
  a new text with Pango markup to display in the banner


.. _hildon-banner-set-fraction:

.. function:: hildon_banner_set_fraction ()

::

  void                hildon_banner_set_fraction          (HildonBanner *self,
                                                           gdouble fraction);

The fraction is the completion of progressbar, the scale is from 0.0 to 1.0. Sets the amount of fraction the progressbar has.

Note that this method only has effect if ``self`` was created with `hildon_banner_show_progress() <hildon-banner-show-progress>`_



``self``:
  a :class:`HildonBanner` widget


``fraction``:
  `gdouble <gdouble>`_


.. _hildon-banner-set-icon:

.. function:: hildon_banner_set_icon ()

::

  void                hildon_banner_set_icon              (HildonBanner *self,
                                                           const gchar *icon_name);

.. warning:: ``hildon_banner_set_icon`` is deprecated and should not be used in newly-written code. This function does nothing. As of hildon 2.2, hildon banners don't allow changing their icons.

Sets the icon to be used in the banner.



``self``:
  a :class:`HildonBanner` widget


``icon_name``:
  the name of icon to use. Can be ```NULL`` <NULL:CAPS>`_ for default icon


.. _hildon-banner-set-icon-from-file:

.. function:: hildon_banner_set_icon_from_file ()

::

  void                hildon_banner_set_icon_from_file    (HildonBanner *self,
                                                           const gchar *icon_file);

.. warning:: ``hildon_banner_set_icon_from_file`` is deprecated and should not be used in newly-written code. This function does nothing. As of hildon 2.2, hildon banners don't allow changing their icons.

Sets the icon from its filename to be used in the banner.



``self``:
  a :class:`HildonBanner` widget


``icon_file``:
  the filename of icon to use. Can be ```NULL`` <NULL:CAPS>`_ for default icon


.. _hildon-banner-set-timeout:

.. function:: hildon_banner_set_timeout ()

::

  void                hildon_banner_set_timeout           (HildonBanner *self,
                                                           int timeout);

Sets the timeout on the banner. After the given amount of miliseconds has elapsed the banner will go away. Note that settings this only makes sense on the banners that are timed and that have not been yet displayed on the screen.

Note that this method only has effect if ``self`` is an information banner (created using `hildon_banner_show_information() <hildon-banner-show-information>`_ and friends).



``self``:
  a :class:`HildonBanner` widget


``timeout``:
  timeout to set in miliseconds.


.. _HildonBanner.property-details:

Property Details
================

.. _HildonBanner--is-timed:

The ``is-timed`` property

::

    is-timed                 bool              : Read / Write / Construct Only

Whether the banner is timed and goes away automatically.



Default value: FALSE

.. _HildonBanner--parent-window:

The ``parent-window`` property

::

    parent-window            GtkWindow*            : Read / Write / Construct Only

The window for which the banner will be singleton.



.. _HildonBanner--timeout:

The ``timeout`` property

::

    timeout                  int                 : Read / Write / Construct Only

The time before making the banner banner go away. This needs to be adjusted before the banner is mapped to the screen.



Allowed values: = 10000

Default value: 3000

.. _HildonNote:

HildonNote
**********

.. _HildonNote.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkWindow
                                         +----GtkDialog
                                               +----HildonNote
  

.. _HildonNote.implemented-interfaces:

Implemented Interfaces
======================

HildonNote implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonNote.properties:

Properties
==========

::

  
    description              str                : Read / Write
    icon                     str                : Read / Write
    note-type                HildonNoteType        : Read / Write / Construct
    progressbar              GtkProgressBar*       : Read / Write
    stock-icon               str                : Read / Write
  

.. _HildonNote.description:

Description
===========

:class:`HildonNote` is a convenient way to prompt users for a small amount of input. A simple note contains an information text and, in case of confirmation notes, it shows buttons to confirm or cancel. It also can include a progress bar.

This widget provides convenient functions to create either information notes, confirmation notes or cancel notes, which are useful to show the progress of a requested task allowing the user to cancel it.

To create information notes you can use `hildon_note_new_information() <hildon-note-new-information>`_ . `hildon_note_new_confirmation() <hildon-note-new-confirmation>`_ creates a note with a text and two buttons to confirm or cancel. Note that it is possible to create a confirmation note with customized buttons by using `hildon_note_new_confirmation_add_buttons() <hildon-note-new-confirmation-add-buttons>`_ .

To create a note with a text, a progress bar and cancel button, `hildon_note_new_cancel_with_progress_bar() <hildon-note-new-cancel-with-progress-bar>`_ can be used.

HildonNote example ================== :: bool show_confirmation_note (GtkWindow *parent) { int retcode; GtkWidget *note; note = hildon_note_new_confirmation (parent, "Confirmation message..."); retcode = gtk_dialog_run (GTK_DIALOG (note)); gtk_widget_destroy (note); if (retcode == GTK_RESPONSE_OK) { g_debug ("User pressed 'OK' button'"); return TRUE; } else { g_debug ("User pressed 'Cancel' button"); return FALSE; } }



.. _HildonNote.details:

Details
=======

.. _HildonNote-struct:

.. class:: HildonNote

::

  typedef struct _HildonNote HildonNote;



.. _hildon-note-new-confirmation:

.. function:: hildon_note_new_confirmation ()

::

  GtkWidget*          hildon_note_new_confirmation        (GtkWindow *parent,
                                                           const gchar *description);

Create a new confirmation note. Confirmation note has a text (description) that you specify and two buttons.



``parent``:
  the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly. In GTK the X window ID can be checked using GDK_WINDOW_XID(GTK_WIDGET(parent)->window).


``description``:
  the message to confirm


*Returns*:
  a :class:`GtkWidget` pointer of the note


.. _hildon-note-new-confirmation-add-buttons:

.. function:: hildon_note_new_confirmation_add_buttons ()

::

  GtkWidget*          hildon_note_new_confirmation_add_buttons
                                                          (GtkWindow *parent,
                                                           const gchar *description,
                                                           ...);

Create a new confirmation note with custom buttons. Confirmation note has a text and any number of buttons. It's important to note that even though the name of the function might suggest, the default ok/cancel buttons are not appended but you have to provide all of the buttons.

FIXME: This doc seems to be wrong, the two buttons aren't added so it would only contain the "additional" buttons? However, changing this would break those applications that rely on current behaviour.



``parent``:
  the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly. In GTK the X window ID can be checked using GDK_WINDOW_XID(GTK_WIDGET(parent)->window).


``description``:
  the message to confirm


``...``:
  arguments pairs for new buttons(label and return value). Terminate the list with ```NULL`` <NULL:CAPS>`_ value.


*Returns*:
  A :class:`GtkWidget` pointer of the note


.. _hildon-note-new-confirmation-with-icon-name:

.. function:: hildon_note_new_confirmation_with_icon_name ()

::

  GtkWidget*          hildon_note_new_confirmation_with_icon_name
                                                          (GtkWindow *parent,
                                                           const gchar *description,
                                                           const gchar *icon_name);

.. warning:: ``hildon_note_new_confirmation_with_icon_name`` is deprecated and should not be used in newly-written code. Since 2.2, icons are not shown in confirmation notes. Icons set with this function will be ignored. Use `hildon_note_new_confirmation() <hildon-note-new-confirmation>`_ instead.

Create a new confirmation note. Confirmation note has a text (description) that you specify and two buttons.



``parent``:
  the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly. In GTK the X window ID can be checked using GDK_WINDOW_XID(GTK_WIDGET(parent)->window).


``description``:
  the message to confirm


``icon_name``:
  icon to be displayed. If NULL, default icon is used.


*Returns*:
  a :class:`GtkWidget` pointer of the note


.. _hildon-note-new-cancel-with-progress-bar:

.. function:: hildon_note_new_cancel_with_progress_bar ()

::

  GtkWidget*          hildon_note_new_cancel_with_progress_bar
                                                          (GtkWindow *parent,
                                                           const gchar *description,
                                                           GtkProgressBar *progressbar);

Create a new cancel note with a progress bar. Cancel note has text(description) that you specify, a Cancel button and a progress bar.



``parent``:
  the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly. In GTK the X window ID can be checked using GDK_WINDOW_XID(GTK_WIDGET(parent)->window).


``description``:
  the action to cancel


``progressbar``:
  a pointer to :class:`GtkProgressBar` to be filled with the progressbar assigned to this note. Use this to set the fraction of progressbar done. This parameter can be ```NULL`` <NULL:CAPS>`_ as well, in which case plain text cancel note appears.


*Returns*:
  a :class:`GtkDialog` . Use this to get rid of this note when you no longer need it.


.. _hildon-note-new-information:

.. function:: hildon_note_new_information ()

::

  GtkWidget*          hildon_note_new_information         (GtkWindow *parent,
                                                           const gchar *description);

Create a new information note. Information note has a text (description) that you specify and an OK button.



``parent``:
  the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly. In GTK the X window ID can be checked using GDK_WINDOW_XID(GTK_WIDGET(parent)->window).


``description``:
  the message to confirm


*Returns*:
  a :class:`GtkWidget` pointer of the note


.. _hildon-note-new-information-with-icon-name:

.. function:: hildon_note_new_information_with_icon_name ()

::

  GtkWidget*          hildon_note_new_information_with_icon_name
                                                          (GtkWindow *parent,
                                                           const gchar *description,
                                                           const gchar *icon_name);

.. warning:: ``hildon_note_new_information_with_icon_name`` is deprecated and should not be used in newly-written code. Since 2.2, icons are not shown in confirmation notes. Icons set with this function will be ignored. Use `hildon_note_new_information() <hildon-note-new-information>`_ instead.

Create a new information note. Information note has text(description) that you specify, an OK button and an icon.



``parent``:
  the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly. In GTK the X window ID can be checked using GDK_WINDOW_XID(GTK_WIDGET(parent)->window).


``description``:
  the message to confirm


``icon_name``:
  icon to be displayed. If NULL, default icon is used.


*Returns*:
  a :class:`GtkWidget` pointer of the note


.. _hildon-note-set-button-text:

.. function:: hildon_note_set_button_text ()

::

  void                hildon_note_set_button_text         (HildonNote *note,
                                                           const gchar *text);

Sets the button text to be used by the hildon_note widget.



``note``:
  a :class:`HildonNote`


``text``:
  sets the button text and if there is two buttons in dialog, the button texts will be text, "Cancel".


.. _hildon-note-set-button-texts:

.. function:: hildon_note_set_button_texts ()

::

  void                hildon_note_set_button_texts        (HildonNote *note,
                                                           const gchar *text_ok,
                                                           const gchar *text_cancel);

Sets the button texts to be used by this hildon_note widget.



``note``:
  a :class:`HildonNote`


``text_ok``:
  the new text of the default OK button


``text_cancel``:
  the new text of the default cancel button


.. _HildonNoteType:

.. :: enum HildonNoteType

::

  typedef enum
  {
      HILDON_NOTE_TYPE_CONFIRMATION = 0,
      HILDON_NOTE_TYPE_CONFIRMATION_BUTTON,
      HILDON_NOTE_TYPE_INFORMATION,
      HILDON_NOTE_TYPE_INFORMATION_THEME,
      HILDON_NOTE_TYPE_PROGRESSBAR
  }                                               HildonNoteType;
  



.. _HildonNote.property-details:

Property Details
================

.. _HildonNote--description:

The ``description`` property

::

    description              str                : Read / Write

Description for the note.



Default value: ""

.. _HildonNote--icon:

The ``icon`` property

::

    icon                     str                : Read / Write

Icon for the note.



Default value: ""

.. _HildonNote--note-type:

The ``note-type`` property

::

    note-type                HildonNoteType        : Read / Write / Construct

The type of the note dialog.

Default value: HILDON_NOTE_TYPE_CONFIRMATION

.. _HildonNote--progressbar:

The ``progressbar`` property

::

    progressbar              GtkProgressBar*       : Read / Write

Progressbar for the note (if any).



.. _HildonNote--stock-icon:

The ``stock-icon`` property

::

    stock-icon               str                : Read / Write

Stock icon name for the note.



Default value: ""

.. _HildonTouchSelector:

HildonTouchSelector
*******************

.. _HildonTouchSelector.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBox
                                   +----GtkVBox
                                         +----HildonTouchSelector
                                               +----HildonTouchSelectorEntry
                                               +----HildonTimeSelector
                                               +----HildonDateSelector
  

.. _HildonTouchSelector.implemented-interfaces:

Implemented Interfaces
======================

HildonTouchSelector implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonTouchSelector.properties:

Properties
==========

::

  
    has-multiple-selection   bool              : Read
    initial-scroll           bool              : Read / Write / Construct
  

.. _HildonTouchSelector.signals:

Signals
=======

::

  
    changed                                        : Run Last
    columns-changed                                : Run Last
  

.. _HildonTouchSelector.description:

Description
===========

:class:`HildonTouchSelector` is a selector widget, that allows users to select items from one to many predefined lists. It is very similar to :class:`GtkComboBox` , but with several individual pannable columns.

Normally, you would use :class:`HildonTouchSelector` together with a :class:`HildonPickerDialog` activated from a button. For the most common cases, you should use :class:`HildonPickerButton` .

The composition of each column in the selector is represented by a :class:`GtkTreeModel` . To add a new column to a :class:`HildonTouchSelector` , use `hildon_touch_selector_append_column() <hildon-touch-selector-append-column>`_ . If you want to add a text-only column, without special attributes, use `hildon_touch_selector_append_text_column() <hildon-touch-selector-append-text-column>`_ .

It is highly recommended that you use only one column :class:`HildonTouchSelector` s. If you only need a text only, one column selector, you can create it with `hildon_touch_selector_new_text() <hildon-touch-selector-new-text>`_ and populate with `hildon_touch_selector_append_text() <hildon-touch-selector-append-text>`_ , `hildon_touch_selector_prepend_text() <hildon-touch-selector-prepend-text>`_ , and `hildon_touch_selector_insert_text() <hildon-touch-selector-insert-text>`_ .

If you need a selector widget that also accepts user inputs, you can use :class:`HildonTouchSelectorEntry` .

The current selection has a string representation. In the most common cases, each column model will contain a text column. You can configure which column in particular using the :class:`HildonTouchSelectorColumn` property `"text-column" <HildonTouchSelectorColumn--text-column>`_

You can get this string representation using `hildon_touch_selector_get_current_text() <hildon-touch-selector-get-current-text>`_ . You can configure how the selection is printed with `hildon_touch_selector_set_print_func() <hildon-touch-selector-set-print-func>`_ , that sets the current hildon touch selector print function. The widget has a default print function, that uses the `"text-column" <HildonTouchSelectorColumn--text-column>`_ property on each :class:`HildonTouchSelectorColumn` to compose the final representation.

If you create the selector using `hildon_touch_selector_new_text() <hildon-touch-selector-new-text>`_ you don't need to take care of this property, as the model is created internally. If you create the selector using `hildon_touch_selector_new() <hildon-touch-selector-new>`_ , you need to specify properly the property for your custom model in order to get a non-empty string representation, or define your custom print function.

Creating a HildonTouchSelector ============================== :: void selection_changed (HildonTouchSelector * selector, gpointer *user_data) { gchar *current_selection = NULL; current_selection = hildon_touch_selector_get_current_text (selector); g_debug ("Current selection : s", current_selection); } static GtkWidget * create_customized_selector () { GtkWidget *selector = NULL; GSList *icon_list = NULL; GtkListStore *store_icons = NULL; GSList *item = NULL; GtkCellRenderer *renderer = NULL; HildonTouchSelectorColumn *column = NULL; selector = hildon_touch_selector_new (); icon_list = gtk_stock_list_ids (); store_icons = gtk_list_store_new (1, G_TYPE_STRING); for (item = icon_list; item; item = g_slist_next (item)) { GtkTreeIter iter; gchar *label = item->data; gtk_list_store_append (store_icons, iter); gtk_list_store_set (store_icons, iter, 0, label, -1); g_free (label); } g_slist_free (icon_list); renderer = gtk_cell_renderer_pixbuf_new (); gtk_cell_renderer_set_fixed_size (renderer, -1, 100); column = hildon_touch_selector_append_column (HILDON_TOUCH_SELECTOR (selector), GTK_TREE_MODEL (store_icons), renderer, "stock-id", 0, NULL); g_object_set (G_OBJECT (column), "text-column", 0, NULL); hildon_touch_selector_set_column_selection_mode (HILDON_TOUCH_SELECTOR (selector), HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE); g_signal_connect (G_OBJECT (selector), "changed", G_CALLBACK (selection_changed), NULL); return selector; } static GtkWidget * create_simple_selector () { GtkWidget *selector = NULL; int i; selector = hildon_touch_selector_new_text (); hildon_touch_selector_set_column_selection_mode (HILDON_TOUCH_SELECTOR (selector), HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE); g_signal_connect (G_OBJECT (selector), "changed", G_CALLBACK (selection_changed), NULL); for (i = 1; i = 10 ; i++) { gchar *label = g_strdup_printf ("Item percnt;d", i); hildon_touch_selector_append_text (HILDON_TOUCH_SELECTOR (selector), label); g_free (label); } return selector; }



.. _HildonTouchSelector.details:

Details
=======

.. _HildonTouchSelectorPrintFunc:

.. function:: HildonTouchSelectorPrintFunc ()

::

  str              (*HildonTouchSelectorPrintFunc)     (HildonTouchSelector *selector,
                                                           gpointer user_data);



``selector``:
  


``user_data``:
  


*Returns*:
  


.. _HildonTouchSelector-struct:

.. class:: HildonTouchSelector

::

  typedef struct _HildonTouchSelector HildonTouchSelector;



.. _HildonTouchSelectorSelectionMode:

.. :: enum HildonTouchSelectorSelectionMode

::

  typedef enum
  {
    HILDON_TOUCH_SELECTOR_SELECTION_MODE_SINGLE,
    HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE
  } HildonTouchSelectorSelectionMode;
  

Describes the selection mode of a :class:`HildonTouchSelector` .



``HILDON_TOUCH_SELECTOR_SELECTION_MODE_SINGLE``
  Users can select one item


``HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE``
  Users can select one to many items


.. _hildon-touch-selector-new:

.. function:: hildon_touch_selector_new ()

::

  GtkWidget*          hildon_touch_selector_new           (void);

Creates a new empty :class:`HildonTouchSelector` .



*Returns*:
  a new :class:`HildonTouchSelector` .


Since 2.2

.. _hildon-touch-selector-new-text:

.. function:: hildon_touch_selector_new_text ()

::

  GtkWidget*          hildon_touch_selector_new_text      (void);

Creates a :class:`HildonTouchSelector` with a single text column that can be populated conveniently through `hildon_touch_selector_append_text() <hildon-touch-selector-append-text>`_ , `hildon_touch_selector_prepend_text() <hildon-touch-selector-prepend-text>`_ , `hildon_touch_selector_insert_text() <hildon-touch-selector-insert-text>`_ .



*Returns*:
  A new :class:`HildonTouchSelector`


Since 2.2

.. _hildon-touch-selector-append-text:

.. function:: hildon_touch_selector_append_text ()

::

  void                hildon_touch_selector_append_text   (HildonTouchSelector *selector,
                                                           const gchar *text);

Appends a new entry in a :class:`HildonTouchSelector` created with `hildon_touch_selector_new_text() <hildon-touch-selector-new-text>`_ .



``selector``:
  A :class:`HildonTouchSelector` .


``text``:
  a non ```NULL`` <NULL:CAPS>`_ text string.


Since 2.2

.. _hildon-touch-selector-prepend-text:

.. function:: hildon_touch_selector_prepend_text ()

::

  void                hildon_touch_selector_prepend_text  (HildonTouchSelector *selector,
                                                           const gchar *text);

Prepends a new entry in a :class:`HildonTouchSelector` created with `hildon_touch_selector_new_text() <hildon-touch-selector-new-text>`_ .



``selector``:
  A :class:`HildonTouchSelector` .


``text``:
  a non ```NULL`` <NULL:CAPS>`_ text string.


Since 2.2

.. _hildon-touch-selector-insert-text:

.. function:: hildon_touch_selector_insert_text ()

::

  void                hildon_touch_selector_insert_text   (HildonTouchSelector *selector,
                                                           int position,
                                                           const gchar *text);

Inserts a new entry in a particular position of a :class:`HildonTouchSelector` created with `hildon_touch_selector_new_text() <hildon-touch-selector-new-text>`_ .



``selector``:
  a :class:`HildonTouchSelector` .


``position``:
  the position to insert ``text``.


``text``:
  A non ```NULL`` <NULL:CAPS>`_ text string.


Since 2.2

.. _hildon-touch-selector-append-text-column:

.. function:: hildon_touch_selector_append_text_column ()

::

  HildonTouchSelectorColumn* hildon_touch_selector_append_text_column
                                                          (HildonTouchSelector *selector,
                                                           GtkTreeModel *model,
                                                           bool center);

Equivalent to `hildon_touch_selector_append_column() <hildon-touch-selector-append-column>`_ , but using a default text cell renderer. This is the most common use case of the widget.



``selector``:
  a :class:`HildonTouchSelector`


``model``:
  a :class:`GtkTreeModel` with data for the column


``center``:
  whether to center the text on the column


*Returns*:
  the new column added, NULL otherwise.


Since 2.2

.. _hildon-touch-selector-append-column:

.. function:: hildon_touch_selector_append_column ()

::

  HildonTouchSelectorColumn* hildon_touch_selector_append_column
                                                          (HildonTouchSelector *selector,
                                                           GtkTreeModel *model,
                                                           GtkCellRenderer *cell_renderer,
                                                           ...);

This functions adds a new column to the widget, whose data will be obtained from the model. Only widgets added this way should used on the selection logic, i.e., the print function, the `"changed" <HildonTouchPicker-changed>`_ signal, etc.

You can optionally pass a :class:`GtkCellRenderer` in ``cell_renderer``, together with a ```NULL`` <NULL:CAPS>`_ -terminated list of pairs property/value, in the same way you would use `gtk_tree_view_column_set_attributes() <gtk-tree-view-column-set-attributes>`_ . This will pack ``cell_renderer`` at the start of the column, expanded by default. If you prefer not to add it this way, you can simply pass ```NULL`` <NULL:CAPS>`_ to ``cell_renderer``\ and use the :class:`GtkCellLayout` interface on the returned :class:`HildonTouchSelectorColumn` to set your renderers.

There is a prerequisite to be considered on models used: text data must be in the first column.

This method basically adds a :class:`GtkTreeView` to the widget, using the model and the data received.



``selector``:
  a :class:`HildonTouchSelector`


``model``:
  the :class:`GtkTreeModel` with the data of the column


``cell_renderer``:
  The :class:`GtkCellRenderer` where to draw each row contents.


``...``:
  a ```NULL`` <NULL:CAPS>`_ -terminated pair of attributes and column numbers.


*Returns*:
  the new column added added, ```NULL`` <NULL:CAPS>`_ otherwise.


Since 2.2

.. _hildon-touch-selector-set-column-attributes:

.. function:: hildon_touch_selector_set_column_attributes ()

::

  void                hildon_touch_selector_set_column_attributes
                                                          (HildonTouchSelector *selector,
                                                           int num_column,
                                                           GtkCellRenderer *cell_renderer,
                                                           ...);

.. warning:: ``hildon_touch_selector_set_column_attributes`` is deprecated and should not be used in newly-written code. :class:`HildonTouchSelectorColumn` implements :class:`GtkCellLayout` , use this interface instead. See `hildon_touch_selector_get_column() <hildon-touch-selector-get-column>`_ .

Sets the attributes for the given column. The attributes must be given in attribute/column pairs, just like in `gtk_tree_view_column_set_attributes() <gtk-tree-view-column-set-attributes>`_ . All existing attributes are removed and replaced with the new ones.



``selector``:
  a :class:`HildonTouchSelector`


``num_column``:
  the number of the column whose attributes we're setting


``cell_renderer``:
  the :class:`GtkCellRendere` we're setting the attributes of


``...``:
  A ```NULL`` <NULL:CAPS>`_ -terminated list of attributes.


Since 2.2

.. _hildon-touch-selector-remove-column:

.. function:: hildon_touch_selector_remove_column ()

::

  bool            hildon_touch_selector_remove_column (HildonTouchSelector *selector,
                                                           int column);

Removes a column from ``selector``.



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the position of the column to be removed


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ if the column was removed, ```FALSE`` <FALSE:CAPS>`_ otherwise


Since 2.2

.. _hildon-touch-selector-get-num-columns:

.. function:: hildon_touch_selector_get_num_columns ()

::

  int                hildon_touch_selector_get_num_columns
                                                          (HildonTouchSelector *selector);

Gets the number of columns in the :class:`HildonTouchSelector` .



``selector``:
  a :class:`HildonTouchSelector`


*Returns*:
  the number of columns in ``selector``.


Since 2.2

.. _hildon-touch-selector-set-column-selection-mode:

.. function:: hildon_touch_selector_set_column_selection_mode ()

::

  void                hildon_touch_selector_set_column_selection_mode
                                                          (HildonTouchSelector *selector,
                                                           HildonTouchSelectorSelectionMode mode);

Sets the selection mode for ``selector``. See :class:`HildonTouchSelectorSelectionMode` .



``selector``:
  a :class:`HildonTouchSelector`


``mode``:
  the :class:`HildonTouchSelectorMode` for ``selector``\


Since 2.2

.. _hildon-touch-selector-get-column-selection-mode:

.. function:: hildon_touch_selector_get_column_selection_mode ()

::

  HildonTouchSelectorSelectionMode hildon_touch_selector_get_column_selection_mode
                                                          (HildonTouchSelector *selector);

Gets the selection mode of ``selector``.



``selector``:
  a :class:`HildonTouchSelector`


*Returns*:
  one of :class:`HildonTouchSelectorSelectionMode`


Since 2.2

.. _hildon-touch-selector-get-column:

.. function:: hildon_touch_selector_get_column ()

::

  HildonTouchSelectorColumn* hildon_touch_selector_get_column
                                                          (HildonTouchSelector *selector,
                                                           int column);

Use this method to retrieve a :class:`HildonTouchSelectorColumn` . Then, you can use the :class:`GtkCellLayout` interface to set up the layout of the column.



``selector``:
  A :class:`HildonTouchSelector`


``column``:
  a column number


*Returns*:
  the ``column``-th :class:`HildonTouchSelectorColumn` in ``selector``\


Since 2.2

.. _hildon-touch-selector-set-active:

.. function:: hildon_touch_selector_set_active ()

::

  void                hildon_touch_selector_set_active    (HildonTouchSelector *selector,
                                                           int column,
                                                           int index);

Sets the active item of the :class:`HildonTouchSelector` to ``index``. The column number is taken from ``column``.

``selector`` must be in ```HILDON_TOUCH_SELECTOR_SELECTION_MODE_SINGLE`` <HILDON-TOUCH-SELECTOR-SELECTION-MODE-SINGLE:CAPS>`_



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  column number


``index``:
  the index of the item to select, or -1 to have no active item


Since 2.2

.. _hildon-touch-selector-get-active:

.. function:: hildon_touch_selector_get_active ()

::

  int                hildon_touch_selector_get_active    (HildonTouchSelector *selector,
                                                           int column);

Returns the index of the currently active item in column number ``column``, or -1 if there's no active item.

``selector`` must be in ```HILDON_TOUCH_SELECTOR_SELECTION_MODE_SINGLE`` <HILDON-TOUCH-SELECTOR-SELECTION-MODE-SINGLE:CAPS>`_



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  column number


*Returns*:
  an integer which is the index of the currently active item, or -1 if there's no active item.


Since 2.2

.. _hildon-touch-selector-get-selected:

.. function:: hildon_touch_selector_get_selected ()

::

  bool            hildon_touch_selector_get_selected  (HildonTouchSelector *selector,
                                                           int column,
                                                           GtkTreeIter *iter);

Sets ``iter`` to the currently selected node on the nth-column, if selection is set to ```HILDON_TOUCH_SELECTOR_SINGLE`` <HILDON-TOUCH-SELECTOR-SINGLE:CAPS>`_ or ```HILDON_TOUCH_SELECTOR_MULTIPLE`` <HILDON-TOUCH-SELECTOR-MULTIPLE:CAPS>`_ with a column different that the first one. ``iter`` may be ```NULL`` <NULL:CAPS>`_ if you just want to test if selection has any selected items.

This function will not work if selection is in ```HILDON_TOUCH_SELECTOR_MULTIPLE`` <HILDON-TOUCH-SELECTOR-MULTIPLE:CAPS>`_ mode and the column is the first one.

See `gtk_tree_selection_get_selected() <gtk-tree-selection-get-selected>`_ for more information.



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the column number we want to get the element


``iter``:
  :class:`GtkTreeIter` currently selected


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ if ``iter`` was correctly set, ```FALSE`` <FALSE:CAPS>`_ otherwise


Since 2.2

.. _hildon-touch-selector-center-on-selected:

.. function:: hildon_touch_selector_center_on_selected ()

::

  void                hildon_touch_selector_center_on_selected
                                                          (HildonTouchSelector *selector);

Ensures all the columns in a :class:`HildonTouchSelector` show a selected item. If one of the columns is in ```HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE`` <HILDON-TOUCH-SELECTOR-SELECTION-MODE-MULTIPLE:CAPS>`_ mode, that column will be scrolled to ensure the selected item that is closest to the currently visible area is shown.



``selector``:
  a :class:`HildonTouchSelector`


Since 2.2

.. _hildon-touch-selector-select-iter:

.. function:: hildon_touch_selector_select_iter ()

::

  void                hildon_touch_selector_select_iter   (HildonTouchSelector *selector,
                                                           int column,
                                                           GtkTreeIter *iter,
                                                           bool scroll_to);

Sets the currently selected item in the column ``column`` to the one pointed by ``iter``, optionally smoothly scrolling to it.



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the column to selects


``iter``:
  the :class:`GtkTreeIter` to be selected


``scroll_to``:
  whether to smoothly scroll to the item


Since 2.2

.. _hildon-touch-selector-unselect-iter:

.. function:: hildon_touch_selector_unselect_iter ()

::

  void                hildon_touch_selector_unselect_iter (HildonTouchSelector *selector,
                                                           int column,
                                                           GtkTreeIter *iter);

Unselect the item pointed by ``iter`` in the column ``column``



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the column to unselects from


``iter``:
  the :class:`GtkTreeIter` to be unselected


Since 2.2

.. _hildon-touch-selector-unselect-all:

.. function:: hildon_touch_selector_unselect_all ()

::

  void                hildon_touch_selector_unselect_all  (HildonTouchSelector *selector,
                                                           int column);

Unselects all the selected items in the column ``column``.



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the position of the column to get the selected rows from


Since 2.2

.. _hildon-touch-selector-get-selected-rows:

.. function:: hildon_touch_selector_get_selected_rows ()

::

  GList*              hildon_touch_selector_get_selected_rows
                                                          (HildonTouchSelector *selector,
                                                           int column);

Creates a list of :class:`GtkTreePath` s of all selected rows in a column. Additionally, if you to plan to modify the model after calling this function, you may want to convert the returned list into a list of GtkTreeRowReferences. To do this, you can use `gtk_tree_row_reference_new() <gtk-tree-row-reference-new>`_ .

See `gtk_tree_selection_get_selected_rows() <gtk-tree-selection-get-selected-rows>`_ for more information.



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the position of the column to get the selected rows from


*Returns*:
  A new :class:`GList` containing a :class:`GtkTreePath` for each selected row in the column ``column``.


Since 2.2

.. _hildon-touch-selector-set-model:

.. function:: hildon_touch_selector_set_model ()

::

  void                hildon_touch_selector_set_model     (HildonTouchSelector *selector,
                                                           int column,
                                                           GtkTreeModel *model);

Sets the :class:`GtkTreeModel` for a particular column in ``model``.



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the position of the column to set the model to


``model``:
  a :class:`GtkTreeModel`


Since 2.2

.. _hildon-touch-selector-get-model:

.. function:: hildon_touch_selector_get_model ()

::

  GtkTreeModel*       hildon_touch_selector_get_model     (HildonTouchSelector *selector,
                                                           int column);

Gets the model of a column of ``selector``.



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the position of the column in ``selector``\


*Returns*:
  the :class:`GtkTreeModel` for the column ``column`` of ``selector``.


Since 2.2

.. _hildon-touch-selector-get-current-text:

.. function:: hildon_touch_selector_get_current_text ()

::

  str              hildon_touch_selector_get_current_text
                                                          (HildonTouchSelector *selector);

Returns a string representing the currently selected items for each column of ``selector``. See `hildon_touch_selector_set_print_func() <hildon-touch-selector-set-print-func>`_ .



``selector``:
  a :class:`HildonTouchSelector`


*Returns*:
  a newly allocated string.


Since 2.2

.. _hildon-touch-selector-set-print-func:

.. function:: hildon_touch_selector_set_print_func ()

::

  void                hildon_touch_selector_set_print_func
                                                          (HildonTouchSelector *selector,
                                                           HildonTouchSelectorPrintFunc func);

Sets the function to be used by `hildon_touch_selector_get_current_text() <hildon-touch-selector-get-current-text>`_ to produce a text representation of the currently selected items in ``selector``. The default function will return a concatenation of comma separated items selected in each column in ``selector``. Use this to override this method if you need a particular representation for your application.



``selector``:
  a :class:`HildonTouchSelector`


``func``:
  a :class:`HildonTouchSelectorPrintFunc` function


Since 2.2

.. _hildon-touch-selector-get-print-func:

.. function:: hildon_touch_selector_get_print_func ()

::

  HildonTouchSelectorPrintFunc hildon_touch_selector_get_print_func
                                                          (HildonTouchSelector *selector);

Gets the :class:`HildonTouchSelectorPrintFunc` currently used. See `hildon_touch_selector_set_print_func() <hildon-touch-selector-set-print-func>`_ .



``selector``:
  a :class:`HildonTouchSelector`


*Returns*:
  a :class:`HildonTouchSelectorPrintFunc` or ```NULL`` <NULL:CAPS>`_ if the default one is currently used.


.. _hildon-touch-selector-set-print-func-full:

.. function:: hildon_touch_selector_set_print_func_full ()

::

  void                hildon_touch_selector_set_print_func_full
                                                          (HildonTouchSelector *selector,
                                                           HildonTouchSelectorPrintFunc func,
                                                           gpointer user_data,
                                                           GDestroyNotify destroy_func);

Sets the function to be used by `hildon_touch_selector_get_current_text() <hildon-touch-selector-get-current-text>`_ to produce a text representation of the currently selected items in ``selector``. The default function will return a concatenation of comma separated items selected in each column in ``selector``. Use this to override this method if you need a particular representation for your application.



``selector``:
  a :class:`HildonTouchSelector`


``func``:
  a :class:`HildonTouchSelectorPrintFunc` function


``user_data``:
  a pointer to user data or ```NULL`` <NULL:CAPS>`_


``destroy_func``:
  a callback for freeing the user data or ```NULL`` <NULL:CAPS>`_


Since 2.2

.. _hildon-touch-selector-has-multiple-selection:

.. function:: hildon_touch_selector_has_multiple_selection ()

::

  bool            hildon_touch_selector_has_multiple_selection
                                                          (HildonTouchSelector *selector);

Determines whether ``selector`` is complex enough to actually require an extra selection step than only picking an item. This is normally ```TRUE`` <TRUE:CAPS>`_ if ``selector`` has multiple columns, multiple selection, or when it is a more complex widget, like :class:`HildonTouchSelectorEntry` .

This information is useful for widgets containing a :class:`HildonTouchSelector` , like :class:`HildonPickerDialog` , that could need a "Done" button, in case that its internal :class:`HildonTouchSelector` has multiple columns, for instance.



``selector``:
  A :class:`HildonTouchSelector`


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ if ``selector`` requires multiple selection steps.


Since 2.2

.. _HildonTouchSelector.property-details:

Property Details
================

.. _HildonTouchSelector--has-multiple-selection:

The ``has-multiple-selection`` property

::

    has-multiple-selection   bool              : Read

Whether the widget has multiple selection (like multiple columns, multiselection mode, or multiple internal widgets) and therefore it may need a confirmation button, for instance.

Default value: FALSE

.. _HildonTouchSelector--initial-scroll:

The ``initial-scroll`` property

::

    initial-scroll           bool              : Read / Write / Construct

Whether to scroll to thecurrent selection whenthe selector is firstshown.

Default value: TRUE

.. _HildonTouchSelector.signal-details:

Signal Details
==============

.. _HildonTouchSelector-changed:

The ``changed`` signal

::

  void                user_function                      (HildonTouchSelector *widget,
                                                          int                 column,
                                                          gpointer             user_data)      : Run Last

The "changed" signal is emitted when the active item on any column is changed. This can be due to the user selecting a different item from the list, or due to a call to `hildon_touch_selector_select_iter() <hildon-touch-selector-select-iter>`_ on one of the columns.



``widget``:
  the object which received the signal


``column``:
  the number of the column that has changed


``user_data``:
  user data set when the signal handler was connected.


Since 2.2

.. _HildonTouchSelector-columns-changed:

The ``columns-changed`` signal

::

  void                user_function                      (HildonTouchSelector *selector,
                                                          gpointer             user_data)      : Run Last

The "columns-changed" signal is emitted when the number of columns in the :class:`HildonTouchSelector` change.



``selector``:
  the object which received the signal


``user_data``:
  user data set when the signal handler was connected.


Since 2.2

.. _HildonTouchSelectorColumn:

HildonTouchSelectorColumn
*************************

.. _HildonTouchSelectorColumn.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----HildonTouchSelectorColumn
  

.. _HildonTouchSelectorColumn.implemented-interfaces:

Implemented Interfaces
======================

HildonTouchSelectorColumn implements :class:`GtkCellLayout` .

.. _HildonTouchSelectorColumn.properties:

Properties
==========

::

  
    text-column              int                  : Read / Write
  

.. _HildonTouchSelectorColumn.description:

Description
===========

:class:`HildonTouchSelectorColumn` object represents a visible column in :class:`HildonTouchSelector` . It allows to manage the cell renderers related to each column.



.. _HildonTouchSelectorColumn.details:

Details
=======

.. _HildonTouchSelectorColumn-struct:

.. class:: HildonTouchSelectorColumn

::

  typedef struct _HildonTouchSelectorColumn HildonTouchSelectorColumn;



.. _HildonTouchSelectorColumn.property-details:

Property Details
================

.. _HildonTouchSelectorColumn--text-column:

The ``text-column`` property

::

    text-column              int                  : Read / Write

A column in the data source model to get the strings from.

Allowed values: = -1

Default value: -1

.. _HildonTouchSelectorEntry:

HildonTouchSelectorEntry
************************

.. _HildonTouchSelectorEntry.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBox
                                   +----GtkVBox
                                         +----HildonTouchSelector
                                               +----HildonTouchSelectorEntry
  

.. _HildonTouchSelectorEntry.implemented-interfaces:

Implemented Interfaces
======================

HildonTouchSelectorEntry implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonTouchSelectorEntry.properties:

Properties
==========

::

  
    text-column              int                  : Read / Write
  

.. _HildonTouchSelectorEntry.description:

Description
===========

:class:`HildonTouchSelectorEntry` is a selector widget with a text entry, similar in behaviour to :class:`GtkComboBoxEntry` , that allows user to select an item from a predefined list or to enter a different one in a :class:`HildonEntry` . Items can also be searched and selected by typing in the entry. For more specific use cases, the :class:`HildonEntry` can be accessed directly with `hildon_touch_selector_get_entry() <hildon-touch-selector-get-entry>`_ .

The main difference between the :class:`GtkTreeModel` used by :class:`HildonTouchSelector` and :class:`HildonTouchSelectorEntry` , is that the latter must always include a text column. You should set it with `hildon_touch_selector_entry_set_text_column() <hildon-touch-selector-entry-set-text-column>`_ .

Normally, you would use :class:`HildonTouchSelectorEntry` together with a :class:`HildonPickerDialog` activated from a button. For the most common cases, you should use :class:`HildonPickerButton` .

If you only need a text only, one column selector, you can create it with `hildon_touch_selector_entry_new_text() <hildon-touch-selector-entry-new-text>`_ and populate it with `hildon_touch_selector_append_text() <hildon-touch-selector-append-text>`_ , `hildon_touch_selector_prepend_text() <hildon-touch-selector-prepend-text>`_ , and `hildon_touch_selector_insert_text() <hildon-touch-selector-insert-text>`_ .



.. _HildonTouchSelectorEntry.details:

Details
=======

.. _HildonTouchSelectorEntry-struct:

.. class:: HildonTouchSelectorEntry

::

  typedef struct _HildonTouchSelectorEntry HildonTouchSelectorEntry;



.. _hildon-touch-selector-entry-new:

.. function:: hildon_touch_selector_entry_new ()

::

  GtkWidget*          hildon_touch_selector_entry_new     (void);

Creates a :class:`HildonTouchSelectorEntry`



*Returns*:
  A new :class:`HildonTouchSelectorEntry`


Since 2.2

.. _hildon-touch-selector-entry-new-text:

.. function:: hildon_touch_selector_entry_new_text ()

::

  GtkWidget*          hildon_touch_selector_entry_new_text
                                                          (void);

Creates a :class:`HildonTouchSelectorEntry` with a single text column that can be populated conveniently through `hildon_touch_selector_append_text() <hildon-touch-selector-append-text>`_ , `hildon_touch_selector_prepend_text() <hildon-touch-selector-prepend-text>`_ , `hildon_touch_selector_insert_text() <hildon-touch-selector-insert-text>`_ .



*Returns*:
  A new :class:`HildonTouchSelectorEntry`


Since 2.2

.. _hildon-touch-selector-entry-set-text-column:

.. function:: hildon_touch_selector_entry_set_text_column ()

::

  void                hildon_touch_selector_entry_set_text_column
                                                          (HildonTouchSelectorEntry *selector,
                                                           int text_column);

Sets the model column which touch selector box should use to get strings from to be ``text_column``.



``selector``:
  A :class:`HildonTouchSelectorEntry`


``text_column``:
  A column in model to get the strings from


Since 2.2

.. _hildon-touch-selector-entry-get-text-column:

.. function:: hildon_touch_selector_entry_get_text_column ()

::

  int                hildon_touch_selector_entry_get_text_column
                                                          (HildonTouchSelectorEntry *selector);

Gets the text column that ``selector`` is using as a text column.



``selector``:
  A :class:`HildonTouchSelectorEntry`


*Returns*:
  the number of the column used as a text column.


Since 2.2

.. _hildon-touch-selector-entry-set-input-mode:

.. function:: hildon_touch_selector_entry_set_input_mode ()

::

  void                hildon_touch_selector_entry_set_input_mode
                                                          (HildonTouchSelectorEntry *selector,
                                                           HildonGtkInputMode input_mode);

Sets the input mode to be used in the :class:`GtkEntry` in ``selector``. See `hildon_gtk_entry_set_input_mode() <hildon-gtk-entry-set-input-mode>`_ for details.

It must be noted that not all input modes are available for the entry in ``selector``. In particular, ```HILDON_GTK_INPUT_MODE_MULTILINE`` <HILDON-GTK-INPUT-MODE-MULTILINE:CAPS>`_ , ```HILDON_GTK_INPUT_MODE_INVISIBLE`` <HILDON-GTK-INPUT-MODE-INVISIBLE:CAPS>`_ , ```HILDON_GTK_INPUT_MODE_DICTIONARY`` <HILDON-GTK-INPUT-MODE-DICTIONARY:CAPS>`_ are disabled, since these are irrelevant for :class:`HildonTouchSelectorEntry` .



``selector``:
  a :class:`HildonTouchSelectorEntry`


``input_mode``:
  :class:`HildonGtkInputMode` mask


Since 2.2

.. _hildon-touch-selector-entry-get-input-mode:

.. function:: hildon_touch_selector_entry_get_input_mode ()

::

  HildonGtkInputMode  hildon_touch_selector_entry_get_input_mode
                                                          (HildonTouchSelectorEntry *selector);

Gets the input mode used in the :class:`GtkEntry` in ``selector``. See `hildon_gtk_entry_get_input_mode() <hildon-gtk-entry-get-input-mode>`_ for details.



``selector``:
  a :class:`HildonTouchSelectorEntry`


*Returns*:
  a mask of :class:`HildonGtkInputMode`


Since 2.2

.. _hildon-touch-selector-entry-get-entry:

.. function:: hildon_touch_selector_entry_get_entry ()

::

  HildonEntry*        hildon_touch_selector_entry_get_entry
                                                          (HildonTouchSelectorEntry *selector);

Provides access to the :class:`HildonEntry` in ``selector``. Use to programmatically change the contents in entry or modify its behavior.



``selector``:
  a :class:`HildonTouchSelectorEntry` .


*Returns*:
  a :class:`HildonEntry` .


Since 2.2

.. _HildonTouchSelectorEntry.property-details:

Property Details
================

.. _HildonTouchSelectorEntry--text-column:

The ``text-column`` property

::

    text-column              int                  : Read / Write





Allowed values: = -1

Default value: -1

Since 2.2

.. _HildonTouchSelectorEntry.see-also:

See Also
========

:class:`HildonTouchSelector` :class:`HildonPickerButton` .. _HildonDateSelector:

HildonDateSelector
******************

.. _HildonDateSelector.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBox
                                   +----GtkVBox
                                         +----HildonTouchSelector
                                               +----HildonDateSelector
  

.. _HildonDateSelector.implemented-interfaces:

Implemented Interfaces
======================

HildonDateSelector implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonDateSelector.properties:

Properties
==========

::

  
    max-year                 int                  : Read / Write / Construct Only
    min-year                 int                  : Read / Write / Construct Only
  

.. _HildonDateSelector.description:

Description
===========

:class:`HildonDateSelector` is a date widget with multiple columns. Users can choose a date by selecting values in the day, month and year columns.

The currently selected month and year can be altered with `hildon_date_selector_select_month() <hildon-date-selector-select-month>`_ . The day can be selected from the active month using `hildon_date_selector_select_day() <hildon-date-selector-select-day>`_ .



.. _HildonDateSelector.details:

Details
=======

.. _HildonDateSelector-struct:

.. class:: HildonDateSelector

::

  typedef struct _HildonDateSelector HildonDateSelector;



.. _hildon-date-selector-new:

.. function:: hildon_date_selector_new ()

::

  GtkWidget*          hildon_date_selector_new            (void);

Creates a new :class:`HildonDateSelector`



*Returns*:
  a new :class:`HildonDateSelector`


Since 2.2

.. _hildon-date-selector-new-with-year-range:

.. function:: hildon_date_selector_new_with_year_range ()

::

  GtkWidget*          hildon_date_selector_new_with_year_range
                                                          (int min_year,
                                                           int max_year);

Creates a new :class:`HildonDateSelector` with a specific year range. If ``min_year`` or ``max_year`` are set to -1, then the default upper or lower bound will be used, respectively.



``min_year``:
  the minimum available year or -1 to ignore


``max_year``:
  the maximum available year or -1 to ignore


*Returns*:
  a new :class:`HildonDateSelector`


Since 2.2

.. _hildon-date-selector-select-month:

.. function:: hildon_date_selector_select_month ()

::

  bool            hildon_date_selector_select_month   (HildonDateSelector *selector,
                                                           int month,
                                                           int year);

Modify the current month and year on the current active date

Utility function to keep this API similar to the previously existing :class:`HildonCalendar` widget.



``selector``:
  the :class:`HildonDateSelector`


``month``:
  the current month (0-11)


``year``:
  the current year


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ on success, ```FALSE`` <FALSE:CAPS>`_ otherwise


Since 2.2

.. _hildon-date-selector-select-day:

.. function:: hildon_date_selector_select_day ()

::

  void                hildon_date_selector_select_day     (HildonDateSelector *selector,
                                                           int day);

Modify the current day on the current active date

Utility function to keep this API similar to the previously existing :class:`HildonCalendar` widget.



``selector``:
  the :class:`HildonDateSelector`


``day``:
  the current day (1-31, 1-30, 1-29, 1-28) depends on the month


Since 2.2

.. _hildon-date-selector-select-current-date:

.. function:: hildon_date_selector_select_current_date ()

::

  bool            hildon_date_selector_select_current_date
                                                          (HildonDateSelector *selector,
                                                           int year,
                                                           int month,
                                                           int day);

Sets the current active date on the :class:`HildonDateSelector` widget



``selector``:
  the :class:`HildonDateSelector`


``year``:
  the current year


``month``:
  the current month (0-11)


``day``:
  the current day (1-31, 1-30, 1-29, 1-28) depends on the month


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ on success, ```FALSE`` <FALSE:CAPS>`_ otherwise


Since 2.2

.. _hildon-date-selector-get-date:

.. function:: hildon_date_selector_get_date ()

::

  void                hildon_date_selector_get_date       (HildonDateSelector *selector,
                                                           int *year,
                                                           int *month,
                                                           int *day);

Gets the current active date on the :class:`HildonDateSelector` widget



``selector``:
  the :class:`HildonDateSelector`


``year``:
  to set the current year


``month``:
  to set the current month (0-11)


``day``:
  to the current day (1-31, 1-30, 1-29, 1-28) depends on the month


Since 2.2

.. _HildonDateSelector.property-details:

Property Details
================

.. _HildonDateSelector--max-year:

The ``max-year`` property

::

    max-year                 int                  : Read / Write / Construct Only

The maximum available year in the selector.

Allowed values: [1900,2100]

Default value: 2037

.. _HildonDateSelector--min-year:

The ``min-year`` property

::

    min-year                 int                  : Read / Write / Construct Only

The minimum available year in the selector.

Allowed values: [1900,2100]

Default value: 1970

.. _HildonTimeSelector:

HildonTimeSelector
******************

.. _HildonTimeSelector.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBox
                                   +----GtkVBox
                                         +----HildonTouchSelector
                                               +----HildonTimeSelector
  

.. _HildonTimeSelector.implemented-interfaces:

Implemented Interfaces
======================

HildonTimeSelector implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonTimeSelector.properties:

Properties
==========

::

  
    minutes-step             int                 : Read / Write / Construct Only
  

.. _HildonTimeSelector.description:

Description
===========

:class:`HildonTimeSelector` allows users to choose a time by selecting hour and minute. It also allows choosing between AM or PM format.

The currently selected time can be altered with `hildon_time_selector_set_time() <hildon-time-selector-set-time>`_ , and retrieved using `hildon_time_selector_get_time() <hildon-time-selector-get-time>`_ .

Use this widget instead of deprecated HildonTimeEditor widget.



.. _HildonTimeSelector.details:

Details
=======

.. _HildonTimeSelector-struct:

.. class:: HildonTimeSelector

::

  typedef struct _HildonTimeSelector HildonTimeSelector;



.. _hildon-time-selector-new:

.. function:: hildon_time_selector_new ()

::

  GtkWidget*          hildon_time_selector_new            (void);

Creates a new :class:`HildonTimeSelector`



*Returns*:
  a new :class:`HildonTimeSelector`


Since 2.2

.. _hildon-time-selector-new-step:

.. function:: hildon_time_selector_new_step ()

::

  GtkWidget*          hildon_time_selector_new_step       (int minutes_step);

Creates a new :class:`HildonTimeSelector` ``minutes_step``: step between the minutes we are going to show in the selector



``minutes_step``:
  


*Returns*:
  a new :class:`HildonTimeSelector`


Since 2.2

.. _hildon-time-selector-set-time:

.. function:: hildon_time_selector_set_time ()

::

  bool            hildon_time_selector_set_time       (HildonTimeSelector *selector,
                                                           int hours,
                                                           int minutes);

Sets the current active hour on the :class:`HildonTimeSelector` widget

The format of the hours accepted is always 24h format, with a range (0-23):(0-59).



``selector``:
  the :class:`HildonTimeSelector`


``hours``:
  the current hour (0-23)


``minutes``:
  the current minute (0-59)


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ on success, ```FALSE`` <FALSE:CAPS>`_ otherwise


Since 2.2

.. _hildon-time-selector-get-time:

.. function:: hildon_time_selector_get_time ()

::

  void                hildon_time_selector_get_time       (HildonTimeSelector *selector,
                                                           int *hours,
                                                           int *minutes);

Gets the current active hour on the :class:`HildonTimeSelector` widget. Both ``year``\ and ``minutes`` can be NULL.

This method returns the date always in 24h format, with a range (0-23):(0-59)



``selector``:
  the :class:`HildonTimeSelector`


``hours``:
  to set the current hour (0-23)


``minutes``:
  to set the current minute (0-59)


Since 2.2

.. _HildonTimeSelector.property-details:

Property Details
================

.. _HildonTimeSelector--minutes-step:

The ``minutes-step`` property

::

    minutes-step             int                 : Read / Write / Construct Only

Step between the minutes in the list of options of the widget .

Allowed values: [1,30]

Default value: 1

.. _HildonPannableArea:

HildonPannableArea
******************

.. _HildonPannableArea.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----HildonPannableArea
  

.. _HildonPannableArea.implemented-interfaces:

Implemented Interfaces
======================

HildonPannableArea implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonPannableArea.properties:

Properties
==========

::

  
    bounce-steps             int                 : Read / Write / Construct
    deceleration             gdouble               : Read / Write / Construct
    direction-error-margin   int                 : Read / Write / Construct
    drag-inertia             gdouble               : Read / Write / Construct
    enabled                  bool              : Read / Write / Construct
    force                    int                 : Read / Write / Construct
    hadjustment              GtkAdjustment*        : Read
    hovershoot-max           int                  : Read / Write / Construct
    hscrollbar-policy        GtkPolicyType         : Read / Write / Construct
    initial-hint             bool              : Read / Write / Construct
    low-friction-mode        bool              : Read / Write / Construct
    mode                     HildonPannableAreaMode  : Read / Write / Construct
    mov-mode                 HildonMovementMode    : Read / Write / Construct
    panning-threshold        int                 : Read / Write / Construct
    scroll-time              gdouble               : Read / Write / Construct
    scrollbar-fade-delay     int                 : Read / Write / Construct
    size-request-policy      HildonSizeRequestPolicy  : Read / Write / Construct
    sps                      int                 : Read / Write / Construct
    vadjustment              GtkAdjustment*        : Read
    velocity-fast-factor     gdouble               : Read / Write / Construct
    velocity-max             gdouble               : Read / Write / Construct
    velocity-min             gdouble               : Read / Write / Construct
    velocity-overshooting-max gdouble               : Read / Write / Construct
    vovershoot-max           int                  : Read / Write / Construct
    vscrollbar-policy        GtkPolicyType         : Read / Write / Construct
  

.. _HildonPannableArea.style-properties:

Style Properties
================

::

  
    indicator-width          int                 : Read / Write
  

.. _HildonPannableArea.signals:

Signals
=======

::

  
    horizontal-movement                            : Run Last / Action
    vertical-movement                              : Run Last / Action
  

.. _HildonPannableArea.description:

Description
===========

:class:`HildonPannableArea` is a container widget that can be "panned" (scrolled) up and down using the touchscreen with fingers. The widget has no scrollbars, but it rather shows small scroll indicators to give an idea of the part of the content that is visible at a time. The scroll indicators appear when a dragging motion is started on the pannable area.

The scrolling is "kinetic", meaning the motion can be "flicked" and it will continue from the initial motion by gradually slowing down to an eventual stop. The motion can also be stopped immediately by pressing the touchscreen over the pannable area.



.. _HildonPannableArea.details:

Details
=======

.. _HildonPannableAreaMode:

.. :: enum HildonPannableAreaMode

::

  typedef enum {
    HILDON_PANNABLE_AREA_MODE_PUSH,
    HILDON_PANNABLE_AREA_MODE_ACCEL,
    HILDON_PANNABLE_AREA_MODE_AUTO
  } HildonPannableAreaMode;
  

Used to change the behaviour of the pannable areaing



``HILDON_PANNABLE_AREA_MODE_PUSH``
  Areaing follows pointer


``HILDON_PANNABLE_AREA_MODE_ACCEL``
  Areaing uses physics to "spin" the widget


``HILDON_PANNABLE_AREA_MODE_AUTO``
  Automatically chooses between push and accel modes, depending on input.


.. _HildonMovementMode:

.. :: enum HildonMovementMode

::

  typedef enum {
    HILDON_MOVEMENT_MODE_HORIZ = 1  1,
    HILDON_MOVEMENT_MODE_VERT = 1  2,
    HILDON_MOVEMENT_MODE_BOTH = 0x000006
  } HildonMovementMode;
  

Used to control the movement of the pannable, we can allow or disallow horizontal or vertical movement. This way the applications can control the movement using scroll_to and jump_to functions



.. _HildonMovementDirection:

.. :: enum HildonMovementDirection

::

  typedef enum {
    HILDON_MOVEMENT_UP,
    HILDON_MOVEMENT_DOWN,
    HILDON_MOVEMENT_LEFT,
    HILDON_MOVEMENT_RIGHT
  } HildonMovementDirection;
  

Used to point out the direction of the movement



.. _HildonSizeRequestPolicy:

.. :: enum HildonSizeRequestPolicy

::

  typedef enum {
    HILDON_SIZE_REQUEST_MINIMUM,
    HILDON_SIZE_REQUEST_CHILDREN
  } HildonSizeRequestPolicy;
  

Used to control the size request policy of the widget



``HILDON_SIZE_REQUEST_MINIMUM``
  The minimum size the widget could use to paint itself


``HILDON_SIZE_REQUEST_CHILDREN``
  The minimum size of the children of the widget


.. _HildonPannableArea-struct:

.. class:: HildonPannableArea

::

  typedef struct _HildonPannableArea HildonPannableArea;

HildonPannableArea has no publicly accessible fields



.. _hildon-pannable-area-new:

.. function:: hildon_pannable_area_new ()

::

  GtkWidget*          hildon_pannable_area_new            (void);

Create a new pannable area widget



*Returns*:
  the newly created :class:`HildonPannableArea`


Since 2.2

.. _hildon-pannable-area-new-full:

.. function:: hildon_pannable_area_new_full ()

::

  GtkWidget*          hildon_pannable_area_new_full       (int mode,
                                                           bool enabled,
                                                           gdouble vel_min,
                                                           gdouble vel_max,
                                                           gdouble decel,
                                                           int sps);

Create a new :class:`HildonPannableArea` widget and set various properties



``mode``:
  :class:`HildonPannableAreaMode`


``enabled``:
  Value for the enabled property


``vel_min``:
  Value for the velocity-min property


``vel_max``:
  Value for the velocity-max property


``decel``:
  Value for the deceleration property


``sps``:
  Value for the sps property


*Returns*:
  the newly create :class:`HildonPannableArea`


Since 2.2

.. _hildon-pannable-area-add-with-viewport:

.. function:: hildon_pannable_area_add_with_viewport ()

::

  void                hildon_pannable_area_add_with_viewport
                                                          (HildonPannableArea *area,
                                                           GtkWidget *child);

Convenience function used to add a child to a :class:`GtkViewport` , and add the viewport to the scrolled window.



``area``:
  A :class:`HildonPannableArea`


``child``:
  Child widget to add to the viewport


Since 2.2

.. _hildon-pannable-area-scroll-to:

.. function:: hildon_pannable_area_scroll_to ()

::

  void                hildon_pannable_area_scroll_to      (HildonPannableArea *area,
                                                           const int x,
                                                           const int y);

Smoothly scrolls ``area`` to ensure that (``x``, ``y``) is a visible point on the widget. To move in only one coordinate, you must set the other one to -1. Notice that, in ```HILDON_PANNABLE_AREA_MODE_PUSH`` <HILDON-PANNABLE-AREA-MODE-PUSH:CAPS>`_ mode, this function works just like `hildon_pannable_area_jump_to() <hildon-pannable-area-jump-to>`_ .

This function is useful if you need to present the user with a particular element inside a scrollable widget, like :class:`GtkTreeView` . For instance, the following example shows how to scroll inside a :class:`GtkTreeView` to make visible an item, indicated by the :class:`GtkTreeIter` ``iter``.

:: GtkTreePath *path; GdkRectangle *rect; path = gtk_tree_model_get_path (model, iter); gtk_tree_view_get_background_area (GTK_TREE_VIEW (treeview), path, NULL, rect); gtk_tree_view_convert_bin_window_to_tree_coords (GTK_TREE_VIEW (treeview), 0, rect.y, NULL, y); hildon_pannable_area_scroll_to (panarea, -1, y); gtk_tree_path_free (path);

If you want to present a child widget in simpler scenarios, use `hildon_pannable_area_scroll_to_child() <hildon-pannable-area-scroll-to-child>`_ instead.

There is a precondition to this function: the widget must be already realized. Check the `hildon_pannable_area_jump_to_child() <hildon-pannable-area-jump-to-child>`_ for more tips regarding how to call this function during initialization.



``area``:
  A :class:`HildonPannableArea` .


``x``:
  The x coordinate of the destination point or -1 to ignore this axis.


``y``:
  The y coordinate of the destination point or -1 to ignore this axis.


Since 2.2

.. _hildon-pannable-area-jump-to:

.. function:: hildon_pannable_area_jump_to ()

::

  void                hildon_pannable_area_jump_to        (HildonPannableArea *area,
                                                           const int x,
                                                           const int y);

Jumps the position of ``area`` to ensure that (``x``, ``y``) is a visible point in the widget. In order to move in only one coordinate, you must set the other one to -1. See `hildon_pannable_area_scroll_to() <hildon-pannable-area-scroll-to>`_ function for an example of how to calculate the position of children in scrollable widgets like :class:`GtkTreeview` .

There is a precondition to this function: the widget must be already realized. Check the `hildon_pannable_area_jump_to_child() <hildon-pannable-area-jump-to-child>`_ for more tips regarding how to call this function during initialization.



``area``:
  A :class:`HildonPannableArea` .


``x``:
  The x coordinate of the destination point or -1 to ignore this axis.


``y``:
  The y coordinate of the destination point or -1 to ignore this axis.


Since 2.2

.. _hildon-pannable-area-scroll-to-child:

.. function:: hildon_pannable_area_scroll_to_child ()

::

  void                hildon_pannable_area_scroll_to_child
                                                          (HildonPannableArea *area,
                                                           GtkWidget *child);

Smoothly scrolls until ``child`` is visible inside ``area``. ``child`` must be a descendant of ``area``. If you need to scroll inside a scrollable widget, e.g., :class:`GtkTreeview` , see `hildon_pannable_area_scroll_to() <hildon-pannable-area-scroll-to>`_ .

There is a precondition to this function: the widget must be already realized. Check the `hildon_pannable_area_jump_to_child() <hildon-pannable-area-jump-to-child>`_ for more tips regarding how to call this function during initialization.



``area``:
  A :class:`HildonPannableArea` .


``child``:
  A :class:`GtkWidget` , descendant of ``area``.


Since 2.2

.. _hildon-pannable-area-jump-to-child:

.. function:: hildon_pannable_area_jump_to_child ()

::

  void                hildon_pannable_area_jump_to_child  (HildonPannableArea *area,
                                                           GtkWidget *child);

Jumps to make sure ``child`` is visible inside ``area``. ``child`` must be a descendant of ``area``. If you want to move inside a scrollable widget, like, :class:`GtkTreeview` , see `hildon_pannable_area_scroll_to() <hildon-pannable-area-scroll-to>`_ .

There is a precondition to this function: the widget must be already realized. You can control if the widget is ready with the GTK_WIDGET_REALIZED macro. If you want to call this function during the initialization process of the widget do it inside a callback to the ::realize signal, using `g_signal_connect_after() <g-signal-connect-after>`_ function.



``area``:
  A :class:`HildonPannableArea` .


``child``:
  A :class:`GtkWidget` , descendant of ``area``.


Since 2.2

.. _hildon-pannable-get-child-widget-at:

.. function:: hildon_pannable_get_child_widget_at ()

::

  GtkWidget*          hildon_pannable_get_child_widget_at (HildonPannableArea *area,
                                                           gdouble x,
                                                           gdouble y);

Get the widget at the point (x, y) inside the pannable area. In case no widget found it returns NULL.



``area``:
  A :class:`HildonPannableArea` .


``x``:
  horizontal coordinate of the point


``y``:
  vertical coordinate of the point


*Returns*:
  the :class:`GtkWidget` if we find a widget, NULL in any other case


Since 2.2

.. _hildon-pannable-area-get-size-request-policy:

.. function:: hildon_pannable_area_get_size_request_policy ()

::

  HildonSizeRequestPolicy hildon_pannable_area_get_size_request_policy
                                                          (HildonPannableArea *area);

This function returns the current size request policy of the widget. That policy controls the way the size_request is done in the pannable area. Check `hildon_pannable_area_set_size_request_policy() <hildon-pannable-area-set-size-request-policy>`_ for a more detailed explanation.



``area``:
  A :class:`HildonPannableArea` .


*Returns*:
  the policy is currently being used in the widget :class:`HildonSizeRequestPolicy` .


Since 2.2

.. _hildon-pannable-area-set-size-request-policy:

.. function:: hildon_pannable_area_set_size_request_policy ()

::

  void                hildon_pannable_area_set_size_request_policy
                                                          (HildonPannableArea *area,
                                                           HildonSizeRequestPolicy size_request_policy);

This function sets the pannable area size request policy. That policy controls the way the size_request is done in the pannable area. Pannable can use the size request of its children (`HILDON_SIZE_REQUEST_CHILDREN <HILDON-SIZE-REQUEST-CHILDREN:CAPS>`_ ) or the minimum size required for the area itself (`HILDON_SIZE_REQUEST_MINIMUM <HILDON-SIZE-REQUEST-MINIMUM:CAPS>`_ ), the latter is the default. Recall this size depends on the scrolling policy you are requesting to the pannable area, if you set `GTK_POLICY_NEVER <GTK-POLICY-NEVER:CAPS>`_ this parameter will not have any effect with `HILDON_SIZE_REQUEST_MINIMUM <HILDON-SIZE-REQUEST-MINIMUM:CAPS>`_ set.



``area``:
  A :class:`HildonPannableArea` .


``size_request_policy``:
  One of the allowed :class:`HildonSizeRequestPolicy`


Since 2.2

.. _hildon-pannable-area-get-hadjustment:

.. function:: hildon_pannable_area_get_hadjustment ()

::

  GtkAdjustment*      hildon_pannable_area_get_hadjustment
                                                          (HildonPannableArea *area);

Returns the horizontal adjustment. This adjustment is the internal widget adjustment used to control the animations. Do not modify it directly to change the position of the pannable, to do that use the pannable API. If you modify the object directly it could cause artifacts in the animations.



``area``:
  A :class:`HildonPannableArea` .


*Returns*:
  The horizontal :class:`GtkAdjustment`


Since 2.2

.. _hildon-pannable-area-get-vadjustment:

.. function:: hildon_pannable_area_get_vadjustment ()

::

  GtkAdjustment*      hildon_pannable_area_get_vadjustment
                                                          (HildonPannableArea *area);

Returns the vertical adjustment. This adjustment is the internal widget adjustment used to control the animations. Do not modify it directly to change the position of the pannable, to do that use the pannable API. If you modify the object directly it could cause artifacts in the animations.



``area``:
  A :class:`HildonPannableArea` .


*Returns*:
  The vertical :class:`GtkAdjustment`


Since 2.2

.. _HildonPannableArea.property-details:

Property Details
================

.. _HildonPannableArea--bounce-steps:

The ``bounce-steps`` property

::

    bounce-steps             int                 : Read / Write / Construct

Number of steps that is going to be used to bounce when hitting theedge, the rubberband effect depends on it.

Default value: 3

.. _HildonPannableArea--deceleration:

The ``deceleration`` property

::

    deceleration             gdouble               : Read / Write / Construct

The multiplier used when decelerating when in acceleration scrolling mode.

Allowed values: [0,1]

Default value: 0.93

.. _HildonPannableArea--direction-error-margin:

The ``direction-error-margin`` property

::

    direction-error-margin   int                 : Read / Write / Construct

After detecting the direction of the movement (horizontal orvertical), we can add this margin of error to allow the movement inthe other direction even apparently it is not.

Default value: 10

.. _HildonPannableArea--drag-inertia:

The ``drag-inertia`` property

::

    drag-inertia             gdouble               : Read / Write / Construct

Percentage of the calculated speed in each moment we are are going to useto calculate the launch speed, the other part would be the speedcalculated previously.

Allowed values: [0,1]

Default value: 0.85

.. _HildonPannableArea--enabled:

The ``enabled`` property

::

    enabled                  bool              : Read / Write / Construct

Enable or disable finger-scroll.

Default value: TRUE

.. _HildonPannableArea--force:

The ``force`` property

::

    force                    int                 : Read / Write / Construct

Force applied to the movement, multiplies the calculated speed of theuser movement the cursor in the screen.

Default value: 120

.. _HildonPannableArea--hadjustment:

The ``hadjustment`` property

::

    hadjustment              GtkAdjustment*        : Read

The GtkAdjustment for the horizontal position.

.. _HildonPannableArea--hovershoot-max:

The ``hovershoot-max`` property

::

    hovershoot-max           int                  : Read / Write / Construct

Space we allow the widget to pass over its horizontal limits whenhitting the edges, set 0 in order to deactivate overshooting.

Allowed values: = 0

Default value: 150

.. _HildonPannableArea--hscrollbar-policy:

The ``hscrollbar-policy`` property

::

    hscrollbar-policy        GtkPolicyType         : Read / Write / Construct

Visual policy of the horizontal scrollbar.

Default value: GTK_POLICY_AUTOMATIC

.. _HildonPannableArea--initial-hint:

The ``initial-hint`` property

::

    initial-hint             bool              : Read / Write / Construct

Whether to hint the user about the pannability of the container.

Default value: TRUE

.. _HildonPannableArea--low-friction-mode:

The ``low-friction-mode`` property

::

    low-friction-mode        bool              : Read / Write / Construct

Avoid decelerating the panning movement, like no friction, the widgetwill stop in the edges or if the user clicks.

Default value: FALSE

.. _HildonPannableArea--mode:

The ``mode`` property

::

    mode                     HildonPannableAreaMode  : Read / Write / Construct

Change the finger-scrolling mode.

Default value: HILDON_PANNABLE_AREA_MODE_AUTO

.. _HildonPannableArea--mov-mode:

The ``mov-mode`` property

::

    mov-mode                 HildonMovementMode    : Read / Write / Construct

Controls if the widget can scroll vertically, horizontally or both.

Default value: HILDON_MOVEMENT_MODE_VERT

.. _HildonPannableArea--panning-threshold:

The ``panning-threshold`` property

::

    panning-threshold        int                 : Read / Write / Construct

Amount of pixels to consider a motion event an scroll, if it is lessit is a click detected incorrectly by the touch screen.

Default value: 6

.. _HildonPannableArea--scroll-time:

The ``scroll-time`` property

::

    scroll-time              gdouble               : Read / Write / Construct

The time to scroll to a position when calling the hildon_pannable_scroll_to function.

Allowed values: [1,20]

Default value: 10

.. _HildonPannableArea--scrollbar-fade-delay:

The ``scrollbar-fade-delay`` property

::

    scrollbar-fade-delay     int                 : Read / Write / Construct

Time the scrollbar is going to be visible if the widget is not inaction in miliseconds.

Default value: 3000

.. _HildonPannableArea--size-request-policy:

The ``size-request-policy`` property

::

    size-request-policy      HildonSizeRequestPolicy  : Read / Write / Construct

Controls the size request policy of the widget.

Default value: HILDON_SIZE_REQUEST_MINIMUM

.. _HildonPannableArea--sps:

The ``sps`` property

::

    sps                      int                 : Read / Write / Construct

Amount of scroll events to generate per second.

Default value: 20

.. _HildonPannableArea--vadjustment:

The ``vadjustment`` property

::

    vadjustment              GtkAdjustment*        : Read

The GtkAdjustment for the vertical position.

.. _HildonPannableArea--velocity-fast-factor:

The ``velocity-fast-factor`` property

::

    velocity-fast-factor     gdouble               : Read / Write / Construct

Minimum velocity that is considered 'fast': children widgets won't receive button presses. Expressed as a fraction of the maximum velocity.

Allowed values: [0,1]

Default value: 0.02

.. _HildonPannableArea--velocity-max:

The ``velocity-max`` property

::

    velocity-max             gdouble               : Read / Write / Construct

Maximum distance the child widget should scroll per 'frame', in pixels per frame.

Allowed values: = 0

Default value: 500

.. _HildonPannableArea--velocity-min:

The ``velocity-min`` property

::

    velocity-min             gdouble               : Read / Write / Construct

Minimum distance the child widget should scroll per 'frame', in pixels per frame.

Allowed values: = 0

Default value: 20

.. _HildonPannableArea--velocity-overshooting-max:

The ``velocity-overshooting-max`` property

::

    velocity-overshooting-max gdouble               : Read / Write / Construct

Maximum distance the child widget should scroll per 'frame', in pixels per frame when it overshoots after hitting the edge.

Allowed values: = 0

Default value: 20

.. _HildonPannableArea--vovershoot-max:

The ``vovershoot-max`` property

::

    vovershoot-max           int                  : Read / Write / Construct

Space we allow the widget to pass over its vertical limits whenhitting the edges, set 0 in order to deactivate overshooting.

Allowed values: = 0

Default value: 150

.. _HildonPannableArea--vscrollbar-policy:

The ``vscrollbar-policy`` property

::

    vscrollbar-policy        GtkPolicyType         : Read / Write / Construct

Visual policy of the vertical scrollbar.

Default value: GTK_POLICY_AUTOMATIC

.. _HildonPannableArea.style-property-details:

Style Property Details
======================

.. _HildonPannableArea--indicator-width:

The ``indicator-width`` style property

::

    indicator-width          int                 : Read / Write

Pixel width used to draw the scroll indicators.

Default value: 8

.. _HildonPannableArea.signal-details:

Signal Details
==============

.. _HildonPannableArea-horizontal-movement:

The ``horizontal-movement`` signal

::

  void                user_function                      (HildonPannableArea *hildonpannable,
                                                          int                direction,
                                                          gdouble             initial_x,
                                                          gdouble             initial_y,
                                                          gpointer            user_data)           : Run Last / Action

The horizontal-movement signal is emitted when the pannable area starts a horizontal movement.



``hildonpannable``:
  the object which received the signal


``direction``:
  the direction of the movement `HILDON_MOVEMENT_UP <HILDON-MOVEMENT-UP:CAPS>`_ or `HILDON_MOVEMENT_DOWN <HILDON-MOVEMENT-DOWN:CAPS>`_


``initial_x``:
  the x value of the touched point in the area when the motion started


``initial_y``:
  the y value of the touched point in the area when the motion started


``user_data``:
  user data set when the signal handler was connected.


Since 2.2

.. _HildonPannableArea-vertical-movement:

The ``vertical-movement`` signal

::

  void                user_function                      (HildonPannableArea *hildonpannable,
                                                          int                direction,
                                                          gdouble             initial_x,
                                                          gdouble             initial_y,
                                                          gpointer            user_data)           : Run Last / Action

The vertical-movement signal is emitted when the pannable area starts a vertical movement.



``hildonpannable``:
  the object which received the signal


``direction``:
  the direction of the movement `HILDON_MOVEMENT_LEFT <HILDON-MOVEMENT-LEFT:CAPS>`_ or `HILDON_MOVEMENT_RIGHT <HILDON-MOVEMENT-RIGHT:CAPS>`_


``initial_x``:
  the x value when the motion started


``initial_y``:
  the y value when the motion started


``user_data``:
  user data set when the signal handler was connected.


Since 2.2

.. _HildonPannableArea.see-also:

See Also
========

:class:`GtkScrolledWindow` .. _HildonEntry:

HildonEntry
***********

.. _HildonEntry.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkEntry
                             +----HildonEntry
  

.. _HildonEntry.implemented-interfaces:

Implemented Interfaces
======================

HildonEntry implements :class:`AtkImplementorIface` , :class:`GtkBuildable` , :class:`GtkEditable` and :class:`GtkCellEditable` .

.. _HildonEntry.description:

Description
===========

The :class:`HildonEntry` is a GTK widget which represents a text entry. It is derived from the :class:`GtkEntry` widget and provides additional commodities specific to the Hildon framework.

Besides all the features inherited from :class:`GtkEntry` , a :class:`HildonEntry` can also have a placeholder text. This text will be shown if the entry is empty and doesn't have the input focus, but it's otherwise ignored. Thus, calls to `hildon_entry_get_text() <hildon-entry-get-text>`_ will never return the placeholder text, not even when it's being displayed.

Although :class:`HildonEntry` is derived from :class:`GtkEntry` , `gtk_entry_get_text() <gtk-entry-get-text>`_ and `gtk_entry_set_text() <gtk-entry-set-text>`_ must never be used to get/set the text in this widget. `hildon_entry_get_text() <hildon-entry-get-text>`_ and `hildon_entry_set_text() <hildon-entry-set-text>`_ must be used instead.

Creating a HildonEntry with a placeholder ========================================= :: GtkWidget * create_entry (void) { GtkWidget *entry; entry = hildon_entry_new (HILDON_SIZE_AUTO); hildon_entry_set_placeholder (HILDON_ENTRY (entry), "First name"); return entry; }



.. _HildonEntry.details:

Details
=======

.. _HildonEntry-struct:

.. class:: HildonEntry

::

  typedef struct _HildonEntry HildonEntry;



.. _hildon-entry-new:

.. function:: hildon_entry_new ()

::

  GtkWidget*          hildon_entry_new                    (HildonSizeType size);

Creates a new entry.



``size``:
  The size of the entry


*Returns*:
  a new :class:`HildonEntry`


Since 2.2

.. _hildon-entry-set-text:

.. function:: hildon_entry_set_text ()

::

  void                hildon_entry_set_text               (HildonEntry *entry,
                                                           const gchar *text);

Sets the text in ``entry`` to ``text``, replacing its current contents.

Note that you must never use `gtk_entry_set_text() <gtk-entry-set-text>`_ to set the text of a :class:`HildonEntry` .



``entry``:
  a :class:`HildonEntry`


``text``:
  the new text


Since 2.2

.. _hildon-entry-get-text:

.. function:: hildon_entry_get_text ()

::

  const str        hildon_entry_get_text               (HildonEntry *entry);

Gets the current text in ``entry``.

Note that you must never use `gtk_entry_get_text() <gtk-entry-get-text>`_ to get the text from a :class:`HildonEntry` .

Also note that placeholder text (set using `hildon_entry_set_placeholder() <hildon-entry-set-placeholder>`_ ) is never returned. Only text set by `hildon_entry_set_text() <hildon-entry-set-text>`_ or typed by the user is considered.



``entry``:
  a :class:`HildonEntry`


*Returns*:
  the text in ``entry``. This text must not be modified or freed.


Since 2.2

.. _hildon-entry-set-placeholder:

.. function:: hildon_entry_set_placeholder ()

::

  void                hildon_entry_set_placeholder        (HildonEntry *entry,
                                                           const gchar *text);

Sets the placeholder text in ``entry`` to ``text``.



``entry``:
  a :class:`HildonEntry`


``text``:
  the new text


Since 2.2

.. _HildonTextView:

HildonTextView
**************

.. _HildonTextView.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkTextView
                                   +----HildonTextView
  

.. _HildonTextView.implemented-interfaces:

Implemented Interfaces
======================

HildonTextView implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonTextView.description:

Description
===========

The :class:`HildonTextView` is a GTK widget which represents a text view. It is derived from the :class:`GtkTextView` widget and provides additional commodities specific to the Hildon framework.

Besides all the features inherited from :class:`GtkTextView` , a :class:`HildonTextView` can also have a placeholder text. This text will be shown if the text view is empty and doesn't have the input focus, but it's otherwise ignored. Thus, calls to `hildon_text_view_get_buffer() <hildon-text-view-get-buffer>`_ will never return the placeholder text, not even when it's being displayed.

Although :class:`HildonTextView` is derived from :class:`GtkTextView` , `gtk_text_view_get_buffer() <gtk-text-view-get-buffer>`_ and `gtk_text_view_set_buffer() <gtk-text-view-set-buffer>`_ must never be used to get/set the buffer in this widget. `hildon_text_view_get_buffer() <hildon-text-view-get-buffer>`_ and `hildon_text_view_set_buffer() <hildon-text-view-set-buffer>`_ must be used instead.

Creating a HildonTextView with a placeholder ============================================ :: GtkWidget * create_text_view (void) { GtkWidget *text_view; text_view = hildon_text_view_new (); hildon_text_view_set_placeholder (HILDON_TEXT_VIEW (text_view), "Type some text here"); return text_view; }



.. _HildonTextView.details:

Details
=======

.. _HildonTextView-struct:

.. class:: HildonTextView

::

  typedef struct _HildonTextView HildonTextView;



.. _hildon-text-view-new:

.. function:: hildon_text_view_new ()

::

  GtkWidget*          hildon_text_view_new                (void);

Creates a new text view.



*Returns*:
  a new :class:`HildonTextView`


Since 2.2

.. _hildon-text-view-set-buffer:

.. function:: hildon_text_view_set_buffer ()

::

  void                hildon_text_view_set_buffer         (HildonTextView *text_view,
                                                           GtkTextBuffer *buffer);

Sets ``buffer`` as the buffer being displayed by ``text_view``. The previous buffer displayed by the text view is unreferenced, and a reference is added to ``buffer``. If you owned a reference to ``buffer``\ before passing it to this function, you must remove that reference yourself

Note that you must never use `gtk_text_view_set_buffer() <gtk-text-view-set-buffer>`_ to set the buffer of a :class:`HildonTextView` .



``text_view``:
  a :class:`HildonTextView`


``buffer``:
  a :class:`GtkTextBuffer`


Since 2.2

.. _hildon-text-view-get-buffer:

.. function:: hildon_text_view_get_buffer ()

::

  GtkTextBuffer*      hildon_text_view_get_buffer         (HildonTextView *text_view);

Returns the text buffer in ``text_view``. The reference count is not incremented; the caller of this function won't own a new reference.

Note that you must never use `gtk_text_view_get_buffer() <gtk-text-view-get-buffer>`_ to get the buffer from a :class:`HildonTextView` .

Also note that placeholder text (set using `hildon_text_view_set_placeholder() <hildon-text-view-set-placeholder>`_ ) is never contained in this buffer.



``text_view``:
  a :class:`HildonTextView`


*Returns*:
  a :class:`GtkTextBuffer`


Since 2.2

.. _hildon-text-view-set-placeholder:

.. function:: hildon_text_view_set_placeholder ()

::

  void                hildon_text_view_set_placeholder    (HildonTextView *text_view,
                                                           const gchar *text);

Sets the placeholder text in ``text_view`` to ``text``.



``text_view``:
  a :class:`HildonTextView`


``text``:
  the new text


Since 2.2

.. _HildonAppMenu:

HildonAppMenu
*************

.. _HildonAppMenu.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkWindow
                                         +----HildonAppMenu
  

.. _HildonAppMenu.implemented-interfaces:

Implemented Interfaces
======================

HildonAppMenu implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonAppMenu.style-properties:

Style Properties
================

::

  
    external-border          int                 : Read
    filter-vertical-spacing  int                 : Read
    horizontal-spacing       int                 : Read
    inner-border             int                 : Read
    vertical-spacing         int                 : Read
  

.. _HildonAppMenu.description:

Description
===========

The :class:`HildonAppMenu` is a GTK widget which represents an application menu in the Hildon framework.

This menu opens from the top of the screen and contains a number of entries (:class:`GtkButton` ) organized in one or two columns, depending on the size of the screen (the number of columns changes automatically if the screen is resized). Entries are added left to right and top to bottom.

Besides that, the :class:`HildonAppMenu` can contain a group of filter buttons (:class:`GtkToggleButton` or :class:`GtkRadioButton` ).

To use a :class:`HildonAppMenu` , add it to a :class:`HildonWindow` using :meth:`HildonWindow.set_app_menu` . The menu will appear when the user presses the window title bar. Alternatively, you can show it by hand using `hildon_app_menu_popup() <hildon-app-menu-popup>`_ .

The menu will be automatically hidden when one of its buttons is clicked. Use `g_signal_connect_after() <g-signal-connect-after>`_ when connecting callbacks to buttons to make sure that they're called after the menu disappears. Alternatively, you can add the button to the menu before connecting any callback.

Although implemented with a :class:`GtkWindow` , :class:`HildonAppMenu` behaves like a normal ref-counted widget, so `g_object_ref() <g-object-ref>`_ , `g_object_unref() <g-object-unref>`_ , `g_object_ref_sink() <g-object-ref-sink>`_ and friends will behave just like with any other non-toplevel widget.

Creating a HildonAppMenu ======================== :: GtkWidget *win; HildonAppMenu *menu; GtkWidget *button; GtkWidget *filter; win = hildon_stackable_window_new (); menu = HILDON_APP_MENU (hildon_app_menu_new ()); // Create a button and add it to the menu button = gtk_button_new_with_label ("Menu command one"); g_signal_connect_after (button, "clicked", G_CALLBACK (button_one_clicked), userdata); hildon_app_menu_append (menu, GTK_BUTTON (button)); // Another button button = gtk_button_new_with_label ("Menu command two"); g_signal_connect_after (button, "clicked", G_CALLBACK (button_two_clicked), userdata); hildon_app_menu_append (menu, GTK_BUTTON (button)); // Create a filter and add it to the menu filter = gtk_radio_button_new_with_label (NULL, "Filter one"); gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (filter), FALSE); g_signal_connect_after (filter, "clicked", G_CALLBACK (filter_one_clicked), userdata); hildon_app_menu_add_filter (menu, GTK_BUTTON (filter)); // Add a new filter filter = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (filter), "Filter two"); gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (filter), FALSE); g_signal_connect_after (filter, "clicked", G_CALLBACK (filter_two_clicked), userdata); hildon_app_menu_add_filter (menu, GTK_BUTTON (filter)); // Show all menu items gtk_widget_show_all (GTK_WIDGET (menu)); // Add the menu to the window hildon_window_set_app_menu (HILDON_WINDOW (win), menu);



.. _HildonAppMenu.details:

Details
=======

.. _HildonAppMenu-struct:

.. class:: HildonAppMenu

::

  typedef struct _HildonAppMenu HildonAppMenu;



.. _hildon-app-menu-new:

.. function:: hildon_app_menu_new ()

::

  GtkWidget*          hildon_app_menu_new                 (void);

Creates a new :class:`HildonAppMenu` .



*Returns*:
  A :class:`HildonAppMenu` .


Since 2.2

.. _hildon-app-menu-append:

.. function:: hildon_app_menu_append ()

::

  void                hildon_app_menu_append              (HildonAppMenu *menu,
                                                           GtkButton *item);

Adds ``item`` to the end of the menu's item list.



``menu``:
  A :class:`HildonAppMenu`


``item``:
  A :class:`GtkButton` to add to the :class:`HildonAppMenu`


Since 2.2

.. _hildon-app-menu-prepend:

.. function:: hildon_app_menu_prepend ()

::

  void                hildon_app_menu_prepend             (HildonAppMenu *menu,
                                                           GtkButton *item);

Adds ``item`` to the beginning of the menu's item list.



``menu``:
  A :class:`HildonAppMenu`


``item``:
  A :class:`GtkButton` to add to the :class:`HildonAppMenu`


Since 2.2

.. _hildon-app-menu-insert:

.. function:: hildon_app_menu_insert ()

::

  void                hildon_app_menu_insert              (HildonAppMenu *menu,
                                                           GtkButton *item,
                                                           int position);

Adds ``item`` to ``menu`` at the position indicated by ``position``.



``menu``:
  A :class:`HildonAppMenu`


``item``:
  A :class:`GtkButton` to add to the :class:`HildonAppMenu`


``position``:
  The position in the item list where ``item`` is added (from 0 to n-1).


Since 2.2

.. _hildon-app-menu-reorder-child:

.. function:: hildon_app_menu_reorder_child ()

::

  void                hildon_app_menu_reorder_child       (HildonAppMenu *menu,
                                                           GtkButton *item,
                                                           int position);

Moves a :class:`GtkButton` to a new position within :class:`HildonAppMenu` .



``menu``:
  A :class:`HildonAppMenu`


``item``:
  A :class:`GtkButton` to move


``position``:
  The new position to place ``item`` (from 0 to n-1).


Since 2.2

.. _hildon-app-menu-add-filter:

.. function:: hildon_app_menu_add_filter ()

::

  void                hildon_app_menu_add_filter          (HildonAppMenu *menu,
                                                           GtkButton *filter);

Adds the ``filter`` to ``menu``.



``menu``:
  A :class:`HildonAppMenu`


``filter``:
  A :class:`GtkButton` to add to the :class:`HildonAppMenu` .


Since 2.2

.. _hildon-app-menu-get-items:

.. function:: hildon_app_menu_get_items ()

::

  GList*              hildon_app_menu_get_items           (HildonAppMenu *menu);

Returns a list of all items (regular items, not filters) contained in ``menu``.



``menu``:
  a :class:`HildonAppMenu`


*Returns*:
  a newly-allocated list containing the items in ``menu``\


Since 2.2

.. _hildon-app-menu-get-filters:

.. function:: hildon_app_menu_get_filters ()

::

  GList*              hildon_app_menu_get_filters         (HildonAppMenu *menu);

Returns a list of all filters contained in ``menu``.



``menu``:
  a :class:`HildonAppMenu`


*Returns*:
  a newly-allocated list containing the filters in ``menu``\


Since 2.2

.. _hildon-app-menu-popup:

.. function:: hildon_app_menu_popup ()

::

  void                hildon_app_menu_popup               (HildonAppMenu *menu,
                                                           GtkWindow *parent_window);

Displays a menu on top of a window and makes it available for selection.



``menu``:
  a :class:`HildonAppMenu`


``parent_window``:
  a :class:`GtkWindow`


Since 2.2

.. _HildonAppMenu.style-property-details:

Style Property Details
======================

.. _HildonAppMenu--external-border:

The ``external-border`` style property

::

    external-border          int                 : Read

Border between the right and left edges of the menu and the screen edges (in horizontal mode).

Default value: 50

.. _HildonAppMenu--filter-vertical-spacing:

The ``filter-vertical-spacing`` style property

::

    filter-vertical-spacing  int                 : Read

Vertical spacing between filters and menu items.

Default value: 8

.. _HildonAppMenu--horizontal-spacing:

The ``horizontal-spacing`` style property

::

    horizontal-spacing       int                 : Read

Horizontal spacing between each menu item. Does not apply to filter buttons.

Default value: 16

.. _HildonAppMenu--inner-border:

The ``inner-border`` style property

::

    inner-border             int                 : Read

Border between menu edges and buttons.

Default value: 16

.. _HildonAppMenu--vertical-spacing:

The ``vertical-spacing`` style property

::

    vertical-spacing         int                 : Read

Vertical spacing between each menu item. Does not apply to filter buttons.

Default value: 16

.. _HildonFindToolbar:

HildonFindToolbar
*****************

.. _HildonFindToolbar.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkToolbar
                                   +----HildonFindToolbar
  

.. _HildonFindToolbar.implemented-interfaces:

Implemented Interfaces
======================

HildonFindToolbar implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonFindToolbar.properties:

Properties
==========

::

  
    column                   int                  : Read / Write
    history-limit            int                  : Read / Write / Construct
    label                    str                : Read / Write / Construct
    list                     GtkListStore*         : Read / Write
    max-characters           int                  : Read / Write / Construct
    prefix                   str                : Read / Write
  

.. _HildonFindToolbar.signals:

Signals
=======

::

  
    close                                          : Run Last
    history-append                                 : Run Last
    invalid-input                                  : Run Last
    search                                         : Run Last
  

.. _HildonFindToolbar.description:

Description
===========

HildonFindToolbar is a toolbar that contains a search entry and a dropdown list with previously searched strings. The list is represented using a :class:`GtkListStore` and can be accesed using a property 'list'. Entries are added automatically to the list when the search button is pressed.



.. _HildonFindToolbar.details:

Details
=======

.. _HildonFindToolbar-struct:

.. class:: HildonFindToolbar

::

  typedef struct _HildonFindToolbar HildonFindToolbar;



.. _hildon-find-toolbar-new:

.. function:: hildon_find_toolbar_new ()

::

  GtkWidget*          hildon_find_toolbar_new             (const gchar *label);

Creates a new HildonFindToolbar.



``label``:
  label for the find_toolbar, NULL to set the label to default "Find"


*Returns*:
  a new HildonFindToolbar


.. _hildon-find-toolbar-new-with-model:

.. function:: hildon_find_toolbar_new_with_model ()

::

  GtkWidget*          hildon_find_toolbar_new_with_model  (const gchar *label,
                                                           GtkListStore *model,
                                                           int column);

Creates a new HildonFindToolbar with a model.



``label``:
  label for the find_toolbar, NULL to set the label to default "Find"


``model``:
  a ``GtkListStore``\


``column``:
  indicating which column the search histry list will retreive string from


*Returns*:
  a new :class:`HildonFindToolbar`


.. _hildon-find-toolbar-highlight-entry:

.. function:: hildon_find_toolbar_highlight_entry ()

::

  void                hildon_find_toolbar_highlight_entry (HildonFindToolbar *ftb,
                                                           bool get_focus);

Highlights the current entry in the find toolbar.



``ftb``:
  find Toolbar whose entry is to be highlighted


``get_focus``:
  if user passes TRUE to this value, then the text in the entry will not only get highlighted, but also get focused.


.. _hildon-find-toolbar-set-active:

.. function:: hildon_find_toolbar_set_active ()

::

  void                hildon_find_toolbar_set_active      (HildonFindToolbar *toolbar,
                                                           int index);

Sets the active item on the toolbar's combo-box. Simply calls gtk_combo_box_set_active on the HildonFindToolbar's combo.



``toolbar``:
  A find toolbar to operate on


``index``:
  An index in the model passed during construction, or -1 to have no active item


.. _hildon-find-toolbar-get-active:

.. function:: hildon_find_toolbar_get_active ()

::

  int                hildon_find_toolbar_get_active      (HildonFindToolbar *toolbar);

Gets the index of the currently active item, or -1 if there's no active item. Simply calls gtk_combo_box_get_active on the HildonFindToolbar's combo.



``toolbar``:
  A find toolbar to query


*Returns*:
  An integer which is the index of the currently active item, or -1 if there's no active item.


.. _hildon-find-toolbar-set-active-iter:

.. function:: hildon_find_toolbar_set_active_iter ()

::

  void                hildon_find_toolbar_set_active_iter (HildonFindToolbar *toolbar,
                                                           GtkTreeIter *iter);

Sets the current active item to be the one referenced by iter. Simply calls gtk_combo_box_set_active_iter on the HildonFindToolbar's combo.



``toolbar``:
  A find toolbar to operate on


``iter``:
  An iter to make active


.. _hildon-find-toolbar-get-active-iter:

.. function:: hildon_find_toolbar_get_active_iter ()

::

  bool            hildon_find_toolbar_get_active_iter (HildonFindToolbar *toolbar,
                                                           GtkTreeIter *iter);

Sets iter to point to the current active item, if it exists. Simply calls gtk_combo_box_get_active_iter on the HildonFindToolbar's combo.



``toolbar``:
  A find toolbar to query


``iter``:
  The uninitialized GtkTreeIter


*Returns*:
  TRUE, if iter was set


.. _hildon-find-toolbar-get-last-index:

.. function:: hildon_find_toolbar_get_last_index ()

::

  int              hildon_find_toolbar_get_last_index  (HildonFindToolbar *toolbar);

Returns the index of the last (most recently added) item in the toolbar. Can be used to set this item active in the history-append signal.



``toolbar``:
  A find toolbar to query


*Returns*:
  Index of the last entry


.. _HildonFindToolbar.property-details:

Property Details
================

.. _HildonFindToolbar--column:

The ``column`` property

::

    column                   int                  : Read / Write

The column number in GtkListStore where strings of search history are kept.



Allowed values: = 0

Default value: 0

.. _HildonFindToolbar--history-limit:

The ``history-limit`` property

::

    history-limit            int                  : Read / Write / Construct

Maximum number of history items in the combobox.



Allowed values: = 0

Default value: 5

.. _HildonFindToolbar--label:

The ``label`` property

::

    label                    str                : Read / Write / Construct

The label to display before the search box.



Default value: "ecdg_ti_find_toolbar_label"

.. _HildonFindToolbar--list:

The ``list`` property

::

    list                     GtkListStore*         : Read / Write

A :class:`GtkListStore` where the search history is kept.



.. _HildonFindToolbar--max-characters:

The ``max-characters`` property

::

    max-characters           int                  : Read / Write / Construct

Maximum number of characters in search string.

Allowed values: [0,65535]

Default value: 0

.. _HildonFindToolbar--prefix:

The ``prefix`` property

::

    prefix                   str                : Read / Write

Search string.

Default value: NULL

.. _HildonFindToolbar.signal-details:

Signal Details
==============

.. _HildonFindToolbar-close:

The ``close`` signal

::

  void                user_function                      (HildonFindToolbar *toolbar,
                                                          gpointer           user_data)      : Run Last

Gets emitted when the close button is pressed.



``toolbar``:
  the toolbar which received the signal


``user_data``:
  user data set when the signal handler was connected.


.. _HildonFindToolbar-history-append:

The ``history-append`` signal

::

  bool            user_function                      (HildonFindToolbar *toolbar,
                                                          gpointer           user_data)      : Run Last

Gets emitted when the current search prefix should be added to history.



``toolbar``:
  the toolbar which received the signal


``user_data``:
  user data set when the signal handler was connected.


.. _HildonFindToolbar-invalid-input:

The ``invalid-input`` signal

::

  void                user_function                      (HildonFindToolbar *toolbar,
                                                          gpointer           user_data)      : Run Last

Gets emitted when the maximum search prefix length is reached and user tries to type more.



``toolbar``:
  the toolbar which received the signal


``user_data``:
  user data set when the signal handler was connected.


.. _HildonFindToolbar-search:

The ``search`` signal

::

  void                user_function                      (HildonFindToolbar *toolbar,
                                                          gpointer           user_data)      : Run Last

Gets emitted when the find button is pressed.



``toolbar``:
  the toolbar which received the signal


``user_data``:
  user data set when the signal handler was connected.


.. _HildonFindToolbar.see-also:

See Also
========

:class:`HildonWindow` .. _HildonEditToolbar:

HildonEditToolbar
*****************

.. _HildonEditToolbar.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBox
                                   +----GtkHBox
                                         +----HildonEditToolbar
  

.. _HildonEditToolbar.implemented-interfaces:

Implemented Interfaces
======================

HildonEditToolbar implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonEditToolbar.style-properties:

Style Properties
================

::

  
    arrow-height             int                 : Read
    arrow-width              int                 : Read
  

.. _HildonEditToolbar.signals:

Signals
=======

::

  
    arrow-clicked                                  : Run First
    button-clicked                                 : Run First
  

.. _HildonEditToolbar.description:

Description
===========

The :class:`HildonEditToolbar` is a toolbar which contains a label and two buttons, one of them being an arrow pointing backwards.

The label is a description of the action that the user is supposed to do. The button is to be pressed when the user completes the action. The arrow is used to go back to the previous view discarding any changes.

Note that those widgets don't do anything themselves by default. To actually peform actions the developer must provide callbacks for them.

To add a :class:`HildonEditToolbar` to a window use `hildon_window_set_edit_toolbar() <hildon-window-set-edit-toolbar>`_ .

HildonEditToolbar example ========================= :: GtkWidget *window; GtkWidget *toolbar; // Declare more widgets here ... window = hildon_stackable_window_new (); toolbar = hildon_edit_toolbar_new_with_text ("Choose items to delete", "Delete"); // Create more widgets here ... // Add toolbar to window hildon_window_set_edit_toolbar (HILDON_WINDOW (window), HILDON_EDIT_TOOLBAR (toolbar)); // Add other widgets ... g_signal_connect (toolbar, "button-clicked", G_CALLBACK (delete_button_clicked), someparameter); g_signal_connect_swapped (toolbar, "arrow-clicked", G_CALLBACK (gtk_widget_destroy), window); gtk_widget_show_all (window); gtk_window_fullscreen (GTK_WINDOW (window));



.. _HildonEditToolbar.details:

Details
=======

.. _HildonEditToolbar-struct:

.. class:: HildonEditToolbar

::

  typedef struct _HildonEditToolbar HildonEditToolbar;



.. _hildon-edit-toolbar-new:

.. function:: hildon_edit_toolbar_new ()

::

  GtkWidget*          hildon_edit_toolbar_new             (void);

Creates a new :class:`HildonEditToolbar` .



*Returns*:
  a new :class:`HildonEditToolbar`


Since 2.2

.. _hildon-edit-toolbar-new-with-text:

.. function:: hildon_edit_toolbar_new_with_text ()

::

  GtkWidget*          hildon_edit_toolbar_new_with_text   (const gchar *label,
                                                           const gchar *button);

Creates a new :class:`HildonEditToolbar` , with the toolbar label set to ``label`` and the button label set to ``button``.



``label``:
  Text for the toolbar label.


``button``:
  Text for the toolbar button.


*Returns*:
  a new :class:`HildonEditToolbar`


Since 2.2

.. _hildon-edit-toolbar-set-label:

.. function:: hildon_edit_toolbar_set_label ()

::

  void                hildon_edit_toolbar_set_label       (HildonEditToolbar *toolbar,
                                                           const gchar *label);

Sets the label of ``toolbar`` to ``label``. This will clear any previously set value.



``toolbar``:
  a :class:`HildonEditToolbar`


``label``:
  a new text for the toolbar label


Since 2.2

.. _hildon-edit-toolbar-set-button-label:

.. function:: hildon_edit_toolbar_set_button_label ()

::

  void                hildon_edit_toolbar_set_button_label
                                                          (HildonEditToolbar *toolbar,
                                                           const gchar *label);

Sets the label of the toolbar button to ``label``. This will clear any previously set value.



``toolbar``:
  a :class:`HildonEditToolbar`


``label``:
  a new text for the label of the toolbar button


Since 2.2

.. _HildonEditToolbar.style-property-details:

Style Property Details
======================

.. _HildonEditToolbar--arrow-height:

The ``arrow-height`` style property

::

    arrow-height             int                 : Read

Height of the arrow button.

Default value: 56

.. _HildonEditToolbar--arrow-width:

The ``arrow-width`` style property

::

    arrow-width              int                 : Read

Width of the arrow button.

Default value: 112

.. _HildonEditToolbar.signal-details:

Signal Details
==============

.. _HildonEditToolbar-arrow-clicked:

The ``arrow-clicked`` signal

::

  void                user_function                      (HildonEditToolbar *widget,
                                                          gpointer           user_data)      : Run First

Emitted when the toolbar back button (arrow) has been activated (pressed and released).



``widget``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


Since 2.2

.. _HildonEditToolbar-button-clicked:

The ``button-clicked`` signal

::

  void                user_function                      (HildonEditToolbar *widget,
                                                          gpointer           user_data)      : Run First

Emitted when the toolbar button has been activated (pressed and released).



``widget``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


Since 2.2

.. _HildonWizardDialog:

HildonWizardDialog
******************

.. _HildonWizardDialog.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkWindow
                                         +----GtkDialog
                                               +----HildonWizardDialog
  

.. _HildonWizardDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonWizardDialog implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonWizardDialog.properties:

Properties
==========

::

  
    autotitle                bool              : Read / Write
    wizard-name              str                : Read / Write
    wizard-notebook          GtkNotebook*          : Read / Write
  

.. _HildonWizardDialog.description:

Description
===========

:class:`HildonWizardDialog` is a widget to create a guided installation process. The dialog has three standard buttons, previous, next, finish, and contains several pages.

Response buttons are dimmed/undimmed automatically. The notebook widget provided by users contains the actual wizard pages.

Usage of the API is very simple, it has only one function to create it and the rest of it is handled by developers notebook. Also, the response is returned, either cancel or finish. Next and previous buttons are handled by the wizard dialog it self, by switching the page either forward or backward in the notebook.

It is possible to determinate whether users can go to the next page by setting a :class:`HildonWizardDialogPageFunc` function with `hildon_wizard_dialog_set_forward_page_func() <hildon-wizard-dialog-set-forward-page-func>`_



.. _HildonWizardDialog.details:

Details
=======

.. _HildonWizardDialogResponse:

.. :: enum HildonWizardDialogResponse

::

  typedef enum
  {
      HILDON_WIZARD_DIALOG_CANCEL = GTK_RESPONSE_CANCEL,
      HILDON_WIZARD_DIALOG_PREVIOUS = 0,
      HILDON_WIZARD_DIALOG_NEXT,
      HILDON_WIZARD_DIALOG_FINISH
  }                                               HildonWizardDialogResponse;
  

Predefined values for use as response ids for :class:`HildonWizardDialog` .

.. warning:: HILDON_WIZARD_DIALOG_CANCEL is deprecated and should not be used in newly-written code.



``HILDON_WIZARD_DIALOG_CANCEL``
  Returned by the 'Cancel' button.


``HILDON_WIZARD_DIALOG_PREVIOUS``
  Returned by the 'Previous' button.


``HILDON_WIZARD_DIALOG_NEXT``
  Returned by the 'Next' button.


``HILDON_WIZARD_DIALOG_FINISH``
  Returned by the 'Finish' button.


.. _HildonWizardDialog-struct:

.. class:: HildonWizardDialog

::

  typedef struct _HildonWizardDialog HildonWizardDialog;



.. _HildonWizardDialogPageFunc:

.. function:: HildonWizardDialogPageFunc ()

::

  bool            (*HildonWizardDialogPageFunc)       (GtkNotebook *notebook,
                                                           int current_page,
                                                           gpointer data);



``notebook``:
  


``current_page``:
  


``data``:
  


*Returns*:
  


.. _hildon-wizard-dialog-new:

.. function:: hildon_wizard_dialog_new ()

::

  GtkWidget*          hildon_wizard_dialog_new            (GtkWindow *parent,
                                                           const char *wizard_name,
                                                           GtkNotebook *notebook);

Creates a new :class:`HildonWizardDialog` .



``parent``:
  a :class:`GtkWindow`


``wizard_name``:
  the name of dialog


``notebook``:
  the notebook to be shown on the dialog


*Returns*:
  a new :class:`HildonWizardDialog`


.. _hildon-wizard-dialog-set-forward-page-func:

.. function:: hildon_wizard_dialog_set_forward_page_func ()

::

  void                hildon_wizard_dialog_set_forward_page_func
                                                          (HildonWizardDialog *wizard_dialog,
                                                           HildonWizardDialogPageFunc page_func,
                                                           gpointer data,
                                                           GDestroyNotify destroy);

Sets the page forwarding function to be ``page_func``. This function will be used to determine whether it is possible to go to the next page when the user presses the forward button. Setting ``page_func`` to ```NULL`` <NULL:CAPS>`_ wil make the wizard to simply go always to the next page.



``wizard_dialog``:
  a :class:`HildonWizardDialog`


``page_func``:
  the :class:`HildonWizardDialogPageFunc`


``data``:
  user data for ``page_func``\


``destroy``:
  destroy notifier for ``data``\


Since 2.2

.. _HildonWizardDialog.property-details:

Property Details
================

.. _HildonWizardDialog--autotitle:

The ``autotitle`` property

::

    autotitle                bool              : Read / Write

If the wizard should automatically try to change the window title when changing steps. Set to FALSE if you'd like to override the default behaviour.



Default value: TRUE

Since 0.14.5

.. _HildonWizardDialog--wizard-name:

The ``wizard-name`` property

::

    wizard-name              str                : Read / Write

The name of the wizard.



Default value: NULL

.. _HildonWizardDialog--wizard-notebook:

The ``wizard-notebook`` property

::

    wizard-notebook          GtkNotebook*          : Read / Write

The notebook object, which is used by the HildonWizardDialog.



.. _HildonPickerDialog:

HildonPickerDialog
******************

.. _HildonPickerDialog.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkBin
                                   +----GtkWindow
                                         +----GtkDialog
                                               +----HildonDialog
                                                     +----HildonPickerDialog
  

.. _HildonPickerDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonPickerDialog implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

.. _HildonPickerDialog.properties:

Properties
==========

::

  
    center-on-show           bool              : Read / Write / Construct
    done-button-text         str                : Read / Write / Construct
  

.. _HildonPickerDialog.description:

Description
===========

:class:`HildonPickerDialog` is a dialog that is used to show a :class:`HildonTouchSelector` widget and a 'Done' button to allow users to finish their selections.

The :class:`HildonPickerDialog` will show a 'Done' button in case the :class:`HildonTouchSelector` allows multiple selection. The label of the button can be set using `hildon_picker_dialog_set_done_label() <hildon-picker-dialog-set-done-label>`_ and retrieved using `hildon_picker_dialog_get_done_label() <hildon-picker-dialog-get-done-label>`_

Note that in most cases developers don't need to deal directly with this widget. :class:`HildonPickerButton` is designed to pop up a :class:`HildonPickerDialog` and manage the interaction with it.



.. _HildonPickerDialog.details:

Details
=======

.. _HILDON-DISABLE-DEPRECATED:CAPS:

.. :: HILDON_DISABLE_DEPRECATED

::

    #define HILDON_DISABLE_DEPRECATED
  



.. _HildonPickerDialog-struct:

.. class:: HildonPickerDialog

::

  typedef struct _HildonPickerDialog HildonPickerDialog;

Button label



Since 2.2

.. _hildon-picker-dialog-new:

.. function:: hildon_picker_dialog_new ()

::

  GtkWidget*          hildon_picker_dialog_new            (GtkWindow *parent);

Creates a new :class:`HildonPickerDialog`



``parent``:
  the parent window


*Returns*:
  a new :class:`HildonPickerDialog`


Since 2.2

.. _hildon-picker-dialog-set-selector:

.. function:: hildon_picker_dialog_set_selector ()

::

  bool            hildon_picker_dialog_set_selector   (HildonPickerDialog *dialog,
                                                           HildonTouchSelector *selector);

Sets ``selector`` as the :class:`HildonTouchSelector` to be shown in ``dialog``



``dialog``:
  a :class:`HildonPickerDialog`


``selector``:
  a :class:`HildonTouchSelector`


*Returns*:
  ```TRUE`` <TRUE:CAPS>`_ if ``selector`` was set, ```FALSE`` <FALSE:CAPS>`_ otherwise


Since 2.2

.. _hildon-picker-dialog-set-done-label:

.. function:: hildon_picker_dialog_set_done_label ()

::

  void                hildon_picker_dialog_set_done_label (HildonPickerDialog *dialog,
                                                           const gchar *label);

Sets a custom string to be used as the 'Done' button label in ``dialog``.



``dialog``:
  a :class:`HildonPickerDialog`


``label``:
  a string


Since 2.2

.. _hildon-picker-dialog-get-done-label:

.. function:: hildon_picker_dialog_get_done_label ()

::

  const str        hildon_picker_dialog_get_done_label (HildonPickerDialog *dialog);

Retrieves current 'Done' button label.



``dialog``:
  a :class:`HildonPickerDialog`


*Returns*:
  the custom string to be used.


Since 2.2

.. _hildon-picker-dialog-get-selector:

.. function:: hildon_picker_dialog_get_selector ()

::

  HildonTouchSelector* hildon_picker_dialog_get_selector  (HildonPickerDialog *dialog);

Retrieves the :class:`HildonTouchSelector` associated to ``dialog``.



``dialog``:
  a :class:`HildonPickerDialog`


*Returns*:
  a :class:`HildonTouchSelector`


Since 2.2

.. _HildonPickerDialog.property-details:

Property Details
================

.. _HildonPickerDialog--center-on-show:

The ``center-on-show`` property

::

    center-on-show           bool              : Read / Write / Construct

If the dialog should center on the current selection when it is showed.

Default value: TRUE

.. _HildonPickerDialog--done-button-text:

The ``done-button-text`` property

::

    done-button-text         str                : Read / Write / Construct

Done Button Label.

Default value: "wdgt_bd_done"

.. _hildon-HildonAnimationActor:

HildonAnimationActor
********************

.. _hildon-HildonAnimationActor.description:

Description
===========



.. _hildon-HildonAnimationActor.details:

Details
=======

.. _HildonAnimationActor:

.. class:: HildonAnimationActor

::

  typedef struct {
      GtkWindow parent;
  } HildonAnimationActor;
  



.. _hildon-animation-actor-new:

.. function:: hildon_animation_actor_new ()

::

  GtkWidget*          hildon_animation_actor_new          (void);

Creates a new :class:`HildonAnimationActor` .



*Returns*:
  A :class:`HildonAnimationActor`


Since 2.2

.. _hildon-animation-actor-send-message:

.. function:: hildon_animation_actor_send_message ()

::

  void                hildon_animation_actor_send_message (HildonAnimationActor *self,
                                                           int message_type,
                                                           int l0,
                                                           int l1,
                                                           int l2,
                                                           int l3,
                                                           int l4);

Sends an X11 ClientMessage event to the window manager with the specified parameters -- id (``message_type``) and data (``l0``, ``l1``, ``l2``, ``l3``, ``l4``).

This is an internal utility function that application will not need to call directly.



``self``:
  A :class:`HildonAnimationActor`


``message_type``:
  Message id for the animation actor message.


``l0``:
  1st animation actor message parameter.


``l1``:
  2nd animation actor message parameter.


``l2``:
  3rd animation actor message parameter.


``l3``:
  4th animation actor message parameter.


``l4``:
  5th animation actor message parameter.


Since 2.2

.. _hildon-animation-actor-set-anchor:

.. function:: hildon_animation_actor_set_anchor ()

::

  void                hildon_animation_actor_set_anchor   (HildonAnimationActor *self,
                                                           int x,
                                                           int y);

Send a message to the window manager setting the anchor point for the animation actor. The anchor point is the point to which the actor position within its parent it is relative.

If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonAnimationActor`


``x``:
  The X coordinate of the anchor point.


``y``:
  The Y coordinate of the anchor point.


Since 2.2

.. _hildon-animation-actor-set-anchor-from-gravity:

.. function:: hildon_animation_actor_set_anchor_from_gravity ()

::

  void                hildon_animation_actor_set_anchor_from_gravity
                                                          (HildonAnimationActor *self,
                                                           int gravity);

Send a message to the window manager setting the anchor point for the animation actor. The anchor point is the point to which the actor position within its parent it is relative. Instead of being defined in (x, y)-coordinates, the anchor point is defined in the relative "gravity" constant as:

\* ```HILDON_AA_N_GRAVITY`` <HILDON-AA-N-GRAVITY:CAPS>`_ translates to (width / 2, 0) coordinate \* ```HILDON_AA_NE_GRAVITY`` <HILDON-AA-NE-GRAVITY:CAPS>`_ translates to (width, 0) coordinate \* ```HILDON_AA_E_GRAVITY`` <HILDON-AA-E-GRAVITY:CAPS>`_ translates to (width, height / 2) coordinate \* ```HILDON_AA_SE_GRAVITY`` <HILDON-AA-SE-GRAVITY:CAPS>`_ translates to (width, height) coordinate \* ```HILDON_AA_S_GRAVITY`` <HILDON-AA-S-GRAVITY:CAPS>`_ translates to (width / 2, height) coordinate \* ```HILDON_AA_SW_GRAVITY`` <HILDON-AA-SW-GRAVITY:CAPS>`_ translates to (0, height) coordinate \* ```HILDON_AA_W_GRAVITY`` <HILDON-AA-W-GRAVITY:CAPS>`_ translates to (0, height / 2) coordinate \* ```HILDON_AA_NW_GRAVITY`` <HILDON-AA-NW-GRAVITY:CAPS>`_ translates to (0, 0) coordinate \* ```HILDON_AA_CENTER_GRAVITY`` <HILDON-AA-CENTER-GRAVITY:CAPS>`_ translates to (width / 2, height / 2) coordinate

If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonAnimationActor`


``gravity``:
  The gravity constant.


Since 2.2

.. _hildon-animation-actor-set-depth:

.. function:: hildon_animation_actor_set_depth ()

::

  void                hildon_animation_actor_set_depth    (HildonAnimationActor *self,
                                                           int depth);

A shortcut for `hildon_animation_actor_set_position_full() <hildon-animation-actor-set-position-full>`_ , changing the window depth, but preserving it's position.



``self``:
  A :class:`HildonAnimationActor`


``depth``:
  Desired window depth (Z coordinate)


Since 2.2

.. _hildon-animation-actor-set-opacity:

.. function:: hildon_animation_actor_set_opacity ()

::

  void                hildon_animation_actor_set_opacity  (HildonAnimationActor *self,
                                                           int opacity);

This function is a shortcut for `hildon_animation_actor_set_show_full() <hildon-animation-actor-set-show-full>`_ , setting actor opacity without changing it's overall visibility.

See `hildon_animation_actor_set_show_full() <hildon-animation-actor-set-show-full>`_ for description of the range of values ``opacity`` argument takes.



``self``:
  A :class:`HildonAnimationActor`


``opacity``:
  Desired opacity setting


Since 2.2

.. _hildon-animation-actor-set-parent:

.. function:: hildon_animation_actor_set_parent ()

::

  void                hildon_animation_actor_set_parent   (HildonAnimationActor *self,
                                                           GtkWindow *parent);

Send a message to the window manager setting the parent window for the animation actor. Parenting an actor will not affect the X window that the HildonAnimationActor represents, but it's off-screen bitmap as it is handled by the compositing window manager.

Parenting an animation actor will affect its visibility as set by the `gtk_widget_show() <gtk-widget-show>`_ , `gtk_widget_hide() <gtk-widget-hide>`_ and `hildon_animation_actor_set_show() <hildon-animation-actor-set-show>`_ . The animation actor will only be visible when the top-level window it is parented is visible.

Passing ```NULL`` <NULL:CAPS>`_ as a ``parent`` argument will unparent the animation actor. This will restore the actor's visibility if it was suppressed by being unparented or parented to an unmapped window.

If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonAnimationActor`


``parent``:
  A :class:`GtkWindow` that the actor will be parented to.


Since 2.2

.. _hildon-animation-actor-set-position:

.. function:: hildon_animation_actor_set_position ()

::

  void                hildon_animation_actor_set_position (HildonAnimationActor *self,
                                                           int x,
                                                           int y);

A shortcut for `hildon_animation_actor_set_position_full() <hildon-animation-actor-set-position-full>`_ , changing the window position, but preserving it's depth setting.



``self``:
  A :class:`HildonAnimationActor`


``x``:
  Desired window X coordinate


``y``:
  Desired window Y coordinate


Since 2.2

.. _hildon-animation-actor-set-position-full:

.. function:: hildon_animation_actor_set_position_full ()

::

  void                hildon_animation_actor_set_position_full
                                                          (HildonAnimationActor *self,
                                                           int x,
                                                           int y,
                                                           int depth);

Send a message to the window manager setting the position of the animation actor. This will set the position of the animation actor off-screen bitmap as it is rendered to the screen. The position of the actor is relative to the parent window. The actor is also subject to the animation effects rendered by the compositing window manager on that window (like those by task switcher).

The window depth affects the stacking of animation actors within a parent window and, more generally, the stacking of clutter actors within a stage/container. The default depth is 0 and a parent window's container will have it's window texture stacked at that level. The stacking at any depth level is sequential -- animation actor B created/parented after animation actor A will obscure the latter if they overlap.

Animation actors with non-zero depth settings are subject to scaling as per the global scene perspective setup, which limits the depth setting as the primary parameter to control the stacking order. Since the stacking order follows the parenting order, it may be better to use `hildon_animation_actor_set_parent() <hildon-animation-actor-set-parent>`_ for setting the stacking.

If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonAnimationActor`


``x``:
  Desired X coordinate


``y``:
  Desired Y coordinate


``depth``:
  Desired window depth (Z coordinate)


Since 2.2

.. _hildon-animation-actor-set-rotation:

.. function:: hildon_animation_actor_set_rotation ()

::

  void                hildon_animation_actor_set_rotation (HildonAnimationActor *self,
                                                           int axis,
                                                           double degrees,
                                                           int x,
                                                           int y,
                                                           int z);

Send a message to the window manager setting the animation actor rotation around one of the three axes. The rotation center coordinates depend on the axis of rotation:

\* ```HILDON_AA_X_AXIS`` <HILDON-AA-X-AXIS:CAPS>`_ requires ``y`` and ``z`` coordinates. \* ```HILDON_AA_Y_AXIS`` <HILDON-AA-Y-AXIS:CAPS>`_ requires ``x`` and ``z`` coordinates. \* ```HILDON_AA_Z_AXIS`` <HILDON-AA-Z-AXIS:CAPS>`_ requires ``x`` and ``y`` coordinates.

If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonAnimationActor`


``axis``:
  The rotation axis.


``degrees``:
  The rotation angle in degrees.


``x``:
  Center of the rotation, X coordinate.


``y``:
  Center of the rotation, Y coordinate.


``z``:
  Center of the rotation, Z coordinate.


Since 2.2

.. _hildon-animation-actor-set-rotationx:

.. function:: hildon_animation_actor_set_rotationx ()

::

  void                hildon_animation_actor_set_rotationx
                                                          (HildonAnimationActor *self,
                                                           int axis,
                                                           int degrees,
                                                           int x,
                                                           int y,
                                                           int z);

This function is just like `hildon_animation_actor_set_rotation() <hildon-animation-actor-set-rotation>`_ , but the rotation angle is given as 16-bit fixed-point number.



``self``:
  A :class:`HildonAnimationActor`


``axis``:
  The rotation axis.


``degrees``:
  The rotation angle in degrees.


``x``:
  Center of the rotation, X coordinate.


``y``:
  Center of the rotation, Y coordinate.


``z``:
  Center of the rotation, Z coordinate.


Since 2.2

.. _hildon-animation-actor-set-scale:

.. function:: hildon_animation_actor_set_scale ()

::

  void                hildon_animation_actor_set_scale    (HildonAnimationActor *self,
                                                           double x_scale,
                                                           double y_scale);

Send a message to the window manager setting the scale factors of the animation actor. This will set the scale factors on the animation actor off-screen bitmap as it is rendered to the screen. If the animation actor is parented to another top-level window, the animation effects rendered by the compositing window manager on that top-level window (like those by task switcher) will also affect the animation actor.

If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonAnimationActor`


``x_scale``:
  Window's desired scale factor along the X-axis


``y_scale``:
  Window's desired scale factor along the Y-axis


Since 2.2

.. _hildon-animation-actor-set-scalex:

.. function:: hildon_animation_actor_set_scalex ()

::

  void                hildon_animation_actor_set_scalex   (HildonAnimationActor *self,
                                                           int x_scale,
                                                           int y_scale);

This function is just like `hildon_animation_actor_set_scale() <hildon-animation-actor-set-scale>`_ , but the scale factors are given as 16-bit fixed-point number.



``self``:
  A :class:`HildonAnimationActor`


``x_scale``:
  Window's desired scale factor along the X-axis


``y_scale``:
  Window's desired scale factor along the Y-axis


Since 2.2

.. _hildon-animation-actor-set-show:

.. function:: hildon_animation_actor_set_show ()

::

  void                hildon_animation_actor_set_show     (HildonAnimationActor *self,
                                                           int show);

This function is a shortcut for `hildon_animation_actor_set_show_full() <hildon-animation-actor-set-show-full>`_ , setting the overall actor visibility without changing it's opacity setting.



``self``:
  A :class:`HildonAnimationActor`


``show``:
  A boolean flag setting the visibility of the animation actor.


Since 2.2

.. _hildon-animation-actor-set-show-full:

.. function:: hildon_animation_actor_set_show_full ()

::

  void                hildon_animation_actor_set_show_full
                                                          (HildonAnimationActor *self,
                                                           int show,
                                                           int opacity);

Send a message to the window manager setting the visibility of the animation actor. This will only affect the visibility of the animation actor set by the compositing window manager in its own rendering pipeline, after X has drawn the window to the off-screen buffer. This setting, naturally, has no effect if the :class:`HildonAnimationActor` widget is not visible in X11 terms (i.e. realized and mapped).

Furthermore, if a widget is parented, its final visibility will be affected by that of the parent window.

The opacity setting ranges from zero (0), being completely transparent to 255 (0xff) being fully opaque.

If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonAnimationActor`


``show``:
  A boolean flag setting the visibility of the animation actor.


``opacity``:
  Desired opacity setting


Since 2.2

.. _HILDON-AA-CENTER-GRAVITY:CAPS:

.. :: HILDON_AA_CENTER_GRAVITY

::

  #define HILDON_AA_CENTER_GRAVITY    9
  



.. _HILDON-AA-E-GRAVITY:CAPS:

.. :: HILDON_AA_E_GRAVITY

::

  #define HILDON_AA_E_GRAVITY	    3
  



.. _HILDON-AA-NE-GRAVITY:CAPS:

.. :: HILDON_AA_NE_GRAVITY

::

  #define HILDON_AA_NE_GRAVITY	    2
  



.. _HILDON-AA-NW-GRAVITY:CAPS:

.. :: HILDON_AA_NW_GRAVITY

::

  #define HILDON_AA_NW_GRAVITY	    8
  



.. _HILDON-AA-N-GRAVITY:CAPS:

.. :: HILDON_AA_N_GRAVITY

::

  #define HILDON_AA_N_GRAVITY	    1
  



.. _HILDON-AA-SE-GRAVITY:CAPS:

.. :: HILDON_AA_SE_GRAVITY

::

  #define HILDON_AA_SE_GRAVITY	    4
  



.. _HILDON-AA-SW-GRAVITY:CAPS:

.. :: HILDON_AA_SW_GRAVITY

::

  #define HILDON_AA_SW_GRAVITY	    6
  



.. _HILDON-AA-S-GRAVITY:CAPS:

.. :: HILDON_AA_S_GRAVITY

::

  #define HILDON_AA_S_GRAVITY	    5
  



.. _HILDON-AA-W-GRAVITY:CAPS:

.. :: HILDON_AA_W_GRAVITY

::

  #define HILDON_AA_W_GRAVITY	    7
  



.. _HILDON-AA-X-AXIS:CAPS:

.. :: HILDON_AA_X_AXIS

::

  #define HILDON_AA_X_AXIS	    0
  



.. _HILDON-AA-Y-AXIS:CAPS:

.. :: HILDON_AA_Y_AXIS

::

  #define HILDON_AA_Y_AXIS	    1
  



.. _HILDON-AA-Z-AXIS:CAPS:

.. :: HILDON_AA_Z_AXIS

::

  #define HILDON_AA_Z_AXIS	    2
  



.. _hildon-HildonRemoteTexture:

HildonRemoteTexture
*******************

.. _hildon-HildonRemoteTexture.description:

Description
===========

The :class:`HildonRemoteTexture` is a GTK+ widget which allows the rendering of a shared memory area within hildon-desktop. It allows the memory area to be positioned and scaled, without altering its' contents.



.. _hildon-HildonRemoteTexture.details:

Details
=======

.. _HildonRemoteTexture:

.. class:: HildonRemoteTexture

::

  typedef struct {
      GtkWindow parent;
  } HildonRemoteTexture;
  



.. _hildon-remote-texture-new:

.. function:: hildon_remote_texture_new ()

::

  GtkWidget*          hildon_remote_texture_new           (void);

Creates a new :class:`HildonRemoteTexture` .



*Returns*:
  A :class:`HildonRemoteTexture`


Since 2.2

.. _hildon-remote-texture-send-message:

.. function:: hildon_remote_texture_send_message ()

::

  void                hildon_remote_texture_send_message  (HildonRemoteTexture *self,
                                                           int message_type,
                                                           int l0,
                                                           int l1,
                                                           int l2,
                                                           int l3,
                                                           int l4);

Sends an X11 ClientMessage event to the window manager with the specified parameters -- id (``message_type``) and data (``l0``, ``l1``, ``l2``, ``l3``, ``l4``).

This is an internal utility function that application will not need to call directly.



``self``:
  A :class:`HildonRemoteTexture`


``message_type``:
  Message id for the remote texture message.


``l0``:
  1st remote texture message parameter.


``l1``:
  2nd remote texture message parameter.


``l2``:
  3rd remote texture message parameter.


``l3``:
  4th remote texture message parameter.


``l4``:
  5th remote texture message parameter.


Since 2.2

.. _hildon-remote-texture-set-image:

.. function:: hildon_remote_texture_set_image ()

::

  void                hildon_remote_texture_set_image     (HildonRemoteTexture *self,
                                                           key_t key,
                                                           int width,
                                                           int height,
                                                           int bpp);





``self``:
  A :class:`HildonRemoteTexture`


``key``:
  The key that would be used with shmget in hildon-desktop. The key should probably be created with ftok, and the relevant shared memory area should be created before this call.


``width``:
  width of image in pixels


``height``:
  height of image in pixels


``bpp``:
  BYTES per pixel - usually 2,3 or 4


Since 2.2

.. _hildon-remote-texture-set-offset:

.. function:: hildon_remote_texture_set_offset ()

::

  void                hildon_remote_texture_set_offset    (HildonRemoteTexture *self,
                                                           double x,
                                                           double y);

Send a message to the window manager setting the offset of the remote texture in the window (in Remote texture's pixels). The texture is also subject to the animation effects rendered by the compositing window manager on that window (like those by task switcher).

If the remote texture WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonRemoteTexture`


``x``:
  Desired X offset


``y``:
  Desired Y offset


Since 2.2

.. _hildon-remote-texture-set-opacity:

.. function:: hildon_remote_texture_set_opacity ()

::

  void                hildon_remote_texture_set_opacity   (HildonRemoteTexture *self,
                                                           int opacity);

This function is a shortcut for `hildon_remote_texture_set_show_full() <hildon-remote-texture-set-show-full>`_ , setting actor opacity without changing it's overall visibility.

See `hildon_remote_texture_set_show_full() <hildon-remote-texture-set-show-full>`_ for description of the range of values ``opacity`` argument takes.



``self``:
  A :class:`HildonRemoteTexture`


``opacity``:
  Desired opacity setting


Since 2.2

.. _hildon-remote-texture-set-parent:

.. function:: hildon_remote_texture_set_parent ()

::

  void                hildon_remote_texture_set_parent    (HildonRemoteTexture *self,
                                                           GtkWindow *parent);

Send a message to the window manager setting the parent window for the remote texture. Parenting an actor will not affect the X window that the HildonRemoteTexture represents, but it's off-screen bitmap as it is handled by the compositing window manager.

Parenting an remote texture will affect its visibility as set by the `gtk_widget_show() <gtk-widget-show>`_ , `gtk_widget_hide() <gtk-widget-hide>`_ and `hildon_remote_texture_set_show() <hildon-remote-texture-set-show>`_ . The remote texture will only be visible when the top-level window it is parented is visible.

Passing ```NULL`` <NULL:CAPS>`_ as a ``parent`` argument will unparent the remote texture. This will restore the actor's visibility if it was suppressed by being unparented or parented to an unmapped window.

If the remote texture WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonRemoteTexture`


``parent``:
  A :class:`GtkWindow` that the actor will be parented to.


Since 2.2

.. _hildon-remote-texture-set-position:

.. function:: hildon_remote_texture_set_position ()

::

  void                hildon_remote_texture_set_position  (HildonRemoteTexture *self,
                                                           int x,
                                                           int y,
                                                           int width,
                                                           int height);

Send a message to the window manager setting the offset of the remote texture in the window (in Remote texture's pixels). The texture is also subject to the animation effects rendered by the compositing window manager on that window (like those by task switcher).

If the remote texture WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonRemoteTexture`


``x``:
  Desired X coordinate


``y``:
  Desired Y coordinate


``width``:
  Desired width


``height``:
  Desired height


Since 2.2

.. _hildon-remote-texture-set-scale:

.. function:: hildon_remote_texture_set_scale ()

::

  void                hildon_remote_texture_set_scale     (HildonRemoteTexture *self,
                                                           double x_scale,
                                                           double y_scale);



``self``:
  


``x_scale``:
  


``y_scale``:
  


.. _hildon-remote-texture-set-show:

.. function:: hildon_remote_texture_set_show ()

::

  void                hildon_remote_texture_set_show      (HildonRemoteTexture *self,
                                                           int show);

This function is a shortcut for `hildon_remote_texture_set_show_full() <hildon-remote-texture-set-show-full>`_ , setting the overall actor visibility without changing it's opacity setting.



``self``:
  A :class:`HildonRemoteTexture`


``show``:
  A boolean flag setting the visibility of the remote texture.


Since 2.2

.. _hildon-remote-texture-set-show-full:

.. function:: hildon_remote_texture_set_show_full ()

::

  void                hildon_remote_texture_set_show_full (HildonRemoteTexture *self,
                                                           int show,
                                                           int opacity);

Send a message to the window manager setting the visibility of the remote texture. This will only affect the visibility of the remote texture set by the compositing window manager in its own rendering pipeline, after X has drawn the window to the off-screen buffer. This setting, naturally, has no effect if the :class:`HildonRemoteTexture` widget is not visible in X11 terms (i.e. realized and mapped).

Furthermore, if a widget is parented, its final visibility will be affected by that of the parent window.

The opacity setting ranges from zero (0), being completely transparent to 255 (0xff) being fully opaque.

If the remote texture WM-counterpart is not ready, the show message will be queued until the WM is ready for it.



``self``:
  A :class:`HildonRemoteTexture`


``show``:
  A boolean flag setting the visibility of the remote texture.


``opacity``:
  Desired opacity setting


Since 2.2

.. _hildon-remote-texture-update-area:

.. function:: hildon_remote_texture_update_area ()

::

  void                hildon_remote_texture_update_area   (HildonRemoteTexture *self,
                                                           int x,
                                                           int y,
                                                           int width,
                                                           int height);

This signals to hildon-desktop that a specific region of the memory area has changed. This will trigger a redraw and will update the relevant tiles of the texture.



``self``:
  A :class:`HildonRemoteTexture`


``x``:
  offset of damaged area in pixels


``y``:
  offset of damaged area in pixels


``width``:
  width of damaged area in pixels


``height``:
  height of damaged area in pixels


Since 2.2


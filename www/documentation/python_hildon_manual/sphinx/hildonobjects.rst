.. module:: hildon

Hildon Widgets and Objects
##########################

Window
******

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
                                         +----Window
                                               +----HildonStackableWindow

Implemented Interfaces
======================

Window implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Signals
=======

::

    clipboard-operation                            : Run First


Description
===========

:class:`Window` is a GTK widget which represents a top-level window in the Hildon framework. It is derived from :class:`gtk.Window` and provides additional commodities specific to the Hildon framework.

:class:`Window` s can have a menu attached, which is toggled with a hardware key or by tapping on the window frame. This menu can be either a :class:`GtkMenu` or a :class:`HildonAppMenu` (set with :meth:`Window.set_main_menu` and :meth:`Window.set_app_menu` respectively). Only one type of menu can be used at the same time. In Hildon 2.2, :class:`HildonAppMenu` is the recommended menu to use.

Similarly, a :class:`Window` can have several toolbars attached. These can be added with :meth:`Window.add_toolbar` . In addition to those, a :class:`Window` can also have a :class:`HildonEditToolbar` . To add it to the window use :meth:`Window.set_edit_toolbar` .

Creating a Window
=======================

::

  import gtk
  import hildon

  window = hildon.Window()
  toolbar = create_toolbar()
  menu = create_menu()

  icon_pixbuf = create_icon()

  window.set_app_menu(menu)

  window.add_toolbar(toolbar)

  window.fullscreen()

  window.set_urgency_hint(True)

  window.set_icon(window, icon_pixbuf)


Details
=======

.. data:: WindowClipboardOperation

+------------------------------------+-----------------------------------------------------+
| Value                              | Meaning                                             |
+====================================+=====================================================+
| ``WINDOW_CO_COPY``                 | Areaing follows pointer                             |
+------------------------------------+-----------------------------------------------------+
| ``WINDOW_CO_CUT``                  | Areaing uses physics to "spin" the widget           |
+------------------------------------+-----------------------------------------------------+
| ``WINDOW_CO_PASTE``                | Automatically chooses between push and accel modes, |
+------------------------------------+-----------------------------------------------------+

.. class:: Window

    .. method:: __init__ (self)

        Creates a new :class:`Window` .

        :returns: 
          A newly created :class:`Window` .


    .. method:: add_with_scrollbar (child)

        Adds ``child`` to the :class:`Window` and creates a scrollbar for it. Similar to adding first a :class:`GtkScrolledWindow` and then ``child`` to it.

        :param: child: :class:`GtkWidget`


    .. method:: set_main_menu (menu)

        Sets the menu to be used for this window. This menu overrides a program-wide menu that may have been set with :meth:`HildonProgram.set_common_menu` . Pass None to remove the current menu. :class:`Window` takes ownership of the passed menu and you're not supposed to free it yourself anymore.

        Note that if you're using a :class:`HildonAppMenu` rather than a :class:`GtkMenu` you should use :meth:`Window.set_app_menu` instead.

        :param: menu: The :class:`GtkMenu` to be used for this :class:`Window`

    .. method:: get_main_menu ()

        Gets the :class:`GtkMenu` assigned to the :class:`HildonAppview` . Note that the window is still the owner of the menu.

        Note that if you're using a :class:`HildonAppMenu` rather than a :class:`GtkMenu` you should use :meth:`Window.get_app_menu` instead.

        :returns: The :class:`GtkMenu` assigned to this application view.

        .. versionadded 2.2

    .. method:: set_app_menu (menu)

        Sets the menu to be used for this window. Pass None to remove the current menu. Any reference to a previous menu will be dropped. :class:`Window` takes ownership of the passed menu and you're not supposed to free it yourself anymore.

        Note that if you're using a :class:`GtkMenu` rather than a :class:`HildonAppMenu` you should use :meth:`Window.set_main_menu` instead.

        :param: menu: a :class:`HildonAppMenu` to be used for this window

        .. versionadded 2.2

    .. method:: get_app_menu ()

        Returns the :class:`HildonAppMenu` assigned to ``self``, or None if it's unset. Note that the window is still the owner of the menu.

        Note that if you're using a :class:`GtkMenu` rather than a :class:`HildonAppMenu` you should use :meth:`Window.get_main_menu` instead.


        :returns: a :class:`HildonAppMenu`

        .. versionadded 2.2

    .. method:: set_menu (menu)

        .. warning:: :meth:`Window.set_menu` is deprecated and should not be used in newly-written code. Hildon 2.2: use :meth:`Window.set_main_menu`

        Sets the menu to be used for this window. This menu overrides a program-wide menu that may have been set with :meth:`HildonProgram.set_common_menu` . Pass None to remove the current menu. Window takes ownership of the passed menu and you're not supposed to free it yourself anymore.

        Note: :meth:`Window.set_menu` calls :meth:`GtkWidget.show_all()` for the :class:`GtkMenu` . To pass control about visibility to the application developer, :meth:`Window.set_main_menu` was introduced, which doesn't do this.

        :param: menu: The :class:`GtkMenu` to be used for this :class:`Window`

    .. method:: get_menu ()

        .. warning:: :meth:`Window.get_menu` is deprecated and should not be used in newly-written code. In Hildon 2.2 this function has been renamed to :meth:`Window.get_main_menu` for consistency

        :returns:  a :class:`GtkMenu`


    .. method:: add_toolbar (toolbar)

        Adds a toolbar to the window. Note that the toolbar is not automatically shown. You need to call :meth:`GtkWidget.show_all` on it to make it visible. It's also possible to hide the toolbar (without removing it) by calling :meth:`GtkWidget.hide`

        :param: toolbar: A :class:`GtkToolbar` to add to the :class:`Window`

    .. method:: remove_toolbar (toolbar)

        Removes a toolbar from the window. Note that this decreases the refference count on the widget. If you want to keep the toolbar alive call :meth:`GObject.ref`before calling this function.

        :param: toolbar: A :class:`GtkToolbar` to remove from the :class:`Window`


    .. method:: set_edit_toolbar (toolbar)

        Adds a :class:`EditToolbar` to the window. Note that the toolbar is not automatically shown. You need to call :meth:`GtkWidget.show` on it to make it visible. It's also possible to hide the toolbar (without removing it) by calling :meth:`GtkWidget.hide` .

        A window can only have at most one edit toolbar at a time, so the previous toolbar (if any) is replaced after calling this function.

        :param: toolbar: A :class:`EditToolbar` , or None to remove the current one.

        .. versionadded 2.2

    .. method:: get_is_topmost ()

        Returns whether the :class:`Window` is currenty activated by the window manager.

        :returns:  True ``self`` is currently activated, False otherwise.


    .. method:: set_markup (markup)

        Sets the marked up title of ``window``. The accepted format is the one used in Pango (see :class:`PangoMarkupFormat` ) with the exception of span.

        Note that you need support from the window manager for this title to be used. See :meth:`gtk.Window.set_title` for the standard way of setting the title of a window.

        :param: markup: the marked up title of the window, or None to unset the current one

        .. versionadded 2.2

    .. method:: hildon_window_get_markup ()

        Gets the marked up title of the window title. See :meth:`Window.set_markup`

        :returns: the marked up title of the window, or None if none has been set explicitely. The returned string is owned by the widget and must not be modified or freed.

        .. versionadded 2.2

Property Details
================

+---------------------------+--------+--------------------------+--------------+--------------------------------------+
| Name                      | type   | Access                   | Default      | Meaning                              |
+===========================+========+==========================+==============+======================================+
| ``is-topmost``            | bool   | Read                     | False        | Whether the window is currently      |
|                           |        |                          |              | activated by the window manager.     |
+---------------------------+--------+--------------------------+--------------+--------------------------------------+
| ``markup``                | str    | Read / Write             | None         | The Markup Text for the window title.|
+---------------------------+--------+--------------------------+--------------+--------------------------------------+

Style Property Details
======================

+---------------------------+-------------+--------------------------+--------------+--------------------------------------+
| Name                      | type        | Access                   | Default      | Meaning                              |
+===========================+=============+==========================+==============+======================================+
| ``borders``               | GtkBorder   | Read                     |              | Size of graphical window borders.    |
+---------------------------+-------------+--------------------------+--------------+--------------------------------------+
| ``toolbar-borders``       | GtkBorder   | Read                     |              | Size of graphical toolbar borders.   |
+---------------------------+-------------+--------------------------+--------------+--------------------------------------+

.. _Window.signal-details:

Signal Details
==============

.. _Window-clipboard-operation:

The ``clipboard-operation`` signal

::

  void                user_function                      (Window *hildonwindow,
                                                          int          arg1,
                                                          gpointer      user_data)         : Run First



``hildonwindow``:
  the object which received the signal.


``arg1``:
  


``user_data``:
  user data set when the signal handler was connected.


.. _Window.see-also:

See Also
========

:class:`HildonProgram` :class:`HildonStackableWindow` .. _HildonStackableWindow:

StackableWindow
***************

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
                                         +----Window
                                               +----StackableWindow

Implemented Interfaces
======================

hildon.StackableWindow implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Description
===========

The :class:`hildon.StackableWindow` is a GTK+ widget which represents a top-level window in the Hildon framework. It is derived from :class:`hildon.Window` . Applications that use stackable windows are organized in a hierarchical way so users can go from any window back to the application's root window.

The user can only see and interact with the window on top of the stack. Although all other windows are mapped and visible, they are obscured by the topmost one so in practice they appear as if they were hidden.

To add a window to the stack, just use :meth:`gtk.Widget.show_all` . The previous one will be obscured by the new one. When the new window is destroyed, the previous one will appear again.

Alternatively, you can remove a window from the top of the stack without destroying it by using :meth:`hildon.WindowStack.pop`. The window will be automatically hidden and the previous one will appear.

For advanced details on stack handling, see :class:`WindowStack`

Basic hildon.StackableWindow example
====================================
::

  import gtk
  import hildon

  def show_new_window(widget):
    win = hildon.StackableWindow()
    # ... configure new window
    win.show_all()

  def main():
    program = hildon.hildon_program_get_instance()

    win = hildon.StackableWindow()
    win.set_title("Main window")

    # ... add some widgets to the window

    button.connect("clicked", show_new_window, None);
    win.connect("destroy", gtk.main_quit, None)

    # This call show the window and also add the window to the stack
    win.show_all()
    gtk.main()

  if __name__ == "__main__":
    main()

Details
=======

.. class:: StackableWindow

    .. method:: __init__()

        Creates a new :class:`StackableWindow` .

        :returns: A :class:`StackableWindow`

        .. versionadded 2.2

    .. method:: get_stack ()

        Returns the stack where window ``self`` is on, or None if the window is not stacked.

        :returns: a :class:`WindowStack` , or None

        .. versionadded 2.2

    .. method:: set_main_menu (menu)

        .. warning:: :meth:`StackableWindow.set_main_menu` is deprecated and should not be used in newly-written code. Hildon 2.2: use :meth:`Window.set_app_menu`

        :param menu: a :class:`HildonAppMenu` to be used for this window

See Also
========

:class:`WindowStack` :class:`Program` :class:`Window`

WindowStack
***********

Object Hierarchy
================

::
  
    GObject
     +----WindowStack
  

Description
===========

The :class:`WindowStack` is an object used to represent a stack of windows in the Hildon framework.

Stacks contain all :class:`HildonStackableWindow` s that are being shown. The user can only interact with the topmost window from each stack (as it covers all the others), but all of them are mapped and visible from the Gtk point of view.

Each window can only be in one stack at a time. All stacked windows are visible and all visible windows are stacked.

Each application has a default stack, and windows are automatically added to it when they are shown with :function:`gtk.Widget.show_all` .

Additional stacks can be created at any time using :function:`hildon.WindowStack()` . To add a window to a specific stack, use :function:`hildon.WindowStack.push_1()` (remember that, for the default stack, :function:`gtk.Widget.show_all` can be used instead).

To remove a window from a stack use :function:`hildon.WindowStack.pop_1()` , or simply :function:`gtk.Widget.hide` .

For more complex layout changes, applications can push and/or pop several windows at the same time in a single step. See :function:`hildon.WindowStack.push()` , `hildon.WindowStack.pop()` and `hildon.WindowStack.pop_and_push()` for more details.


Details
=======

.. class:: WindowStack

::

  typedef struct _WindowStack WindowStack;



.. function:: hildon_window_stack_get_default ()

::

  WindowStack*  hildon_window_stack_get_default     (void);

Returns the default window stack. This stack always exists and doesn't need to be created by the application.


:returns: 
  the default :class:`WindowStack`


.. versionadded 2.2

.. function:: hildon_window_stack_new ()

::

  WindowStack*  hildon_window_stack_new             (void);

Creates a new :class:`WindowStack` . The stack is initially empty.



:returns: 
  a new :class:`WindowStack`


.. versionadded 2.2


.. function:: hildon_window_stack_size ()

::

  int                hildon_window_stack_size            (WindowStack *stack);

Returns the number of windows in ``stack``



``stack``:
  A :class:`WindowStack`


:returns: 
  Number of windows in ``stack``\


.. versionadded 2.2


.. function:: hildon_window_stack_get_windows ()

::

  GList*              hildon_window_stack_get_windows     (WindowStack *stack);

Returns the list of windows on this stack (topmost first). The widgets in the list are not individually referenced. Once you are done with the list you must call `g_list_free() <g-list-free>`_ .



``stack``:
  a :class:`WindowStack`


:returns: 
  a newly-allocated list of :class:`HildonStackableWindow` s


.. versionadded 2.2


.. function:: hildon_window_stack_peek ()

::

  GtkWidget*          hildon_window_stack_peek            (WindowStack *stack);

Returns the window on top of ``stack``. The stack is never modified.



``stack``:
  A ```WindowStack`` <WindowStack>`_


:returns: 
  the window on top of the stack, or None if the stack is empty.


.. versionadded 2.2

.. function:: hildon_window_stack_push ()

::

  void                hildon_window_stack_push            (WindowStack *stack,
                                                           HildonStackableWindow *win1,
                                                           ...);

Pushes all windows to the top of ``stack``, and shows them. Everything is done in a single transition, so the user will only see the last window. None of the windows must be already stacked.



``stack``:
  A ```WindowStack`` <WindowStack>`_


``win1``:
  The first window to push


``...``:
  A None -terminated list of additional :class:`HildonStackableWindow` s to push.


.. versionadded 2.2


.. function:: hildon_window_stack_push_list ()

::

  void                hildon_window_stack_push_list       (WindowStack *stack,
                                                           GList *list);

Pushes all windows in ``list`` to the top of ``stack``, and shows them. Everything is done in a single transition, so the user will only see the last window in ``list`` during this operation. None of the windows must be already stacked.



``stack``:
  A ```WindowStack`` <WindowStack>`_


``list``:
  A list of ```HildonStackableWindow`` <HildonStackableWindow>`_ s to push


.. versionadded 2.2


.. function:: hildon_window_stack_push_1 ()

::

  void                hildon_window_stack_push_1          (WindowStack *stack,
                                                           HildonStackableWindow *win);

Adds ``win`` to the top of ``stack``, and shows it. The window must not be already stacked.



``stack``:
  A ```WindowStack`` <WindowStack>`_


``win``:
  A ```HildonStackableWindow`` <HildonStackableWindow>`_


.. versionadded 2.2


.. function:: hildon_window_stack_pop ()

::

  void                hildon_window_stack_pop             (WindowStack *stack,
                                                           int nwindows,
                                                           GList **popped_windows);

Pops ``nwindows`` windows from ``stack``, and hides them. Everything is done in a single transition, so the user will not see any of the windows being popped in this operation.

If ``popped_windows`` is not None , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.



``stack``:
  A ```WindowStack`` <WindowStack>`_


``nwindows``:
  Number of windows to pop


``popped_windows``:
  if non-None , the list of popped windows is stored here


.. versionadded 2.2


.. function:: hildon_window_stack_pop_1 ()

::

  GtkWidget*          hildon_window_stack_pop_1           (WindowStack *stack);

Removes the window on top of ``stack``, and hides it. If the stack is empty nothing happens.



``stack``:
  A ```WindowStack`` <WindowStack>`_


:returns: 
  the window on top of the stack, or None if the stack is empty.


.. versionadded 2.2


.. function:: hildon_window_stack_pop_and_push ()

::

  void                hildon_window_stack_pop_and_push    (WindowStack *stack,
                                                           int nwindows,
                                                           GList **popped_windows,
                                                           HildonStackableWindow *win1,
                                                           ...);

Pops ``nwindows`` windows from ``stack`` (and hides them), then pushes all passed windows (and shows them). Everything is done in a single transition, so the user will only see the last pushed window. None of the pushed windows must be already stacked.

If ``popped_windows`` is not None , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.



``stack``:
  A ```WindowStack`` <WindowStack>`_


``nwindows``:
  Number of windows to pop.


``popped_windows``:
  if non-None , the list of popped windows is stored here


``win1``:
  The first window to push


``...``:
  A None -terminated list of additional :class:`HildonStackableWindow` s to push.


.. versionadded 2.2


.. function:: hildon_window_stack_pop_and_push_list ()

::

  void                hildon_window_stack_pop_and_push_list
                                                          (WindowStack *stack,
                                                           int nwindows,
                                                           GList **popped_windows,
                                                           GList *list);

Pops ``nwindows`` windows from ``stack`` (and hides them), then pushes all windows in ``list`` (and shows them). Everything is done in a single transition, so the user will only see the last window from ``list``. None of the pushed windows must be already stacked.

If ``popped_windows`` is not None , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.



``stack``:
  A ```WindowStack`` <WindowStack>`_


``nwindows``:
  Number of windows to pop.


``popped_windows``:
  if non-None , the list of popped windows is stored here


``list``:
  A list of ```HildonStackableWindow`` <HildonStackableWindow>`_ s to push


.. versionadded 2.2

.. _WindowStack.property-details:

Property Details
================

.. _WindowStack--window-group:

The ``window-group`` property

::

    window-group             GtkWindowGroup*       : Read / Write / Construct Only

GtkWindowGroup that all windows on this stack belong to.

.. _WindowStack.see-also:

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


:returns: 
  a new :class:`HildonButton`


.. versionadded 2.2

.. _hildon-button-new-with-text:

.. function:: hildon_button_new_with_text ()

::

  GtkWidget*          hildon_button_new_with_text         (HildonSizeType size,
                                                           HildonButtonArrangement arrangement,
                                                           const gchar *title,
                                                           const gchar *value);

Creates a new :class:`HildonButton` with two labels, ``title`` and ``value``.

If you just don't want to use one of the labels, set it to None . You can set it to a non-None value at any time later using `hildon_button_set_title() <hildon-button-set-title>`_ or `hildon_button_set_value() <hildon-button-set-value>`_ .



``size``:
  Flags to set the size of the button.


``arrangement``:
  How the labels must be arranged.


``title``:
  Title of the button (main label), or None


``value``:
  Value of the button (secondary label), or None


:returns: 
  a new :class:`HildonButton`


.. versionadded 2.2

.. _hildon-button-set-title:

.. function:: hildon_button_set_title ()

::

  void                hildon_button_set_title             (HildonButton *button,
                                                           const gchar *title);

Sets the title (main label) of ``button`` to ``title``.

This will clear any previously set title.

If ``title`` is set to None , the title label will be hidden and the value label will be realigned.



``button``:
  a :class:`HildonButton`


``title``:
  a new title (main label) for the button, or None


.. versionadded 2.2

.. _hildon-button-set-value:

.. function:: hildon_button_set_value ()

::

  void                hildon_button_set_value             (HildonButton *button,
                                                           const gchar *value);

Sets the value (secondary label) of ``button`` to ``value``.

This will clear any previously set value.

If ``value`` is set to None , the value label will be hidden and the title label will be realigned.



``button``:
  a :class:`HildonButton`


``value``:
  a new value (secondary label) for the button, or None


.. versionadded 2.2

.. _hildon-button-get-title:

.. function:: hildon_button_get_title ()

::

  const str        hildon_button_get_title             (HildonButton *button);

Fetches the text from the main label (title) of ``button``, as set by `hildon_button_set_title() <hildon-button-set-title>`_ or `hildon_button_set_text() <hildon-button-set-text>`_ . If the label text has not been set the return value will be None . This will be the case if you create an empty button with `hildon_button_new() <hildon-button-new>`_ to use as a container.



``button``:
  a :class:`HildonButton`


:returns: 
  The text of the title label. This string is owned by the widget and must not be modified or freed.


.. versionadded 2.2

.. _hildon-button-get-value:

.. function:: hildon_button_get_value ()

::

  const str        hildon_button_get_value             (HildonButton *button);

Fetches the text from the secondary label (value) of ``button``, as set by `hildon_button_set_value() <hildon-button-set-value>`_ or `hildon_button_set_text() <hildon-button-set-text>`_ . If the label text has not been set the return value will be None . This will be the case if you create an empty button with `hildon_button_new() <hildon-button-new>`_ to use as a container.



``button``:
  a :class:`HildonButton`


:returns: 
  The text of the value label. This string is owned by the widget and must not be modified or freed.


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-button-get-image:

.. function:: hildon_button_get_image ()

::

  GtkWidget*          hildon_button_get_image             (HildonButton *button);

Gets the widget that is currenty set as the image of ``button``, previously set with `hildon_button_set_image() <hildon-button-set-image>`_



``button``:
  a :class:`HildonButton`


:returns: 
  a :class:`GtkWidget` or None in case there is no image


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-button-add-size-groups:

.. function:: hildon_button_add_size_groups ()

::

  void                hildon_button_add_size_groups       (HildonButton *button,
                                                           GtkSizeGroup *title_size_group,
                                                           GtkSizeGroup *value_size_group,
                                                           GtkSizeGroup *image_size_group);

Convenience function to add title, value and image to size groups. None size groups will be ignored.



``button``:
  a :class:`HildonButton`


``title_size_group``:
  A :class:`GtkSizeGroup` for the button title (main label), or None


``value_size_group``:
  A :class:`GtkSizeGroup` group for the button value (secondary label), or None


``image_size_group``:
  A :class:`GtkSizeGroup` group for the button image, or None


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-button-get-style:

.. function:: hildon_button_get_style ()

::

  HildonButtonStyle   hildon_button_get_style             (HildonButton *button);

Gets the visual style of the button.



``button``:
  A :class:`HildonButton`


:returns: 
  a :class:`HildonButtonStyle`


.. versionadded 2.2

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


:returns: 
  A newly created :class:`HildonCheckButton`


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-check-button-get-active:

.. function:: hildon_check_button_get_active ()

::

  bool            hildon_check_button_get_active      (HildonCheckButton *button);

Gets the current state of ``button``.



``button``:
  A :class:`HildonCheckButton`


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ if ``button`` is active, ```FALSE`` <FALSE:CAPS>`_ otherwise.


.. versionadded 2.2

.. _hildon-check-button-toggled:

.. function:: hildon_check_button_toggled ()

::

  void                hildon_check_button_toggled         (HildonCheckButton *button);

Emits the `"toggled" <HildonCheckButton-toggled>`_ signal on the :class:`HildonCheckButton` . There is no good reason for an application ever to call this function.



``button``:
  A :class:`HildonCheckButton`


.. versionadded 2.2

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


.. versionadded 2.2

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

:class:`HildonPickerButton` is a widget that lets the user select a particular item from a list. Visually, it's a button with title and value labels that brings up a :class:`PickerDialog` . The user can then use this dialog to choose an item, which will be displayed in the value label of the button.

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


:returns: 
  a newly created :class:`HildonPickerButton`


.. versionadded 2.2

.. _hildon-picker-button-set-selector:

.. function:: hildon_picker_button_set_selector ()

::

  void                hildon_picker_button_set_selector   (HildonPickerButton *button,
                                                           HildonTouchSelector *selector);

Sets ``selector`` as the :class:`HildonTouchSelector` to be shown in the :class:`PickerDialog` that ``button`` brings up.



``button``:
  a :class:`HildonPickerButton`


``selector``:
  a :class:`HildonTouchSelector`


.. versionadded 2.2

.. _hildon-picker-button-get-selector:

.. function:: hildon_picker_button_get_selector ()

::

  HildonTouchSelector* hildon_picker_button_get_selector  (HildonPickerButton *button);

Retrieves the :class:`HildonTouchSelector` associated to ``button``.



``button``:
  a :class:`HildonPickerButton`


:returns: 
  a :class:`HildonTouchSelector`


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-picker-button-get-active:

.. function:: hildon_picker_button_get_active ()

::

  int                hildon_picker_button_get_active     (HildonPickerButton *button);

Returns the index of the currently active item, or -1 if there's no active item. If the selector has several columns, only the first one is used.



``button``:
  a :class:`HildonPickerButton`


:returns: 
  an integer which is the index of the currently active item, or -1 if there's no active item.


.. versionadded 2.2

.. _hildon-picker-button-get-done-button-text:

.. function:: hildon_picker_button_get_done_button_text ()

::

  const str        hildon_picker_button_get_done_button_text
                                                          (HildonPickerButton *button);

Gets the text used in the :class:`PickerDialog` that is launched by ``button``. If no custom text is set, then None is returned.



``button``:
  a :class:`HildonPickerButton`


:returns: 
  the custom string to be used, or None if the default `"done-button-text" <PickerDialog-done-button-text>`_ is to be used.


.. versionadded 2.2

.. _hildon-picker-button-set-done-button-text:

.. function:: hildon_picker_button_set_done_button_text ()

::

  void                hildon_picker_button_set_done_button_text
                                                          (HildonPickerButton *button,
                                                           const gchar *done_button_text);

Sets a custom string to be used in the "done" button in :class:`PickerDialog` . If unset, the default HildonPickerButton::done-button-text property value will be used.



``button``:
  a :class:`HildonPickerButton`


``done_button_text``:
  a string


.. versionadded 2.2

.. _hildon-picker-button-value-changed:

.. function:: hildon_picker_button_value_changed ()

::

  void                hildon_picker_button_value_changed  (HildonPickerButton *button);

Emits a "`"value-changed" <HildonPickerButton-value-changed>`_ " signal to the given :class:`HildonPickerButton`



``button``:
  a :class:`HildonPickerButton`


.. versionadded 2.2

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


.. versionadded 2.2

.. _HildonPickerButton.see-also:

See Also
========

:class:`HildonTouchSelector` :class:`PickerDialog` .. _HildonDateButton:

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

:class:`HildonDateButton` is a widget that shows a text label and a date, and allows the user to select a different date. Visually, it's a button that, once clicked, presents a :class:`PickerDialog` containing a :class:`HildonDateSelector` . Once the user selects a different date from the selector, this will be shown in the button.



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


:returns: 
  a new :class:`HildonDateButton`


.. versionadded 2.2

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


:returns: 
  a new :class:`HildonDateButton`


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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

:class:`HildonTimeButton` is a widget that shows a text label and a time, and allows the user to select a different time. Visually, it's a button that, once clicked, presents a :class:`PickerDialog` containing a :class:`HildonTimeSelector` . Once the user selects a different time from the selector, this will be shown in the button.



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


:returns: 
  a new :class:`HildonTimeButton`


.. versionadded 2.2

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


:returns: 
  a new :class:`HildonTimeButton`


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


:returns: 
  a :class:`GtkWidget` pointer of Caption


.. _hildon-caption-get-size-group:

.. function:: hildon_caption_get_size_group ()

::

  GtkSizeGroup*       hildon_caption_get_size_group       (const HildonCaption *caption);

Query given captioned control for the :class:`GtkSizeGroup` assigned to it.



``caption``:
  a :class:`HildonCaption`


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
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
  Progressbar to use. You usually can just pass None , unless you want somehow customized progress bar.


``text``:
  text to display.


:returns: 
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
  the name of icon to use. Can be None for default icon


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
  the filename of icon to use. Can be None for default icon


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

HildonNote example ================== :: bool show_confirmation_note (gtk.Window *parent) { int retcode; GtkWidget *note; note = hildon_note_new_confirmation (parent, "Confirmation message..."); retcode = gtk_dialog_run (GTK_DIALOG (note)); gtk_widget_destroy (note); if (retcode == GTK_RESPONSE_OK) { g_debug ("User pressed 'OK' button'"); return TRUE; } else { g_debug ("User pressed 'Cancel' button"); return FALSE; } }



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


:returns: 
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
  arguments pairs for new buttons(label and return value). Terminate the list with None value.


:returns: 
  A :class:`GtkWidget` pointer of the note


.. _hildon-note-new-confirmation-with-icon-name:

.. function:: hildon_note_new_confirmation_with_icon_name ()

::

  GtkWidget*          hildon_note_new_confirmation_with_icon_name
                                                          (GtkWindow *parent,
                                                           const gchar *description,
                                                           const gchar *icon_name);

.. warning:: ``hildon_note_new_confirmation_with_icon_name`` is deprecated and should not be used in newly-written code. .. versionadded 2.2, icons are not shown in confirmation notes. Icons set with this function will be ignored. Use `hildon_note_new_confirmation() <hildon-note-new-confirmation>`_ instead.

Create a new confirmation note. Confirmation note has a text (description) that you specify and two buttons.



``parent``:
  the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly. In GTK the X window ID can be checked using GDK_WINDOW_XID(GTK_WIDGET(parent)->window).


``description``:
  the message to confirm


``icon_name``:
  icon to be displayed. If NULL, default icon is used.


:returns: 
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
  a pointer to :class:`GtkProgressBar` to be filled with the progressbar assigned to this note. Use this to set the fraction of progressbar done. This parameter can be None as well, in which case plain text cancel note appears.


:returns: 
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


:returns: 
  a :class:`GtkWidget` pointer of the note


.. _hildon-note-new-information-with-icon-name:

.. function:: hildon_note_new_information_with_icon_name ()

::

  GtkWidget*          hildon_note_new_information_with_icon_name
                                                          (GtkWindow *parent,
                                                           const gchar *description,
                                                           const gchar *icon_name);

.. warning:: ``hildon_note_new_information_with_icon_name`` is deprecated and should not be used in newly-written code. .. versionadded 2.2, icons are not shown in confirmation notes. Icons set with this function will be ignored. Use `hildon_note_new_information() <hildon-note-new-information>`_ instead.

Create a new information note. Information note has text(description) that you specify, an OK button and an icon.



``parent``:
  the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly. In GTK the X window ID can be checked using GDK_WINDOW_XID(GTK_WIDGET(parent)->window).


``description``:
  the message to confirm


``icon_name``:
  icon to be displayed. If NULL, default icon is used.


:returns: 
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

Normally, you would use :class:`HildonTouchSelector` together with a :class:`PickerDialog` activated from a button. For the most common cases, you should use :class:`HildonPickerButton` .

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
  


:returns: 
  


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



:returns: 
  a new :class:`HildonTouchSelector` .


.. versionadded 2.2

.. _hildon-touch-selector-new-text:

.. function:: hildon_touch_selector_new_text ()

::

  GtkWidget*          hildon_touch_selector_new_text      (void);

Creates a :class:`HildonTouchSelector` with a single text column that can be populated conveniently through `hildon_touch_selector_append_text() <hildon-touch-selector-append-text>`_ , `hildon_touch_selector_prepend_text() <hildon-touch-selector-prepend-text>`_ , `hildon_touch_selector_insert_text() <hildon-touch-selector-insert-text>`_ .



:returns: 
  A new :class:`HildonTouchSelector`


.. versionadded 2.2

.. _hildon-touch-selector-append-text:

.. function:: hildon_touch_selector_append_text ()

::

  void                hildon_touch_selector_append_text   (HildonTouchSelector *selector,
                                                           const gchar *text);

Appends a new entry in a :class:`HildonTouchSelector` created with `hildon_touch_selector_new_text() <hildon-touch-selector-new-text>`_ .



``selector``:
  A :class:`HildonTouchSelector` .


``text``:
  a non None text string.


.. versionadded 2.2

.. _hildon-touch-selector-prepend-text:

.. function:: hildon_touch_selector_prepend_text ()

::

  void                hildon_touch_selector_prepend_text  (HildonTouchSelector *selector,
                                                           const gchar *text);

Prepends a new entry in a :class:`HildonTouchSelector` created with `hildon_touch_selector_new_text() <hildon-touch-selector-new-text>`_ .



``selector``:
  A :class:`HildonTouchSelector` .


``text``:
  a non None text string.


.. versionadded 2.2

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
  A non None text string.


.. versionadded 2.2

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


:returns: 
  the new column added, NULL otherwise.


.. versionadded 2.2

.. _hildon-touch-selector-append-column:

.. function:: hildon_touch_selector_append_column ()

::

  HildonTouchSelectorColumn* hildon_touch_selector_append_column
                                                          (HildonTouchSelector *selector,
                                                           GtkTreeModel *model,
                                                           GtkCellRenderer *cell_renderer,
                                                           ...);

This functions adds a new column to the widget, whose data will be obtained from the model. Only widgets added this way should used on the selection logic, i.e., the print function, the `"changed" <HildonTouchPicker-changed>`_ signal, etc.

You can optionally pass a :class:`GtkCellRenderer` in ``cell_renderer``, together with a None -terminated list of pairs property/value, in the same way you would use `gtk_tree_view_column_set_attributes() <gtk-tree-view-column-set-attributes>`_ . This will pack ``cell_renderer`` at the start of the column, expanded by default. If you prefer not to add it this way, you can simply pass None to ``cell_renderer``\ and use the :class:`GtkCellLayout` interface on the returned :class:`HildonTouchSelectorColumn` to set your renderers.

There is a prerequisite to be considered on models used: text data must be in the first column.

This method basically adds a :class:`GtkTreeView` to the widget, using the model and the data received.



``selector``:
  a :class:`HildonTouchSelector`


``model``:
  the :class:`GtkTreeModel` with the data of the column


``cell_renderer``:
  The :class:`GtkCellRenderer` where to draw each row contents.


``...``:
  a None -terminated pair of attributes and column numbers.


:returns: 
  the new column added added, None otherwise.


.. versionadded 2.2

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
  A None -terminated list of attributes.


.. versionadded 2.2

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


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ if the column was removed, ```FALSE`` <FALSE:CAPS>`_ otherwise


.. versionadded 2.2

.. _hildon-touch-selector-get-num-columns:

.. function:: hildon_touch_selector_get_num_columns ()

::

  int                hildon_touch_selector_get_num_columns
                                                          (HildonTouchSelector *selector);

Gets the number of columns in the :class:`HildonTouchSelector` .



``selector``:
  a :class:`HildonTouchSelector`


:returns: 
  the number of columns in ``selector``.


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-touch-selector-get-column-selection-mode:

.. function:: hildon_touch_selector_get_column_selection_mode ()

::

  HildonTouchSelectorSelectionMode hildon_touch_selector_get_column_selection_mode
                                                          (HildonTouchSelector *selector);

Gets the selection mode of ``selector``.



``selector``:
  a :class:`HildonTouchSelector`


:returns: 
  one of :class:`HildonTouchSelectorSelectionMode`


.. versionadded 2.2

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


:returns: 
  the ``column``-th :class:`HildonTouchSelectorColumn` in ``selector``\


.. versionadded 2.2

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


.. versionadded 2.2

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


:returns: 
  an integer which is the index of the currently active item, or -1 if there's no active item.


.. versionadded 2.2

.. _hildon-touch-selector-get-selected:

.. function:: hildon_touch_selector_get_selected ()

::

  bool            hildon_touch_selector_get_selected  (HildonTouchSelector *selector,
                                                           int column,
                                                           GtkTreeIter *iter);

Sets ``iter`` to the currently selected node on the nth-column, if selection is set to ```HILDON_TOUCH_SELECTOR_SINGLE`` <HILDON-TOUCH-SELECTOR-SINGLE:CAPS>`_ or ```HILDON_TOUCH_SELECTOR_MULTIPLE`` <HILDON-TOUCH-SELECTOR-MULTIPLE:CAPS>`_ with a column different that the first one. ``iter`` may be None if you just want to test if selection has any selected items.

This function will not work if selection is in ```HILDON_TOUCH_SELECTOR_MULTIPLE`` <HILDON-TOUCH-SELECTOR-MULTIPLE:CAPS>`_ mode and the column is the first one.

See `gtk_tree_selection_get_selected() <gtk-tree-selection-get-selected>`_ for more information.



``selector``:
  a :class:`HildonTouchSelector`


``column``:
  the column number we want to get the element


``iter``:
  :class:`GtkTreeIter` currently selected


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ if ``iter`` was correctly set, ```FALSE`` <FALSE:CAPS>`_ otherwise


.. versionadded 2.2

.. _hildon-touch-selector-center-on-selected:

.. function:: hildon_touch_selector_center_on_selected ()

::

  void                hildon_touch_selector_center_on_selected
                                                          (HildonTouchSelector *selector);

Ensures all the columns in a :class:`HildonTouchSelector` show a selected item. If one of the columns is in ```HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE`` <HILDON-TOUCH-SELECTOR-SELECTION-MODE-MULTIPLE:CAPS>`_ mode, that column will be scrolled to ensure the selected item that is closest to the currently visible area is shown.



``selector``:
  a :class:`HildonTouchSelector`


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


:returns: 
  A new :class:`GList` containing a :class:`GtkTreePath` for each selected row in the column ``column``.


.. versionadded 2.2

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


.. versionadded 2.2

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


:returns: 
  the :class:`GtkTreeModel` for the column ``column`` of ``selector``.


.. versionadded 2.2

.. _hildon-touch-selector-get-current-text:

.. function:: hildon_touch_selector_get_current_text ()

::

  str              hildon_touch_selector_get_current_text
                                                          (HildonTouchSelector *selector);

Returns a string representing the currently selected items for each column of ``selector``. See `hildon_touch_selector_set_print_func() <hildon-touch-selector-set-print-func>`_ .



``selector``:
  a :class:`HildonTouchSelector`


:returns: 
  a newly allocated string.


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-touch-selector-get-print-func:

.. function:: hildon_touch_selector_get_print_func ()

::

  HildonTouchSelectorPrintFunc hildon_touch_selector_get_print_func
                                                          (HildonTouchSelector *selector);

Gets the :class:`HildonTouchSelectorPrintFunc` currently used. See `hildon_touch_selector_set_print_func() <hildon-touch-selector-set-print-func>`_ .



``selector``:
  a :class:`HildonTouchSelector`


:returns: 
  a :class:`HildonTouchSelectorPrintFunc` or None if the default one is currently used.


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
  a pointer to user data or None


``destroy_func``:
  a callback for freeing the user data or None


.. versionadded 2.2

.. _hildon-touch-selector-has-multiple-selection:

.. function:: hildon_touch_selector_has_multiple_selection ()

::

  bool            hildon_touch_selector_has_multiple_selection
                                                          (HildonTouchSelector *selector);

Determines whether ``selector`` is complex enough to actually require an extra selection step than only picking an item. This is normally ```TRUE`` <TRUE:CAPS>`_ if ``selector`` has multiple columns, multiple selection, or when it is a more complex widget, like :class:`HildonTouchSelectorEntry` .

This information is useful for widgets containing a :class:`HildonTouchSelector` , like :class:`PickerDialog` , that could need a "Done" button, in case that its internal :class:`HildonTouchSelector` has multiple columns, for instance.



``selector``:
  A :class:`HildonTouchSelector`


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ if ``selector`` requires multiple selection steps.


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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

Normally, you would use :class:`HildonTouchSelectorEntry` together with a :class:`PickerDialog` activated from a button. For the most common cases, you should use :class:`HildonPickerButton` .

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



:returns: 
  A new :class:`HildonTouchSelectorEntry`


.. versionadded 2.2

.. _hildon-touch-selector-entry-new-text:

.. function:: hildon_touch_selector_entry_new_text ()

::

  GtkWidget*          hildon_touch_selector_entry_new_text
                                                          (void);

Creates a :class:`HildonTouchSelectorEntry` with a single text column that can be populated conveniently through `hildon_touch_selector_append_text() <hildon-touch-selector-append-text>`_ , `hildon_touch_selector_prepend_text() <hildon-touch-selector-prepend-text>`_ , `hildon_touch_selector_insert_text() <hildon-touch-selector-insert-text>`_ .



:returns: 
  A new :class:`HildonTouchSelectorEntry`


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-touch-selector-entry-get-text-column:

.. function:: hildon_touch_selector_entry_get_text_column ()

::

  int                hildon_touch_selector_entry_get_text_column
                                                          (HildonTouchSelectorEntry *selector);

Gets the text column that ``selector`` is using as a text column.



``selector``:
  A :class:`HildonTouchSelectorEntry`


:returns: 
  the number of the column used as a text column.


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-touch-selector-entry-get-input-mode:

.. function:: hildon_touch_selector_entry_get_input_mode ()

::

  HildonGtkInputMode  hildon_touch_selector_entry_get_input_mode
                                                          (HildonTouchSelectorEntry *selector);

Gets the input mode used in the :class:`GtkEntry` in ``selector``. See `hildon_gtk_entry_get_input_mode() <hildon-gtk-entry-get-input-mode>`_ for details.



``selector``:
  a :class:`HildonTouchSelectorEntry`


:returns: 
  a mask of :class:`HildonGtkInputMode`


.. versionadded 2.2

.. _hildon-touch-selector-entry-get-entry:

.. function:: hildon_touch_selector_entry_get_entry ()

::

  HildonEntry*        hildon_touch_selector_entry_get_entry
                                                          (HildonTouchSelectorEntry *selector);

Provides access to the :class:`HildonEntry` in ``selector``. Use to programmatically change the contents in entry or modify its behavior.



``selector``:
  a :class:`HildonTouchSelectorEntry` .


:returns: 
  a :class:`HildonEntry` .


.. versionadded 2.2

.. _HildonTouchSelectorEntry.property-details:

Property Details
================

.. _HildonTouchSelectorEntry--text-column:

The ``text-column`` property

::

    text-column              int                  : Read / Write





Allowed values: = -1

Default value: -1

.. versionadded 2.2

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



:returns: 
  a new :class:`HildonDateSelector`


.. versionadded 2.2

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


:returns: 
  a new :class:`HildonDateSelector`


.. versionadded 2.2

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


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ on success, ```FALSE`` <FALSE:CAPS>`_ otherwise


.. versionadded 2.2

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


.. versionadded 2.2

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


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ on success, ```FALSE`` <FALSE:CAPS>`_ otherwise


.. versionadded 2.2

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


.. versionadded 2.2

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



:returns: 
  a new :class:`HildonTimeSelector`


.. versionadded 2.2

.. _hildon-time-selector-new-step:

.. function:: hildon_time_selector_new_step ()

::

  GtkWidget*          hildon_time_selector_new_step       (int minutes_step);

Creates a new :class:`HildonTimeSelector` ``minutes_step``: step between the minutes we are going to show in the selector



``minutes_step``:
  


:returns: 
  a new :class:`HildonTimeSelector`


.. versionadded 2.2

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


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ on success, ```FALSE`` <FALSE:CAPS>`_ otherwise


.. versionadded 2.2

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


.. versionadded 2.2

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


.. _HildonPannableArea.description:

Description
===========

:class:`HildonPannableArea` is a container widget that can be "panned" (scrolled) up and down using the touchscreen with fingers. The widget has no scrollbars, but it rather shows small scroll indicators to give an idea of the part of the content that is visible at a time. The scroll indicators appear when a dragging motion is started on the pannable area.

The scrolling is "kinetic", meaning the motion can be "flicked" and it will continue from the initial motion by gradually slowing down to an eventual stop. The motion can also be stopped immediately by pressing the touchscreen over the pannable area.


.. _HildonPannableArea.details:

Details
=======

.. _HildonPannableAreaMode:

.. data:: HildonPannableAreaMode

+------------------------------+-----------------------------------------------------+
| Value                        | Meaning                                             |
+==============================+=====================================================+
| ``PANNABLE_AREA_MODE_PUSH``  | Areaing follows pointer                             |
+------------------------------+-----------------------------------------------------+
| ``PANNABLE_AREA_MODE_ACCEL`` | Areaing uses physics to "spin" the widget           |
+------------------------------+-----------------------------------------------------+
| ``PANNABLE_AREA_MODE_AUTO``  | Automatically chooses between push and accel modes, |
|                              | depending on input.                                 |
+------------------------------+-----------------------------------------------------+


.. _HildonMovementMode:

.. data:: HildonMovementMode
    Used to control the movement of the pannable, we can allow or disallow horizontal or vertical movement. This way the applications can control the movement using scroll_to and jump_to functions


+------------------------------------+---------------------+
| Value                              | Meaning             |
+====================================+=====================+
| ``MOVEMENT_MODE_HORIZ``            | 1  1                |
+------------------------------------+---------------------+
| ``MOVEMENT_MODE_VERT``             | 1  2                |
+------------------------------------+---------------------+
| ``MOVEMENT_MODE_BOTH``             | 0x000006            |
+------------------------------------+---------------------+
 

.. _HildonMovementDirection:

.. data:: HildonMovementDirection
    Used to point out the direction of the movement

+--------------------------+---------------------+
| Value                    | Meaning             |
+==========================+=====================+
| ``MOVEMENT_UP``          |                     |
+--------------------------+---------------------+
| ``MOVEMENT_DOWN``        |                     |
+--------------------------+---------------------+
| ``MOVEMENT_LEFT``        |                     |
+--------------------------+---------------------+
| ``HILDON_MOVEMENT_RIGHT``|                     |
+--------------------------+---------------------+


.. _HildonSizeRequestPolicy:

.. data:: HildonSizeRequestPolicy
    Used to control the size request policy of the widget

+---------------------------+--------------------------------------------------------+
| Value                     | Meaning                                                |
+===========================+========================================================+
| ``SIZE_REQUEST_MINIMUM``  | The minimum size the widget could use to paint itself  |
+---------------------------+--------------------------------------------------------+
| ``SIZE_REQUEST_CHILDREN`` | The minimum size of the children of the widget         |
+---------------------------+--------------------------------------------------------+



Ctors:

.. class:: HildonPannableArea

    .. method:: __init__()

        Create a new pannable area widget

    .. method:: add_with_viewport(child)
        
        Convenience function used to add a child to a :class:`GtkViewport` , and add the viewport to the scrolled window.

        :param child: Child widget to add to the viewport



    .. method:: scroll_to(x, y)

        Smoothly scrolls ``area`` to ensure that (``x``, ``y``) is a visible point on the widget. To move in only one coordinate, you must set the other one to -1. Notice that, in ```PANNABLE_AREA_MODE_PUSH``, this function works just like :meth:`jump_to'.

        This function is useful if you need to present the user with a particular element inside a scrollable widget, like :class:`GtkTreeView` . For instance, the following example shows how to scroll inside a :class:`GtkTreeView` to make visible an item, indicated by the :class:`GtkTreeIter` ``iter``.

        :: 
            path = model.get_pah(model)
            rect = treeview.get_background_area(path, None)
            (x, y) = treeview.convert_bin_window_to_tree_coords(0, rect.y)
            panarea.scroll_to(-1, y)


        If you want to present a child widget in simpler scenarios, use :meth:`scroll_to_child` instead.

        There is a precondition to this function: the widget must be already realized. Check the :meth:`jump_to_child` for more tips regarding how to call this function during initialization.

        :param x: The x coordinate of the destination point or -1 to ignore this axis.
        :param y: The y coordinate of the destination point or -1 to ignore this axis.


    .. method:: jump_to(x, y)

        Jumps the position of ``area`` to ensure that (``x``, ``y``) is a visible point in the widget. In order to move in only one coordinate, you must set the other one to -1. See :meth:`scroll_to` function for an example of how to calculate the position of children in scrollable widgets like :class:`GtkTreeview` .
        There is a precondition to this function: the widget must be already realized. Check the :meth:`jump_to_child` for more tips regarding how to call this function during initialization.

        :param x: The x coordinate of the destination point or -1 to ignore this axis.
        :param y: The y coordinate of the destination point or -1 to ignore this axis.

    .. method:: scroll_to_child(child)

        Smoothly scrolls until ``child`` is visible inside ``area``. ``child`` must be a descendant of ``area``. If you need to scroll inside a scrollable widget, e.g., :class:`GtkTreeview` , see :meth:`scroll_to`.

        There is a precondition to this function: the widget must be already realized. Check the :meth:`jump_to_child` for more tips regarding how to call this function during initialization.

        :param child: A :class:`GtkWidget` , descendant of ``area``.

    .. method:: jump_to_child(child)

        Jumps to make sure ``child`` is visible inside ``area``. ``child`` must be a descendant of ``area``. If you want to move inside a scrollable widget, like, :class:`GtkTreeview` , see :meth:`scroll_to`.
        
        There is a precondition to this function: the widget must be already realized. You can control if the widget is ready with the GTK_WIDGET_REALIZED macro. If you want to call this function during the initialization process of the widget do it inside a callback to the ::realize signal, using `g_signal_connect_after() <g-signal-connect-after>`_ function.

        :param child: A :class:`GtkWidget` , descendant of ``area``.


    .. method:: get_child_widget_at(x, y)

        Get the widget at the point (x, y) inside the pannable area. In case no widget found it returns None.

        :param x: horizontal coordinate of the point
        :param y: vertical coordinate of the point
        :returns: the :class:`GtkWidget` if we find a widget, NULL in any other case


    .. method:: get_size_request_policy()

        This function returns the current size request policy of the widget. That policy controls the way the size_request is done in the pannable area. Check  :meth:`set_size_request_policy` for a more detailed explanation.

        :returns:  the policy is currently being used in the widget :class:`HildonSizeRequestPolicy` .

    .. method: set_size_request_policy(size_request_policy)

        This function sets the pannable area size request policy. That policy controls the way the size_request is done in the pannable area. Pannable can use the size request of its children hildon.SIZE_REQUEST_CHILDREN or the minimum size required for the area itself hildon.SIZE_REQUEST_MINIMUM, the latter is the default. Recall this size depends on the scrolling policy you are requesting to the pannable area, if you set gtk.POLICY_NEVER this parameter will not have any effect with hildon.SIZE_REQUEST_MINIMUM set.

        :param size_request_policy: One of the allowed :class:`HildonSizeRequestPolicy`


    .. method:: get_hadjustment()

        Returns the horizontal adjustment. This adjustment is the internal widget adjustment used to control the animations. Do not modify it directly to change the position of the pannable, to do that use the pannable API. If you modify the object directly it could cause artifacts in the animations.

        :returns: The horizontal :class:`GtkAdjustment`

    
    .. method: get_vadjustment()

        Returns the vertical adjustment. This adjustment is the internal widget adjustment used to control the animations. Do not modify it directly to change the position of the pannable, to do that use the pannable API. If you modify the object directly it could cause artifacts in the animations.

        :returns:  The vertical :class:`GtkAdjustment`


Functions
=========

.. function:: hildon_pannable_area_new_full(mode, enabled, vel_min, vel_max, decel, sps)

    Create a new :class:`HildonPannableArea` widget and set various properties

    :param mode: :class:`HildonPannableAreaMode`
    :param enabled: Value for the enabled property
    :param vel_min: Value for the velocity-min property
    :param vel_max: Value for the velocity-max property
    :param decel: Value for the deceleration property
    :param sps: Value for the sps property
    :returns: the newly create :class:`HildonPannableArea`
        

.. versionadded 2.2

.. _HildonPannableArea.property-details:

Property Details
================

+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| Name                             | type          | Access                   | Default                  | Meaning                                                                                                                                    |
+==================================+===============+==========================+==========================+============================================================================================================================================+
| ``bounce-steps``                 | int           | Read / Write / Construct | 3                        | Number of steps that is going to be used to bounce when hitting theedge, the rubberband effect depends on it.                              |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``deceleration``                 | float         | Read / Write / Construct | 0.93                     | The multiplier used when decelerating when in acceleration scrolling mode.                                                                 |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``direction-error-margin``       | int           | Read / Write / Construct | 10                       | After detecting the direction of the movement (horizontal orvertical), we can add this margin of error to allow the movement inthe other   |
|                                  |               |                          |                          | direction even apparently it is not.                                                                                                       |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``drag-inertia``                 | float         | Read / Write / Construct | 0.85                     | Percentage of the calculated speed in each moment we are are going to useto calculate the launch speed, the other part would be the        |
|                                  |               |                          |                          | speedcalculated previously.                                                                                                                |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``enabled``                      | bool          | Read / Write / Construct | True                     | Enable or disable finger-scroll.                                                                                                           |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``force``                        | int           | Read / Write / Construct | 120                      | Force applied to the movement,                                                                                                             |
|                                  |               |                          |                          | multiplies the calculated speed of                                                                                                         | 
|                                  |               |                          |                          | theuser movement the cursor in the                                                                                                         |
|                                  |               |                          |                          | screen.                                                                                                                                    |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``hadjustment``                  | gtk.Adjustment| Read                     |                          | The GtkAdjustment for the horizontal                                                                                                       |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
|``hovershoot-max``                | int           | Read / Write / Construct | 150                      | Space we allow the widget to pass                                                                                                          |
|                                  |               |                          |                          | over its horizontal limits                                                                                                                 |
|                                  |               |                          |                          | whenhitting the edges, set 0 in order                                                                                                      |
|                                  |               |                          |                          |  to deactivate overshooting.                                                                                                               |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``hscrollbar-policy``            | GtkPolicyType | Read / Write / Construct | gtk.POLICY_AUTOMATIC     | Visual policy of the horizontal scrollbar.                                                                                                 |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``initial-hint``                 | bool          | Read / Write / Construct | True                     | Whether to hint the user about the pannability of the container.                                                                           |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``low-friction-mode``            | bool          | Read / Write / Construct | False                    | Change the finger-scrolling mode.                                                                                                          |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``mode``                         | Mode          | Read / Write / Construct | PANNABLE_AREA_MODE_AUTO  | Change the finger-scrolling mode.                                                                                                          |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``mov-mode``                     | MovementMode  | Read / Write / Construct | hildon.MOVEMENT_MODE_VERT| Controls if the widget can scroll vertically, horizontally or both.                                                                        |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``panning-threshold``            | int           | Read / Write / Construct | 6                        | Amount of pixels to consider a motion event an scroll, if it is lessit is a click detected incorrectly by the touch screen.                |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``scroll-time``                  | float         | Read / Write / Construct | 10                       | The time to scroll to a position when calling the hildon_pannable_scroll_to function.                                                      |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``scrollbar-fade-delay``         | int           | Read / Write / Construct | 3000                     | Time the scrollbar is going to be visible if the widget is not inaction in miliseconds.                                                    |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``size-request-policy``          | SizeRequestPol| Read / Write / Construct | SIZE_REQUEST_MINIMUM     | Controls the size request policy of the widget.                                                                                            |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``sps``                          | int           | Read / Write / Construct | 20                       | Amount of scroll events to generate per second.                                                                                            |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``vadjustment``                  | gtk.Adjustment| Read                     |                          | The GtkAdjustment for the vertical position.                                                                                               |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``velocity-fast-factor``         | float         | Read / Write / Construct | 0.02                     | Minimum velocity that is considered 'fast': children widgets won't receive button presses. Expressed as a fraction of the maximum velocity.|
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``velocity-max``                 | float         | Read / Write / Construct | 500                      | Maximum distance the child widget should scroll per 'frame', in pixels per frame.                                                          |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``velocity-min``                 | float         | Read / Write / Construct | 20                       | Minimum distance the child widget should scroll per 'frame', in pixels per frame.                                                          |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``velocity-overshooting-max``    | float         | Read / Write / Construct | 20                       | Maximum distance the child widget should scroll per 'frame', in pixels per frame when it overshoots after hitting the edge.                |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``vovershoot-max``               | int           | Read / Write / Construct | 150                      | Space we allow the widget to pass over its vertical limits whenhitting the edges, set 0 in order to deactivate overshooting.               |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+
| ``vscrollbar-policy``            | PolicyType    | Read / Write / Construct | gtk.POLICY_AUTOMATIC     | Visual policy of the vertical scrollbar.                                                                                                   |
+----------------------------------+---------------+--------------------------+--------------------------+--------------------------------------------------------------------------------------------------------------------------------------------+



Style Property Details
======================

+----------------------+------+--------------+----------+-------------------------------------------------+
| Name                 | type | Access       | Default  | Meaning                                         |
+======================+======+==============+==========+=================================================+
| ``indicator-width``  | int  | Read / Write | 8        | Pixel width used to draw the scroll indicators. |
+----------------------+------+--------------+----------+-------------------------------------------------+


Signal Details
==============

The ``horizontal-movement`` signal

.. function:: user_function(hildonpannable, direction, initial_x, initial_y, user_data)

    The horizontal-movement signal is emitted when the pannable area starts a horizontal movement.


    :param hildonpannable: the object which received the signal
    :param direction: the direction of the movement hildon.MOVEMENT_UP or hildon.MOVEMENT_DOWN
    :param initial_x: the x value of the touched point in the area when the motion started
    :param initial_y: the y value of the touched point in the area when the motion started
    :param user_data: user data set when the signal handler was connected.


.. _HildonPannableArea-vertical-movement:

The ``vertical-movement`` signal

.. function:: user_function(hildonpannable, direction, initial_x, initial_y, user_data)

    The vertical-movement signal is emitted when the pannable area starts a vertical movement.

    :param hildonpannable: the object which received the signal
    :param direction: the direction of the movement hildon.MOVEMENT_LEFT or hildon.MOVEMENT_RIGHT
    :param initial_x: the x value when the motion started
    :param initial_y: the y value when the motion started
    :param user_data: user data set when the signal handler was connected.


See Also
========

:class:`GtkScrolledWindow` 


Entry
*****

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkEntry
                             +----HildonEntry
  


Implemented Interfaces
======================

Entry implements :class:`AtkImplementorIface` , :class:`GtkBuildable` , :class:`GtkEditable` and :class:`GtkCellEditable` .


Description
===========

The :class:`Entry` is a GTK widget which represents a text entry. It is derived from the :class:`gtk.Entry` widget and provides additional commodities specific to the Hildon framework.

Besides all the features inherited from :class:`gtk.Entry` , a :class:`Entry` can also have a placeholder text. This text will be shown if the entry is empty and doesn't have the input focus, but it's otherwise ignored. Thus, calls to `hildon_entry_get_text() <hildon-entry-get-text>`_ will never return the placeholder text, not even when it's being displayed.

Although :class:`Entry` is derived from :class:`gtk.Entry` , `get_text`_ and `set_text` must never be used to get/set the text in this widget. `get_text` and `set_text` must be used instead.

Creating a Entry with a placeholder 

::

    def create_entry():
        entry = hildon.Entry(hildon.SIZE_AUTO)
        entry.set_placeholder("First name")
        return entry

Details
=======

.. class:: Entry

    .. method:: __init__(size = 0)
        Creates a new entry.

        :param size: The size of the entry
        :returns:  a new :class:`Entry`


    .. method:: set_text(text)
        Sets the text in ``entry`` to ``text``, replacing its current contents.
        Note that you must never use :meth:`set_text()`_ to set the text of a :class:`Entry` .

        :param text: the new text


    .. method:: get_text()
        Gets the current text in ``entry``.
        Note that you must never use :meth:`get_text()` to get the text from a :class:`Entry` .
        Also note that placeholder text (set using :meth:`set_placeholder()` is never returned. Only text set by :meth:`set_text` or typed by the user is considered.

        :returns:  the text in ``entry``. This text must not be modified or freed.

    .. method:: set_placeholder(text)
        Sets the placeholder text in ``entry`` to ``text``.
    
        :param text: the new text


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



:returns: 
  a new :class:`HildonTextView`


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-text-view-get-buffer:

.. function:: hildon_text_view_get_buffer ()

::

  GtkTextBuffer*      hildon_text_view_get_buffer         (HildonTextView *text_view);

Returns the text buffer in ``text_view``. The reference count is not incremented; the caller of this function won't own a new reference.

Note that you must never use `gtk_text_view_get_buffer() <gtk-text-view-get-buffer>`_ to get the buffer from a :class:`HildonTextView` .

Also note that placeholder text (set using `hildon_text_view_set_placeholder() <hildon-text-view-set-placeholder>`_ ) is never contained in this buffer.



``text_view``:
  a :class:`HildonTextView`


:returns: 
  a :class:`GtkTextBuffer`


.. versionadded 2.2

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


.. versionadded 2.2

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

To use a :class:`HildonAppMenu` , add it to a :class:`Window` using :meth:`Window.set_app_menu` . The menu will appear when the user presses the window title bar. Alternatively, you can show it by hand using `hildon_app_menu_popup() <hildon-app-menu-popup>`_ .

The menu will be automatically hidden when one of its buttons is clicked. Use `g_signal_connect_after() <g-signal-connect-after>`_ when connecting callbacks to buttons to make sure that they're called after the menu disappears. Alternatively, you can add the button to the menu before connecting any callback.

Although implemented with a :class:`gtk.Window` , :class:`HildonAppMenu` behaves like a normal ref-counted widget, so `g_object_ref() <g-object-ref>`_ , `g_object_unref() <g-object-unref>`_ , `g_object_ref_sink() <g-object-ref-sink>`_ and friends will behave just like with any other non-toplevel widget.

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



:returns: 
  A :class:`HildonAppMenu` .


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

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


.. versionadded 2.2

.. _hildon-app-menu-get-items:

.. function:: hildon_app_menu_get_items ()

::

  GList*              hildon_app_menu_get_items           (HildonAppMenu *menu);

Returns a list of all items (regular items, not filters) contained in ``menu``.



``menu``:
  a :class:`HildonAppMenu`


:returns: 
  a newly-allocated list containing the items in ``menu``\


.. versionadded 2.2

.. _hildon-app-menu-get-filters:

.. function:: hildon_app_menu_get_filters ()

::

  GList*              hildon_app_menu_get_filters         (HildonAppMenu *menu);

Returns a list of all filters contained in ``menu``.



``menu``:
  a :class:`HildonAppMenu`


:returns: 
  a newly-allocated list containing the filters in ``menu``\


.. versionadded 2.2

.. _hildon-app-menu-popup:

.. function:: hildon_app_menu_popup ()

::

  void                hildon_app_menu_popup               (HildonAppMenu *menu,
                                                           gtk.Window *parent_window);

Displays a menu on top of a window and makes it available for selection.



``menu``:
  a :class:`HildonAppMenu`


``parent_window``:
  a :class:`gtk.Window`


.. versionadded 2.2

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


:returns: 
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


:returns: 
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


:returns: 
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


:returns: 
  TRUE, if iter was set


.. _hildon-find-toolbar-get-last-index:

.. function:: hildon_find_toolbar_get_last_index ()

::

  int              hildon_find_toolbar_get_last_index  (HildonFindToolbar *toolbar);

Returns the index of the last (most recently added) item in the toolbar. Can be used to set this item active in the history-append signal.



``toolbar``:
  A find toolbar to query


:returns: 
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

:class:`Window`

EditToolbar
***********

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
                                         +----EditToolbar
  

Implemented Interfaces
======================

EditToolbar implements :class:`AtkImplementorIface` and :class:`gtk.Buildable` .

Description
===========

The :class:`EditToolbar` is a toolbar which contains a label and two buttons, one of them being an arrow pointing backwards.

The label is a description of the action that the user is supposed to do. The button is to be pressed when the user completes the action. The arrow is used to go back to the previous view discarding any changes.

Note that those widgets don't do anything themselves by default. To actually peform actions the developer must provide callbacks for them.

To add a :class:`EditToolbar` to a window use :meth:`Window.set_edit_toolbar` .

::

    window = hildon.StackableWindow()
    toolbar = hildon.EditToolbar("Choose items to delete", "Delete");
    # Create more widgets here ...

    # Add toolbar to window
    window.set_edit_toolbar(toolbar)

    # Add other widgets ...

    g_signal_connect(toolbar, "button-clicked", delete_button_clicked, someparameter);
    g_signal_connect_swapped(toolbar, "arrow-clicked", gtk.widget_destroy, window);

    gtk.widget_show_all(window);
    gtk.window_fullscreen(window);



.. _EditToolbar.details:

Details
=======

.. class:: EditToolbar

    .. method:: __init__([label, [button]])

        Creates a new :class:`EditToolbar` , with the toolbar label set to ``label`` and the button label set to ``button``.

        :param label: Text for the toolbar label.
        :param button: Text for the toolbar button.
        :returns: a new :class:`EditToolbar`

        .. versionadded 2.2

.. method:: set_label (label)

    Sets the label of ``toolbar`` to ``label``. This will clear any previously set value.

    :param toolbar: a :class:`EditToolbar`
    :param label: a new text for the toolbar label

    .. versionadded 2.2

.. method:: set_button_label (label)

Sets the label of the toolbar button to ``label``. This will clear any previously set value.

:param toolbar: a :class:`EditToolbar`
:param label: a new text for the label of the toolbar button

.. versionadded 2.2

Style Property Details
======================

+---------------------------+--------+--------------------------+--------------+--------------------------------------+
| Name                      | type   | Access                   | Default      | Meaning                              |
+===========================+========+==========================+==============+======================================+
| ``arrow-height``          | int    | Read                     | 56           | Number of steps that is going to be  |
+---------------------------+--------+--------------------------+--------------+--------------------------------------+
| ``arrow-width``           | int    | Read                     | 112          | The multiplier used when decelerating|
+---------------------------+--------+--------------------------+--------------+--------------------------------------+

::

    arrow-height             int                 : Read

Height of the arrow button.

Default value: 56

.. _EditToolbar--arrow-width:

The ``arrow-width`` style property

::

    arrow-width              int                 : Read

Width of the arrow button.

Default value: 112

.. _EditToolbar.signal-details:

Signal Details
==============

.. _EditToolbar-arrow-clicked:

The ``arrow-clicked`` signal

::

  void                user_function                      (EditToolbar *widget,
                                                          gpointer           user_data)      : Run First

Emitted when the toolbar back button (arrow) has been activated (pressed and released).



``widget``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. versionadded 2.2

.. _EditToolbar-button-clicked:

The ``button-clicked`` signal

::

  void                user_function                      (EditToolbar *widget,
                                                          gpointer           user_data)      : Run First

Emitted when the toolbar button has been activated (pressed and released).



``widget``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. versionadded 2.2

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
  


:returns: 
  


.. _hildon-wizard-dialog-new:

.. function:: hildon_wizard_dialog_new ()

::

  GtkWidget*          hildon_wizard_dialog_new            (GtkWindow *parent,
                                                           const char *wizard_name,
                                                           GtkNotebook *notebook);

Creates a new :class:`HildonWizardDialog` .



``parent``:
  a :class:`gtk.Window`


``wizard_name``:
  the name of dialog


``notebook``:
  the notebook to be shown on the dialog


:returns: 
  a new :class:`HildonWizardDialog`


.. _hildon-wizard-dialog-set-forward-page-func:

.. function:: hildon_wizard_dialog_set_forward_page_func ()

::

  void                hildon_wizard_dialog_set_forward_page_func
                                                          (HildonWizardDialog *wizard_dialog,
                                                           HildonWizardDialogPageFunc page_func,
                                                           gpointer data,
                                                           GDestroyNotify destroy);

Sets the page forwarding function to be ``page_func``. This function will be used to determine whether it is possible to go to the next page when the user presses the forward button. Setting ``page_func`` to None wil make the wizard to simply go always to the next page.



``wizard_dialog``:
  a :class:`HildonWizardDialog`


``page_func``:
  the :class:`HildonWizardDialogPageFunc`


``data``:
  user data for ``page_func``\


``destroy``:
  destroy notifier for ``data``\


.. versionadded 2.2

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



PickerDialog
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
                                         +----GtkDialog
                                               +----HildonDialog
                                                     +----PickerDialog

Implemented Interfaces
======================

PickerDialog implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Description
===========

:class:`PickerDialog` is a dialog that is used to show a :class:`HildonTouchSelector` widget and a 'Done' button to allow users to finish their selections.

The :class:`PickerDialog` will show a 'Done' button in case the :class:`HildonTouchSelector` allows multiple selection. The label of the button can be set using :meth:`PickerDialog.set_done_label` and retrieved using :meth:`PickerDialog.get_done_label`

Note that in most cases developers don't need to deal directly with this widget. :class:`HildonPickerButton` is designed to pop up a :class:`PickerDialog` and manage the interaction with it.

Details
=======

.. data:: HILDON_DISABLE_DEPRECATED

.. class:: PickerDialog

    Button label

    .. versionadded 2.2

    .. method:: __init__(parent)

        Creates a new :class:`PickerDialog`

        :param parent: the parent window
        :returns: a new :class:`PickerDialog`

        .. versionadded 2.2

    .. method:: set_selector (selector)

        Sets ``selector`` as the :class:`HildonTouchSelector` to be shown in ``dialog``

        :param selector: a :class:`HildonTouchSelector`
        :returns: True if ``selector`` was set, False otherwise

        .. versionadded 2.2

    .. method:: set_done_label (label)

        Sets a custom string to be used as the 'Done' button label in ``dialog``.

        :param dialog: a :class:`PickerDialog`
        :param label: a string

        .. versionadded 2.2

    .. method:: get_done_label ()

        Retrieves current 'Done' button label.

        :returns: the custom string to be used.

        .. versionadded 2.2

    .. method:: get_selector ()

        Retrieves the :class:`HildonTouchSelector` associated to ``dialog``.

        :returns: a :class:`HildonTouchSelector`

        .. versionadded 2.2

Property Details
================

+---------------------------+--------+--------------------------+----------------+------------------------------------------------------------------------+
| Name                      | type   | Access                   | Default        | Meaning                                                                |
+===========================+========+==========================+================+========================================================================+
| ``center-on-show``        | bool   | Read / Write / Construct | True           | If the dialog should center on the current selection when it is showed.|
+---------------------------+--------+--------------------------+----------------+------------------------------------------------------------------------+
| ``done-button-text``      | str    | Read / Write / Construct | "wdgt_bd_done" | Done Button Label.                                                     |
+---------------------------+--------+--------------------------+----------------+------------------------------------------------------------------------+

AnimationActor
**************

Details
=======

.. class:: AnimationActor

    .. method:: __init__ ()

        Creates a new :class:`AnimationActor` .

        :returns: A :class:`AnimationActor`

        .. versionadded 2.2

    .. method:: send_message (message_type, l0, l1, l2, l3, l4)

        Sends an X11 ClientMessage event to the window manager with the specified parameters -- id (``message_type``) and data (``l0``, ``l1``, ``l2``, ``l3``, ``l4``).

        This is an internal utility function that application will not need to call directly.

        :param message_type: Message id for the animation actor message.
        :param l0: 1st animation actor message parameter.
        :param l1: 2nd animation actor message parameter.
        :param l2: 3rd animation actor message parameter.
        :param l3: 4th animation actor message parameter.
        :param l4: 5th animation actor message parameter.

        .. versionadded 2.2

    .. method:: set_anchor (x, y)

        Send a message to the window manager setting the anchor point for the animation actor. The anchor point is the point to which the actor position within its parent it is relative.

        If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param x: The X coordinate of the anchor point.
        :param y: The Y coordinate of the anchor point.

        .. versionadded 2.2

    .. method:: set_anchor_from_gravity (gravity)

        Send a message to the window manager setting the anchor point for the animation actor. The anchor point is the point to which the actor position within its parent it is relative. Instead of being defined in (x, y)-coordinates, the anchor point is defined in the relative "gravity" constant as:

        :const:`HILDON_AA_N_GRAVITY`
            translates to (width / 2, 0) coordinate 
        :const:`HILDON_AA_NE_GRAVITY`
            translates to (width, 0) coordinate 
        :const:`HILDON_AA_E_GRAVITY`
            translates to (width, height / 2) coordinate 
        :const:`HILDON_AA_SE_GRAVITY`
            translates to (width, height) coordinate 
        :const:`HILDON_AA_S_GRAVITY`
            translates to (width / 2, height) coordinate 
        :const:`HILDON_AA_SW_GRAVITY`
            translates to (0, height) coordinate 
        :const:`HILDON_AA_W_GRAVITY`
            translates to (0, height / 2) coordinate 
        :const:`HILDON_AA_NW_GRAVITY`
            translates to (0, 0) coordinate 
        :const:`HILDON_AA_CENTER_GRAVITY`
            translates to (width / 2, height / 2) coordinate

        If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param gravity: The gravity constant.

        .. versionadded 2.2

    .. method:: set_depth (depth)

        A shortcut for :meth:`AnimationActor.set_position_full` , changing the window depth, but preserving it's position.

        :param depth: Desired window depth (Z coordinate)

        .. versionadded 2.2

    .. method:: set_opacity (opacity)

        This function is a shortcut for :meth:`AnimationActor.set_show_full` , setting actor opacity without changing it's overall visibility.

        See :meth:`AnimationActor.set_show_full` for description of the range of values ``opacity`` argument takes.

        :param opacity: Desired opacity setting

        .. versionadded 2.2

    .. method:: set_parent (parent)

        Send a message to the window manager setting the parent window for the animation actor. Parenting an actor will not affect the X window that the AnimationActor represents, but it's off-screen bitmap as it is handled by the compositing window manager.

        Parenting an animation actor will affect its visibility as set by the :function:`gtk.Widget.show_all` , :meth:`GtkWidget.hide` and :meth:`AnimationActor.set_show` . The animation actor will only be visible when the top-level window it is parented is visible.

        Passing None as a ``parent`` argument will unparent the animation actor. This will restore the actor's visibility if it was suppressed by being unparented or parented to an unmapped window.

        If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param parent: A :class:`gtk.Window` that the actor will be parented to.

        .. versionadded 2.2

    .. method:: set_position (x, y)

        A shortcut for :meth:`AnimationActor.set_position_full` , changing the window position, but preserving it's depth setting.

        :param x: Desired window X coordinate
        :param y: Desired window Y coordinate

        .. versionadded 2.2

    .. method:: set_position_full (x, y, depth)

        Send a message to the window manager setting the position of the animation actor. This will set the position of the animation actor off-screen bitmap as it is rendered to the screen. The position of the actor is relative to the parent window. The actor is also subject to the animation effects rendered by the compositing window manager on that window (like those by task switcher).

        The window depth affects the stacking of animation actors within a parent window and, more generally, the stacking of clutter actors within a stage/container. The default depth is 0 and a parent window's container will have it's window texture stacked at that level. The stacking at any depth level is sequential -- animation actor B created/parented after animation actor A will obscure the latter if they overlap.

        Animation actors with non-zero depth settings are subject to scaling as per the global scene perspective setup, which limits the depth setting as the primary parameter to control the stacking order. Since the stacking order follows the parenting order, it may be better to use :meth:`AnimationActor.set_parent` for setting the stacking.

        If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param x: Desired X coordinate
        :param y: Desired Y coordinate
        :param depth: Desired window depth (Z coordinate)

        .. versionadded 2.2

    .. method:: set_rotation (axis, degrees, x, y, z)

        Send a message to the window manager setting the animation actor rotation around one of the three axes. The rotation center coordinates depend on the axis of rotation:

        :const:`HILDON_AA_X_AXIS`
            requires ``y`` and ``z`` coordinates.
        :const:`HILDON_AA_Y_AXIS`
            requires ``x`` and ``z`` coordinates. 
        :const:`HILDON_AA_Z_AXIS`
            requires ``x`` and ``y`` coordinates.

        If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param axis: The rotation axis.
        :param degrees: The rotation angle in degrees.
        :param x: Center of the rotation, X coordinate.
        :param y: Center of the rotation, Y coordinate.
        :param z: Center of the rotation, Z coordinate.

        .. versionadded 2.2

    .. method:: set_rotationx (axis, degrees, x, y, z)

        This function is just like :meth:`AnimationActor.set_rotation` , but the rotation angle is given as 16-bit fixed-point number.

        :param axis: The rotation axis.
        :parma degrees: The rotation angle in degrees.
        :param x: Center of the rotation, X coordinate.
        :param y: Center of the rotation, Y coordinate.
        :param z: Center of the rotation, Z coordinate.

        .. versionadded 2.2

    .. method:: set_scale (x_scale, y_scale)

        Send a message to the window manager setting the scale factors of the animation actor. This will set the scale factors on the animation actor off-screen bitmap as it is rendered to the screen. If the animation actor is parented to another top-level window, the animation effects rendered by the compositing window manager on that top-level window (like those by task switcher) will also affect the animation actor.

        If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param x_scale: Window's desired scale factor along the X-axis
        :param y_scale: Window's desired scale factor along the Y-axis

        .. versionadded 2.2

    .. method:: set_scalex (x_scale, y_scale)

        This function is just like :meth:`AnimationActor.set_scale` , but the scale factors are given as 16-bit fixed-point number.

        :param x_scale: Window's desired scale factor along the X-axis
        :param y_scale: Window's desired scale factor along the Y-axis

        .. versionadded 2.2

    .. method:: set_show (show)

        This function is a shortcut for :meth:`AnimationActor.set_show_full` , setting the overall actor visibility without changing it's opacity setting.

        :param show: A boolean flag setting the visibility of the animation actor.

        .. versionadded 2.2

    .. method:: set_show_full (show, opacity)

        Send a message to the window manager setting the visibility of the animation actor. This will only affect the visibility of the animation actor set by the compositing window manager in its own rendering pipeline, after X has drawn the window to the off-screen buffer. This setting, naturally, has no effect if the :class:`AnimationActor` widget is not visible in X11 terms (i.e. realized and mapped).

        Furthermore, if a widget is parented, its final visibility will be affected by that of the parent window.

        The opacity setting ranges from zero (0), being completely transparent to 255 (0xff) being fully opaque.

        If the animation actor WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param show: A boolean flag setting the visibility of the animation actor.
        :param opacity: Desired opacity setting

        .. versionadded 2.2

.. data:: HILDON_AA_CENTER_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_E_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_NE_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_NW_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_N_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_SE_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_SW_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_S_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_W_GRAVITY

    .. seealso:: :meth:`AnimationActor.set_anchor_from_gravity`

.. data:: HILDON_AA_X_AXIS

    .. seealso:: :meth:`AnimationActor.set_rotation`

.. data:: HILDON_AA_Y_AXIS

    .. seealso:: :meth:`AnimationActor.set_rotation`

.. data:: HILDON_AA_Z_AXIS

    .. seealso:: :meth:`AnimationActor.set_rotation`

RemoteTexture
*******************

Description
===========

The :class:`RemoteTexture` is a GTK+ widget which allows the rendering of a shared memory area within hildon-desktop. It allows the memory area to be positioned and scaled, without altering its' contents.

Details
=======

.. class:: RemoteTexture

    .. method:: __init__ ()

        Creates a new :class:`RemoteTexture` .

        :returns: A :class:`RemoteTexture`

        .. versionadded 2.2

    .. method:: send_message (message_type, l0, l1, l2, l3, l4)

        Sends an X11 ClientMessage event to the window manager with the specified parameters --- id (``message_type``) and data (``l0``, ``l1``, ``l2``, ``l3``, ``l4``).

        This is an internal utility function that application will not need to call directly.

        :param message_type: Message id for the remote texture message.
        :param l0: 1st remote texture message parameter.
        :param l1: 2nd remote texture message parameter.
        :param l2: 3rd remote texture message parameter.
        :param l3: 4th remote texture message parameter.
        :param l4: 5th remote texture message parameter.

        .. versionadded 2.2

    .. method:: set_image (key, width, height, bpp)

        :param key: The key that would be used with shmget in hildon-desktop. The key should probably be created with ftok, and the relevant shared memory area should be created before this call.
        :param width: width of image in pixels
        :param height: height of image in pixels
        :param bpp: BYTES per pixel - usually 2,3 or 4

        .. versionadded 2.2


    .. method:: set_offset (x, y)

        Send a message to the window manager setting the offset of the remote texture in the window (in Remote texture's pixels). The texture is also subject to the animation effects rendered by the compositing window manager on that window (like those by task switcher).

        If the remote texture WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param x: Desired X offset
        :param y: Desired Y offset

        .. versionadded 2.2

    .. method:: set_opacity (opacity)

        This function is a shortcut for :meth:`RemoteTexture.set_show_full` , setting actor opacity without changing it's overall visibility.

        See :meth:`RemoteTexture.set_show_full` for description of the range of values ``opacity`` argument takes.

        :param opacity: Desired opacity setting

        .. versionadded 2.2


    .. method:: set_parent (parent)

        Send a message to the window manager setting the parent window for the remote texture. Parenting an actor will not affect the X window that the RemoteTexture represents, but it's off-screen bitmap as it is handled by the compositing window manager.

        Parenting an remote texture will affect its visibility as set by the :function:`gtk.Widget.show_all` , :meth:`GtkWidget.hide` and `hildon_remote_texture_set_show() <hildon-remote-texture-set-show>`_ . The remote texture will only be visible when the top-level window it is parented is visible.

        Passing None as a ``parent`` argument will unparent the remote texture. This will restore the actor's visibility if it was suppressed by being unparented or parented to an unmapped window.

        If the remote texture WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param parent: A :class:`gtk.Window` that the actor will be parented to.

        .. versionadded 2.2

    .. method:: set_position (x, y, width, height)

        Send a message to the window manager setting the offset of the remote texture in the window (in Remote texture's pixels). The texture is also subject to the animation effects rendered by the compositing window manager on that window (like those by task switcher).

        If the remote texture WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param x: Desired X coordinate
        :param y: Desired Y coordinate
        :param width: Desired width
        :param height: Desired height

        .. versionadded 2.2

    .. method:: set_scale (x_scale, y_scale)

    .. method:: set_show (show)

        This function is a shortcut for :meth:`RemoteTexture.set_show_full` , setting the overall actor visibility without changing it's opacity setting.

        :param show: A boolean flag setting the visibility of the remote texture.

        .. versionadded 2.2

    .. method:: set_show_full (show, opacity)

        Send a message to the window manager setting the visibility of the remote texture. This will only affect the visibility of the remote texture set by the compositing window manager in its own rendering pipeline, after X has drawn the window to the off-screen buffer. This setting, naturally, has no effect if the :class:`RemoteTexture` widget is not visible in X11 terms (i.e. realized and mapped).

        Furthermore, if a widget is parented, its final visibility will be affected by that of the parent window.

        The opacity setting ranges from zero (0), being completely transparent to 255 (0xff) being fully opaque.

        If the remote texture WM-counterpart is not ready, the show message will be queued until the WM is ready for it.

        :param show: A boolean flag setting the visibility of the remote texture.
        :param opacity: Desired opacity setting

        .. versionadded 2.2

    .. method:: update_area (x, y, width, height)

        This signals to hildon-desktop that a specific region of the memory area has changed. This will trigger a redraw and will update the relevant tiles of the texture.

        :param x: offset of damaged area in pixels
        :param y: offset of damaged area in pixels
        :param width: width of damaged area in pixels
        :param height: height of damaged area in pixels

        .. versionadded 2.2


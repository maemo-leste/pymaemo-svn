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

        :param child: :class:`gtk.Widget`


    .. method:: set_main_menu (menu)

        Sets the menu to be used for this window. This menu overrides a program-wide menu that may have been set with :meth:`HildonProgram.set_common_menu` . Pass None to remove the current menu. :class:`Window` takes ownership of the passed menu and you're not supposed to free it yourself anymore.

        Note that if you're using a :class:`HildonAppMenu` rather than a :class:`GtkMenu` you should use :meth:`Window.set_app_menu` instead.

        :param menu: The :class:`GtkMenu` to be used for this :class:`Window`

    .. method:: get_main_menu ()

        Gets the :class:`GtkMenu` assigned to the :class:`HildonAppview` . Note that the window is still the owner of the menu.

        Note that if you're using a :class:`HildonAppMenu` rather than a :class:`GtkMenu` you should use :meth:`Window.get_app_menu` instead.

        :returns: The :class:`GtkMenu` assigned to this application view.

        .. versionadded 2.2

    .. method:: set_app_menu (menu)

        Sets the menu to be used for this window. Pass None to remove the current menu. Any reference to a previous menu will be dropped. :class:`Window` takes ownership of the passed menu and you're not supposed to free it yourself anymore.

        Note that if you're using a :class:`GtkMenu` rather than a :class:`HildonAppMenu` you should use :meth:`Window.set_main_menu` instead.

        :param menu: a :class:`HildonAppMenu` to be used for this window

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

        :param menu: The :class:`GtkMenu` to be used for this :class:`Window`

    .. method:: get_menu ()

        .. warning:: :meth:`Window.get_menu` is deprecated and should not be used in newly-written code. In Hildon 2.2 this function has been renamed to :meth:`Window.get_main_menu` for consistency

        :returns:  a :class:`GtkMenu`


    .. method:: add_toolbar (toolbar)

        Adds a toolbar to the window. Note that the toolbar is not automatically shown. You need to call :meth:`GtkWidget.show_all` on it to make it visible. It's also possible to hide the toolbar (without removing it) by calling :meth:`GtkWidget.hide`

        :param toolbar: A :class:`GtkToolbar` to add to the :class:`Window`

    .. method:: remove_toolbar (toolbar)

        Removes a toolbar from the window. Note that this decreases the refference count on the widget. If you want to keep the toolbar alive call :meth:`GObject.ref` before calling this function.

        :param toolbar: A :class:`GtkToolbar` to remove from the :class:`Window`


    .. method:: set_edit_toolbar (toolbar)

        Adds a :class:`EditToolbar` to the window. Note that the toolbar is not automatically shown. You need to call :meth:`GtkWidget.show` on it to make it visible. It's also possible to hide the toolbar (without removing it) by calling :meth:`GtkWidget.hide` .

        A window can only have at most one edit toolbar at a time, so the previous toolbar (if any) is replaced after calling this function.

        :param toolbar: A :class:`EditToolbar` , or None to remove the current one.

        .. versionadded 2.2

    .. method:: get_is_topmost ()

        Returns whether the :class:`Window` is currenty activated by the window manager.

        :returns:  True ``self`` is currently activated, False otherwise.


    .. method:: set_markup (markup)

        Sets the marked up title of ``window``. The accepted format is the one used in Pango (see :class:`PangoMarkupFormat` ) with the exception of span.

        Note that you need support from the window manager for this title to be used. See :meth:`gtk.Window.set_title` for the standard way of setting the title of a window.

        :param markup: the marked up title of the window, or None to unset the current one

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

Signal Details
==============

.. _Window-clipboard-operation:

    The ``clipboard-operation`` signal.

    .. function:: user_function(hildon_window, arg1, user_data)

        :param hildon_window: the object which received the signal.
        :param operation: the operation that happened
        :param user_data: user data set when the signal handler was connected.


.. _Window.see-also:

See Also
========

:class:`HildonProgram` :class:`HildonStackableWindow` 

.. _HildonStackableWindow:

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

Each application has a default stack, and windows are automatically added to it when they are shown with :meth:`gtk.Widget.show_all` .

Additional stacks can be created at any time using :meth:`hildon.WindowStack` . To add a window to a specific stack, use :meth:`hildon.WindowStack.push_1` (remember that, for the default stack, :meth:`gtk.Widget.show_all` can be used instead).

To remove a window from a stack use :meth:`hildon.WindowStack.pop_1` , or simply :meth:`gtk.Widget.hide` .

For more complex layout changes, applications can push and/or pop several windows at the same time in a single step. See :meth:`hildon.WindowStack.push` , :meth:`hildon.WindowStack.pop` and :meth:`hildon.WindowStack.pop_and_push` for more details.


Details
=======

.. class:: WindowStack

    .. method:: get_default ()

        Returns the default window stack. This stack always exists and doesn't need to be created by the application.

        :returns: the default :class:`WindowStack`

        .. versionadded 2.2

    .. method:: __init__ ()

        Creates a new :class:`WindowStack` . The stack is initially empty.

        :returns: a new :class:`WindowStack`

        .. versionadded 2.2

    .. method:: size ()

        Returns the number of windows in ``stack``

        :returns: Number of windows in ``stack``

        .. versionadded 2.2

    .. method:: get_windows ()

        Returns the list of windows on this stack (topmost first). The widgets in the list are not individually referenced.

        :returns: a newly-allocated list of :class:`HildonStackableWindow` s

        .. versionadded 2.2

    .. method:: peek ()

        Returns the window on top of ``stack``. The stack is never modified.

        :returns: the window on top of the stack, or None if the stack is empty.

        .. versionadded 2.2

    .. method:: push (win1, ...)

        Pushes all windows to the top of ``stack``, and shows them. Everything is done in a single transition, so the user will only see the last window. None of the windows must be already stacked.

        :param win1: The first window to push

        :param ...: A None -terminated list of additional :class:`HildonStackableWindow` s to push.

        .. versionadded 2.2

    .. method:: push_list (list)

        Pushes all windows in ``list`` to the top of ``stack``, and shows them. Everything is done in a single transition, so the user will only see the last window in ``list`` during this operation. None of the windows must be already stacked.

        :param list: A list of :class:`HildonStackableWindow` s to push

        .. versionadded 2.2

    .. method:: push_1 (win)

        Adds ``win`` to the top of ``stack``, and shows it. The window must not be already stacked.

        ``win``: A :class:`HildonStackableWindow`

        .. versionadded 2.2

    .. method:: pop (nwindows, popped_windows)

        Pops ``nwindows`` windows from ``stack``, and hides them. Everything is done in a single transition, so the user will not see any of the windows being popped in this operation.

        If ``popped_windows`` is not None , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.

        ``nwindows``: Number of windows to pop

        ``popped_windows``: if non-None , the list of popped windows is stored here

        .. versionadded 2.2

    .. method:: pop_1 ()

        Removes the window on top of ``stack``, and hides it. If the stack is empty nothing happens.

        :returns: the window on top of the stack, or None if the stack is empty.

        .. versionadded 2.2

    .. method:: pop_and_push (nwindows, popped_windows, win1, ...)

        Pops ``nwindows`` windows from ``stack`` (and hides them), then pushes all passed windows (and shows them). Everything is done in a single transition, so the user will only see the last pushed window. None of the pushed windows must be already stacked.

        If ``popped_windows`` is not None , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.

        ``nwindows``: Number of windows to pop.

        ``popped_windows``: if non-None , the list of popped windows is stored here

        ``win1``: The first window to push

        ``...``: A None -terminated list of additional :class:`HildonStackableWindow` s to push.

        .. versionadded 2.2

    .. method:: pop_and_push_list (nwindows, popped_windows, list)

        Pops ``nwindows`` windows from ``stack`` (and hides them), then pushes all windows in ``list`` (and shows them). Everything is done in a single transition, so the user will only see the last window from ``list``. None of the pushed windows must be already stacked.

        If ``popped_windows`` is not None , the list of popped windows is stored there (ordered bottom-up). That list must be freed by the user.

        ``nwindows``: Number of windows to pop.

        ``popped_windows``: if non-None , the list of popped windows is stored here

        ``list``: A list of :class:`HildonStackableWindow` s to push

        .. versionadded 2.2

Property Details
================

The ``window-group`` property

============= =============== ============================= ======= =======
Name          type            Access                        Default Meaning
============= =============== ============================= ======= =======
window-group  gtk.WindowGroup Read / Write / Construct Only
============= =============== ============================= ======= =======

GtkWindowGroup that all windows on this stack belong to.

See Also
========

:class:`HildonStackableWindow`

.. _HildonButton:

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

.. _HildonButton.description:

Description
===========

The :class:`HildonButton` is a GTK widget which represents a clickable button. It is derived from the :class:`GtkButton` widget and provides additional commodities specific to the Hildon framework.

The height of a :class:`HildonButton` can be set to either "finger" height or "thumb" height. It can also be configured to use halfscreen or fullscreen width. Alternatively, either dimension can be set to "auto" so it behaves like a standard :class:`GtkButton` .

The :class:`HildonButton` can hold any valid child widget, but it usually contains two labels, named title and value, and it can also contain an image. The contents of the button are packed together inside a :class:`GtkAlignment` and they do not expand by default (they don't use the full space of the button).

To change the alignment of both labels, use :meth:`gtk.Button.set_alignment`.

To make them expand and use the full space of the button, use :meth:`HildonButton.set_alignment` .

To change the relative alignment of each label, use :meth:`HildonButton.set_title_alignment` and :meth:`HildonButton.set_value_alignment` .

In hildon-button-example.c included in the Hildon distribution you can see examples of how to create the most common button layouts.

If only one label is needed, :class:`GtkButton` can be used as well, see also :class:`GtkButton`.

Creating a HildonButton
=======================

::

  def button_clicked(button, user_data=None):
      title = button.get_title()
      value = button.get_value()

      print "Button clicked with title %s and value %s" % (title, value)

  def create_button():
      button = hildon.Button(gtk.HILDON_SIZE_AUTO_WIDTH | gtk.HILDON_SIZE_FINGER_HEIGHT,
                             hildon.BUTTON_ARRANGEMENT_VERTICAL)
      button.set_text("Some title", "some value")

      image = gtk.image_new_from_stock(gtk.STOCK_INFO, gtk.ICON_SIZE_BUTTON)
      button.set_image(image)
      button.set_image_position(gtk.POS_RIGHT)

      button.set_alignment(button, 0.0, 0.5)

      button.connect("clicked", button_clicked)

      return button

.. _HildonButton.details:

Details
=======

.. class:: HildonButton

    .. data:: ButtonArrangement

        +------------------------------------+-----------------------------------------------------+
        | Value                              | Meaning                                             |
        +====================================+=====================================================+
        | ``BUTTON_ARRANGEMENT_HORIZONTAL``  | Labels are arranged from left to right              |
        +------------------------------------+-----------------------------------------------------+
        | ``BUTTON_ARRANGEMENT_VERTICAL``    | Labels are arranged from top to bottom              |
        +------------------------------------+-----------------------------------------------------+

        Describes the arrangement of labels inside a :class:`HildonButton`

    .. data:: ButtonStyle

        +------------------------------------+-----------------------------------------------------+
        | Value                              | Meaning                                             |
        +====================================+=====================================================+
        | ``BUTTON_STYLE_NORMAL``            | The button will look like a :class:`Button`         |
        +------------------------------------+-----------------------------------------------------+
        | ``BUTTON_STYLE_PICKER``            | The button will look like a :class:`PickerButton`   |
        +------------------------------------+-----------------------------------------------------+

        Describes the visual style of a :class:`Button`

    .. method:: __init__ (size, arrangement, title=None, value=None)

        Creates a new :class:`HildonButton` with two labels, ``title`` and ``value``.

        If you just don't want to use one of the labels, set it to None . You can set it to a non-None value at any time later using :meth:`HildonButton.set_title` or :meth:`HildonButton.set_value` .

        :param size: Flags to set the size of the button.
        :param arrangement: How the labels must be arranged.
        :param title: Title of the button (main label), or None
        :parma value: Value of the button (secondary label), or None

        :returns: a new :class:`HildonButton`

        .. versionadded 2.2

    .. method:: set_title (title)

        Sets the title (main label) of ``button`` to ``title``.

        This will clear any previously set title.

        If ``title`` is set to None , the title label will be hidden and the value label will be realigned.

        :param title: a new title (main label) for the button, or None


        .. versionadded 2.2

    .. method:: set_value (value)

        Sets the value (secondary label) of ``button`` to ``value``.

        This will clear any previously set value.

        If ``value`` is set to None , the value label will be hidden and the title label will be realigned.

        :param value: a new value (secondary label) for the button, or None

        .. versionadded 2.2

    .. method:: get_title ()

        Fetches the text from the main label (title) of ``button``, as set by :meth:`HildonButton.set_title` or :meth:`HildonButton.set_text` . If the label text has not been set the return value will be None . This will be the case if you create an empty button to use as a container.

        :returns: The text of the title label. This string is owned by the widget and must not be modified or freed.

        .. versionadded 2.2

    .. method:: get_value ()

        Fetches the text from the secondary label (value) of ``button``, as set by :meth:`HildonButton.set_value` or :meth:`HildonButton.set_text` . If the label text has not been set the return value will be None . This will be the case if you create an empty button to use as a container.

        :returns: The text of the value label. This string is owned by the widget and must not be modified or freed.

        .. versionadded 2.2

    .. method:: set_text (title, value)

        Convenience function to change both labels of a :class:`HildonButton`

        :param title: new text for the button title (main label)
        :param value: new text for the button value (secondary label)

        .. versionadded 2.2

    .. method:: set_image (image)

        Sets the image of ``button`` to the given widget. The previous image (if any) will be removed.

        :param image: a widget to set as the button image

        .. versionadded 2.2

    .. method:: get_image ()

        Gets the widget that is currenty set as the image of ``button``, previously set with :meth:`HildonButton.set_image`

        :returns: a :class:`GtkWidget` or None in case there is no image

        .. versionadded 2.2

    .. method:: set_image_position (position)

        Sets the position of the image inside ``button``. Only :data:`gtk.POS_LEFT` and :data:`gtk.POS_RIGHT` are currently supported.

        :param position: the position of the image (:data:`gtk.POS_LEFT` or :data:`gtk.POS_RIGHT`)

        .. versionadded 2.2

    .. _hildon-button-set-alignment:

    .. method:: set_alignment (xalign, yalign, xscale, yscale)

        Sets the alignment of the contents of the widget. If you don't need to change ``xscale`` or ``yscale`` you can just use :meth:`gtk.Button.set_alignment` instead.

        Note that for this method to work properly the, child widget of ``button`` must be a :class:`GtkAlignment` . That's what :class:`HildonButton` uses by default, so this function will work unless you add a custom widget to ``button``.

        :param xalign: the horizontal alignment of the contents, from 0 (left) to 1 (right).
        :param yalign: the vertical alignment of the contents, from 0 (top) to 1 (bottom).
        :param xscale: the amount that the child widget expands horizontally to fill up unused space, from 0 to 1
        :param yscale: the amount that the child widget expands vertically to fill up unused space, from 0 to 1

        .. versionadded 2.2

    .. _hildon-button-set-title-alignment:

    .. method:: set_title_alignment ()

    ::

      void                hildon_button_set_title_alignment   (HildonButton *button,
                                                               gfloat xalign,
                                                               gfloat yalign);

    Sets the alignment of the title label. See also :meth:`HildonButton.set_alignment` to set the alignment of the whole contents of the button.



    ``button``:
      a :class:`HildonButton`


    ``xalign``:
      the horizontal alignment of the title label, from 0 (left) to 1 (right).


    ``yalign``:
      the vertical alignment of the title label, from 0 (top) to 1 (bottom).


    .. versionadded 2.2

    .. _hildon-button-set-value-alignment:

    .. method:: set_value_alignment ()

    ::

      void                hildon_button_set_value_alignment   (HildonButton *button,
                                                               gfloat xalign,
                                                               gfloat yalign);

    Sets the alignment of the value label. See also :meth:`HildonButton.set_alignment` to set the alignment of the whole contents of the button.



    ``button``:
      a :class:`HildonButton`


    ``xalign``:
      the horizontal alignment of the value label, from 0 (left) to 1 (right).


    ``yalign``:
      the vertical alignment of the value label, from 0 (top) to 1 (bottom).


    .. versionadded 2.2

    .. _hildon-button-set-image-alignment:

    .. method:: set_image_alignment ()

    ::

      void                hildon_button_set_image_alignment   (HildonButton *button,
                                                               gfloat xalign,
                                                               gfloat yalign);

    Sets the alignment of the image. See also :meth:`HildonButton.set_alignment` to set the alignment of the whole contents of the button.



    ``button``:
      a :class:`HildonButton`


    ``xalign``:
      the horizontal alignment of the image, from 0 (left) to 1 (right).


    ``yalign``:
      the vertical alignment of the image, from 0 (top) to 1 (bottom).


    .. versionadded 2.2

    .. _hildon-button-add-title-size-group:

    .. method:: add_title_size_group ()

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

    .. method:: add_value_size_group ()

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

    .. method:: add_image_size_group ()

    ::

      void                hildon_button_add_image_size_group  (HildonButton *button,
                                                               GtkSizeGroup *size_group);

    Adds the image of ``button`` to ``size_group``. You must add an image using :meth:`HildonButton.set_image` before calling this function.



    ``button``:
      a :class:`HildonButton`


    ``size_group``:
      A :class:`GtkSizeGroup` for the button image


    .. versionadded 2.2

    .. _hildon-button-add-size-groups:

    .. method:: add_size_groups ()

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

    .. method:: set_style ()

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

    .. method:: get_style ()

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

CheckButton
***********

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
  

Implemented Interfaces
======================

CheckButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Description
===========

:class:`HildonCheckButton` is a button containing a label and a check box which will remain 'pressed-in' when clicked. Clicking again will make the check box toggle its state.

The state of a :class:`HildonCheckButton` can be set using :meth:`hildon.check_button_set_active` , and retrieved using :meth:`hildon.check_button_get_active` . The label can be set using :meth:`gtk.Button.set_label` and retrieved using :meth:`gtk.Button.get_label` .

.. note:: :class:`HildonCheckButton` does NOT support an image, so don't use :meth:`gtk.Button.set_image` .

Using a Hildon check button
=========================== 
::
  
  def button_toggled(checkbutton):
      if (checkbutton.get_active()):
          print "Button is active"
      else:
          print "Button is not active"

  def create_check_button():
      button = hildon.CheckButton(gtk.HILDON_SIZE_AUTO)
      button.set_label("Click me")
      button.connect("toggled", button_toggled)
      return button

Details
=======

.. class:: HildonCheckButton

    .. method:: __init__ (size)

        Creates a new :class:`HildonCheckButton` .

        :param size: Flags indicating the size of the new button

        :returns: A newly created :class:`HildonCheckButton`

        .. versionadded 2.2

    .. method:: set_active (is_active)

        Sets the status of a :class:`HildonCheckButton` . Set to True if you want ``button`` to be 'pressed-in', and False to raise it. This action causes the "toggled" signal to be emitted.

        :param is_active: new state for the button

        .. versionadded 2.2

    .. method:: get_active ()

        Gets the current state of ``button``.

        :returns: True if ``button`` is active, False otherwise.

        .. versionadded 2.2

    .. method:: toggled ()

        Emits the "toggled" signal on the :class:`HildonCheckButton` . There is no good reason for an application ever to call this function.

        .. versionadded 2.2


Style Property Details
======================

The ``checkbox-size`` style property

============= ==== ====== ======= ======================
Name          type Access Default Meaning
============= ==== ====== ======= ======================
checkbox-size int  Read   26      Size of the check box.
============= ==== ====== ======= ======================

Signal Details
==============

The ``toggled`` signal


.. function:: user_function (user_data)

    Emitted when the :class:`HildonCheckButton` 's state is changed.

    :param user_data: user data set when the signal handler was connected.

    .. versionadded 2.2


PickerButton
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
                                   +----GtkButton
                                         +----HildonButton
                                               +----HildonPickerButton
                                                     +----HildonDateButton
                                                     +----HildonTimeButton
  

Implemented Interfaces
======================

HildonPickerButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Description
===========

:class:`HildonPickerButton` is a widget that lets the user select a particular item from a list. Visually, it's a button with title and value labels that brings up a :class:`PickerDialog` . The user can then use this dialog to choose an item, which will be displayed in the value label of the button.

You should create your own :class:`TouchSelector` at convenience and set it to the :class:`HildonPickerButton` with :meth:`hildon.PickerButton.set_selector` . For the common use cases of buttons to select date and time, you can use :class:`HildonDateButton` and :class:`HildonTimeButton` .


Details
=======

.. class:: HildonPickerButton

    .. method:: __init__ (size, arrangement)

        Creates a new :class:`HildonPickerButton` . See :meth:`hildon.Button` for details on the parameters.

        :param size: One of :class:`HildonSizeType` , specifying the size of the new button.

        :param arrangement: one of :class:`HildonButtonArrangement` , specifying the placement of the labels.

        :returns: a newly created :class:`HildonPickerButton`

        .. versionadded 2.2

    .. method:: set_selector (selector)

        Sets ``selector`` as the :class:`TouchSelector` to be shown in the :class:`PickerDialog` that ``button`` brings up.

        :param selector: a :class:`TouchSelector`

        .. versionadded 2.2

    .. method:: get_selector ()

        Retrieves the :class:`TouchSelector` associated to ``button``.

        :returns: a :class:`TouchSelector`

        .. versionadded 2.2

    .. method:: set_active (index)

        Sets the active item of the :class:`TouchSelector` associated to ``button`` to ``index``. If the selector has several columns, only the first one is used.

        :param index: the index of the item to select, or -1 to have no active item

        .. versionadded 2.2

    .. method:: get_active ()

        Returns the index of the currently active item, or -1 if there's no active item. If the selector has several columns, only the first one is used.

        :returns: an integer which is the index of the currently active item, or -1 if there's no active item.

        .. versionadded 2.2

    .. method:: get_done_button_text ()

        Gets the text used in the :class:`PickerDialog` that is launched by ``button``. If no custom text is set, then None is returned.

        :returns: the custom string to be used, or None if the default "done-button-text" is to be used.
        .. versionadded 2.2

    .. method:: set_done_button_text (done_button_text)

        Sets a custom string to be used in the "done" button in :class:`PickerDialog` . If unset, the default "done-button-text" property value will be used.

        :param done_button_text: a string

        .. versionadded 2.2

    .. method:: value_changed ()

        Emits a "value-changed" signal to the given :class:`HildonPickerButton`

        .. versionadded 2.2

Property Details
================

===================== ==================== ============ =================== =========================================================
Name                  type                 Access       Default             Meaning                              
===================== ==================== ============ =================== =========================================================
``done-button-text``  str                  Read / Write None                The text for the "done" button in the dialog launched.
``touch-selector``    hildon.TouchSelector Read / Write HildonTouchSelector widget to be launched on button clicked.
===================== ==================== ============ =================== =========================================================

Signal Details
==============

The ``value-changed`` signal

.. function:: user_function (widget, user_data)

    The ::value-changed signal is emitted each time the user chooses a different item from the :class:`TouchSelector` related, and the value label gets updated.

    :param widget: the widget that received the signal

    :param user_data: user data set when the signal handler was connected.

    .. versionadded 2.2

See Also
========

:class:`TouchSelector` :class:`PickerDialog`

DateButton
**********

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
  

Implemented Interfaces
======================

HildonDateButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Description
===========

:class:`HildonDateButton` is a widget that shows a text label and a date, and allows the user to select a different date. Visually, it's a button that, once clicked, presents a :class:`PickerDialog` containing a :class:`HildonDateSelector` . Once the user selects a different date from the selector, this will be shown in the button.


Details
=======

.. class:: HildonDateButton

    .. method:: __init__ (size, arrangement)

        Creates a new :class:`HildonDateButton` . See `hildon_button_new() <hildon-button-new>`_ for details on the parameters.

        :param size: One of :class:`HildonSizeType`

        :param arrangement: one of :class:`HildonButtonArrangement`

        :returns: a new :class:`HildonDateButton`

        .. versionadded 2.2

    .. method:: new_with_year_range (size, arrangement, min_year, max_year)

        Creates a new :class:`HildonDateButton` with a specific valid range of years. See :meth:`hildon.DateSelector.new_with_year_range` for details on the range.

        :param size: One of :class:`HildonSizeType`

        :param arrangement: one of :class:`HildonButtonArrangement`

        :param min_year: the minimum available year or -1 to ignore

        :param max_year: the maximum available year or -1 to ignore

        :returns: a new :class:`HildonDateButton`

        .. versionadded 2.2

    .. method:: get_date (year, month, day)

        Retrieves currently selected date from ``button``.

        :param year: return location for the selected year

        :param month: return location for the selected month

        :param day: return location for the selected day

        .. versionadded 2.2

    .. method:: hildon_date_button_set_date (year, month, day)

        Sets the date in ``button``. The date set will be displayed and will be the default selected option on the shown :class:`HildonDateSelector` .

        :param year: the year to set.

        :param month: the month number to set.

        :param day: the day of the month to set.

        .. versionadded 2.2

See Also
========

:class:`HildonPickerButton` :class:`HildonTimeButton`

TimeButton
**********

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
  

Implemented Interfaces
======================

HildonTimeButton implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .


Description
===========

:class:`HildonTimeButton` is a widget that shows a text label and a time, and allows the user to select a different time. Visually, it's a button that, once clicked, presents a :class:`PickerDialog` containing a :class:`HildonTimeSelector` . Once the user selects a different time from the selector, this will be shown in the button.


Details
=======

.. class:: HildonTimeButton

    .. method:: __init__ (size, param)

        Creates a new :class:`HildonTimeButton` . See :meth:`hildon.Button` for details on the parameters.

        :param size: One of :class:`HildonSizeType`

        :param arrangement: one of :class:`HildonButtonArrangement`

        :returns: a new :class:`HildonTimeButton`

        .. versionadded 2.2

    .. method:: new_step (size, arrangement, minutes_step)

        Creates a new :class:`HildonTimeButton` . See :meth:`hildon.Button` for details on the parameters.

        :param size: One of :class:`HildonSizeType`

        :param arrangement: one of :class:`HildonButtonArrangement`

        :param minutes_step: step between the minutes in the selector options

        :returns: a new :class:`HildonTimeButton`

        .. versionadded 2.2

    .. method:: get_time (hours, minutes)

        Retrieves the time from ``button``.

        :param hours: return location for the hours of the time selected

        :param minutes: return location for the minutes of the time selected

        .. versionadded 2.2

    .. method:: set_time (hours, minutes)

        Sets the time to be displayed in ``button``. This time will be selected by default on the :class:`HildonTimeSelector` .

        :param hours: the hours to be set

        :param minutes: the time to be set

        .. versionadded 2.2

See Also
========

:class:`HildonPickerButton` :class:`HildonDateButton`

Caption
*******

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
  

Implemented Interfaces
======================

Caption implements :class:`atk.ImplementorIface` and :class:`gtk.Buildable` .


Description
===========

:class:`Caption` is a single-child container widget that precedes the contained widget with a field label and an optional icon. It allows grouping of several controls together. When a captioned widget has focus, both widget and caption label are displayed with active focus.

Details
=======

.. data:: CaptionStatus

    Keys to set the :class:`Caption` to be optional or mandatory.

=========================== ========================================
Value                       Meaming  
=========================== ========================================
``CAPTION_OPTIONAL``        Optional.
``CAPTION_MANDATORY``       Mandatory.
=========================== ========================================

.. data:: CaptionIconPosition

    Keys to set the icon placement in :class:`Caption` .

================================== ========================================
Value                              Meaming  
================================== ========================================
``HILDON_CAPTION_POSITION_LEFT``   Show the icon on the left side.
``HILDON_CAPTION_POSITION_RIGHT``  Show the icon on the right side.
================================== ========================================


.. _HildonCaption-struct:

.. class:: HildonCaption

::

  typedef struct _HildonCaption HildonCaption;



    .. method:: __init__ (group, value, control, icon, flag)

        Creates a new instance of hildon_caption widget, with a specific control and image. Note: Clicking on a focused caption will trigger the activate signal. The default behaviour for the caption's activate signal is to call gtk.Widget.activate on it's control.

        :param group: a :class:`GtkSizeGroup` for controlling the size of related captions, Can be None

        :param value: the caption text to accompany the text entry. The widget makes a copy of this text.

        :param control: the control that is to be captioned

        :param icon: an icon to accompany the label - can be None in which case no icon is displayed

        :param flag: indicates whether this captioned control is mandatory or optional

        :returns: a :class:`GtkWidget` pointer of Caption

    .. method:: get_size_group ()

        Query given captioned control for the :class:`GtkSizeGroup` assigned to it.

        :returns: a :class:`GtkSizeGroup`

    .. method:: set_size_group (new_group)

        Sets a :class:`GtkSizeGroup` of a given captioned control.

        :param new_group: a :class:`GtkSizeGroup`

    .. method:: is_mandatory ()

        Query :class:`HildonCaption` whether this captioned control is a mandatory one.

        :returns: is this captioned control a mandatory one?

    .. method:: set_status (flag)

        Sets :class:`HildonCaption` status.

        :param flag: one of the values from :class:`HildonCaptionStatus`

    .. method:: get_status ()

        Gets :class:`HildonCaption` status.

        :returns: one of the values from :class:`HildonCaptionStatus`


    .. method:: set_icon_position (pos)

        Sets :class:`HildonCaption` icon position.

        :param pos: one of the values from :class:`HildonCaptionIconPosition`

    .. method:: get_icon_position ()

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
  the :class:`gtk.Widget` that is the owner of the banner


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
  the :class:`gtk.Widget` that is the owner of the banner


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
  the :class:`gtk.Widget` that wants to display banner


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
  the :class:`gtk.Widget` that wants to display banner


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
  the :class:`gtk.Widget` that wants to display banner


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

Note
**********

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
                                               +----Note

Implemented Interfaces
======================

Note implements :class:`AtkImplementorIface` and :class:`gtk.Buildable` .

Description
===========

:class:`Note` is a convenient way to prompt users for a small amount of input. A simple note contains an information text and, in case of confirmation notes, it shows buttons to confirm or cancel. It also can include a progress bar.

This widget provides convenient functions to create either information notes, confirmation notes or cancel notes, which are useful to show the progress of a requested task allowing the user to cancel it.

To create information notes you can use :func:`hildon_note_new_information` . :func:`hildon_note_new_confirmation` creates a note with a text and two buttons to confirm or cancel.

To create a note with a text, a progress bar and cancel button, :func:`hildon_note_new_cancel_with_progress_bar` can be used.

::

    bool show_confirmation_note (gtk.Window *parent) {
        int retcode; GtkWidget *note;
        note = hildon_note_new_confirmation (parent, "Confirmation message...");
        retcode = gtk_dialog_run (GTK_DIALOG (note));
        gtk_widget_destroy (note);
        if (retcode == GTK_RESPONSE_OK) {
            g_debug ("User pressed 'OK' button'");
            return TRUE;
        } else {
            g_debug ("User pressed 'Cancel' button");
            return FALSE;
        }
    }

Details
=======

.. function:: hildon_note_new_confirmation (parent, description)

    Create a new confirmation note. Confirmation note has a text (description) that you specify and two buttons.

    :param parent:the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly.
    :param description: the message to confirm
    :returns: a :class:`gtk.Widget` pointer of the note

.. function:: hildon_note_new_confirmation_with_icon_name (parent, description, icon_name)

    .. warning:: :func:`hildon_note_new_confirmation_with_icon_name` is deprecated and should not be used in newly-written code. Since Hildon 2.2, icons are not shown in confirmation notes. Icons set with this function will be ignored. Use :func:`hildon_note_new_confirmation` instead.

    Create a new confirmation note. Confirmation note has a text (description) that you specify and two buttons.

    :param parent: the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly.
    :param description: the message to confirm
    :param icon_name: icon to be displayed. If NULL, default icon is used.
    :returns: a :class:`gtk.Widget` pointer of the note

.. function:: hildon_note_new_cancel_with_progress_bar (parent, description, progressbar)

    Create a new cancel note with a progress bar. Cancel note has text(description) that you specify, a Cancel button and a progress bar.

    :param parent: the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly.
    :param description: the action to cancel
    :param progressbar: a pointer to :class:`gtk.ProgressBar` to be filled with the progressbar assigned to this note. Use this to set the fraction of progressbar done. This parameter can be None as well, in which case plain text cancel note appears.
    :returns: a :class:`gtk.Dialog` . Use this to get rid of this note when you no longer need it.

.. function:: hildon_note_new_information (parent, description)

    Create a new information note. Information note has a text (description) that you specify and an OK button.

    :param parent: the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly.
    :param description: the message to confirm
    :returns: a :class:`gtk.Widget` pointer of the note

.. function:: hildon_note_new_information_with_icon_name (parent, description, icon_name)

    .. warning:: :func:`hildon_note_new_information_with_icon_name` is deprecated and should not be used in newly-written code. Since Hildon 2.2, icons are not shown in confirmation notes. Icons set with this function will be ignored. Use :func:`hildon_note_new_information` instead.

    Create a new information note. Information note has text(description) that you specify, an OK button and an icon.

    :param parent: the parent window. The X window ID of the parent window has to be the same as the X window ID of the application. This is important so that the window manager could handle the windows correctly.
    :param description: the message to confirm
    :param icon_name: icon to be displayed. If NULL, default icon is used.
    :returns: a :class:`gtk.Widget` pointer of the note


.. class:: Note

    .. method:: set_button_text (text)

        Sets the button text to be used by the hildon_note widget.

        :param note: a :class:`Note`
        :param text: sets the button text and if there is two buttons in dialog, the button texts will be text, "Cancel".

.. method:: set_button_texts (text_ok, text_cancel)

    Sets the button texts to be used by this hildon_note widget.

    :param note: a :class:`Note`
    :param text_ok: the new text of the default OK button
    :param text_cancel: the new text of the default cancel button


.. data:: NoteType

    ==================================== =======
    Name                                 Meaning
    ==================================== =======
    HILDON_NOTE_TYPE_CONFIRMATION
    HILDON_NOTE_TYPE_CONFIRMATION_BUTTON
    HILDON_NOTE_TYPE_INFORMATION
    HILDON_NOTE_TYPE_INFORMATION_THEME
    HILDON_NOTE_TYPE_PROGRESSBAR
    ==================================== =======
  
Property Details
================

.. _Note--description:

The ``description`` property

::

    description              str                : Read / Write

Description for the note.



Default value: ""

.. _Note--icon:

The ``icon`` property

::

    icon                     str                : Read / Write

Icon for the note.



Default value: ""

.. _Note--note-type:

The ``note-type`` property

::

    note-type                NoteType        : Read / Write / Construct

The type of the note dialog.

Default value: HILDON_NOTE_TYPE_CONFIRMATION

.. _Note--progressbar:

The ``progressbar`` property

::

    progressbar              GtkProgressBar*       : Read / Write

Progressbar for the note (if any).



.. _Note--stock-icon:

The ``stock-icon`` property

::

    stock-icon               str                : Read / Write

Stock icon name for the note.



Default value: ""

TouchSelector
*************

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
  

Implemented Interfaces
======================

TouchSelector implements :class:`atk.ImplementorIface` and :class:`gtk.Buildable` .


Description
===========

:class:`TouchSelector` is a selector widget, that allows users to select items from one to many predefined lists. It is very similar to :class:`gtk.ComboBox` , but with several individual pannable columns.

Normally, you would use :class:`TouchSelector` together with a :class:`PickerDialog` activated from a button. For the most common cases, you should use :class:`PickerButton` .

The composition of each column in the selector is represented by a :class:`GtkTreeModel` . To add a new column to a :class:`TouchSelector` , use `hildon_touch_selector_append_column() <hildon-touch-selector-append-column>`_ . If you want to add a text-only column, without special attributes, use `hildon_touch_selector_append_text_column() <hildon-touch-selector-append-text-column>`_ .

It is highly recommended that you use only one column :class:`TouchSelector` s. If you only need a text only, one column selector, you can create it with `hildon_touch_selector_new_text() <hildon-touch-selector-new-text>`_ and populate with `hildon_touch_selector_append_text() <hildon-touch-selector-append-text>`_ , `hildon_touch_selector_prepend_text() <hildon-touch-selector-prepend-text>`_ , and `hildon_touch_selector_insert_text() <hildon-touch-selector-insert-text>`_ .

If you need a selector widget that also accepts user inputs, you can use :class:`TouchSelectorEntry` .

The current selection has a string representation. In the most common cases, each column model will contain a text column. You can configure which column in particular using the :class:`TouchSelectorColumn` property `"text-column" <TouchSelectorColumn--text-column>`_

You can get this string representation using :meth:`get_current_text()`. You can configure how the selection is printed with :meth:`set_print_func()`, that sets the current hildon touch selector print function. The widget has a default print function, that uses the "text-column" property on each :class:`SelectorColumn` to compose the final representation.

If you create the selector using :func:`hildon_touch_selector_new_text()` you don't need to take care of this property, as the model is created internally. If you create the selector using :meth:`__init__()` , you need to specify properly the property for your custom model in order to get a non-empty string representation, or define your custom print function.

Creating a TouchSelector
======================== 


::

    def selection_changed(selector, user_data):
        current_selection = selector.get_current_text()
        print "Current selection : %s" % current_selection

    def create_customized_selector():
        selector = hildon.TouchSelector()

        icon_list = gtk.stock_list_ids()

        store_icons = gtk.ListStore(gobject.TYPE_STRING);

        for item in icon_list:
            new_iter = store_icons.append()
            store_icons.set(new_iter, 0, item)

        renderer = gtk.CellRendererPixbuf() 
        renderer.set_fixed_size(-1, 100)


        # Add the column to the selector
        # FIXME: bug 4646
        #column = selector.append_column(store_icons, renderer, "stock-id", 0)

        selector.set_column_selection_mode(hildon.TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE)

        column.set_property("text-column", 0)

        return selector



Details
=======

  
.. data:: TouchSelectorSelectionMode

================================================== ========================================
Value                                              Meaning
================================================== ========================================
``HILDON_TOUCH_SELECTOR_SELECTION_MODE_SINGLE``    Users can select one item
``HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE``  Users can select one to many items 
================================================== ========================================


.. class:: HildonTouchSelector

    .. method:: __init__()
    
        Creates a new empty :class:`TouchSelector` .

        :returns:  a new :class:`TouchSelector` .



    .. method:: append_text(text)

        Appends a new entry in a :class:`TouchSelector` created with :func:`hildon_touch_selector_new_text()`.

        :param text: a non None text string.


    .. method:: prepend_text(text)

        Prepends a new entry in a :class:`TouchSelector` created with :func:`hildon_touch_selector_new_text()`.

        :param text: a non None text string.


    .. method:: insert_text(position, text)

        Inserts a new entry in a particular position of a :class:`TouchSelector` created with :func:`hildon_touch_selector_new_text()`.

        :param position: the position to insert ``text``.
        :param text: A non None text string.


    .. method:: append_text_column(model, center)

        Equivalent to :meth:`append_column()`, but using a default text cell renderer. This is the most common use case of the widget.

        :param model: a :class:`gtk.TreeModel` with data for the column
        :param center: whether to center the text on the column
        :returns: The new column added, None otherwise.


    .. method:: append_column(model, cell_renderer, ...)

        This functions adds a new column to the widget, whose data will be obtained from the model. Only widgets added this way should used on the selection logic, i.e., the print function, the "changed" signal, etc.
        You can optionally pass a :class:`gtk.CellRenderer` in ``cell_renderer``, together with a None -terminated list of pairs property/value, in the same way you would use `gtk.TreeViewColumn.set_attributes()`. This will pack ``cell_renderer`` at the start of the column, expanded by default. If you prefer not to add it this way, you can simply pass None to ``cell_renderer``\ and use the :class:`gtk.CellLayout` interface on the returned :class:`SelectorColumn` to set your renderers.
        There is a prerequisite to be considered on models used: text data must be in the first column.
        This method basically adds a :class:`gtk.TreeView` to the widget, using the model and the data received.

        :param model: the :class:`gtk.TreeModel` with the data of the column
        :param cell_renderer: The :class:`gtk.CellRenderer` where to draw each row contents.
        :returns:  the new column added added, None otherwise.


    .. method:: set_column_attributes(num_column, cell_renderer, ...)

        .. warning:: :meth:``set_column_attributes`` is deprecated and should not be used in newly-written code. :class:`SelectorColumn` implements :class:`gtk.CellLayout` , use this interface instead. See :meth:`get_column()`.

        Sets the attributes for the given column. The attributes must be given in attribute/column pairs, just like in :meth:`set_attributes()`. All existing attributes are removed and replaced with the new ones.

        :param num_column: the number of the column whose attributes we're setting
        :param cell_renderer: the :class:`gtk.CellRendere` we're setting the attributes of


    .. method:: remove_column(column)

        Removes a column from ``selector``.

        :param column: the position of the column to be removed
        :returns:   True if the column was removed, False otherwise



    .. method:: get_num_columns()
    
        Gets the number of columns in the :class:`TouchSelector` .

        :returns: the number of columns in ``selector``.


    .. method:: set_column_selection_mode(mode)

        Sets the selection mode for ``selector``. See :class:`TouchSelectorSelectionMode` .

        :param mode: the :class:`TouchSelectorMode` for ``selector``


    .. method:: get_column_selection_mode ()

        Gets the selection mode of ``selector``.

        :returns: one of :class:`TouchSelectorSelectionMode`


    .. method:: get_column(column)

        Use this method to retrieve a :class:`TouchSelectorColumn` . Then, you can use the :class:`gtk.CellLayout` interface to set up the layout of the column.

        :param column: a column number
        :returns:  the ``column``-th :class:`TouchSelectorColumn` in ``selector``

    .. method:: set_active(column, index)

        Sets the active item of the :class:`TouchSelector` to ``index``. The column number is taken from ``column``.
        ``selector`` must be in TOUCH_SELECTOR_SELECTION_MODE_SINGLE

        :param column: column number
        :param index: the index of the item to select, or -1 to have no active item


    .. method:: get_active (column)
    
        Returns the index of the currently active item in column number ``column``, or -1 if there's no active item.
        ``selector`` must be in TOUCH_SELECTOR_SELECTION_MODE_SINGLE

        :param column: column number
        :returns: an integer which is the index of the currently active item, or -1 if there's no active item.

    .. method:: selector_get_selected(column)

        Sets ``iter`` to the currently selected node on the nth-column, if selection is set to TOUCH_SELECTOR_SINGLE or TOUCH_SELECTOR_MULTIPLE with a column different that the first one. ``iter`` may be None if you just want to test if selection has any selected items.
        This function will not work if selection is in TOUCH_SELECTOR_MULTIPLE mode and the column is the first one.

        See :meth:`get_selected()` for more information.

        :param column: the column number we want to get the element
        :returns: class:`GtkTreeIter` currently selected or None otherwise

    .. method:: center_on_selected()

        Ensures all the columns in a :class:`TouchSelector` show a selected item. If one of the columns is in ```TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE`` mode, that column will be scrolled to ensure the selected item that is closest to the currently visible area is shown.


    .. method:: select_iter(column, iter, scroll_to)

        Sets the currently selected item in the column ``column`` to the one pointed by ``iter``, optionally smoothly scrolling to it.

        :param column: the column to selects
        :param iter: the :class:`gtk.TreeIter` to be selected
        :param scroll_to: whether to smoothly scroll to the item


    .. method:: unselect_iter(column, iter)

        Unselect the item pointed by ``iter`` in the column ``column``

        :param column: the column to unselects from
        :param iter: the :class:`gtk.TreeIter` to be unselected


    .. method:: unselect_all(column)

        Unselects all the selected items in the column ``column``.

        :param column: the position of the column to get the selected rows from


    .. method:: get_selected_rows(column)

        Creates a list of :class:`gtk.TreePath` s of all selected rows in a column. Additionally, if you to plan to modify the model after calling this function, you may want to convert the returned list into a list of GtkTreeRowReferences. To do this, you can use `gtk.TreeRowReference`.

        See :meth:`get_selected_rows()` for more information.

        :param column: the position of the column to get the selected rows from
        :returns:  A new list containing a :class:`gtk.TreePath` for each selected row in the column ``column``.


    .. method:: set_model(column,model)

        Sets the :class:`gtk.TreeModel` for a particular column in ``model``.

        :param column: the position of the column to set the model to
        :param model: a :class:`GtkTreeModel`


    .. method:: get_model(column)

        Gets the model of a column of ``selector``.

        :param column: the position of the column in ``selector``
        :returns:  the :class:`gtk.TreeModel` for the column ``column`` of ``selector``.

    .. method:: get_current_text()

        Returns a string representing the currently selected items for each column of ``selector``. See :meth:`set_print_func`.
    
        :returns:  a newly allocated string.


    .. method:: set_print_func(func)

        Sets the function to be used by :meth:`get_current_text` to produce a text representation of the currently selected items in ``selector``. The default function will return a concatenation of comma separated items selected in each column in ``selector``. Use this to override this method if you need a particular representation for your application.

        :param func: a callable object


    .. method:: get_print_func()

        Gets the PrintFunc currently used. See :meth:`set_print_func`.

        :returns: a object or None if the default one is currently used.



    .. method:: has_multiple_selection()

        Determines whether ``selector`` is complex enough to actually require an extra selection step than only picking an item. This is normally True if ``selector`` has multiple columns, multiple selection, or when it is a more complex widget, like :class:`TouchSelectorEntry` .
        This information is useful for widgets containing a :class:`TouchSelector` , like :class:`PickerDialog` , that could need a "Done" button, in case that its internal :class:`TouchSelector` has multiple columns, for instance.

        :returns: True if ``selector`` requires multiple selection steps.


Related Functions
=================

    :function: hildon_touch_selector_new_text ()

        Creates a :class:`TouchSelector` with a single text column that can be populated conveniently through :meth:`append_text`, :meth:`prepend_text`, :meth:`insert_text`.

        :returns:  A new :class:`TouchSelector`


Property Details
================

============================ ============ ======================== ============== =====================================================================================================================================================================================
Name                         type         Access                   Default        Meaning
============================ ============ ======================== ============== =====================================================================================================================================================================================
``has-multiple-selection``   bool         Read                     False          Whether the widget has multiple selection (like multiple columns, multiselection mode, or multiple internal widgets) and therefore it may need a confirmation button, for instance.
``initial-scroll``           bool         Read / Write / Construct True           Whether to scroll to thecurrent selection whenthe selector is firstshown.
============================ ============ ======================== ============== =====================================================================================================================================================================================



Signal Details
==============


The ``changed`` signal

.. function:: user_function (widget, column, user_data)
    
    The "changed" signal is emitted when the active item on any column is changed. This can be due to the user selecting a different item from the list, or due to a call to :meth:`select_iter()` on one of the columns.

    :param widget: the object which received the signal
    :param column: the number of the column that has changed
    :param user_data: user data set when the signal handler was connected.


The ``columns-changed`` signal

.. function:: user_function(selector, user_data)

    The "columns-changed" signal is emitted when the number of columns in the :class:`TouchSelector` change.

    :param selector: the object which received the signal
    :param user_data: user data set when the signal handler was connected.


TouchSelectorColumn
*******************

Object Hierarchy
================

::
  
    GObject
     +----TouchSelectorColumn
  
Implemented Interfaces
======================

TouchSelectorColumn implements :class:`gtk.CellLayout` .

Description
===========

:class:`TouchSelectorColumn` object represents a visible column in :class:`TouchSelector` . It allows to manage the cell renderers related to each column.

Details
=======

.. class:: TouchSelectorColumn

Property Details
================

============================ ============ ============ ============== ==========================================================
Name                         type         Access       Default        Meaning
============================ ============ ============ ============== ==========================================================
``text-column``              int          Read / Write -1             A column in the data source model to get the strings from.
============================ ============ ============ ============== ==========================================================


SelectorEntry
*************

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
  


Implemented Interfaces
======================

SelectorEntry implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Description
===========

:class:`SelectorEntry` is a selector widget with a text entry, similar in behaviour to :class:`gtk.ComboBoxEntry` , that allows user to select an item from a predefined list or to enter a different one in a :class:`HildonEntry` . Items can also be searched and selected by typing in the entry. For more specific use cases, the :class:`HildonEntry` can be accessed directly with `hildon_touch_selector_get_entry() <hildon-touch-selector-get-entry>`_ .

The main difference between the :class:`gtk.TreeModel` used by :class:`HildonTouchSelector` and :class:`TouchSelectorEntry` , is that the latter must always include a text column. You should set it with :meth:`touch_selector_entry_set_text_column`.

Normally, you would use :class:`TouchSelectorEntry` together with a :class:`PickerDialog` activated from a button. For the most common cases, you should use :class:`PickerButton` .

If you only need a text only, one column selector, you can create it with :func:`hildon_touch_selector_entry_new_text` and populate it with :meth:`append_text`, :meth:`prepend_text()`, and :meth:`insert_text`.



Details
=======

.. class:: TouchSelectorEntry

    .. method:: __init__ ()

        Creates a :class:`TouchSelectorEntry`

        :returns:  A new :class:`TouchSelectorEntry`


    .. method:: set_text_column(text_column)

        Sets the model column which touch selector box should use to get strings from to be ``text_column``.

        :param text_column: A column in model to get the strings from


    .. method:: get_text_column()

        Gets the text column that ``selector`` is using as a text column.

        :returns:  the number of the column used as a text column.


    .. method:: set_input_mode(input_mode)

        Sets the input mode to be used in the :class:`gtk.Entry` in ``selector``. See :meth:`set_input_mode` for details.
        It must be noted that not all input modes are available for the entry in ``selector``. In particular, ``GTK_INPUT_MODE_MULTILINE``, ``GTK_INPUT_MODE_INVISIBLE``, ``GTK_INPUT_MODE_DICTIONARY`` are disabled, since these are irrelevant for :class:`TouchSelectorEntry` .

        :param input_mode: :class:`GtkInputMode` mask


    .. method:: get_input_mode()
        Gets the input mode used in the :class:`gtk.Entry` in ``selector``. See :meth:`get_input_mode` for details.


        :returns: a mask of :class:`GtkInputMode`



    .. method:: get_entry()

        Provides access to the :class:`Entry` in ``selector``. Use to programmatically change the contents in entry or modify its behavior.

        :returns:  a :class:`Entry` .


Related Functions
=================

.. function:: hildon_touch_selector_entry_new_text()

    Creates a :class:`TouchSelectorEntry` with a single text column that can be populated conveniently through :meth:`append_text`, :meth:`prepend_text()`, :meth:`insert_text()`.

    :returns: A new :class:`TouchSelectorEntry`


Property Details
================

================ =========== ============= =============== ===========================================
Name             type        Access        Default         Meaning
================ =========== ============= =============== ===========================================
``text-column``  int         Read / Write  -1                  
================ =========== ============= =============== ===========================================

See Also
========

:class:`TouchSelector` :class:`PickerButton`


DateSelector
************

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
  


Implemented Interfaces
======================

DateSelector implements :class:`atk.ImplementorIface` and :class:`gtk.Buildable` .

Description
===========

:class:`DateSelector` is a date widget with multiple columns. Users can choose a date by selecting values in the day, month and year columns.

The currently selected month and year can be altered with :meth:`select_month()`. The day can be selected from the active month using :meth:`select_day`.


Details
=======

.. class:: HildonDateSelector

    .. method:: __init__()

        Creates a new :class:`DateSelector`
    
        :returns:  a new :class:`DateSelector`


    .. method:: select_month(month, year)

        Modify the current month and year on the current active date
        Ytility function to keep this API similar to the previously existing :class:`Calendar` widget.

        :param month: the current month (0-11)
        :param year: the current year
        :returns:  True on success, False otherwise


    .. method:: select_day(day)

        Modify the current day on the current active date
        Utility function to keep this API similar to the previously existing :class:`Calendar` widget.

        :param day: the current day (1-31, 1-30, 1-29, 1-28) depends on the month


    .. method:: select_current_date(year, month, day)

        Sets the current active date on the :class:`DateSelector` widget
        
        :param year: the current year
        :param month: the current month (0-11)
        :param day: the current day (1-31, 1-30, 1-29, 1-28) depends on the month
        :returns:  True on success, False otherwise


    .. method:: get_date()

        Gets the current active date on the :class:`DateSelector` widget

        :returns: a tuple with (year, month, day)


Related Functions
=================

    .. function:: hildon_date_selector_new_with_year_range (min_year, max_year)

        Creates a new :class:`DateSelector` with a specific year range. If ``min_year`` or ``max_year`` are set to -1, then the default upper or lower bound will be used, respectively.

        :param min_year: the minimum available year or -1 to ignore
        :param max_year: the maximum available year or -1 to ignore
        :returns:  a new :class:`DateSelector`



Property Details
================


=============================== =========== =============================== =============== ===========================================
Name                            type         Access                         Default         Meaning
=============================== =========== =============================== =============== ===========================================
``max-year``                    int         Read / Write / Construct Only   2037            The maximum available year in the selector.    
``min-year``                    int         Read / Write / Construct Only   1970            The minimum available year in the selector.
=============================== =========== =============================== =============== ===========================================


TimeSelector
************


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
  


Implemented Interfaces
======================

TimeSelector implements :class:`atk.ImplementorIface` and :class:`gtk.Buildable` .


Description
===========

:class:`TimeSelector` allows users to choose a time by selecting hour and minute. It also allows choosing between AM or PM format.

The currently selected time can be altered with :meth:`set_time`, and retrieved using :meth:`get_time`.

Use this widget instead of deprecated HildonTimeEditor widget.



Details
=======

.. class:: HildonTimeSelector

    .. method:: __init__ ()

        Creates a new :class:`TimeSelector`
        
        :returns:  a new :class:`TimeSelector`


    .. method:: new_step(minutes_step)

        Creates a new :class:`TimeSelector` ``minutes_step``: step between the minutes we are going to show in the selector

        :param minutes_step:
  
        :returns:  a new :class:`TimeSelector`


    .. method:: set_time(hours,minutes)

        Sets the current active hour on the :class:`TimeSelector` widget
        The format of the hours accepted is always 24h format, with a range (0-23):(0-59).

        :param hours: the current hour (0-23)
        :param minutes: the current minute (0-59)
        :returns: True on success, False otherwise


    .. method:: get_time ()
        
        Gets the current active hour on the :class:`TimeSelector` widget.
        This method returns the date always in 24h format, with a range (0-23):(0-59)

        :returns: a tuple with (hours, minutes) 


Property Details
================

============================ ============ ============================= ============== ===============================================================
Name                         type         Access                        Default        Meaning
============================ ============ ============================= ============== ===============================================================
``minutes-step``             int          Read / Write / Construct Only 1              Step between the minutes in the list of options of the widget . 
============================ ============ ============================= ============== ===============================================================


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

        Smoothly scrolls ``area`` to ensure that (``x``, ``y``) is a visible point on the widget. To move in only one coordinate, you must set the other one to -1. Notice that, in :const:`PANNABLE_AREA_MODE_PUSH`, this function works just like :meth:`jump_to`.

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

        :param child: A :class:`gtk.Widget` , descendant of ``area``.

    .. method:: jump_to_child(child)

        Jumps to make sure ``child`` is visible inside ``area``. ``child`` must be a descendant of ``area``. If you want to move inside a scrollable widget, like, :class:`GtkTreeview` , see :meth:`scroll_to`.
        
        There is a precondition to this function: the widget must be already realized. You can control if the widget is ready with the GTK_WIDGET_REALIZED macro. If you want to call this function during the initialization process of the widget do it inside a callback to the ::realize signal, using `g_signal_connect_after() <g-signal-connect-after>`_ function.

        :param child: A :class:`gtk.Widget` , descendant of ``area``.


    .. method:: get_child_widget_at(x, y)

        Get the widget at the point (x, y) inside the pannable area. In case no widget found it returns None.

        :param x: horizontal coordinate of the point
        :param y: vertical coordinate of the point
        :returns: the :class:`gtk.Widget` if we find a widget, NULL in any other case


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
|                                  |               |                          |                          | to deactivate overshooting.                                                                                                                |
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

Besides all the features inherited from :class:`gtk.Entry` , a :class:`Entry` can also have a placeholder text. This text will be shown if the entry is empty and doesn't have the input focus, but it's otherwise ignored. Thus, calls to :meth:`Entry.get_text` will never return the placeholder text, not even when it's being displayed.

Creating a Entry with a placeholder 
===================================

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
        Note that you must never use :meth:`Entry.set_text` to set the text of a :class:`Entry` .

        :param text: the new text


    .. method:: get_text()

        Gets the current text in ``entry``.
        Note that you must never use :meth:`get_text` to get the text from a :class:`Entry` .
        Also note that placeholder text (set using :meth:`set_placeholder` is never returned. Only text set by :meth:`set_text` or typed by the user is considered.

        :returns:  the text in ``entry``. This text must not be modified or freed.

    .. method:: set_placeholder(text)

        Sets the placeholder text in ``entry`` to ``text``.
    
        :param text: the new text


TextView
********

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
  


Implemented Interfaces
======================

TextView implements :class:`AtkImplementorIface` and :class:`GtkBuildable` .

Description
===========

The :class:`TextView` is a GTK widget which represents a text view. It is derived from the :class:`gtk.TextView` widget and provides additional commodities specific to the Hildon framework.

Besides all the features inherited from :class:`gtk.TextView` , a :class:`TextView` can also have a placeholder text. This text will be shown if the text view is empty and doesn't have the input focus, but it's otherwise ignored. Thus, calls to `hildon_text_view_get_buffer() <hildon-text-view-get-buffer>`_ will never return the placeholder text, not even when it's being displayed.

Although :class:`TextView` is derived from :class:`gtk.TextView` , :meth:`get_buffer()` and :meth:`set_buffer()` must never be used to get/set the buffer in this widget. :meth:`get_buffer()` and :meth:`set_buffer` must be used instead.

Creating a TextView with a placeholder
======================================

::

    def create_text_view ():
        text_view = hildon.TextView()
        text_view.set_placeholder("Type some text here")
        return text_view


Details
=======

.. class:: TextView

    .. method:: __init__()

        Creates a new text view.

        :returns:  a new :class:`TextView`


    .. method:: set_buffer(buffer)

        Sets ``buffer`` as the buffer being displayed by ``text_view``. The previous buffer displayed by the text view is unreferenced, and a reference is added to ``buffer``. If you owned a reference to ``buffer``\ before passing it to this function, you must remove that reference yourself
        Note that you must never use :meth:`set_buffer` to set the buffer of a :class:`TextView` .

        :param buffer: a :class:`gtk.TextBuffer`


    .. method:: get_buffer()

        Returns the text buffer in ``text_view``. The reference count is not incremented; the caller of this function won't own a new reference.
        Note that you must never use :meth:`get_buffer` to get the buffer from a :class:`TextView` .
        Also note that placeholder text (set using :meth:`set_placeholder` is never contained in this buffer.

        :returns:  a :class:`gtk.TextBuffer`

    .. method:: set_placeholder(text)

        Sets the placeholder text in ``text_view`` to ``text``.
        
        :param text: the new text


AppMenu
*******

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
  

Implemented Interfaces
======================

AppMenu implements :class:`atk.ImplementorIface` and :class:`gtk.Buildable` .


Description
===========

The :class:`AppMenu` is a GTK widget which represents an application menu in the Hildon framework.

This menu opens from the top of the screen and contains a number of entries (:class:`gtk.Button` ) organized in one or two columns, depending on the size of the screen (the number of columns changes automatically if the screen is resized). Entries are added left to right and top to bottom.

Besides that, the :class:`AppMenu` can contain a group of filter buttons (:class:`gtk.ToggleButton` or :class:`gtk.RadioButton` ).

To use a :class:`AppMenu` , add it to a :class:`Window` using :meth:`Window.set_app_menu` . The menu will appear when the user presses the window title bar. Alternatively, you can show it by hand using :meth:`popup`.

The menu will be automatically hidden when one of its buttons is clicked. Use `g_signal_connect_after()` when connecting callbacks to buttons to make sure that they're called after the menu disappears. Alternatively, you can add the button to the menu before connecting any callback.

Although implemented with a :class:`gtk.Window` , :class:`AppMenu` behaves like a normal ref-counted widget, so :meth:`ref()`, :meth:`unref` , :meth:`ref_sink` and friends will behave just like with any other non-toplevel widget.

Creating a AppMenu
==================

::

    win = hildon.StackableWindow()
    menu = hildon.AppMenu() 

    # Create a button and add it to the menu
    button = gtk.Button("Menu command one")
    button.connect("clicked", button_one_clicked, userdata)
    menu.append(button)

    # Another button
    button = gtk.Button("Menu command two")
    button.connect("clicked", button_two_clicked, userdata)
    menu.append(button)

    # Create a filter and add it to the menu
    filter = gtk.RadioButton(None, "Filter one")
    filter.set_mode(False)
    filter.connect("clicked", filter_one_clicked, userdata)
    menu.add_filter(filter)

    # Add a new filter
    filter = gtk.RadioButton(None, "Filter two")
    filter.set_mode(False)
    filter.connect("clicked", filter_two_clicked, userdata)
    menu.add_filter(filter)

    # Show all menu items
    menu.show_all()

    # Add the menu to the window
    window.set_app_menu(menu)


Details
=======

.. class:: AppMenu

    .. method:: __init_ ()

        Creates a new :class:`AppMenu` .

        :returns:  A :class:`AppMenu` .


    .. method:: append(item)

        Adds ``item`` to the end of the menu's item list.

        :param item: A :class:`gtk.Button` to add to the :class:`AppMenu`


    .. method:: prepend(item)

        Adds ``item`` to the beginning of the menu's item list.

        :param item: A :class:`gtk.Button` to add to the :class:`AppMenu`


    .. method:: menu_insert(item, positon)

        Adds ``item`` to ``menu`` at the position indicated by ``position``.

        :param item: A :class:`gtk.Button` to add to the :class:`AppMenu`
        :param position: The position in the item list where ``item`` is added (from 0 to n-1).


    .. method:: reorder_child(item, position)

        Moves a :class:`GtkButton` to a new position within :class:`AppMenu` .

        :param item: A :class:`gtk.Button` to move
        :param position: The new position to place ``item`` (from 0 to n-1).


    .. method:: add_filter(filter)

        Adds the ``filter`` to ``menu``.

        :param filter: A :class:`gtk.Button` to add to the :class:`AppMenu` .


    .. method:: get_items()

        Returns a list of all items (regular items, not filters) contained in ``menu``.

        :returns:  a newly-allocated list containing the items in ``menu``


    .. method:: get_filters()

        Returns a list of all filters contained in ``menu``.

        :returns: a newly-allocated list containing the filters in ``menu``


    .. method:: menu_popup(parent_window)

        Displays a menu on top of a window and makes it available for selection.

        :param parent_window: a :class:`gtk.Window`



Style Property Details
======================


=============================== ======= =================== =========== ================================================================================================
Name                            type    Access              Default     Meaning                                         
=============================== ======= =================== =========== ================================================================================================
``external-border``             int     Read                50          Border between the right and left edges of the menu and the screen edges (in horizontal mode).
``filter-vertical-spacing``     int     Read                8           Vertical spacing between filters and menu items.
``horizontal-spacing``          int     Read                16          Horizontal spacing between each menu item. Does not apply to filter buttons.
``inner-border``                int     Read                16          Border between menu edges and buttons.
``vertical-spacing``            int     Read                16          Vertical spacing between each menu item. Does not apply to filter buttons.
=============================== ======= =================== =========== ================================================================================================


FindToolbar
*****************

Object Hierarchy
================

::
  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----GtkToolbar
                                   +----FindToolbar
  
Implemented Interfaces
======================

FindToolbar implements :class:`AtkImplementorIface` and :class:`gtk.Buildable` .

Description
===========

FindToolbar is a toolbar that contains a search entry and a dropdown list with previously searched strings. The list is represented using a :class:`gtk.ListStore` and can be accesed using a property 'list'. Entries are added automatically to the list when the search button is pressed.

Details
=======

.. class:: FindToolbar

    .. method:: __init__ (label, [model, [column]])

        Creates a new FindToolbar with a model.

        :param label: label for the find_toolbar, NULL to set the label to default "Find"
        :param model: a ``gtk.ListStore``
        :param column: indicating which column the search histry list will retreive string from
        :returns: a new :class:`FindToolbar`

    .. method:: highlight_entry (get_focus)

        Highlights the current entry in the find toolbar.

        :param ftb: find Toolbar whose entry is to be highlighted
        :param get_focus: if user passes TRUE to this value, then the text in the entry will not only get highlighted, but also get focused.

    .. method:: set_active (index)

        Sets the active item on the toolbar's combo-box. Simply calls gtk_combo_box_set_active on the FindToolbar's combo.

        :param toolbar: A find toolbar to operate on
        :param index: An index in the model passed during construction, or -1 to have no active item

    .. method:: get_active ()

        Gets the index of the currently active item, or -1 if there's no active item. Simply calls gtk_combo_box_get_active on the FindToolbar's combo.

        :returns: An integer which is the index of the currently active item, or -1 if there's no active item.

    .. method:: set_active_iter (iter)

        Sets the current active item to be the one referenced by iter. Simply calls gtk_combo_box_set_active_iter on the FindToolbar's combo.

        :param iter: An iter to make active

    .. method:: get_active_iter (iter)

        Sets iter to point to the current active item, if it exists. Simply calls :meth:`gtk.comboBox.get_active_iter` on the FindToolbar's combo.

        :param iter: The uninitialized GtkTreeIter
        :returns: True, if iter was set

    .. method:: get_last_index ()

        Returns the index of the last (most recently added) item in the toolbar. Can be used to set this item active in the history-append signal.

        :returns: Index of the last entry

Property Details
================

+---------------------------+---------------------------+--------------------------+------------------------------+------------------------------------------------------------------------------+
| Name                      | type                      | Access                   | Default                      | Meaning                                                                      |
+===========================+===========================+==========================+==============================+==============================================================================+
| ``column``                | int                       | Read / Write             | 0                            | The column number in gtk.ListStore where strings of search history are kept. |
+---------------------------+---------------------------+--------------------------+------------------------------+------------------------------------------------------------------------------+
| ``history-limit``         | int                       | Read / Write / Construct | 5                            | Maximum number of history items in the combobox.                             |
+---------------------------+---------------------------+--------------------------+------------------------------+------------------------------------------------------------------------------+
| ``labe``                  | str                       | Read / Write / Construct | "ecdg_ti_find_toolbar_label" | The label to display before the search box.                                  |
+---------------------------+---------------------------+--------------------------+------------------------------+------------------------------------------------------------------------------+
| ``list``                  | :class:`gtk.ListStore`    | Read / Write             |                              | A :class:`gtk.ListStore` where the search history is kept.                   |
+---------------------------+---------------------------+--------------------------+------------------------------+------------------------------------------------------------------------------+
| ``max-characters``        | int                       | Read / Write / Construct | 0                            | Maximum number of characters in search string.                               |
+---------------------------+---------------------------+--------------------------+------------------------------+------------------------------------------------------------------------------+
| ``prefix``                | str                       | Read / Write / Construct | None                         | Search string.                                                               |
+---------------------------+---------------------------+--------------------------+------------------------------+------------------------------------------------------------------------------+

Signal Details
==============

The ``close`` signal

.. function:: user_function(toolbar, user_data)

    Gets emitted when the close button is pressed.

    :param toolbar: the toolbar which received the signal
    :param user_data: user data set when the signal handler was connected.

The ``history-append`` signal

.. function:: user_function(toolbar, user_data)

    Gets emitted when the current search prefix should be added to history.

    :param toolbar: the toolbar which received the signal
    :param user_data: user data set when the signal handler was connected.

The ``invalid-input`` signal

.. function user_function(toolbar, user_data)

    Gets emitted when the maximum search prefix length is reached and user tries to type more.

    :param toolbar: the toolbar which received the signal
    :param user_data: user data set when the signal handler was connected.

The ``search`` signal

.. function:: user_function(toolbar, user_data)

    Gets emitted when the find button is pressed.

    :param toolbar: the toolbar which received the signal
    :param user_data: user data set when the signal handler was connected.

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

EditToolbar implements :class:`atk.ImplementorIface` and :class:`gtk.Buildable` .

Description
===========

The :class:`EditToolbar` is a toolbar which contains a label and two buttons, one of them being an arrow pointing backwards.

The label is a description of the action that the user is supposed to do. The button is to be pressed when the user completes the action. The arrow is used to go back to the previous view discarding any changes.

Note that those widgets don't do anything themselves by default. To actually peform actions the developer must provide callbacks for them.

To add a :class:`EditToolbar` to a window use :meth:`Window.set_edit_toolbar` .

::

    window = hildon.StackableWindow()
    toolbar = hildon.EditToolbar("Choose items to delete", "Delete")
    # Create more widgets here ...

    # Add toolbar to window
    window.set_edit_toolbar(toolbar)

    # Add other widgets ...

    toolbar.connect("button-clicked", delete_button_clicked, someparameter)
    toolbar.connect_swapped("arrow-clicked", gtk.widget_destroy, window)

    gtk.widget_show_all(window)
    gtk.window_fullscreen(window)

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
| ``arrow-height``          | int    | Read                     | 56           | Height of the arrow button.          |
+---------------------------+--------+--------------------------+--------------+--------------------------------------+
| ``arrow-width``           | int    | Read                     | 112          | Width of the arrow button.           |
+---------------------------+--------+--------------------------+--------------+--------------------------------------+

Signal Details
==============

The ``arrow-clicked`` signal

.. function:: user_function(widget, user_data)

    Emitted when the toolbar back button (arrow) has been activated (pressed and released).

    :param widget: the object which received the signal.
    :param user_data: user data set when the signal handler was connected.

    .. versionadded 2.2

The ``button-clicked`` signal

.. function:: user_function(widget, user_data)

    Emitted when the toolbar button has been activated (pressed and released).

    :param widget: the object which received the signal.
    :param user_data: user data set when the signal handler was connected.

    .. versionadded 2.2

WizardDialog
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
                                               +----WizardDialog

Implemented Interfaces
======================

WizardDialog implements :class:`atk.ImplementorIface` and :class:`gtk.Buildable`.

Description
===========

:class:`WizardDialog` is a widget to create a guided installation process. The dialog has three standard buttons, previous, next, finish, and contains several pages.

Response buttons are dimmed/undimmed automatically. The notebook widget provided by users contains the actual wizard pages.

Usage of the API is very simple, it has only one function to create it and the rest of it is handled by developers notebook. Also, the response is returned, either cancel or finish. Next and previous buttons are handled by the wizard dialog it self, by switching the page either forward or backward in the notebook.

It is possible to determinate whether users can go to the next page by setting a :class:`WizardDialogPageFunc` function with :meth:`WizardDialog.set_forward_page_func`.

Details
=======

.. class:: WizardDialog

    .. method:: __init__ (parent, wizard_name, notebook)

        Creates a new :class:`WizardDialog` .

        :param parent: a :class:`gtk.Window`
        :param wizard_name: the name of dialog
        :param notebook: the notebook to be shown on the dialog

        :returns: A :class:`WizardDialog`

    .. method:: set_forward_page_func (page_func, data)

        Sets the page forwarding function to be ``page_func``. This function will be used to determine whether it is possible to go to the next page when the user presses the forward button. Setting ``page_func`` to None wil make the wizard to simply go always to the next page.

        The signature of ``page_func`` is:

        ``def page_func(current_page, user_data):``

        where ``current_page`` is the index of the current page and ``user_data`` is data.

        :param page_func: the function, or ``None`` to use the default function.
        :param data: user data for ``page_func``\

.. data:: WizardDialogResponse

    Used to control the size request policy of the widget

    ========================== ==================================
    Value                      Meaning
    ========================== ==================================
    ``WIZARD_DIALOG_CANCEL``   Returned by the 'Cancel' button.
    ``WIZARD_DIALOG_PREVIOUS`` Returned by the 'Previous' button.
    ``WIZARD_DIALOG_NEXT``     Returned by the 'Next' button.
    ``WIZARD_DIALOG_FINISH``   Returned by the 'Finish' button.
    ========================== ==================================

    .. warning:: WIZARD_DIALOG_CANCEL is deprecated and should not be used in newly-written code.

Property Details
================

============================ ============ ============ ============== ========================================
Name                         type         Access       Default        Meaning
============================ ============ ============ ============== ========================================
``autotitle``                bool         Read / Write True           If the wizard should automatically try
                                                                      to change the window title when changing
                                                                      steps. Set to FALSE if you'd like to
                                                                      override the default behaviour.
``wizard-name``              str          Read / Write None           The name of the wizard.
``wizard-notebook``          gtk.Notebook Read / Write                The notebook object, which is used by
                                                                      the WizardDialog.
============================ ============ ============ ============== ========================================


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

:class:`PickerDialog` is a dialog that is used to show a :class:`TouchSelector` widget and a 'Done' button to allow users to finish their selections.

The :class:`PickerDialog` will show a 'Done' button in case the :class:`TouchSelector` allows multiple selection. The label of the button can be set using :meth:`PickerDialog.set_done_label` and retrieved using :meth:`PickerDialog.get_done_label`

Note that in most cases developers don't need to deal directly with this widget. :class:`PickerButton` is designed to pop up a :class:`PickerDialog` and manage the interaction with it.

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

        Sets ``selector`` as the :class:`TouchSelector` to be shown in ``dialog``

        :param selector: a :class:`TouchSelector`
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

        Retrieves the :class:`TouchSelector` associated to ``dialog``.

        :returns: a :class:`TouchSelector`

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

        Parenting an animation actor will affect its visibility as set by the :meth:`gtk.Widget.show_all` , :meth:`GtkWidget.hide` and :meth:`AnimationActor.set_show` . The animation actor will only be visible when the top-level window it is parented is visible.

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

        Parenting an remote texture will affect its visibility as set by the :meth:`gtk.Widget.show_all` , :meth:`GtkWidget.hide` and :meth:`RemoteTexture.set_show` . The remote texture will only be visible when the top-level window it is parented is visible.

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


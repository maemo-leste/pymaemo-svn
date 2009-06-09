Hildon Core Reference
#####################

Main
****

.. module:: hildon

Before using Hildon, you need to initialize it; initialization connects to the window system display, and parses some standard command line arguments. See also :func:`gtk_init` to know more details on this topic.

Hildon should be initialized by using `hildon_gtk_init() <hildon-gtk-init>`_ . Notice this function also initialize gtk by calling :func:`gtk_init` . In case you need a customized initialization of GTK+ library you could use :func:`hildon_init` after the customized GTK+ initialization.

Typical main function for a Hildon application
==============================================

::
  
  import gtk
  import hildon
  
  def main():
    # Create the main window
    mainwin = hildon.StackableWindow()

    # Set up our GUI elements
   ...
   
    # Show the application window
    mainwin.show_all()
  
    # Enter the main event loop, and wait for user interaction
    gtk.main()

  if __name__ == "__main__":
    main()

   
Details
=======

.. function:: hildon_init ()

    Initializes the hildon library. Call this function after calling :func:`gtk_init` and before using any hildon or GTK+ functions in your program.

    .. versionadded:: 2.2

.. function:: hildon_gtk_init (argc, argv)

    Convenience function to initialize the GTK+ and hildon libraries. Use this function to replace a call to :func:`gtk_init` and also initialize the hildon library. See :func:`hildon_init` and :func:`gtk_init` for details.

    :param argc: Address of the ``argc`` parameter of your main() function. Changed if any arguments were handled.
    :param argv: Address of the ``argv`` parameter of main() . Any parameters understood by :func:`gtk_init` are stripped before return.

    .. versionadded 2.2

Additions to GTK+
*****************

Hildon provides some functions to extend the functionality of existing Gtk widgets. This also includes convenience functions to easily perform frequent tasks.

Details
=======

.. function:: hildon_gtk_menu_new ()

    This is a convenience function to create a :class:`gtk.Menu` setting its widget name to allow Hildon specific styling.

    :returns: A newly created :class:`gtk.Menu` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_button_new (size)

    This is a convenience function to create a :class:`GtkButton` setting its size to one of the pre-defined Hildon sizes.

    Buttons created with this function also override the "gtk-button-images" setting. Images set using :func:`gtk_button_set_image` are always shown.

    Buttons created using this function have "focus-on-click" set to False by default.

    :param size: Flags indicating the size of the new button

    :returns: A newly created :class:`GtkButton` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_toggle_button_new (size)

    This is a convenience function to create a :class:`GtkToggleButton` setting its size to one of the pre-defined Hildon sizes.

    Buttons created with this function also override the "gtk-button-images" setting. Images set using :func:`gtk_button_set_image` are always shown.

    Buttons created using this function have "focus-on-click" set to False by default.

    :param size: Flags indicating the size of the new button

    :returns: A newly created :class:`GtkToggleButton` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_radio_button_new (size, group)

    This is a convenience function to create a :class:`GtkRadioButton` setting its size to one of the pre-defined Hildon sizes.

    Buttons created with this function also override the "gtk-button-images" setting. Images set using :func:`gtk_button_set_image` are always shown.

    Buttons created using this function have "focus-on-click" set to False by default.

    :param size: Flags indicating the size of the new button
    :param group: An existing radio button group, or ``NULL`` if you are creating a new group
    :returns: A newly created :class:`GtkRadioButton` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_radio_button_new_from_widget (size, radio_group_member)

    This is a convenience function to create a :class:`GtkRadioButton` setting its size to one of the pre-defined Hildon sizes.

    Buttons created with this function also override the "gtk-button-images" setting. Images set using :func:`gtk_button_set_image` are always shown.

    Buttons created using this function have "focus-on-click" set to False by default.

    :param size: Flags indicating the size of the new button
    :param radio_group_member: widget to get radio group from or ``NULL``
    :returns: A newly created :class:`GtkRadioButton` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_tree_view_new (mode)

    Creates a new :class:`GtkTreeView` widget with the Hildon UI mode set to ``mode``

    :param mode: the Hildon UI mode
    :returns: A newly created :class:`GtkTreeView` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_tree_view_new_with_model (mode, model)

    Creates a new :class:`GtkTreeView` widget with the Hildon UI mode set to ``mode`` and the model initialized to ``model``.

    :param mode: the Hildon UI mode
    :param model: the model.
    :returns: A newly created :class:`GtkTreeView` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_tree_view_set_ui_mode (treeview, mode)

    Sets the UI mode of ``treeview`` to ``mode``.

    :param treeview: A :class:`GtkTreeView`
    :param mode: The new :class:`HildonUIMode`

    .. versionadded 2.2

.. function:: hildon_gtk_icon_view_new (mode)

    Creates a new :class:`GtkIconView` widget with the Hildon UI mode set to ``mode``

    :param mode: the Hildon UI mode
    :returns: A newly created :class:`GtkIconView` widget

    .. versionadded 2.2

.. function:: hildon_gtk_icon_view_new_with_model (mode, model)

    Creates a new :class:`GtkIconView` widget with the Hildon UI mode set to ``mode`` and the model intitialized to ``model``.

    :param mode: the Hildon UI mode
    :param model: The model.
    :returns: A newly created :class:`GtkIconView` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_icon_view_set_ui_mode (iconview, mode)

    Sets the UI mode of ``iconview`` to ``mode``.

    :param iconview: A :class:`GtkIconView`
    :param mode: The new :class:`HildonUIMode`

    .. versionadded 2.2

.. function:: hildon_gtk_window_set_progress_indicator (window, state)

    This functions tells the window manager to show/hide a progress indicator in the window title. It applies to :class:`HildonDialog` and :class:`hildon.Window` (including subclasses).

    Note that ``window`` must be realized for this to work.

    :param window: a :class:`GtkWindow` .
    :param state: The state we want to set: 1 -> show progress indicator, 0 -> hide progress indicator.

    .. versionadded 2.2

.. function:: hildon_gtk_hscale_new ()

    Creates a new horizontal scale widget that lets the user select a value. The value is technically a double between 0.0 and 1.0. See :func:`gtk_adjustment_configure` for reconfiguring the adjustment.

    The scale is hildonized, which means that a click or tap immediately jumps to the desired position, see :func:`gtk_range_set_jump_to_position` . Further more the value is not displayed, see :func:`gtk_scale_set_draw_value` .

    :returns: a new hildonized :class:`GtkHScale`

    .. versionadded 2.2

.. function:: hildon_gtk_vscale_new ()

    Creates a new vertical scale widget that lets the user select a value. The value is technically a double between 0.0 and 1.0. See :func:`gtk_adjustment_configure` for reconfiguring the adjustment.

    The scale is hildonized, which means that a click or tap immediately jumps to the desired position, see :func:`gtk_range_set_jump_to_position` . Further more the value is not displayed, see :func:`gtk_scale_set_draw_value` .

    :returns: a new hildonized :class:`GtkVScale`

    .. versionadded 2.2

See Also
========

    :class:`HildonButton` :class:`HildonCheckButton`

Constants
*********

.. data:: HILDON_ICON_SIZE_XSMALL

    gtk.icon_size_from_name ("hildon-small")

.. data:: HILDON_ICON_SIZE_STYLUS

    gtk.icon_size_from_name ("hildon-stylus")

.. data:: HILDON_ICON_SIZE_FINGER

    gtk.icon_size_from_name ("hildon-finger")

.. data:: HILDON_ICON_SIZE_THUMB

    gtk.icon_size_from_name ("hildon-thumb")

.. data:: HILDON_ICON_SIZE_LARGE
    
    gtk.icon_size_from_name ("hildon-large")

.. data:: HILDON_ICON_SIZE_XLARGE                  
    
    gtk.icon_size_from_name ("hildon-xlarge")

.. data:: HILDON_ICON_SIZE_TOOLBAR
.. data:: HILDON_ICON_PIXEL_SIZE_XSMALL
.. data:: HILDON_ICON_PIXEL_SIZE_SMALL
.. data:: HILDON_ICON_PIXEL_SIZE_STYLUS
.. data:: HILDON_ICON_PIXEL_SIZE_FINGER
.. data:: HILDON_ICON_PIXEL_SIZE_THUMB
.. data:: HILDON_ICON_PIXEL_SIZE_LARGE
.. data:: HILDON_ICON_PIXEL_SIZE_XLARGE
.. data:: HILDON_ICON_PIXEL_SIZE_TOOLBAR
.. data:: HILDON_MARGIN_HALF
.. data:: HILDON_MARGIN_DEFAULT
.. data:: HILDON_MARGIN_DOUBLE
.. data:: HILDON_MARGIN_TRIPLE
.. data:: HILDON_HARDKEY_UP

    :data:`gtk.GDK_Up`

.. data:: HILDON_HARDKEY_LEFT

    :data:`gtk.GDK_Left`

.. data:: HILDON_HARDKEY_RIGHT

    :data:`gtk.GDK_Right`

.. data:: HILDON_HARDKEY_DOWN

    :data:`gtk.GDK_Down`

.. data:: HILDON_HARDKEY_SELECT

    :data:`gtk.GDK_Return`

.. data:: HILDON_HARDKEY_MENU

    :data:`gtk.GDK_F4`

.. data:: HILDON_HARDKEY_HOME

    :data:`gtk.GDK_F5`

.. data:: HILDON_HARDKEY_ESC

    :data:`gtk.GDK_Escape`

.. data:: HILDON_HARDKEY_FULLSCREEN

    :data:`gtk.GDK_F6`

.. data:: HILDON_HARDKEY_INCREASE

    :data:`gtk.GDK_F7`

.. data:: HILDON_HARDKEY_DECREASE

    :data:`gtk.GDK_F8`

.. data:: HILDON_WINDOW_TITLEBAR_HEIGHT
  
.. function:: hildon_get_icon_pixel_size (size)

    Returns the icon size (height) for the given, named icon. In most cases it's much more convienient to call one of the predefined macros instead of this function directly.

    :param size: the icon size to get pixel size for
    :returns: the height/width of icon to use. O if icon could not be found.

Helper Functions
****************

Description
===========

Hildon provides some helper functions that can be used for commonly performed tasks and functionality blocks. This includes operations on widget styles and probing functions for touch events.

Details
=======

.. function:: hildon_helper_set_logical_font (widget, logicalfontname)

    This function assigns a defined logical font to the ``widget`` and all its child widgets. it also connects to the "style_set" signal which will retrieve assign the new font for the given logical name each time the theme is changed The returned signal id can be used to disconnect the signal. When calling multiple times the previous signal (obtained by calling this function) is disconnected automatically and should not be used.

    :param widget: a :class:`GtkWidget` to assign this logical font for.
    :param logicalfontname: a gchar\* with the logical font name to assign to the widget.
    :returns: the signal id that is triggered every time theme is changed. 0 if font set failed.

.. function:: hildon_helper_set_logical_color (widget, rcflags, state, logicalcolorname)

    This function assigns a defined logical color to the ``widget`` and all it's child widgets. It also connects to the "style_set" signal which will retrieve assign the new color for the given logical name each time the theme is changed. The returned signal id can be used to disconnect the signal. When calling multiple times the previous signal (obtained by calling this function) is disconnected automatically and should not be used.

    Example: If the style you want to modify is bg[NORMAL] then set rcflags to GTK_RC_BG and state to GTK_STATE_NORMAL.

    :param widget: A :class:`GtkWidget` to assign this logical font for.
    :param rcflags: :class:`GtkRcFlags` enumeration defining whether to assign to FG, BG, TEXT or BASE style.
    :param state: :class:`GtkStateType` indicating to which state to assign the logical color
    :param logicalcolorname: A string with the logical font name to assign to the widget.
    :returns: The signal id that is triggered every time theme is changed. 0 if color set failed.

.. function:: hildon_helper_event_button_is_finger (event)

    Checks if the given button event is a finger event.

    :param event: A `GtkEventButton <GtkEventButton>`_ to check
    :returns: True if the event is a finger event.

.. function:: hildon_helper_set_insensitive_message (widget, message)

    .. warning:: :func:`hildon_helper_set_insensitive_message` is deprecated and should not be used in newly-written code. As of hildon 2.2, it is strongly discouraged to use insensitive messages.

    This function assigns an insensitive message to a ``widget``. When the ``widget`` is in an insensitive state and the user activates it, the ``message`` will be displayed using a standard :class:`HildonBanner` .

    :param widget: A :class:`GtkWidget` to assign a banner to
    :param message: A message to display to the user

.. function:: hildon_helper_set_insensitive_messagef (widget, format, ...)

    .. warning:: :func:`hildon_helper_set_insensitive_messagef` is deprecated and should not be used in newly-written code. As of hildon 2.2, it is strongly discouraged to use insensitive messages.

    A version of hildon_helper_set_insensitive_message with string formatting.

    :param widget: A :class:`GtkWidget` to assign a banner to
    :param format: a printf-like format string
    :param ...: arguments for the format string

.. function:: hildon_helper_set_thumb_scrollbar (win, thumb)

    This function enables a thumb scrollbar on a given scrolled window. It'll convert the existing normal scrollbar into a larger, finger-usable scrollbar that works without a stylus. As fingerable list rows are fairly high, consider using the whole available vertical space of your application for the content in order to have as many rows as possible visible on the screen at once.

    Finger-Sized scrollbar should always be used together with finger-sized content.

    :param win: A :class:`GtkScrolledWindow` to use as target
    :param thumb: True to enable the thumb scrollbar, False to disable

Sound Utilities
***************

Details
=======

.. function:: hildon_play_system_sound (sample)

    Plays the given sample using libcanberra. Volume level is received from gconf.

    :param sample: sound file to play

Program
*******

Object Hierarchy
================

::
  
    GObject
     +----Program
  
Description
===========

:class:`Program` is an object used to represent an application running in the Hildon framework.

Applications can have one or more :class:`hildon.Window` s. These can be registered in the :class:`Program` with :meth:`Program.add_window` , and can be unregistered similarly with :meth:`Program.remove_window` .

:class:`Program` provides the programmer with commodities such as applying a common toolbar and menu to all registered :class:`hildon.Window` s. This is done with :meth:`Program.set_common_menu` , :meth:`Program.set_common_app_menu` and :meth:`Program.set_common_toolbar`.

:class:`Program` is also used to apply program-wide properties that are specific to the Hildon framework. For instance :meth:`Program.set_can_hibernate` sets whether or not an application can be set to hibernate by the Hildon task navigator, in situations of low memory.

:: 

    program = hildon.Program.get_instance()

    window1 = hildon.Window()
    window2 = hildon.Window()

    common_toolbar = create_common_toolbar()
    window_specific_toolbar = create_window_specific_toolbar()

    menu = create_menu()

    program.add_window(window1)
    program.add_window(window2)

    program.set_common_app_menu (menu)

    program.set_common_toolbar (common_toolbar)
    window1.add_toolbar (window_specific_toolbar)

    program.set_can_hibernate (True)


Details
=======

.. class:: Program

    .. method:: get_instance()

        Returns the :class:`Program` for the current process. The object is created on the first call. Note that you're not supposed to unref the returned object since it's not reffed in the first place.

        :returns: the :class:`Program` .

    .. method:: add_window (window)

        Registers a :class:`hildon.Window` as belonging to a given :class:`Program` . This allows to apply program-wide settings as all the registered windows, such as :meth:`Program.set_common_menu` , :meth:`Program.set_common_app_menu` and :meth:`Program.set_common_toolbar`.

        :param window: A :class:`hildon.Window` to be added


    .. method:: remove_window (window)

        Used to unregister a window from the program. Subsequent calls to :meth:`Program.set_common_menu` , :meth:`Program.set_common_app_menu` and :meth:`Program.set_common_toolbar` will not affect the window.

        :param window: The :class:`hildon.Window` to unregister

    .. method:: set_can_hibernate (can_hibernate)

        Used to set whether or not the Hildon task navigator should be able to set the program to hibernation in case of low memory

        :param can_hibernate: whether or not the :class:`Program` can hibernate

    .. method:: get_can_hibernate ()

        Returns whether the :class:`Program` is set to be support hibernation from the Hildon task navigator

        :returns: True if the program can hibernate, False otherwise.


    .. method:: set_common_menu (menu)

        Sets a :class:`gtk.Menu` that will appear in all :class:`hildon.Window` s registered with the :class:`Program` . Only one common :class:`gtk.Menu` can be set, further calls will detach the previous common :class:`gtk.Menu` . A :class:`hildon.Window` can use its own :class:`gtk.Menu` with :meth:`hildon.Window.set_menu`

        This method does not support :class:`HildonAppMenu` s. See :meth:`Program.set_common_app_menu` for that.

        :param menu: A :class:`gtk.Menu` to use as common menu for the program

        .. versionadded 2.2

    .. method:: get_common_menu ()

        Returns the :class:`gtk.Menu` that was set as common menu for this :class:`Program` .

        :returns: the :class:`gtk.Menu` or ``NULL`` of no common menu was set.

    .. method:: set_common_app_menu (menu)

        Sets a :class:`HildonAppMenu` that will appear in all :class:`hildon.Window` s registered with the :class:`Program` . Only one common :class:`HildonAppMenu` can be set, further calls will detach the previous common :class:`HildonAppMenu` . A :class:`hildon.Window` can use its own :class:`HildonAppMenu` with :meth:`hildon.Window.set_app_menu`

        This method does not support :class:`gtk.Menu` s. See :meth:`Program.set_common_menu` for that.

        :param menu: A :class:`HildonAppMenu` to use as common menu for the program

        .. versionadded 2.2

    .. method:: get_common_app_menu ()

        Returns the :class:`HildonAppMenu` that was set as common menu for this :class:`Program` .

        :returns: the :class:`HildonAppMenu` or ``NULL`` of no common app menu was set.

        .. versionadded 2.2

    .. method:: set_common_toolbar (toolbar)

        Sets a :class:`gtk.Toolbar` that will appear in all the :class:`hildon.Window` registered to the :class:`Program` . Only one common :class:`gtk.Toolbar` can be set, further call will detach the previous common :class:`gtk.Toolbar` . A :class:`hildon.Window` can use its own :class:`gtk.Toolbar` with :meth:`hildon.Window.add_toolbar` . Both :class:`Program` and :class:`hildon.Window` specific toolbars will be shown

        :param toolbar: A :class:`gtk.Toolbar` to use as common toolbar for the program

    .. method:: get_common_toolbar ()

        Returns the :class:`gtk.Toolbar` that was set as common toolbar for this :class:`Program` .

        :returns: the :class:`gtk.Toolbar` or ``NULL`` of no common toolbar was set.

    .. method:: get_is_topmost ()

        Returns whether one of the program's windows or dialogs is currently activated by the window manager.

        :returns: True if a window or dialog is topmost, False otherwise.


    .. method:: pop_window_stack ()

        .. warning:: :meth:`Program.pop_window_stack` is deprecated and should not be used in newly-written code. Use :meth:`hildon.Window.stack_pop` instead

        Pops a window from the stack.

        :returns: A :class:`HildonStackableWindow` , or ``NULL``

        .. versionadded 2.2

    .. method:: peek_window_stack ()

        .. warning:: :meth:`Program.peek_window_stack` is deprecated and should not be used in newly-written code. Use :meth:`hildon.Window.stack_peek` instead

        :returns: A :class:`HildonStackableWindow` , or ``NULL``


        .. versionadded 2.2

    .. method:: go_to_root_window ()

        .. warning:: :meth:`Program.go_to_root_window` is deprecated and should not be used in newly-written code. See :class:`hildon.WindowStack`

        Goes to the root window of the stack.

        .. versionadded 2.2

Property Details
================

+---------------------------+--------+--------------------------+--------------+-----------------------------------------------------------------------------------------------+
| Name                      | type   | Access                   | Default      | Meaning                                                                                       |
+===========================+========+==========================+==============+===============================================================================================+
| ``can-hibernate``         | bool   | Read / Write             | False        | Whether the program should be set to hibernate by the Task Navigator in low memory situation. |
+---------------------------+--------+--------------------------+--------------+-----------------------------------------------------------------------------------------------+
| ``is-topmost``            | bool   | Read                     | False        | Whether one of the program's window or dialog currently is activated by window manager.       |
+---------------------------+--------+--------------------------+--------------+-----------------------------------------------------------------------------------------------+

See Also
========

:class:`hildon.Window` :class:`HildonStackableWindow` 

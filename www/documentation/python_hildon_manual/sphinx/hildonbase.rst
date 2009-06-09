.. _hildonbase:

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
  
  int
  main (int argc, char **argv)
  {
    /* Initialize i18n support */
    gtk_set_locale ();
  
    /* Initialize the widget set */
    hildon_gtk_init (argc, argv);
  
    /* Create the main window */
    mainwin = hildon_stackable_window_new();
  
    /* Set up our GUI elements */
   ...
  
    /* Show the application window */
    gtk_widget_show_all (mainwin);
  
    /* Enter the main event loop, and wait for user interaction */
    gtk_main ();
  
    /* The user lost interest */
    return 0;
  }
   
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

    This is a convenience function to create a :class:`GtkMenu` setting its widget name to allow Hildon specific styling.

    :returns: A newly created :class:`GtkMenu` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_button_new (size)

    This is a convenience function to create a :class:`GtkButton` setting its size to one of the pre-defined Hildon sizes.

    Buttons created with this function also override the "gtk-button-images" setting. Images set using :func:`gtk_button_set_image` are always shown.

    Buttons created using this function have "focus-on-click" set to ``FALSE`` by default.

    :param size: Flags indicating the size of the new button

    :returns: A newly created :class:`GtkButton` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_toggle_button_new (size)

    This is a convenience function to create a :class:`GtkToggleButton` setting its size to one of the pre-defined Hildon sizes.

    Buttons created with this function also override the "gtk-button-images" setting. Images set using :func:`gtk_button_set_image` are always shown.

    Buttons created using this function have "focus-on-click" set to ``FALSE`` by default.

    :param size: Flags indicating the size of the new button

    :returns: A newly created :class:`GtkToggleButton` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_radio_button_new (size, group)

    This is a convenience function to create a :class:`GtkRadioButton` setting its size to one of the pre-defined Hildon sizes.

    Buttons created with this function also override the "gtk-button-images" setting. Images set using :func:`gtk_button_set_image` are always shown.

    Buttons created using this function have "focus-on-click" set to ``FALSE`` by default.

    :param size: Flags indicating the size of the new button
    :param group: An existing radio button group, or ``NULL`` if you are creating a new group
    :returns: A newly created :class:`GtkRadioButton` widget.

    .. versionadded 2.2

.. function:: hildon_gtk_radio_button_new_from_widget (size, radio_group_member)

    This is a convenience function to create a :class:`GtkRadioButton` setting its size to one of the pre-defined Hildon sizes.

    Buttons created with this function also override the "gtk-button-images" setting. Images set using :func:`gtk_button_set_image` are always shown.

    Buttons created using this function have "focus-on-click" set to ``FALSE`` by default.

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

    This functions tells the window manager to show/hide a progress indicator in the window title. It applies to :class:`HildonDialog` and :class:`HildonWindow` (including subclasses).

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

    gtk_icon_size_from_name ("hildon-small")

.. data:: HILDON_ICON_SIZE_STYLUS

    gtk_icon_size_from_name ("hildon-stylus")

.. data:: HILDON_ICON_SIZE_FINGER

    gtk_icon_size_from_name ("hildon-finger")

.. data:: HILDON_ICON_SIZE_THUMB

    gtk_icon_size_from_name ("hildon-thumb")

.. data:: HILDON_ICON_SIZE_LARGE
    
    gtk_icon_size_from_name ("hildon-large")

.. data:: HILDON_ICON_SIZE_XLARGE                  
    
    gtk_icon_size_from_name ("hildon-xlarge")

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

    :data:`GDK_Up`

.. data:: HILDON_HARDKEY_LEFT

    :data:`GDK_Left`

.. data:: HILDON_HARDKEY_RIGHT

    :data:`GDK_Right`

.. data:: HILDON_HARDKEY_DOWN

    :data:`GDK_Down`

.. data:: HILDON_HARDKEY_SELECT

    :data:`GDK_Return`

.. data:: HILDON_HARDKEY_MENU

    :data:`GDK_F4`

.. data:: HILDON_HARDKEY_HOME

    :data:`GDK_F5`

.. data:: HILDON_HARDKEY_ESC

    :data:`GDK_Escape`

.. data:: HILDON_HARDKEY_FULLSCREEN

    :data:`GDK_F6`

.. data:: HILDON_HARDKEY_INCREASE

    :data:`GDK_F7`

.. data:: HILDON_HARDKEY_DECREASE

    :data:`GDK_F8`

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

.. function:: hildon_helper_set_logical_color ()

::

  gulong              hildon_helper_set_logical_color     (GtkWidget *widget,
                                                           GtkRcFlags rcflags,
                                                           GtkStateType state,
                                                           const gchar *logicalcolorname);

This function assigns a defined logical color to the ``widget`` and all it's child widgets. It also connects to the "style_set" signal which will retrieve assign the new color for the given logical name each time the theme is changed. The returned signal id can be used to disconnect the signal. When calling multiple times the previous signal (obtained by calling this function) is disconnected automatically and should not be used.

Example : If the style you want to modify is bg[NORMAL] then set rcflags to GTK_RC_BG and state to GTK_STATE_NORMAL.



``widget``:
  A :class:`GtkWidget` to assign this logical font for.


``rcflags``:
  `GtkRcFlags <GtkRcFlags>`_ enumeration defining whether to assign to FG, BG, TEXT or BASE style.


``state``:
  `GtkStateType <GtkStateType>`_ indicating to which state to assign the logical color


``logicalcolorname``:
  A gchar\* with the logical font name to assign to the widget.


:returns: 
  The signal id that is triggered every time theme is changed. 0 if color set failed.


.. _hildon-helper-event-button-is-finger:

.. function:: hildon_helper_event_button_is_finger ()

::

  gboolean            hildon_helper_event_button_is_finger
                                                          (GdkEventButton *event);

Checks if the given button event is a finger event.



``event``:
  A `GtkEventButton <GtkEventButton>`_ to check


:returns: 
  TRUE if the event is a finger event.


.. _hildon-helper-set-insensitive-message:

.. function:: hildon_helper_set_insensitive_message ()

::

  void                hildon_helper_set_insensitive_message
                                                          (GtkWidget *widget,
                                                           const gchar *message);

.. warning:: ``hildon_helper_set_insensitive_message`` is deprecated and should not be used in newly-written code. As of hildon 2.2, it is strongly discouraged to use insensitive messages.

This function assigns an insensitive message to a ``widget``. When the ``widget`` is in an insensitive state and the user activates it, the ``message`` will be displayed using a standard `HildonBanner <HildonBanner>`_ .



``widget``:
  A :class:`GtkWidget` to assign a banner to


``message``:
  A message to display to the user


.. _hildon-helper-set-insensitive-messagef:

.. function:: hildon_helper_set_insensitive_messagef ()

::

  void                hildon_helper_set_insensitive_messagef
                                                          (GtkWidget *widget,
                                                           const gchar *format,
                                                           ...);

.. warning:: ``hildon_helper_set_insensitive_messagef`` is deprecated and should not be used in newly-written code. As of hildon 2.2, it is strongly discouraged to use insensitive messages.

A version of hildon_helper_set_insensitive_message with string formatting.



``widget``:
  A :class:`GtkWidget` to assign a banner to


``format``:
  a printf-like format string


``...``:
  arguments for the format string


.. _hildon-helper-set-thumb-scrollbar:

.. function:: hildon_helper_set_thumb_scrollbar ()

::

  void                hildon_helper_set_thumb_scrollbar   (GtkScrolledWindow *win,
                                                           gboolean thumb);

This function enables a thumb scrollbar on a given scrolled window. It'll convert the existing normal scrollbar into a larger, finger-usable scrollbar that works without a stylus. As fingerable list rows are fairly high, consider using the whole available vertical space of your application for the content in order to have as many rows as possible visible on the screen at once.

Finger-Sized scrollbar should always be used together with finger-sized content.



``win``:
  A `GtkScrolledWindow <GtkScrolledWindow>`_ to use as target


``thumb``:
  TRUE to enable the thumb scrollbar, FALSE to disable


.. _hildon-Sound-Utilities:

Sound Utilities
***************

.. _hildon-Sound-Utilities.description:

Description
===========





.. _hildon-Sound-Utilities.details:

Details
=======

.. _hildon-play-system-sound:

.. function:: hildon_play_system_sound ()

::

  void                hildon_play_system_sound            (const gchar *sample);

Plays the given sample using libcanberra. Volume level is received from gconf.



``sample``:
  sound file to play


.. _HildonProgram:

HildonProgram
*************

.. _HildonProgram_object-hierarchy:

Object Hierarchy
================

::
  
    GObject
     +----HildonProgram
  

.. _HildonProgram.properties:

Properties
==========

::

  
    can-hibernate            gboolean              : Read / Write
    is-topmost               gboolean              : Read
  

.. _HildonProgram.description:

Description
===========

`HildonProgram <HildonProgram>`_ is an object used to represent an application running in the Hildon framework.

Applications can have one or more :class:`HildonWindow` s. These can be registered in the `HildonProgram <HildonProgram>`_ with `hildon_program_add_window() <hildon-program-add-window>`_ , and can be unregistered similarly with `hildon_program_remove_window() <hildon-program-remove-window>`_ .

`HildonProgram <HildonProgram>`_ provides the programmer with commodities such as applying a common toolbar and menu to all registered :class:`HildonWindow` s. This is done with `hildon_program_set_common_menu() <hildon-program-set-common-menu>`_ , `hildon_program_set_common_app_menu() <hildon-program-set-common-app-menu>`_ and `hildon_program_set_common_toolbar() <hildon-program-set-common-toolbar>`_ .

`HildonProgram <HildonProgram>`_ is also used to apply program-wide properties that are specific to the Hildon framework. For instance `hildon_program_set_can_hibernate() <hildon-program-set-can-hibernate>`_ sets whether or not an application can be set to hibernate by the Hildon task navigator, in situations of low memory.

:: HildonProgram *program; HildonWindow *window1; HildonWindow *window2; GtkToolbar *common_toolbar, *window_specific_toolbar; HildonAppMenu *menu; program = HILDON_PROGRAM (hildon_program_get_instance ()); window1 = HILDON_WINDOW (hildon_window_new ()); window2 = HILDON_WINDOW (hildon_window_new ()); common_toolbar = create_common_toolbar (); window_specific_toolbar = create_window_specific_toolbar (); menu = create_menu (); hildon_program_add_window (program, window1); hildon_program_add_window (program, window2); hildon_program_set_common_app_menu (program, menu); hildon_program_set_common_toolbar (program, common_toolbar); hildon_window_add_toolbar (window1, window_specific_toolbar); hildon_program_set_can_hibernate (program, TRUE);



.. _HildonProgram.details:

Details
=======

.. _HildonProgram-struct:

.. class:: HildonProgram

::

  typedef struct _HildonProgram HildonProgram;



.. _hildon-program-get-instance:

.. function:: hildon_program_get_instance ()

::

  HildonProgram*      hildon_program_get_instance         (void);

Returns the `HildonProgram <HildonProgram>`_ for the current process. The object is created on the first call. Note that you're not supposed to unref the returned object since it's not reffed in the first place.



:returns: 
  the `HildonProgram <HildonProgram>`_ .


.. _hildon-program-add-window:

.. function:: hildon_program_add_window ()

::

  void                hildon_program_add_window           (HildonProgram *self,
                                                           HildonWindow *window);

Registers a :class:`HildonWindow` as belonging to a given `HildonProgram <HildonProgram>`_ . This allows to apply program-wide settings as all the registered windows, such as `hildon_program_set_common_menu() <hildon-program-set-common-menu>`_ , `hildon_program_set_common_app_menu() <hildon-program-set-common-app-menu>`_ and `hildon_program_set_common_toolbar() <hildon-program-set-common-toolbar>`_ .



``self``:
  The `HildonProgram <HildonProgram>`_ to which the window should be registered


``window``:
  A :class:`HildonWindow` to be added


.. _hildon-program-remove-window:

.. function:: hildon_program_remove_window ()

::

  void                hildon_program_remove_window        (HildonProgram *self,
                                                           HildonWindow *window);

Used to unregister a window from the program. Subsequent calls to `hildon_program_set_common_menu() <hildon-program-set-common-menu>`_ , `hildon_program_set_common_app_menu() <hildon-program-set-common-app-menu>`_ and `hildon_program_set_common_toolbar() <hildon-program-set-common-toolbar>`_ will not affect the window.



``self``:
  The `HildonProgram <HildonProgram>`_ to which the window should be unregistered


``window``:
  The :class:`HildonWindow` to unregister


.. _hildon-program-set-can-hibernate:

.. function:: hildon_program_set_can_hibernate ()

::

  void                hildon_program_set_can_hibernate    (HildonProgram *self,
                                                           gboolean can_hibernate);

Used to set whether or not the Hildon task navigator should be able to set the program to hibernation in case of low memory



``self``:
  The `HildonProgram <HildonProgram>`_ which can hibernate or not


``can_hibernate``:
  whether or not the `HildonProgram <HildonProgram>`_ can hibernate


.. _hildon-program-get-can-hibernate:

.. function:: hildon_program_get_can_hibernate ()

::

  gboolean            hildon_program_get_can_hibernate    (HildonProgram *self);

Returns whether the `HildonProgram <HildonProgram>`_ is set to be support hibernation from the Hildon task navigator



``self``:
  The `HildonProgram <HildonProgram>`_ which can hibernate or not


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ if the program can hibernate, ``FALSE`` otherwise.


.. _hildon-program-set-common-menu:

.. function:: hildon_program_set_common_menu ()

::

  void                hildon_program_set_common_menu      (HildonProgram *self,
                                                           GtkMenu *menu);

Sets a :class:`GtkMenu` that will appear in all :class:`HildonWindow` s registered with the `HildonProgram <HildonProgram>`_ . Only one common :class:`GtkMenu` can be set, further calls will detach the previous common :class:`GtkMenu` . A :class:`HildonWindow` can use its own :class:`GtkMenu` with `hildon_window_set_menu() <hildon-window-set-menu>`_

This method does not support `HildonAppMenu <HildonAppMenu>`_ s. See `hildon_program_set_common_app_menu() <hildon-program-set-common-app-menu>`_ for that.



``self``:
  The `HildonProgram <HildonProgram>`_ in which the common menu should be used


``menu``:
  A :class:`GtkMenu` to use as common menu for the program


.. versionadded 2.2

.. _hildon-program-get-common-menu:

.. function:: hildon_program_get_common_menu ()

::

  GtkMenu*            hildon_program_get_common_menu      (HildonProgram *self);

Returns the :class:`GtkMenu` that was set as common menu for this `HildonProgram <HildonProgram>`_ .



``self``:
  The `HildonProgram <HildonProgram>`_ from which to retrieve the common menu


:returns: 
  the :class:`GtkMenu` or ``NULL`` of no common menu was set.


.. function:: hildon_program_set_common_app_menu ()

::

  void                hildon_program_set_common_app_menu  (HildonProgram *self,
                                                           HildonAppMenu *menu);

Sets a `HildonAppMenu <HildonAppMenu>`_ that will appear in all :class:`HildonWindow` s registered with the `HildonProgram <HildonProgram>`_ . Only one common `HildonAppMenu <HildonAppMenu>`_ can be set, further calls will detach the previous common `HildonAppMenu <HildonAppMenu>`_ . A :class:`HildonWindow` can use its own `HildonAppMenu <HildonAppMenu>`_ with `hildon_window_set_app_menu() <hildon-window-set-app-menu>`_

This method does not support :class:`GtkMenu` s. See `hildon_program_set_common_menu() <hildon-program-set-common-menu>`_ for that.



``self``:
  The `HildonProgram <HildonProgram>`_ in which the common menu should be used


``menu``:
  A `HildonAppMenu <HildonAppMenu>`_ to use as common menu for the program


.. versionadded 2.2

.. function:: hildon_program_get_common_app_menu ()

::

  HildonAppMenu*      hildon_program_get_common_app_menu  (HildonProgram *self);

Returns the `HildonAppMenu <HildonAppMenu>`_ that was set as common menu for this `HildonProgram <HildonProgram>`_ .



``self``:
  The `HildonProgram <HildonProgram>`_ from which to retrieve the common app menu


:returns: 
  the `HildonAppMenu <HildonAppMenu>`_ or ``NULL`` of no common app menu was set.


.. versionadded 2.2

.. function:: hildon_program_set_common_toolbar ()

::

  void                hildon_program_set_common_toolbar   (HildonProgram *self,
                                                           GtkToolbar *toolbar);

Sets a `GtkToolbar <GtkToolbar>`_ that will appear in all the :class:`HildonWindow` registered to the `HildonProgram <HildonProgram>`_ . Only one common `GtkToolbar <GtkToolbar>`_ can be set, further call will detach the previous common `GtkToolbar <GtkToolbar>`_ . A :class:`HildonWindow` can use its own `GtkToolbar <GtkToolbar>`_ with `hildon_window_add_toolbar() <hildon-window-add-toolbar>`_ . Both `HildonProgram <HildonProgram>`_ and :class:`HildonWindow` specific toolbars will be shown



``self``:
  The `HildonProgram <HildonProgram>`_ in which the common toolbar should be used


``toolbar``:
  A `GtkToolbar <GtkToolbar>`_ to use as common toolbar for the program


.. function:: hildon_program_get_common_toolbar ()

::

  GtkToolbar*         hildon_program_get_common_toolbar   (HildonProgram *self);

Returns the `GtkToolbar <GtkToolbar>`_ that was set as common toolbar for this `HildonProgram <HildonProgram>`_ .



``self``:
  The `HildonProgram <HildonProgram>`_ from which to retrieve the common toolbar


:returns: 
  the `GtkToolbar <GtkToolbar>`_ or ``NULL`` of no common toolbar was set.


.. function:: hildon_program_get_is_topmost ()

::

  gboolean            hildon_program_get_is_topmost       (HildonProgram *self);

Returns whether one of the program's windows or dialogs is currently activated by the window manager.



``self``:
  A :class:`HildonWindow`


:returns: 
  ```TRUE`` <TRUE:CAPS>`_ if a window or dialog is topmost, ``FALSE`` otherwise.


.. function:: hildon_program_pop_window_stack ()

::

  HildonStackableWindow* hildon_program_pop_window_stack  (HildonProgram *self);

.. warning:: ``hildon_program_pop_window_stack`` is deprecated and should not be used in newly-written code. Use `hildon_window_stack_pop() <hildon-window-stack-pop>`_ instead

Pops a window from the stack.



``self``:
  A `HildonProgram <HildonProgram>`_


:returns: 
  A `HildonStackableWindow <HildonStackableWindow>`_ , or ``NULL``


.. versionadded 2.2

.. function:: hildon_program_peek_window_stack ()

::

  HildonStackableWindow* hildon_program_peek_window_stack (HildonProgram *self);

.. warning:: ``hildon_program_peek_window_stack`` is deprecated and should not be used in newly-written code. Use `hildon_window_stack_peek() <hildon-window-stack-peek>`_ instead





``self``:
  A `HildonProgram <HildonProgram>`_


:returns: 
  A `HildonStackableWindow <HildonStackableWindow>`_ , or ``NULL``


.. versionadded 2.2

.. function:: hildon_program_go_to_root_window ()

::

  void                hildon_program_go_to_root_window    (HildonProgram *self);

.. warning:: ``hildon_program_go_to_root_window`` is deprecated and should not be used in newly-written code. See `HildonWindowStack <HildonWindowStack>`_

Goes to the root window of the stack.



``self``:
  A `HildonProgram <HildonProgram>`_


.. versionadded 2.2

Property Details
================

The ``can-hibernate`` property

::

    can-hibernate            gboolean              : Read / Write

Whether the program should be set to hibernate by the Task Navigator in low memory situation.



Default value: FALSE

The ``is-topmost`` property

::

    is-topmost               gboolean              : Read

Whether one of the program's window or dialog currently is activated by window manager.



Default value: FALSE

See Also
========

:class:`HildonWindow` `HildonStackableWindow <HildonStackableWindow>`_ 
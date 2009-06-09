Deprecated
##########

.. _HildonColorButton:

HildonColorButton
*****************

.. _HildonColorButton.object-hierarchy:

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
                                         +----HildonColorButton
  

.. _HildonColorButton.implemented-interfaces:

Implemented Interfaces
======================

HildonColorButton implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonColorButton.properties:

Properties
==========

::

  
    color                    GdkColor*             : Read / Write
    popup-shown              gboolean              : Read
  

.. _HildonColorButton.signals:

Signals
=======

::

  
    setup-dialog                                   : Run Last
  

.. _HildonColorButton.description:

Description
===========

HildonColorButton is a widget to open a HildonColorChooserDialog. The selected color is shown in the button. The selected color is a property of the button. The property name is "color" and its type is GtkColor.

HildonColorButton example ========================= :: HildonColorButton *cbutton; GtkColor *color; cbutton = hildon_color_button_new(); gtk_object_get( GTK_OBJECT(cbutton), "color", color );



.. _HildonColorButton.details:

Details
=======

.. _HildonColorButton-struct:

.. class:: HildonColorButton

::

  typedef struct _HildonColorButton HildonColorButton;

.. warning:: ``HildonColorButton`` is deprecated and should not be used in newly-written code.



.. _hildon-color-button-new:

.. function:: hildon_color_button_new ()

::

  GtkWidget*          hildon_color_button_new             (void);

.. warning:: ``hildon_color_button_new`` is deprecated and should not be used in newly-written code.

Creates a new color button. This returns a widget in the form of a small button containing a swatch representing the selected color. When the button is clicked, a color-selection dialog will open, allowing the user to select a color. The swatch will be updated to reflect the new color when the user finishes.



*Returns*:
  a new color button


.. _hildon-color-button-new-with-color:

.. function:: hildon_color_button_new_with_color ()

::

  GtkWidget*          hildon_color_button_new_with_color  (const GdkColor *color);

.. warning:: ``hildon_color_button_new_with_color`` is deprecated and should not be used in newly-written code.

Creates a new color button with ``color`` as the initial color.



``color``:
  a `GdkColor <GdkColor>`_ for the initial color


*Returns*:
  a new color button


.. _hildon-color-button-get-color:

.. function:: hildon_color_button_get_color ()

::

  void                hildon_color_button_get_color       (HildonColorButton *button,
                                                           GdkColor *color);

.. warning:: ``hildon_color_button_get_color`` is deprecated and should not be used in newly-written code.





``button``:
  a `HildonColorButton <HildonColorButton>`_


``color``:
  a color `GdkColor <GdkColor>`_ to be fillled with the current color


.. _hildon-color-button-set-color:

.. function:: hildon_color_button_set_color ()

::

  void                hildon_color_button_set_color       (HildonColorButton *button,
                                                           GdkColor *color);

.. warning:: ``hildon_color_button_set_color`` is deprecated and should not be used in newly-written code.

Sets the color selected by the button.



``button``:
  a `HildonColorButton <HildonColorButton>`_


``color``:
  a color to be set


.. _hildon-color-button-get-popup-shown:

.. function:: hildon_color_button_get_popup_shown ()

::

  gboolean            hildon_color_button_get_popup_shown (HildonColorButton *button);

.. warning:: ``hildon_color_button_get_popup_shown`` is deprecated and should not be used in newly-written code.

This function checks if the color button has the color selection dialog currently popped-up.



``button``:
  a `HildonColorButton <HildonColorButton>`_


*Returns*:
  TRUE if the dialog is popped-up (visible to user).


.. _hildon-color-button-popdown:

.. function:: hildon_color_button_popdown ()

::

  void                hildon_color_button_popdown         (HildonColorButton *button);

.. warning:: ``hildon_color_button_popdown`` is deprecated and should not be used in newly-written code.

If the color selection dialog is currently popped-up (visible) it will be popped-down (hidden).



``button``:
  a `HildonColorButton <HildonColorButton>`_


.. _HildonColorButton.property-details:

Property Details
================

.. _HildonColorButton--color:

The ``color`` property

::

    color                    GdkColor*             : Read / Write

The currently selected color.



.. _HildonColorButton--popup-shown:

The ``popup-shown`` property

::

    popup-shown              gboolean              : Read

If the color selection dialog is currently popped-up (visible)



Default value: FALSE

.. _HildonColorButton.signal-details:

Signal Details
==============

.. _HildonColorButton-setup-dialog:

The ``setup-dialog`` signal

::

  void                user_function                      (HildonColorButton        *hildoncolorbutton,
                                                          HildonColorChooserDialog *arg1,
                                                          gpointer                  user_data)              : Run Last



``hildoncolorbutton``:
  the object which received the signal.


``arg1``:
  


``user_data``:
  user data set when the signal handler was connected.


.. _HildonColorButton.see-also:

See Also
========

`HildonColorChooserDialog <HildonColorChooserDialog>`_ `HildonColorPopup <HildonColorPopup>`_ .. _HildonColorChooser:

HildonColorChooser
******************

.. _HildonColorChooser.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----HildonColorChooser
  

.. _HildonColorChooser.implemented-interfaces:

Implemented Interfaces
======================

HildonColorChooser implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonColorChooser.properties:

Properties
==========

::

  
    color                    GdkColor*             : Read / Write
  

.. _HildonColorChooser.style-properties:

Style Properties
================

::

  
    graphic-border           GtkBorder*            : Read
    inner-size               GtkBorder*            : Read
    outer-border             GtkBorder*            : Read
  

.. _HildonColorChooser.signals:

Signals
=======

::

  
    color-changed                                  : Run First
  

.. _HildonColorChooser.description:

Description
===========

HildonColorChooser is a widget that displays an HSV colorspace. The user can manipulate the colorspace and easily select and shade of any color he wants.

Normally you should not need to use this widget directly. Using `HildonColorButton <HildonColorButton>`_ or `HildonColorChooserDialog <HildonColorChooserDialog>`_ is much more handy.



.. _HildonColorChooser.details:

Details
=======

.. _HildonColorChooser-struct:

.. class:: HildonColorChooser

::

  typedef struct _HildonColorChooser HildonColorChooser;

.. warning:: ``HildonColorChooser`` is deprecated and should not be used in newly-written code.



.. _hildon-color-chooser-new:

.. function:: hildon_color_chooser_new ()

::

  GtkWidget*          hildon_color_chooser_new            (void);

.. warning:: ``hildon_color_chooser_new`` is deprecated and should not be used in newly-written code.



*Returns*:
  


.. _hildon-color-chooser-set-color:

.. function:: hildon_color_chooser_set_color ()

::

  void                hildon_color_chooser_set_color      (HildonColorChooser *chooser,
                                                           GdkColor *color);

.. warning:: ``hildon_color_chooser_set_color`` is deprecated and should not be used in newly-written code.

Sets the color selected in the widget. Will move the crosshair pointer to indicate the passed color.



``chooser``:
  a `HildonColorChooser <HildonColorChooser>`_


``color``:
  a color to be set


.. _hildon-color-chooser-get-color:

.. function:: hildon_color_chooser_get_color ()

::

  void                hildon_color_chooser_get_color      (HildonColorChooser *chooser,
                                                           GdkColor *color);

.. warning:: ``hildon_color_chooser_get_color`` is deprecated and should not be used in newly-written code.

Retrives the currently selected color in the chooser.



``chooser``:
  a `HildonColorChooser <HildonColorChooser>`_


``color``:
  a color structure to fill with the currently selected color


.. _HildonColorChooser.property-details:

Property Details
================

.. _HildonColorChooser--color:

The ``color`` property

::

    color                    GdkColor*             : Read / Write

The currently selected color.



.. _HildonColorChooser.style-property-details:

Style Property Details
======================

.. _HildonColorChooser--graphic-border:

The ``graphic-border`` style property

::

    graphic-border           GtkBorder*            : Read

Size of graphical border.

.. _HildonColorChooser--inner-size:

The ``inner-size`` style property

::

    inner-size               GtkBorder*            : Read

Sizes of SV plane, H bar and spacing.

.. _HildonColorChooser--outer-border:

The ``outer-border`` style property

::

    outer-border             GtkBorder*            : Read

The outer border for the chooser.

.. _HildonColorChooser.signal-details:

Signal Details
==============

.. _HildonColorChooser-color-changed:

The ``color-changed`` signal

::

  void                user_function                      (HildonColorChooser *hildoncolorchooser,
                                                          gpointer            user_data)               : Run First



``hildoncolorchooser``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonColorChooser.see-also:

See Also
========

`HildonColorChooserDialog <HildonColorChooserDialog>`_ .. _HildonControlbar:

HildonControlbar
****************

.. _HildonControlbar.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkRange
                             +----GtkScale
                                   +----HildonControlbar
  

.. _HildonControlbar.implemented-interfaces:

Implemented Interfaces
======================

HildonControlbar implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonControlbar.properties:

Properties
==========

::

  
    max                      gint                  : Read / Write
    min                      gint                  : Read / Write
    value                    gint                  : Read / Write
  

.. _HildonControlbar.style-properties:

Style Properties
================

::

  
    inner-border-width       guint                 : Read
  

.. _HildonControlbar.signals:

Signals
=======

::

  
    end-reached                                    : Run First
  

.. _HildonControlbar.description:

Description
===========

`HildonControlbar <HildonControlbar>`_ is a horizontally positioned range widget that is visually divided into blocks and supports setting a minimum and maximum value for the range.

.. note:: `HildonControlbar <HildonControlbar>`_ has been deprecated since Hildon 2.2 See `Migrating Control Bars <hildon-migrating-control-bar>`_ section to know how to migrate this deprecated widget.

HildonControlbar example ======================== :: GtkWidget *cbar = hildon_controlbar_new(); hildon_controlbar_set_max (HILDON_CONTROLBAR (cbar), 12); hildon_controlbar_set_value (HILDON_CONTROLBAR (cbar), 6);



.. _HildonControlbar.details:

Details
=======

.. _HildonControlbar-struct:

.. class:: HildonControlbar

::

  typedef struct _HildonControlbar HildonControlbar;

.. warning:: ``HildonControlbar`` is deprecated and should not be used in newly-written code.



.. _hildon-controlbar-new:

.. function:: hildon_controlbar_new ()

::

  GtkWidget*          hildon_controlbar_new               (void);

.. warning:: ``hildon_controlbar_new`` is deprecated and should not be used in newly-written code.

Creates a new `HildonControlbar <HildonControlbar>`_ widget.



*Returns*:
  a `GtkWidget <GtkWidget>`_ pointer of newly created control bar widget


.. _hildon-controlbar-set-value:

.. function:: hildon_controlbar_set_value ()

::

  void                hildon_controlbar_set_value         (HildonControlbar *self,
                                                           gint value);

.. warning:: ``hildon_controlbar_set_value`` is deprecated and should not be used in newly-written code.

Set the current value of the control bar to the specified value.



``self``:
  pointer to `HildonControlbar <HildonControlbar>`_


``value``:
  value in range of = 0 G_MAX_INT


.. _hildon-controlbar-get-value:

.. function:: hildon_controlbar_get_value ()

::

  gint                hildon_controlbar_get_value         (HildonControlbar *self);

.. warning:: ``hildon_controlbar_get_value`` is deprecated and should not be used in newly-written code.





``self``:
  pointer to `HildonControlbar <HildonControlbar>`_


*Returns*:
  current value as gint


.. _hildon-controlbar-get-max:

.. function:: hildon_controlbar_get_max ()

::

  gint                hildon_controlbar_get_max           (HildonControlbar *self);

.. warning:: ``hildon_controlbar_get_max`` is deprecated and should not be used in newly-written code.





``self``:
  a pointer to `HildonControlbar <HildonControlbar>`_


*Returns*:
  maximum value of control bar


.. _hildon-controlbar-get-min:

.. function:: hildon_controlbar_get_min ()

::

  gint                hildon_controlbar_get_min           (HildonControlbar *self);

.. warning:: ``hildon_controlbar_get_min`` is deprecated and should not be used in newly-written code.





``self``:
  a pointer to `HildonControlbar <HildonControlbar>`_


*Returns*:
  minimum value of controlbar


.. _hildon-controlbar-set-max:

.. function:: hildon_controlbar_set_max ()

::

  void                hildon_controlbar_set_max           (HildonControlbar *self,
                                                           gint max);

.. warning:: ``hildon_controlbar_set_max`` is deprecated and should not be used in newly-written code.

Set the control bar's maximum to the given value.

If the new maximum is smaller than current value, the value will be adjusted so that it equals the new maximum.



``self``:
  pointer to `HildonControlbar <HildonControlbar>`_


``max``:
  maximum value to set. The value needs to be greater than 0.


.. _hildon-controlbar-set-min:

.. function:: hildon_controlbar_set_min ()

::

  void                hildon_controlbar_set_min           (HildonControlbar *self,
                                                           gint min);

.. warning:: ``hildon_controlbar_set_min`` is deprecated and should not be used in newly-written code.

Set the control bar's minimum to the given value.

If the new minimum is smaller than current value, the value will be adjusted so that it equals the new minimum.



``self``:
  pointer to `HildonControlbar <HildonControlbar>`_


``min``:
  minimum value to set. The value needs to be greater than or equal to 0.


.. _hildon-controlbar-set-range:

.. function:: hildon_controlbar_set_range ()

::

  void                hildon_controlbar_set_range         (HildonControlbar *self,
                                                           gint min,
                                                           gint max);

.. warning:: ``hildon_controlbar_set_range`` is deprecated and should not be used in newly-written code.

Set the controlbars range to the given value

If the new maximum is smaller than current value, the value will be adjusted so that it equals the new maximum.

If the new minimum is smaller than current value, the value will be adjusted so that it equals the new minimum.



``self``:
  pointer to `HildonControlbar <HildonControlbar>`_


``min``:
  Minimum value to set. The value needs to be greater than or equal to 0.


``max``:
  maximum value to set. The value needs to be greater than 0.


.. _HildonControlbar.property-details:

Property Details
================

.. _HildonControlbar--max:

The ``max`` property

::

    max                      gint                  : Read / Write

Controlbar maximum value.



Default value: 10

.. _HildonControlbar--min:

The ``min`` property

::

    min                      gint                  : Read / Write

Controlbar minimum value.



Default value: 0

.. _HildonControlbar--value:

The ``value`` property

::

    value                    gint                  : Read / Write

Controlbar current value.



Default value: 0

.. _HildonControlbar.style-property-details:

Style Property Details
======================

.. _HildonControlbar--inner-border-width:

The ``inner-border-width`` style property

::

    inner-border-width       guint                 : Read

The border spacing between the controlbar border and controlbar blocks.

Allowed values: = G_MAXINT

Default value: 0

.. _HildonControlbar.signal-details:

Signal Details
==============

.. _HildonControlbar-end-reached:

The ``end-reached`` signal

::

  void                user_function                      (HildonControlbar *hildoncontrolbar,
                                                          gboolean          arg1,
                                                          gpointer          user_data)             : Run First



``hildoncontrolbar``:
  the object which received the signal.


``arg1``:
  


``user_data``:
  user data set when the signal handler was connected.


.. _HildonVolumebar:

HildonVolumebar
***************

.. _HildonVolumebar.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----HildonVolumebar
                                   +----HildonHVolumebar
                                   +----HildonVVolumebar
  

.. _HildonVolumebar.implemented-interfaces:

Implemented Interfaces
======================

HildonVolumebar implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonVolumebar.properties:

Properties
==========

::

  
    has-mute                 gboolean              : Read / Write / Construct
    level                    gdouble               : Read / Write
    mute                     gboolean              : Read / Write
  

.. _HildonVolumebar.signals:

Signals
=======

::

  
    level-changed                                  : Run Last / Action
    mute-toggled                                   : Run Last / Action
  

.. _HildonVolumebar.description:

Description
===========

`HildonVolumebar <HildonVolumebar>`_ is a base class for widgets that display a volume bar that allows increasing or decreasing volume within a predefined range, and muting the volume when users click the mute icon.

.. note:: `HildonVolumebar <HildonVolumebar>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. See `Migrating Volume Bars <hildon-migrating-volume-bar>`_ section to know how to migrate this deprecated widget.



.. _HildonVolumebar.details:

Details
=======

.. _HildonVolumebar-struct:

.. class:: HildonVolumebar

::

  typedef struct _HildonVolumebar HildonVolumebar;

.. warning:: ``HildonVolumebar`` is deprecated and should not be used in newly-written code.



.. _hildon-volumebar-get-level:

.. function:: hildon_volumebar_get_level ()

::

  double              hildon_volumebar_get_level          (HildonVolumebar *self);

.. warning:: ``hildon_volumebar_get_level`` is deprecated and should not be used in newly-written code.

Gets the volume level of this `HildonVolumebar <HildonVolumebar>`_ .



``self``:
  volume bar to query level on


*Returns*:
  volume level or -1 on error


.. _hildon-volumebar-set-level:

.. function:: hildon_volumebar_set_level ()

::

  void                hildon_volumebar_set_level          (HildonVolumebar *self,
                                                           gdouble level);

.. warning:: ``hildon_volumebar_set_level`` is deprecated and should not be used in newly-written code.

Sets new volume level for this `HildonVolumebar <HildonVolumebar>`_ .



``self``:
  volume bar to change level on


``level``:
  new level


.. _hildon-volumebar-get-mute:

.. function:: hildon_volumebar_get_mute ()

::

  gboolean            hildon_volumebar_get_mute           (HildonVolumebar *self);

.. warning:: ``hildon_volumebar_get_mute`` is deprecated and should not be used in newly-written code.

Gets mute status of this `HildonVolumebar <HildonVolumebar>`_ (ON/OFF).



``self``:
  volume bar to query mute status


*Returns*:
  Mute status as `gboolean <gboolean>`_ value.


.. _hildon-volumebar-set-mute:

.. function:: hildon_volumebar_set_mute ()

::

  void                hildon_volumebar_set_mute           (HildonVolumebar *self,
                                                           gboolean mute);

.. warning:: ``hildon_volumebar_set_mute`` is deprecated and should not be used in newly-written code.

Sets mute status for this `HildonVolumebar <HildonVolumebar>`_ .



``self``:
  volume bar to work on


``mute``:
  mute ON/OFF


.. _hildon-volumebar-get-adjustment:

.. function:: hildon_volumebar_get_adjustment ()

::

  GtkAdjustment*      hildon_volumebar_get_adjustment     (HildonVolumebar *self);

.. warning:: ``hildon_volumebar_get_adjustment`` is deprecated and should not be used in newly-written code.

Gets the GtkAdjustment used in volume bar. This can be handy to pass to hildon_appview_set_connected_adjustment which will allow changing the volume with 'increase' / 'decrease' hardware buttons.



``self``:
  a `HildonVolumebar <HildonVolumebar>`_


*Returns*:
  a `GtkAdjustment <GtkAdjustment>`_ used by volume bar.


.. _hildon-volumebar-set-range-insensitive-message:

.. function:: hildon_volumebar_set_range_insensitive_message ()

::

  void                hildon_volumebar_set_range_insensitive_message
                                                          (HildonVolumebar *widget,
                                                           const gchar *message);

.. warning:: ``hildon_volumebar_set_range_insensitive_message`` is deprecated and should not be used in newly-written code. As of hildon 2.2, it is strongly discouraged to use insensitive messages.

Used to asign an insensitive message to the slider of the given volumebar. It simply calls hildon_helper_set_insensitive_message on the slider/range of the volumebar.



``widget``:
  A ``GtkWidget`` to assign the banner to


``message``:
  A message to display to the user


.. _hildon-volumebar-set-range-insensitive-messagef:

.. function:: hildon_volumebar_set_range_insensitive_messagef ()

::

  void                hildon_volumebar_set_range_insensitive_messagef
                                                          (HildonVolumebar *widget,
                                                           const gchar *format,
                                                           ...);

.. warning:: ``hildon_volumebar_set_range_insensitive_messagef`` is deprecated and should not be used in newly-written code. As of hildon 2.2, it is strongly discouraged to use insensitive messages.

A helper printf-like variant of hildon_helper_set_insensitive_message.



``widget``:
  A ``GtkWidget`` to assign the banner to


``format``:
  a printf-like format string


``...``:
  arguments for the format string


.. _HildonVolumebar.property-details:

Property Details
================

.. _HildonVolumebar--has-mute:

The ``has-mute`` property

::

    has-mute                 gboolean              : Read / Write / Construct

Whether the mute button is visibile.



Default value: TRUE

.. _HildonVolumebar--level:

The ``level`` property

::

    level                    gdouble               : Read / Write

Current volume level.



Allowed values: [0,100]

Default value: 50

.. _HildonVolumebar--mute:

The ``mute`` property

::

    mute                     gboolean              : Read / Write

Whether volume is muted.



Default value: FALSE

.. _HildonVolumebar.signal-details:

Signal Details
==============

.. _HildonVolumebar-level-changed:

The ``level-changed`` signal

::

  void                user_function                      (HildonVolumebar *hildonvolumebar,
                                                          gpointer         user_data)            : Run Last / Action



``hildonvolumebar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonVolumebar-mute-toggled:

The ``mute-toggled`` signal

::

  void                user_function                      (HildonVolumebar *hildonvolumebar,
                                                          gpointer         user_data)            : Run Last / Action



``hildonvolumebar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonVolumebar.see-also:

See Also
========

`HildonHVolumebar <HildonHVolumebar>`_ `HildonVVolumebar <HildonVVolumebar>`_ .. _HildonVVolumebar:

HildonVVolumebar
****************

.. _HildonVVolumebar.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----HildonVolumebar
                                   +----HildonVVolumebar
  

.. _HildonVVolumebar.implemented-interfaces:

Implemented Interfaces
======================

HildonVVolumebar implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonVVolumebar.description:

Description
===========

`HildonVVolumebar <HildonVVolumebar>`_ is a subclass of `HildonVolumebar <HildonVolumebar>`_ . It displays a vertical volume bar that allows increasing or decreasing volume within a predefined range, and muting when users click the mute icon.

.. note:: `HildonVVolumebar <HildonVVolumebar>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. See `Migrating Volume Bars <hildon-migrating-volume-bar>`_ section to know how to migrate this deprecated widget.

Here is an example that creates a vertical volume bar and connects both its signals.

HildonVVolumebar example ======================== :: GtkWidget *volbar = hildon_vvolumebar_new (); g_signal_connect (G_OBJECT (volbar), "mute_toggled", G_CALLBACK (mute_toggle), NULL); g_signal_connect (G_OBJECT (volbar), "level_changed", G_CALLBACK (level_change), NULL);



.. _HildonVVolumebar.details:

Details
=======

.. _HildonVVolumebar-struct:

.. class:: HildonVVolumebar

::

  typedef struct _HildonVVolumebar HildonVVolumebar;

.. warning:: ``HildonVVolumebar`` is deprecated and should not be used in newly-written code.



.. _hildon-vvolumebar-new:

.. function:: hildon_vvolumebar_new ()

::

  GtkWidget*          hildon_vvolumebar_new               (void);

.. warning:: ``hildon_vvolumebar_new`` is deprecated and should not be used in newly-written code.

Creates a new `HildonVVolumebar <HildonVVolumebar>`_ widget.



*Returns*:
  a new `HildonVVolumebar <HildonVVolumebar>`_


.. _HildonVVolumebar.see-also:

See Also
========

`HildonVolumebar <HildonVolumebar>`_ `HildonHVolumebar <HildonHVolumebar>`_ .. _HildonHVolumebar:

HildonHVolumebar
****************

.. _HildonHVolumebar.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----HildonVolumebar
                                   +----HildonHVolumebar
  

.. _HildonHVolumebar.implemented-interfaces:

Implemented Interfaces
======================

HildonHVolumebar implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonHVolumebar.description:

Description
===========

The `HildonHVolumebar <HildonHVolumebar>`_ widget displays a horizontal volume bar that allows increasing or decreasing volume within a pre-defined range, and includes a mute icon which users can click to mute the sound.

.. note:: `HildonHVolumeBar <HildonHVolumeBar>`_ has been deprecated since Hildon 2.2 See `Migrating Volume Bars <hildon-migrating-volume-bar>`_ section to know how to migrate this deprecated widget.

:: GtkWidget *volbar = hildon_hvolumebar_new (); g_signal_connect (G_OBJECT(volbar), "mute_toggled", G_CALLBACK(mute_toggle), NULL); g_signal_connect (G_OBJECT(volbar), "level_changed", G_CALLBACK(level_change), NULL);



.. _HildonHVolumebar.details:

Details
=======

.. _HildonHVolumebar-struct:

.. class:: HildonHVolumebar

::

  typedef struct _HildonHVolumebar HildonHVolumebar;

.. warning:: ``HildonHVolumebar`` is deprecated and should not be used in newly-written code.



.. _hildon-hvolumebar-new:

.. function:: hildon_hvolumebar_new ()

::

  GtkWidget*          hildon_hvolumebar_new               (void);

.. warning:: ``hildon_hvolumebar_new`` is deprecated and should not be used in newly-written code.

Creates a new `HildonHVolumebar <HildonHVolumebar>`_ widget.



*Returns*:
  a new `HildonHVolumebar <HildonHVolumebar>`_


.. _HildonHVolumebar.see-also:

See Also
========

`HildonVVolumebar <HildonVVolumebar>`_ `HildonVolumebar <HildonVolumebar>`_ .. _HildonSeekbar:

HildonSeekbar
*************

.. _HildonSeekbar.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkRange
                             +----GtkScale
                                   +----HildonSeekbar
  

.. _HildonSeekbar.implemented-interfaces:

Implemented Interfaces
======================

HildonSeekbar implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonSeekbar.properties:

Properties
==========

::

  
    fraction                 gdouble               : Read / Write
    position                 gdouble               : Read / Write
    total-time               gdouble               : Read / Write
  

.. _HildonSeekbar.description:

Description
===========

HildonSeekbar allows seeking in media with a range widget. It supports for setting or getting the length (total time) of the media, the position within it and the fraction (maximum position in a stream/the amount currently downloaded). The position is clamped between zero and the total time, or zero and the fraction in case of a stream.



.. _HildonSeekbar.details:

Details
=======

.. _HildonSeekbar-struct:

.. class:: HildonSeekbar

::

  typedef struct _HildonSeekbar HildonSeekbar;

.. warning:: ``HildonSeekbar`` is deprecated and should not be used in newly-written code.



.. _hildon-seekbar-new:

.. function:: hildon_seekbar_new ()

::

  GtkWidget*          hildon_seekbar_new                  (void);

.. warning:: ``hildon_seekbar_new`` is deprecated and should not be used in newly-written code.

Create a new `HildonSeekbar <HildonSeekbar>`_ widget.



*Returns*:
  a `GtkWidget <GtkWidget>`_ pointer of `HildonSeekbar <HildonSeekbar>`_ widget


.. _hildon-seekbar-get-total-time:

.. function:: hildon_seekbar_get_total_time ()

::

  gint                hildon_seekbar_get_total_time       (HildonSeekbar *seekbar);

.. warning:: ``hildon_seekbar_get_total_time`` is deprecated and should not be used in newly-written code.





``seekbar``:
  pointer to `HildonSeekbar <HildonSeekbar>`_ widget


*Returns*:
  total playing time of media in seconds.


.. _hildon-seekbar-set-total-time:

.. function:: hildon_seekbar_set_total_time ()

::

  void                hildon_seekbar_set_total_time       (HildonSeekbar *seekbar,
                                                           gint time);

.. warning:: ``hildon_seekbar_set_total_time`` is deprecated and should not be used in newly-written code.

Set total playing time of media in seconds.



``seekbar``:
  pointer to `HildonSeekbar <HildonSeekbar>`_ widget


``time``:
  integer greater than zero


.. _hildon-seekbar-get-position:

.. function:: hildon_seekbar_get_position ()

::

  gint                hildon_seekbar_get_position         (HildonSeekbar *seekbar);

.. warning:: ``hildon_seekbar_get_position`` is deprecated and should not be used in newly-written code.

Get current position in stream in seconds.



``seekbar``:
  pointer to `HildonSeekbar <HildonSeekbar>`_ widget


*Returns*:
  current position in stream in seconds


.. _hildon-seekbar-set-position:

.. function:: hildon_seekbar_set_position ()

::

  void                hildon_seekbar_set_position         (HildonSeekbar *seekbar,
                                                           gint time);

.. warning:: ``hildon_seekbar_set_position`` is deprecated and should not be used in newly-written code.

Set current position in stream in seconds.



``seekbar``:
  pointer to `HildonSeekbar <HildonSeekbar>`_ widget


``time``:
  time within range of = 0 G_MAXINT


.. _hildon-seekbar-set-fraction:

.. function:: hildon_seekbar_set_fraction ()

::

  void                hildon_seekbar_set_fraction         (HildonSeekbar *seekbar,
                                                           guint fraction);

.. warning:: ``hildon_seekbar_set_fraction`` is deprecated and should not be used in newly-written code.

Set current fraction value of the range. It should be between the minimal and maximal values of the range in seekbar.



``seekbar``:
  pointer to `HildonSeekbar <HildonSeekbar>`_ widget


``fraction``:
  the new position of the progress indicator


.. _hildon-seekbar-get-fraction:

.. function:: hildon_seekbar_get_fraction ()

::

  guint               hildon_seekbar_get_fraction         (HildonSeekbar *seekbar);

.. warning:: ``hildon_seekbar_get_fraction`` is deprecated and should not be used in newly-written code.

Get current fraction value of the rage.



``seekbar``:
  pointer to `HildonSeekbar <HildonSeekbar>`_ widget


*Returns*:
  current fraction


.. _HildonSeekbar.property-details:

Property Details
================

.. _HildonSeekbar--fraction:

The ``fraction`` property

::

    fraction                 gdouble               : Read / Write

Current fraction related to the progress indicator.



Allowed values: = 0

Default value: 0

.. _HildonSeekbar--position:

The ``position`` property

::

    position                 gdouble               : Read / Write

Current position in this media file.



Allowed values: = 0

Default value: 0

.. _HildonSeekbar--total-time:

The ``total-time`` property

::

    total-time               gdouble               : Read / Write

Total playing time of this media file.



Allowed values: = 0

Default value: 0

.. _HildonCalendar:

HildonCalendar
**************

.. _HildonCalendar.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----HildonCalendar
  

.. _HildonCalendar.implemented-interfaces:

Implemented Interfaces
======================

HildonCalendar implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonCalendar.properties:

Properties
==========

::

  
    day                      gint                  : Read / Write
    max-year                 gint                  : Read / Write
    min-year                 gint                  : Read / Write
    month                    gint                  : Read / Write
    no-month-change          gboolean              : Read / Write
    show-day-names           gboolean              : Read / Write
    show-heading             gboolean              : Read / Write
    show-week-numbers        gboolean              : Read / Write
    week-start               gint                  : Read / Write
    year                     gint                  : Read / Write
  

.. _HildonCalendar.signals:

Signals
=======

::

  
    day-selected                                   : Run First
    day-selected-double-click                      : Run First
    erroneous-date                                 : Run First
    month-changed                                  : Run First
    next-month                                     : Run First
    next-year                                      : Run First
    prev-month                                     : Run First
    prev-year                                      : Run First
    selected-date                                  : Run First
  

.. _HildonCalendar.description:

Description
===========

`HildonCalendar <HildonCalendar>`_ is a slightly modified `GtkCalendar <GtkCalendar>`_ . It has an almost same API but a slightly different look and behaviour. Use this widget instead of standard `GtkCalendar <GtkCalendar>`_ or use `HildonDateEditor <HildonDateEditor>`_ for more higher-level date setting operations.

.. note:: `HildonCalendar <HildonCalendar>`_ has been deprecated since Hildon 2.2 See `Migrating Date Widgets <hildon-migrating-date-widgets>`_ section to know how to migrate this deprecated widget.



.. _HildonCalendar.details:

Details
=======

.. _HildonCalendarDisplayOptions:

.. :: enum HildonCalendarDisplayOptions

::

  typedef enum
  {
      HILDON_CALENDAR_SHOW_HEADING                = 1  0,
      HILDON_CALENDAR_SHOW_DAY_NAMES              = 1  1,
      HILDON_CALENDAR_NO_MONTH_CHANGE             = 1  2,
      HILDON_CALENDAR_SHOW_WEEK_NUMBERS           = 1  3,
      HILDON_CALENDAR_WEEK_START_MONDAY           = 1  4
  } HildonCalendarDisplayOptions;
  

.. warning:: ``HildonCalendarDisplayOptions`` is deprecated and should not be used in newly-written code.



.. _HildonCalendar-struct:

.. class:: HildonCalendar

::

  typedef struct _HildonCalendar HildonCalendar;

.. warning:: ``HildonCalendar`` is deprecated and should not be used in newly-written code.



.. _hildon-calendar-new:

.. function:: hildon_calendar_new ()

::

  GtkWidget*          hildon_calendar_new                 (void);

.. warning:: ``hildon_calendar_new`` is deprecated and should not be used in newly-written code.



*Returns*:
  


.. _hildon-calendar-select-month:

.. function:: hildon_calendar_select_month ()

::

  gboolean            hildon_calendar_select_month        (HildonCalendar *calendar,
                                                           guint month,
                                                           guint year);

.. warning:: ``hildon_calendar_select_month`` is deprecated and should not be used in newly-written code.



``calendar``:
  


``month``:
  


``year``:
  


*Returns*:
  


.. _hildon-calendar-select-day:

.. function:: hildon_calendar_select_day ()

::

  void                hildon_calendar_select_day          (HildonCalendar *calendar,
                                                           guint day);

.. warning:: ``hildon_calendar_select_day`` is deprecated and should not be used in newly-written code.



``calendar``:
  


``day``:
  


.. _hildon-calendar-mark-day:

.. function:: hildon_calendar_mark_day ()

::

  gboolean            hildon_calendar_mark_day            (HildonCalendar *calendar,
                                                           guint day);

.. warning:: ``hildon_calendar_mark_day`` is deprecated and should not be used in newly-written code.



``calendar``:
  


``day``:
  


*Returns*:
  


.. _hildon-calendar-unmark-day:

.. function:: hildon_calendar_unmark_day ()

::

  gboolean            hildon_calendar_unmark_day          (HildonCalendar *calendar,
                                                           guint day);

.. warning:: ``hildon_calendar_unmark_day`` is deprecated and should not be used in newly-written code.



``calendar``:
  


``day``:
  


*Returns*:
  


.. _hildon-calendar-clear-marks:

.. function:: hildon_calendar_clear_marks ()

::

  void                hildon_calendar_clear_marks         (HildonCalendar *calendar);

.. warning:: ``hildon_calendar_clear_marks`` is deprecated and should not be used in newly-written code.



``calendar``:
  


.. _hildon-calendar-set-display-options:

.. function:: hildon_calendar_set_display_options ()

::

  void                hildon_calendar_set_display_options (HildonCalendar *calendar,
                                                           HildonCalendarDisplayOptions flags);

.. warning:: ``hildon_calendar_set_display_options`` is deprecated and should not be used in newly-written code.

Sets display options (whether to display the heading and the month headings).



``calendar``:
  a `HildonCalendar <HildonCalendar>`_


``flags``:
  the display options to set


.. _hildon-calendar-get-display-options:

.. function:: hildon_calendar_get_display_options ()

::

  HildonCalendarDisplayOptions hildon_calendar_get_display_options
                                                          (HildonCalendar *calendar);

.. warning:: ``hildon_calendar_get_display_options`` is deprecated and should not be used in newly-written code.

Returns the current display options of ``calendar``.



``calendar``:
  a `HildonCalendar <HildonCalendar>`_


*Returns*:
  the display options.


.. _hildon-calendar-get-date:

.. function:: hildon_calendar_get_date ()

::

  void                hildon_calendar_get_date            (HildonCalendar *calendar,
                                                           guint *year,
                                                           guint *month,
                                                           guint *day);

.. warning:: ``hildon_calendar_get_date`` is deprecated and should not be used in newly-written code.



``calendar``:
  


``year``:
  


``month``:
  


``day``:
  


.. _hildon-calendar-freeze:

.. function:: hildon_calendar_freeze ()

::

  void                hildon_calendar_freeze              (HildonCalendar *calendar);

.. warning:: ``hildon_calendar_freeze`` is deprecated and should not be used in newly-written code.



``calendar``:
  


.. _hildon-calendar-thaw:

.. function:: hildon_calendar_thaw ()

::

  void                hildon_calendar_thaw                (HildonCalendar *calendar);

.. warning:: ``hildon_calendar_thaw`` is deprecated and should not be used in newly-written code.



``calendar``:
  


.. _HildonCalendar.property-details:

Property Details
================

.. _HildonCalendar--day:

The ``day`` property

::

    day                      gint                  : Read / Write

The selected day as number between 1 and 31 or 0 to unselect the currently selected day.



Allowed values: [0,31]

Default value: 0

.. _HildonCalendar--max-year:

The ``max-year`` property

::

    max-year                 gint                  : Read / Write

Maximum valid year (0 if no limit).



Allowed values: [0,10000]

Default value: 0

.. _HildonCalendar--min-year:

The ``min-year`` property

::

    min-year                 gint                  : Read / Write

Minimum valid year (0 if no limit).



Allowed values: [0,10000]

Default value: 0

.. _HildonCalendar--month:

The ``month`` property

::

    month                    gint                  : Read / Write

The selected month as number between 0 and 11.



Allowed values: [0,11]

Default value: 0

.. _HildonCalendar--no-month-change:

The ``no-month-change`` property

::

    no-month-change          gboolean              : Read / Write

Determines whether the selected month can be changed.



Default value: FALSE

.. _HildonCalendar--show-day-names:

The ``show-day-names`` property

::

    show-day-names           gboolean              : Read / Write

Determines whether day names are displayed.



Default value: TRUE

.. _HildonCalendar--show-heading:

The ``show-heading`` property

::

    show-heading             gboolean              : Read / Write

Determines whether a heading is displayed.



Default value: TRUE

.. _HildonCalendar--show-week-numbers:

The ``show-week-numbers`` property

::

    show-week-numbers        gboolean              : Read / Write

Determines whether week numbers are displayed.



Default value: FALSE

.. _HildonCalendar--week-start:

The ``week-start`` property

::

    week-start               gint                  : Read / Write

Determines the start day of the week (0 for Sunday, 1 for Monday etc.)



Allowed values: [0,6]

Default value: 0

.. _HildonCalendar--year:

The ``year`` property

::

    year                     gint                  : Read / Write

The selected year.



Allowed values: = 0

Default value: 0

.. _HildonCalendar.signal-details:

Signal Details
==============

.. _HildonCalendar-day-selected:

The ``day-selected`` signal

::

  void                user_function                      (HildonCalendar *hildoncalendar,
                                                          gpointer        user_data)           : Run First



``hildoncalendar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendar-day-selected-double-click:

The ``day-selected-double-click`` signal

::

  void                user_function                      (HildonCalendar *hildoncalendar,
                                                          gpointer        user_data)           : Run First



``hildoncalendar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendar-erroneous-date:

The ``erroneous-date`` signal

::

  void                user_function                      (HildonCalendar *arg0,
                                                          gpointer        user_data)      : Run First

Emitted when the user tries to set a date which is outside the boundaries set by min-year and max-year properties.



``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendar-month-changed:

The ``month-changed`` signal

::

  void                user_function                      (HildonCalendar *hildoncalendar,
                                                          gpointer        user_data)           : Run First



``hildoncalendar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendar-next-month:

The ``next-month`` signal

::

  void                user_function                      (HildonCalendar *hildoncalendar,
                                                          gpointer        user_data)           : Run First



``hildoncalendar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendar-next-year:

The ``next-year`` signal

::

  void                user_function                      (HildonCalendar *hildoncalendar,
                                                          gpointer        user_data)           : Run First



``hildoncalendar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendar-prev-month:

The ``prev-month`` signal

::

  void                user_function                      (HildonCalendar *hildoncalendar,
                                                          gpointer        user_data)           : Run First



``hildoncalendar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendar-prev-year:

The ``prev-year`` signal

::

  void                user_function                      (HildonCalendar *hildoncalendar,
                                                          gpointer        user_data)           : Run First



``hildoncalendar``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendar-selected-date:

The ``selected-date`` signal

::

  void                user_function                      (HildonCalendar *arg0,
                                                          gpointer        user_data)      : Run First

Emitted on button-release when the user has selected a date.



``user_data``:
  user data set when the signal handler was connected.


.. _HildonCalendarPopup:

HildonCalendarPopup
*******************

.. _HildonCalendarPopup.object-hierarchy:

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
                                               +----HildonCalendarPopup
  

.. _HildonCalendarPopup.implemented-interfaces:

Implemented Interfaces
======================

HildonCalendarPopup implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonCalendarPopup.properties:

Properties
==========

::

  
    day                      gint                  : Read / Write
    max-year                 guint                 : Write
    min-year                 guint                 : Write
    month                    gint                  : Read / Write
    year                     gint                  : Read / Write
  

.. _HildonCalendarPopup.description:

Description
===========

HildonCalendarPopup is a dialog which contains a HildonCalendar. It also contains arrow buttons for changing the month/year. If an entered date is invalid, an information message will be shown.

.. note:: `HildonCalendarPopup <HildonCalendarPopup>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. See `Migrating Date Widgets <hildon-migrating-date-widgets>`_ section to know how to migrate this deprecated widget.

HildonCalendarPopup example =========================== :: ... gint y, m, d; GtkWidget *parent, *popup; // get current date into y, m, d... gtk_widget_get_ancestor (GTK_WIDGET (data), GTK_TYPE_WINDOW); popup = hildon_calendar_popup_new (GTK_WINDOW (parent), y, m, d); result = gtk_dialog_run (GTK_DIALOG (popup)); switch (result) { case GTK_RESPONSE_OK: case GTK_RESPONSE_ACCEPT: hildon_calendar_popup_get_date (HILDON_CALENDAR_POPUP (popup), y, m, d); // here set the new date } gtk_widget_destroy(popup); ...



.. _HildonCalendarPopup.details:

Details
=======

.. _HildonCalendarPopup-struct:

.. class:: HildonCalendarPopup

::

  typedef struct _HildonCalendarPopup HildonCalendarPopup;

.. warning:: ``HildonCalendarPopup`` is deprecated and should not be used in newly-written code.



.. _hildon-calendar-popup-new:

.. function:: hildon_calendar_popup_new ()

::

  GtkWidget*          hildon_calendar_popup_new           (GtkWindow *parent,
                                                           guint year,
                                                           guint month,
                                                           guint day);

.. warning:: ``hildon_calendar_popup_new`` is deprecated and should not be used in newly-written code.

This function returns a new HildonCalendarPopup. The initially selected date is specified by the parameters (year, month, day). If the specified date is invalid, the current date is used.



``parent``:
  parent window for dialog


``year``:
  initial year


``month``:
  initial month


``day``:
  initial day


*Returns*:
  new ``HildonCalendarPopup`` widget


.. _hildon-calendar-popup-set-date:

.. function:: hildon_calendar_popup_set_date ()

::

  void                hildon_calendar_popup_set_date      (HildonCalendarPopup *cal,
                                                           guint year,
                                                           guint month,
                                                           guint day);

.. warning:: ``hildon_calendar_popup_set_date`` is deprecated and should not be used in newly-written code.

Activates a new date on the calendar popup.



``cal``:
  the ``HildonCalendarPopup`` widget


``year``:
  year


``month``:
  month


``day``:
  day


.. _hildon-calendar-popup-get-date:

.. function:: hildon_calendar_popup_get_date ()

::

  void                hildon_calendar_popup_get_date      (HildonCalendarPopup *cal,
                                                           guint *year,
                                                           guint *month,
                                                           guint *day);

.. warning:: ``hildon_calendar_popup_get_date`` is deprecated and should not be used in newly-written code.

Gets the currently selected year, month, and day. It's possible to pass NULL to any of the pointers if you don't need that data.



``cal``:
  the ``HildonCalendarPopup`` widget


``year``:
  year


``month``:
  month


``day``:
  day


.. _HildonCalendarPopup.property-details:

Property Details
================

.. _HildonCalendarPopup--day:

The ``day`` property

::

    day                      gint                  : Read / Write

currently selected day.

Default value: 0

.. _HildonCalendarPopup--max-year:

The ``max-year`` property

::

    max-year                 guint                 : Write

Maximum valid year.

Allowed values: [1,10000]

Default value: 2037

.. _HildonCalendarPopup--min-year:

The ``min-year`` property

::

    min-year                 guint                 : Write

Minimum valid year.

Allowed values: [1,10000]

Default value: 1970

.. _HildonCalendarPopup--month:

The ``month`` property

::

    month                    gint                  : Read / Write

currently selected month.

Default value: 0

.. _HildonCalendarPopup--year:

The ``year`` property

::

    year                     gint                  : Read / Write

the currently selected year.

Default value: 0

.. _HildonCalendarPopup.see-also:

See Also
========

`HildonDateEditor <HildonDateEditor>`_ `HildonTimeEditor <HildonTimeEditor>`_ .. _HildonWeekdayPicker:

HildonWeekdayPicker
*******************

.. _HildonWeekdayPicker.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----HildonWeekdayPicker
  

.. _HildonWeekdayPicker.implemented-interfaces:

Implemented Interfaces
======================

HildonWeekdayPicker implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonWeekdayPicker.signals:

Signals
=======

::

  
    selection-changed                              : Run Last / Action
  

.. _HildonWeekdayPicker.description:

Description
===========

`HildonWeekdayPicker <HildonWeekdayPicker>`_ supports non-mutually exclusive selection of days of the week. Selected days of the week are shown with a pushed-in effect.

`HildonWeekdayPicker <HildonWeekdayPicker>`_ is used where users are required to pick days on which a certain event should take place, for example, which days a Calendar event should be repeated on. It is used in Calendar in the Repeat dialog, in Tasks in the Repeat dialog and in the Email set-up wizard.

.. note:: `HildonWeekdayPicker <HildonWeekdayPicker>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. See `Migrating Date Widgets <hildon-migrating-date-widgets>`_ section to know how to migrate this deprecated widget.

HildonWeekdayPicker example =========================== :: gint i; HildonWeekdayPicker *picker = hildon_weekday_picker_new (); hildon_weekday_picker_set_day (picker, i); hildon_weekday_picker_unset_day (picker, i); hildon_weekday_picker_toggle_day (picker, i); hildon_weekday_picker_set_all (picker); hildon_weekday_picker_unset_all( picker );



.. _HildonWeekdayPicker.details:

Details
=======

.. _HildonWeekdayPicker-struct:

.. class:: HildonWeekdayPicker

::

  typedef struct _HildonWeekdayPicker HildonWeekdayPicker;

.. warning:: ``HildonWeekdayPicker`` is deprecated and should not be used in newly-written code.



.. _hildon-weekday-picker-new:

.. function:: hildon_weekday_picker_new ()

::

  GtkWidget*          hildon_weekday_picker_new           (void);

.. warning:: ``hildon_weekday_picker_new`` is deprecated and should not be used in newly-written code.

Creates a new `HildonWeekdayPicker <HildonWeekdayPicker>`_ .



*Returns*:
  pointer to a new `HildonWeekdayPicker <HildonWeekdayPicker>`_ widget.


.. _hildon-weekday-picker-set-day:

.. function:: hildon_weekday_picker_set_day ()

::

  void                hildon_weekday_picker_set_day       (HildonWeekdayPicker *picker,
                                                           GDateWeekday day);

.. warning:: ``hildon_weekday_picker_set_day`` is deprecated and should not be used in newly-written code.

Sets specified weekday active.



``picker``:
  the `HildonWeekdayPicker <HildonWeekdayPicker>`_ widget


``day``:
  day to be set active


.. _hildon-weekday-picker-unset-day:

.. function:: hildon_weekday_picker_unset_day ()

::

  void                hildon_weekday_picker_unset_day     (HildonWeekdayPicker *picker,
                                                           GDateWeekday day);

.. warning:: ``hildon_weekday_picker_unset_day`` is deprecated and should not be used in newly-written code.

Unselect specified weekday.



``picker``:
  the `HildonWeekdayPicker <HildonWeekdayPicker>`_ widget


``day``:
  day to be set inactive


.. _hildon-weekday-picker-toggle-day:

.. function:: hildon_weekday_picker_toggle_day ()

::

  void                hildon_weekday_picker_toggle_day    (HildonWeekdayPicker *picker,
                                                           GDateWeekday day);

.. warning:: ``hildon_weekday_picker_toggle_day`` is deprecated and should not be used in newly-written code.

Toggles current status of the specified weekday.



``picker``:
  the `HildonWeekdayPicker <HildonWeekdayPicker>`_ widget


``day``:
  day to be toggled


.. _hildon-weekday-picker-set-all:

.. function:: hildon_weekday_picker_set_all ()

::

  void                hildon_weekday_picker_set_all       (HildonWeekdayPicker *picker);

.. warning:: ``hildon_weekday_picker_set_all`` is deprecated and should not be used in newly-written code.

Sets all weekdays active.



``picker``:
  the `HildonWeekdayPicker <HildonWeekdayPicker>`_ widget


.. _hildon-weekday-picker-unset-all:

.. function:: hildon_weekday_picker_unset_all ()

::

  void                hildon_weekday_picker_unset_all     (HildonWeekdayPicker *picker);

.. warning:: ``hildon_weekday_picker_unset_all`` is deprecated and should not be used in newly-written code.

Sets all weekdays inactive.



``picker``:
  the `HildonWeekdayPicker <HildonWeekdayPicker>`_ widget


.. _hildon-weekday-picker-isset-day:

.. function:: hildon_weekday_picker_isset_day ()

::

  gboolean            hildon_weekday_picker_isset_day     (HildonWeekdayPicker *picker,
                                                           GDateWeekday day);

.. warning:: ``hildon_weekday_picker_isset_day`` is deprecated and should not be used in newly-written code.

Checks if the specified weekday is set active.



``picker``:
  the `HildonWeekdayPicker <HildonWeekdayPicker>`_ widget


``day``:
  day to be checked.


*Returns*:
  TRUE if the day is set, FALSE if the day is not set


.. _HildonWeekdayPicker.signal-details:

Signal Details
==============

.. _HildonWeekdayPicker-selection-changed:

The ``selection-changed`` signal

::

  void                user_function                      (HildonWeekdayPicker *hildonweekdaypicker,
                                                          gint                 arg1,
                                                          gpointer             user_data)                : Run Last / Action



``hildonweekdaypicker``:
  the object which received the signal.


``arg1``:
  


``user_data``:
  user data set when the signal handler was connected.


.. _HildonWeekdayPicker.see-also:

See Also
========

`HildonWeekdayPicker <HildonWeekdayPicker>`_ .. _HildonTimePicker:

HildonTimePicker
****************

.. _HildonTimePicker.object-hierarchy:

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
                                               +----HildonTimePicker
  

.. _HildonTimePicker.implemented-interfaces:

Implemented Interfaces
======================

HildonTimePicker implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonTimePicker.properties:

Properties
==========

::

  
    minutes                  guint                 : Read / Write
  

.. _HildonTimePicker.style-properties:

Style Properties
================

::

  
    arrow-height             guint                 : Read
    arrow-width              guint                 : Read
  

.. _HildonTimePicker.description:

Description
===========

`HildonTimePicker <HildonTimePicker>`_ is a dialog popup widget which lets the user set the time, using up/down arrows on hours and minutes. There are two arrows for minutes, so that minutes can be added also in 10 min increments.This widget is mainly used as a part of `HildonTimeEditor <HildonTimeEditor>`_ implementation.

.. note:: `HildonTimePicker <HildonTimePicker>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. See `Migrating Time Widgets <hildon-migrating-time-widgets>`_ section to know how to migrate this deprecated widget.

HildonTimePicker example ======================== :: parent = gtk_widget_get_ancestor (GTK_WIDGET (editor), GTK_TYPE_WINDOW); picker = hildon_time_picker_new (GTK_WINDOW (parent)); hildon_time_editor_get_time (editor, h, m, s); hildon_time_picker_set_time( HILDON_TIME_PICKER( picker ), h, m ); result = gtk_dialog_run (GTK_DIALOG (picker)); switch (result) { case GTK_RESPONSE_OK: case GTK_RESPONSE_ACCEPT: hildon_time_picker_get_time(HILDON_TIME_PICKER (picker), h, m ); foo_set_time(h,m); break; default: break; } gtk_widget_destroy( picker );



.. _HildonTimePicker.details:

Details
=======

.. _HildonTimePicker-struct:

.. class:: HildonTimePicker

::

  typedef struct _HildonTimePicker HildonTimePicker;

.. warning:: ``HildonTimePicker`` is deprecated and should not be used in newly-written code.



.. _hildon-time-picker-new:

.. function:: hildon_time_picker_new ()

::

  GtkWidget*          hildon_time_picker_new              (GtkWindow *parent);

.. warning:: ``hildon_time_picker_new`` is deprecated and should not be used in newly-written code.

`HildonTimePicker <HildonTimePicker>`_ shows time picker dialog. The close button is placed in the dialog's action area and time picker is placed in dialogs vbox. The actual time picker consists of two `GtkLabel <GtkLabel>`_ fields - one for hours and one for minutes - and an AM/PM button. A colon (:) is placed between hour and minute fields.



``parent``:
  parent window


*Returns*:
  pointer to a new `HildonTimePicker <HildonTimePicker>`_ widget.


.. _hildon-time-picker-set-time:

.. function:: hildon_time_picker_set_time ()

::

  void                hildon_time_picker_set_time         (HildonTimePicker *picker,
                                                           guint hours,
                                                           guint minutes);

.. warning:: ``hildon_time_picker_set_time`` is deprecated and should not be used in newly-written code.

Sets the time of the `HildonTimePicker <HildonTimePicker>`_ widget.



``picker``:
  the `HildonTimePicker <HildonTimePicker>`_ widget


``hours``:
  hours


``minutes``:
  minutes


.. _hildon-time-picker-get-time:

.. function:: hildon_time_picker_get_time ()

::

  void                hildon_time_picker_get_time         (HildonTimePicker *picker,
                                                           guint *hours,
                                                           guint *minutes);

.. warning:: ``hildon_time_picker_get_time`` is deprecated and should not be used in newly-written code.

Gets the time of the `HildonTimePicker <HildonTimePicker>`_ widget.



``picker``:
  the `HildonTimePicker <HildonTimePicker>`_ widget


``hours``:
  hours


``minutes``:
  minutes


.. _HildonTimePicker.property-details:

Property Details
================

.. _HildonTimePicker--minutes:

The ``minutes`` property

::

    minutes                  guint                 : Read / Write

Currently selected time in minutes since midnight.



Allowed values: = 1440

Default value: 0

.. _HildonTimePicker.style-property-details:

Style Property Details
======================

.. _HildonTimePicker--arrow-height:

The ``arrow-height`` style property

::

    arrow-height             guint                 : Read

Increase/decrease arrows height.

Default value: 26

.. _HildonTimePicker--arrow-width:

The ``arrow-width`` style property

::

    arrow-width              guint                 : Read

Increase/decrease arrows width.

Default value: 26

.. _HildonTimePicker.see-also:

See Also
========

`HildonTimeEditor <HildonTimeEditor>`_ .. _HildonNumberEditor:

HildonNumberEditor
******************

.. _HildonNumberEditor.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----HildonNumberEditor
  

.. _HildonNumberEditor.implemented-interfaces:

Implemented Interfaces
======================

HildonNumberEditor implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonNumberEditor.properties:

Properties
==========

::

  
    value                    gint                  : Read / Write
  

.. _HildonNumberEditor.signals:

Signals
=======

::

  
    range-error                                    : Run Last
  

.. _HildonNumberEditor.description:

Description
===========

HildonNumberEditor is used to enter a number from a specific range. There are two buttons to scroll the value in number field. Manual input is also possible.

.. note:: `HildonNumberEditor <HildonNumberEditor>`_ has been deprecated since Hildon 2.2 See `Migrating Number Widgets <hildon-migrating-number-widgets>`_ section to know how to migrate this deprecated widget.

HildonNumberEditor example ========================== :: number_editor = hildon_number_editor_new (-250, 500); hildon_number_editor_set_range (number_editor, 0, 100);



.. _HildonNumberEditor.details:

Details
=======

.. _HildonNumberEditorErrorType:

.. :: enum HildonNumberEditorErrorType

::

  typedef enum
  {
      HILDON_NUMBER_EDITOR_ERROR_MAXIMUM_VALUE_EXCEED,
      HILDON_NUMBER_EDITOR_ERROR_MINIMUM_VALUE_EXCEED,
      HILDON_NUMBER_EDITOR_ERROR_ERRONEOUS_VALUE
  }                                               HildonNumberEditorErrorType;
  

.. warning:: ``HildonNumberEditorErrorType`` is deprecated and should not be used in newly-written code.



.. _HildonNumberEditor-struct:

.. class:: HildonNumberEditor

::

  typedef struct _HildonNumberEditor HildonNumberEditor;

.. warning:: ``HildonNumberEditor`` is deprecated and should not be used in newly-written code.



.. _hildon-number-editor-new:

.. function:: hildon_number_editor_new ()

::

  GtkWidget*          hildon_number_editor_new            (gint min,
                                                           gint max);

.. warning:: ``hildon_number_editor_new`` is deprecated and should not be used in newly-written code.

Creates new number editor



``min``:
  minimum accepted value


``max``:
  maximum accepted value


*Returns*:
  a new `HildonNumberEditor <HildonNumberEditor>`_ widget


.. _hildon-number-editor-set-range:

.. function:: hildon_number_editor_set_range ()

::

  void                hildon_number_editor_set_range      (HildonNumberEditor *editor,
                                                           gint min,
                                                           gint max);

.. warning:: ``hildon_number_editor_set_range`` is deprecated and should not be used in newly-written code.

Sets accepted number range for editor



``editor``:
  a `HildonNumberEditor <HildonNumberEditor>`_ widget


``min``:
  minimum accepted value


``max``:
  maximum accepted value


.. _hildon-number-editor-get-value:

.. function:: hildon_number_editor_get_value ()

::

  gint                hildon_number_editor_get_value      (HildonNumberEditor *editor);

.. warning:: ``hildon_number_editor_get_value`` is deprecated and should not be used in newly-written code.





``editor``:
  pointer to `HildonNumberEditor <HildonNumberEditor>`_


*Returns*:
  current NumberEditor value


.. _hildon-number-editor-set-value:

.. function:: hildon_number_editor_set_value ()

::

  void                hildon_number_editor_set_value      (HildonNumberEditor *editor,
                                                           gint value);

.. warning:: ``hildon_number_editor_set_value`` is deprecated and should not be used in newly-written code.

Sets numeric value for number editor



``editor``:
  pointer to `HildonNumberEditor <HildonNumberEditor>`_


``value``:
  numeric value for number editor


.. _HildonNumberEditor.property-details:

Property Details
================

.. _HildonNumberEditor--value:

The ``value`` property

::

    value                    gint                  : Read / Write

The current value of the number editor.



Default value: 0

.. _HildonNumberEditor.signal-details:

Signal Details
==============

.. _HildonNumberEditor-range-error:

The ``range-error`` signal

::

  gboolean            user_function                      (HildonNumberEditor         *hildonnumbereditor,
                                                          HildonNumberEditorErrorType arg1,
                                                          gpointer                    user_data)               : Run Last



``hildonnumbereditor``:
  the object which received the signal.


``arg1``:
  


``user_data``:
  user data set when the signal handler was connected.


*Returns*:
  


.. _HildonRangeEditor:

HildonRangeEditor
*****************

.. _HildonRangeEditor.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----HildonRangeEditor
  

.. _HildonRangeEditor.implemented-interfaces:

Implemented Interfaces
======================

HildonRangeEditor implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonRangeEditor.properties:

Properties
==========

::

  
    higher                   gint                  : Read / Write / Construct
    lower                    gint                  : Read / Write / Construct
    max                      gint                  : Read / Write / Construct
    min                      gint                  : Read / Write / Construct
    separator                gchar*                : Read / Write / Construct
  

.. _HildonRangeEditor.style-properties:

Style Properties
================

::

  
    hildon-range-editor-entry-alignment gint                  : Read
    hildon-range-editor-separator-padding gint                  : Read
  

.. _HildonRangeEditor.description:

Description
===========

HidlonRangeEditor allows entering a pair of integers, e.g. the lower and higher bounds of a range. A minimum and maximum can also be set for the bounds.

.. note:: `HildonRangeEditor <HildonRangeEditor>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. See `Migrating Number Widgets <hildon-migrating-number-widgets>`_ section to know how to migrate this deprecated widget.

:: range_editor = hildon_range_editor_new (); hildon_range_editor_set_limits (editor, start, end ); hildon_range_editor_get_range (editor, start, end);



.. _HildonRangeEditor.details:

Details
=======

.. _HildonRangeEditor-struct:

.. class:: HildonRangeEditor

::

  typedef struct _HildonRangeEditor HildonRangeEditor;

.. warning:: ``HildonRangeEditor`` is deprecated and should not be used in newly-written code.



.. _hildon-range-editor-new-with-separator:

.. function:: hildon_range_editor_new_with_separator ()

::

  GtkWidget*          hildon_range_editor_new_with_separator
                                                          (const gchar *separator);

.. warning:: ``hildon_range_editor_new_with_separator`` is deprecated and should not be used in newly-written code.

HildonRangeEditor contains two Gtk entries that accept numbers. A separator is displayed between two entries. CHECKME: Use '-' as a separator in the case of null separator?



``separator``:
  a string that is shown between the numbers


*Returns*:
  pointer to a new ``HildonRangeEditor`` widget


.. _hildon-range-editor-new:

.. function:: hildon_range_editor_new ()

::

  GtkWidget*          hildon_range_editor_new             (void);

.. warning:: ``hildon_range_editor_new`` is deprecated and should not be used in newly-written code.

HildonRangeEditor contains two GtkEntrys that accept numbers and minus.



*Returns*:
  pointer to a new ``HildonRangeEditor`` widget


.. _hildon-range-editor-set-range:

.. function:: hildon_range_editor_set_range ()

::

  void                hildon_range_editor_set_range       (HildonRangeEditor *editor,
                                                           gint start,
                                                           gint end);

.. warning:: ``hildon_range_editor_set_range`` is deprecated and should not be used in newly-written code.

Sets a range to the editor. (The current value)

Sets the range of the ``HildonRangeEditor`` widget.



``editor``:
  the `HildonRangeEditor <HildonRangeEditor>`_ widget


``start``:
  range's start value


``end``:
  range's end value


.. _hildon-range-editor-get-range:

.. function:: hildon_range_editor_get_range ()

::

  void                hildon_range_editor_get_range       (HildonRangeEditor *editor,
                                                           gint *start,
                                                           gint *end);

.. warning:: ``hildon_range_editor_get_range`` is deprecated and should not be used in newly-written code.

Gets the range of the ``HildonRangeEditor`` widget.



``editor``:
  the `HildonRangeEditor <HildonRangeEditor>`_ widget


``start``:
  ranges start value


``end``:
  ranges end value


.. _hildon-range-editor-set-limits:

.. function:: hildon_range_editor_set_limits ()

::

  void                hildon_range_editor_set_limits      (HildonRangeEditor *editor,
                                                           gint start,
                                                           gint end);

.. warning:: ``hildon_range_editor_set_limits`` is deprecated and should not be used in newly-written code.

Sets the range of the ``HildonRangeEditor`` widget.



``editor``:
  the `HildonRangeEditor <HildonRangeEditor>`_ widget


``start``:
  minimum acceptable value (default: no limit)


``end``:
  maximum acceptable value (default: no limit)


.. _hildon-range-editor-set-lower:

.. function:: hildon_range_editor_set_lower ()

::

  void                hildon_range_editor_set_lower       (HildonRangeEditor *editor,
                                                           gint value);

.. warning:: ``hildon_range_editor_set_lower`` is deprecated and should not be used in newly-written code.



``editor``:
  


``value``:
  


.. _hildon-range-editor-set-higher:

.. function:: hildon_range_editor_set_higher ()

::

  void                hildon_range_editor_set_higher      (HildonRangeEditor *editor,
                                                           gint value);

.. warning:: ``hildon_range_editor_set_higher`` is deprecated and should not be used in newly-written code.



``editor``:
  


``value``:
  


.. _hildon-range-editor-get-lower:

.. function:: hildon_range_editor_get_lower ()

::

  gint                hildon_range_editor_get_lower       (HildonRangeEditor *editor);

.. warning:: ``hildon_range_editor_get_lower`` is deprecated and should not be used in newly-written code.



``editor``:
  


*Returns*:
  


.. _hildon-range-editor-get-higher:

.. function:: hildon_range_editor_get_higher ()

::

  gint                hildon_range_editor_get_higher      (HildonRangeEditor *editor);

.. warning:: ``hildon_range_editor_get_higher`` is deprecated and should not be used in newly-written code.



``editor``:
  


*Returns*:
  


.. _hildon-range-editor-set-min:

.. function:: hildon_range_editor_set_min ()

::

  void                hildon_range_editor_set_min         (HildonRangeEditor *editor,
                                                           gint value);

.. warning:: ``hildon_range_editor_set_min`` is deprecated and should not be used in newly-written code.



``editor``:
  


``value``:
  


.. _hildon-range-editor-set-max:

.. function:: hildon_range_editor_set_max ()

::

  void                hildon_range_editor_set_max         (HildonRangeEditor *editor,
                                                           gint value);

.. warning:: ``hildon_range_editor_set_max`` is deprecated and should not be used in newly-written code.



``editor``:
  


``value``:
  


.. _hildon-range-editor-get-min:

.. function:: hildon_range_editor_get_min ()

::

  gint                hildon_range_editor_get_min         (HildonRangeEditor *editor);

.. warning:: ``hildon_range_editor_get_min`` is deprecated and should not be used in newly-written code.



``editor``:
  


*Returns*:
  


.. _hildon-range-editor-get-max:

.. function:: hildon_range_editor_get_max ()

::

  gint                hildon_range_editor_get_max         (HildonRangeEditor *editor);

.. warning:: ``hildon_range_editor_get_max`` is deprecated and should not be used in newly-written code.



``editor``:
  


*Returns*:
  


.. _hildon-range-editor-set-separator:

.. function:: hildon_range_editor_set_separator ()

::

  void                hildon_range_editor_set_separator   (HildonRangeEditor *editor,
                                                           const gchar *separator);

.. warning:: ``hildon_range_editor_set_separator`` is deprecated and should not be used in newly-written code.



``editor``:
  


``separator``:
  


.. _hildon-range-editor-get-separator:

.. function:: hildon_range_editor_get_separator ()

::

  const gchar*        hildon_range_editor_get_separator   (HildonRangeEditor *editor);

.. warning:: ``hildon_range_editor_get_separator`` is deprecated and should not be used in newly-written code.



``editor``:
  


*Returns*:
  


.. _HildonRangeEditor.property-details:

Property Details
================

.. _HildonRangeEditor--higher:

The ``higher`` property

::

    higher                   gint                  : Read / Write / Construct

Current value in the entry presenting higher end of selected range. Default: 999



Default value: 999

.. _HildonRangeEditor--lower:

The ``lower`` property

::

    lower                    gint                  : Read / Write / Construct

Current value in the entry presenting lower end of selected range. Default: -999



Default value: -999

.. _HildonRangeEditor--max:

The ``max`` property

::

    max                      gint                  : Read / Write / Construct

Maximum value in a range. Default: 999



Default value: 999

.. _HildonRangeEditor--min:

The ``min`` property

::

    min                      gint                  : Read / Write / Construct

Minimum value in a range. Default: -999



Default value: -999

.. _HildonRangeEditor--separator:

The ``separator`` property

::

    separator                gchar*                : Read / Write / Construct

Separator string to separate range editor entries. Default: "-"



Default value: "ckct_wi_range_separator"

.. _HildonRangeEditor.style-property-details:

Style Property Details
======================

.. _HildonRangeEditor--hildon-range-editor-entry-alignment:

The ``hildon-range-editor-entry-alignment`` style property

::

    hildon-range-editor-entry-alignment gint                  : Read

Hildon RangeEditor entry alignment.

Allowed values: [0,1]

Default value: 1

.. _HildonRangeEditor--hildon-range-editor-separator-padding:

The ``hildon-range-editor-separator-padding`` style property

::

    hildon-range-editor-separator-padding gint                  : Read

Hildon RangeEditor separaror padding.

Default value: 3

.. _HildonTimeEditor:

HildonTimeEditor
****************

.. _HildonTimeEditor.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----HildonTimeEditor
  

.. _HildonTimeEditor.implemented-interfaces:

Implemented Interfaces
======================

HildonTimeEditor implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonTimeEditor.properties:

Properties
==========

::

  
    duration-max             guint                 : Read / Write
    duration-min             guint                 : Read / Write
    duration-mode            gboolean              : Read / Write
    show-hours               gboolean              : Read / Write
    show-seconds             gboolean              : Read / Write
    ticks                    guint                 : Read / Write
  

.. _HildonTimeEditor.signals:

Signals
=======

::

  
    time-error                                     : Run Last
  

.. _HildonTimeEditor.description:

Description
===========

HildonTimeEditor is used to edit time or duration. Time mode is restricted to normal 24 hour cycle, but Duration mode can select any amount of time up to 99 hours. It consists of entries for hours, minutes and seconds, and pm/am indicator as well as a button which popups a `HildonTimePicker <HildonTimePicker>`_ dialog.

.. note:: `HildonTimeEditor <HildonTimeEditor>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. See `Migrating Time Widgets <hildon-migrating-time-widgets>`_ section to know how to migrate this deprecated widget.

HildonTimePicker example ======================== :: editor = hildon_time_editor_new (); hildon_time_editor_set_time (editor, h, m, s); gtk_box_pack_start (..., editor) hildon_time_editor_get_time (editor, h, m, s);



.. _HildonTimeEditor.details:

Details
=======

.. _HildonDateTimeError:

.. :: enum HildonDateTimeError

::

  typedef enum 
  {
      HILDON_DATE_TIME_ERROR_NO_ERROR = -1,
      HILDON_DATE_TIME_ERROR_MAX_HOURS,
      HILDON_DATE_TIME_ERROR_MAX_MINS,
      HILDON_DATE_TIME_ERROR_MAX_SECS,
      HILDON_DATE_TIME_ERROR_MAX_DAY,
      HILDON_DATE_TIME_ERROR_MAX_MONTH,
      HILDON_DATE_TIME_ERROR_MAX_YEAR,
      HILDON_DATE_TIME_ERROR_MIN_HOURS,
      HILDON_DATE_TIME_ERROR_MIN_MINS,
      HILDON_DATE_TIME_ERROR_MIN_SECS,
      HILDON_DATE_TIME_ERROR_MIN_DAY,
      HILDON_DATE_TIME_ERROR_MIN_MONTH,
      HILDON_DATE_TIME_ERROR_MIN_YEAR,
      HILDON_DATE_TIME_ERROR_EMPTY_HOURS,
      HILDON_DATE_TIME_ERROR_EMPTY_MINS,
      HILDON_DATE_TIME_ERROR_EMPTY_SECS,
      HILDON_DATE_TIME_ERROR_EMPTY_DAY,
      HILDON_DATE_TIME_ERROR_EMPTY_MONTH,
      HILDON_DATE_TIME_ERROR_EMPTY_YEAR,
      HILDON_DATE_TIME_ERROR_MIN_DURATION,
      HILDON_DATE_TIME_ERROR_MAX_DURATION,
      HILDON_DATE_TIME_ERROR_INVALID_CHAR,
      HILDON_DATE_TIME_ERROR_INVALID_DATE,
      HILDON_DATE_TIME_ERROR_INVALID_TIME
  }                                               HildonDateTimeError;
  

.. warning:: ``HildonDateTimeError`` is deprecated and should not be used in newly-written code.



.. _HildonTimeEditor-struct:

.. class:: HildonTimeEditor

::

  typedef struct _HildonTimeEditor HildonTimeEditor;

.. warning:: ``HildonTimeEditor`` is deprecated and should not be used in newly-written code.



.. _hildon-time-editor-new:

.. function:: hildon_time_editor_new ()

::

  GtkWidget*          hildon_time_editor_new              (void);

.. warning:: ``hildon_time_editor_new`` is deprecated and should not be used in newly-written code.

This function creates a new time editor.



*Returns*:
  pointer to a new `HildonTimeEditor <HildonTimeEditor>`_ widget


.. _hildon-time-editor-set-time:

.. function:: hildon_time_editor_set_time ()

::

  void                hildon_time_editor_set_time         (HildonTimeEditor *editor,
                                                           guint hours,
                                                           guint minutes,
                                                           guint seconds);

.. warning:: ``hildon_time_editor_set_time`` is deprecated and should not be used in newly-written code.

This function sets the time on an existing time editor. If the time specified by the arguments is invalid, it's fixed. The time is assumed to be in 24h format.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


``hours``:
  hours


``minutes``:
  minutes


``seconds``:
  seconds


.. _hildon-time-editor-get-time:

.. function:: hildon_time_editor_get_time ()

::

  void                hildon_time_editor_get_time         (HildonTimeEditor *editor,
                                                           guint *hours,
                                                           guint *minutes,
                                                           guint *seconds);

.. warning:: ``hildon_time_editor_get_time`` is deprecated and should not be used in newly-written code.

Gets the time of the `HildonTimeEditor <HildonTimeEditor>`_ widget. The time returned is always in 24h format.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


``hours``:
  hours


``minutes``:
  minutes


``seconds``:
  seconds


.. _hildon-time-editor-set-duration-range:

.. function:: hildon_time_editor_set_duration_range ()

::

  void                hildon_time_editor_set_duration_range
                                                          (HildonTimeEditor *editor,
                                                           guint min_seconds,
                                                           guint max_seconds);

.. warning:: ``hildon_time_editor_set_duration_range`` is deprecated and should not be used in newly-written code.

Sets the duration editor time range of the `HildonTimeEditor <HildonTimeEditor>`_ widget.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


``min_seconds``:
  minimum allowed time in seconds


``max_seconds``:
  maximum allowed time in seconds


.. _hildon-time-editor-get-duration-range:

.. function:: hildon_time_editor_get_duration_range ()

::

  void                hildon_time_editor_get_duration_range
                                                          (HildonTimeEditor *editor,
                                                           guint *min_seconds,
                                                           guint *max_seconds);

.. warning:: ``hildon_time_editor_get_duration_range`` is deprecated and should not be used in newly-written code.

Gets the duration editor time range of the `HildonTimeEditor <HildonTimeEditor>`_ widget.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


``min_seconds``:
  pointer to guint


``max_seconds``:
  pointer to guint


.. _hildon-time-editor-set-ticks:

.. function:: hildon_time_editor_set_ticks ()

::

  void                hildon_time_editor_set_ticks        (HildonTimeEditor *editor,
                                                           guint ticks);

.. warning:: ``hildon_time_editor_set_ticks`` is deprecated and should not be used in newly-written code.

Sets the current duration in seconds. This means seconds from midnight, if not in duration mode. In case of any errors, it tries to fix it.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


``ticks``:
  the duration to set, in seconds


.. _hildon-time-editor-get-ticks:

.. function:: hildon_time_editor_get_ticks ()

::

  guint               hildon_time_editor_get_ticks        (HildonTimeEditor *editor);

.. warning:: ``hildon_time_editor_get_ticks`` is deprecated and should not be used in newly-written code.

This function returns the current duration, in seconds. This means seconds from midnight, if not in duration mode.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


*Returns*:
  current duration in seconds


.. _hildon-time-editor-set-show-seconds:

.. function:: hildon_time_editor_set_show_seconds ()

::

  void                hildon_time_editor_set_show_seconds (HildonTimeEditor *editor,
                                                           gboolean show_seconds);

.. warning:: ``hildon_time_editor_set_show_seconds`` is deprecated and should not be used in newly-written code.

This function shows or hides the seconds field.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_


``show_seconds``:
  enable or disable showing of seconds


.. _hildon-time-editor-get-show-seconds:

.. function:: hildon_time_editor_get_show_seconds ()

::

  gboolean            hildon_time_editor_get_show_seconds (HildonTimeEditor *editor);

.. warning:: ``hildon_time_editor_get_show_seconds`` is deprecated and should not be used in newly-written code.

This function returns a boolean indicating the visibility of seconds in the `HildonTimeEditor <HildonTimeEditor>`_



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


*Returns*:
  TRUE if the seconds are visible


.. _hildon-time-editor-set-show-hours:

.. function:: hildon_time_editor_set_show_hours ()

::

  void                hildon_time_editor_set_show_hours   (HildonTimeEditor *editor,
                                                           gboolean show_hours);

.. warning:: ``hildon_time_editor_set_show_hours`` is deprecated and should not be used in newly-written code.

This function shows or hides the hours field.



``editor``:
  The `HildonTimeEditor <HildonTimeEditor>`_ .


``show_hours``:
  Enable or disable showing of hours.


.. _hildon-time-editor-get-show-hours:

.. function:: hildon_time_editor_get_show_hours ()

::

  gboolean            hildon_time_editor_get_show_hours   (HildonTimeEditor *editor);

.. warning:: ``hildon_time_editor_get_show_hours`` is deprecated and should not be used in newly-written code.

This function returns a boolean indicating the visibility of hours in the ``HildonTimeEditor``



``editor``:
  the ``HildonTimeEditor`` widget.


*Returns*:
  TRUE if hours are visible.


.. _hildon-time-editor-set-duration-mode:

.. function:: hildon_time_editor_set_duration_mode ()

::

  void                hildon_time_editor_set_duration_mode
                                                          (HildonTimeEditor *editor,
                                                           gboolean duration_mode);

.. warning:: ``hildon_time_editor_set_duration_mode`` is deprecated and should not be used in newly-written code.

This function sets the duration editor mode in which the maximum hours is 99.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_


``duration_mode``:
  enable or disable duration editor mode


.. _hildon-time-editor-get-duration-mode:

.. function:: hildon_time_editor_get_duration_mode ()

::

  gboolean            hildon_time_editor_get_duration_mode
                                                          (HildonTimeEditor *editor);

.. warning:: ``hildon_time_editor_get_duration_mode`` is deprecated and should not be used in newly-written code.

This function returns a boolean indicating whether the `HildonTimeEditor <HildonTimeEditor>`_ is in the duration mode.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


*Returns*:
  TRUE if the `HildonTimeEditor <HildonTimeEditor>`_ is in duration mode


.. _hildon-time-editor-set-duration-min:

.. function:: hildon_time_editor_set_duration_min ()

::

  void                hildon_time_editor_set_duration_min (HildonTimeEditor *editor,
                                                           guint duration_min);

.. warning:: ``hildon_time_editor_set_duration_min`` is deprecated and should not be used in newly-written code.

Sets the minimum allowed duration for the duration mode. Note: Has no effect in time mode



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


``duration_min``:
  mimimum allowed duration


.. _hildon-time-editor-get-duration-min:

.. function:: hildon_time_editor_get_duration_min ()

::

  guint               hildon_time_editor_get_duration_min (HildonTimeEditor *editor);

.. warning:: ``hildon_time_editor_get_duration_min`` is deprecated and should not be used in newly-written code.

This function returns the smallest duration the `HildonTimeEditor <HildonTimeEditor>`_ allows in the duration mode.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


*Returns*:
  minimum allowed duration in seconds


.. _hildon-time-editor-set-duration-max:

.. function:: hildon_time_editor_set_duration_max ()

::

  void                hildon_time_editor_set_duration_max (HildonTimeEditor *editor,
                                                           guint duration_max);

.. warning:: ``hildon_time_editor_set_duration_max`` is deprecated and should not be used in newly-written code.

Sets the maximum allowed duration in seconds for the duration mode. Note: Has no effect in time mode



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


``duration_max``:
  maximum allowed duration in seconds


.. _hildon-time-editor-get-duration-max:

.. function:: hildon_time_editor_get_duration_max ()

::

  guint               hildon_time_editor_get_duration_max (HildonTimeEditor *editor);

.. warning:: ``hildon_time_editor_get_duration_max`` is deprecated and should not be used in newly-written code.

This function returns the longest duration the `HildonTimeEditor <HildonTimeEditor>`_ allows in the duration mode.



``editor``:
  the `HildonTimeEditor <HildonTimeEditor>`_ widget


*Returns*:
  maximum allowed duration in seconds


.. _hildon-time-editor-get-time-separators:

.. function:: hildon_time_editor_get_time_separators ()

::

  void                hildon_time_editor_get_time_separators
                                                          (GtkLabel *hm_sep_label,
                                                           GtkLabel *ms_sep_label);

.. warning:: ``hildon_time_editor_get_time_separators`` is deprecated and should not be used in newly-written code.

Gets hour-minute separator and minute-second separator from current locale and sets then to the labels we set as parameters. Both parameters can be NULL if you just want to assing one separator.



``hm_sep_label``:
  the label that will show the hour:minutes separator


``ms_sep_label``:
  the label that will show the minutes:seconds separator


.. _HildonTimeEditor.property-details:

Property Details
================

.. _HildonTimeEditor--duration-max:

The ``duration-max`` property

::

    duration-max             guint                 : Read / Write

Largest possible duration value.

Default value: 359999

.. _HildonTimeEditor--duration-min:

The ``duration-min`` property

::

    duration-min             guint                 : Read / Write

Smallest possible duration value.

Allowed values: = 359999

Default value: 0

.. _HildonTimeEditor--duration-mode:

The ``duration-mode`` property

::

    duration-mode            gboolean              : Read / Write

Controls whether the TimeEditor is in duration mode.

Default value: FALSE

.. _HildonTimeEditor--show-hours:

The ``show-hours`` property

::

    show-hours               gboolean              : Read / Write

Controls whether the hours field is shown in the editor.

Default value: TRUE

.. _HildonTimeEditor--show-seconds:

The ``show-seconds`` property

::

    show-seconds             gboolean              : Read / Write

Controls whether the seconds are shown in the editor.

Default value: FALSE

.. _HildonTimeEditor--ticks:

The ``ticks`` property

::

    ticks                    guint                 : Read / Write

If editor is in duration mode, contains the duration seconds. If not, contains seconds since midnight.



Default value: 0

.. _HildonTimeEditor.signal-details:

Signal Details
==============

.. _HildonTimeEditor-time-error:

The ``time-error`` signal

::

  gboolean            user_function                      (HildonTimeEditor   *hildontimeeditor,
                                                          HildonDateTimeError arg1,
                                                          gpointer            user_data)             : Run Last



``hildontimeeditor``:
  the object which received the signal.


``arg1``:
  


``user_data``:
  user data set when the signal handler was connected.


*Returns*:
  


.. _HildonTimeEditor.see-also:

See Also
========

`HildonTimePicker <HildonTimePicker>`_ .. _HildonDateEditor:

HildonDateEditor
****************

.. _HildonDateEditor.object-hierarchy:

Object Hierarchy
================

::

  
    GObject
     +----GInitiallyUnowned
           +----GtkObject
                 +----GtkWidget
                       +----GtkContainer
                             +----HildonDateEditor
  

.. _HildonDateEditor.implemented-interfaces:

Implemented Interfaces
======================

HildonDateEditor implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonDateEditor.properties:

Properties
==========

::

  
    day                      guint                 : Read / Write
    max-year                 guint                 : Read / Write
    min-year                 guint                 : Read / Write
    month                    guint                 : Read / Write
    year                     guint                 : Read / Write
  

.. _HildonDateEditor.signals:

Signals
=======

::

  
    date-error                                     : Run Last
  

.. _HildonDateEditor.description:

Description
===========

HildonDateEditor is a widget with three entry fields (day, month, year) and an icon (button): clicking on the icon opens up a HildonCalendarPopup.

.. note:: `HildonDateEditor <HildonDateEditor>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. Use `HildonDateSelector <HildonDateSelector>`_ instead. See `Migrating Date Widgets <hildon-migrating-date-widgets>`_ section to know how to migrate this deprecated widget.

:: guint y, m, d; GtkDialog *dialog; GtkWidget *date_editor; dialog = GTK_DIALOG (gtk_dialog_new ()); date_editor = hildon_date_editor_new (); gtk_box_pack_start (GTK_BOX (dialog->vbox), gtk_label_new ("Choose a date"), FALSE, FALSE, 10); gtk_box_pack_start (GTK_BOX (dialog->vbox), date_editor, FALSE, FALSE, 10); gtk_dialog_add_button (dialog, "Close", GTK_RESPONSE_CANCEL); gtk_widget_show_all (GTK_WIDGET (dialog)); gtk_dialog_run (dialog); hildon_date_editor_get_date (HILDON_DATE_EDITOR (date_editor), y, m, d); g_debug ("Date: u-u-u", y, m, d);



.. _HildonDateEditor.details:

Details
=======

.. _HildonDateEditor-struct:

.. class:: HildonDateEditor

::

  typedef struct _HildonDateEditor HildonDateEditor;

.. warning:: ``HildonDateEditor`` is deprecated and should not be used in newly-written code.



.. _hildon-date-editor-new:

.. function:: hildon_date_editor_new ()

::

  GtkWidget*          hildon_date_editor_new              (void);

.. warning:: ``hildon_date_editor_new`` is deprecated and should not be used in newly-written code.

Creates a new date editor. The current system date is shown in the editor.



*Returns*:
  pointer to a new ``HildonDateEditor`` widget.


.. _hildon-date-editor-set-date:

.. function:: hildon_date_editor_set_date ()

::

  void                hildon_date_editor_set_date         (HildonDateEditor *date,
                                                           guint year,
                                                           guint month,
                                                           guint day);

.. warning:: ``hildon_date_editor_set_date`` is deprecated and should not be used in newly-written code.

Sets the date shown in the editor.



``date``:
  the ``HildonDateEditor`` widget


``year``:
  year


``month``:
  month


``day``:
  day


.. _hildon-date-editor-get-date:

.. function:: hildon_date_editor_get_date ()

::

  void                hildon_date_editor_get_date         (HildonDateEditor *date,
                                                           guint *year,
                                                           guint *month,
                                                           guint *day);

.. warning:: ``hildon_date_editor_get_date`` is deprecated and should not be used in newly-written code.

Gets the date represented by the date editor. You can pass NULL to any of the pointers if you're not interested in obtaining it.



``date``:
  the ``HildonDateEditor`` widget


``year``:
  year


``month``:
  month


``day``:
  day


.. _hildon-date-editor-set-year:

.. function:: hildon_date_editor_set_year ()

::

  gboolean            hildon_date_editor_set_year         (HildonDateEditor *editor,
                                                           guint year);

.. warning:: ``hildon_date_editor_set_year`` is deprecated and should not be used in newly-written code.

Sets the year shown in the editor.



``editor``:
  the ``HildonDateEditor`` widget


``year``:
  year


*Returns*:
  TRUE if the year is valid and has been set.


.. _hildon-date-editor-set-month:

.. function:: hildon_date_editor_set_month ()

::

  gboolean            hildon_date_editor_set_month        (HildonDateEditor *editor,
                                                           guint month);

.. warning:: ``hildon_date_editor_set_month`` is deprecated and should not be used in newly-written code.

Sets the month shown in the editor.



``editor``:
  the ``HildonDateEditor`` widget


``month``:
  month


*Returns*:
  TRUE if the month is valid and has been set.


.. _hildon-date-editor-set-day:

.. function:: hildon_date_editor_set_day ()

::

  gboolean            hildon_date_editor_set_day          (HildonDateEditor *editor,
                                                           guint day);

.. warning:: ``hildon_date_editor_set_day`` is deprecated and should not be used in newly-written code.

Sets the day shown in the editor.



``editor``:
  the ``HildonDateEditor`` widget


``day``:
  day


*Returns*:
  TRUE if the day is valid and has been set.


.. _hildon-date-editor-get-year:

.. function:: hildon_date_editor_get_year ()

::

  guint               hildon_date_editor_get_year         (HildonDateEditor *editor);

.. warning:: ``hildon_date_editor_get_year`` is deprecated and should not be used in newly-written code.





``editor``:
  the ``HildonDateEditor`` widget


*Returns*:
  the current year shown in the editor.


.. _hildon-date-editor-get-month:

.. function:: hildon_date_editor_get_month ()

::

  guint               hildon_date_editor_get_month        (HildonDateEditor *editor);

.. warning:: ``hildon_date_editor_get_month`` is deprecated and should not be used in newly-written code.

Gets the month shown in the editor.



``editor``:
  the ``HildonDateEditor`` widget


*Returns*:
  the current month shown in the editor.


.. _hildon-date-editor-get-day:

.. function:: hildon_date_editor_get_day ()

::

  guint               hildon_date_editor_get_day          (HildonDateEditor *editor);

.. warning:: ``hildon_date_editor_get_day`` is deprecated and should not be used in newly-written code.

Gets the day shown in the editor.



``editor``:
  the ``HildonDateEditor`` widget


*Returns*:
  the current day shown in the editor


.. _HildonDateEditor.property-details:

Property Details
================

.. _HildonDateEditor--day:

The ``day`` property

::

    day                      guint                 : Read / Write

Current day.



Allowed values: [1,31]

Default value: 1

.. _HildonDateEditor--max-year:

The ``max-year`` property

::

    max-year                 guint                 : Read / Write

Maximum valid year.



Allowed values: [1,10000]

Default value: 2037

.. _HildonDateEditor--min-year:

The ``min-year`` property

::

    min-year                 guint                 : Read / Write

Minimum valid year.



Allowed values: [1,10000]

Default value: 1970

.. _HildonDateEditor--month:

The ``month`` property

::

    month                    guint                 : Read / Write

Current month.



Allowed values: [1,12]

Default value: 1

.. _HildonDateEditor--year:

The ``year`` property

::

    year                     guint                 : Read / Write

Current year.



Allowed values: [1,10000]

Default value: 2007

.. _HildonDateEditor.signal-details:

Signal Details
==============

.. _HildonDateEditor-date-error:

The ``date-error`` signal

::

  gboolean            user_function                      (HildonDateEditor   *hildondateeditor,
                                                          HildonDateTimeError arg1,
                                                          gpointer            user_data)             : Run Last



``hildondateeditor``:
  the object which received the signal.


``arg1``:
  


``user_data``:
  user data set when the signal handler was connected.


*Returns*:
  


.. _HildonDateEditor.see-also:

See Also
========

`HildonCalendarPopup <HildonCalendarPopup>`_ `HildonTimeEditor <HildonTimeEditor>`_ .. _hildon-HildonBreadCrumbTrail:

HildonBreadCrumbTrail
*********************

.. _hildon-HildonBreadCrumbTrail.description:

Description
===========

HildonBreadCrumbTrail is a GTK widget used to represent the currently active path in some kind of hierarchical structure (file system, media library, structured document, etc).

It has built-in support for text and icon bread crumbs, but the trail only requires a very simple interface to be implemented for its children and thus new types of items can be implemented if needed. See `HildonBreadCrumb <HildonBreadCrumb>`_ for more details.



.. _hildon-HildonBreadCrumbTrail.details:

Details
=======

.. _HildonBreadCrumbTrail:

.. class:: HildonBreadCrumbTrail

::

  typedef struct {
    GtkContainer parent;
  
    HildonBreadCrumbTrailPrivate *priv;
  } HildonBreadCrumbTrail;
  

.. warning:: ``HildonBreadCrumbTrail`` is deprecated and should not be used in newly-written code.



.. _hildon-bread-crumb-trail-new:

.. function:: hildon_bread_crumb_trail_new ()

::

  GtkWidget*          hildon_bread_crumb_trail_new        (void);

.. warning:: ``hildon_bread_crumb_trail_new`` is deprecated and should not be used in newly-written code.

Creates a new `HildonBreadCrumbTrail <HildonBreadCrumbTrail>`_ widget.



*Returns*:
  a `GtkWidget <GtkWidget>`_ pointer of newly created bread crumb trail widget


Stability Level: Unstable

.. _hildon-bread-crumb-trail-push:

.. function:: hildon_bread_crumb_trail_push ()

::

  void                hildon_bread_crumb_trail_push       (HildonBreadCrumbTrail *bct,
                                                           HildonBreadCrumb *item,
                                                           gpointer id,
                                                           GDestroyNotify destroy);

.. warning:: ``hildon_bread_crumb_trail_push`` is deprecated and should not be used in newly-written code.

Adds a new bread crumb to the end of the trail.



``bct``:
  pointer to `HildonBreadCrumbTrail <HildonBreadCrumbTrail>`_


``item``:
  the `HildonBreadCrumb <HildonBreadCrumb>`_ to be added to the trail


``id``:
  optional id for the bread crumb


``destroy``:
  GDestroyNotify callback to be called when the bread crumb is destroyed


Stability Level: Unstable

.. _hildon-bread-crumb-trail-push-text:

.. function:: hildon_bread_crumb_trail_push_text ()

::

  void                hildon_bread_crumb_trail_push_text  (HildonBreadCrumbTrail *bct,
                                                           const gchar *text,
                                                           gpointer id,
                                                           GDestroyNotify destroy);

.. warning:: ``hildon_bread_crumb_trail_push_text`` is deprecated and should not be used in newly-written code.

Adds a new bread crumb to the end of the trail containing the specified text.



``bct``:
  pointer to `HildonBreadCrumbTrail <HildonBreadCrumbTrail>`_


``text``:
  content of the new bread crumb


``id``:
  optional id for the bread crumb


``destroy``:
  GDestroyNotify callback to be called when the bread crumb is destroyed


Stability Level: Unstable

.. _hildon-bread-crumb-trail-push-icon:

.. function:: hildon_bread_crumb_trail_push_icon ()

::

  void                hildon_bread_crumb_trail_push_icon  (HildonBreadCrumbTrail *bct,
                                                           const gchar *text,
                                                           GtkWidget *icon,
                                                           gpointer id,
                                                           GDestroyNotify destroy);

.. warning:: ``hildon_bread_crumb_trail_push_icon`` is deprecated and should not be used in newly-written code.

Adds a new bread crumb to the end of the trail containing the specified text and icon.



``bct``:
  pointer to `HildonBreadCrumbTrail <HildonBreadCrumbTrail>`_


``text``:
  content of the new bread crumb


``icon``:
  a widget to set as the icon in the bread crumb


``id``:
  optional id for the bread crumb


``destroy``:
  GDestroyNotify callback to be called when the bread crumb is destroyed


Stability Level: Unstable

.. _hildon-bread-crumb-trail-pop:

.. function:: hildon_bread_crumb_trail_pop ()

::

  void                hildon_bread_crumb_trail_pop        (HildonBreadCrumbTrail *bct);

.. warning:: ``hildon_bread_crumb_trail_pop`` is deprecated and should not be used in newly-written code.

Removes the last bread crumb from the trail.



``bct``:
  pointer to `HildonBreadCrumbTrail <HildonBreadCrumbTrail>`_


Stability Level: Unstable

.. _hildon-bread-crumb-trail-clear:

.. function:: hildon_bread_crumb_trail_clear ()

::

  void                hildon_bread_crumb_trail_clear      (HildonBreadCrumbTrail *bct);

.. warning:: ``hildon_bread_crumb_trail_clear`` is deprecated and should not be used in newly-written code.

Removes all the bread crumbs from the bread crumb trail.



``bct``:
  pointer to `HildonBreadCrumbTrail <HildonBreadCrumbTrail>`_


Stability Level: Unstable

.. _HildonDialog:

HildonDialog
************

.. _HildonDialog.object-hierarchy:

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
  

.. _HildonDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonDialog implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonDialog.description:

Description
===========

`HildonDialog <HildonDialog>`_ is a GTK widget which represent a popup window in the Hildon framework. It is derived from `GtkDialog <GtkDialog>`_ and provides additional commodities specific to the Hildon framework.

As of hildon 2.2, `HildonDialog <HildonDialog>`_ has been deprecated in favor of `GtkDialog <GtkDialog>`_ .

.. note:: `HildonDialog <HildonDialog>`_ has been deprecated since Hildon 2.2 and should not be used in newly written code. See `Migrating Hildon Dialogs <hildon-migrating-hildon-dialogs>`_ section to know how to migrate this deprecated widget.

Simple HildonDialog usage ========================= :: void quick_message (gchar *message) { GtkWidget *dialog, *label; dialog = hildon_dialog_new (); label = gtk_label_new (message); g_signal_connect_swapped (dialog, "response", G_CALLBACK (gtk_widget_destroy), dialog); gtk_container_add (GTK_CONTAINER (GTK_DIALOG(dialog)->vbox), label); gtk_widget_show_all (dialog); }



.. _HildonDialog.details:

Details
=======

.. _HildonDialog-struct:

.. class:: HildonDialog

::

  typedef struct _HildonDialog HildonDialog;

.. warning:: ``HildonDialog`` is deprecated and should not be used in newly-written code.



.. _hildon-dialog-new:

.. function:: hildon_dialog_new ()

::

  GtkWidget*          hildon_dialog_new                   (void);

.. warning:: ``hildon_dialog_new`` is deprecated and should not be used in newly-written code.

Creates a new `HildonDialog <HildonDialog>`_ widget



*Returns*:
  the newly created `HildonDialog <HildonDialog>`_


Since 2.2

.. _hildon-dialog-new-with-buttons:

.. function:: hildon_dialog_new_with_buttons ()

::

  GtkWidget*          hildon_dialog_new_with_buttons      (const gchar *title,
                                                           GtkWindow *parent,
                                                           GtkDialogFlags flags,
                                                           const gchar *first_button_text,
                                                           ...);

.. warning:: ``hildon_dialog_new_with_buttons`` is deprecated and should not be used in newly-written code.

Creates a new `HildonDialog <HildonDialog>`_ . See `gtk_dialog_new_with_buttons() <gtk-dialog-new-with-buttons>`_ for more information.



``title``:
  Title of the dialog, or ```NULL`` <NULL:CAPS>`_


``parent``:
  Transient parent of the dialog, or ```NULL`` <NULL:CAPS>`_


``flags``:
  from `GtkDialogFlags <GtkDialogFlags>`_


``first_button_text``:
  stock ID or text to go in first button, or ```NULL`` <NULL:CAPS>`_


``...``:
  response ID for first button, then additional buttons, ending with ```NULL`` <NULL:CAPS>`_


*Returns*:
  a new `HildonDialog <HildonDialog>`_


Since 2.2

.. _hildon-dialog-add-button:

.. function:: hildon_dialog_add_button ()

::

  GtkWidget*          hildon_dialog_add_button            (HildonDialog *dialog,
                                                           const gchar *button_text,
                                                           gint response_id);

.. warning:: ``hildon_dialog_add_button`` is deprecated and should not be used in newly-written code.

Adds a button to the dialog. Works exactly like `gtk_dialog_add_button() <gtk-dialog-add-button>`_ , the only difference being that the button has finger size.



``dialog``:
  a `HildonDialog <HildonDialog>`_


``button_text``:
  text of the button, or stock ID


``response_id``:
  response ID for the button.


*Returns*:
  the button widget that was added


Since 2.2

.. _hildon-dialog-add-buttons:

.. function:: hildon_dialog_add_buttons ()

::

  void                hildon_dialog_add_buttons           (HildonDialog *dialog,
                                                           const gchar *first_button_text,
                                                           ...);

.. warning:: ``hildon_dialog_add_buttons`` is deprecated and should not be used in newly-written code.

Adds several buttons to the dialog. Works exactly like `gtk_dialog_add_buttons() <gtk-dialog-add-buttons>`_ , the only difference being that the buttons have finger size.



``dialog``:
  a `HildonDialog <HildonDialog>`_


``first_button_text``:
  text of the button, or stock ID


``...``:
  response ID for first button, then more text-response_id pairs


Since 2.2

.. _HildonDialog.see-also:

See Also
========

`HildonCodeDialog <HildonCodeDialog>`_ `HildonColorChooserDialog <HildonColorChooserDialog>`_ `HildonFontSelectionDialog <HildonFontSelectionDialog>`_ `HildonGetPasswordDialog <HildonGetPasswordDialog>`_ `HildonLoginDialog <HildonLoginDialog>`_ `HildonSetPasswordDialog <HildonSetPasswordDialog>`_ `HildonSortDialog <HildonSortDialog>`_ `HildonWizardDialog <HildonWizardDialog>`_ .. _HildonColorChooserDialog:

HildonColorChooserDialog
************************

.. _HildonColorChooserDialog.object-hierarchy:

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
                                               +----HildonColorChooserDialog
  

.. _HildonColorChooserDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonColorChooserDialog implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonColorChooserDialog.style-properties:

Style Properties
================

::

  
    container-sizes          GtkBorder*            : Read
    default-color            GdkColor*             : Read
    defined-color0           GdkColor*             : Read
    defined-color1           GdkColor*             : Read
    defined-color10          GdkColor*             : Read
    defined-color11          GdkColor*             : Read
    defined-color12          GdkColor*             : Read
    defined-color13          GdkColor*             : Read
    defined-color14          GdkColor*             : Read
    defined-color15          GdkColor*             : Read
    defined-color16          GdkColor*             : Read
    defined-color17          GdkColor*             : Read
    defined-color18          GdkColor*             : Read
    defined-color19          GdkColor*             : Read
    defined-color2           GdkColor*             : Read
    defined-color20          GdkColor*             : Read
    defined-color21          GdkColor*             : Read
    defined-color22          GdkColor*             : Read
    defined-color23          GdkColor*             : Read
    defined-color24          GdkColor*             : Read
    defined-color25          GdkColor*             : Read
    defined-color26          GdkColor*             : Read
    defined-color27          GdkColor*             : Read
    defined-color28          GdkColor*             : Read
    defined-color29          GdkColor*             : Read
    defined-color3           GdkColor*             : Read
    defined-color30          GdkColor*             : Read
    defined-color31          GdkColor*             : Read
    defined-color4           GdkColor*             : Read
    defined-color5           GdkColor*             : Read
    defined-color6           GdkColor*             : Read
    defined-color7           GdkColor*             : Read
    defined-color8           GdkColor*             : Read
    defined-color9           GdkColor*             : Read
    num-buttons              GtkBorder*            : Read
    radio-sizes              GtkBorder*            : Read
  

.. _HildonColorChooserDialog.description:

Description
===========

HildonColorChooserDialog enables the user to select an arbitrary color from a HSV colorspace. The color is stored in one of the predefined color slots and can be reselected later on.

Additionally the user can choose one of the standard "factory" colors.



.. _HildonColorChooserDialog.details:

Details
=======

.. _HildonColorChooserDialog-struct:

.. class:: HildonColorChooserDialog

::

  typedef struct _HildonColorChooserDialog HildonColorChooserDialog;

.. warning:: ``HildonColorChooserDialog`` is deprecated and should not be used in newly-written code.



.. _hildon-color-chooser-dialog-new:

.. function:: hildon_color_chooser_dialog_new ()

::

  GtkWidget*          hildon_color_chooser_dialog_new     (void);

.. warning:: ``hildon_color_chooser_dialog_new`` is deprecated and should not be used in newly-written code.

Creates a new color chooser dialog.



*Returns*:
  a new color chooser dialog.


.. _hildon-color-chooser-dialog-set-color:

.. function:: hildon_color_chooser_dialog_set_color ()

::

  void                hildon_color_chooser_dialog_set_color
                                                          (HildonColorChooserDialog *dialog,
                                                           GdkColor *color);

.. warning:: ``hildon_color_chooser_dialog_set_color`` is deprecated and should not be used in newly-written code.

Sets the dialog to point at the given color. It'll first try to search the palette of the existing colors to match the passed color. If the color is not found in the pallette, the color in the currently selected box will be modified.



``dialog``:
  a `HildonColorChooserDialog <HildonColorChooserDialog>`_


``color``:
  a color to set on the `HildonColorChooserDialog <HildonColorChooserDialog>`_


.. _hildon-color-chooser-dialog-get-color:

.. function:: hildon_color_chooser_dialog_get_color ()

::

  void                hildon_color_chooser_dialog_get_color
                                                          (HildonColorChooserDialog *dialog,
                                                           GdkColor *color);

.. warning:: ``hildon_color_chooser_dialog_get_color`` is deprecated and should not be used in newly-written code.

Retrives the currently selected color in the color chooser dialog.



``dialog``:
  a `HildonColorChooserDialog <HildonColorChooserDialog>`_


``color``:
  a color structure to fill with the currently selected color


.. _HildonColorChooserDialog.style-property-details:

Style Property Details
======================

.. _HildonColorChooserDialog--container-sizes:

The ``container-sizes`` style property

::

    container-sizes          GtkBorder*            : Read

Container specific sizes.

.. _HildonColorChooserDialog--default-color:

The ``default-color`` style property

::

    default-color            GdkColor*             : Read

Default color for nonpainted custom colors.

.. _HildonColorChooserDialog--defined-color0:

The ``defined-color0`` style property

::

    defined-color0           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color1:

The ``defined-color1`` style property

::

    defined-color1           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color10:

The ``defined-color10`` style property

::

    defined-color10          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color11:

The ``defined-color11`` style property

::

    defined-color11          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color12:

The ``defined-color12`` style property

::

    defined-color12          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color13:

The ``defined-color13`` style property

::

    defined-color13          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color14:

The ``defined-color14`` style property

::

    defined-color14          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color15:

The ``defined-color15`` style property

::

    defined-color15          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color16:

The ``defined-color16`` style property

::

    defined-color16          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color17:

The ``defined-color17`` style property

::

    defined-color17          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color18:

The ``defined-color18`` style property

::

    defined-color18          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color19:

The ``defined-color19`` style property

::

    defined-color19          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color2:

The ``defined-color2`` style property

::

    defined-color2           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color20:

The ``defined-color20`` style property

::

    defined-color20          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color21:

The ``defined-color21`` style property

::

    defined-color21          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color22:

The ``defined-color22`` style property

::

    defined-color22          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color23:

The ``defined-color23`` style property

::

    defined-color23          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color24:

The ``defined-color24`` style property

::

    defined-color24          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color25:

The ``defined-color25`` style property

::

    defined-color25          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color26:

The ``defined-color26`` style property

::

    defined-color26          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color27:

The ``defined-color27`` style property

::

    defined-color27          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color28:

The ``defined-color28`` style property

::

    defined-color28          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color29:

The ``defined-color29`` style property

::

    defined-color29          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color3:

The ``defined-color3`` style property

::

    defined-color3           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color30:

The ``defined-color30`` style property

::

    defined-color30          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color31:

The ``defined-color31`` style property

::

    defined-color31          GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color4:

The ``defined-color4`` style property

::

    defined-color4           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color5:

The ``defined-color5`` style property

::

    defined-color5           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color6:

The ``defined-color6`` style property

::

    defined-color6           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color7:

The ``defined-color7`` style property

::

    defined-color7           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color8:

The ``defined-color8`` style property

::

    defined-color8           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--defined-color9:

The ``defined-color9`` style property

::

    defined-color9           GdkColor*             : Read

Pre-defined colors for the dialog.

.. _HildonColorChooserDialog--num-buttons:

The ``num-buttons`` style property

::

    num-buttons              GtkBorder*            : Read

Number of color store buttons.

.. _HildonColorChooserDialog--radio-sizes:

The ``radio-sizes`` style property

::

    radio-sizes              GtkBorder*            : Read

Color radio specific sizes.

.. _HildonColorChooserDialog.see-also:

See Also
========

`HildonColorButton <HildonColorButton>`_ .. _HildonSetPasswordDialog:

HildonSetPasswordDialog
***********************

.. _HildonSetPasswordDialog.object-hierarchy:

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
                                               +----HildonSetPasswordDialog
  

.. _HildonSetPasswordDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonSetPasswordDialog implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonSetPasswordDialog.properties:

Properties
==========

::

  
    message                  gchar*                : Read / Write
    modify-protection        gboolean              : Read / Write / Construct Only
    password                 gchar*                : Read / Write
  

.. _HildonSetPasswordDialog.description:

Description
===========

HildonSetPasswordDialog allows setting and changing a password.

In Change mode: Dialog is used to change or remove an existing password. Unselecting the check box dims the password fields below it. If the dialog is accepted with 'OK' while the check box is unselected, a Confirmation Note is shown. If the Confirmation Note Dialog is accepted with 'Remove', the password protection is removed.

In Set mode: Set Password Dialog is used to define a password, or change a password that cannot be removed.



.. _HildonSetPasswordDialog.details:

Details
=======

.. _HildonSetPasswordDialog-struct:

.. class:: HildonSetPasswordDialog

::

  typedef struct _HildonSetPasswordDialog HildonSetPasswordDialog;

.. warning:: ``HildonSetPasswordDialog`` is deprecated and should not be used in newly-written code.



.. _hildon-set-password-dialog-new:

.. function:: hildon_set_password_dialog_new ()

::

  GtkWidget*          hildon_set_password_dialog_new      (GtkWindow *parent,
                                                           gboolean modify_protection);

.. warning:: ``hildon_set_password_dialog_new`` is deprecated and should not be used in newly-written code.

Constructs a new HildonSetPasswordDialog.



``parent``:
  parent window; can be NULL


``modify_protection``:
  TRUE creates a new change password dialog and FALSE creates a new set password dialog


*Returns*:
  a new `GtkWidget <GtkWidget>`_ of type HildonSetPasswordDialog


.. _hildon-set-password-dialog-new-with-default:

.. function:: hildon_set_password_dialog_new_with_default ()

::

  GtkWidget*          hildon_set_password_dialog_new_with_default
                                                          (GtkWindow *parent,
                                                           const gchar *password,
                                                           gboolean modify_protection);

.. warning:: ``hildon_set_password_dialog_new_with_default`` is deprecated and should not be used in newly-written code.

Same as `hildon_set_password_dialog_new <hildon-set-password-dialog-new>`_ , but with a default password in password field.



``parent``:
  parent window; can be NULL


``password``:
  a default password to be shown in password field


``modify_protection``:
  TRUE creates a new change password dialog and FALSE creates a new set password dialog


*Returns*:
  a new `GtkWidget <GtkWidget>`_ of type HildonSetPasswordDialog


.. _hildon-set-password-dialog-get-password:

.. function:: hildon_set_password_dialog_get_password ()

::

  const gchar*        hildon_set_password_dialog_get_password
                                                          (HildonSetPasswordDialog *dialog);

.. warning:: ``hildon_set_password_dialog_get_password`` is deprecated and should not be used in newly-written code.

Returns current password.



``dialog``:
  pointer to HildonSetPasswordDialog


*Returns*:
  changed password ( if the dialog is successfully accepted with 'OK' ( and when the check box is 'ON' ( in Change Password Dialog ))


.. _hildon-set-password-dialog-get-protected:

.. function:: hildon_set_password_dialog_get_protected ()

::

  gboolean            hildon_set_password_dialog_get_protected
                                                          (HildonSetPasswordDialog *dialog);

.. warning:: ``hildon_set_password_dialog_get_protected`` is deprecated and should not be used in newly-written code.

Returns the protection mode.



``dialog``:
  pointer to HildonSetPasswordDialog


*Returns*:
  password protection mode ( TRUE when the protection is 'ON' and FALSE when the protection is 'OFF' )


.. _hildon-set-password-dialog-set-message:

.. function:: hildon_set_password_dialog_set_message ()

::

  void                hildon_set_password_dialog_set_message
                                                          (HildonSetPasswordDialog *dialog,
                                                           const gchar *message);

.. warning:: ``hildon_set_password_dialog_set_message`` is deprecated and should not be used in newly-written code.

Sets the optional descriptive text.



``dialog``:
  the dialog


``message``:
  the message or some other descriptive text to be set


.. _HildonSetPasswordDialog.property-details:

Property Details
================

.. _HildonSetPasswordDialog--message:

The ``message`` property

::

    message                  gchar*                : Read / Write

A message to display to the user.

Default value: NULL

.. _HildonSetPasswordDialog--modify-protection:

The ``modify-protection`` property

::

    modify-protection        gboolean              : Read / Write / Construct Only

Password type.



Default value: TRUE

.. _HildonSetPasswordDialog--password:

The ``password`` property

::

    password                 gchar*                : Read / Write

Content of the password field.



Default value: "DEFAULT"

.. _HildonSetPasswordDialog.see-also:

See Also
========

`HildonGetPasswordDialog <HildonGetPasswordDialog>`_ .. _HildonGetPasswordDialog:

HildonGetPasswordDialog
***********************

.. _HildonGetPasswordDialog.object-hierarchy:

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
                                               +----HildonGetPasswordDialog
  

.. _HildonGetPasswordDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonGetPasswordDialog implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonGetPasswordDialog.properties:

Properties
==========

::

  
    caption-label            gchar*                : Read / Write
    get-old                  gboolean              : Read / Write / Construct Only
    max-characters           gint                  : Read / Write
    message                  gchar*                : Read / Write
    numbers-only             gboolean              : Read / Write
    password                 gchar*                : Read / Write
  

.. _HildonGetPasswordDialog.description:

Description
===========

HildonGetPasswordDialog prompts the user for a password. It allows inputting password, with an optional configurable label eg. for showing a custom message. The maximum length of the password can be set.

HildonGetPassword example ========================= :: get_dialog = HILDON_GET_PASSWORD_DIALOG (hildon_get_password_dialog_new (parent, FALSE)); gtk_widget_show (GTK_WIDGET (get_dialog)); i = gtk_dialog_run (GTK_DIALOG (get_dialog)); pass = hildon_get_password_dialog_get_password (get_dialog); if (i == GTK_RESPONSE_OK (strcmp (pass, dialog.current_password) != 0)) { gtk_infoprint (GTK_WINDOW (parent), STR_PASSWORD_INCORRECT); gtk_widget_set_sensitive (GTK_WIDGET (dialog.button2), FALSE); gtk_widget_set_sensitive (GTK_WIDGET (dialog.button3), FALSE); gtk_widget_set_sensitive (GTK_WIDGET (dialog.button4), FALSE); } else if (i == GTK_RESPONSE_OK) { gtk_widget_set_sensitive( GTK_WIDGET( dialog.button2 ), TRUE); } else { gtk_widget_set_sensitive (GTK_WIDGET (dialog.button2), FALSE); gtk_widget_set_sensitive (GTK_WIDGET (dialog.button3), FALSE); gtk_widget_set_sensitive (GTK_WIDGET (dialog.button4), FALSE); } gtk_widget_destroy (GTK_WIDGET (get_dialog)); }



.. _HildonGetPasswordDialog.details:

Details
=======

.. _HildonGetPasswordDialog-struct:

.. class:: HildonGetPasswordDialog

::

  typedef struct _HildonGetPasswordDialog HildonGetPasswordDialog;

.. warning:: ``HildonGetPasswordDialog`` is deprecated and should not be used in newly-written code.



.. _hildon-get-password-dialog-new:

.. function:: hildon_get_password_dialog_new ()

::

  GtkWidget*          hildon_get_password_dialog_new      (GtkWindow *parent,
                                                           gboolean get_old);

.. warning:: ``hildon_get_password_dialog_new`` is deprecated and should not be used in newly-written code.

Construct a new HildonGetPasswordDialog.



``parent``:
  parent window; can be NULL


``get_old``:
  FALSE creates a new get password dialog and TRUE creates a new get old password dialog. That is, if the password to be obtained is the old password, this parameter is specified TRUE.


*Returns*:
  a new `GtkWidget <GtkWidget>`_ of type HildonGetPasswordDialog


.. _hildon-get-password-dialog-new-with-default:

.. function:: hildon_get_password_dialog_new_with_default ()

::

  GtkWidget*          hildon_get_password_dialog_new_with_default
                                                          (GtkWindow *parent,
                                                           const gchar *password,
                                                           gboolean get_old);

.. warning:: ``hildon_get_password_dialog_new_with_default`` is deprecated and should not be used in newly-written code.

Same as `hildon_get_password_dialog_new <hildon-get-password-dialog-new>`_ but with a default password in password field.



``parent``:
  parent window; can be NULL


``password``:
  a default password to be shown in password field


``get_old``:
  FALSE creates a new get password dialog and TRUE creates a new get old password dialog. That is, if the password to be obtained is the old password, this parameter is specified TRUE.


*Returns*:
  a new `GtkWidget <GtkWidget>`_ of type HildonGetPasswordDialog


.. _hildon-get-password-dialog-set-message:

.. function:: hildon_get_password_dialog_set_message ()

::

  void                hildon_get_password_dialog_set_message
                                                          (HildonGetPasswordDialog *dialog,
                                                           const gchar *message);

.. warning:: ``hildon_get_password_dialog_set_message`` is deprecated and should not be used in newly-written code.

Sets the optional descriptive text displayed at the top of the dialog.



``dialog``:
  the dialog


``message``:
  a custom message or some other descriptive text to be set


.. _hildon-get-password-dialog-set-caption:

.. function:: hildon_get_password_dialog_set_caption ()

::

  void                hildon_get_password_dialog_set_caption
                                                          (HildonGetPasswordDialog *dialog,
                                                           const gchar *new_caption);

.. warning:: ``hildon_get_password_dialog_set_caption`` is deprecated and should not be used in newly-written code.

Sets the password entry field's neigbouring label.



``dialog``:
  the dialog


``new_caption``:
  the text to be set as the caption label


.. _hildon-get-password-dialog-set-max-characters:

.. function:: hildon_get_password_dialog_set_max_characters ()

::

  void                hildon_get_password_dialog_set_max_characters
                                                          (HildonGetPasswordDialog *dialog,
                                                           gint max_characters);

.. warning:: ``hildon_get_password_dialog_set_max_characters`` is deprecated and should not be used in newly-written code.

sets the maximum number of characters allowed as the password



``dialog``:
  the dialog


``max_characters``:
  the maximum number of characters the password dialog accepts


.. _hildon-get-password-dialog-get-password:

.. function:: hildon_get_password_dialog_get_password ()

::

  const gchar*        hildon_get_password_dialog_get_password
                                                          (HildonGetPasswordDialog *dialog);

.. warning:: ``hildon_get_password_dialog_get_password`` is deprecated and should not be used in newly-written code.

Gets the currently entered password. The string should not be freed.



``dialog``:
  pointer to HildonSetPasswordDialog


*Returns*:
  current password entered by the user.


.. _HildonGetPasswordDialog.property-details:

Property Details
================

.. _HildonGetPasswordDialog--caption-label:

The ``caption-label`` property

::

    caption-label            gchar*                : Read / Write

Caption label.



Default value: NULL

.. _HildonGetPasswordDialog--get-old:

The ``get-old`` property

::

    get-old                  gboolean              : Read / Write / Construct Only

If the dialog is used to retrieve an old password or set a new one.



Default value: FALSE

.. _HildonGetPasswordDialog--max-characters:

The ``max-characters`` property

::

    max-characters           gint                  : Read / Write

Maximum characters than can be entered.



Default value: 0

.. _HildonGetPasswordDialog--message:

The ``message`` property

::

    message                  gchar*                : Read / Write

Optional message displayed to the user.



Default value: NULL

.. _HildonGetPasswordDialog--numbers-only:

The ``numbers-only`` property

::

    numbers-only             gboolean              : Read / Write

If the password entry field is operating in numbers-only mode.



Default value: FALSE

.. _HildonGetPasswordDialog--password:

The ``password`` property

::

    password                 gchar*                : Read / Write

Password field contents.



Default value: "DEFAULT"

.. _HildonGetPasswordDialog.see-also:

See Also
========

`HildonSetPasswordDialog <HildonSetPasswordDialog>`_ .. _HildonLoginDialog:

HildonLoginDialog
*****************

.. _HildonLoginDialog.object-hierarchy:

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
                                               +----HildonLoginDialog
  

.. _HildonLoginDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonLoginDialog implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonLoginDialog.properties:

Properties
==========

::

  
    message                  gchar*                : Read / Write
    password                 gchar*                : Read / Write
    username                 gchar*                : Read / Write
  

.. _HildonLoginDialog.description:

Description
===========

`HildonLoginDialog <HildonLoginDialog>`_ is used to enter a username and password when accessing a password protected area. The widget performs no input checking and is used only for retrieving the username and a password.



.. _HildonLoginDialog.details:

Details
=======

.. _HildonLoginDialog-struct:

.. class:: HildonLoginDialog

::

  typedef struct _HildonLoginDialog HildonLoginDialog;

.. warning:: ``HildonLoginDialog`` is deprecated and should not be used in newly-written code.



.. _hildon-login-dialog-new:

.. function:: hildon_login_dialog_new ()

::

  GtkWidget*          hildon_login_dialog_new             (GtkWindow *parent);

.. warning:: ``hildon_login_dialog_new`` is deprecated and should not be used in newly-written code.

Creates a new `HildonLoginDialog <HildonLoginDialog>`_ widget with Ok and Close buttons.



``parent``:
  the parent window of the dialog


*Returns*:
  the newly created `HildonLoginDialog <HildonLoginDialog>`_


.. _hildon-login-dialog-new-with-default:

.. function:: hildon_login_dialog_new_with_default ()

::

  GtkWidget*          hildon_login_dialog_new_with_default
                                                          (GtkWindow *parent,
                                                           const gchar *name,
                                                           const gchar *password);

.. warning:: ``hildon_login_dialog_new_with_default`` is deprecated and should not be used in newly-written code.

Same as `hildon_login_dialog_new <hildon-login-dialog-new>`_ but with a default username and password.



``parent``:
  the parent window of the dialog


``name``:
  default username, NULL if unset


``password``:
  default password, NULL if unset


*Returns*:
  the newly created `HildonLoginDialog <HildonLoginDialog>`_


.. _hildon-login-dialog-get-username:

.. function:: hildon_login_dialog_get_username ()

::

  const gchar*        hildon_login_dialog_get_username    (HildonLoginDialog *dialog);

.. warning:: ``hildon_login_dialog_get_username`` is deprecated and should not be used in newly-written code.

Gets the text that's in the username entry.



``dialog``:
  the dialog


*Returns*:
  a pointer to the name string. You should not modify it.


.. _hildon-login-dialog-get-password:

.. function:: hildon_login_dialog_get_password ()

::

  const gchar*        hildon_login_dialog_get_password    (HildonLoginDialog *dialog);

.. warning:: ``hildon_login_dialog_get_password`` is deprecated and should not be used in newly-written code.

Gets the text that's in the password entry.



``dialog``:
  the dialog


*Returns*:
  a pointer to the password string. You should not modify it.


.. _hildon-login-dialog-set-message:

.. function:: hildon_login_dialog_set_message ()

::

  void                hildon_login_dialog_set_message     (HildonLoginDialog *dialog,
                                                           const gchar *msg);

.. warning:: ``hildon_login_dialog_set_message`` is deprecated and should not be used in newly-written code.

Sets the optional descriptive text that is displayed on the top of the dialog.



``dialog``:
  the dialog


``msg``:
  the message or some other descriptive text to be set


.. _HildonLoginDialog.property-details:

Property Details
================

.. _HildonLoginDialog--message:

The ``message`` property

::

    message                  gchar*                : Read / Write

Optional message displayed to the user.



Default value: NULL

.. _HildonLoginDialog--password:

The ``password`` property

::

    password                 gchar*                : Read / Write

Contents of the password field.



Default value: "DEFAULT"

.. _HildonLoginDialog--username:

The ``username`` property

::

    username                 gchar*                : Read / Write

Contents of the username field.



Default value: "DEFAULT"

.. _HildonLoginDialog.see-also:

See Also
========

`HildonGetPasswordDialog <HildonGetPasswordDialog>`_ `HildonSetPasswordDialog <HildonSetPasswordDialog>`_ .. _HildonSortDialog:

HildonSortDialog
****************

.. _HildonSortDialog.object-hierarchy:

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
                                               +----HildonSortDialog
  

.. _HildonSortDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonSortDialog implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonSortDialog.properties:

Properties
==========

::

  
    sort-key                 gint                  : Read / Write
    sort-order               GtkSortType           : Read / Write
  

.. _HildonSortDialog.description:

Description
===========

HildonSortDialog is used to define an order (ascending/descending) and a field by which items are sorted in a list. The combo boxes display the current value when the dialog is opened.

.. note:: `HildonSortDialog <HildonSortDialog>`_ has been deprecated since Hildon 2.2 See `Migrating Sort Dialogs <hildon-migrating-sort-dialogs>`_ section to know how to migrate this deprecated widget.

An example for using HildonSortDialog ===================================== :: HildonSortDialog *sort_dialog = HILDON_SORT_DIALOG (hildon_sort_dialog_new (parent)); gint response_id, add_sort_index; sort_by[0] = STR_SORT_BY_DATE; sort_by[1] = STR_SORT_BY_NAME; sort_by[2] = STR_SORT_BY_SIZE; sort_by[3] = NULL; sorting_order[0] = STR_SORTING_ORDER_ASCENDING; sorting_order[1] = STR_SORTING_ORDER_DESCENDING; sorting_order[2] = NULL; add_sort_index = hildon_sort_dialog_add_sort_key (sort_dialog, STR_SORT_BY_DATE); hildon_sort_dialog_add_sort_key (sort_dialog, STR_SORT_BY_NAME); hildon_sort_dialog_add_sort_key (sort_dialog, STR_SORT_BY_SIZE); if (dialog.first_time_clicked == TRUE) { hildon_sort_dialog_set_sort_key (sort_dialog, add_sort_index); } if (dialog.first_time_clicked == FALSE) { hildon_sort_dialog_set_sort_key (sort_dialog, dialog.sort_key); hildon_sort_dialog_set_sort_order (sort_dialog, dialog.sort_order); } gtk_widget_show (GTK_WIDGET (sort_dialog)); response_id = gtk_dialog_run (GTK_DIALOG (sort_dialog)); if (response_id == GTK_RESPONSE_OK) { dialog.sort_key = hildon_sort_dialog_get_sort_key (sort_dialog); gtk_label_set_text (GTK_LABEL (dialog.label1), sort_by [dialog.sort_key]); dialog.sort_order = hildon_sort_dialog_get_sort_order (sort_dialog); gtk_label_set_text (GTK_LABEL (dialog.label2), sorting_order [dialog.sort_order]); dialog.first_time_clicked = FALSE; }



.. _HildonSortDialog.details:

Details
=======

.. _HildonSortDialog-struct:

.. class:: HildonSortDialog

::

  typedef struct _HildonSortDialog HildonSortDialog;

.. warning:: ``HildonSortDialog`` is deprecated and should not be used in newly-written code.



.. _hildon-sort-dialog-new:

.. function:: hildon_sort_dialog_new ()

::

  GtkWidget*          hildon_sort_dialog_new              (GtkWindow *parent);

.. warning:: ``hildon_sort_dialog_new`` is deprecated and should not be used in newly-written code.

HildonSortDialog contains two HildonCaptions with combo boxes.



``parent``:
  widget to be transient for, or NULL if none


*Returns*:
  pointer to a new ``HildonSortDialog`` widget


.. _hildon-sort-dialog-get-sort-key:

.. function:: hildon_sort_dialog_get_sort_key ()

::

  gint                hildon_sort_dialog_get_sort_key     (HildonSortDialog *dialog);

.. warning:: ``hildon_sort_dialog_get_sort_key`` is deprecated and should not be used in newly-written code.

Gets index to currently active sort key.



``dialog``:
  the `HildonSortDialog <HildonSortDialog>`_ widget


*Returns*:
  an integer which is the index value of the "Sort by" field


.. _hildon-sort-dialog-get-sort-order:

.. function:: hildon_sort_dialog_get_sort_order ()

::

  GtkSortType         hildon_sort_dialog_get_sort_order   (HildonSortDialog *dialog);

.. warning:: ``hildon_sort_dialog_get_sort_order`` is deprecated and should not be used in newly-written code.

Gets current sorting order from "Sort order" field.



``dialog``:
  the `HildonSortDialog <HildonSortDialog>`_ widget


*Returns*:
  current sorting order as `GtkSortType <GtkSortType>`_


.. _hildon-sort-dialog-set-sort-key:

.. function:: hildon_sort_dialog_set_sort_key ()

::

  void                hildon_sort_dialog_set_sort_key     (HildonSortDialog *dialog,
                                                           int key);

.. warning:: ``hildon_sort_dialog_set_sort_key`` is deprecated and should not be used in newly-written code.

Sets the index value of the `HildonSortDialog <HildonSortDialog>`_ widget.



``dialog``:
  the `HildonSortDialog <HildonSortDialog>`_ widget


``key``:
  combo box's index value


.. _hildon-sort-dialog-set-sort-order:

.. function:: hildon_sort_dialog_set_sort_order ()

::

  void                hildon_sort_dialog_set_sort_order   (HildonSortDialog *dialog,
                                                           GtkSortType order);

.. warning:: ``hildon_sort_dialog_set_sort_order`` is deprecated and should not be used in newly-written code.

Sets the index value of the `HildonSortDialog <HildonSortDialog>`_ widget.



``dialog``:
  the `HildonSortDialog <HildonSortDialog>`_ widget


``order``:
  combo box's index value


.. _hildon-sort-dialog-add-sort-key:

.. function:: hildon_sort_dialog_add_sort_key ()

::

  gint                hildon_sort_dialog_add_sort_key     (HildonSortDialog *dialog,
                                                           const gchar *sort_key);

.. warning:: ``hildon_sort_dialog_add_sort_key`` is deprecated and should not be used in newly-written code.

Adds a new sort key and returns the respective index in sort key combobox.



``dialog``:
  the `HildonSortDialog <HildonSortDialog>`_ widget


``sort_key``:
  combo box's index value


*Returns*:
  an integer which is the index of the added combo box's item


.. _hildon-sort-dialog-add-sort-key-reversed:

.. function:: hildon_sort_dialog_add_sort_key_reversed ()

::

  gint                hildon_sort_dialog_add_sort_key_reversed
                                                          (HildonSortDialog *dialog,
                                                           const gchar *sort_key);

.. warning:: ``hildon_sort_dialog_add_sort_key_reversed`` is deprecated and should not be used in newly-written code.

Adds a new sort key and returns the respective index in sort key combobox. The default sort order for this key is reversed (Descending first).



``dialog``:
  the `HildonSortDialog <HildonSortDialog>`_ widget


``sort_key``:
  combo box's index value


*Returns*:
  an integer which is the index of the added combo box's item


.. _HildonSortDialog.property-details:

Property Details
================

.. _HildonSortDialog--sort-key:

The ``sort-key`` property

::

    sort-key                 gint                  : Read / Write

The currently active sort key.



Default value: 0

.. _HildonSortDialog--sort-order:

The ``sort-order`` property

::

    sort-order               GtkSortType           : Read / Write

The sort order for the currently active sort key.



Default value: GTK_SORT_ASCENDING

.. _HildonFontSelectionDialog:

HildonFontSelectionDialog
*************************

.. _HildonFontSelectionDialog.object-hierarchy:

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
                                               +----HildonFontSelectionDialog
  

.. _HildonFontSelectionDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonFontSelectionDialog implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonFontSelectionDialog.properties:

Properties
==========

::

  
    bold                     gboolean              : Read / Write
    bold-set                 gboolean              : Read / Write / Construct
    color                    GdkColor*             : Read / Write
    color-set                gboolean              : Read / Write / Construct
    family                   gchar*                : Read / Write
    family-set               gboolean              : Read / Write / Construct
    font-scaling             gdouble               : Read / Write
    italic                   gboolean              : Read / Write
    italic-set               gboolean              : Read / Write / Construct
    position                 gint                  : Read / Write
    position-set             gboolean              : Read / Write / Construct
    preview-text             gchar*                : Read / Write
    size                     gint                  : Read / Write
    size-set                 gboolean              : Read / Write / Construct
    strikethrough            gboolean              : Read / Write
    strikethrough-set        gboolean              : Read / Write / Construct
    underline                gboolean              : Read / Write
    underline-set            gboolean              : Read / Write / Construct
  

.. _HildonFontSelectionDialog.description:

Description
===========

Font selection can be made using this widget. Users can select font name, size, style, etc. Since hildon 2.2, the previously available preview dialog has been removed.



.. _HildonFontSelectionDialog.details:

Details
=======

.. _HildonFontSelectionDialog-struct:

.. class:: HildonFontSelectionDialog

::

  typedef struct _HildonFontSelectionDialog HildonFontSelectionDialog;

.. warning:: ``HildonFontSelectionDialog`` is deprecated and should not be used in newly-written code.



.. _hildon-font-selection-dialog-new:

.. function:: hildon_font_selection_dialog_new ()

::

  GtkWidget*          hildon_font_selection_dialog_new    (GtkWindow *parent,
                                                           const gchar *title);

.. warning:: ``hildon_font_selection_dialog_new`` is deprecated and should not be used in newly-written code.

If NULL is passed for title, then default title "Font" will be used.



``parent``:
  the parent window


``title``:
  the title of font selection dialog


*Returns*:
  a new `HildonFontSelectionDialog <HildonFontSelectionDialog>`_


.. _hildon-font-selection-dialog-get-preview-text:

.. function:: hildon_font_selection_dialog_get_preview_text ()

::

  gchar*              hildon_font_selection_dialog_get_preview_text
                                                          (HildonFontSelectionDialog *fsd);

.. warning:: ``hildon_font_selection_dialog_get_preview_text`` is deprecated and should not be used in newly-written code.

Gets the text in preview dialog, which does not include the reference text. The returned string must be freed by the user. Please note that since hildon 2.2, the preview has been discontinued, so this setting has no effect.



``fsd``:
  the font selection dialog


*Returns*:
  a string pointer


.. _hildon-font-selection-dialog-set-preview-text:

.. function:: hildon_font_selection_dialog_set_preview_text ()

::

  void                hildon_font_selection_dialog_set_preview_text
                                                          (HildonFontSelectionDialog *fsd,
                                                           const gchar *text);

.. warning:: ``hildon_font_selection_dialog_set_preview_text`` is deprecated and should not be used in newly-written code.

The default preview text is "The quick brown fox jumped over the lazy dogs". Please note that since hildon 2.2, the preview has been discontinued, so this setting has no effect.



``fsd``:
  the font selection dialog


``text``:
  the text to be displayed in the preview dialog


.. _HildonFontSelectionDialog.property-details:

Property Details
================

.. _HildonFontSelectionDialog--bold:

The ``bold`` property

::

    bold                     gboolean              : Read / Write

Whether the text is bold.

Default value: FALSE

.. _HildonFontSelectionDialog--bold-set:

The ``bold-set`` property

::

    bold-set                 gboolean              : Read / Write / Construct

Whether the bold is inconsistent.

Default value: FALSE

.. _HildonFontSelectionDialog--color:

The ``color`` property

::

    color                    GdkColor*             : Read / Write

GdkColor for the text.



.. _HildonFontSelectionDialog--color-set:

The ``color-set`` property

::

    color-set                gboolean              : Read / Write / Construct

Is font bold status set or inconsistent.



Default value: FALSE

.. _HildonFontSelectionDialog--family:

The ``family`` property

::

    family                   gchar*                : Read / Write

Font family used.



Default value: "Sans"

.. _HildonFontSelectionDialog--family-set:

The ``family-set`` property

::

    family-set               gboolean              : Read / Write / Construct

Is font family set or inconsistent.



Default value: FALSE

.. _HildonFontSelectionDialog--font-scaling:

The ``font-scaling`` property

::

    font-scaling             gdouble               : Read / Write

The font scaling factor applied to the preview dialog.



Allowed values: [0,10]

Default value: 1

.. _HildonFontSelectionDialog--italic:

The ``italic`` property

::

    italic                   gboolean              : Read / Write

Is font set as italic.



Default value: FALSE

.. _HildonFontSelectionDialog--italic-set:

The ``italic-set`` property

::

    italic-set               gboolean              : Read / Write / Construct

Is font italic status set or inconsistent.



Default value: FALSE

.. _HildonFontSelectionDialog--position:

The ``position`` property

::

    position                 gint                  : Read / Write

The font positioning versus baseline.



Allowed values: [-1,1]

Default value: 0

.. _HildonFontSelectionDialog--position-set:

The ``position-set`` property

::

    position-set             gboolean              : Read / Write / Construct

Is the font positioning set.



Default value: FALSE

.. _HildonFontSelectionDialog--preview-text:

The ``preview-text`` property

::

    preview-text             gchar*                : Read / Write

The text used for the preview dialog.



Default value: ""

.. _HildonFontSelectionDialog--size:

The ``size`` property

::

    size                     gint                  : Read / Write

Font size.



Allowed values: [6,32]

Default value: 16

.. _HildonFontSelectionDialog--size-set:

The ``size-set`` property

::

    size-set                 gboolean              : Read / Write / Construct

Is font size set or inconsistent.



Default value: FALSE

.. _HildonFontSelectionDialog--strikethrough:

The ``strikethrough`` property

::

    strikethrough            gboolean              : Read / Write

Is the font striken-through.



Default value: FALSE

.. _HildonFontSelectionDialog--strikethrough-set:

The ``strikethrough-set`` property

::

    strikethrough-set        gboolean              : Read / Write / Construct

Is the font strikenthrough status set.



Default value: FALSE

.. _HildonFontSelectionDialog--underline:

The ``underline`` property

::

    underline                gboolean              : Read / Write

Is font underline status set or inconsistent.



Default value: FALSE

.. _HildonFontSelectionDialog--underline-set:

The ``underline-set`` property

::

    underline-set            gboolean              : Read / Write / Construct

Whether the underline is inconsistent.

Default value: FALSE

.. _HildonCodeDialog:

HildonCodeDialog
****************

.. _HildonCodeDialog.object-hierarchy:

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
                                               +----HildonCodeDialog
  

.. _HildonCodeDialog.implemented-interfaces:

Implemented Interfaces
======================

HildonCodeDialog implements `AtkImplementorIface <AtkImplementorIface>`_ and `GtkBuildable <GtkBuildable>`_ .

.. _HildonCodeDialog.signals:

Signals
=======

::

  
    input                                          : Run Last
  

.. _HildonCodeDialog.description:

Description
===========

`HildonCodeDialog <HildonCodeDialog>`_ displays a keypad that can be used to enter numerical pin codes or lock codes. It emits a 'input' signal each time an input action is performed on the dialog.



.. _HildonCodeDialog.details:

Details
=======

.. _HildonCodeDialog-struct:

.. class:: HildonCodeDialog

::

  typedef struct _HildonCodeDialog HildonCodeDialog;

.. warning:: ``HildonCodeDialog`` is deprecated and should not be used in newly-written code.



.. _hildon-code-dialog-new:

.. function:: hildon_code_dialog_new ()

::

  GtkWidget*          hildon_code_dialog_new              (void);

.. warning:: ``hildon_code_dialog_new`` is deprecated and should not be used in newly-written code.

Use this function to create a new HildonCodeDialog.



*Returns*:
  A ``HildonCodeDialog``.


.. _hildon-code-dialog-get-code:

.. function:: hildon_code_dialog_get_code ()

::

  const gchar*        hildon_code_dialog_get_code         (HildonCodeDialog *dialog);

.. warning:: ``hildon_code_dialog_get_code`` is deprecated and should not be used in newly-written code.

Use this function to access the code entered by the user.



``dialog``:
  The `HildonCodeDialog <HildonCodeDialog>`_ from which to get the entered code


*Returns*:
  The entered code.


.. _hildon-code-dialog-clear-code:

.. function:: hildon_code_dialog_clear_code ()

::

  void                hildon_code_dialog_clear_code       (HildonCodeDialog *dialog);

.. warning:: ``hildon_code_dialog_clear_code`` is deprecated and should not be used in newly-written code.



``dialog``:
  


.. _hildon-code-dialog-set-help-text:

.. function:: hildon_code_dialog_set_help_text ()

::

  void                hildon_code_dialog_set_help_text    (HildonCodeDialog *dialog,
                                                           const gchar *text);

.. warning:: ``hildon_code_dialog_set_help_text`` is deprecated and should not be used in newly-written code.

Use this function to set the text that will be displayd in the help label



``dialog``:
  The `HildonCodeDialog <HildonCodeDialog>`_ whose entry should be cleared:


``text``:
  The text to use in the help label.


.. _hildon-code-dialog-set-input-sensitive:

.. function:: hildon_code_dialog_set_input_sensitive ()

::

  void                hildon_code_dialog_set_input_sensitive
                                                          (HildonCodeDialog *dialog,
                                                           gboolean sensitive);

.. warning:: ``hildon_code_dialog_set_input_sensitive`` is deprecated and should not be used in newly-written code.

This function will block or enable the input on the code dialog by making the input button sensitive (or not).



``dialog``:
  The `HildonCodeDialog <HildonCodeDialog>`_ whose state is to be changed


``sensitive``:
  The new state


.. _HildonCodeDialog.signal-details:

Signal Details
==============

.. _HildonCodeDialog-input:

The ``input`` signal

::

  void                user_function                      (HildonCodeDialog *hildoncodedialog,
                                                          gpointer          user_data)             : Run Last



``hildoncodedialog``:
  the object which received the signal.


``user_data``:
  user data set when the signal handler was connected.


.. _hildon-hildon-bread-crumb:

hildon-bread-crumb
******************

.. _hildon-hildon-bread-crumb.description:

Description
===========

`HildonBreadCrumb <HildonBreadCrumb>`_ is an interface for creating new types of items for the `HildonBreadCrumbTrail <HildonBreadCrumbTrail>`_ widget.



.. _hildon-hildon-bread-crumb.details:

Details
=======

.. _HildonBreadCrumb:

.. class:: HildonBreadCrumb

::

  typedef struct _HildonBreadCrumb HildonBreadCrumb;

.. warning:: ``HildonBreadCrumb`` is deprecated and should not be used in newly-written code.



.. _HildonBreadCrumbIface:

.. class:: HildonBreadCrumbIface

::

  typedef struct {
    GTypeInterface g_iface;
  
    /* virtual table */
    void (* get_natural_size) (HildonBreadCrumb *bread_crumb,
                               gint *natural_width, gint *natural_height);
    /* signals */
    void (* crumb_activated) (HildonBreadCrumb *bread_crumb);
  } HildonBreadCrumbIface;
  

.. warning:: ``HildonBreadCrumbIface`` is deprecated and should not be used in newly-written code.



.. _hildon-bread-crumb-get-natural-size:

.. function:: hildon_bread_crumb_get_natural_size ()

::

  void                hildon_bread_crumb_get_natural_size (HildonBreadCrumb *bread_crumb,
                                                           gint *width,
                                                           gint *height);

.. warning:: ``hildon_bread_crumb_get_natural_size`` is deprecated and should not be used in newly-written code.

Function to ask the ``bread_crumb`` its preferred width and height requisition. Natural size is different to size_request in that it's not the minimum space the widget needs, but the ideal space it'd like to be allocated. For example, in the case of a label the natural size would be the width and height needed to show the full label without line breaks.



``bread_crumb``:
  A `HildonBreadCrumb <HildonBreadCrumb>`_


``width``:
  location to store the natural width request of the ``bread_crumb``\


``height``:
  location to store the natural height request of the ``bread_crumb``\


.. _hildon-bread-crumb-activated:

.. function:: hildon_bread_crumb_activated ()

::

  void                hildon_bread_crumb_activated        (HildonBreadCrumb *bread_crumb);

.. warning:: ``hildon_bread_crumb_activated`` is deprecated and should not be used in newly-written code.

Emits the "crumb-activated" signal. The signal is meant to indicate that the user has interacted with the bread crumb.



``bread_crumb``:
  a `HildonBreadCrumb <HildonBreadCrumb>`_



.. _ch-Utilities:

Utilities
#########

Apart from the widgets, Hildon provides a set of helper functions and objects to make easier the development of applications. This chapter will review them and explain how they can you help.

The Program object
******************

Hildon provides an object to represent a whole application, the HildonProgramObject. This object provides several convenience functions that make it easier to develop Hildon applications.

The HildonProgram provides the programmer with commodities such as applying a common menu or toolbar to every HildonWindow registered to it.

It is necessary to register all the windows as belonging to the program in order to apply a common menu and toolbar.

To register or unregister windows you should use the following functions:

::

  
  void        hildon_program_add_window       (HildonProgram *self,
                                               HildonWindow *window);
  void        hildon_program_remove_window    (HildonProgram *self,
                                               HildonWindow *window);
      
And the following functions will take effect over each registered window. This is a convenient way to setup common elements for each registered window in your application.

::

  
  
  void           hildon_program_set_common_menu        (HildonProgram *self,
                                                        GtkMenu *menu);
  GtkMenu*       hildon_program_get_common_menu        (HildonProgram *self);
  void           hildon_program_set_common_app_menu    (HildonProgram *self,
                                                        HildonAppMenu *menu);
  HildonAppMenu* hildon_program_get_common_app_menu    (HildonProgram *self);
  void           hildon_program_set_common_toolbar     (HildonProgram *self,
                                                        GtkToolbar *toolbar);
  GtkToolbar*    hildon_program_get_common_toolbar     (HildonProgram *self);
  
      
HildonProgram also allows users to apply program-wide properties. For example, the property "can-hibernate" that specify whether the program should be set to hibernate by the Task Navigator in a low memory situation or not.

The following convenience functions are provided to set and retrieve the value of the property "can-hibernate".

::

  
  
  void        hildon_program_set_can_hibernate      (HildonProgram *self,
                                                     gboolean can_hibernate);
  gboolean    hildon_program_get_can_hibernate      (HildonProgram *self);
  
      
@@COMMENT@@[Here a simple example of use of the HildonProgram object.]

Sound utilities
***************

Hildon provides the following function to play a sample. The function receives the sample file name as parameter and the volume level is controlled by the gconf variable */apps/osso/sound/system_alert_volume*\

::

  
  
  void        hildon_play_system_sound        (const gchar *sample);
  
      
Miscellaneous Helper Functions
******************************

Text Font and Colors
====================

The following funtions allows you to set a font or color for the text diplayed by a certain widget. The size or color is identified by a logical name which should be defined by the GTK's rc files defined as part of the themes definition.

Since logical names are used to identify the colors and font, they are independent from the theme, meaning that if the theme is changed the widget keeps the same logical font or color set by these functions.

::

  
  
  gulong      hildon_helper_set_logical_font  (GtkWidget *widget,
                                               const gchar *logicalfontname);
  gulong      hildon_helper_set_logical_color (GtkWidget *widget,
                                               GtkRcFlags rcflags,
                                               GtkStateType state,
                                               const gchar *logicalcolorname);
          
        
These functions achieve to keep the set logical font or color by connecting to "style-set" signal. The returned signal identifier can be used to disconnect the signal.

To set a logical color is necessary to pass in the GtkRcFlags and GtkStateType to indicate which color you want to modify. For example, to modify the foreground color of the widget during normal operations then set rcflags to GTK_RC_BG and state to GTK_STATE_NORMAL.

Finger Events
=============

The following function can be in callbacks that handle button events to check if the given button event is a finger event, meaning that the event was emitted as a result of a push with the finger somewhere on the touchscreen.

::

  
  
  gboolean    hildon_helper_event_button_is_finger (GdkEventButton *event);
  
        
This function is rarely used in applications development.

Thumbable Scrollbars
====================

The function showed bellow enables a thumb scrollbar on a given scrolled window, converting the existing normal scrollbar into a larger, finger-usable scrollbar that works without a stylus.

::

  
  
  void        hildon_helper_set_thumb_scrollbar (GtkScrolledWindow *win,
                                                 gboolean thumb);
  
        

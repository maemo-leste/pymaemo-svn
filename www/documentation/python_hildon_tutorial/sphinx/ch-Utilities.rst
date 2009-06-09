.. _ch-Utilities:

Utilities
#########

Apart from the widgets, Hildon provides a set of helper functions and objects to make easier the development of applications. This chapter will review them and explain how they can help you.

The Program object
******************

Hildon provides an object to represent a whole application, the hildon.ProgramObject. This object provides several convenience functions that make it easier to develop Hildon applications.

The hildon.Program provides the programmer with commodities such as applying a common menu or toolbar to every hildon.Window registered to it.

It is necessary to register all the windows as belonging to the program in order to apply a common menu and toolbar.

To register or unregister windows you should use the following functions:

::

  def add_window(self, window)
  def remove_window(self, window)
     
And the following functions will take effect over each registered window. This is a convenient way to setup common elements for each registered window in your application.

::

  def set_common_menu(self, menu)
  def get_common_menu(self)
  def set_common_toolbar(self, toolbar)
  def get_common_toolbar(self)
  
      
hildon.Program also allows users to apply program-wide properties. For example, the property "can-hibernate" that specify whether the program should be set to hibernate by the Task Navigator in a low memory situation or not.

The following convenience functions are provided to set and retrieve the value of the property "can-hibernate".

::

  def set_can_hibernat(self, can_hibernate) 
  def get_can_hibernate(self)
  
      
Sound utilities
***************

Hildon provides the following function to play a sample. The function receives the sample file name as parameter and the volume level is controlled by the gconf variable */apps/osso/sound/system_alert_volume*\

::

  def hildon_play_system_sound (sample)
  
      
Miscellaneous Helper Functions
******************************

Text Font and Colors
====================

The following funtions allows you to set a font or color for the text diplayed by a certain widget. The size or color is identified by a logical name which should be defined by the GTK's rc files defined as part of the themes definition.

Since logical names are used to identify the colors and font, they are independent from the theme, meaning that if the theme is changed the widget keeps the same logical font or color set by these functions.

::

  
  def set_logical_font(widget, logicalfontname)
  def set_logical_color(widget, rcflags, state, logicalcolorname)
          
        
These functions achieve to keep the set logical font or color by connecting to "style-set" signal. The returned signal identifier can be used to disconnect the signal.

To set a logical color is necessary to pass in the gtk.RcFlags and gtk.StateType to indicate which color you want to modify. For example, to modify the foreground color of the widget during normal operations then set rcflags to gtk.RC_BG and state to gtk.STATE_NORMAL.

Finger Events
=============

The following function can be in callbacks that handle button events to check if the given button event is a finger event, meaning that the event was emitted as a result of a push with the finger somewhere on the touchscreen.

::

  def hildon_helper_event_button_is_finger(event)
  
        
This function is rarely used in applications development.

Thumbable Scrollbars
====================

The function showed bellow enables a thumb scrollbar on a given scrolled window, converting the existing normal scrollbar into a larger, finger-usable scrollbar that works without a stylus.

::

  def hildon_helper_set_thumb_scrollbar(win, thumb) 
  
        

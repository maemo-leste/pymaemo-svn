.. _ch-Controls:

Controls
########

Hildon provides a set of controls specially designed for touchscreens that allows to build simple and easy-to-use interfaces. This chapter explains how to use these widgets.

Buttons
*******

There are several types of buttons that can be used in a Hildon application. Hildon provides specialized buttons derived from gtk.Button which provide additional commodities specific to the Hildon framework. And it is also adviced the use of gtk.Buttons and gtk.ToggleButtons as it will will expalin in this chapter. We will begin reviewing the Hildon specific buttons.

Hildon Button
=============

hildon.Button is a gtk.Button which usually contains two labels, named title and value and also can include an image.

To create a hildon.Button you can use the following functions:

::
  
  button = hildon.Button(size, arrangement, title='', value='')
  

Note that in the creation of a hildon.Button you must indicate the value for the properties "size" and "arrangement", choosing a Hildon size and a hildon.BUTTON_ARRANGEMENT_HORIZONTAL or hildon.BUTTON_ARRANGEMENT_VERTICAL arrangement of the labels.

Both labels can be set and retrieved by using the following convenience functions.

::
  
  hildon.Button.set_title(title)
  hildon.Button.set_value(value)
  title = hildon.Button.get_title()
  value = hildon.Button.get_value()
  

Alternatively, there is a convenience function to set both labels of a hildon.Button.

::
  
  hildon.Button.set_text(title, value)
  

Regarding images into hildon.Buttons, there are functions to set and retrieve the current image using hildon.Button.set_image() and hildon.Button.get_image().

You can also select the position of the image.

::
  
  hildon.Button.set_image_position(position)
  

Currently supported positions are gtk.POS_LEFT or gtk.POS_RIGHT.

The visual style (color, fonts, etc) of a hildon.Button can be changed by using the function hildon.Button.set_style(). Use hildon.ButtonStyle.normal to make it look like a normal hildon.Button, or hildon.ButtonStyle.picker to make it look like a hildon.PickerButton.

The next simple example shows how to create a hildon.Button and set the text which will be shown by the label, an image is added as well.

Example of a Hildon button with a label and an image
====================================================

::
  
  def create_button():
      # Create a hildon button
      button = hildon.Button(gtk.HILDON_SIZE_AUTO_WIDTH | gtk.HILDON_SIZE_FINGER_HEIGHT,
                             hildon.BUTTON_ARRANGEMENT_VERTICAL)
      
      # Set labels value
      button.set_text("Some title", "Some value")
      
      # Set image
      image = gtk.image_new_from_stock(gtk.STOCK_INFO, gtk.ICON_SIZE_BUTTON)
      button.set_image(image)
      button.set_image_position(gtk.POS_RIGHT)
      
      return button
  

Hildon Check Button
===================

hildon.CheckButton is a button containing a label and a check box which when pressed will toggle its state between checked or unchecked.

To create a hildon.CheckButton:

::
  
  button = hildon.CheckButton(size)
  

Note that, again, it is needed to indicate a size for the button.

The current state of the button can be retrieve or set with the following functions, respectively.

::
  
  is_active = hildon.CheckButton.get_active()
  hildon.CheckButton.set_active(is_active)
  

The signal "toggled" is emitted when the state of the button changes. A handler could be attached to this signal if it is necessary to perform a further action.

Here is a simple example which creates a check button and a simple callback to handle the signal "toggled".

Example of a Hildon check button
================================

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
  

Using Gtk Buttons and Toggles
=============================

As was said above, apart from Hildon specific buttons the use of gtk.Button and gtk.ToggleButton is also adviced in the Hildon framework.

hildon.GtkButton
================

When just a label is needed you do not need to use hildon.Buttons and a hildon.GtkButton can be used instead. You can use it as you would do in a GTK application. The only change is the creation function that you should use:

::
  
  button = hildon.GtkButton(size)
  

This alternative constructor allows you to set a Hildon size for the newly create function.

hildon.GtkToggleButton
======================

To create a hildon.GtkToggleButton in a Hildon application you should use:

::
  
  togglebutton = hildon.GtkToggleButton(size)
  

hildon.GtkRadioButton
=====================

To create a hildon.GtkRadioButton in a Hildon application you should use:

::
  
  radiobutton = hildon.GtkRadioButton(size, group)
  

The most common use case of this type of buttons in a Hildon application is as filters in a application menu. In the section Touch View Menu you can read more details about how this topic.

Text Display and Handling
*************************

Text entry fields are used for entering one or more lines of plain text. Use a hildon.Entry for a single-line text input or hildon.TextView if you need a multi-line text input.

Hildon Text Entry
=================

The hildon.Entry is a GTK+ widget which represents a text entry. It is derived from the gtk.Entry widget and provides additional commodities specific to the Hildon framework.

The main additional feature is that it can have a placeholder text which is shown if the entry is empty and does not have the focus.

Creating a new hildon.Entry:

::
  
  entry = hildon.Entry(size)
  

Note that the creation function needs to specify a size from ``HildonSizeType``\

The placeholder is stored as a property and a convenience function to set it is provided:

::
  
  hildon.Entry.set_placeholder(text)
  

Here's a very simple example showing how to create a hindon.Entry.

Example of a Hildon entry
=========================

::
  
  def create_entry():
      entry = hildon.Entry(gtk.HILDON_SIZE_AUTO)
      entry.set_placeholder("First name")
      return entry
  

Hildon Text Area
================

The hildon.TextView is a GTK+ widget which represents a text area in Hildon applications. It is derived from the gtk.TextView widget and provides additional commodities specific to the Hildon framework.

Create a hildon.TextView:

::
  
  textview = hildon.TextView()
  

Like for the hildon.TextEntry presented above, a placeholder can be stored as well using the function .

::
  
  hildon.TextView.set_placeholder(text)
        

The text that is being edited with a hildon.TextView is represented by a object gtk.TextBuffer. Below, you can find functions to set and retrieve the buffer associated with a hildon.TextView.

::
  
  hildon.TextView.set_buffer(buffer)
  textbuffer = hildon.TextView.get_buffer()
  

Here is an example that shows how to create a hildon.TextView and how to set its placeholder. Also, the buffer is retrieved and a function is set as a handler to the "changed" of the buffer. The handler simply gets the text from the hildon.TextView's buffer and prints it.

Example of a Hildon text view with a placeholder
================================================

::
  
  def text_changed(buffer):
      start = buffer.get_start_iter()
      
      end = buffer.get_end_iter()
      text = buffer.get_text(start, end, false)
      
      print text
  
  def create_text_view():
      text_view = hildon.TextView()
      text_view.set_placeholder("Type some text here")
      
      buffer = text_view.get_buffer()
      buffer.connect("changed", text_changed)
      
      return text_view
  

.. _section-notification-widgets:

Notification widgets
********************

To cover the main use cases regarding notification of users, Hildon provides banners and notes. Banner widgets display a text information during a certain period of time. Notes are specialized gtk.Dialogs that need a small amount of input from the user.

Banners
=======

A hildon.Banner is useful to display information which does not need any user response. This widget automatically disappears after a certain time period.

To create and show a banner you can use:

::
  
  banner = hildon.hildon_banner_show_information(widget, icon_name, text)
  
  banner = hildon.hildon_banner_show_information_with_markup(widget, icon_name, markup)
    

All functions above require a widget as an argument that should be a pointer to the owner widget of the banner. Usually, the owner is the window that represents the currently displayed view.

Function hildon.hildon_banner_show_information() shows a banner with the given text.

You can also apply a `Pango markup <http://maemo.org/api_refs/5.0/beta/pango/PangoMarkupFormat.html>`_ and add some attributes to the displayed text. To do that you can either use hildon.hildon_banner_show_information_with_markup() to create the banner or setup the markup by calling hildon.Banner.set_markup() after the initialization.

.. warning:: Currently, icons are not displayed in banners, so any value that you pass as the icon_name will be ignored.

The period of time after the banner automatically disappear is stored in the property "timeout" (in miliseconds). A convenience function to set this property is provided:

::
  
  hildon.Banner.set_timeout(timeout)
    

Here is a simple example showing how to setup and show an informational banner.

Setting up an informational banner
==================================

::
  
  # Create a banner with a markup
  banner = hildon.Banner.show_information_with_markup(widget, None, "<b>Information banner</b>")
  banner.set_timeout(9000)
  

.. note:: For each window in your application there can only be one timed banner, so if you spawn a new banner before the earlier one has timed out, the previous one will be replaced.

Notes
=====

hildon.Notes are gtk.Dialogs designed to request a small amount of input from users. Usually, notes show an information text and buttons to confirm, cancel, etc. according to their type.

Unlike banners, notes always need a user action, that is, notes do not disappear automatically after a period of time.

The hildon.Note widget provides functions to create and show different types of notes: information notes, confirmation notes and cancel notes.

::
  
  def hildon_note_new_information(parent, description)
  def hildon_note_new_information_with_icon_name(parent, description, icon_name)
  def hildon_note_new_confirmation(parent, description)
  def hildon_note_new_confirmation_with_icon_name(parent, description, icon_name)
  def hildon_note_new_cancel_with_progress_bar(parent, description, progressbar)
  

Every function to create notes receives as a parameter the parent window of the newly created note. This is important so that the window manager can handle the windows properly.

Below, each different type of note will be explain.

Information Notes
=================

Information notes are used to show an information to the users. This note disappears when user taps outside the note's area. Otherwise the note remains visible.

Here's an example of how to show an information note and handle the user's answer.

Example of a Hildon information note
====================================

::
  
  def show_information_note(parent):
      note = hildon.hildon_note_new_information(parent, \
          "Lorem ipsum dolor sit amet, consectetur adipiscing elit." \
          "Maecenas tristique dictum est. Aenean rhoncus aliquam mi." \
          "In hac habitasse platea dictumst.")
      
      response = gtk.Dialog.run(note)
      
      if response == gtk.RESPONSE_DELETE_EVENT:
          print "show_information_note: gtk.RESPONSE_DELETE_EVENT"
  

Confirmation Notes
==================

Confirmation notes show an information text that is usually a question and two buttons labelled "Yes" and "No".

You can use hildon.hildon_note_new_confirmation() to create a confirmation note with the text you specify and two buttons labelled "Yes"/"No" as follows:

Example of a Hildon confirmation note
=====================================

::
  
  def show_confirmation_note(parent):
      note = hildon.hildon_note_new_confirmation(parent, "Do you want foo ?")
      
      response = gtk.Dialog.run(note)
      
      if response == gtk.RESPONSE_DELETE_EVENT:
          print "show_information_note: gtk.RESPONSE_DELETE_EVENT"
  

Alternatively, you can use hildon.Note.add_buttons() to create a confirmation note with custom buttons.

Example of a Hildon copnfirmation note with custom buttons
==========================================================

::
  
  def show_confirmation_note_with_buttons(parent):
      note = hildon.hildon_note_new_confirmation(parent, "Do you want foo ?")
      note.add_buttons("ACCEPT", gtk.RESPONSE_OK, \
                       "CANCEL", gtk.RESPONSE_CANCEL, \
                       "DELETE", gtk.RESPONSE_DELETE_EVENT)
      
      response = gtk.Dialog.run(note)
      
      if response == gtk.RESPONSE_DELETE_EVENT:
          print "show_information_note: gtk.RESPONSE_DELETE_EVENT"
  

Cancel Notes
============

A cancel note displays a text, a Cancel button and a progress bar. They are useful to tell users that a long task is in progress. Also, cancel notes allow users to cancel the task in progress.

Next example shows how to create a cancel note with a progress bar. Note that to control the progress bar, additional code would be needed.

Example of a Hildon cancel note with a progress bar
===================================================

::
  
  def show_information_note_with_progress_bar(parent):
      progressbar = gtk.ProgressBar()
      note = hildon.hildon_note_new_cancel_with_progress_bar(parent,
                                                             "A large task is happening",
                                                             progressbar)
      
      response = gtk.Dialog.run(note)
      
      if response == gtk.RESPONSE_DELETE_EVENT:
          print "show_information_note: gtk.RESPONSE_DELETE_EVENT"
  


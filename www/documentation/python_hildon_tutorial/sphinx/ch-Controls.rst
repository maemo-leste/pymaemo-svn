.. _ch-Controls:

Controls
########

Hildon provides a set of controls specially designed for touchscreens that allows to build simple and easy-to-use interfaces. This chapter explains how to use these widgets.

Buttons
*******

There are several types of buttons that can be used in a Hildon application. Hildon provides specialized buttons derived from GtkButton which provide additional commodities specific to the Hildon framework. And it is also adviced the use of GtkButtons and GtkToggleButtons as it will will expalin in this chapter. We will begin reviewing the Hildon specific buttons.

Hildon Button
=============

HildonButton is a GtkButton which usually contains two labels, named title and value and also can include an image.

To create a HildonButton you can use the following functions:

::

  
  
  GtkWidget*  hildon_button_new               (HildonSizeType size,
                                               HildonButtonArrangement arrangement);
  GtkWidget*  hildon_button_new_with_text     (HildonSizeType size,
                                               HildonButtonArrangement arrangement,
                                               const gchar *title,
                                               const gchar *value)
  
        
Note that in the creation of a HildonButton you must indicate the value for the properties "size" and "arrangement", choosing a Hildon size and a horizontal or vertical arrangement of the labels.

Both labels can be set and retrieved by using the following convenience functions.

::

  
  
  void        hildon_button_set_title         (HildonButton *button,
                                               const gchar *title);
  void        hildon_button_set_value         (HildonButton *button,
                                               const gchar *value);
  const gchar* hildon_button_get_title        (HildonButton *button);
  const gchar* hildon_button_get_value        (HildonButton *button);
  
        
Alternatively, there is a convenience function to set both labels of a HildonButton.

::

  
  
  void        hildon_button_set_text          (HildonButton *button,
                                               const gchar *title,
                                               const gchar *value);
  
        
Regarding images into HildonButtons, there are functions to set and retrieve the current image using hildon_button_set_image() and hildon_button_get_image().

You can also select the position of the image.

::

  
  
  void        hildon_button_set_image_position (HildonButton *button,
                                                GtkPositionType position);
  
        
Currently supported positions are GTK_POS_LEFT or GTK_POS_RIGHT.

The visual style (color, fonts, etc) of a HildonButton can be changed by using the function hildon_button_set_style(). Use HILDON_BUTTON_STYLE_NORMAL to make it look like a normal HildonButton, or HILDON_BUTTON_STYLE_PICKER to make it look like a HildonPickerButton.

The next simple example shows how to create a HildonButton and set the text which will be shown by the label, an image is added as well.

Example of a Hildon button with a label and an image
====================================================

.. code-block:: python

  
  
  GtkWidget *
  create_button (void)
  {
      GtkWidget *button;
      GtkWidget *image;
  
      /* Create a hildon button */
      button = hildon_button_new (HILDON_SIZE_AUTO_WIDTH | HILDON_SIZE_FINGER_HEIGHT,
                                  HILDON_BUTTON_ARRANGEMENT_VERTICAL);
  
      /* Set labels value */
      hildon_button_set_text (HILDON_BUTTON (button), "Some title", "Some value");
  
      /* Set image */
      image = gtk_image_new_from_stock (GTK_STOCK_INFO, GTK_ICON_SIZE_BUTTON);
      hildon_button_set_image (HILDON_BUTTON (button), image);
      hildon_button_set_image_position (HILDON_BUTTON (button), GTK_POS_RIGHT);
  
      return button;
  }
  
          
Hildon Check Button
===================

HildonCheckButton is a button containing a label and a check box which when pressed will toggle its state between checked or unchecked.

To create a HildonCheckButton:

::

  
  
  GtkWidget*  hildon_check_button_new         (HildonSizeType size);
  
        
Note that, again, it is needed to indicate a size for the button.

The current state of the button can be retrieve or set with the following functions, respectively.

::

  
  
  gboolean    hildon_check_button_get_active  (HildonCheckButton *button);
  
  void        hildon_check_button_set_active  (HildonCheckButton *button,
                                               gboolean is_active);
  
        
The signal "toggled" is emitted when the state of the button changes. A handler could be attached to this signal if it is necessary to perform a further action.

Here is a simple example which creates a check button and a simple callback to handle the signal "toggled".

Example of a Hildon check button
================================

.. code-block:: python

  
  
  void
  button_toggled (HildonCheckButton *button, gpointer user_data)
  {
      gboolean active;
  
      active = hildon_check_button_get_active (button);
      if (active)
         g_debug ("Button is active");
      else
         g_debug ("Button is not active");
  }
  
  GtkWidget *
  create_button (void)
  {
      GtkWidget *button;
  
      button = hildon_check_button_new (HILDON_SIZE_AUTO);
      gtk_button_set_label (GTK_BUTTON (button), "Click me");
  
      g_signal_connect (button, "toggled", G_CALLBACK (button_toggled), NULL);
  
      return button;
  }
  
          
Using Gtk Buttons and Toggles
=============================

As was said above, apart from Hildon specific buttons the use of GtkButton and GtkToggleButton is also adviced in the Hildon framework.

GtkButton
=========

When just a label is needed you do not need to use HildonButtons and a GtkButton can be used instead. You can use it as you would do in a GTK application. The only change is the creation function that you should use:

::

  
  
  GtkWidget*  hildon_gtk_button_new           (HildonSizeType size);
  
          
This alternative constructor allows you to set a Hildon size for the newly create function.

GtkToggleButton
===============

To create a GtkToggleButton in a Hildon application you should use:

::

  
  
  GtkWidget*  hildon_gtk_toggle_button_new    (HildonSizeType size);
  
          
GtkRadioButton
==============

To create a GtkRadioButton in a Hildon application you should use:

::

  
  
  GtkWidget*  hildon_gtk_radio_button_new     (HildonSizeType size,
                                               GSList *group);
  
          
The most common use case of this type of buttons in a Hildon application is as filters in a application menu. In the section Touch View Menu you can read more details about how this topic.

Text Display and Handling
*************************

Text entry fields are used for entering one or more lines of plain text. Use a HildonEntry for a single-line text input or HildonTextView if you need a multi-line text input.

Hildon Text Entry
=================

The HildonEntry is a GTK+ widget which represents a text entry. It is derived from the GtkEntry widget and provides additional commodities specific to the Hildon framework.

The main additional feature is that it can have a placeholder text which is shown if the entry is empty and does not have the focus.

Creating a new HildonEntry:

::

  
  
  GtkWidget*  hildon_entry_new                (HildonSizeType size);
  
        
Note that the creation function needs to specify a size from ``HildonSizeType``\

The placeholder is stored as a property and a convenience function to set it is provided:

::

  
  
  void        hildon_entry_set_placeholder    (HildonEntry *entry,
                                               const gchar *text);
  
        
Here's a very simple example showing how to create a HindonEntry.

Example of a Hildon entry
=========================

.. code-block:: python

  
  
  GtkWidget *
  create_entry (void)
  {
      GtkWidget *entry;
  
      entry = hildon_entry_new (HILDON_SIZE_AUTO);
      hildon_entry_set_placeholder (HILDON_ENTRY (entry),
  	                          "First name");
  
      return entry;
  }
  
          
Hildon Text Area
================

The HildonTextView is a GTK+ widget which represents a text area in Hildon applications. It is derived from the GtkTextView widget and provides additional commodities specific to the Hildon framework.

Create a HildonTextView:

::

  
  
  GtkWidget*  hildon_text_view_new            (void);
  
        
Like for the HildonTextEntry presented above, a placeholder can be stored as well using the function .

::

  
  
  void        hildon_text_view_set_placeholder    (HildonEntry *entry,
                                                   const gchar *text);
  
        
The text that is being edited with a HildonTextView is represented by a object GtkTextBuffer. Below, you can find functions to set and retrieve the buffer associated with a HildonTextView.

::

  
  void        hildon_text_view_set_buffer         (HildonTextView *text_view,
                                                   GtkTextBuffer *buffer);
  GtkTextBuffer* hildon_text_view_get_buffer      (HildonTextView *text_view);
        
Here is an example that shows how to create a HildonTextView and how to set its placeholder. Also, the buffer is retrieved and a function is set as a handler to the "changed" of the buffer. The handler simply gets the text from the HildonTextView's buffer and prints it.

Example of a Hildon text view with a placeholder
================================================

.. code-block:: python

  
  
  static void
  text_changed                                    (GtkTextBuffer *buffer,
                                                   gpointer      *user_data)
  {
      gchar *text;
      GtkTextIter start, end;
  
      gtk_text_buffer_get_start_iter (buffer, &start);
      gtk_text_buffer_get_end_iter (buffer, &end);
  
      text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);
  
      g_debug (text);
  }
  
  GtkWidget *
  create_text_view (void)
  {
      GtkWidget *text_view;
  
      text_view = hildon_text_view_new();
      hildon_text_view_set_placeholder (HILDON_TEXT_VIEW (text_view),
                                        "Type some text here");
  
      buffer = hildon_text_view_get_buffer (textview);
  
      g_signal_connect (buffer,
                        "changed",
                        G_CALLBACK (text_changed),
                        NULL);
  
      return text_view;
  }
  
          
.. warning:: Although HildonTextView is derived from GtkTextView, gtk_text_view_get_buffer() and gtk_text_view_set_buffer() must never be used to get/set the buffer in this widget, hildon_text_view_get_buffer() and hildon_text_view_set_buffer() must be used instead.

.. _section-notification-widgets:

Notification widgets
********************

To cover the main use cases regarding notification of users, Hildon provides banners and notes. Banner widgets display a text information during a certain period of time. Notes are specialized GtkDialogs that need a small amount of input from the user.

Banners
=======

A HildonBanner is useful to display information which does not need any user response. This widget automatically disappears after a certain time period.

To create and show a banner you can use:

::

  
  
  GtkWidget*  hildon_banner_show_information  (GtkWidget *widget,
                                               const gchar *icon_name,
                                               const gchar *text);
  
  GtkWidget*  hildon_banner_show_informationf (GtkWidget *widget,
                                               const gchar *icon_name,
                                               const gchar *format,
                                               ...);
  
  GtkWidget*  hildon_banner_show_information_with_markup
                                              (GtkWidget *widget,
                                               const gchar *icon_name,
                                               const gchar *markup);
  
        
All functions above require a widget as an argument that should be a pointer to the owner widget of the banner. Usually, the owner is the window that represents the currently displayed view.

Function hildon_banner_show_information() shows a banner with the given text.

Function hildon_banner_show_informationf() shows a banner which displays the text given by the printf-like formated string applied to the parameters that the rest of the function's arguments represent.

You can also apply a Pango markup and add some attributes to the displayed text. To do that you can either use hildon_banner_show_information_with_markup() to create the banner or setup the markup by calling hildon_banner_set_markup() after the initialization. [ @@COMMENT@@ LINK TO PANGO MARKUP]

.. warning:: Currently, icons are not displayed in banners, so any value that you pass as the icon_name will be ignored.

The period of time after the banner automatically disappear is stored in the property "timeout" (in miliseconds). A convenience function to set this property is provided:

::

  
  
  void        hildon_banner_set_timeout       (HildonBanner *self,
                                               guint timeout);
  
        
Here is a simple example showing how to setup and show an informational banner.

Setting up an informational banner
==================================

.. code-block:: python

  
  
      GtkWidget* banner;
  
      /* Create a banner with a markup */
      banner = hildon_banner_show_information_with_markup (widget,
                                                           NULL,
                                                           "<b>Information banner</b>");
  
      hildon_banner_set_timeout (HILDON_BANNER (banner), 9000);
  
          
.. note:: For each window in your application there can only be one timed banner, so if you spawn a new banner before the earlier one has timed out, the previous one will be replaced.

Notes
=====

HildonNotes are GtkDialogs designed to request a small amount of input from users. Usually, notes show an information text and buttons to confirm, cancel, etc. according to their type.

Unlike banners, notes always need a user action, that is, notes do not disappear automatically after a period of time.

The HildonNote widget provides functions to create and show different types of notes: information notes, confirmation notes and cancel notes.

::

  
  
  GtkWidget*  hildon_note_new_information     (GtkWindow *parent,
                                               const gchar *description);
  GtkWidget*  hildon_note_new_confirmation    (GtkWindow *parent,
                                               const gchar *description);
  GtkWidget*  hildon_note_new_confirmation_add_buttons
                                              (GtkWindow *parent,
                                               const gchar *description,
                                               ...);
  GtkWidget*  hildon_note_new_cancel_with_progress_bar
                                              (GtkWindow *parent,
                                               const gchar *description,
                                               GtkProgressBar *progressbar);
  
        
Every function to create notes receives as a parameter the parent window of the newly created note. This is important so that the window manager can handle the windows properly.

Below, each different type of note will be explain.

Information Notes
=================

Information notes are used to show an information to the users. This note disappears when user taps outside the note's area. Otherwise the note remains visible.

Here's an example of how to show an information note and handle the user's answer.

Example of a Hildon information note
====================================

.. code-block:: python

  
  
  static void
  show_information_note                          (GtkWidget *parent)
  {
    GtkWidget *window, *note;
    gint response;
  
    note = hildon_note_new_information (NULL,
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
      "Maecenas tristique dictum est. Aenean rhoncus aliquam mi."
      "In hac habitasse platea dictumst.");
  
    response = gtk_dialog_run (GTK_DIALOG (note));
  
    if (response == GTK_RESPONSE_DELETE_EVENT)
      g_debug ("%s: GTK_RESPONSE_DELETE_EVENT", __FUNCTION__);
  
    gtk_object_destroy (GTK_OBJECT (note));
  }
  
            
Confirmation Notes
==================

Confirmation notes show an information text that is usually a question and two buttons labelled "Yes" and "No".

You can use hildon_note_new_confirmation() to create a confirmation note with the text you specify and two buttons labelled "Yes"/"No" as follows:

Example of a Hildon confirmation note
=====================================

.. code-block:: python

  
  
  static void
  show_confirmation_note                          (GtkWidget *parent)
  {
      GtkWidget *note;
      gint response;
  
      note = hildon_note_new_confirmation (parent,
                                           "Do you want foo ?");
  
      response = gtk_dialog_run (GTK_DIALOG (note));
  
      if (response == GTK_RESPONSE_DELETE_EVENT)
        g_debug ("%s: GTK_RESPONSE_DELETE_EVENT", __FUNCTION__);
  
      gtk_object_destroy (GTK_OBJECT (note));
  }
  
            
Alternatively, you can use hildon_note_new_confirmation_add_buttons() to create a confirmation note with custom buttons.

Example of a Hildon copnfirmation note with custom buttons
==========================================================

.. code-block:: python

  
  
  static void
  show_confirmation_note                          (GtkWidget *parent)
  {
      GtkWidget *note;
      gint response;
  
      note = hildon_note_new_confirmation_add_buttons(parent,
                                                      "Do you want foo?",
                                                      "ACCEPT", GTK_RESPONSE_OK,
                                                      "CANCEL", GTK_RESPONSE_CANCEL,
                                                      "DELETE", GTK_RESPONSE_DELETE_EVENT);
  
      response = gtk_dialog_run (GTK_DIALOG (note));
  
      if (response == GTK_RESPONSE_DELETE_EVENT)
        g_debug ("%s: GTK_RESPONSE_DELETE_EVENT", __FUNCTION__);
  
      gtk_object_destroy (GTK_OBJECT (note));
  }
  
  	  
Cancel Notes
============

A cancel note displays a text, a Cancel button and a progress bar. They are useful to tell users that a long task is in progress. Also, cancel notes allow users to cancel the task in progress.

Next example shows how to create a cancel note with a progress bar. Note that to control the progress bar, additional code would be needed.

Example of a Hildon cancel note with a progress bar
===================================================

.. code-block:: python

  
  
  static void
  show_information_note                          (GtkWidget *parent)
  {
      GtkWidget *note;
      GtkProgressBar *progressbar;
      gint response;
  
      progressbar = gtk_progress_bar_new ();
  
      note = hildon_note_new_cancel_with_progress_bar (parent,
                                                       "A large task is happening",
                                                       progressbar);
  
      response = gtk_dialog_run (GTK_DIALOG (note));
  
      if (response == GTK_RESPONSE_DELETE_EVENT)
        g_debug ("%s: GTK_RESPONSE_DELETE_EVENT", __FUNCTION__);
  
      gtk_object_destroy (GTK_OBJECT (note));
  }
  
            
PARENT IS MANDATORY ???? EXPLAIN THAT


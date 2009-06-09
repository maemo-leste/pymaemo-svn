.. _hildonmigration:

Migration
#########

This section helps you migrate widgets that are deprecated by providing an alternative to them. Most sections have examples of how a given deprecated widget was used and provide another example of how the functionality of that widget should be accomplished in newly written code.

.. _hildon-migration-control-bar:

Control Bar
***********

.. _hildon-migrating-control-bar:

Migrating Control Bars
======================

ControlBar widgets are deprecated since Hildon 2.2 and a gtk.Scale should be used to accomplish the same functionality.

To make a gtk.Scale have the same functionality as a control bar you'll need to change some properties of the widget's Adjustment so it has a range equal to the control bar's as well as the step increment.

The following example shows a control bar with the range of 0 to 4.

A Typical Control Bar
=====================

::

  bar = hildon.ControlBar()
  bar.set_range(1, 4)
  bar.set_value(2)
  
        
To accomplish the same functionality as the previous control bar example, one could use something like in the following example.

A Replacement for the Control Bar
=================================

::

  scale = hildon.GtkHScale()
  adjustment = scale.get_adjustment()
  adjustment.set_property("step-increment", 1)
  adjustment.set_property("lower", 0)
  adjustment.set_property("upper", 4)
  adjustment.set_property("value", 2) 
          

.. _hildon-migration-volume-bar:

Volume Bar
**********

.. _hildon-migrating-volume-bar:

Migrating Volume Bars
=====================

VolumeBar widgets are deprecated since Hildon 2.2 and the way to exactly reproduce their functionality is to use a gtk.Scale together with a toggle button. Instead of the toggle button, a Hildon picker button could be used or two radio buttons or any other widgets that allow the user to choose from two options. The toggle button is used in this example since it is the very similar with the deprecated volume bar's button.

The deprecated volume bar is shown on the example bellow.

A Typical Volume Bar
====================

::
  
  bar = hildon.VVolumebar()
  bar.set_size_request(-1, 300)
           

A very similar widget can be done like the following example shows.

A Replacement for the Volume Bar
================================

::
  
  def toggle_volume_state_cb (toggle, bar)
      mute = toggle.get_active()
      bar.set_sensitive(!mute)

  bar = hildon.GtkVScale()
  bar.set_size_request(-1, 300)
  bar.set_restrict_to_fill_level(True)
  
  toggle_volume = hildon.GtkToggleButton(gtk.HILDON_SIZE_FINGER_HEIGHT)
  toggle_volume.set_label("Mute")
  toggle_volume.connect("toggled", toggle_volume_state_cb, bar)

  volume = gtk.VBox(0, False)
  volume.add(bar)
  volume.pack_end(toggle_volume, False, False, 0)
           

.. _hildon-migration-date-widgets:

Date Widgets
************

.. _hildon-migrating-date-widgets:

Migrating Date Widgets
======================

Being deprecated since Hildon 2.2, the calendar popup and date editor can be substituded by a hildon.DateButton.

Examples of a typical calendar popup and a date editor are presented bellow.

A Typical Calendar Popup
========================

::

  y = 2009
  m = 4
  d = 25

  popup = hildon.CalendarPopup(parent, y, m, d)
  popup.run()
  (y, m, d) = popup.get_date()
          

A Typical Date Editor
=====================

::

  def on_error (widget, error_type):
      print "Error: %d" % error_type
      return False  

  dialog = gtk.Dialog()
  date_editor = hildon.DateEditor()
  dialog.vbox.pack_start(gtk.Label("Choose a date"), False, False, 10)
  doalog.vbox.pack_start(date_editor, False, False, 10)
  dialog.add_button("Close", gtk.RESPONSE_CANCEL)

  date_editor.connect("date_error", on_error)

  dialog.show_all()  
  dialog.run()

  (y, m, d) = date_editor.get_date()  
           

The following example accomplishes equivalent functionality using a hildon.DateButton.

A Replacement for the Calendar Popup
====================================

::

    
  dialog = gtk.Dialog()
  y = 2009
  m = 3
  d = 25

  date_button = hildon.DateButton(gtk.HILDON_SIZE_THUMB_HEIGHT,
                                  gtk.HILDON_BUTTON_ARRANGEMENT_VERTICAL)
  date_button.set_date(y, m, d)
  dialog.vbox.pack_end(date_button, False, False, 0)

  dialog.show_all()
  dialog.run()
  (y, m, d) = date_button.get_date()
           

Weekday Picker
==============

A weekday picker (deprecated since Hildon 2.2) can be easily replaced by a HildonPickerButton.

The following example presents the deprecated weekday picker in a dialog.

A Typical Weekday Picker
========================

::

  dialog = gtk.Dialog()    
  picker = hildon.WeekdayPicker()
  dialog.pack_start(picker, True, True, 0)
  
  dialog.add_button("Close", gtk.RESPONSE_CLOSE)

  dialog.show_all()
  dialog.run()
  

With a hildon.PickerButton it is easy to add the weekdays to its TouchSelector and thus having the same functionality.

A Replacement for the Weekday Picker
====================================

::

  
  
  dialog = gtk.Dialog()    
  picker = hildon.PickerButton(gtk.HILDON_SIZE_THUMB_HEIGHT,
                               gtk.HILDON_BUTTON_ARRANGEMENT_VERTICAL)
  picker.set_title("Weekday:")
  selector = hildon.hildon_touch_selector_new_text()

  weekdays = ["Sunday", "Monday", "Tuesday", "Thursday", "Friday", "Saturday"]
  for day_name in weekdays:
    selector.append_text(day_name)

  selector.set_column_selection_mode(hildon.SELECTION_MODE_MULTIPLE)
  picker.set_selector(selector)
  picker.set_active(0)
  
  dialog->vbox->pack_start(picker, True, True, 0)
  dialog.show_all()
  dialog.run()
  

.. _hildon-migration-time-widgets:

Time Widgets
************

.. _hildon-migrating-time-widgets:

Migrating Time Widgets
======================

A hildon.TimeButton is the way to replace the time picker and time editor widgets (deprecated since Hildon version 2.2).

A time picker and time editor are shown in the examples bellow.

A Typical Time Picker
=====================

::

  
  dialog = hildon.TimePicker(None)
  
  dialog.show_all()
  dialog.run()
  
          

A Typical Time Editor
=====================

::

  dialog = gtk.Dialog()
  time_editor = hildon.TimeEditor()
  
  dialog->vbox->pack_start(timer_editor, False, False, 0)
  dialog.add_button("Close", gtk.RESPONSE_CANCEL)
  
  dialog.show_all()
  dialog.run()
  
          

The same functionality can be achieved as the following example shows.

A Replacement for the Time Picker
=================================

::

  dialog = gtk.Dialog()
  time_button = hildon.TimeButton(gtk.HILDON_SIZE_THUMB_HEIGHT,
                                  gtk.HILDON_BUTTON_ARRANGEMENT_VERTICAL)
  dialog.vbox.pack_end(time_button, False, False, 0)
  dialog.show_all()
  dialog.run()

.. _hildon-migration-number-widgets:

Number Widgets
**************

.. _hildon-migrating-number-widgets:

Migrating Number Widgets
========================

To achieve the same functionlity of hildon.NumberEditor you can use a hildon.PickerButton with a hildon.TouchSelectorEntry assigned to it. With these widgets you can also easily have the functionality of a hildon.RangeEditor (not covered in this example). Both the hildon.NumberEditor and the hildon.RangeEditor are deprecated since Hildon 2.2.

The following example shows a typical NumberEditor.

A Typical Number Editor
=======================

::


  dialog = gtk.Dialog()
  editor = hildon.NumberEditor(0, 30)
  label = gtk.Label("Number:")
  hbox = gtk.HBox(False, 12)
  
  hbox.pack_start(label, True, True, 0)
  hbox.pack_start(label, editor, False, False, 0)
  dialog.vbox.pack_start(hbox, True, True, 0)
  
  dialog.show_all()
  dialog.run()
  
          

The functionality of the example above is shown on the example bellow using by validating the HildonPickerButton's value every time it's changed. The choices given in the hildon.TouchSelectorShould be the most common choices.

A Replacement for the Number Editor
===================================

::

  def changed_value_cb (picker, data):
      choice = picker.get_value()
      picker.set_value(str(number))
  
  dialog = gtk.Dialog()
  picker = hildon.PickerButton(gtk.HILDON_SIZE_THUMB_HEIGHT,
                               gtk.HILDON_BUTTON_ARRANGEMENT_VERTICAL)

  picker.set_title("Number:")
  selector = hildon.hildon_touch_selector_entry_new_text()

  values = ["0", "5", "10", "15", "20", "25", "30"]
  for txt in values:
    selector.append_text(txt)

  picker.set_selector(selector)
  picker.set_active(0)
  picker.connect("value-changed", changed_value_cb)
  dialog.vbox.pack_start(picker, True, True, 0)

  dialog.show_all()
  dialog.run()
  
          

.. _hildon-migration-hildon-dialogs:

Hildon Dialogs
**************

.. _hildon-migrating-hildon-dialogs:

Migrating Hildon Dialogs
========================

The substitution of a hildon.Dialog should be easy. Since version 2.2, dialogs in Hildon should be used as normal gtk.Dialog objects.

.. _hildon-migration-sort-dialogs:

Sort Dialogs
************

.. _hildon-migrating-sort-dialogs:

Migrating Sort Dialogs
======================

hildon.SortDialog is deprecated since Hildon 2.2. The correct way to let the user sort contents is with menu filters.

The following example shows a typical NumberEditor.

A Typical Number Editor
=======================

::
  
  dialog = hildon.SortDialog(None)
  dialog.add_sort_key("First key")
  dialog.add_sort_key_reversed("Second, key")
  
          

The functionality of the example above is shown on the example bellow using by validating the hildon.PickerButton's value every time it's changed. The choices given in the hildon.TouchSelectorShould be the most common choices.

A Replacement for the Number Editor
===================================

::

  
  window = hildon.StackableWindow()
  window.set_title("Sort Example")
  
  menu = hildon.AppMenu()
  
  filter = hildon.GtkRadioButton(gtk.HILDON_SIZE_THUMB_HEIGHT, None)
  filter.set_label( "1st Key");
  menu.add_filter(filter)
  filter.set_mode(False)
  filter.set_active(True)
  
  filter = hildon.hildon_gtk_radio_button_new_from_widget(
                              gtk.HILDON_SIZE_FINGER_HEIGHT, filter)
  filter.set_label("2nd Key")
  menu.add_filter(filter)
  filter.set_mode(False)
  
  filter = hildon.GtkRadioButton(gtk.HILDON_SIZE_THUMB_HEIGHT, None)
  filter.set_label(filter, "A-Z")
  menu.add_filter(filter)
  filter.set_mode(False)
  
  filter = hildon.hildon_gtk_radio_button_new_from_widget(
                              gtk.HILDON_SIZE_FINGER_HEIGHT, filter)

  filter.set_label(filter, "Z-A")
  menu.add_filter(filter)
  filter.set_mode(False)
  
  window.set_main_menu(menu)
  
          


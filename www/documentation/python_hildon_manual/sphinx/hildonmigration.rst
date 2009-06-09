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

ControlBar widgets are deprecated since Hildon 2.2 and a GtkScale should be used to accomplish the same functionality.

To make a GtkScale have the same functionality as a control bar you'll need to change some properties of the widget's Adjustment so it has a range equal to the control bar's as well as the step increment.

The following example shows a control bar with the range of 0 to 4.

A Typical Control Bar
=====================

::

  
  
  HildonControlbar *bar = HILDON_CONTROLBAR (hildon_controlbar_new ());
  hildon_controlbar_set_range (bar, 1, 4);
  hildon_controlbar_set_value (bar, 2);
  
          

To accomplish the same functionality as the previous control bar example, one could use something like in the following example.

A Replacement for the Control Bar
=================================

::

  
  
  GtkHScale *scale = GTK_HSCALE (hildon_gtk_hscale_new ());
  GtkAdjustment *adjustment = GTK_ADJUSTMENT (
                          gtk_range_get_adjustment (GTK_RANGE (scale)));
  g_object_set (adjustment, "step-increment", 1, "lower", 0, NULL);
  g_object_set (adjustment, "upper", 4, NULL);
  g_object_set (adjustment, "value", 2, NULL);
  
          

.. _hildon-migration-volume-bar:

Volume Bar
**********

.. _hildon-migrating-volume-bar:

Migrating Volume Bars
=====================

VolumeBar widgets are deprecated since Hildon 2.2 and the way to exactly reproduce their functionality is to use a GtkScale together with a toggle button. Instead of the toggle button, a Hildon picker button could be used or two radio buttons or any other widgets that allow the user to choose from two options. The toggle button is used in this example since it is the very similar with the deprecated volume bar's button.

The deprecated volume bar is shown on the example bellow.

A Typical Volume Bar
====================

::

  
  
  HildonVVolumebar *bar = HILDON_VVOLUMEBAR (hildon_vvolumebar_new ());
  gtk_widget_set_size_request (GTK_WIDGET (bar), -1, 300);
  
          

A very similar widget can be done like the following example shows.

A Replacement for the Volume Bar
================================

::

  
  
  void
  toggle_volume_state_cb (GtkToggleButton *toggle, gpointer data)
  {
      GtkVScale *bar = GTK_VSCALE (data);
      gboolean mute = gtk_toggle_button_get_active (toggle);
      gtk_widget_set_sensitive (GTK_WIDGET (bar), !mute);
  }
  
  GtkVScale *bar = GTK_VSCALE (hildon_gtk_vscale_new ());
  gtk_widget_set_size_request (GTK_WIDGET (bar), -1, 300);
  gtk_range_set_restrict_to_fill_level (GTK_RANGE (bar), TRUE);
  GtkToggleButton *toggle_volume = GTK_TOGGLE_BUTTON (hildon_gtk_toggle_button_new (
                                          HILDON_SIZE_FINGER_HEIGHT));
  gtk_button_set_label (GTK_BUTTON (toggle_volume), "Mute");
  g_signal_connect (toggle_volume, "toggled",
                      G_CALLBACK (toggle_volume_state_cb), bar);
  GtkVBox *volume = GTK_VBOX (gtk_vbox_new (0, FALSE));
  gtk_container_add (GTK_CONTAINER (volume), GTK_WIDGET (bar));
  gtk_box_pack_end (GTK_BOX (volume), GTK_WIDGET (toggle_volume), FALSE, FALSE, 0);
  
          

.. _hildon-migration-date-widgets:

Date Widgets
************

.. _hildon-migrating-date-widgets:

Migrating Date Widgets
======================

Being deprecated since Hildon 2.2, the calendar popup and date editor can be substituded by a HildonDateButton.

Examples of a typical calendar popup and a date editor are presented bellow.

A Typical Calendar Popup
========================

::

  
  
  guint y = 2009, m = 4, d = 25;
  GtkWidget *parent, *popup;
  popup = hildon_calendar_popup_new (GTK_WINDOW (parent), y, m, d);
  gtk_dialog_run (GTK_DIALOG (popup));
  hildon_calendar_popup_get_date (HILDON_CALENDAR_POPUP (popup),
                                          &y, &m, &d);
  
          

A Typical Date Editor
=====================

::

  
  
  gboolean
  on_error (GtkWidget *widget, HildonDateTimeError error_type);
  
  gboolean
  on_error (GtkWidget *widget, HildonDateTimeError error_type)
  {
      g_debug ("Error: %d", error_type);
      return FALSE;
  }
  
  GtkDialog *dialog = GTK_DIALOG (gtk_dialog_new ());
  HildonDateEditor *date_editor = HILDON_DATE_EDITOR (hildon_date_editor_new ());
  
  gtk_box_pack_start (GTK_BOX (dialog->vbox), gtk_label_new ("Choose a date"), FALSE, FALSE, 10);
  gtk_box_pack_start (GTK_BOX (dialog->vbox), GTK_WIDGET (date_editor), FALSE, FALSE, 10);
  gtk_dialog_add_button (dialog, "Close", GTK_RESPONSE_CANCEL);
  
  g_signal_connect (G_OBJECT (date_editor), "date_error", G_CALLBACK (on_error), NULL);
  
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  
  hildon_date_editor_get_date (date_editor, &y, &m, &d);
  
          

The following example accomplishes equivalent functionality using a HildonDateButton.

A Replacement for the Calendar Popup
====================================

::

  
  
  GtkDialog *dialog = GTK_DIALOG (gtk_dialog_new ());
  guint y = 2009, m = 3, d = 25;
  HildonDateButton *date_button = HILDON_DATE_BUTTON (hildon_date_button_new (
              HILDON_SIZE_THUMB_HEIGHT, HILDON_BUTTON_ARRANGEMENT_VERTICAL));
  hildon_date_button_set_date (date_button, y, m, d);
  gtk_box_pack_end (GTK_BOX (dialog->vbox), GTK_WIDGET (date_button), FALSE, FALSE, 0);
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  hildon_date_button_get_date (date_button, &y, &m, &d);
  
          

Weekday Picker
==============

A weekday picker (deprecated since Hildon 2.2) can be easily replaced by a HildonPickerButton.

The following example presents the deprecated weekday picker in a dialog.

A Typical Weekday Picker
========================

::

  
  
  GtkDialog *dialog = GTK_DIALOG (gtk_dialog_new ());
  GtkWidget *picker = hildon_weekday_picker_new ();
  gtk_box_pack_start (GTK_BOX (dialog->vbox), picker, TRUE, TRUE, 0);
  gtk_dialog_add_button (dialog, "Close", GTK_RESPONSE_CLOSE);
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  
          

With a HildonPickerButton it is easy to add the weekdays to its TouchSelector and thus having the same functionality.

A Replacement for the Weekday Picker
====================================

::

  
  
  GtkDialog *dialog = GTK_DIALOG (gtk_dialog_new ());
  GtkWidget *picker = hildon_picker_button_new (HILDON_SIZE_THUMB_HEIGHT,
                                  HILDON_BUTTON_ARRANGEMENT_VERTICAL);
  hildon_button_set_title (HILDON_BUTTON (picker), "Weekday:");
  HildonTouchSelector *selector = HILDON_TOUCH_SELECTOR (
                                  hildon_touch_selector_new_text ());
  hildon_touch_selector_append_text (selector, "Sunday");
  hildon_touch_selector_append_text (selector, "Monday");
  hildon_touch_selector_append_text (selector, "Tuesday");
  hildon_touch_selector_append_text (selector, "Thursday");
  hildon_touch_selector_append_text (selector, "Friday");
  hildon_touch_selector_append_text (selector, "Saturday");
  hildon_touch_selector_set_column_selection_mode (selector,
                      HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE);
                      
  hildon_picker_button_set_selector (HILDON_PICKER_BUTTON (picker), selector);
  hildon_picker_button_set_active (HILDON_PICKER_BUTTON (picker), 0);
  gtk_box_pack_start (GTK_BOX (dialog->vbox), picker, TRUE, TRUE, 0);
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  
          

.. _hildon-migration-time-widgets:

Time Widgets
************

.. _hildon-migrating-time-widgets:

Migrating Time Widgets
======================

A HildonTimeButton is the way to replace the time picker and time editor widgets (deprecated since Hildon version 2.2).

A time picker and time editor are shown in the examples bellow.

A Typical Time Picker
=====================

::

  
  
  GtkDialog *dialog = GTK_DIALOG (hildon_time_picker_new (NULL));
  
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  
          

A Typical Time Editor
=====================

::

  
  
  GtkDialog *dialog = GTK_DIALOG (gtk_dialog_new ());
  HildonTimeEditor *time_editor = HILDON_TIME_EDITOR (hildon_time_editor_new ());
  
  gtk_box_pack_start (GTK_BOX (dialog->vbox), GTK_WIDGET (time_editor), FALSE, FALSE, 0);
  gtk_dialog_add_button (dialog, "Close", GTK_RESPONSE_CANCEL);
  
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  
          

The same functionality can be achieved as the following example shows.

A Replacement for the Time Picker
=================================

::

  
  
  GtkDialog *dialog = GTK_DIALOG (gtk_dialog_new ());
  HildonTimeButton *time_button = HILDON_TIME_BUTTON (hildon_time_button_new (
              HILDON_SIZE_THUMB_HEIGHT, HILDON_BUTTON_ARRANGEMENT_VERTICAL));
  gtk_box_pack_end (GTK_BOX (dialog->vbox), GTK_WIDGET (time_button), FALSE, FALSE, 0);
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  
          

.. _hildon-migration-number-widgets:

Number Widgets
**************

.. _hildon-migrating-number-widgets:

Migrating Number Widgets
========================

To achieve the same functionlity of HildonNumberEditor you can use a HildonPickerButton with a HildonTouchSelectorEntry assigned to it. With these widgets you can also easily have the functionality of a HildonRangeEditor (not covered in this example). Both the HildonNumberEditor and the HildonRangeEditor are deprecated since Hildon 2.2.

The following example shows a typical NumberEditor.

A Typical Number Editor
=======================

::

  
  
  GtkDialog *dialog = GTK_DIALOG (gtk_dialog_new ());
  GtkWidget *editor = hildon_number_editor_new (0, 30);
  GtkWidget *label = gtk_label_new ("Number:");
  GtkWidget *hbox = gtk_hbox_new (FALSE, 12);
  
  gtk_box_pack_start (GTK_BOX (hbox), label, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (hbox), editor, FALSE, FALSE, 0);
  gtk_box_pack_start (GTK_BOX (dialog->vbox), hbox, TRUE, TRUE, 0);
  
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  
          

The functionality of the example above is shown on the example bellow using by validating the HildonPickerButton's value every time it's changed. The choices given in the HildonTouchSelectorShould be the most common choices.

A Replacement for the Number Editor
===================================

::

  
  
  void
  changed_value_cb (HildonPickerButton *picker, gpointer data)
  {
      gdouble number = 0;
      const gchar *choice = hildon_button_get_value(HILDON_BUTTON (picker));
      number = CLAMP(g_ascii_strtod (choice, NULL), 0, 30);
      hildon_button_set_value(HILDON_BUTTON (picker), g_strdup_printf ("%d", (int) number));
  }
  
  GtkDialog *dialog = GTK_DIALOG (gtk_dialog_new ());
  GtkWidget *picker = hildon_picker_button_new (HILDON_SIZE_THUMB_HEIGHT,
                                  HILDON_BUTTON_ARRANGEMENT_VERTICAL);
  hildon_button_set_title (HILDON_BUTTON (picker), "Number:");
  HildonTouchSelector *selector = HILDON_TOUCH_SELECTOR (
                                  hildon_touch_selector_entry_new_text ());
  hildon_touch_selector_append_text (selector, "0");
  hildon_touch_selector_append_text (selector, "5");
  hildon_touch_selector_append_text (selector, "10");
  hildon_touch_selector_append_text (selector, "15");
  hildon_touch_selector_append_text (selector, "20");
  hildon_touch_selector_append_text (selector, "25");
  hildon_touch_selector_append_text (selector, "30");
  hildon_picker_button_set_selector (HILDON_PICKER_BUTTON (picker), selector);
  hildon_picker_button_set_active (HILDON_PICKER_BUTTON (picker), 0);
  g_signal_connect (G_OBJECT (picker), "value-changed",
                                  G_CALLBACK (changed_value_cb), NULL);
  gtk_box_pack_start (GTK_BOX (dialog->vbox), picker, TRUE, TRUE, 0);
  gtk_widget_show_all (GTK_WIDGET (dialog));
  gtk_dialog_run (dialog);
  
          

.. _hildon-migration-hildon-dialogs:

Hildon Dialogs
**************

.. _hildon-migrating-hildon-dialogs:

Migrating Hildon Dialogs
========================

The substitution of a HildonDialog should be easy. Since version 2.2, dialogs in Hildon should be used as normal GtkDialog objects.

.. _hildon-migration-sort-dialogs:

Sort Dialogs
************

.. _hildon-migrating-sort-dialogs:

Migrating Sort Dialogs
======================

HildonSortDialog is deprecated since Hildon 2.2. The correct way to let the user sort contents is with menu filters.

The following example shows a typical NumberEditor.

A Typical Number Editor
=======================

::

  
  
  GtkDialog *dialog = GTK_DIALOG (hildon_sort_dialog_new (NULL));
  
  hildon_sort_dialog_add_sort_key (HILDON_SORT_DIALOG (dialog), "First key");
  hildon_sort_dialog_add_sort_key_reversed (HILDON_SORT_DIALOG (dialog), "Second, key");
  
          

The functionality of the example above is shown on the example bellow using by validating the HildonPickerButton's value every time it's changed. The choices given in the HildonTouchSelectorShould be the most common choices.

A Replacement for the Number Editor
===================================

::

  
  
  GtkRadioButton *filter;
  GtkWidget *window = hildon_stackable_window_new ();
  gtk_window_set_title (GTK_WINDOW (window), "Sort Example");
  
  HildonAppMenu *menu = HILDON_APP_MENU (hildon_app_menu_new ());
  
  filter = GTK_RADIO_BUTTON (hildon_gtk_radio_button_new (
                                  HILDON_SIZE_THUMB_HEIGHT, NULL));
  gtk_button_set_label (GTK_BUTTON (filter), "1st Key");
  hildon_app_menu_add_filter (menu, GTK_BUTTON (filter));
  gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (filter), FALSE);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (filter), TRUE);
  
  filter = GTK_RADIO_BUTTON (hildon_gtk_radio_button_new_from_widget (
                              HILDON_SIZE_FINGER_HEIGHT, filter));
  gtk_button_set_label (GTK_BUTTON (filter), "2nd Key");
  hildon_app_menu_add_filter (menu, GTK_BUTTON (filter));
  gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (filter), FALSE);
  
  filter = GTK_RADIO_BUTTON (hildon_gtk_radio_button_new (
                                  HILDON_SIZE_THUMB_HEIGHT, NULL));
  gtk_button_set_label (GTK_BUTTON (filter), "A-Z");
  hildon_app_menu_add_filter (menu, GTK_BUTTON (filter));
  gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (filter), FALSE);
  
  filter = GTK_RADIO_BUTTON (hildon_gtk_radio_button_new_from_widget (
                              HILDON_SIZE_FINGER_HEIGHT, filter));
  gtk_button_set_label (GTK_BUTTON (filter), "Z-A");
  hildon_app_menu_add_filter (menu, GTK_BUTTON (filter));
  gtk_toggle_button_set_mode (GTK_TOGGLE_BUTTON (filter), FALSE);
  
  hildon_stackable_window_set_main_menu (HILDON_STACKABLE_WINDOW (window), menu);
  
          


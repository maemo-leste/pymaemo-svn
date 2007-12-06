/* -*- Mode: C; c-basic-offset: 4 -*-
 * python-hildon - Python bindings for the Hildon toolkit.
 *
 * hildon-types: definitions that should be in hildon
 *               itself but are not yet.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#include "hildon-types.h"

GType
hildon_note_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_NOTE_CONFIRMATION_TYPE, "HILDON_NOTE_CONFIRMATION_TYPE", "confirmation-type" },
      { HILDON_NOTE_CONFIRMATION_BUTTON_TYPE, "HILDON_NOTE_CONFIRMATION_BUTTON_TYPE", "confirmation-button-type" },
      { HILDON_NOTE_INFORMATION_TYPE, "HILDON_NOTE_INFORMATION_TYPE", "information-type" },
      { HILDON_NOTE_INFORMATION_THEME_TYPE, "HILDON_NOTE_INFORMATION_THEME_TYPE", "information-theme-type" },
      { HILDON_NOTE_PROGRESSBAR_TYPE, "HILDON_NOTE_PROGRESSBAR_TYPE", "progressbar-type" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonNoteType", values);
  }
  return etype;
}

/* Generated data (by glib-mkenums) */


/* enumerations from "/usr/include/hildon-widgets/hildon-date-editor.h" */
GType
hildon_date_editor_error_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { NO_ERROR, "NO_ERROR", "no-error" },
      { MAX_DAY, "MAX_DAY", "max-day" },
      { MAX_MONTH, "MAX_MONTH", "max-month" },
      { MAX_YEAR, "MAX_YEAR", "max-year" },
      { MIN_DAY, "MIN_DAY", "min-day" },
      { MIN_MONTH, "MIN_MONTH", "min-month" },
      { MIN_YEAR, "MIN_YEAR", "min-year" },
      { EMPTY_DAY, "EMPTY_DAY", "empty-day" },
      { EMPTY_MONTH, "EMPTY_MONTH", "empty-month" },
      { EMPTY_YEAR, "EMPTY_YEAR", "empty-year" },
      { INVALID_DATE, "INVALID_DATE", "invalid-date" },
      { INVALID_CHAR, "INVALID_CHAR", "invalid-char" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonDateEditorErrorType", values);
  }
  return etype;
}

/* enumerations from "/usr/include/hildon-widgets/hildon-grid-item.h" */
GType
hildon_grid_position_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_GRID_ITEM_LABEL_POS_BOTTOM, "HILDON_GRID_ITEM_LABEL_POS_BOTTOM", "bottom" },
      { HILDON_GRID_ITEM_LABEL_POS_RIGHT, "HILDON_GRID_ITEM_LABEL_POS_RIGHT", "right" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonGridPositionType", values);
  }
  return etype;
}
GType
hildon_grid_item_icon_size_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_GRID_ITEM_ICON_27x27, "HILDON_GRID_ITEM_ICON_27x27", "27x27" },
      { HILDON_GRID_ITEM_ICON_128x128, "HILDON_GRID_ITEM_ICON_128x128", "128x128" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonGridItemIconSizeType", values);
  }
  return etype;
}

/* enumerations from "/usr/include/hildon-widgets/hildon-input-mode-hint.h" */
GType
hildon_input_mode_hint_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_INPUT_MODE_HINT_ALPHANUMERICSPECIAL, "HILDON_INPUT_MODE_HINT_ALPHANUMERICSPECIAL", "alphanumericspecial" },
      { HILDON_INPUT_MODE_HINT_NUMERIC, "HILDON_INPUT_MODE_HINT_NUMERIC", "numeric" },
      { HILDON_INPUT_MODE_HINT_ALPHA, "HILDON_INPUT_MODE_HINT_ALPHA", "alpha" },
      { HILDON_INPUT_MODE_HINT_NUMERICSPECIAL, "HILDON_INPUT_MODE_HINT_NUMERICSPECIAL", "numericspecial" },
      { HILDON_INPUT_MODE_HINT_ALPHASPECIAL, "HILDON_INPUT_MODE_HINT_ALPHASPECIAL", "alphaspecial" },
      { HILDON_INPUT_MODE_HINT_ALPHANUMERIC, "HILDON_INPUT_MODE_HINT_ALPHANUMERIC", "alphanumeric" },
      { HILDON_INPUT_MODE_HINT_HEXA, "HILDON_INPUT_MODE_HINT_HEXA", "hexa" },
      { HILDON_INPUT_MODE_HINT_HEXASPECIAL, "HILDON_INPUT_MODE_HINT_HEXASPECIAL", "hexaspecial" },
      { HILDON_INPUT_MODE_HINT_TELE, "HILDON_INPUT_MODE_HINT_TELE", "tele" },
      { HILDON_INPUT_MODE_HINT_TELESPECIAL, "HILDON_INPUT_MODE_HINT_TELESPECIAL", "telespecial" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonInputModeHint", values);
  }
  return etype;
}

/* enumerations from "/usr/include/hildon-widgets/hildon-number-editor.h" */
GType
hildon_number_editor_error_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MAXIMUM_VALUE_EXCEED, "MAXIMUM_VALUE_EXCEED", "maximum-value-exceed" },
      { MINIMUM_VALUE_EXCEED, "MINIMUM_VALUE_EXCEED", "minimum-value-exceed" },
      { ERRONEOUS_VALUE, "ERRONEOUS_VALUE", "erroneous-value" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonNumberEditorErrorType", values);
  }
  return etype;
}

/* enumerations from "/usr/include/hildon-widgets/hildon-telephone-editor.h" */
GType
hildon_telephone_editor_format_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_TELEPHONE_EDITOR_FORMAT_FREE, "HILDON_TELEPHONE_EDITOR_FORMAT_FREE", "free" },
      { HILDON_TELEPHONE_EDITOR_FORMAT_COERCE, "HILDON_TELEPHONE_EDITOR_FORMAT_COERCE", "coerce" },
      { HILDON_TELEPHONE_EDITOR_FORMAT_COERCE_COUNTRY, "HILDON_TELEPHONE_EDITOR_FORMAT_COERCE_COUNTRY", "coerce-country" },
      { HILDON_TELEPHONE_EDITOR_FORMAT_COERCE_AREA, "HILDON_TELEPHONE_EDITOR_FORMAT_COERCE_AREA", "coerce-area" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonTelephoneEditorFormat", values);
  }
  return etype;
}

/* enumerations from "/usr/include/hildon-widgets/hildon-time-editor.h" */
GType
hildon_time_editor_error_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { NO_TIME_ERROR, "NO_TIME_ERROR", "no-time-error" },
      { MAX_HOURS, "MAX_HOURS", "max-hours" },
      { MAX_MINS, "MAX_MINS", "max-mins" },
      { MAX_SECS, "MAX_SECS", "max-secs" },
      { MIN_HOURS, "MIN_HOURS", "min-hours" },
      { MIN_MINS, "MIN_MINS", "min-mins" },
      { MIN_SECS, "MIN_SECS", "min-secs" },
      { EMPTY_HOURS, "EMPTY_HOURS", "empty-hours" },
      { EMPTY_MINS, "EMPTY_MINS", "empty-mins" },
      { EMPTY_SECS, "EMPTY_SECS", "empty-secs" },
      { MIN_DUR, "MIN_DUR", "min-dur" },
      { MAX_DUR, "MAX_DUR", "max-dur" },
      { INVALID_TIME, "INVALID_TIME", "invalid-time" },
      { INVALID_CHAR, "INVALID_CHAR", "invalid-char" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonTimeEditorErrorType", values);
  }
  return etype;
}

/* Generated data ends here */


/* Generated data (by glib-mkenums) */


/* enumerations from "/usr/include/hildon-fm/hildon-widgets/hildon-file-selection.h" */
GType
hildon_file_selection_mode_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_FILE_SELECTION_MODE_LIST, "HILDON_FILE_SELECTION_MODE_LIST", "list" },
      { HILDON_FILE_SELECTION_MODE_THUMBNAILS, "HILDON_FILE_SELECTION_MODE_THUMBNAILS", "thumbnails" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonFileSelectionMode", values);
  }
  return etype;
}
GType
hildon_file_selection_sort_key_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_FILE_SELECTION_SORT_NAME, "HILDON_FILE_SELECTION_SORT_NAME", "name" },
      { HILDON_FILE_SELECTION_SORT_TYPE, "HILDON_FILE_SELECTION_SORT_TYPE", "type" },
      { HILDON_FILE_SELECTION_SORT_MODIFIED, "HILDON_FILE_SELECTION_SORT_MODIFIED", "modified" },
      { HILDON_FILE_SELECTION_SORT_SIZE, "HILDON_FILE_SELECTION_SORT_SIZE", "size" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonFileSelectionSortKey", values);
  }
  return etype;
}
GType
hildon_file_selection_pane_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_FILE_SELECTION_PANE_NAVIGATION, "HILDON_FILE_SELECTION_PANE_NAVIGATION", "navigation" },
      { HILDON_FILE_SELECTION_PANE_CONTENT, "HILDON_FILE_SELECTION_PANE_CONTENT", "content" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonFileSelectionPane", values);
  }
  return etype;
}
GType
hildon_file_selection_visible_columns_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_FILE_SELECTION_SHOW_NAME, "HILDON_FILE_SELECTION_SHOW_NAME", "name" },
      { HILDON_FILE_SELECTION_SHOW_MODIFIED, "HILDON_FILE_SELECTION_SHOW_MODIFIED", "modified" },
      { HILDON_FILE_SELECTION_SHOW_SIZE, "HILDON_FILE_SELECTION_SHOW_SIZE", "size" },
      { HILDON_FILE_SELECTION_SHOW_ALL, "HILDON_FILE_SELECTION_SHOW_ALL", "all" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonFileSelectionVisibleColumns", values);
  }
  return etype;
}

/* enumerations from "/usr/include/hildon-fm/hildon-widgets/hildon-file-system-common.h" */
GType
hildon_file_system_model_item_type_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_FILE_SYSTEM_MODEL_UNKNOWN, "HILDON_FILE_SYSTEM_MODEL_UNKNOWN", "unknown" },
      { HILDON_FILE_SYSTEM_MODEL_FILE, "HILDON_FILE_SYSTEM_MODEL_FILE", "file" },
      { HILDON_FILE_SYSTEM_MODEL_FOLDER, "HILDON_FILE_SYSTEM_MODEL_FOLDER", "folder" },
      { HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_IMAGES, "HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_IMAGES", "safe-folder-images" },
      { HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_VIDEOS, "HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_VIDEOS", "safe-folder-videos" },
      { HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_SOUNDS, "HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_SOUNDS", "safe-folder-sounds" },
      { HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_DOCUMENTS, "HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_DOCUMENTS", "safe-folder-documents" },
      { HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_GAMES, "HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_GAMES", "safe-folder-games" },
      { HILDON_FILE_SYSTEM_MODEL_MMC, "HILDON_FILE_SYSTEM_MODEL_MMC", "mmc" },
      { HILDON_FILE_SYSTEM_MODEL_GATEWAY, "HILDON_FILE_SYSTEM_MODEL_GATEWAY", "gateway" },
      { HILDON_FILE_SYSTEM_MODEL_LOCAL_DEVICE, "HILDON_FILE_SYSTEM_MODEL_LOCAL_DEVICE", "local-device" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonFileSystemModelItemType", values);
  }
  return etype;
}

/* enumerations from "/usr/include/hildon-fm/hildon-widgets/hildon-file-system-model.h" */
GType
hildon_file_system_model_columns_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_GTK_PATH, "HILDON_FILE_SYSTEM_MODEL_COLUMN_GTK_PATH", "column-gtk-path" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_LOCAL_PATH, "HILDON_FILE_SYSTEM_MODEL_COLUMN_LOCAL_PATH", "column-local-path" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_URI, "HILDON_FILE_SYSTEM_MODEL_COLUMN_URI", "column-uri" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_FILE_NAME, "HILDON_FILE_SYSTEM_MODEL_COLUMN_FILE_NAME", "column-file-name" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_DISPLAY_NAME, "HILDON_FILE_SYSTEM_MODEL_COLUMN_DISPLAY_NAME", "column-display-name" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_SORT_KEY, "HILDON_FILE_SYSTEM_MODEL_COLUMN_SORT_KEY", "column-sort-key" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_MIME_TYPE, "HILDON_FILE_SYSTEM_MODEL_COLUMN_MIME_TYPE", "column-mime-type" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_FILE_SIZE, "HILDON_FILE_SYSTEM_MODEL_COLUMN_FILE_SIZE", "column-file-size" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_FILE_TIME, "HILDON_FILE_SYSTEM_MODEL_COLUMN_FILE_TIME", "column-file-time" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_FOLDER, "HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_FOLDER", "column-is-folder" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_AVAILABLE, "HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_AVAILABLE", "column-is-available" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_HAS_LOCAL_PATH, "HILDON_FILE_SYSTEM_MODEL_COLUMN_HAS_LOCAL_PATH", "column-has-local-path" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_TYPE, "HILDON_FILE_SYSTEM_MODEL_COLUMN_TYPE", "column-type" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_ICON, "HILDON_FILE_SYSTEM_MODEL_COLUMN_ICON", "column-icon" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_ICON_EXPANDED, "HILDON_FILE_SYSTEM_MODEL_COLUMN_ICON_EXPANDED", "column-icon-expanded" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_ICON_COLLAPSED, "HILDON_FILE_SYSTEM_MODEL_COLUMN_ICON_COLLAPSED", "column-icon-collapsed" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_THUMBNAIL, "HILDON_FILE_SYSTEM_MODEL_COLUMN_THUMBNAIL", "column-thumbnail" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_LOAD_READY, "HILDON_FILE_SYSTEM_MODEL_COLUMN_LOAD_READY", "column-load-ready" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_FREE_SPACE, "HILDON_FILE_SYSTEM_MODEL_COLUMN_FREE_SPACE", "column-free-space" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_TITLE, "HILDON_FILE_SYSTEM_MODEL_COLUMN_TITLE", "column-title" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_AUTHOR, "HILDON_FILE_SYSTEM_MODEL_COLUMN_AUTHOR", "column-author" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_HIDDEN, "HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_HIDDEN", "column-is-hidden" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_UNAVAILABLE_REASON, "HILDON_FILE_SYSTEM_MODEL_COLUMN_UNAVAILABLE_REASON", "column-unavailable-reason" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_FAILED_ACCESS_MESSAGE, "HILDON_FILE_SYSTEM_MODEL_COLUMN_FAILED_ACCESS_MESSAGE", "column-failed-access-message" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_SORT_WEIGHT, "HILDON_FILE_SYSTEM_MODEL_COLUMN_SORT_WEIGHT", "column-sort-weight" },
      { HILDON_FILE_SYSTEM_MODEL_COLUMN_EXTRA_INFO, "HILDON_FILE_SYSTEM_MODEL_COLUMN_EXTRA_INFO", "column-extra-info" },
      { HILDON_FILE_SYSTEM_MODEL_NUM_COLUMNS, "HILDON_FILE_SYSTEM_MODEL_NUM_COLUMNS", "num-columns" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("HildonFileSystemModelColumns", values);
  }
  return etype;
}

/* Generated data ends here */


/* Generated data (by glib-mkenums) */


/* enumerations from "/usr/include/glib-2.0/glib/gdate.h" */
GType
g_date_dmy_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { G_DATE_DAY, "G_DATE_DAY", "day" },
      { G_DATE_MONTH, "G_DATE_MONTH", "month" },
      { G_DATE_YEAR, "G_DATE_YEAR", "year" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("GDateDMY", values);
  }
  return etype;
}
GType
g_date_weekday_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { G_DATE_BAD_WEEKDAY, "G_DATE_BAD_WEEKDAY", "bad-weekday" },
      { G_DATE_MONDAY, "G_DATE_MONDAY", "monday" },
      { G_DATE_TUESDAY, "G_DATE_TUESDAY", "tuesday" },
      { G_DATE_WEDNESDAY, "G_DATE_WEDNESDAY", "wednesday" },
      { G_DATE_THURSDAY, "G_DATE_THURSDAY", "thursday" },
      { G_DATE_FRIDAY, "G_DATE_FRIDAY", "friday" },
      { G_DATE_SATURDAY, "G_DATE_SATURDAY", "saturday" },
      { G_DATE_SUNDAY, "G_DATE_SUNDAY", "sunday" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("GDateWeekday", values);
  }
  return etype;
}
GType
g_date_month_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { G_DATE_BAD_MONTH, "G_DATE_BAD_MONTH", "bad-month" },
      { G_DATE_JANUARY, "G_DATE_JANUARY", "january" },
      { G_DATE_FEBRUARY, "G_DATE_FEBRUARY", "february" },
      { G_DATE_MARCH, "G_DATE_MARCH", "march" },
      { G_DATE_APRIL, "G_DATE_APRIL", "april" },
      { G_DATE_MAY, "G_DATE_MAY", "may" },
      { G_DATE_JUNE, "G_DATE_JUNE", "june" },
      { G_DATE_JULY, "G_DATE_JULY", "july" },
      { G_DATE_AUGUST, "G_DATE_AUGUST", "august" },
      { G_DATE_SEPTEMBER, "G_DATE_SEPTEMBER", "september" },
      { G_DATE_OCTOBER, "G_DATE_OCTOBER", "october" },
      { G_DATE_NOVEMBER, "G_DATE_NOVEMBER", "november" },
      { G_DATE_DECEMBER, "G_DATE_DECEMBER", "december" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("GDateMonth", values);
  }
  return etype;
}

/* Generated data ends here */


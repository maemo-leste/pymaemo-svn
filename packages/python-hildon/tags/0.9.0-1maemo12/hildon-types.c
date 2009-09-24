
/* Generated data (by glib-mkenums) */

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

/* enumerations from "/usr/include/hildon-fm-2/hildon/hildon-file-system-model.h" */

GType
hildon_file_system_model_columns_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_FILE_SYSTEM_MODEL_COLUMN_GTK_PATH_INTERNAL, "HILDON_FILE_SYSTEM_MODEL_COLUMN_GTK_PATH_INTERNAL", "column-gtk-path-internal" },
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
            { HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_READONLY, "HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_READONLY", "column-is-readonly" },
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
            { HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_DRIVE, "HILDON_FILE_SYSTEM_MODEL_COLUMN_IS_DRIVE", "column-is-drive" },
            { HILDON_FILE_SYSTEM_MODEL_NUM_COLUMNS, "HILDON_FILE_SYSTEM_MODEL_NUM_COLUMNS", "num-columns" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonFileSystemModelColumns", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-fm-2/hildon/hildon-file-system-common.h" */

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
            { HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_CAMERA, "HILDON_FILE_SYSTEM_MODEL_SAFE_FOLDER_CAMERA", "safe-folder-camera" },
            { HILDON_FILE_SYSTEM_MODEL_MMC, "HILDON_FILE_SYSTEM_MODEL_MMC", "mmc" },
            { HILDON_FILE_SYSTEM_MODEL_GATEWAY, "HILDON_FILE_SYSTEM_MODEL_GATEWAY", "gateway" },
            { HILDON_FILE_SYSTEM_MODEL_LOCAL_DEVICE, "HILDON_FILE_SYSTEM_MODEL_LOCAL_DEVICE", "local-device" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonFileSystemModelItemType", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-fm-2/hildon/hildon-file-system-voldev.h" */

GType
voldev_t_voldev_t_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { EXT_CARD, "EXT_CARD", "ext-card" },
            { INT_CARD, "INT_CARD", "int-card" },
            { USB_STORAGE, "USB_STORAGE", "usb-storage" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("voldev_t", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-fm-2/hildon/hildon-file-selection.h" */

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


/* enumerations from "/usr/include/hildon-1/hildon/hildon-wizard-dialog.h" */

GType
hildon_wizard_dialog_response_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_WIZARD_DIALOG_CANCEL, "HILDON_WIZARD_DIALOG_CANCEL", "cancel" },
            { HILDON_WIZARD_DIALOG_PREVIOUS, "HILDON_WIZARD_DIALOG_PREVIOUS", "previous" },
            { HILDON_WIZARD_DIALOG_NEXT, "HILDON_WIZARD_DIALOG_NEXT", "next" },
            { HILDON_WIZARD_DIALOG_FINISH, "HILDON_WIZARD_DIALOG_FINISH", "finish" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonWizardDialogResponse", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-caption.h" */

GType
hildon_caption_status_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_CAPTION_OPTIONAL, "HILDON_CAPTION_OPTIONAL", "optional" },
            { HILDON_CAPTION_MANDATORY, "HILDON_CAPTION_MANDATORY", "mandatory" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonCaptionStatus", values);
    }
    return etype;
}

GType
hildon_caption_icon_position_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_CAPTION_POSITION_LEFT, "HILDON_CAPTION_POSITION_LEFT", "left" },
            { HILDON_CAPTION_POSITION_RIGHT, "HILDON_CAPTION_POSITION_RIGHT", "right" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonCaptionIconPosition", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-pannable-area.h" */

GType
hildon_pannable_area_mode_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_PANNABLE_AREA_MODE_PUSH, "HILDON_PANNABLE_AREA_MODE_PUSH", "push" },
            { HILDON_PANNABLE_AREA_MODE_ACCEL, "HILDON_PANNABLE_AREA_MODE_ACCEL", "accel" },
            { HILDON_PANNABLE_AREA_MODE_AUTO, "HILDON_PANNABLE_AREA_MODE_AUTO", "auto" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonPannableAreaMode", values);
    }
    return etype;
}

GType
hildon_movement_mode_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GFlagsValue values[] = {
            { HILDON_MOVEMENT_MODE_HORIZ, "HILDON_MOVEMENT_MODE_HORIZ", "horiz" },
            { HILDON_MOVEMENT_MODE_VERT, "HILDON_MOVEMENT_MODE_VERT", "vert" },
            { HILDON_MOVEMENT_MODE_BOTH, "HILDON_MOVEMENT_MODE_BOTH", "both" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static ("HildonMovementMode", values);
    }
    return etype;
}

GType
hildon_movement_direction_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_MOVEMENT_UP, "HILDON_MOVEMENT_UP", "up" },
            { HILDON_MOVEMENT_DOWN, "HILDON_MOVEMENT_DOWN", "down" },
            { HILDON_MOVEMENT_LEFT, "HILDON_MOVEMENT_LEFT", "left" },
            { HILDON_MOVEMENT_RIGHT, "HILDON_MOVEMENT_RIGHT", "right" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonMovementDirection", values);
    }
    return etype;
}

GType
hildon_size_request_policy_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_SIZE_REQUEST_MINIMUM, "HILDON_SIZE_REQUEST_MINIMUM", "minimum" },
            { HILDON_SIZE_REQUEST_CHILDREN, "HILDON_SIZE_REQUEST_CHILDREN", "children" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonSizeRequestPolicy", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-time-editor.h" */

GType
hildon_date_time_error_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_DATE_TIME_ERROR_NO_ERROR, "HILDON_DATE_TIME_ERROR_NO_ERROR", "no-error" },
            { HILDON_DATE_TIME_ERROR_MAX_HOURS, "HILDON_DATE_TIME_ERROR_MAX_HOURS", "max-hours" },
            { HILDON_DATE_TIME_ERROR_MAX_MINS, "HILDON_DATE_TIME_ERROR_MAX_MINS", "max-mins" },
            { HILDON_DATE_TIME_ERROR_MAX_SECS, "HILDON_DATE_TIME_ERROR_MAX_SECS", "max-secs" },
            { HILDON_DATE_TIME_ERROR_MAX_DAY, "HILDON_DATE_TIME_ERROR_MAX_DAY", "max-day" },
            { HILDON_DATE_TIME_ERROR_MAX_MONTH, "HILDON_DATE_TIME_ERROR_MAX_MONTH", "max-month" },
            { HILDON_DATE_TIME_ERROR_MAX_YEAR, "HILDON_DATE_TIME_ERROR_MAX_YEAR", "max-year" },
            { HILDON_DATE_TIME_ERROR_MIN_HOURS, "HILDON_DATE_TIME_ERROR_MIN_HOURS", "min-hours" },
            { HILDON_DATE_TIME_ERROR_MIN_MINS, "HILDON_DATE_TIME_ERROR_MIN_MINS", "min-mins" },
            { HILDON_DATE_TIME_ERROR_MIN_SECS, "HILDON_DATE_TIME_ERROR_MIN_SECS", "min-secs" },
            { HILDON_DATE_TIME_ERROR_MIN_DAY, "HILDON_DATE_TIME_ERROR_MIN_DAY", "min-day" },
            { HILDON_DATE_TIME_ERROR_MIN_MONTH, "HILDON_DATE_TIME_ERROR_MIN_MONTH", "min-month" },
            { HILDON_DATE_TIME_ERROR_MIN_YEAR, "HILDON_DATE_TIME_ERROR_MIN_YEAR", "min-year" },
            { HILDON_DATE_TIME_ERROR_EMPTY_HOURS, "HILDON_DATE_TIME_ERROR_EMPTY_HOURS", "empty-hours" },
            { HILDON_DATE_TIME_ERROR_EMPTY_MINS, "HILDON_DATE_TIME_ERROR_EMPTY_MINS", "empty-mins" },
            { HILDON_DATE_TIME_ERROR_EMPTY_SECS, "HILDON_DATE_TIME_ERROR_EMPTY_SECS", "empty-secs" },
            { HILDON_DATE_TIME_ERROR_EMPTY_DAY, "HILDON_DATE_TIME_ERROR_EMPTY_DAY", "empty-day" },
            { HILDON_DATE_TIME_ERROR_EMPTY_MONTH, "HILDON_DATE_TIME_ERROR_EMPTY_MONTH", "empty-month" },
            { HILDON_DATE_TIME_ERROR_EMPTY_YEAR, "HILDON_DATE_TIME_ERROR_EMPTY_YEAR", "empty-year" },
            { HILDON_DATE_TIME_ERROR_MIN_DURATION, "HILDON_DATE_TIME_ERROR_MIN_DURATION", "min-duration" },
            { HILDON_DATE_TIME_ERROR_MAX_DURATION, "HILDON_DATE_TIME_ERROR_MAX_DURATION", "max-duration" },
            { HILDON_DATE_TIME_ERROR_INVALID_CHAR, "HILDON_DATE_TIME_ERROR_INVALID_CHAR", "invalid-char" },
            { HILDON_DATE_TIME_ERROR_INVALID_DATE, "HILDON_DATE_TIME_ERROR_INVALID_DATE", "invalid-date" },
            { HILDON_DATE_TIME_ERROR_INVALID_TIME, "HILDON_DATE_TIME_ERROR_INVALID_TIME", "invalid-time" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonDateTimeError", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-note.h" */

GType
hildon_note_type_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_NOTE_TYPE_CONFIRMATION, "HILDON_NOTE_TYPE_CONFIRMATION", "confirmation" },
            { HILDON_NOTE_TYPE_CONFIRMATION_BUTTON, "HILDON_NOTE_TYPE_CONFIRMATION_BUTTON", "confirmation-button" },
            { HILDON_NOTE_TYPE_INFORMATION, "HILDON_NOTE_TYPE_INFORMATION", "information" },
            { HILDON_NOTE_TYPE_INFORMATION_THEME, "HILDON_NOTE_TYPE_INFORMATION_THEME", "information-theme" },
            { HILDON_NOTE_TYPE_PROGRESSBAR, "HILDON_NOTE_TYPE_PROGRESSBAR", "progressbar" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonNoteType", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-window.h" */

GType
hildon_window_clipboard_operation_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_WINDOW_CO_COPY, "HILDON_WINDOW_CO_COPY", "copy" },
            { HILDON_WINDOW_CO_CUT, "HILDON_WINDOW_CO_CUT", "cut" },
            { HILDON_WINDOW_CO_PASTE, "HILDON_WINDOW_CO_PASTE", "paste" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonWindowClipboardOperation", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-calendar.h" */

GType
hildon_calendar_display_options_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GFlagsValue values[] = {
            { HILDON_CALENDAR_SHOW_HEADING, "HILDON_CALENDAR_SHOW_HEADING", "show-heading" },
            { HILDON_CALENDAR_SHOW_DAY_NAMES, "HILDON_CALENDAR_SHOW_DAY_NAMES", "show-day-names" },
            { HILDON_CALENDAR_NO_MONTH_CHANGE, "HILDON_CALENDAR_NO_MONTH_CHANGE", "no-month-change" },
            { HILDON_CALENDAR_SHOW_WEEK_NUMBERS, "HILDON_CALENDAR_SHOW_WEEK_NUMBERS", "show-week-numbers" },
            { HILDON_CALENDAR_WEEK_START_MONDAY, "HILDON_CALENDAR_WEEK_START_MONDAY", "week-start-monday" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static ("HildonCalendarDisplayOptions", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-time-selector.h" */

GType
hildon_time_selector_format_policy_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_TIME_SELECTOR_FORMAT_POLICY_AMPM, "HILDON_TIME_SELECTOR_FORMAT_POLICY_AMPM", "ampm" },
            { HILDON_TIME_SELECTOR_FORMAT_POLICY_24H, "HILDON_TIME_SELECTOR_FORMAT_POLICY_24H", "24h" },
            { HILDON_TIME_SELECTOR_FORMAT_POLICY_AUTOMATIC, "HILDON_TIME_SELECTOR_FORMAT_POLICY_AUTOMATIC", "automatic" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonTimeSelectorFormatPolicy", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-button.h" */

GType
hildon_button_arrangement_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_BUTTON_ARRANGEMENT_HORIZONTAL, "HILDON_BUTTON_ARRANGEMENT_HORIZONTAL", "horizontal" },
            { HILDON_BUTTON_ARRANGEMENT_VERTICAL, "HILDON_BUTTON_ARRANGEMENT_VERTICAL", "vertical" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonButtonArrangement", values);
    }
    return etype;
}

GType
hildon_button_style_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_BUTTON_STYLE_NORMAL, "HILDON_BUTTON_STYLE_NORMAL", "normal" },
            { HILDON_BUTTON_STYLE_PICKER, "HILDON_BUTTON_STYLE_PICKER", "picker" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonButtonStyle", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-number-editor.h" */

GType
hildon_number_editor_error_type_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_NUMBER_EDITOR_ERROR_MAXIMUM_VALUE_EXCEED, "HILDON_NUMBER_EDITOR_ERROR_MAXIMUM_VALUE_EXCEED", "maximum-value-exceed" },
            { HILDON_NUMBER_EDITOR_ERROR_MINIMUM_VALUE_EXCEED, "HILDON_NUMBER_EDITOR_ERROR_MINIMUM_VALUE_EXCEED", "minimum-value-exceed" },
            { HILDON_NUMBER_EDITOR_ERROR_ERRONEOUS_VALUE, "HILDON_NUMBER_EDITOR_ERROR_ERRONEOUS_VALUE", "erroneous-value" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonNumberEditorErrorType", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-touch-selector.h" */

GType
hildon_touch_selector_selection_mode_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { HILDON_TOUCH_SELECTOR_SELECTION_MODE_SINGLE, "HILDON_TOUCH_SELECTOR_SELECTION_MODE_SINGLE", "single" },
            { HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE, "HILDON_TOUCH_SELECTOR_SELECTION_MODE_MULTIPLE", "multiple" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("HildonTouchSelectorSelectionMode", values);
    }
    return etype;
}


/* enumerations from "/usr/include/hildon-1/hildon/hildon-gtk.h" */

GType
hildon_portrait_flags_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GFlagsValue values[] = {
            { HILDON_PORTRAIT_MODE_REQUEST, "HILDON_PORTRAIT_MODE_REQUEST", "request" },
            { HILDON_PORTRAIT_MODE_SUPPORT, "HILDON_PORTRAIT_MODE_SUPPORT", "support" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static ("HildonPortraitFlags", values);
    }
    return etype;
}


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


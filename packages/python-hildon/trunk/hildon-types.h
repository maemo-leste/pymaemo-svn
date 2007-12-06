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


#ifndef HILDON_TYPES_H
#define HILDON_TYPES_H

#include <glib.h>
#include <glib/gtypes.h>
#include <gtk/gtkuimanager.h>
#include <gtk/gtkfilefilter.h>
#include <hildon-base-lib/hildon-base-dnotify.h>
#include <hildon-base-lib/hildon-base-types.h>
#include <hildon-widgets/gtk-infoprint.h>
#include <hildon-widgets/hildon-add-home-dialog.h>
#include <hildon-widgets/hildon-app-private.h>
#include <hildon-widgets/hildon-app.h>
#include <hildon-widgets/hildon-appview.h>
#include <hildon-widgets/hildon-banner.h>
#include <hildon-widgets/hildon-calendar-popup.h>
#include <hildon-widgets/hildon-caption.h>
#include <hildon-widgets/hildon-code-dialog.h>
#include <hildon-widgets/hildon-color-button.h>
#if 0
#include <hildon-widgets/hildon-color-chooser-button.h>
#include <hildon-widgets/hildon-color-chooser-dialog.h>
#include <hildon-widgets/hildon-color-chooser.h>
#include <hildon-widgets/hildon-plugin-widget.h>
#endif
#include <hildon-widgets/hildon-color-selector.h>
#include <hildon-widgets/hildon-color-popup.h>
#include <hildon-widgets/hildon-controlbar.h>
#include <hildon-widgets/hildon-date-editor.h>
#include <hildon-widgets/hildon-defines.h>
#include <hildon-widgets/hildon-dialoghelp.h>
#include <hildon-widgets/hildon-file-handling-note.h>
#include <hildon-widgets/hildon-find-toolbar.h>
#include <hildon-widgets/hildon-font-selection-dialog.h>
#include <hildon-widgets/hildon-get-password-dialog.h>
#include <hildon-widgets/hildon-grid.h>
#include <hildon-widgets/hildon-grid-item.h>
#include <hildon-widgets/hildon-hvolumebar.h>
#include <hildon-widgets/hildon-input-mode-hint.h>
#include <hildon-widgets/hildon-name-password-dialog.h>
#include <hildon-widgets/hildon-note.h>
#include <hildon-widgets/hildon-number-editor.h>
#include <hildon-widgets/hildon-program.h>
#include <hildon-widgets/hildon-range-editor.h>
#include <hildon-widgets/hildon-scroll-area.h>
#include <hildon-widgets/hildon-seekbar.h>
#include <hildon-widgets/hildon-set-password-dialog.h>
#include <hildon-widgets/hildon-sort-dialog.h>
#include <hildon-widgets/hildon-system-sound.h>
#include <hildon-widgets/hildon-telephone-editor.h>
#include <hildon-widgets/hildon-time-editor.h>
#include <hildon-widgets/hildon-time-picker.h>
#include <hildon-widgets/hildon-volumebar.h>
#include <hildon-widgets/hildon-vvolumebar.h>
#include <hildon-widgets/hildon-weekday-picker.h>
#include <hildon-widgets/hildon-window.h>
#include <hildon-widgets/hildon-window-private.h>
#include <hildon-widgets/hildon-wizard-dialog.h>

#include <hildon-fm/hildon-widgets/hildon-file-chooser-dialog.h>
#include <hildon-fm/hildon-widgets/hildon-file-details-dialog.h>
#include <hildon-fm/hildon-widgets/hildon-file-selection.h>
#include <hildon-fm/hildon-widgets/hildon-file-system-common.h>
#include <hildon-fm/hildon-widgets/hildon-file-system-info.h>
#include <hildon-fm/hildon-widgets/hildon-file-system-model.h>

#ifndef HILDON_DISABLE_DEPRECATED
#include <hildon-widgets/hildon-search.h>
#include <hildon-widgets/hildon-find-object-dialog.h>
#include <hildon-widgets/hildon-find-replace-dialog.h>
#endif

GType hildon_note_type_get_type (void);
#define HILDON_TYPE_NOTE_TYPE (hildon_note_type_get_type())


/* Generated data (by glib-mkenums) */

/* enumerations from "/usr/include/hildon-widgets/hildon-date-editor.h" */
GType hildon_date_editor_error_type_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_DATE_EDITOR_ERROR_TYPE (hildon_date_editor_error_type_get_type())
/* enumerations from "/usr/include/hildon-widgets/hildon-grid-item.h" */
GType hildon_grid_position_type_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_GRID_POSITION_TYPE (hildon_grid_position_type_get_type())
GType hildon_grid_item_icon_size_type_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_GRID_ITEM_ICON_SIZE_TYPE (hildon_grid_item_icon_size_type_get_type())
/* enumerations from "/usr/include/hildon-widgets/hildon-input-mode-hint.h" */
GType hildon_input_mode_hint_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_INPUT_MODE_HINT (hildon_input_mode_hint_get_type())
/* enumerations from "/usr/include/hildon-widgets/hildon-number-editor.h" */
GType hildon_number_editor_error_type_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_NUMBER_EDITOR_ERROR_TYPE (hildon_number_editor_error_type_get_type())
/* enumerations from "/usr/include/hildon-widgets/hildon-telephone-editor.h" */
GType hildon_telephone_editor_format_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_TELEPHONE_EDITOR_FORMAT (hildon_telephone_editor_format_get_type())
/* enumerations from "/usr/include/hildon-widgets/hildon-time-editor.h" */
GType hildon_time_editor_error_type_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_TIME_EDITOR_ERROR_TYPE (hildon_time_editor_error_type_get_type())

/* Generated data ends here */


/* Generated data (by glib-mkenums) */

/* enumerations from "/usr/include/hildon-fm/hildon-widgets/hildon-file-selection.h" */
GType hildon_file_selection_mode_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_FILE_SELECTION_MODE (hildon_file_selection_mode_get_type())
GType hildon_file_selection_sort_key_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_FILE_SELECTION_SORT_KEY (hildon_file_selection_sort_key_get_type())
GType hildon_file_selection_pane_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_FILE_SELECTION_PANE (hildon_file_selection_pane_get_type())
GType hildon_file_selection_visible_columns_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_FILE_SELECTION_VISIBLE_COLUMNS (hildon_file_selection_visible_columns_get_type())
/* enumerations from "/usr/include/hildon-fm/hildon-widgets/hildon-file-system-common.h" */
GType hildon_file_system_model_item_type_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_FILE_SYSTEM_MODEL_ITEM_TYPE (hildon_file_system_model_item_type_get_type())
/* enumerations from "/usr/include/hildon-fm/hildon-widgets/hildon-file-system-model.h" */
GType hildon_file_system_model_columns_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_FILE_SYSTEM_MODEL_COLUMNS (hildon_file_system_model_columns_get_type())

/* Generated data ends here */

/* Generated data (by glib-mkenums) */

/* enumerations from "/usr/include/glib-2.0/glib/gdate.h" */
GType g_date_dmy_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_DATE_DMY (g_date_dmy_get_type())
GType g_date_weekday_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_DATE_WEEKDAY (g_date_weekday_get_type())
GType g_date_month_get_type (void) G_GNUC_CONST;
#define HILDON_TYPE_DATE_MONTH (g_date_month_get_type())

/* Generated data ends here */
#endif /* !HILDON_TYPES_H */


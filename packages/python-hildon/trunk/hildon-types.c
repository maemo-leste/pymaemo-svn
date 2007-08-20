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

#include "hildon-types.c.in"

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

/* -*- Mode: C; c-basic-offset: 4 -*-
 * python-conic - Python bindings for the ConIc library.
 *
 * conic-types: includes the generated enumerations and extra
 *              definitions.
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


#ifndef ABOOK_TYPES_H
#define ABOOK_TYPES_H

#include <glib.h>
#include <glib/gtypes.h>

/* TODO Fill in osso-abook headers */


#include <libosso-abook/osso-abook.h>
#include <libosso-abook/osso-abook-account-model.h>
#include <libosso-abook/osso-abook-account.h>
#include <libosso-abook/osso-abook-chat-button.h>
#include <libosso-abook/osso-abook-account-group.h>
#include <libosso-abook/osso-abook-voip-call-button.h>
#include <python-osso/osso.h>

/* FIXME Nasty hack - Remaining macros from TreeModel */

#include <libosso.h>

#include "abook-types.h.in"


#endif /* !ABOOK_TYPES_H */

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


#ifndef MC_TYPES_H
#define MC_TYPES_H

#include <glib.h>
#include <glib/gtypes.h>

#include <libmissioncontrol/mission-control.h>
#include <libmissioncontrol/mc-account.h>
#include <libmissioncontrol/mc-account-monitor.h>
#include <libmissioncontrol/mc-manager.h>
#include <libmissioncontrol/mc-profile.h>
#include <libmissioncontrol/mc.h>

#define DBUS_API_SUBJECT_TO_CHANGE

#include <dbus/dbus.h>
#include <libtelepathy/tp-conn.h>
#include <libtelepathy/tp-constants.h>

//#include <libmissioncontrol/mc.h>

/* Hacks to get the MissionControl object working */
#define MC_MISSION_CONTROL(obj) MISSIONCONTROL(obj)
#define MC_TYPE_MISSION_CONTROL MISSIONCONTROL_TYPE


//#include "mc-types.h.in"



/* Generated data (by glib-mkenums) */

/* enumerations from "/usr/include/libmissioncontrol/mc-account.h" */
GType mc_account_setting_state_get_type (void) G_GNUC_CONST;
#define MC_TYPE_ACCOUNT_SETTING_STATE (mc_account_setting_state_get_type())
/* enumerations from "/usr/include/libmissioncontrol/mc-profile.h" */
GType mc_profile_capability_flags_get_type (void) G_GNUC_CONST;
#define MC_TYPE_PROFILE_CAPABILITY_FLAGS (mc_profile_capability_flags_get_type())
/* enumerations from "/usr/include/libmissioncontrol/mission-control.h" */
GType mc_error_get_type (void) G_GNUC_CONST;
#define MC_TYPE_ERROR (mc_error_get_type())
GType osso_rtcom_presence_get_type (void) G_GNUC_CONST;
#define MC_TYPE_RTCOM_PRESENCE (osso_rtcom_presence_get_type())
GType mc_presence_get_type (void) G_GNUC_CONST;
#define MC_TYPE_PRESENCE (mc_presence_get_type())
GType mc_status_get_type (void) G_GNUC_CONST;
#define MC_TYPE_STATUS (mc_status_get_type())

/* Generated data ends here */

#endif /* !MC_TYPES_H */

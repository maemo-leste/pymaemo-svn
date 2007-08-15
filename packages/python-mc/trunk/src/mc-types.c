/* -*- Mode: C; c-basic-offset: 4 -*-
 * python-conic - Python bindings for the ConIc library.
 *
 * conic-types: extra definitions.
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

#include "mc-types.h"

//#include "mc-types.c.in"

/* Generated data (by glib-mkenums) */


/* enumerations from "/usr/include/libmissioncontrol/mc-account.h" */
GType
mc_account_setting_state_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MC_ACCOUNT_SETTING_ABSENT, "MC_ACCOUNT_SETTING_ABSENT", "absent" },
      { MC_ACCOUNT_SETTING_FROM_ACCOUNT, "MC_ACCOUNT_SETTING_FROM_ACCOUNT", "from-account" },
      { MC_ACCOUNT_SETTING_FROM_PROFILE, "MC_ACCOUNT_SETTING_FROM_PROFILE", "from-profile" },
      { MC_ACCOUNT_SETTING_FROM_PROXY, "MC_ACCOUNT_SETTING_FROM_PROXY", "from-proxy" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("McAccountSettingState", values);
  }
  return etype;
}

/* enumerations from "/usr/include/libmissioncontrol/mc-profile.h" */
GType
mc_profile_capability_flags_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { MC_PROFILE_CAPABILITY_NONE, "MC_PROFILE_CAPABILITY_NONE", "none" },
      { MC_PROFILE_CAPABILITY_CHAT_P2P, "MC_PROFILE_CAPABILITY_CHAT_P2P", "chat-p2p" },
      { MC_PROFILE_CAPABILITY_CHAT_ROOM, "MC_PROFILE_CAPABILITY_CHAT_ROOM", "chat-room" },
      { MC_PROFILE_CAPABILITY_CHAT_ROOM_LIST, "MC_PROFILE_CAPABILITY_CHAT_ROOM_LIST", "chat-room-list" },
      { MC_PROFILE_CAPABILITY_VOICE_P2P, "MC_PROFILE_CAPABILITY_VOICE_P2P", "voice-p2p" },
      { MC_PROFILE_CAPABILITY_CONTACT_SEARCH, "MC_PROFILE_CAPABILITY_CONTACT_SEARCH", "contact-search" },
      { MC_PROFILE_CAPABILITY_SPLIT_ACCOUNT, "MC_PROFILE_CAPABILITY_SPLIT_ACCOUNT", "split-account" },
      { MC_PROFILE_CAPABILITY_REGISTRATION_UI, "MC_PROFILE_CAPABILITY_REGISTRATION_UI", "registration-ui" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("McProfileCapabilityFlags", values);
  }
  return etype;
}

/* enumerations from "/usr/include/libmissioncontrol/mission-control.h" */
GType
mc_error_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MC_DISCONNECTED_ERROR, "MC_DISCONNECTED_ERROR", "disconnected-error" },
      { MC_INVALID_HANDLE_ERROR, "MC_INVALID_HANDLE_ERROR", "invalid-handle-error" },
      { MC_NO_MATCHING_CONNECTION_ERROR, "MC_NO_MATCHING_CONNECTION_ERROR", "no-matching-connection-error" },
      { MC_INVALID_ACCOUNT_ERROR, "MC_INVALID_ACCOUNT_ERROR", "invalid-account-error" },
      { MC_PRESENCE_FAILURE_ERROR, "MC_PRESENCE_FAILURE_ERROR", "presence-failure-error" },
      { MC_NO_ACCOUNTS_ERROR, "MC_NO_ACCOUNTS_ERROR", "no-accounts-error" },
      { MC_NETWORK_ERROR, "MC_NETWORK_ERROR", "network-error" },
      { MC_CONTACT_DOES_NOT_SUPPORT_VOICE_ERROR, "MC_CONTACT_DOES_NOT_SUPPORT_VOICE_ERROR", "contact-does-not-support-voice-error" },
      { MC_LOWMEM_ERROR, "MC_LOWMEM_ERROR", "lowmem-error" },
      { MC_CHANNEL_REQUEST_GENERIC_ERROR, "MC_CHANNEL_REQUEST_GENERIC_ERROR", "channel-request-generic-error" },
      { MC_CHANNEL_BANNED_ERROR, "MC_CHANNEL_BANNED_ERROR", "channel-banned-error" },
      { MC_CHANNEL_FULL_ERROR, "MC_CHANNEL_FULL_ERROR", "channel-full-error" },
      { MC_CHANNEL_INVITE_ONLY_ERROR, "MC_CHANNEL_INVITE_ONLY_ERROR", "channel-invite-only-error" },
      { MC_LAST_ERROR, "MC_LAST_ERROR", "last-error" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("MCError", values);
  }
  return etype;
}
GType
osso_rtcom_presence_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { OSSO_RTCOM_PRESENCE_UNSET, "OSSO_RTCOM_PRESENCE_UNSET", "osso-rtcom-presence-unset" },
      { OSSO_RTCOM_PRESENCE_OFFLINE, "OSSO_RTCOM_PRESENCE_OFFLINE", "osso-rtcom-presence-offline" },
      { OSSO_RTCOM_PRESENCE_AVAILABLE, "OSSO_RTCOM_PRESENCE_AVAILABLE", "osso-rtcom-presence-available" },
      { OSSO_RTCOM_PRESENCE_AWAY, "OSSO_RTCOM_PRESENCE_AWAY", "osso-rtcom-presence-away" },
      { OSSO_RTCOM_PRESENCE_EXTENDED_AWAY, "OSSO_RTCOM_PRESENCE_EXTENDED_AWAY", "osso-rtcom-presence-extended-away" },
      { OSSO_RTCOM_PRESENCE_HIDDEN, "OSSO_RTCOM_PRESENCE_HIDDEN", "osso-rtcom-presence-hidden" },
      { OSSO_RTCOM_PRESENCE_DO_NOT_DISTURB, "OSSO_RTCOM_PRESENCE_DO_NOT_DISTURB", "osso-rtcom-presence-do-not-disturb" },
      { LAST_OSSO_RTCOM_PRESENCE, "LAST_OSSO_RTCOM_PRESENCE", "last-osso-rtcom-presence" },
      { MC_PRESENCE_UNSET, "MC_PRESENCE_UNSET", "mc-presence-unset" },
      { MC_PRESENCE_OFFLINE, "MC_PRESENCE_OFFLINE", "mc-presence-offline" },
      { MC_PRESENCE_AVAILABLE, "MC_PRESENCE_AVAILABLE", "mc-presence-available" },
      { MC_PRESENCE_AWAY, "MC_PRESENCE_AWAY", "mc-presence-away" },
      { MC_PRESENCE_EXTENDED_AWAY, "MC_PRESENCE_EXTENDED_AWAY", "mc-presence-extended-away" },
      { MC_PRESENCE_HIDDEN, "MC_PRESENCE_HIDDEN", "mc-presence-hidden" },
      { MC_PRESENCE_DO_NOT_DISTURB, "MC_PRESENCE_DO_NOT_DISTURB", "mc-presence-do-not-disturb" },
      { LAST_MC_PRESENCE, "LAST_MC_PRESENCE", "last-mc-presence" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("OssoRtcomPresence", values);
  }
  return etype;
}
GType
mc_presence_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MC_PRESENCE_UNSET, "MC_PRESENCE_UNSET", "mc-presence-unset" },
      { MC_PRESENCE_OFFLINE, "MC_PRESENCE_OFFLINE", "mc-presence-offline" },
      { MC_PRESENCE_AVAILABLE, "MC_PRESENCE_AVAILABLE", "mc-presence-available" },
      { MC_PRESENCE_AWAY, "MC_PRESENCE_AWAY", "mc-presence-away" },
      { MC_PRESENCE_EXTENDED_AWAY, "MC_PRESENCE_EXTENDED_AWAY", "mc-presence-extended-away" },
      { MC_PRESENCE_HIDDEN, "MC_PRESENCE_HIDDEN", "mc-presence-hidden" },
      { MC_PRESENCE_DO_NOT_DISTURB, "MC_PRESENCE_DO_NOT_DISTURB", "mc-presence-do-not-disturb" },
      { LAST_MC_PRESENCE, "LAST_MC_PRESENCE", "last-mc-presence" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("McPresence", values);
  }
  return etype;
}
GType
mc_status_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { MC_STATUS_DISCONNECTED, "MC_STATUS_DISCONNECTED", "disconnected" },
      { MC_STATUS_CONNECTING, "MC_STATUS_CONNECTING", "connecting" },
      { MC_STATUS_CONNECTED, "MC_STATUS_CONNECTED", "connected" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static ("McStatus", values);
  }
  return etype;
}

/* Generated data ends here */


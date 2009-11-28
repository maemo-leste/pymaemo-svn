
/* Generated data (by glib-mkenums) */

/*
 * This file is part of python-location
 *
 * Copyright (C) 2009 Instituto Nokia de Tecnologia (INdT)
 *
 * Contact: PyMaemo Team <pymaemo-developers@garage.maemo.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#include "location-types.h"

/* enumerations from "/usr/include/location/location-gps-device.h" */

GType
location_gps_device_status_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { LOCATION_GPS_DEVICE_STATUS_NO_FIX, "LOCATION_GPS_DEVICE_STATUS_NO_FIX", "no-fix" },
            { LOCATION_GPS_DEVICE_STATUS_FIX, "LOCATION_GPS_DEVICE_STATUS_FIX", "fix" },
            { LOCATION_GPS_DEVICE_STATUS_DGPS_FIX, "LOCATION_GPS_DEVICE_STATUS_DGPS_FIX", "dgps-fix" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("LocationGPSDeviceStatus", values);
    }
    return etype;
}

GType
location_gps_device_mode_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { LOCATION_GPS_DEVICE_MODE_NOT_SEEN, "LOCATION_GPS_DEVICE_MODE_NOT_SEEN", "not-seen" },
            { LOCATION_GPS_DEVICE_MODE_NO_FIX, "LOCATION_GPS_DEVICE_MODE_NO_FIX", "no-fix" },
            { LOCATION_GPS_DEVICE_MODE_2D, "LOCATION_GPS_DEVICE_MODE_2D", "2d" },
            { LOCATION_GPS_DEVICE_MODE_3D, "LOCATION_GPS_DEVICE_MODE_3D", "3d" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("LocationGPSDeviceMode", values);
    }
    return etype;
}


/* enumerations from "/usr/include/location/location-gpsd-control.h" */

GType
location_gpsd_control_interval_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { LOCATION_INTERVAL_DEFAULT, "LOCATION_INTERVAL_DEFAULT", "default" },
            { LOCATION_INTERVAL_1S, "LOCATION_INTERVAL_1S", "1s" },
            { LOCATION_INTERVAL_2S, "LOCATION_INTERVAL_2S", "2s" },
            { LOCATION_INTERVAL_5S, "LOCATION_INTERVAL_5S", "5s" },
            { LOCATION_INTERVAL_10S, "LOCATION_INTERVAL_10S", "10s" },
            { LOCATION_INTERVAL_20S, "LOCATION_INTERVAL_20S", "20s" },
            { LOCATION_INTERVAL_30S, "LOCATION_INTERVAL_30S", "30s" },
            { LOCATION_INTERVAL_60S, "LOCATION_INTERVAL_60S", "60s" },
            { LOCATION_INTERVAL_120S, "LOCATION_INTERVAL_120S", "120s" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("LocationGPSDControlInterval", values);
    }
    return etype;
}

GType
location_gpsd_control_error_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { LOCATION_ERROR_USER_REJECTED_DIALOG, "LOCATION_ERROR_USER_REJECTED_DIALOG", "user-rejected-dialog" },
            { LOCATION_ERROR_USER_REJECTED_SETTINGS, "LOCATION_ERROR_USER_REJECTED_SETTINGS", "user-rejected-settings" },
            { LOCATION_ERROR_BT_GPS_NOT_AVAILABLE, "LOCATION_ERROR_BT_GPS_NOT_AVAILABLE", "bt-gps-not-available" },
            { LOCATION_ERROR_METHOD_NOT_ALLOWED_IN_OFFLINE_MODE, "LOCATION_ERROR_METHOD_NOT_ALLOWED_IN_OFFLINE_MODE", "method-not-allowed-in-offline-mode" },
            { LOCATION_ERROR_SYSTEM, "LOCATION_ERROR_SYSTEM", "system" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("LocationGPSDControlError", values);
    }
    return etype;
}


/* Generated data ends here */


#include "location-types-extras.h"

GType
location_gpsd_control_method_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GEnumValue values[] = {
            { LOCATION_METHOD_USER_SELECTED, "LOCATION_METHOD_USER_SELECTED", "user-selected" },
            { LOCATION_METHOD_CWP, "LOCATION_METHOD_CWP", "cwp" },
            { LOCATION_METHOD_ACWP, "LOCATION_METHOD_ACWP", "acwp" },
            { LOCATION_METHOD_GNSS, "LOCATION_METHOD_GNSS", "gnss" },
            { LOCATION_METHOD_AGNSS, "LOCATION_METHOD_AGNSS", "agnss" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static ("LocationGPSDControlMethod", values);
    }
    return etype;
}

GType
location_gps_device_set_get_type (void)
{
    static GType etype = 0;
    if (etype == 0) {
        static const GFlagsValue values[] = {
            { LOCATION_GPS_DEVICE_NONE_SET, "LOCATION_GPS_DEVICE_NONE_SET", "none" },
            { LOCATION_GPS_DEVICE_ALTITUDE_SET, "LOCATION_GPS_DEVICE_ALTITUDE_SET", "altitude" },
            { LOCATION_GPS_DEVICE_SPEED_SET, "LOCATION_GPS_DEVICE_SPEED_SET", "speed" },
            { LOCATION_GPS_DEVICE_TRACK_SET, "LOCATION_GPS_DEVICE_TRACK_SET", "track" },
            { LOCATION_GPS_DEVICE_CLIMB_SET, "LOCATION_GPS_DEVICE_CLIMB_SET", "climb" },
            { LOCATION_GPS_DEVICE_LATLONG_SET, "LOCATION_GPS_DEVICE_LATLONG_SET", "latlong" },
            { LOCATION_GPS_DEVICE_TIME_SET, "LOCATION_GPS_DEVICE_TIME_SET", "time" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static ("LocationGPSDeviceSet", values);
    }
    return etype;
}

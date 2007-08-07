''' Geoclue - A DBus api and wrapper for geography information
 * Copyright (C) 2006 Garmin
 * 
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2 as published by the Free Software Foundation; 
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
'''
cdef extern from 'glib.h':
    void g_type_init()

cdef extern from 'position.h':

    ctypedef enum GEOCLUE_POSITION_RETURNCODE:
        GEOCLUE_POSITION_SUCCESS                  =  0
        GEOCLUE_POSITION_NOT_INITIALIZED          = -1
        GEOCLUE_POSITION_DBUS_ERROR               = -2
        GEOCLUE_POSITION_SERVICE_NOT_AVAILABLE    = -3
        GEOCLUE_POSITION_METHOD_NOT_IMPLEMENTED   = -4
        GEOCLUE_POSITION_NO_SATELLITE_FIX         = -5
        GEOCLUE_POSITION_SATELLITE_NOT_IN_VIEW    = -6

    ctypedef enum GEOCLUE_POSITION_FIX:
        GEOCLUE_POSITION_NO_FIX                         = -1
        GEOCLUE_POSITION_TWO_DIMENSION                  = 1
        GEOCLUE_POSITION_THREE_DIMENSION                = 2
        GEOCLUE_POSITION_TWO_DIMENSION_DIFFERENTIAL     = 3
        GEOCLUE_POSITION_THREE_DIMENSION_DIFFERENTIAL   = 4

    ctypedef void (*GEOCLUE_POSITION_CALLBACK)(double lat, double lon, void* userdata)

    GEOCLUE_POSITION_RETURNCODE geoclue_position_version(int* major, int* minor, int* micro)
    GEOCLUE_POSITION_RETURNCODE geoclue_position_init()
    GEOCLUE_POSITION_RETURNCODE geoclue_position_init_specific(char* service, char* path)
    GEOCLUE_POSITION_RETURNCODE geoclue_position_get_all_providers(char*** OUT_service, char*** OUT_path, char*** OUT_desc)
    GEOCLUE_POSITION_RETURNCODE geoclue_position_close()
    GEOCLUE_POSITION_RETURNCODE geoclue_position_service_provider(char** name)
    GEOCLUE_POSITION_RETURNCODE geoclue_position_current_position (double* OUT_latitude, double* OUT_longitude )
    GEOCLUE_POSITION_RETURNCODE geoclue_position_set_position_callback(GEOCLUE_POSITION_CALLBACK callback, void* userdata )
    GEOCLUE_POSITION_RETURNCODE geoclue_position_current_position_error (double* OUT_latitude_error, double* OUT_longitude_error, GEOCLUE_POSITION_FIX* OUT_fix_type )
    GEOCLUE_POSITION_RETURNCODE geoclue_position_current_altitude (double* OUT_altitude )
    GEOCLUE_POSITION_RETURNCODE geoclue_position_current_velocity (double* OUT_north_velocity, double* OUT_east_velocity )
#    GEOCLUE_POSITION_RETURNCODE geoclue_position_satellites_in_view (GArray** OUT_prn_numbers )
    GEOCLUE_POSITION_RETURNCODE geoclue_position_satellites_data (int IN_prn_number, double* OUT_elevation, double* OUT_azimuth, double* OUT_signal_noise_ratio, unsigned int* OUT_differential, unsigned int* OUT_ephemeris )

def version():
    print 'version'

def init():
    g_type_init()

    status = geoclue_position_init()

    if (status != GEOCLUE_POSITION_SUCCESS):
        print 'Init Retorno: %d'%status

    return status

def init_specific():
    print 'Init Specific'

def get_all_providers():
    cdef char **service
    cdef char **path
    cdef char **desc

    status = geoclue_position_get_all_providers(&service, &path, &desc)

    if (status == GEOCLUE_POSITION_SUCCESS):
        ret_data = service[0], path[0], desc[0]
    else:
        ret_data = status

    return ret_data

#def close():

def service_provider():
    cdef char *name

    status = geoclue_position_service_provider(&name)

    if (status == GEOCLUE_POSITION_SUCCESS):
        ret_data = name[0]
    else:
        ret_data = status

    return ret_data

def current_position():
    cdef double latitude, longitude

    status = geoclue_position_current_position(&latitude, &longitude)

    if (status == GEOCLUE_POSITION_SUCCESS):
        ret_value = latitude, longitude
    else:
        ret_value = status

    return ret_value

#def set_position_callback(GEOCLUE_POSITION_CALLBACK callback, void* userdata ):
#def current_position_error (double* OUT_latitude_error, double* OUT_longitude_error, GEOCLUE_POSITION_FIX* OUT_fix_type ):
#def current_altitude (double* OUT_altitude ):
#def current_velocity (double* OUT_north_velocity, double* OUT_east_velocity ):
##def _satellites_in_view (GArray** OUT_prn_numbers ):
#def satellites_data (int IN_prn_number, double* OUT_elevation, double* OUT_azimuth, double* OUT_signal_noise_ratio, unsigned int* OUT_differential, unsigned int* OUT_ephemeris ):

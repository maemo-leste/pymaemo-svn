Python bindings for liblocation
###############################

location-distance-utils
***********************

.. module:: location

Utility functions for calculating distances.


Details
=======

.. function:: distance_between (latitude_s, longitude_s, latitude_f, longitude_f)

   Calculates the circle distance between two points, the origin (described by `latitude_s`, `longitude_s`) and the destination (described by `latitude_f`, `longitude_f`).

   :param latitude_s: Origin latitude
   :param longitute_s: Origin longitude
   :param latitude_f: Destination latitude
   :param longitude_f: Destination longitude
   :returns: Distance in km between the two points

LocationGPSDControl
*******************

.. module:: location.GPSDControl

Object for controlling location services.

.. todo:: add enumerations/flags/constants

Details
=======

.. data:: GPSDControlInterval

============================= =======================================
Value                         Meaning
============================= =======================================
``LOCATION_INTERVAL_DEFAULT`` Default value for the system.
``LOCATION_INTERVAL_1S``      1 second between subsequent fixes.
``LOCATION_INTERVAL_2S``      2 seconds between subsequent fixes.
``LOCATION_INTERVAL_5S``      5 seconds between subsequent fixes.
``LOCATION_INTERVAL_10S``     10 seconds between subsequent fixes.
``LOCATION_INTERVAL_20S``     20 seconds between subsequent fixes.
``LOCATION_INTERVAL_30S``     30 seconds between subsequent fixes.
``LOCATION_INTERVAL_60S``     60 seconds between subsequent fixes.
``LOCATION_INTERVAL_120S``    120 seconds between subsequent fixes. 
============================= =======================================


.. data:: GPSDControlError

======================================================= =================================================
Value                                                   Meaning
======================================================= =================================================
``LOCATION_ERROR_USER_REJECTED_DIALOG``                 User rejected location enabling dialog.
``LOCATION_ERROR_USER_REJECTED_SETTINGS``               User changed settings which disabled locationing.
``LOCATION_ERROR_BT_GPS_NOT_AVAILABLE``                 Problems using BT GPS.
``LOCATION_ERROR_METHOD_NOT_ALLOWED_IN_OFFLINE_MODE``   Method unavailable in offline mode.
``LOCATION_ERROR_SYSTEM``                               System error, dbus, hildon, etc.
======================================================= =================================================

.. function:: get_type ()


.. function:: get_default ()
   
   This function is used by applications to obtain a single instance of the LocationGPSDControl object.

   :returns: an instance of the LocationGPSDControl object.
.. function:: start ()
   
    Starts an active connection to Location server. In other words, by calling this function the application informs that it wants to use the location service.
.. function:: stop ()
   
   Informs the location framework that the application is no longer interested about the current location. Location service is kept running as long as there is at least one application using it. Please note that LocationGPSDevice still sends data as long as the location framework is running.

.. function:: request_status ()

.. warning:: location.GPSDControl.request_status is deprecated and should not be used in newly-written code.


LocationGPSDevice
*****************

.. module:: location.GPSDevice

Client side listener of location changes.

Details
=======

.. data:: GPSDeviceStatus

======================================= =============================================================================
Value                                   Meaning
======================================= =============================================================================
``LOCATION_GPS_DEVICE_STATUS_NO_FIX``   The device does not have a fix.
``LOCATION_GPS_DEVICE_STATUS_FIX``      The device has a fix.
``LOCATION_GPS_DEVICE_STATUS_DGPS_FIX`` The device has a DGPS fix. (*Deprecated: this constant is not used anymore.*)
======================================= =============================================================================

.. data:: GPSDeviceMode

===================================== ================================================
Value                                 Meaning
===================================== ================================================
``LOCATION_GPS_DEVICE_MODE_NOT_SEEN`` The device has not seen a satellite yet.
``LOCATION_GPS_DEVICE_MODE_NO_FIX``   The device has no fix.
``LOCATION_GPS_DEVICE_MODE_2D``       The device has latitude and longitude fix.
``LOCATION_GPS_DEVICE_MODE_3D``       The device has latitude, longitude, and altitude. 
===================================== ================================================



.. function:: get_type ()


.. function:: reset_last_known ()

Resets the last known location to unknown.

.. function:: start ()

.. warning:: location.GPSDevice.start() is deprecated and should not be used in newly-written code. This function does nothing.

.. function:: stop ()

.. warning:: location.GPSDevice.stop() is deprecated and should not be used in newly-written code. This function does nothing.


location-misc
*************

Miscellaneous utility functions.

Details
=======

.. function:: location.make_resident()

.. warning:: location.make_resident is deprecated and should not be used in newly-written code. 

Loads the location library into memory and makes it resident so that it cannot be unloaded.

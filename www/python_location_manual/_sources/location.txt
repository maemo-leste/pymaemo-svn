Python bindings for liblocation
###############################

.. module:: location

Module constants
****************

Interval between fixes:
=======================

.. data:: INTERVAL_DEFAULT

Default value for the system.

.. data:: INTERVAL_1S

1 second between subsequent fixes.

.. data:: INTERVAL_2S

2 seconds between subsequent fixes.

.. data:: INTERVAL_5S

5 seconds between subsequent fixes

.. data:: INTERVAL_10S

10 seconds between subsequent fixes.

.. data:: INTERVAL_20S

20 seconds between subsequent fixes.

.. data:: INTERVAL_30S

30 seconds between subsequent fixes.

.. data:: INTERVAL_60S

60 seconds between subsequent fixes.

.. data:: INTERVAL_120S

120 seconds between subsequent fixes.


Location methods
================

.. data:: LOCATION_METHOD_USER_SELECTED

The method is based on the current device settings. This is the default.

.. data:: LOCATION_METHOD_CWP

Use the Complimentary Wireless Position method.

.. data:: LOCATION_METHOD_ACWP

Use the Assisted Complimentary Wireless Position method.

.. data:: LOCATION_METHOD_GNSS

Use the Global Navigation Satellite System method.

.. data:: LOCATION_METHOD_AGNSS

Use the Assisted Global Navigation Satellite System method.

Location errors
===============

.. data::  ERROR_USER_REJECTED_DIALOG

User rejected location enabling dialog.

.. data::  ERROR_USER_REJECTED_SETTINGS

User changed settings which disabled locationing.

.. data:: ERROR_BT_GPS_NOT_AVAILABLE

Problems using BT GPS.

.. data::  ERROR_METHOD_NOT_ALLOWED_IN_OFFLINE_MODE

Method unavailable in offline mode.

.. data:: ERROR_SYSTEM

System error, dbus, hildon, etc.


Fix statuses
============

.. data:: GPS_DEVICE_STATUS_NO_FIX   

The device does not have a fix.

.. data:: GPS_DEVICE_STATUS_FIX      

The device has a fix.

.. data:: GPS_DEVICE_STATUS_DGPS_FIX 

The device has a DGPS fix. (*Deprecated: this constant is not used anymore.*)

Device modes
============

.. data:: GPS_DEVICE_MODE_NOT_SEEN 

The device has not seen a satellite yet.

.. data:: GPS_DEVICE_MODE_NO_FIX   

The device has no fix.

.. data:: GPS_DEVICE_MODE_2D       

The device has latitude and longitude fix.

.. data:: GPS_DEVICE_MODE_3D 

The device has latitude, longitude, and altitude. 


Miscellaneous functions
***********************

.. function:: distance_between (latitude_s, longitude_s, latitude_f, longitude_f)

   Calculates the circle distance between two points, the origin (described by `latitude_s`, `longitude_s`) and the destination (described by `latitude_f`, `longitude_f`).

   :param latitude_s: Origin latitude
   :param longitute_s: Origin longitude
   :param latitude_f: Destination latitude
   :param longitude_f: Destination longitude
   :returns: Distance in km between the two points


.. function:: make_resident ()

Loads the location library into memory and makes it resident so that it cannot be unloaded.

.. warning:: make_resident is deprecated and should not be used in newly-written code. 

   







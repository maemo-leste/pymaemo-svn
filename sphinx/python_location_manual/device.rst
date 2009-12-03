.. module:: location.GPSDevice

GPSDevice
#########

From http://wiki.maemo.org/PyMaemo/Using_Location_API#Using_liblocation_from_Python: GPSDevice has information about device status and contains the actual fix when one exists. 

Attributes
==========

.. data::  online 

Whether there is a connection to the hardware

.. data:: status

Status of the device

.. data:: fix

Tuple containing actual fix data (latitude, longitude, etc)

.. data:: satellites_in_view

Number of satellites in view

.. data:: satellites_in_use

Number of satellites in use

.. data:: satellites

Array of satellites

.. data:: cell_info

Information about cell the device is connected to 

.. warning:: Currently the attributes `satellites` and `cell_info` are not supported in Python.

Fix attribute members
=====================

.. data::  fix.mode 

The mode of the fix

.. data::  fix.fields

A bitfield representing which items of this tuple contain valid data

.. data::  fix.time

The timestamp of the update (location.GPS_DEVICE_TIME_SET)

.. data::  fix.lept

Time accuracy

.. data::  fix.latitude

Fix latitude (location.GPS_DEVICE_LATLONG_SET)

.. data::  fix.longitude

Fix longitude (location.GPS_DEVICE_LATLONG_SET)

.. data::  fix.eph

Horizontal position accuracy

.. data::  fix.altitude

Fix altitude in meters (location.GPS_DEVICE_ALTITUDE_SET)

.. data::   fix.epv

Vertical position accuracy

.. data::   fix.track

Direction of motion in degrees (location.GPS_DEVICE_TRACK_SET)

.. data::   fix.epd

Track accuracy

.. data::   fix.speed

Current speed in km/h (location.GPS_DEVICE_SPEED_SET)

.. data::   fix.eps

Speed accuracy

.. data::   fix.climb

Current rate of climb in m/s (location.GPS_DEVICE_CLIMB_SET)

.. data::   fix.epc

Climb accuracy 

Methods
=======

.. function:: reset_last_known ()

Resets the last known location to unknown.

.. function:: start ()

.. warning:: location.GPSDevice.start() is deprecated and should not be used in newly-written code. This function does nothing.

.. function:: stop ()

.. warning:: location.GPSDevice.stop() is deprecated and should not be used in newly-written code. This function does nothing.


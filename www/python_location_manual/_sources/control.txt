.. module:: location.GPSDControl

GPSDControl
###########

From http://wiki.maemo.org/PyMaemo/Using_Location_API#Using_liblocation_from_Python: GPSDControl is used for starting and stopping of location services, setting location method and interval, and listening for errors.

Functions
=========

.. function:: get_default ()

   This function is used by applications to obtain a single instance of the GPSDControl object.

   :returns: an instance of the GPSDControl object.

.. function:: start ()

    Starts an active connection to Location server. In other words, by calling this function the application informs that it wants to use the location service.

.. function:: stop ()

   Informs the location framework that the application is no longer interested about the current location. Location service is kept running as long as there is at least one application using it. Please note that GPSDevice still sends data as long as the location framework is running.

.. function:: request_status ()

.. warning:: location.GPSDControl.request_status is deprecated and should not be used in newly-written code.


Installation On Device
**********************

Maemo 5 (Fremantle)
-------------------

To install PyMaemo you first need to enable the PyMaemo repository,
so you can enjoy Python on your device.

.. note:: You will need a working internet connection to install
          PyMaemo on your device, check your device manual about
          how to configure one.

Follow the sequence depicted on the images below.
Open the **App Manager**, click on the title **Application manager**,
then on the button **Application catalogues**, then click on **New**.

Fill the new repository data with the information below and click **Save**.

| **Catalogue name:** `Maemo Extras-Devel`
| **Web address:** `http://repository.maemo.org/extras-devel`
| **Distribution:** `fremantle`
| **Components:** `free non-free`

OS2008 (Diablo)
---------------

These are the instructions for Diablo:

1. Open Application Manager
2. ApplicationManager->Tools->Application catalogue...
3. Edit Maemo Extras
4. Uncheck disabled box
5. Click OK and wait refresh

Now run x-term application, to get a command line prompt. Your device must be in RD mode. This is done using sudo flasher --enable-rd-mode.

Inside x-term type (hit ENTER after each line):

::

    sudo /usr/sbin/gainroot
    apt-get update
    apt-get install python2.5-runtime

When asked to agree, choose **Y**. Now wait until python is being installed.


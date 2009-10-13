Installation On Scratchbox
**************************

Follow these instructions to install the Maemo SDK on your PC.
Notice that the SDK will be installed on a Maemo target inside
the `Scratchbox <http://scratchbox.org>`_ environment,
Scratchbox and Maemo 5 SDK installers can be found on
`forum.nokia.com <http://www.forum.nokia.com/info/sw.nokia.com/id/c05693a1-265c-4c7f-a389-fc227db4c465/Maemo_5_SDK.html>`_.

Scratchbox works only on Linux platforms, if you are bound
to the Windows chains consider using the
`Maemo SDK Virtual Image <http://maemovmware.garage.maemo.org>`_.

Fremantle SDK
-------------

First make sure your targets have the Nokia Binaries installed.
If not, visit the `Maemo 5.0 (Fremantle) SDK EULA
<http://tablets-dev.nokia.com/eula/index.php>`_ page and proceed
as described there.

With the Fremantle targets properly installed add this line to
your targets **/etc/apt/sources.list**.

::

    deb http://repository.maemo.org/extras-devel/ fremantle free non-free


Now resynchronize your package index files with the following command:

::

    [sbox-FREMANTLE_X86: ~] > apt-get update


After that you are ready to install python2.5 plus bindings doing this:

::

    [sbox-FREMANTLE_X86: ~] > apt-get install python-sdk


To see all python-related packages issue this command

::

    [sbox-FREMANTLE_X86: ~] > apt-cache search python*


Note that you'll see also scratchbox's own python (version 2.3) which you
must not use for your Maemo development. So, run your scripts explicitly
calling python2.5 instead of just python.

Also, some programs require some extra configuration done by the
run-standalone.sh script. Call python with it as follows:

::

    run-standalone.sh python2.5 <yourscript.py>


Diablo (OS2009) SDK
-------------------

The first thing is to add the Maemo extras repository (where Python is located) to your list of package sources. To do that you will have to edit the file /etc/apt/sources.list  inside scratchbox, for both targets (X86 and ARMEL), which should look similar to this:

::

    deb http://repository.maemo.org/ diablo free non-free
    deb-src http://repository.maemo.org/ diablo free
    deb file:/home/[username]/maemo-sdk-nokia-binaries_4.1.2 diablo explicit

Add the following line to it:

::

    deb http://repository.maemo.org/extras/ diablo free non-free

Now resynchronize your package index files with the following command:

::

    [sbox-SDK_X86: ~] > apt-get update


After that you are ready to install python2.5 plus bindings doing this:

::

    [sbox-SDK_X86: ~] > apt-get install python2.5-sdk


To see all python-related packages issue this command

::

    [sbox-SDK_X86: ~] > apt-cache search python*


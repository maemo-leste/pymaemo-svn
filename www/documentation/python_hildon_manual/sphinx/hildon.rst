.. _hildon:

.. _hildon-building:

Compiling the Hildon libraries
******************************

.. _overview:

Building Hildon on UNIX-like systems
====================================

This chapter covers building and installing Hildon on UNIX and UNIX-like systems such as GNU/Linux.

On UNIX-like systems Hildon uses the standard GNU build system, using ``autoconf`` for package configuration and resolving portability issues, ``automake`` for building makefiles that comply with the GNU Coding Standards, and ``libtool`` for building shared libraries on multiple platforms.

The first thing to do before start building Hildon widgets is to uncompress the source tarball packages. For example:

::

  
        $ tar xvzf hildon-widgets-2.2.0.tar.gz
        $ tar xvjf hildon-widgets-2.2.0.tar.bz2
      

In the toplevel of the directory that is created, there will be a shell script called ``configure`` which you then run to take the template makefiles called ``Makefile.in`` in the package and create makefiles customized for your operating system. The ``configure``\ script can be passed various command line arguments to determine how the package is built and installed. The most commonly useful argument is the ``--prefix`` argument which determines where the package is installed. To install a package in ``/opt/hildon`` you would run configure as:

::

  
        $ ./configure --prefix=/opt/hildon
      

A full list of options can be found by running ``configure`` with the ``--help`` argument. In general, the defaults are right and should be trusted. After you've run ``configure``, you then run the ``make`` and ``make install`` commands to build the package and install it, respectively.

::

  
        $ make
        $ make install
      

If you don't have permission to write to the directory you are installing in, you may have to change to root temporarily before running ``make install``. Also, if you are installing in a system directory, on some systems you will need to run ``ldconfig`` after ``make install`` so that the newly installed libraries will be found.

Several environment variables are useful to pass to set before running configure. ``CPPFLAGS`` contains options to pass to the C compiler, and is used to tell the compiler where to look for include files. The ``LDFLAGS`` variable is used in a similar fashion for the linker. Finally, the ``PKG_CONFIG_PATH`` environment variable contains a search path that ``pkg-config`` (see below) uses when looking for for file describing how to compile programs using different libraries. If you were installing Hildon and its dependencies into ``/opt/hildon``, you might want to set these variables as:

::

  
        $ CPPFLAGS="-I/opt/hildon/include"
        $ LDFLAGS="-L/opt/hildon/lib"
        $ PKG_CONFIG_PATH="/opt/hildon/lib/pkgconfig"
        $ export CPPFLAGS LDFLAGS PKG_CONFIG_PATH
      

You may also need to set the ``LD_LIBRARY_PATH``\ environment variable so the systems dynamic linker can find the newly installed libraries, and the ``PATH``\ environment program so that utility binaries installed by the various libraries will be found.

::

  
        $ LD_LIBRARY_PATH="/opt/hildon/lib"
        $ PATH="/opt/hildon/bin:$PATH"
        $ export LD_LIBRARY_PATH PATH
      

.. _dependencies:

Dependencies
============

Before you can compile the Hildon widget toolkit, you need to have various other tools and libraries installed on your system. The two tools needed during the build process (apart from the tools mentioned above such as ``autoconf``) are ``pkg-config`` and GNU make.

* `pkg-config <http://pkg-config.freedesktop.org>`_ is a tool for tracking the compilation flags needed for libraries that are used by the Hildon libraries. For each library, a small ``.pc`` text file is installed in a standard location that contains the compilation flags needed for that library along with version number information.
* The Hildon makefiles will mostly work with different versions of ``make``, however, there tends to be a few incompatibilities, so the Hildon team recommends installing `GNU make <http://www.gnu.org/software/make>`_ if you don't already have it on your system and using it.
* GTK+
* Canberra

.. _extra-configuration-options:

Extra Configuration Options
===========================

In addition to the normal options, the ``configure`` script for the Hildon library supports a number of additional arguments.

.. _hildon-compiling:

Compiling Hildon Applications
*****************************

Compiling Hildon Applications on UNIX
=====================================

To compile a Hildon application, you need to tell the compiler where to find the Hildon header files and libraries. This is done with the ``pkg-config`` utility.

The following interactive shell session demonstrates how ``pkg-config`` is used (the actual output on your system may be different):

::

  
  $ pkg-config --cflags hildon-1
  -DMAEMO_CHANGES -DMAEMO_GTK -I/usr/include/hildon-1 -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pango-1.0
  -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/pixman-1
  $ pkg-config --libs hildon-1
  -lhildon-1 -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lpangocairo-1.0 -lpango-1.0 -lcairo -lgobject-2.0 -lgmodule-2.0 -lglib-2.0
  

The simplest way to compile a program is to use the "backticks" feature of the shell. If you enclose a command in backticks (*not single quotes*), then its output will be substituted into the command line before execution. So, to compile a Hildon Hello World you should type the following:

::

  
  $ cc `pkg-config --cflags --libs hildon-1` hello.c -o hello
  

If you want to make sure that your program doesn't use any deprecated functions, you can define the preprocessor symbol HILDON_DISABLE_DEPRECATED by using the command line option ``-DHILDON_DISABLE_DEPRECATED=1``.

.. _hildon-running:

Running Hildon Applications
***************************

Running and debugging Hildon Applications
=========================================

Since Hildon is built on top of GTK+, all Hildon applications support the same standard commandline options and inspect the same environment variables that a GTK+ application does. To know more about this, read `Running GTK+ Applications <gtk-running>`_

.. _hildon-resources:

Mailing lists and bug reports
*****************************

Filing a bug report or feature request
======================================

If you encounter a bug, misfeature, or missing feature in Hildon, please file a bug report on `http://bugs.maemo.org <http://bugs.maemo.org>`_ . File those against the "hildon-libs" component of the "Desktop Platform".

Don't hesitate to file a bug report, even if you think we may know about it already, or aren't sure of the details. Just give us as much information as you have, and if it's already fixed or has already been discussed, we'll add a note to that effect in the report.

The bug tracker should definitely be used for feature requests, it's not only for bugs. We track all Hildon development in Bugzilla, so it's the way to be sure the Hildon developers won't forget about an issue.

Submitting Patches
==================

If you develop a bugfix or enhancement for Hildon, please file that in Bugzilla as well. Bugzilla allows you to attach files; please attach a patch generated by the ``diff`` utility, using the ``-u`` option to make the patch more readable. All patches must be offered under the terms of the GNU LGPL license, so be sure you are authorized to give us the patch under those terms.

If you want to discuss your patch before or after developing it, mail `maemo-developers@maemo.org <mailto:maemo-developers@maemo.org>`_ . But be sure to file the Bugzilla report as well; if the patch is only on the list and not in Bugzilla, it's likely to slip through the cracks.

Mailing lists
=============

There are several mailing lists dedicated to Maemo platform and related libraries as Hildon. You can find more information on mailing lists at `http://maemo.org/community/mailing-lists <http://maemo.org/community/mailing-lists>`_ .


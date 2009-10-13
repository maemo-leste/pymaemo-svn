FAQ
===

**What is Python?**

    Python is a dynamic object-oriented programming language that can be used for many kinds of software development. It offers strong support for integration with other languages and tools, comes with extensive standard libraries, and can be learned in a few days.

**What is PyMaemo?**

    It is the Python package ported to run in Maemo based devices.

**Does PyMaemo come installed by default?**

    No, but there are some requirements and we expect to fulfill all of them in a near future.

**Why to use two diferent .install files?**

    Due to a limitation in Application Manager, only one repository can be handled by a .install file. PyMaemo depends on two repositories, to avoid duplication of packages. One repository contains base packages and another contains PyMaemo itself. This behaviour will change in a next release of Application Manager.

**Why I get "missing dependencies" message when I try to install PyMaemo?**

    Because you have to use both .install files (read previous question) as described at installation page.

**Why do some modules (e.g.: curses) are missing?**

    In order to keep the platform small and supportable, PyMaemo only comes with the most commonly used packages.

**Why do I get the error <put some error message here>?**

    First make sure that you are running python2.5 explicitly, as python inside scratchbox defaults to scratchbox' python (2.3)

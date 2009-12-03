FAQ
===

**What is Python?**

    Python is a dynamic object-oriented programming language that can be used
    for many kinds of software development. It offers strong support for
    integration with other languages and tools, comes with extensive standard
    libraries, and can be learned in a few days.

**What is PyMaemo?**

    It is the Python package ported to run in Maemo based devices.

**Does PyMaemo come installed by default?**

    No, but there are some requirements and we expect to fulfill all of them in
    a near future.

**Why to use two diferent .install files?**

    Due to a limitation in Application Manager, only one repository can be
    handled by a .install file. PyMaemo depends on two repositories, to avoid
    duplication of packages. One repository contains base packages and another
    contains PyMaemo itself. This behaviour will change in a next release of
    Application Manager.

**Why I get "missing dependencies" message when I try to install PyMaemo?**

    Because you have to use both .install files (read previous question) as
    described at installation page.

**Why do some modules (e.g.: curses) are missing?**

    In order to keep the platform small and supportable, PyMaemo only comes
    with the most commonly used packages.

**I get errors like "ImportError: No module named xyz" even though module xyz is installed under /usr/lib/python2.5**

**Why do I get the error <put some error message here>?**

    Inside Scratchbox, if you call just "python" it will run the internal
    Python interpreter used by Scratchbox (/scratchbox/tools/bin/python), which
    is at version 2.3. This interpreter will not see any modules installed
    inside your target.

    This occurs **even** if you use the complete path (/usr/bin/python), due to
    some path redirection trick done by Scratchbox. Therefore, to make sure you
    are using the correct Python interpreter (currently at version 2.5), make
    sure to call "python2.5" explicitely, i.e. use "#!/usr/bin/python2.5 at the
    beginning of your scripts and modify Debian packaging so that python2.5 is
    called instead of just "python".

**When I build my Python application on Scratchbox, files are installed in /scratchbox/...**

**How do I modify Debian packaging so the correct Python interpreter is called?**

    You can try adding these lines to the beginning of your debian/rules (after
    the first "#!/usr/bin/make -f" line)::

        PATH := /usr/bin:$(PATH)
        export PATH
        SBOX_REDIRECT_IGNORE = /usr/bin/python
        export SBOX_REDIRECT_IGNORE

    If that still does not work, please post your error messages to our
    `mailing list <https://garage.maemo.org/mailman/listinfo/pymaemo-developers/>`_.

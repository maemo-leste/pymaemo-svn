#!/usr/bin/python2.5
import sys
import glob
from distutils.core import setup

sys.path.append("/usr/share/pygtk/2.0")
from dsextras import BuildExt, TemplateExtension, getoutput

defsdir = getoutput("pkg-config --variable=defsdir pygtk-2.0")

extensions = []

hildon = TemplateExtension(name = "hildon",
                           pkc_name = "hildon-1",
                           pkc_version = "2.1.42",
                           pygobject_pkc = ("hildon-fm-2",
                                            "pygobject-2.0",
                                            "gconf-2.0", # needed by hildon-fm-2 (see MB#4538)
                                            "gnome-vfs-2.0", # needed by hildon-fm-2 (see MB#4538)
                                            "hildon-notify",
                                            "dbus-1",
                                            "dbus-glib-1",
                                           ),
                           sources = ["hildonmodule.c",
                                      "hildon.c",
                                      "hildon-types.c",
                                     ],
                           defs = "hildon.defs",
                           override = "hildon.override",
                           register = [defsdir + "/gtk-types.defs",
                                       defsdir + "/gdk-types.defs",
                                       defsdir + "/gtk-base.defs",
                                       defsdir + "/pynotify.defs",
                                      ],
                           extra_compile_args = ["-DMAEMO_CHANGES",
                                                 "-DMAEMO_GTK",
                                                ],
                          )

extensions.append(hildon)

setup(name = "hildon",
      version = "0.9.0",
      ext_modules = extensions,
      py_modules = ["hildonglade"],
      data_files = [("/usr/share/python-hildon-dev/examples", glob.glob("examples/*.py")),
                    ("/usr/share/python-hildon-dev/defs", glob.glob("defs/*.defs")),
                    ("/usr/share/python-hildon-tests", glob.glob("tests/*.py"))],
      cmdclass = {"build_ext": BuildExt}
     )

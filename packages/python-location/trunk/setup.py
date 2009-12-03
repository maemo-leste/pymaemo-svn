#!/usr/bin/python2.5
import sys
import glob
from distutils.core import setup

sys.path.append("/usr/share/pygtk/2.0")
from dsextras import BuildExt, TemplateExtension, getoutput

defsdir = getoutput("pkg-config --variable=defsdir pygtk-2.0")

extensions = []

location = TemplateExtension(name = "location",
                             pkc_name = "liblocation",
                             pkc_version = "0.99",
                             sources = ["locationmodule.c",
                                        "location.c",
                                        "location-types.c",
                                        "location-types-extras.c",
                                       ],
                             defs = "location.defs",
                             override = "location.override",
                             register = [defsdir + "/gtk-types.defs",
                                         defsdir + "/gdk-types.defs",
                                         defsdir + "/gtk-base.defs",
                                        ],
                             extra_compile_args = ["-DMAEMO_CHANGES",
                                                   "-DMAEMO_GTK",
                                                   "-Werror",
                                                  ],
                             extra_link_args = ["-Wl,-zdefs", "-lpython2.5"],
                            )

extensions.append(location)

setup(name = "location",
      version = "0.1",
      ext_modules = extensions,
      cmdclass = {"build_ext": BuildExt}
     )

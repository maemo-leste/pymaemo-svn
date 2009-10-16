#!/usr/bin/python2.5
import sys
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
                                      ],
                           extra_compile_args = ["-DMAEMO_CHANGES",
                                                 "-DMAEMO_GTK",
                                                ],
                          )

extensions.append(hildon)

setup(name = "hildon",
      version = "0.9.0",
      ext_modules = extensions,
      cmdclass = {"build_ext": BuildExt}
     )

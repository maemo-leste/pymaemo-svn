News
****

PyMaemo for Maemo 5 beta 2 SDK just released *2009-08-09*
---------------------------------------------------------

New packages:

* python-mafw (0.1-1maemo1)
* python-hildondesktop (0.0.3-1maemo1)
* python-notify (0.1.1-2maemo1)
* pyclutter (0.8.0-1maemo2)

Updated packages:

* gnome-python (2.26.1-1maemo1)
* pygtk (2.12.1-6maemo7)
* python2.5 (2.5.4-1maemo1)
* python-central (0.6.11.1maemo1)
* python-defaults (2.5.2-3maemo3)
* python-hildon (0.9.0-1maemo10)
* python-setuptools (0.6c9-1maemo1)

Bugs closed:

* MB#4530
* MB#4450
* MB#4629
* MB#4628
* MB#4647
* MB#4632
* MB#4646
* MB#4750
* MB#4749
* MB#4791

Known issues:

* MB#4782
* MB#4821
* MB#4824
* MB#4839
* MB#4849
* MB#4734

PyMaemo for Maemo 5 beta SDK just released *2009-05-11*
---------------------------------------------------------

New packages:

* gst0.10-python (0.10.14-2maemo3)
* pyid3lib (0.5.1-2maemo2)

Updated packages:

* pygame (1.8.1release-0maemo3)
* python-support (1.0.2maemo1)
* python-conic (0.1-5)
* pycurl (7.18.2-1)
* python2.5 (2.5.2-15maemo2)
* pygtk (2.12.1-6maemo6)
* python-hildon (0.9.0-1maemo4)

Bugs closed:

* MB#4426
* GB#4008
* GB#2051
* MB#4235

Known issues:

* MB#4492
* MB#4530

PyMaemo for Maemo 5 alpha SDK released *2009-04-02*
---------------------------------------------------

* Updated versions of all packages, now matching the Debian Lenny stable
  release.
* Custom packaging was dropped and now we use the standard Debian packages
  (plus Maemo specific customizations). This means that PyMaemo packages
  should now be fully compatible with Debian, thus facilitating ports of
  existing applications from Debian.
* Dropped python-gpsbt package, since libgpsbt does not exists on fremantle
  anymore.
* Added ipython (not installed by python-runtime)
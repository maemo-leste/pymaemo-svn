#!/usr/bin/env python2.5
import unittest

import gtk
import hildon

class TestHildonBannerNullArguments(unittest.TestCase):
    def setUp(self):
        self.parent = hildon.Window()

    def tearDown(self):
        self.parent.destroy()

    def testShowInformation(self):
        hildon.hildon_banner_show_information(self.parent,
                                              "",
                                              "Dummy text")

    def testShowInformationWithMarkup(self):
        hildon.hildon_banner_show_information_with_markup(self.parent,
                                              "",
                                              "Dummy text")

    def testShowAnimation(self):
        hildon.hildon_banner_show_animation(self.parent,
                                              "",
                                              "Dummy text")

    def testShowProgressbar(self):
        hildon.hildon_banner_show_progress(self.parent,
                                              gtk.ProgressBar(),
                                              "Dummy text")

if __name__ == "__main__":
    unittest.main()

#!/usr/bin/env python2.5

"""
Tests for pymaemo bug #2009 - null arguments in hildonBanner functions
"""

import unittest

import pygtk
pygtk.require("2.0")

import hildon

class TestHildonBannerNullArguments(unittest.TestCase):
    
    
    def setUp(self):
        self.parent = hildon.Window()

    def tearDown(self):
        self.parent.destroy()

    def testShowInformation(self):
        hildon.hildon_banner_show_information(self.parent,
                                              None,
                                              "Dummy text")
        
    def testShowInformationWithMarkup(self):
        hildon.hildon_banner_show_information_with_markup(self.parent,
                                              None,
                                              "Dummy text")

    def testShowAnimation(self):
        hildon.hildon_banner_show_animation(self.parent,
                                              None,
                                              "Dummy text")

    def testShowProgressbar(self):
        hildon.hildon_banner_show_progress(self.parent,
                                              None,
                                              "Dummy text")
        
if __name__ == "__main__":
    unittest.main()


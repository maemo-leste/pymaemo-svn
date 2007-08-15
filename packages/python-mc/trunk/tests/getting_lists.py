#!/usr/bin/env python

import unittest

import mc

class TestLists(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def testProtocolGetParams(self):
        protocol = mc.protocols_list()[0]
        a = protocol.get_params()
        print a

    def testProtocolListByManager(self):
        protocols = mc.protocols_list()
        for protocol in protocols:
            manager = protocol.get_manager()
            prof2 = mc.protocols_list(manager=manager)
            self.assert_(protocol in prof2)

    def testAccountList(self):
        accounts = mc.accounts_list()
        accounts = mc.accounts_list(enabled=True)
        accounts = mc.accounts_list(vcard_field="Foobar")
        profile = mc.profiles_list()[0]
        accounts = mc.accounts_list(profile=profile)

    def testProfileList(self):
        profiles = mc.profiles_list()
        for profile in profiles:
            field = profile.get_vcard_field()
            prof2 = mc.profiles_list(vcard_field=field)
            self.assert_(profile in prof2)

if __name__ == "__main__":
    unittest.main()

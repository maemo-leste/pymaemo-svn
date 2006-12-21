# This set of tests exercises the backward-compatibility class
# in mailbox.py (the ones without write support).

import mailbox
import os
import time
import unittest
from test import test_support

# cleanup earlier tests
try:
    os.unlink(test_support.TESTFN)
except os.error:
    pass

FROM_ = "From some.body@dummy.domain  Sat Jul 24 13:43:35 2004\n"
DUMMY_MESSAGE = """\
From: some.body@dummy.domain
To: me@my.domain
Subject: Simple Test

This is a dummy message.
"""

class MaildirTestCase(unittest.TestCase):

    def setUp(self):
        # create a new maildir mailbox to work with:
        self._dir = test_support.TESTFN
        os.mkdir(self._dir)
        os.mkdir(os.path.join(self._dir, "cur"))
        os.mkdir(os.path.join(self._dir, "tmp"))
        os.mkdir(os.path.join(self._dir, "new"))
        self._counter = 1
        self._msgfiles = []

    def tearDown(self):
        map(os.unlink, self._msgfiles)
        os.rmdir(os.path.join(self._dir, "cur"))
        os.rmdir(os.path.join(self._dir, "tmp"))
        os.rmdir(os.path.join(self._dir, "new"))
        os.rmdir(self._dir)

    def createMessage(self, dir, mbox=False):
        t = int(time.time() % 1000000)
        pid = self._counter
        self._counter += 1
        filename = os.extsep.join((str(t), str(pid), "myhostname", "mydomain"))
        tmpname = os.path.join(self._dir, "tmp", filename)
        newname = os.path.join(self._dir, dir, filename)
        fp = open(tmpname, "w")
        self._msgfiles.append(tmpname)
        if mbox:
            fp.write(FROM_)
        fp.write(DUMMY_MESSAGE)
        fp.close()
        if hasattr(os, "link"):
            os.link(tmpname, newname)
        else:
            fp = open(newname, "w")
            fp.write(DUMMY_MESSAGE)
            fp.close()
        self._msgfiles.append(newname)
        return tmpname

    def test_empty_maildir(self):
        """Test an empty maildir mailbox"""
        # Test for regression on bug #117490:
        self.mbox = mailbox.Maildir(test_support.TESTFN)
        self.assert_(len(self.mbox) == 0)
        self.assert_(self.mbox.next() is None)
        self.assert_(self.mbox.next() is None)

    def test_nonempty_maildir_cur(self):
        self.createMessage("cur")
        self.mbox = mailbox.Maildir(test_support.TESTFN)
        self.assert_(len(self.mbox) == 1)
        self.assert_(self.mbox.next() is not None)
        self.assert_(self.mbox.next() is None)
        self.assert_(self.mbox.next() is None)

    def test_nonempty_maildir_new(self):
        self.createMessage("new")
        self.mbox = mailbox.Maildir(test_support.TESTFN)
        self.assert_(len(self.mbox) == 1)
        self.assert_(self.mbox.next() is not None)
        self.assert_(self.mbox.next() is None)
        self.assert_(self.mbox.next() is None)

    def test_nonempty_maildir_both(self):
        self.createMessage("cur")
        self.createMessage("new")
        self.mbox = mailbox.Maildir(test_support.TESTFN)
        self.assert_(len(self.mbox) == 2)
        self.assert_(self.mbox.next() is not None)
        self.assert_(self.mbox.next() is not None)
        self.assert_(self.mbox.next() is None)
        self.assert_(self.mbox.next() is None)

    def test_unix_mbox(self):
        ### should be better!
        import email.Parser
        fname = self.createMessage("cur", True)
        n = 0
        for msg in mailbox.PortableUnixMailbox(open(fname),
                                               email.Parser.Parser().parse):
            n += 1
            self.assertEqual(msg["subject"], "Simple Test")
            self.assertEqual(len(str(msg)), len(FROM_)+len(DUMMY_MESSAGE))
        self.assertEqual(n, 1)

    # XXX We still need more tests!


def test_main():
    test_support.run_unittest(MaildirTestCase)


if __name__ == "__main__":
    test_main()

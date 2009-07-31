
import unittest

import gtk
import hildon

class TestConstructor(unittest.TestCase):

    def setUp(self):
        self.summary = 'summary'
        self.body = 'body'
        self.icon = 'open'
        self.category = 'category'

    def testBasic(self):
        notification = hildon.Notification(self.summary, self.body, self.icon)
        self.assert_(isinstance(notification, hildon.Notification))

    def testMissingArgs(self):
        self.assertRaises(TypeError, hildon.Notification)
        self.assertRaises(TypeError, hildon.Notification, 'summary')
        self.assertRaises(TypeError, hildon.Notification, 'summary', 'body')

    def testWithCategory(self):
        notification = hildon.Notification(self.summary, self.body,
                                           self.icon, self.category)
        self.assert_(isinstance(notification, hildon.Notification))

class TestPersistent(unittest.TestCase):
    def testPersistent(self):
        notification = hildon.Notification('sum', 'bod', 'open')
        # TODO Sets the hint byte "persistent". Could't find a way to
        # verify if its really set.
        notification.set_persistent(True)

    def testPersistentInvalidArg(self):
        notification = hildon.Notification('sum', 'bod', 'open')
        self.assertRaises(TypeError, notification.set_persistent, 'aaa')

class TestSound(unittest.TestCase):
    def testSound(self):
        notification = hildon.Notification('sum', 'bod', 'open')
        # Same case as set_persistent
        notification.set_sound('foo.wav')

    def testSoundInvalidArg(self):
        notification = hildon.Notification('sum', 'bod', 'open')
        self.assertRaises(TypeError, notification.set_sound, 33)


if __name__ == '__main__':
    unittest.main()

import unittest

import gtk
import hildon

class TestHildonWindowStack(unittest.TestCase):
    def test_get_default(self):
        default_stack = hildon.WindowStack.get_default()
        self.assert_(isinstance(default_stack, hildon.WindowStack))

    def test_get_windows(self):
        stack = hildon.WindowStack()
        w = hildon.StackableWindow()
        stack.push_1(w)
        self.assertTrue(stack.get_windows(), [w])

    def test_push_list(self):
        stack = hildon.WindowStack()
        w1 = hildon.StackableWindow()
        w2 = hildon.StackableWindow()
        stack.push_list([w1, w2])
        self.assertTrue(stack.get_windows(), [w1, w2])

if __name__ == '__main__':
    unittest.main()

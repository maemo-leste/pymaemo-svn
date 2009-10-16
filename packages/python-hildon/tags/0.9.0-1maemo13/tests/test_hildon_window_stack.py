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
        self.assertEqual(stack.get_windows(), [w])

    def test_push_list(self):
        stack = hildon.WindowStack()
        self.assertRaises(TypeError, stack.push_list)
        self.assertRaises(TypeError, stack.push_list, "x")
        w1 = hildon.StackableWindow()
        w2 = hildon.StackableWindow()
        stack.push_list([w1, w2])
        self.assertEqual(set(stack.get_windows()), set([w1, w2]))

    def test_push(self):
        stack = hildon.WindowStack()
        self.assertRaises(TypeError, stack.push)
        self.assertRaises(TypeError, stack.push, "x")
        w1 = hildon.StackableWindow()
        w2 = hildon.StackableWindow()
        stack.push(w1, w2)
        self.assertEqual(set(stack.get_windows()), set([w1, w2]))

    def test_pop(self):
        stack = hildon.WindowStack()
        self.assertRaises(TypeError, stack.pop)
        self.assertRaises(TypeError, stack.pop, "x")
        self.assertEqual(stack.pop(1), [])
        w1 = hildon.StackableWindow()
        w2 = hildon.StackableWindow()
        stack.push(w1, w2)
        self.assertEqual(set(stack.pop(2)), set([w1, w2]))
        self.assertEqual(stack.pop(1), [])

    def test_pop_and_push_list(self):
        stack = hildon.WindowStack()
        self.assertRaises(TypeError, stack.pop_and_push_list)
        self.assertRaises(TypeError, stack.pop_and_push_list, "x")
        w1 = hildon.StackableWindow()
        w2 = hildon.StackableWindow()
        stack.push(w1, w2)
        w3 = hildon.StackableWindow()
        w4 = hildon.StackableWindow()
        self.assertRaises(TypeError, stack.pop_and_push_list, 2, "x")
        popped = stack.pop_and_push_list(2, [w3, w4])
        self.assertEqual(set(popped), set([w1, w2]))
        popped = stack.pop_and_push_list(2, [])
        self.assertEqual(set(popped), set([w3, w4]))
        self.assertEqual(stack.pop(1), [])

    def test_pop_and_push(self):
        stack = hildon.WindowStack()
        self.assertRaises(TypeError, stack.pop_and_push)
        self.assertRaises(TypeError, stack.pop_and_push, "x")
        w1 = hildon.StackableWindow()
        w2 = hildon.StackableWindow()
        stack.push(w1, w2)
        w3 = hildon.StackableWindow()
        w4 = hildon.StackableWindow()
        self.assertRaises(TypeError, stack.pop_and_push, 2, "x")
        popped = stack.pop_and_push(2, w3, w4)
        self.assertEqual(set(popped), set([w1, w2]))
        popped = stack.pop_and_push(2)
        self.assertEqual(set(popped), set([w3, w4]))
        self.assertEqual(stack.pop(1), [])

if __name__ == '__main__':
    unittest.main()

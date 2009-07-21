# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 2.2, "Pushing a new window into a stack"

import hildon

win = hildon.StackableWindow()
stack = hildon.WindowStack.get_default()
stack.push_1(win)


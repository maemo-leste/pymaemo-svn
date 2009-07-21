# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 2.4, "Popping a number of windows from a stack into a list"

import hildon

nwindows = 10

stack = hildon.WindowStack.get_default()

if stack.size() > nwindows:
    list = stack.pop(nwindows)

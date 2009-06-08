# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 2.4, "Popping a number of windows from a stack into a list"

import hildon

stack = hildon.hildon_stackable_window_get_default()
nwindows = 10
win_list = []

if stack.hildon_stackable_window_size() > nwindows :
    stack.hildon_window_stack_pop(nwindows, win_list)


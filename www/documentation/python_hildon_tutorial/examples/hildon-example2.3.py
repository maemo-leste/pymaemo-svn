# Based on C code from:
# "Hildon Tutorial" version 2009-04-28
# Example 2.3, "Pushing a list of windows into a stack"

import hildon

window = hildon.StackableWindow()
window.show_all()
stack = window.get_stack()

nwindows = 10
win_list = []

while nwindows > 0:
    parent = hildon.StackableWindow()
    win_list.append(parent) 
    nwindows -= 1;

#TODO: push_list must be implemented as an override
stack.push_list(win_list)


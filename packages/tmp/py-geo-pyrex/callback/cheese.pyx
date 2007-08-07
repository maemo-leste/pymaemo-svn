#
#   Pyrex wrapper for the cheesefinder API
#

cdef extern from "cheesefinder.h":
    ctypedef void (*cheesefunc)(char *name, void *user_data)
    void find_cheeses(cheesefunc user_func, void *user_data)

def find(cb_func, user_data=None):
    data = cb_func, user_data
    find_cheeses(callback, <void*>data)

cdef void callback(char *name, void *data):
    function = (<object>data)[0]
    user_data = (<object>data)[1]
    cb_func = (<object>function)
    cb_func(name, user_data)

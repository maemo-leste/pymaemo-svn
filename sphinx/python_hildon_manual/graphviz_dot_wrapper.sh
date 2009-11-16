#!/bin/sh
# wrapper to allow running sphinx-build outside Scratchbox, but still importing
# Python modules from Scratchbox for generating graph inheritance data.

# unset LD_LIBRARY_PATH so that "dot" can work properly.
unset LD_LIBRARY_PATH
exec dot "$@"

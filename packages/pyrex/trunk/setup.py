#
#   Pyrex setup file
#

from distutils.core import setup
from distutils.sysconfig import get_python_lib
import os
from Pyrex.Compiler.Version import version

compiler_dir = os.path.join(get_python_lib(prefix=''), 'Pyrex/Compiler')

def packages():
    result = []
    def find_packages(dir, parent_names):
        for name in os.listdir(dir):
            subdir = os.path.join(dir, name)
            if os.path.isdir(subdir) and os.path.exists(os.path.join(subdir, "__init__.py")):
                pkg_names = parent_names + [name]
                result.append(".".join(pkg_names))
                find_packages(subdir, pkg_names)
    source_dir = os.path.dirname(__file__) or os.curdir
    find_packages(source_dir, [])
    return result

def scripts():
    if os.name == "posix":
        return ["bin/pyrexc"]
    else:
        return ["pyrexc.py"]

setup(
    name = 'Pyrex', 
    version = version,
    url = 'http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/',
    author = 'Greg Ewing',
    author_email = 'greg.ewing@canterbury.ac.nz',
    scripts = scripts(),
    packages = packages(),
    data_files=[
        (compiler_dir, ['Pyrex/Compiler/Lexicon.pickle'])
    ]
)

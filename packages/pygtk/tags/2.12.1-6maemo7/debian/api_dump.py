#!/usr/bin/env python

'''Script to show the difference between two modules APIs'''

import sys
import inspect

try:
    import yaml
    has_yaml = True
except ImportError:
    has_yaml = False
    sys.stderr.write("Can't import yaml. Using raw output.")

from optparse import OptionParser

from api_helper import ClassInfo

try:
    import psyco
    psyco.profile()
except ImportError:
    pass

def build_option_parser():
    parser = OptionParser()

    parser.add_option('-r', '--raw', action='store_true', dest='raw',
                        default=False)

    return parser

def owner_class(method, cls=None):
    '''Returns the class where the method is first defined.

    For builtin methods where the attribute im_class isn't available,
    pass the method's class (where you access it) in the cls argument.'''

    root_cls = cls if cls else method.im_class

    try:
        return filter(lambda cls: hasattr(cls, method.__name__),
                      root_cls.__mro__)[-1]
    except AttributeError:
        return None # Don't handle old style classes


def build_class_data(klass):
    '''Builds the ClassInfo wrapper for klass'''
    cls = ClassInfo(klass.__name__)

    for member_name, member in inspect.getmembers(klass):
        if member_name.startswith('__'):
            continue

        if not inspect.isroutine(member):
            cls.members.append(member_name)
        elif owner_class(member, cls=klass) == klass:
            cls.members.append(member_name)

    return cls


def build_module_data(module):
    '''Returns two dicts with this module's classes and variables'''

    classes = {}
    variables = {}

    for obj_name, obj in inspect.getmembers(module):
        if obj_name.startswith('__') or inspect.ismodule(obj):
            continue

        if inspect.isclass(obj):
            classes[obj_name] = build_class_data(obj)
        else:
            variables[obj_name] = obj

    return classes, variables

def load_module(name):
    '''Imports a module and returns it. Wrapper for package.module cases'''
    module = __import__(name)

    if '.' in name: # __imports__ returns the top level package
        _, mod_name = name.split('.')
        module = getattr(module, mod_name)

    return module

def raw_print(classes, variables, output):
    data = variables.keys()
    for cls in classes:
        data.append(str(classes[cls]))
        for member in classes[cls].members:
            data.append("%s.%s" % (classes[cls], member))

    output.write('\n'.join(sorted(data))+'\n')

def main(argv=None):
    '''Dumps the module contents into a text file'''
    if argv is None:
        argv = sys.argv

    parser = build_option_parser()

    opt, args = parser.parse_args(sys.argv)

    if len(args) < 2:
        sys.stderr.write("Usage: api_dump.py <module>\n")
        sys.exit(1)

    module_name = args[1]
    module = load_module(module_name)

    classes, variables = build_module_data(module)

    output = file(module_name+'.txt', 'w')

    if has_yaml and not opt.raw:
        yaml.dump({'classes':classes,
                     'variables':sorted(variables.keys())},
                     output)
    else:
        raw_print(classes, variables, output)

if __name__ == '__main__':
    main()

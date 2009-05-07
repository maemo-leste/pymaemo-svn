/* -*- Mode: C; c-basic-offset: 4 -*-
 * python-hildon - Python bindings for the Hildon toolkit.
 *
 *   hildonmodule.c: module wrapping the Hildon library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#include <Python.h>

#include <pygobject.h>
#include <pygtk/pygtk.h>

void pyhildon_register_classes(PyObject *d);
extern void pyhildon_add_constants(PyObject *module, const gchar *strip_prefix);
extern PyMethodDef pyhildon_functions[];

static void
_add_keysyms(PyObject *module)
{
    PyModule_AddIntConstant(module, "KEY_LEFT", 0xff51);
    PyModule_AddIntConstant(module, "KEY_UP", 0xff52);
    PyModule_AddIntConstant(module, "KEY_RIGHT", 0xff53);
    PyModule_AddIntConstant(module, "KEY_DOWN", 0xff54);

    PyModule_AddIntConstant(module, "KEY_SELECT", 0xff0d);
    PyModule_AddIntConstant(module, "KEY_MENU", 0xffc1);
    PyModule_AddIntConstant(module, "KEY_HOME", 0xffc2);
    PyModule_AddIntConstant(module, "KEY_ESC", 0xff1b);
    PyModule_AddIntConstant(module, "KEY_FULLSCREEN", 0xffc3);
    PyModule_AddIntConstant(module, "KEY_INCREASE", 0xffc4);
    PyModule_AddIntConstant(module, "KEY_DECREASE", 0xffc5);
}

DL_EXPORT(void)
inithildon(void)
{
    PyObject *m, *d;

    m = Py_InitModule("hildon", pyhildon_functions);
    d = PyModule_GetDict(m);

    init_pygobject();
    init_pygtk();
    
    pyhildon_register_classes(d);
    pyhildon_add_constants(m, "HILDON_");
    _add_keysyms(m);
}

/* -*- Mode: C; c-basic-offset: 4 -*-
 * pygtk- Python bindings for the GTK toolkit.
 *
 *   hildonmimemodule.c: wrapper for Hildon widgets library.
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

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif
#include <Python.h>

#include <pygobject.h>
#include <pygtk/pygtk.h>

void pyhildonmime_register_classes (PyObject *d);
extern void pyhildonmime_add_constants(PyObject *module, const gchar *strip_prefix);
extern PyMethodDef pyhildonmime_functions[];

void _add_keysyms(PyObject *module)
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
    return;
}

DL_EXPORT(void)
inithildonmime (void)
{
    PyObject *m, *d;

    m = Py_InitModule("hildonmime", pyhildonmime_functions);
    d = PyModule_GetDict(m);

    init_pygobject();
    init_pygtk();
    
    pyhildonmime_register_classes(d);
    pyhildonmime_add_constants(m, "HILDON_");
    _add_keysyms(m);
}

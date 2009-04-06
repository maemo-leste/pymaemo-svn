/* -*- Mode: C; c-basic-offset: 4 -*-
 * pygtk- Python bindings for the GTK toolkit.
 *
 *   hildonhelpmodule.c: wrapper for Hildon widgets library.
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

void pyhildonhelp_register_classes (PyObject *d);
extern PyMethodDef pyhildonhelp_functions[];

DL_EXPORT(void)
inithildonhelp (void)
{
    PyObject *m, *d;

    m = Py_InitModule("hildonhelp", pyhildonhelp_functions);
    d = PyModule_GetDict(m);

    init_pygobject();
    init_pygtk();

    pyhildonhelp_register_classes(d);
}

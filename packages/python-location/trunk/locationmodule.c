/*
 * This file is part of python-location
 *
 * Copyright (C) 2009 Instituto Nokia de Tecnologia (INdT)
 *
 * Contact: PyMaemo Team <pymaemo-developers@garage.maemo.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#include <pygobject.h>

void pylocation_register_classes(PyObject *d);
void pylocation_add_constants(PyObject *module, const gchar *strip_prefix);
extern PyMethodDef pylocation_functions[];

DL_EXPORT(void)
initlocation(void)
{
    init_pygobject();

    PyObject *m = Py_InitModule("location", pylocation_functions);
    PyObject *d = PyModule_GetDict(m);

    pylocation_register_classes(d);
    pylocation_add_constants(m, "LOCATION_");
    if (PyErr_Occurred())
        Py_FatalError("could not initialise \"location\" module");
}

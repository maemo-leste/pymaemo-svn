/* -*- Mode: C; c-basic-offset: 4 -*-
 * python-mc - Python bindings for the MissionControl library.
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

#ifndef DBUS_API_SUBJECT_TO_CHANGE
#define DBUS_API_SUBJECT_TO_CHANGE
#endif
#include <dbus/dbus.h>
#include <dbus/dbus-glib-lowlevel.h>

void pymc_register_classes (PyObject *d);
void pymc_add_constants(PyObject *module, const gchar *strip_prefix);

extern PyMethodDef pymc_functions[];

/* FIXME This can be automatized... */
/* #defines not scanned by h2defs and codegen */
static void add_constants(PyObject *m)
{
        //PyModule_AddStringConstant(m, "CONTACT_DND_TYPE", "x-osso-contact-list");
        return;
}

DL_EXPORT(void)
initmc (void)
{
    PyObject *m, *d;

    m = Py_InitModule("mc", pymc_functions);
    d = PyModule_GetDict(m);

    init_pygobject();

    pymc_register_classes(d);
    pymc_add_constants(m, "MC_");

    add_constants(m);

    if (PyErr_Occurred())
        Py_FatalError("could not initialize module mc");

}

/* -*- Mode: C; c-basic-offset: 4 -*-
 * python-conic- Python bindings for the ConIc library.
 *
 *   conicmodule.c: wrapper for ConIc connectivity library.
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

void pyconic_register_classes (PyObject *d);
void pyconic_add_constants(PyObject *module, const gchar *strip_prefix);

extern PyMethodDef pyconic_functions[];

static DBusConnection *connection;

/* FIXME This can be automatized... */
/* #defines not scanned by h2defs and codegen */
static void add_bearer_constants(PyObject *d)
{
        PyObject *v;

        v = PyString_FromString("WLAN_INFRA");
        PyDict_SetItemString(d, "BEARER_WLAN_INFRA", v);
        Py_DECREF(v);

        v = PyString_FromString("WLAN_ADHOC");
        PyDict_SetItemString(d, "BEARER_WLAN_ADHOC", v);
        Py_DECREF(v);

        v = PyString_FromString("DUN_GSM_CS");
        PyDict_SetItemString(d, "BEARER_DUN_GSM_CS", v);
        Py_DECREF(v); 
        
        v = PyString_FromString("DUN_GSM_PS");
        PyDict_SetItemString(d, "BEARER_DUN_GSM_PS", v);
        Py_DECREF(v); 
  
        return;
}

DL_EXPORT(void)
initconic (void)
{
    PyObject *m, *d;

    m = Py_InitModule("conic", pyconic_functions);
    d = PyModule_GetDict(m);
    
    connection = dbus_bus_get(DBUS_BUS_SYSTEM, NULL);
    dbus_connection_setup_with_g_main(connection, NULL);

    init_pygobject();
        
    pyconic_register_classes(d);
    pyconic_add_constants(m, "CON_IC_");

    add_bearer_constants(d);

}

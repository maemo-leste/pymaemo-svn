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

#include <dbus/dbus.h>
#include <dbus/dbus-glib-lowlevel.h>
#include <pygobject.h>
#include <pygtk/pygtk.h>
#include <hildon/hildon-defines.h>

void pyhildon_register_classes(PyObject *d);
extern void pyhildon_add_constants(PyObject *module, const gchar *strip_prefix);
extern PyMethodDef pyhildon_functions[];

static void
_add_keysyms(PyObject *module)
{
    PyModule_AddIntConstant(module, "KEY_LEFT", HILDON_HARDKEY_LEFT);
    PyModule_AddIntConstant(module, "KEY_UP", HILDON_HARDKEY_UP);
    PyModule_AddIntConstant(module, "KEY_RIGHT", HILDON_HARDKEY_RIGHT);
    PyModule_AddIntConstant(module, "KEY_DOWN", HILDON_HARDKEY_DOWN);

    PyModule_AddIntConstant(module, "KEY_SELECT", HILDON_HARDKEY_SELECT);
    PyModule_AddIntConstant(module, "KEY_MENU", HILDON_HARDKEY_MENU);
    PyModule_AddIntConstant(module, "KEY_HOME", HILDON_HARDKEY_HOME);
    PyModule_AddIntConstant(module, "KEY_ESC", HILDON_HARDKEY_ESC);
    PyModule_AddIntConstant(module, "KEY_FULLSCREEN", HILDON_HARDKEY_FULLSCREEN);
    PyModule_AddIntConstant(module, "KEY_INCREASE", HILDON_HARDKEY_INCREASE);
    PyModule_AddIntConstant(module, "KEY_DECREASE", HILDON_HARDKEY_DECREASE);
}

DL_EXPORT(void)
inithildon(void)
{
    PyObject *m, *d;
    static DBusConnection *connection = NULL;

    m = Py_InitModule("hildon", pyhildon_functions);
    if (m == NULL) {
        PyErr_Print();
        exit(1);
    }
    d = PyModule_GetDict(m);

    init_pygobject();
    init_pygtk();

    /* Hildon notification requires a working DBus connection to work.
     * The same happened to hildonhelp some time ago */
    if (connection == NULL) {
        connection = dbus_bus_get(DBUS_BUS_SESSION, NULL);
        dbus_connection_setup_with_g_main(connection, NULL);
    }

    pyhildon_register_classes(d);
    pyhildon_add_constants(m, "HILDON_");
    _add_keysyms(m);
}

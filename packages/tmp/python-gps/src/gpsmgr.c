/**
 * gpsmgr.c
 * Python bindings for GPS daemon manager.
 *
 * Copyright (C) 2005-2007 INdT - Instituto Nokia de Tecnologia
 *
 * Contact: Luciano Miguel Wolf <luciano.wolf@indt.org.br>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include "gps.h"

PyObject *
GpsMgr_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	GpsMgr *self;

	self = (GpsMgr *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->mgr = NULL;
	}

	return (PyObject *)self;
}


int
GpsMgr_init(GpsMgr *self, PyObject *args, PyObject *kwds)
{
	PyObject *mgr = NULL;
	GpsMgr *fullmgr = NULL;

	if (!PyArg_ParseTuple(args, "O", &mgr))
		return -1;

	fullmgr = (GpsMgr *)mgr;
	self->mgr = fullmgr->mgr;

	strcpy(((gpsmgr_t *)self->mgr)->file, "teste!");

	if (self->mgr == NULL) {
//		PyErr_SetString(OssoException, "IAP Event not initialize yet.");
		return -1;
	}

	return 0;
}

void
GpsMgr_dealloc(GpsMgr *self)
{
	PyObject *tmp;

	if (self->mgr == NULL)
		return;

	tmp = self->mgr;
	self->mgr = NULL;
	Py_XDECREF(tmp);
}

static PyObject *
GpsMgr_get_pid(GpsMgr *self, void *closure)
{
	Py_RETURN_NONE;
}

static PyObject *
GpsMgr_get_mgr_pid(GpsMgr *self, void *closure)
{
	Py_RETURN_NONE;
}

static PyObject *
GpsMgr_get_file(GpsMgr *self, void *closure)
{
	char *name;

	if (self->mgr != NULL)
		name = ((gpsmgr_t *)self->mgr)->file;
	else
		Py_RETURN_NONE;

	return PyString_FromString(name);
}

static PyObject *
GpsMgr_get_lock_file_desc(GpsMgr *self, void *closure)
{
	Py_RETURN_NONE;
}

static PyObject *
GpsMgr_get_slot(GpsMgr *self, void *closure)
{
	Py_RETURN_NONE;
}

static PyObject *
GpsMgr_get_already_locked_by_us(GpsMgr *self, void *closure)
{
	Py_RETURN_NONE;
}

static struct PyGetSetDef GpsMgr_getset[] = {
	{"pid",
		(getter)GpsMgr_get_pid, 0, NULL, 0},
	{"mgr_pid",
		(getter)GpsMgr_get_mgr_pid, 0, NULL, 0},
	{"file",
		(getter)GpsMgr_get_file, 0, NULL, 0},
	{"lock_file_desc",
		(getter)GpsMgr_get_lock_file_desc, 0, NULL, 0},
	{"locking_slot",
		(getter)GpsMgr_get_slot, 0, NULL, 0},
	{"already_locked_by_us",
		(getter)GpsMgr_get_already_locked_by_us, 0, NULL, 0},

	{0, 0, 0, 0}
};

void
add_constants(PyObject *module)
{
	PyModule_AddStringConstant(module, "GPSD_LOCK",
									GPSMGR_GPSD_LOCK);
	PyModule_AddStringConstant(module, "LOCK",
									GPSMGR_LOCK);
	PyModule_AddStringConstant(module, "LOCK2",
									GPSMGR_LOCK2);
	PyModule_AddIntConstant(module, "MODE_JUST_CHECK",
									GPSMGR_MODE_JUST_CHECK);
	PyModule_AddIntConstant(module, "MODE_LOCK_IF_POSSIBLE",
									GPSMGR_MODE_LOCK_IF_POSSIBLE);
	PyModule_AddIntConstant(module, "MAX_APPLICATIONS",
									GPSMGR_MAX_APPLICATIONS);
	return;
}

static struct PyMethodDef GpsMgr_methods[] = {
	/* Default */
	{0, 0, 0, 0}
};

static PyTypeObject GpsMgrType = {
	PyObject_HEAD_INIT(NULL)
	0,																/* ob_size */
	"gps.manager",													/* tp_name */
	sizeof(GpsMgr),													/* tp_basicsize */
	0,																/* tp_itemsize */
	(destructor)GpsMgr_dealloc,										/* tp_dealloc */
	0,																/* tp_print */
	0,																/* tp_getattr */
	0,																/* tp_setattr */
	0,																/* tp_compare */
	0,																/* tp_repr */
	0,																/* tp_as_number */
	0,																/* tp_as_sequence */
	0,																/* tp_as_mapping */
	0,																/* tp_hash */
	0,																/* tp_call */
	0,																/* tp_str */
	0,																/* tp_getattro */
	0,																/* tp_setattro */
	0,																/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE,	/* tp_flags */
	"GPS Manager class",											/* tp_doc */
	0,																/* tp_traverse */
	0,																/* tp_clear */
	0,																/* tp_richcompare */
	0,																/* tp_weaklistoffset */
	0,																/* tp_iter */
	0,																/* tp_iternext */
	GpsMgr_methods,													/* tp_methods */
	0,																/* tp_members */
	GpsMgr_getset,													/* tp_getset */
	0,																/* tp_base */
	0,																/* tp_dict */
	0,																/* tp_descr_get */
	0,																/* tp_descr_set */
	0,																/* tp_dictoffset */
	(initproc)GpsMgr_init,											/* tp_init */
	0,																/* tp_alloc */
	GpsMgr_new,														/* tp_new */
};

static struct PyMethodDef gps_manager_methods[] = {
	/* Default */
	{"start",
		(PyCFunction)Manager_start,
		METH_VARARGS | METH_KEYWORDS,
		"Adds a callback for IAP events."},
	{"stop",
		(PyCFunction)Manager_stop,
		METH_VARARGS,
		"Requests a connection. Answer is sent using the callback function."},
	{"is_gpsd_running",
		(PyCFunction)Manager_is_gpsd_running,
		METH_VARARGS | METH_KEYWORDS,
		"Requests to disconnect the device."},
	{"set_debug_mode",
		(PyCFunction)Manager_set_debug_mode,
		METH_VARARGS,
		"Requests statistics about current connection."},

    {0, 0, 0, 0}
};

PyMODINIT_FUNC
initmanager(void)
{
	PyObject *module;

	/* prepare types */
	if (PyType_Ready(&GpsMgrType) < 0) {
		return;
	}

	/* initialize module */
	module = Py_InitModule3("manager", gps_manager_methods, NULL);

	/* add types */
	Py_INCREF(&GpsMgrType);
	PyModule_AddObject(module, "GpsMgr", (PyObject *)&GpsMgrType);

	/* add constants */
	add_constants(module);

//	osso_iap_cb(_wrap_ic_callback_handler);

	/* DBus problems... */
/*    dbus_connection_setup_with_g_main(dbus_bus_get(DBUS_BUS_SYSTEM, NULL), NULL);
 *    */
}

PyObject *
Manager_start(GpsMgr *self, PyObject *args, PyObject *kwargs)
{
//	gpsmgr_t *b;
//	b = self->mgr;

//	printf("File: %s\n", PyString_AsString(self.GpsMgr_get_file()));
	Py_RETURN_NONE;
}
/*            char *path, char **gps_devices, char *ctrl_sock, 
			int debug_level, short port, gpsmgr_t *ctx);
*/

PyObject *
Manager_stop(GpsMgr *self, PyObject *args)
{
	Py_RETURN_NONE;
}
/*                gpsmgr_t *ctx);
*/

PyObject *
Manager_is_gpsd_running(GpsMgr *self, PyObject *args, PyObject *kwargs)
{
	Py_RETURN_NONE;
}
/*                gpsmgr_t *ctx, int *num_of_clients, int mode);
*/

PyObject *
Manager_set_debug_mode(GpsMgr *self, PyObject *args)
{
	Py_RETURN_NONE;
}
/*                int mode);
*/

/* vim:ts=4:noet:sw=4:sws=4:si:ai:showmatch:foldmethod=indent
 */

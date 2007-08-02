/**
 * gpsbt.c
 * Python bindings for GPS Bluetooth management.
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

#include <Python.h>
#include "gps.h"

PyObject *
GpsBt_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	GpsBt *self;

	self = (GpsBt *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->bt = NULL;
	}

	return (PyObject *)self;
}


int
GpsBt_init(GpsBt *self, PyObject *args, PyObject *kwds)
{
	PyObject *bt = NULL;
	GpsBt *fullbt = NULL;
	
	if (!PyArg_ParseTuple(args, "O", &bt))
		return -1;

	fullbt = (GpsBt *)bt;
	self->bt = fullbt->bt;
	
	if (self->bt == NULL) {
//		PyErr_SetString(OssoException, "GpsBt not initialize yet.");
		return -1;
	}

	return 0;
}


void
GpsBt_dealloc(GpsBt *self)
{
	if (self->bt == NULL)
		return;

	self->bt = NULL;
	return;
}


static struct PyMethodDef GpsBt_methods[] = {
	{0, 0, 0, 0}
};

static struct PyGetSetDef GpsBt_getset[] = {
	{"type",
		(getter)IapEvent_get_type, 0, NULL, 0},
	{"iap",
		(getter)IapEvent_get_iap_name, 0, NULL, 0},
	{"error_code",
		(getter)IapEvent_get_extra, 0, NULL, "code"},
	{"time_active",
		(getter)IapEvent_get_extra, 0, NULL, "time"},
	{"signal_strength",
		(getter)IapEvent_get_extra, 0, NULL, "signal"},
	{"rx_packets",
		(getter)IapEvent_get_extra, 0, NULL, "rx_packets"},
	{"tx_packets",
		(getter)IapEvent_get_extra, 0, NULL, "tx_packets"},
	{"rx_bytes",
		(getter)IapEvent_get_extra, 0, NULL, "rx_bytes"},
	{"tx_bytes",
		(getter)IapEvent_get_extra, 0, NULL, "tx_bytes"},

	{0, 0, 0, 0}
};

static PyTypeObject GpsBtType = {
	PyObject_HEAD_INIT(NULL)
	0,																/* ob_size */
	"gps.GpsBt",													/* tp_name */
	sizeof(GpsBt),												/* tp_basicsize */
	0,																/* tp_itemsize */
	(destructor)GpsBt_dealloc,									/* tp_dealloc */
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
	"GPS Bluetooth class",											/* tp_doc */
	0,																/* tp_traverse */
	0,																/* tp_clear */
	0,																/* tp_richcompare */
	0,																/* tp_weaklistoffset */
	0,																/* tp_iter */
	0,																/* tp_iternext */
	GpsBt_methods,												/* tp_methods */
	0,																/* tp_members */
	GpsBt_getset,																/* tp_getset */
	0,																/* tp_base */
	0,																/* tp_dict */
	0,																/* tp_descr_get */
	0,																/* tp_descr_set */
	0,																/* tp_dictoffset */
	(initproc)GpsBt_init,											/* tp_init */
	0,																/* tp_alloc */
	GpsBt_new,													/* tp_new */
};

static struct PyMethodDef bluetooth_methods[] = {
	{0, 0, 0, 0}
};

PyMODINIT_FUNC
initbluetooth(void)
{
	PyObject *module;

	/* prepare types */
	GpsBtType.tp_new = PyType_GenericNew;
	if (PyType_Ready(&GpsBtType) < 0) {
		return;
	}

	/* initialize module */
	module = Py_InitModule3("system_note", osso_methods,
			"FIXME: put documentation about SytemNote module.");

	/* add types */
	Py_INCREF(&GpsBtType);
	PyModule_AddObject(module, "Bluetooth", (PyObject *)&GpsBtType);

	/* add contants */
	/* : */
	/* : */
	/* : */
}

/*
PyObject *
GpsBt_system_note_dialog(GpsBt *self, PyObject *args, PyObject *kwds)
{
	osso_return_t ret;
	char *message = NULL;
	char *type_string = NULL;
	osso_system_note_type_t type = OSSO_GN_NOTICE;
	osso_rpc_t retval;

	static char *kwlist[] = { "message", "type", 0 };

	if (!_check_context(self->context)) return 0;

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "s|s:GpsBt.system_note_dialog",
				kwlist, &message, &type_string))
	{
		return NULL;
	}

	if (type_string) {
		if (!strcasecmp(type_string, "warning")) {
			type = OSSO_GN_WARNING;
		} else if (!strcasecmp(type_string, "error")) {
			type = OSSO_GN_ERROR;
		} else if (!strcasecmp(type_string, "wait")) {
			type = OSSO_GN_WAIT;
		}
	}
	
	ret = osso_system_note_dialog(self->context, message, type, &retval);
	if (ret != OSSO_OK) {
		_set_exception(ret, &retval);
		return NULL;
	}

	return _rpc_t_to_python(&retval);
}


PyObject *
GpsBt_system_note_infoprint(GpsBt *self, PyObject *args, PyObject *kwds)
{
	char *message = NULL;
	osso_return_t ret;
	osso_rpc_t retval;

	static char *kwlist[] = { "message", 0 };

	if (!_check_context(self->context)) return 0;

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "s:GpsBt.system_note_infoprint",
				kwlist, &message))
	{
		return NULL;
	}

	ret = osso_system_note_infoprint(self->context, message, &retval);
	if (ret != OSSO_OK) {
		_set_exception(ret, &retval);
		return NULL;
	}

	return _rpc_t_to_python(&retval);
}
*/
/* vim:ts=4:noet:sw=4:sws=4:si:ai:showmatch:foldmethod=indent
 */


/* Internal context information */
//typedef struct {
//  gpsmgr_t mgr;
//  char **rfcomms; /* what devices where found (null terminated array),
//		   * not used if compiled with USE_AUTOMATIC_DISCONNECT
//		   * (see gpsbt.c for details)
//		   */
//  int timeout; /* timeout for dbus messages */
//} gpsbt_t;

//extern int gpsbt_start(char *bda,
//		       int debug_level,
//		       int gpsd_debug_level,
//		       short port,
//		       char *error_buf,
//		       int error_buf_max_len,
//		       int timeout_ms,
//		       gpsbt_t *ctx);

//extern int gpsbt_stop(gpsbt_t *ctx);

//extern int gpsbt_set_debug_level(int level);

//extern int gpsbt_init_pairing(char *bda);


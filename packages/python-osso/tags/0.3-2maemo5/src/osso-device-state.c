/**
 * osso-device-state.c
 * Python bindings for libosso components.
 *
 * Copyright (C) 2005-2006 INdT - Instituto Nokia de Tecnologia
 *
 * Contact: Osvaldo Santana Neto <osvaldo.santana@indt.org.br>
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

#include "osso.h"

static PyObject *device_state_callback = NULL;

/* ----------------------------------------------- */
/* Devicestate type default methods                    */
/* ----------------------------------------------- */

PyObject *
DeviceState_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	Context *self;

	self = (Context *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->context = NULL;
	}

	return (PyObject *)self;
}


int
DeviceState_init(Context *self, PyObject *args, PyObject *kwds)
{
	PyObject *ossocontext = NULL;
	Context *fullcontext = NULL;
	
	if (!PyArg_ParseTuple(args, "O", &ossocontext))
		return -1;

	fullcontext = (Context *)ossocontext;
	self->context = fullcontext->context;

	if (self->context == NULL) {
		PyErr_SetString(OssoException, "Cannot initialize context.");
		return -1;
	}

	return 0;
}


PyObject *
DeviceState_close(Context *self)
{
	if (!_check_context(self->context)) return 0;
	self->context = NULL;
	Py_RETURN_NONE;
}


void
DeviceState_dealloc(Context *self)
{
	if (self->context == NULL)
		return;

	self->context = NULL;
	return;
}


static struct PyMethodDef DeviceState_methods[] = {
	/* Device state */
	{"display_state_on", (PyCFunction)Context_display_state_on, METH_VARARGS | METH_KEYWORDS,
		"c.device_state.display_state_on()\n\n"
		"Request to turn on the display as if the user had pressed a key or the\n"
		"touch screen. This can be used after completing a long operation such as\n"
		"downloading a large file or after retrieving e-mails."},
	{"display_blanking_pause", (PyCFunction)Context_display_blanking_pause, METH_VARARGS | METH_KEYWORDS,
		"c.device_state.display_blanking_pause()\n\n"
		"Request not to blank the display. This method must be called again\n"
		"within 60 seconds to renew the request. The method is used, for\n"
		"example, by the video player during video playback. Alson prevents\n"
		"suspending the device."},
	{"set_device_state_callback", (PyCFunction)Context_set_device_state_callback, METH_VARARGS | METH_KEYWORDS,
		"c.device_state.set_device_callback(callback[, user_data[, shutdown[, save_data\n"
		"    [, memory_low[, system_inactivity[, mode]]]]]]\n"
		"  )\n\n"
		"This method registers a callback function that is called whenever the\n"
		"state device changes. The first call to this method will also check\n"
		"the current state of the device, and if the state is available, the\n"
		"corresponding callback function will be called immediately. Callback\n"
		"function will receive the shutdown, save_data, memory_low,\n"
		"system_inactivity, mode and user_data parameters with state device. If\n"
		"you specify shutdown, save_data, memory_low, system_inactivity\n"
		"(booleans) or mode ('normal', 'flight', 'invalid', 'offline') the\n"
		"callback function will be called only when this state changes. Use\n"
		"None in callback parameter to unset this callback."},
	/* Default */
	{"close", (PyCFunction)DeviceState_close, METH_NOARGS, "Close device_state context."},
	{0, 0, 0, 0}
};

static PyTypeObject DeviceStateType = {
	PyObject_HEAD_INIT(NULL)
	0,																/* ob_size */
	"osso.DeviceState",												/* tp_name */
	sizeof(Context),												/* tp_basicsize */
	0,																/* tp_itemsize */
	(destructor)DeviceState_dealloc,								/* tp_dealloc */
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
	"OSSO DeviceState class",										/* tp_doc */
	0,																/* tp_traverse */
	0,																/* tp_clear */
	0,																/* tp_richcompare */
	0,																/* tp_weaklistoffset */
	0,																/* tp_iter */
	0,																/* tp_iternext */
	DeviceState_methods,											/* tp_methods */
	0,																/* tp_members */
	0,																/* tp_getset */
	0,																/* tp_base */
	0,																/* tp_dict */
	0,																/* tp_descr_get */
	0,																/* tp_descr_set */
	0,																/* tp_dictoffset */
	(initproc)DeviceState_init,										/* tp_init */
	0,																/* tp_alloc */
	DeviceState_new,												/* tp_new */
};

static struct PyMethodDef osso_methods[] = {
	{0, 0, 0, 0}
};

PyMODINIT_FUNC
initdevice_state(void)
{
	PyObject *module;

	/* prepare types */
	DeviceStateType.tp_new = PyType_GenericNew;
	if (PyType_Ready(&DeviceStateType) < 0) {
		return;
	}

	/* initialize module */
	module = Py_InitModule3("device_state", osso_methods,
			"FIXME: put documentation about DeviceState module.");

	/* add types */
	Py_INCREF(&DeviceStateType);
	PyModule_AddObject(module, "DeviceState", (PyObject *)&DeviceStateType);

	_load_exceptions();

	/* add contants */
	/* : */
	/* : */
	/* : */
}

static void
_wrap_device_state_callback_handler(osso_hw_state_t *hw_state, void *data)
{
	PyObject *py_args = NULL;
	PyGILState_STATE state;
	char *hw_state_str;

	state = PyGILState_Ensure();

	if (device_state_callback == NULL) {
		return;
	}

	switch (hw_state->sig_device_mode_ind) {
		case OSSO_DEVMODE_NORMAL:
			hw_state_str = "normal";
			break;
		case OSSO_DEVMODE_FLIGHT:
			hw_state_str = "flight";
			break;
		case OSSO_DEVMODE_OFFLINE:
			hw_state_str = "offline";
			break;
		case OSSO_DEVMODE_INVALID:
			hw_state_str = "invalid";
			break;
		default:
			hw_state_str = "";
	}

	py_args = Py_BuildValue("(bbbbsO)", 
			hw_state->shutdown_ind,
			hw_state->save_unsaved_data_ind,
			hw_state->memory_low_ind,
			hw_state->system_inactivity_ind,
			hw_state_str,
			data);

	PyEval_CallObject(device_state_callback, py_args);

	PyGILState_Release(state);
	return;
}


PyObject *
Context_set_device_state_callback(Context *self, PyObject *args, PyObject *kwds)
{
	PyObject *py_func = NULL;
	PyObject *py_data = NULL;
	char shutdown = 0;
	char save_data = 0;
	char memory_low = 0;
	char system_inactivity = 0;
	char *mode = "normal";
	osso_hw_state_t hw_state;
	osso_return_t ret;

	static char *kwlist[] = { "callback", "shutdown", "save_data",
		"memory_low", "system_inactivity", "mode", "user_data", 0 };

	if (!_check_context(self->context)) return 0;

	if (!PyArg_ParseTupleAndKeywords(args, kwds,
				"O|bbbbsO:Context.set_device_state_callback", kwlist,
				&py_func, &shutdown, &save_data, &memory_low,
				&system_inactivity, &mode, &py_data)) {
		return NULL;
	}

	if (py_func != Py_None) {
		if (!PyCallable_Check(py_func)) {
			PyErr_SetString(PyExc_TypeError, "callback parameter must be callable");
			return NULL;
		}
		Py_XINCREF(py_func);
		Py_XDECREF(device_state_callback);
		device_state_callback = py_func;
	} else {
		Py_XDECREF(device_state_callback);
		device_state_callback = NULL;
	}

	hw_state.shutdown_ind = shutdown;
	hw_state.save_unsaved_data_ind = save_data;
	hw_state.memory_low_ind = memory_low;
	hw_state.system_inactivity_ind = system_inactivity;
	
	if (!strcasecmp(mode, "normal")) {
		hw_state.sig_device_mode_ind = OSSO_DEVMODE_NORMAL;
	} else if (!strcasecmp(mode, "flight")) {
		hw_state.sig_device_mode_ind = OSSO_DEVMODE_FLIGHT;
	} else if (!strcasecmp(mode, "offline")) {
		hw_state.sig_device_mode_ind = OSSO_DEVMODE_OFFLINE;
	} else if (!strcasecmp(mode, "invalid")) {
		hw_state.sig_device_mode_ind = OSSO_DEVMODE_INVALID;
	} else {
		PyErr_SetString(OssoException, "Invalid device mode. Use 'normal',"
				"'flight', 'offline' or 'invalid' instead.");
		return NULL;
	}

	if (device_state_callback != NULL) {
		ret = osso_hw_set_event_cb(self->context, &hw_state,
				_wrap_device_state_callback_handler, py_data);
	} else {
		ret = osso_hw_unset_event_cb(self->context, &hw_state);
	}

	if (ret != OSSO_OK) {
		_set_exception(ret, NULL);
		return NULL;
	}

	Py_RETURN_NONE;
}


PyObject *
Context_display_state_on(Context *self)
{
	osso_return_t ret = OSSO_OK;

	if (!_check_context(self->context)) return 0;

	ret = osso_display_state_on(self->context);
	if (ret != OSSO_OK) {
		_set_exception(ret, NULL);
		return NULL;
	}

	Py_RETURN_NONE;
}


PyObject *
Context_display_blanking_pause(Context *self)
{
	osso_return_t ret = OSSO_OK;

	if (!_check_context(self->context)) return 0;

	ret = osso_display_blanking_pause(self->context);
	if (ret != OSSO_OK) {
		_set_exception(ret, NULL);
		return NULL;
	}

	Py_RETURN_NONE;
}

/* vim:ts=4:noet:sw=4:sws=4:si:ai:showmatch:foldmethod=indent
 */

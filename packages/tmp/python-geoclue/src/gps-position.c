/**
 * gps-position.c
 * Python bindings for libosso components.
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
#include <geoclue/position.h>

/* ----------------------------------------------- */
/* Position type default methods                */
/* ----------------------------------------------- */

PyObject *
Position_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	PyObject *self;

	self = (PyObject *)type->tp_alloc(type, 0);
/*	if (self != NULL) {
		self->context = NULL;
	}*/

	return (PyObject *)self;
}


int
Position_init(PyObject *self, PyObject *args, PyObject *kwds)
{
/*	PyObject *ossocontext = NULL;
	PyObject *fullcontext = NULL;
	
	if (!PyArg_ParseTuple(args, "O", &ossocontext))
		return -1;

	fullcontext = (PyObject *)ossocontext;
	self->context = fullcontext->context;
	
	if (self->context == NULL) {
		PyErr_SetString(OssoException, "PyObject not initialize yet.");
		return -1;
	}
*/
	return 0;
}


PyObject *
Position_close(PyObject *self)
{
/*	if (!_check_context(self->context)) return 0;
	self->context = NULL;*/
	Py_RETURN_NONE;
}


void
Position_dealloc(PyObject *self)
{
/*	if (self->context == NULL)
		return;

	self->context = NULL;*/
	return;
}


static struct PyMethodDef Position_methods[] = {
/*	{"application_top", (PyCFunction)PyObject_application_top, METH_VARARGS | METH_KEYWORDS,
		"c.application.application_top(application, arguments) -> object\n"
		"\n"
		"This method tops an application. If the application is not already\n"
		"running, D-BUS will launch it via the auto-activation mechanism."},
*/	/* Default */
	{"version", (PyCFunction)Gps_position_version, METH_VARARGS | METH_KEYWORDS,
		"(PyObject *self, PyObject *args, PyObject *kwds)"},
	{"init", (PyCFunction)Gps_position_init, METH_NOARGS,
		"(PyObject *self)"},
	{"init_specific", (PyCFunction)Gps_position_init_specific, METH_VARARGS | METH_KEYWORDS,
		"(PyObject *self, PyObject *args, PyObject *kwds)"},
	{"get_all_providers", (PyCFunction)Gps_position_get_all_providers, METH_VARARGS | METH_KEYWORDS,
		"(PyObject *self, PyObject *args, PyObject *kwds)"},
	{"close_position", (PyCFunction)Gps_position_close, METH_NOARGS,
		"(PyObject *self)"},
	{"service_provider", (PyCFunction)Gps_position_service_provider, METH_KEYWORDS,
		"(PyObject *self, PyObject *args)"},
	{"current_position", (PyCFunction)Gps_position_current_position, METH_VARARGS | METH_KEYWORDS,
		"(PyObject *self, PyObject *args, PyObject *kwds)"},
	{"set_position_callback", (PyCFunction)Gps_position_set_position_callback, METH_VARARGS | METH_KEYWORDS,
		"(PyObject *self, PyObject *args, PyObject *kwds)"},
	{"position_error", (PyCFunction)Gps_position_current_position_error, METH_VARARGS | METH_KEYWORDS,
		"(PyObject *self, PyObject *args, PyObject *kwds)"},
	{"current_altitude", (PyCFunction)Gps_position_current_altitude, METH_KEYWORDS,
		"(PyObject *self, PyObject *args)"},
	{"current_velocity", (PyCFunction)Gps_position_current_velocity, METH_VARARGS | METH_KEYWORDS,
		"(PyObject *self, PyObject *args, PyObject *kwds)"},
	{"satellites_in_view", (PyCFunction)Gps_position_satellites_in_view, METH_KEYWORDS,
		"(PyObject *self, PyObject *args)"},
	{"satellites_data", (PyCFunction)Gps_position_satellites_data, METH_VARARGS | METH_KEYWORDS,
		"(PyObject *self, PyObject *args, PyObject *kwds)"},

	{"close", (PyCFunction)Position_close, METH_NOARGS, "Close application context."},
	{0, 0, 0, 0}
};

static PyTypeObject PositionType = {
	PyObject_HEAD_INIT(NULL)
	0,																/* ob_size */
	"gps.Position",													/* tp_name */
	sizeof(PyObject),												/* tp_basicsize */
	0,																/* tp_itemsize */
	(destructor)Position_dealloc,									/* tp_dealloc */
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
	"GPS Position class",											/* tp_doc */
	0,																/* tp_traverse */
	0,																/* tp_clear */
	0,																/* tp_richcompare */
	0,																/* tp_weaklistoffset */
	0,																/* tp_iter */
	0,																/* tp_iternext */
	Position_methods,												/* tp_methods */
	0,																/* tp_members */
	0,																/* tp_getset */
	0,																/* tp_base */
	0,																/* tp_dict */
	0,																/* tp_descr_get */
	0,																/* tp_descr_set */
	0,																/* tp_dictoffset */
	(initproc)Position_init,										/* tp_init */
	0,																/* tp_alloc */
	Position_new,													/* tp_new */
};

static struct PyMethodDef gps_methods[] = {
	{0, 0, 0, 0}
};

PyMODINIT_FUNC
initposition(void)
{
	PyObject *module;

	/* prepare types */
	PositionType.tp_new = PyType_GenericNew;
	if (PyType_Ready(&PositionType) < 0) {
		return;
	}

	/* initialize module */
	module = Py_InitModule3("position", gps_methods,
			"FIXME: put documentation about Position module.");

	/* add types */
	Py_INCREF(&PositionType);
	PyModule_AddObject(module, "Position", (PyObject *)&PositionType);

//	_load_exceptions();
	/* add contants */
	/* : */
	/* : */
	/* : */
}

PyObject *
Gps_position_version(PyObject *self, PyObject *args, PyObject *kwds)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_init(PyObject *self)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_init_specific(PyObject *self, PyObject *args, PyObject *kwds)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_get_all_providers(PyObject *self, PyObject *args, PyObject *kwds)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_close(PyObject *self)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_service_provider(PyObject *self, PyObject *args)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_current_position(PyObject *self, PyObject *args, PyObject *kwds)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_set_position_callback(PyObject *self, PyObject *args, PyObject *kwds)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_current_position_error(PyObject *self, PyObject *args, PyObject *kwds)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_current_altitude(PyObject *self, PyObject *args)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_current_velocity(PyObject *self, PyObject *args, PyObject *kwds)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_satellites_in_view(PyObject *self, PyObject *args)
{
	Py_RETURN_NONE;
}

PyObject *
Gps_position_satellites_data(PyObject *self, PyObject *args, PyObject *kwds)
{
	Py_RETURN_NONE;
}

/* vim:ts=4:noet:sw=4:sws=4:si:ai:showmatch:foldmethod=indent
 */

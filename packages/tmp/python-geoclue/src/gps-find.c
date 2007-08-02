/**
 * gps-find.c
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

#include "gps.h"
#include <geoclue/find.h>

/* ----------------------------------------------- */
/* Find type default methods                */
/* ----------------------------------------------- */

PyObject *
Find_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
/*	PyObject *self;

	self = (PyObject *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->context = NULL;
	}

	return (PyObject *)self;*/
	Py_RETURN_NONE;
}


int
Find_init(PyObject *self, PyObject *args, PyObject *kwds)
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
Find_close(PyObject *self)
{
/*	if (!_check_context(self->context)) return 0;
	self->context = NULL;*/
	Py_RETURN_NONE;
}


void
Find_dealloc(PyObject *self)
{
/*	if (self->context == NULL)
		return;

	self->context = NULL;*/
	return;
}


static struct PyMethodDef Find_methods[] = {
	/* Finds */
/*	{"application_top", (PyCFunction)PyObject_application_top, METH_VARARGS | METH_KEYWORDS,
		"c.application.application_top(application, arguments) -> object\n"
		"\n"
		"This method tops an application. If the application is not already\n"
		"running, D-BUS will launch it via the auto-activation mechanism."},
*/	/* Default */
	{"close", (PyCFunction)Find_close, METH_NOARGS, "Close application context."},
	{0, 0, 0, 0}
};

static PyTypeObject FindType = {
	PyObject_HEAD_INIT(NULL)
	0,																/* ob_size */
	"gps.Find",														/* tp_name */
	sizeof(PyObject),												/* tp_basicsize */
	0,																/* tp_itemsize */
	(destructor)Find_dealloc,										/* tp_dealloc */
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
	"GPS Find class",												/* tp_doc */
	0,																/* tp_traverse */
	0,																/* tp_clear */
	0,																/* tp_richcompare */
	0,																/* tp_weaklistoffset */
	0,																/* tp_iter */
	0,																/* tp_iternext */
	Find_methods,													/* tp_methods */
	0,																/* tp_members */
	0,																/* tp_getset */
	0,																/* tp_base */
	0,																/* tp_dict */
	0,																/* tp_descr_get */
	0,																/* tp_descr_set */
	0,																/* tp_dictoffset */
	(initproc)Find_init,											/* tp_init */
	0,																/* tp_alloc */
	Find_new,														/* tp_new */
};

static struct PyMethodDef gps_methods[] = {
	{0, 0, 0, 0}
};

PyMODINIT_FUNC
initfind(void)
{
	PyObject *module;

	/* prepare types */
	FindType.tp_new = PyType_GenericNew;
	if (PyType_Ready(&FindType) < 0) {
		return;
	}

	/* initialize module */
	module = Py_InitModule3("find", gps_methods,
			"FIXME: put documentation about Find module.");

	/* add types */
	Py_INCREF(&FindType);
	PyModule_AddObject(module, "Find", (PyObject *)&FindType);

//	_load_exceptions();
	/* add contants */
	/* : */
	/* : */
	/* : */
}

PyObject *
PyObject_application_top(PyObject *self, PyObject *args, PyObject *kwds)
{
	/*osso_return_t ret;*/
	PyObject ret;
	char *application = NULL;
	char *arguments = NULL;

	static char *kwlist[] = { "application", "arguments", 0 };

//	if (!_check_context(self->context)) return 0;

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "s|z:PyObject.application_top",
				kwlist, &application, &arguments))
	{
		return NULL;
	}

	/*ret = osso_application_top(self->context, application, arguments);
	if (ret != OSSO_OK) {
		_set_exception(ret, NULL);
		return NULL;
	}
*/
	Py_RETURN_NONE;
}

PyObject *
Gps_find_version(PyObject *self, PyObject *args, PyObject *kwds)
{

}

PyObject *
Gps_find_init(PyObject *self)
{

}

PyObject *
Gps_find_init_specific(PyObject *self, PyObject *args, PyObject *kwds)
{

}

PyObject *
Gps_find_get_all_providers(PyObject *self, PyObject *args, PyObject *kwds)
{

}

PyObject *
Gps_find_close(PyObject *self)
{

}

PyObject *
Gps_find_service_provider(PyObject *self, PyObject *args)
{

}

PyObject *
Gps_find_top_level_categories(PyObject *self, PyObject *args)
{

}

PyObject *
Gps_find_subcategories(PyObject *self, PyObject *args, PyObject *kwds)
{

}

PyObject *
Gps_find_find_near(PyObject *self, PyObject *args, PyObject *kwds)
{

}

/* vim:ts=4:noet:sw=4:sws=4:si:ai:showmatch:foldmethod=indent
 */

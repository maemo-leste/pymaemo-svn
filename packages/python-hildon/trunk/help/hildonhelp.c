/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#define PY_SSIZE_T_CLEAN
#include <Python.h>




#if PY_VERSION_HEX < 0x02050000
typedef int Py_ssize_t;
#define PY_SSIZE_T_MAX INT_MAX
#define PY_SSIZE_T_MIN INT_MIN
typedef inquiry lenfunc;
typedef intargfunc ssizeargfunc;
typedef intobjargproc ssizeobjargproc;
#endif


#line 23 "help/hildonhelp.override"
#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <libintl.h>

#include <glib-object.h>

#include <hildon/hildon-help.h>

#include <python-osso/osso.h>

#line 35 "help/hildonhelp.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGtkDialog_Type;
#define PyGtkDialog_Type (*_PyGtkDialog_Type)
static PyTypeObject *_PyOssoContext_Type;
#define PyOssoContext_Type (*_PyOssoContext_Type)


/* ---------- forward type declarations ---------- */

#line 49 "help/hildonhelp.c"



/* ----------- functions ----------- */

#line 48 "help/hildonhelp.override"
static PyObject *
_wrap_hildon_help_show(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "context", "topic_id", "flags", NULL };

    PyObject *pyosso = NULL;
    osso_context_t *osso = NULL;
    osso_return_t ret;
    char *topic_id;
    int flags;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                    "Osi:hildon.help_show",
                                    kwlist,
                                    &pyosso, &topic_id, &flags))
        return NULL;

    if (pyosso != NULL) {
        if (PyObject_TypeCheck(pyosso, &PyOssoContext_Type)) {
            osso = ((Context *)pyosso)->context;
        } else if (pyosso != Py_None) {
            PyErr_SetString(PyExc_TypeError,
                            "context must be osso.Context or None");
            return NULL;
        }
    }

    ret = hildon_help_show(osso, topic_id, flags);

    Py_INCREF(Py_None);
    return Py_None;
}

#line 89 "help/hildonhelp.c"


#line 83 "help/hildonhelp.override"
static PyObject *
_wrap_hildon_help_dialog_help_enable(PyObject *self,
                                     PyObject *args,
                                     PyObject *kwargs)
{
    static char *kwlist[] = {"dialog", "topic", "context", NULL};
    gboolean ret = FALSE;

    PyGObject *pydialog;
    GtkDialog *dialog;
    PyObject *pyosso = NULL;
    osso_context_t *osso = NULL;
    char *topic;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                    "O!s|O:hildon.help_dialog_enable_help",
                                    kwlist,
                                    &PyGtkDialog_Type, &pydialog,
                                    &topic,
                                    &pyosso))
        return NULL;
    
    if (pyosso != NULL) {
        if (PyObject_TypeCheck(pyosso, &PyOssoContext_Type)) {
            osso = ((Context *)pyosso)->context;
        } else if (pyosso != Py_None) {
            PyErr_SetString(PyExc_TypeError,
                            "context must be osso.Context or None");
            return NULL;
        }
    }

    dialog = (GtkDialog *)(pydialog->obj);

    ret = hildon_help_dialog_help_enable(dialog, topic, osso);

    if (ret) {
        Py_RETURN_TRUE;
    } else {
        Py_RETURN_FALSE;
    }
}
#line 135 "help/hildonhelp.c"


const PyMethodDef pyhildonhelp_functions[] = {
    { "help_show", (PyCFunction)_wrap_hildon_help_show, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "help_dialog_help_enable", (PyCFunction)_wrap_hildon_help_dialog_help_enable, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

/* initialise stuff extension classes */
void
pyhildonhelp_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("osso")) != NULL) {
        _PyOssoContext_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Context");
        if (_PyOssoContext_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Context from osso");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import osso");
        return ;
    }
    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkDialog_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Dialog");
        if (_PyGtkDialog_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Dialog from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }


#line 190 "help/hildonhelp.c"
}

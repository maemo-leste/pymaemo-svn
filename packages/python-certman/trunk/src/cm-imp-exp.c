/*
 * Python bindings for X.509 Certificate Manager library.
 *
 * Copyright (C) 2007 INdT - Instituto Nokia de Tecnologia
 *
 * Author: Daniel d'Andrada T. de Carvalho <daniel.carvalho@indt.org.br>
 *
 * cm-imp-exp.c
 * Implementation of the import/export methods.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#import "certman.h"
#include "cm-util.h"

// Internal variables
static PyObject *confirm_callable = NULL;
static PyObject *error_callable = NULL;

// Internal function prototypes
static int _pkcs12_confirm_cb_wrapper (X509 * xcert,
                                cst_t_cert_folder * folder,
                                cst_t_cert_purpose * purpose,
                                unsigned char ** out_password,
                                int is_pair,
                                int *cancel,
                                void *data);

static int _pkcs12_error_cb_wrapper (X509 * xcert, int error, void *data);


/*
 * Wrapper for CST_import_PKCS12
 */
PyObject*
CertMan_import_PKCS12 (CertMan *self, PyObject *args, PyObject *kwds)
{
    PyObject *pyfile;
    unsigned char *password;
    PyObject *user_data;
    FILE *file;
    GError *error = NULL;

    static char *kwlist[] = {"file", "confirm_cb", "error_cb",
                             "password", "user_data", 0 };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O!OOs|O:CertMan.import_PKCS12", kwlist,
            PyFile_Type, &pyfile, &confirm_callable, &error_callable, &password, &user_data))
    {
        return NULL;
    }

    if (PyCallable_Check (confirm_callable) != 1)
    {
        PyErr_SetString (PyExc_TypeError,
            "confirm_cb parameter must be a callable object (i.e., a function or a method).");
        return NULL;
    }

    if (PyCallable_Check (error_callable) != 1)
    {
        PyErr_SetString (PyExc_TypeError,
            "error_cb parameter must be a callable object (i.e., a function or a method).");
        return NULL;
    }

    file = PyFile_AsFile (pyfile);

    // Call the wrapped function
    CST_import_PKCS12 (self->cst, file,
                       _pkcs12_confirm_cb_wrapper, _pkcs12_error_cb_wrapper,
                       password, user_data, &error);

    if (error != NULL)
    {
        PyErr_SetString (PyExc_RuntimeError, error->message);
        g_error_free (error);
        return NULL;
    }

    Py_RETURN_NONE;
}


/*
 * Wraps a Python callable to be used as a C cst_pkcs12_confirm_cb callback function.
 */
static int
_pkcs12_confirm_cb_wrapper (X509 * xcert,
                            cst_t_cert_folder * folder,
                            cst_t_cert_purpose * purpose,
                            unsigned char ** out_password,
                            int is_pair,
                            int *cancel,
                            void *data)
{
    PyObject *py_args = NULL;
    PyObject *py_ret = NULL;
    PyGILState_STATE state;

    state = PyGILState_Ensure();

    if (confirm_callable == NULL)
    {
        return FALSE;
    }

    py_args = Py_BuildValue("(ssOO)", interface, method, _rpc_args_c_to_py(arguments), data);
    py_ret = PyEval_CallObject(confirm_callable, py_args);

    if (py_ret == NULL)
    {
        retval->type = DBUS_TYPE_STRING;
        retval->value.s = "There are some exceptions in callback.";
        PyGILState_Release(state);
        return OSSO_ERROR;
    }

    _python_to_rpc_t(py_ret, retval);

    PyGILState_Release(state);
    return OSSO_OK;
}


/*
 * Wraps a Python callable to be used as a C cst_pkcs12_error_cb callback function.
 */
static int _pkcs12_error_cb_wrapper (X509 * xcert, int error, void *data)
{
}

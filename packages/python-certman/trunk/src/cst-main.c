/*
 * cst-main.c
 * Python bindings for X.509 Certificate Manager library.
 *
 * Copyright (C) 2007 INdT - Instituto Nokia de Tecnologia
 *
 * Author: Daniel d'Andrada T. de Carvalho <daniel.carvalho@indt.org.br>
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

#include "certman.h"

/* ----------------------------------------------- */
/* CertMan type default methods                    */
/* ----------------------------------------------- */

int
CertMan_init (CertMan *self, PyObject *args, PyObject *kwds)
{
    int readonly;
    unsigned char *password;
    const char *filename;

    static char *kwlist[] = { "readonly", "password", "filename", 0 };

    if (!PyArg_ParseTupleAndKeywords (args, kwds, "|iss", kwlist,
            &readonly, &password, &filename))
    {
        return -1;
    }

    if (filename == NULL)
        self->cst = CST_open (readonly, password);
    else
        self->cst = CST_open_file (filename, readonly, password);

    if (self->cst == NULL)
    {
        PyErr_SetString	(PyExc_RuntimeError, "Cannot open CST.");
        return -1;
    }

    return 0;
}


void
CertMan_dealloc(CertMan *self)
{
    if (self->cst == NULL)
        return;

    CST_free (self->cst);
    self->cst = NULL;
    return;
}


PyObject*
CertMan_backup (CertMan *self, PyObject *args, PyObject *kwds)
{
    int ret;
    const char *filename;
    unsigned char *password;

    static char *kwlist[] = { "filename", "password", 0 };

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "s|s:CertMan.backup",
                kwlist, &filename, &password))
    {
        return NULL;
    }

    ret = CST_backup(self->cst, filename, password);
    if (ret != CST_ERROR_OK)
    {
        _set_exception(ret, NULL);
        return NULL;
    }

    Py_RETURN_NONE;
}


static struct PyMethodDef CertMan_methods[] = {
    {"backup", (PyCFunction)CertMan_backup, METH_VARARGS | METH_KEYWORDS,
        "cst.backup(filename[, password]) -> object\n"
        "\n"
        "Backup local (file) storage.\n"
        "\n"
        "Parameters:\n"
        "filename      Filename for backup\n"
        "password      Password (NOT USED)"},
    {0, 0, 0, 0}
};

static PyTypeObject CertManType = {
    PyObject_HEAD_INIT(NULL)
    0,                                                              /* ob_size */
    "certman.CertMan",                                              /* tp_name */
    sizeof(CertMan),                                                /* tp_basicsize */
    0,                                                              /* tp_itemsize */
    (destructor)CertMan_dealloc,                                    /* tp_dealloc */
    0,                                                              /* tp_print */
    0,                                                              /* tp_getattr */
    0,                                                              /* tp_setattr */
    0,                                                              /* tp_compare */
    0,                                                              /* tp_repr */
    0,                                                              /* tp_as_number */
    0,                                                              /* tp_as_sequence */
    0,                                                              /* tp_as_mapping */
    0,                                                              /* tp_hash */
    0,                                                              /* tp_call */
    0,                                                              /* tp_str */
    0,                                                              /* tp_getattro */
    0,                                                              /* tp_setattro */
    0,                                                              /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "X.509 Certificate Manager class",                              /* tp_doc */
    0,                                                              /* tp_traverse */
    0,                                                              /* tp_clear */
    0,                                                              /* tp_richcompare */
    0,                                                              /* tp_weaklistoffset */
    0,                                                              /* tp_iter */
    0,                                                              /* tp_iternext */
    CertMan_methods,                                                /* tp_methods */
    0,                                                              /* tp_members */
    0,                                                              /* tp_getset */
    0,                                                              /* tp_base */
    0,                                                              /* tp_dict */
    0,                                                              /* tp_descr_get */
    0,                                                              /* tp_descr_set */
    0,                                                              /* tp_dictoffset */
    (initproc)CertMan_init,                                         /* tp_init */
    0,                                                              /* tp_alloc */
    0,                                                              /* tp_new */
};


PyMODINIT_FUNC
initcertman (void)
{
    PyObject *module;

    /* prepare types */
    CertManType.tp_new = PyType_GenericNew;
    if (PyType_Ready (&CertManType) < 0)
    {
        return;
    }

    /* initialize module */
    module = Py_InitModule3 ("certman", NULL,
        "Python bindings for X.509 Certificate Manager library.");

    /* add exceptions */
    CSTNotFoundException = PyErr_NewException("certman.NotFoundException", 0, 0);
    CSTStructureCorruptException = PyErr_NewException("certman.StructureCorruptException", 0, 0);
    CSTCreateFileException = PyErr_NewException("certman.CreateFileException", 0, 0);
    CSTCertExistException = PyErr_NewException("certman.CertExistException", 0, 0);
    CSTCRLExistException = PyErr_NewException("certman.CRLExistException", 0, 0);
    CSTStorageIsReadOnlyException = PyErr_NewException("certman.StorageIsReadOnlyException", 0, 0);
    CSTKeyNotFoundException = PyErr_NewException("certman.KeyNotFoundException", 0, 0);
    CSTCertNotFoundException = PyErr_NewException("certman.CertNotFoundException", 0, 0);
    CSTNotInitException = PyErr_NewException("certman.NotInitException", 0, 0);
    CSTParamIncorrectException = PyErr_NewException("certman.ParamIncorrectException", 0, 0);
    CSTNotOpenException = PyErr_NewException("certman.NotOpenException", 0, 0);
    CSTAssignIncorrectException = PyErr_NewException("certman.AssignIncorrectException", 0, 0);
    CSTCRLNotValidException = PyErr_NewException("certman.CRLNotValidException", 0, 0);
    CSTChainIncompleteException = PyErr_NewException("certman.ChainIncompleteException", 0, 0);
    CSTCapabilityNotFoundException = PyErr_NewException("certman.CapabilityNotFoundException", 0, 0);
    CSTIncorrectPurposeException = PyErr_NewException("certman.IncorrectPurposeException", 0, 0);
    CSTNoSpcException = PyErr_NewException("certman.NoSpcException", 0, 0);
    CSTDBStructureCorruptException = PyErr_NewException("certman.DBStructureCorruptException", 0, 0);
    CSTLockException = PyErr_NewException("certman.LockException", 0, 0);
    CSTPasswordWrongException = PyErr_NewException("certman.PasswordWrongException", 0, 0);
    CSTBadInternalFormatException = PyErr_NewException("certman.BadInternalFormatException", 0, 0);
    CSTCancelException = PyErr_NewException("certman.CancelException", 0, 0);

    Py_INCREF (CSTNotFoundException);
    Py_INCREF (CSTStructureCorruptException);
    Py_INCREF (CSTCreateFileException);
    Py_INCREF (CSTCertExistException);
    Py_INCREF (CSTCRLExistException);
    Py_INCREF (CSTStorageIsReadOnlyException);
    Py_INCREF (CSTKeyNotFoundException);
    Py_INCREF (CSTCertNotFoundException);
    Py_INCREF (CSTNotInitException);
    Py_INCREF (CSTParamIncorrectException);
    Py_INCREF (CSTNotOpenException);
    Py_INCREF (CSTAssignIncorrectException);
    Py_INCREF (CSTCRLNotValidException);
    Py_INCREF (CSTChainIncompleteException);
    Py_INCREF (CSTCapabilityNotFoundException);
    Py_INCREF (CSTIncorrectPurposeException);
    Py_INCREF (CSTNoSpcException);
    Py_INCREF (CSTDBStructureCorruptException);
    Py_INCREF (CSTLockException);
    Py_INCREF (CSTPasswordWrongException);
    Py_INCREF (CSTBadInternalFormatException);
    Py_INCREF (CSTCancelException);

    PyModule_AddObject (module, "NotFoundException", CSTNotFoundException);
    PyModule_AddObject (module, "StructureCorruptException", CSTStructureCorruptException);
    PyModule_AddObject (module, "CreateFileException", CSTCreateFileException);
    PyModule_AddObject (module, "CertExistException", CSTCertExistException);
    PyModule_AddObject (module, "CRLExistException", CSTCRLExistException);
    PyModule_AddObject (module, "StorageIsReadOnlyException", CSTStorageIsReadOnlyException);
    PyModule_AddObject (module, "KeyNotFoundException", CSTKeyNotFoundException);
    PyModule_AddObject (module, "CertNotFoundException", CSTCertNotFoundException);
    PyModule_AddObject (module, "NotInitException", CSTNotInitException);
    PyModule_AddObject (module, "ParamIncorrectException", CSTParamIncorrectException);
    PyModule_AddObject (module, "NotOpenException", CSTNotOpenException);
    PyModule_AddObject (module, "AssignIncorrectException", CSTAssignIncorrectException);
    PyModule_AddObject (module, "CRLNotValidException", CSTCRLNotValidException);
    PyModule_AddObject (module, "ChainIncompleteException", CSTChainIncompleteException);
    PyModule_AddObject (module, "CapabilityNotFoundException", CSTCapabilityNotFoundException);
    PyModule_AddObject (module, "IncorrectPurposeException", CSTIncorrectPurposeException);
    PyModule_AddObject (module, "NoSpcException", CSTNoSpcException);
    PyModule_AddObject (module, "DBStructureCorruptException", CSTDBStructureCorruptException);
    PyModule_AddObject (module, "LockException", CSTLockException);
    PyModule_AddObject (module, "PasswordWrongException", CSTPasswordWrongException);
    PyModule_AddObject (module, "BadInternalFormatException", CSTBadInternalFormatException);
    PyModule_AddObject (module, "CancelException", CSTCancelException);

    /* add types */
    Py_INCREF (&CertManType);
    PyModule_AddObject (module, "CertMan", (PyObject*) &CertManType);
}

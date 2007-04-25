/*
 * Python bindings for X.509 Certificate Manager library.
 *
 * Copyright (C) 2007 INdT - Instituto Nokia de Tecnologia
 *
 * Author: Daniel d'Andrada T. de Carvalho <daniel.carvalho@indt.org.br>
 *
 * certman.h
 * Project definitions
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

#ifndef __CERTMAN_H__
#define __CERTMAN_H__

#include <Python.h>
#include <cst.h>

/* Exceptions  */
PyObject *CSTNotFoundException;
PyObject *CSTStructureCorruptException;
PyObject *CSTCreateFileException;
PyObject *CSTCertExistException;
PyObject *CSTCRLExistException;
PyObject *CSTStorageIsReadOnlyException;
PyObject *CSTKeyNotFoundException;
PyObject *CSTCertNotFoundException;
PyObject *CSTNotInitException;
PyObject *CSTParamIncorrectException;
PyObject *CSTNotOpenException;
PyObject *CSTAssignIncorrectException;
PyObject *CSTCRLNotValidException;
PyObject *CSTChainIncompleteException;
PyObject *CSTCapabilityNotFoundException;
PyObject *CSTIncorrectPurposeException;
PyObject *CSTNoSpcException;
PyObject *CSTDBStructureCorruptException;
PyObject *CSTLockException;
PyObject *CSTPasswordWrongException;
PyObject *CSTBadInternalFormatException;
PyObject *CSTCancelException;

/* CertMan */
typedef struct {
    PyObject_HEAD
    CST* cst;
} CertMan;

/*** CertMan type main methods ***/
int CertMan_init(CertMan *self, PyObject *args, PyObject *kwds);
void CertMan_dealloc(CertMan *self);
PyObject* CertMan_backup (CertMan *self, PyObject *args, PyObject *kwds);

/*** Import/export methods ***/
PyObject* CertMan_import_PKCS12 (CertMan *self, PyObject *args, PyObject *kwds);

#endif

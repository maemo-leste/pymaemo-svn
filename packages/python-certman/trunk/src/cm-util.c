/*
 * Python bindings for X.509 Certificate Manager library.
 *
 * Copyright (C) 2007 INdT - Instituto Nokia de Tecnologia
 *
 * Author: Daniel d'Andrada T. de Carvalho <daniel.carvalho@indt.org.br>
 *
 * cm-util.c
 * Utility functions used troughout the project.
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

#include "cm-util.h"

/*
 * set exception
 */
void
certman_set_exception (void)
{
    switch (CST_last_error ())
    {
        case CST_ERROR_NOT_FOUND:
            PyErr_SetNone(CSTNotFoundException);
            break;

        case CST_ERROR_STRUCTURE_CORRUPT:
            PyErr_SetNone(CSTStructureCorruptException);
            break;

        case CST_ERROR_CREATE_FILE:
            PyErr_SetNone(CSTCreateFileException);
            break;

        case CST_ERROR_CERT_EXIST:
            PyErr_SetNone(CSTCertExistException);
            break;

        case CST_ERROR_CRL_EXIST:
            PyErr_SetNone(CSTCRLExistException);
            break;

        case CST_ERROR_STORAGE_IS_READONLY:
            PyErr_SetNone(CSTStorageIsReadOnlyException);
            break;

        case CST_ERROR_KEY_NOTFOUND:
            PyErr_SetNone(CSTKeyNotFoundException);
            break;

        case CST_ERROR_CERT_NOTFOUND:
            PyErr_SetNone(CSTCertNotFoundException);
            break;

        case CST_ERROR_NOT_IMPLEMENTED:
            PyErr_SetNone(PyExc_NotImplementedError);
            break;

        case CST_ERROR_NOT_INIT:
            PyErr_SetNone(CSTNotInitException);
            break;

        case CST_ERROR_PARAM_INCORRECT:
            PyErr_SetNone(CSTParamIncorrectException);
            break;

        case CST_ERROR_NOT_OPEN:
            PyErr_SetNone(CSTNotOpenException);
            break;

        case CST_ERROR_ASSIGN_INCORRECT:
            PyErr_SetNone(CSTAssignIncorrectException);
            break;

        case CST_ERROR_CRL_NOT_VALID:
            PyErr_SetNone(CSTCRLNotValidException);
            break;

        case CST_ERROR_CHAIN_INCOMPLETE:
            PyErr_SetNone(CSTChainIncompleteException);
            break;

        case CST_ERROR_CAPABILITY_NOTFOUND:
            PyErr_SetNone(CSTCapabilityNotFoundException);
            break;

        case CST_ERROR_INCORRECT_PURPOSE:
            PyErr_SetNone(CSTIncorrectPurposeException);
            break;

        case CST_ERROR_IO:
            PyErr_SetNone(PyExc_IOError);
            break;

        case CST_ERROR_NOSPC:
            PyErr_SetNone(CSTNoSpcException);
            break;

        case CST_ERROR_DBSTRUCTURE_CORRUPT:
            PyErr_SetNone(CSTDBStructureCorruptException);
            break;

        case CST_ERROR_LOCK:
            PyErr_SetNone(CSTLockException);
            break;

        case CST_ERROR_PASSWORD_WRONG:
            PyErr_SetNone(CSTPasswordWrongException);
            break;

        case CST_ERROR_BAD_INTERNAL_FORMAT:
            PyErr_SetNone(CSTBadInternalFormatException);
            break;

        case CST_ERROR_CANCEL:
            PyErr_SetNone(CSTCancelException);
            break;
    }
}


/*
 * cert_folder to string
 */
const char*
certman_cert_folder_to_str (const cst_t_cert_folder cert_folder)
{
    switch (cert_folder)
    {
        case CST_FOLDER_CA:
            return "certificate authority";

        case CST_FOLDER_PERSONAL:
            return "personal";

        case CST_FOLDER_OTHER:
            return "other";

        case CST_FOLDER_SITE:
            return "site";

        case CST_FOLDER_UNKNOWN:
            return "unknown";

        default:
            return NULL;
    }
}


/*
 * cert_purpose to string
 */
const char*
certman_cert_purpose_to_str (const cst_t_cert_purpose cert_purpose)
{
/*
CST_PURPOSE_NONE        0x0000
CST_PURPOSE_CA          0x0001
CST_PURPOSE_SMIME_SGN   0x0002
CST_PURPOSE_SMIME_ENC   0x0004
CST_PURPOSE_SSL_SERVER  0x0008
CST_PURPOSE_SSL_CLIENT  0x0010
CST_PURPOSE_SSL_WLAN    0x0020
CST_PURPOSE_CRL_SIGN    0x0040
CST_PURPOSE_ALL         0xFFFFFFFF
*/
}

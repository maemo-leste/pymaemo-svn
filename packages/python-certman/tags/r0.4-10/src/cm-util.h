/*
 * Python bindings for X.509 Certificate Manager library.
 *
 * Copyright (C) 2007 INdT - Instituto Nokia de Tecnologia
 *
 * Author: Daniel d'Andrada T. de Carvalho <daniel.carvalho@indt.org.br>
 *
 * cm-util.h
 * Utility Functions
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

#ifndef __CM_UTIL_H__
#define __CM_UTIL_H__

#include <Python.h>
#include <cst.h>

/*
 * Sets an exception from last error.
 */
void certman_set_exception (void);

/*
 * Returns the string representation of the given cst_t_cert_folder or
 * NULL if it's invalid.
 */
const char* certman_cert_folder_to_str (const cst_t_cert_folder cert_folder);

/*
 * Returns the string representation of the given cst_t_cert_purpose or
 * NULL if it's invalid.
 */
const char* certman_cert_purpose_to_str (const cst_t_cert_purpose cert_purpose);

#endif // __CM_UTIL_H__

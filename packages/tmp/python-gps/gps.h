/**
 * gps.h
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

#ifndef __GPS_H__
#define __GPS_H__

#include <Python.h>
#include <gpsbt.h>
#include <gpsmgr.h>

/* gpsbt.h */
PyObject *gpsbt_start(Context *self, PyObject *args, PyObject *kwds);
PyObject *gpsbt_stop(Context *self, PyObject *args, PyObject *kwds);
PyObject *gpsbt_set_debug_level(Context *self, PyObject *args, PyObject *kwds);
PyObject *gpsbt_init_pairing(Context *self, PyObject *args, PyObject *kwds);

/* gpsmgr.h */
PyObject *gpsmgr_start(Context *self, PyObject *args, PyObject *kwds);
PyObject *gpsmgr_stop(Context *self);
PyObject *gpsmgr_is_gpsd_running(Context *self, PyObject *args, PyObject *kwds);
PyObject *gpsmgr_set_debug_mode(Context *self);

#endif

/* vim:ts=4:noet:sw=4:sws=4:si:ai:showmatch:foldmethod=indent
 */

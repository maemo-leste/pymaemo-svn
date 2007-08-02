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

/* GPS Bluetooth */
typedef struct {
	PyObject_HEAD
	struct gpsbt_t *bt;
} GpsBt;

/* GPS Manager */
typedef struct {
	PyObject_HEAD
	struct gpsmgr_t *mgr;
} GpsMgr;

/* gpsbt.h */
PyObject *gps_bt_start(GpsBt *self, PyObject *args, PyObject *kwds);
PyObject *gps_bt_stop(GpsBt *self, PyObject *args, PyObject *kwds);
PyObject *gps_bt_set_debug_level(GpsBt *self, PyObject *args, PyObject *kwds);
PyObject *gps_bt_init_pairing(GpsBt *self, PyObject *args, PyObject *kwds);

/* gpsmgr.h */
PyObject *Manager_start(GpsMgr *self, PyObject *args, PyObject *kwds);
PyObject *Manager_stop(GpsMgr *self, PyObject *args);
PyObject *Manager_is_gpsd_running(GpsMgr *self, PyObject *args, PyObject *kwds);
PyObject *Manager_set_debug_mode(GpsMgr *self, PyObject *args);

#endif

/* vim:ts=4:noet:sw=4:sws=4:si:ai:showmatch:foldmethod=indent
 */

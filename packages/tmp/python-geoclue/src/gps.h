/**
 * gps.h
 * Python bindings for geoclue components.
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
#include <marshal.h>
#include <time.h>
//#include <osso-helplib.h>
//#include <pygtk/pygtk.h>

#define DBUS_API_SUBJECT_TO_CHANGE
#include <dbus/dbus.h>

/*PyObject *OssoException;
PyObject *OssoRPCException;
PyObject *OssoInvalidException;
PyObject *OssoNameException;
PyObject *OssoNoStateException;
PyObject *OssoStateSizeException;
*/
/* Default values for .._with_defaults functions */
/*#define MAX_IF_LEN 255
#define MAX_SVC_LEN 255
#define MAX_OP_LEN 255
#define OSSO_BUS_ROOT      "com.nokia"
#define OSSO_BUS_ROOT_PATH "/com/nokia"
*/
/* Helper functions */
/*char *appname_to_valid_path_component(char *application);
PyObject *_rpc_t_to_python(osso_rpc_t *arg);
void _python_to_rpc_t(PyObject *py_arg, osso_rpc_t *rpc_arg);
PyObject *_rpc_args_c_to_py(GArray *args);
void _argfill(DBusMessage *msg, void *raw_tuple);
*/
/* PyObject */
/*typedef struct {
	PyObject_HEAD
	osso_context_t *context;
} PyObject;
*/
/* IAP Events */
/*typedef struct {
	PyObject_HEAD
	struct iap_event_t *event;
} IapEvent;
*/
/* PyObject type default methods */
/*char _check_context(osso_context_t *context);
void _set_exception(osso_return_t err, osso_rpc_t *retval);
void _load_exceptions(void);

PyObject *PyObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
int PyObject_init(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *PyObject_close(PyObject *self);
void PyObject_dealloc(PyObject *self);
*/
/* Find */
PyObject *Gps_find_version(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_find_init(PyObject *self);
PyObject *Gps_find_init_specific(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_find_get_all_providers(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_find_close(PyObject *self);
PyObject *Gps_find_service_provider(PyObject *self, PyObject *args);
PyObject *Gps_find_top_level_categories(PyObject *self, PyObject *args);
PyObject *Gps_find_subcategories(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_find_find_near(PyObject *self, PyObject *args, PyObject *kwds);

/* Geocode */
PyObject *Gps_geocode_version(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_geocode_init(PyObject *self);
PyObject *Gps_geocode_close(PyObject *self);
PyObject *Gps_geocode_service_provider(PyObject *self, PyObject *args);
PyObject *Gps_geocode_to_lat_lon(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_geocode_free_text_to_lat_lon(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_geocode_lat_lon_to_address(PyObject *self, PyObject *args, PyObject *kwds);

/* Map */
PyObject *Gps_map_version(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_init(PyObject *self);
PyObject *Gps_map_init_specific(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_get_all_providers(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_close(PyObject *self);
PyObject *Gps_map_service_provider(PyObject *self, PyObject *args);
PyObject *Gps_map_max_zoom(PyObject *self, PyObject *args);
PyObject *Gps_map_min_zoom(PyObject *self, PyObject *args);
PyObject *Gps_map_max_height(PyObject *self, PyObject *args);
PyObject *Gps_map_min_height(PyObject *self, PyObject *args);
PyObject *Gps_map_max_width(PyObject *self, PyObject *args);
PyObject *Gps_map_min_width(PyObject *self, PyObject *args);
PyObject *Gps_map_get_map(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_latlong_to_offset(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_offset_to_latlong(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_find_zoom_level(PyObject *self, PyObject *args, PyObject *kwds);

/* Map_GTK */
PyObject *Gps_map_gtk_get_gdk_pixbuf(PyObject *self, PyObject *args, PyObject *kwds);

/* Map_GTK_Layout */
PyObject *Gps_map_gtk_layout_get_type(PyObject *self);
PyObject *Gps_map_gtk_layout_new(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_gtk_layout_new_corners(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_gtk_layout_zoom_in(PyObject *self, PyObject *args);
PyObject *Gps_map_gtk_layout_zoom_out(PyObject *self, PyObject *args);
PyObject *Gps_map_gtk_layout_zoom(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_gtk_layout_lat_lon(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_map_gtk_layout_add_widget(PyObject *self, PyObject *args, PyObject *kwds);

/* Position */
PyObject *Gps_position_version(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_position_init(PyObject *self);
PyObject *Gps_position_init_specific(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_position_get_all_providers(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_position_close(PyObject *self);
PyObject *Gps_position_service_provider(PyObject *self, PyObject *args);
PyObject *Gps_position_current_position(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_position_set_position_callback(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_position_current_position_error(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_position_current_altitude(PyObject *self, PyObject *args);
PyObject *Gps_position_current_velocity(PyObject *self, PyObject *args, PyObject *kwds);
PyObject *Gps_position_satellites_in_view(PyObject *self, PyObject *args);
PyObject *Gps_position_satellites_data(PyObject *self, PyObject *args, PyObject *kwds);

#endif

/* vim:ts=4:noet:sw=4:sws=4:si:ai:showmatch:foldmethod=indent
 */

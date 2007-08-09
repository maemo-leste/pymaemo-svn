'''gpsbt module
'''

'''
 * gps.pyx
 * Python bindings for libgpsbt components.
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
'''

cdef extern from 'gpsbt.h':

    ctypedef struct gpsbt_t:
        pass

    int gpsbt_start(char *bda, int debug_level, int gpsd_debug_level,
                    short port, char *error_buf, int error_buf_max_len,
                    int timeout_ms, gpsbt_t *ctx)

    int gpsbt_stop(gpsbt_t *ctx)

#############################################################
cdef class Context:
    cdef gpsbt_t _context_stored

    cdef void set_value(self, gpsbt_t *cont):
        self._context_stored = cont[0]

    cdef gpsbt_t get_value(self):
        return self._context_stored

def start(char *bda=NULL, int dbg_lvl=0, int gpsd_dbg_lvl=0, short port=0, char * error_buf=NULL,
          int error_buf_max_len=0, int timeout_ms=0):
    cdef gpsbt_t ctx_out, tmp
    cdef Context ctx_container, bla

    status = gpsbt_start(bda, dbg_lvl, gpsd_dbg_lvl, port, error_buf, error_buf_max_len,
                         timeout_ms, &ctx_out)
    ctx_container = Context()
    ctx_container.set_value(&ctx_out)

# Testing method get_value
#    if (status==0):
#        tmp = ctx_container.get_value()
#        gpsbt_stop(&tmp)

    return status, ctx_container

def stop(object ctx):
    cdef gpsbt_t ctx_in
    cdef Context ctx_container

    ctx_container = ctx
    ctx_in = ctx_container.get_value()
    status = gpsbt_stop(&ctx_in)

    return status

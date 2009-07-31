/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 23 "conic.override"
#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <libintl.h>

#include <glib-object.h>

#include "conic-types.h"

#line 21 "conic.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyConIcConnection_Type;
PyTypeObject G_GNUC_INTERNAL PyConIcConnectionEvent_Type;
PyTypeObject G_GNUC_INTERNAL PyConIcEvent_Type;
PyTypeObject G_GNUC_INTERNAL PyConIcIap_Type;
PyTypeObject G_GNUC_INTERNAL PyConIcStatisticsEvent_Type;

#line 36 "conic.c"



/* ----------- ConIcConnection ----------- */

static int
_wrap_con_ic_connection_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":conic.Connection.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create conic.Connection object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_con_ic_connection_connect(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "flags", NULL };
    PyObject *py_flags = NULL;
    int ret;
    ConIcConnectFlags flags;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:ConIcConnection.request_connection", kwlist, &py_flags))
        return NULL;
    if (pyg_flags_get_value(CON_IC_TYPE_CONNECT_FLAGS, py_flags, (gpointer)&flags))
        return NULL;
    
    ret = con_ic_connection_connect(CON_IC_CONNECTION(self->obj), flags);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_con_ic_connection_connect_by_id(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", "flags", NULL };
    char *id;
    PyObject *py_flags = NULL;
    int ret;
    ConIcConnectFlags flags;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:ConIcConnection.request_connection_by_id", kwlist, &id, &py_flags))
        return NULL;
    if (pyg_flags_get_value(CON_IC_TYPE_CONNECT_FLAGS, py_flags, (gpointer)&flags))
        return NULL;
    
    ret = con_ic_connection_connect_by_id(CON_IC_CONNECTION(self->obj), id, flags);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_con_ic_connection_disconnect(PyGObject *self)
{
    int ret;

    
    ret = con_ic_connection_disconnect(CON_IC_CONNECTION(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_con_ic_connection_disconnect_by_id(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    char *id;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:ConIcConnection.disconnect_by_id", kwlist, &id))
        return NULL;
    
    ret = con_ic_connection_disconnect_by_id(CON_IC_CONNECTION(self->obj), id);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_con_ic_connection_statistics(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    char *id;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:ConIcConnection.statistics", kwlist, &id))
        return NULL;
    
    ret = con_ic_connection_statistics(CON_IC_CONNECTION(self->obj), id);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_con_ic_connection_get_proxy_mode(PyGObject *self)
{
    gint ret;

    
    ret = con_ic_connection_get_proxy_mode(CON_IC_CONNECTION(self->obj));
    
    return pyg_enum_from_gtype(CON_IC_TYPE_PROXY_MODE, ret);
}

#line 45 "conic.override"
static PyObject *
_wrap_con_ic_connection_get_proxy_ignore_hosts (PyGObject *self)
{
    GSList *list, *head;
    PyObject *ret;
    ConIcConnection *connection;
    gint i, len;

    connection = CON_IC_CONNECTION(self->obj);
    if(connection){
        list = con_ic_connection_get_proxy_ignore_hosts(connection);
        head = list;
        len = g_slist_length(list);
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
    
    if(!list){
        Py_INCREF(Py_None);
        return Py_None;
    }

    ret = PyList_New(len);

    for(i = 0; i < len; i++){
        PyList_SetItem(ret, i, PyString_FromString(list->data));
        list = list->next;
    }

    g_slist_free(head);

    return ret;
}

#line 192 "conic.c"


static PyObject *
_wrap_con_ic_connection_get_proxy_autoconfig_url(PyGObject *self)
{
    const gchar *ret;

    
    ret = con_ic_connection_get_proxy_autoconfig_url(CON_IC_CONNECTION(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_con_ic_connection_get_proxy_host(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "protocol", NULL };
    PyObject *py_protocol = NULL;
    const gchar *ret;
    ConIcProxyProtocol protocol;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:ConIcConnection.get_proxy_host", kwlist, &py_protocol))
        return NULL;
    if (pyg_enum_get_value(CON_IC_TYPE_PROXY_PROTOCOL, py_protocol, (gpointer)&protocol))
        return NULL;
    
    ret = con_ic_connection_get_proxy_host(CON_IC_CONNECTION(self->obj), protocol);
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_con_ic_connection_get_proxy_port(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "protocol", NULL };
    PyObject *py_protocol = NULL;
    int ret;
    ConIcProxyProtocol protocol;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:ConIcConnection.get_proxy_port", kwlist, &py_protocol))
        return NULL;
    if (pyg_enum_get_value(CON_IC_TYPE_PROXY_PROTOCOL, py_protocol, (gpointer)&protocol))
        return NULL;
    
    ret = con_ic_connection_get_proxy_port(CON_IC_CONNECTION(self->obj), protocol);
    
    return PyInt_FromLong(ret);
}

#line 82 "conic.override"
static PyObject *
_wrap_con_ic_connection_get_all_iaps (PyGObject *self)
{
    GSList *list, *head;
    PyObject *ret;
    ConIcConnection *connection;
    gint i, len;

    connection = CON_IC_CONNECTION(self->obj);
    if(connection){
        list = con_ic_connection_get_all_iaps(connection);
        head = list;
        len = g_slist_length(list);
    } else {
        Py_INCREF(Py_None);
        return Py_None;
    }
    
    if(!list){
        Py_INCREF(Py_None);
        return Py_None;
    }

    ret = PyList_New(len);

    for(i = 0; i < len; i++){
        ConIcIap *iap = list->data;
        PyList_SetItem(ret, i, pygobject_new((GObject *)iap));
        list = list->next;
    }

    g_slist_free(head);

    return ret;
}
/* End of fix */
#line 285 "conic.c"


static PyObject *
_wrap_con_ic_connection_get_iap(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    char *id;
    ConIcIap *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:ConIcConnection.get_iap", kwlist, &id))
        return NULL;
    
    ret = con_ic_connection_get_iap(CON_IC_CONNECTION(self->obj), id);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyConIcConnection_methods[] = {
    { "request_connection", (PyCFunction)_wrap_con_ic_connection_connect, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "request_connection_by_id", (PyCFunction)_wrap_con_ic_connection_connect_by_id, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "disconnect", (PyCFunction)_wrap_con_ic_connection_disconnect, METH_NOARGS,
      NULL },
    { "disconnect_by_id", (PyCFunction)_wrap_con_ic_connection_disconnect_by_id, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "statistics", (PyCFunction)_wrap_con_ic_connection_statistics, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_proxy_mode", (PyCFunction)_wrap_con_ic_connection_get_proxy_mode, METH_NOARGS,
      NULL },
    { "get_proxy_ignore_hosts", (PyCFunction)_wrap_con_ic_connection_get_proxy_ignore_hosts, METH_NOARGS,
      NULL },
    { "get_proxy_autoconfig_url", (PyCFunction)_wrap_con_ic_connection_get_proxy_autoconfig_url, METH_NOARGS,
      NULL },
    { "get_proxy_host", (PyCFunction)_wrap_con_ic_connection_get_proxy_host, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_proxy_port", (PyCFunction)_wrap_con_ic_connection_get_proxy_port, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_all_iaps", (PyCFunction)_wrap_con_ic_connection_get_all_iaps, METH_NOARGS,
      NULL },
    { "get_iap", (PyCFunction)_wrap_con_ic_connection_get_iap, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyConIcConnection_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "conic.Connection",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyConIcConnection_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_con_ic_connection_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- ConIcEvent ----------- */

static PyObject *
_wrap_con_ic_event_get_iap_id(PyGObject *self)
{
    const gchar *ret;

    
    ret = con_ic_event_get_iap_id(CON_IC_EVENT(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_con_ic_event_get_bearer_type(PyGObject *self)
{
    const gchar *ret;

    
    ret = con_ic_event_get_bearer_type(CON_IC_EVENT(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyConIcEvent_methods[] = {
    { "get_iap_id", (PyCFunction)_wrap_con_ic_event_get_iap_id, METH_NOARGS,
      NULL },
    { "get_bearer_type", (PyCFunction)_wrap_con_ic_event_get_bearer_type, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyConIcEvent_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "conic.Event",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyConIcEvent_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- ConIcConnectionEvent ----------- */

static PyObject *
_wrap_con_ic_connection_event_get_status(PyGObject *self)
{
    gint ret;

    
    ret = con_ic_connection_event_get_status(CON_IC_CONNECTION_EVENT(self->obj));
    
    return pyg_enum_from_gtype(CON_IC_TYPE_CONNECTION_STATUS, ret);
}

static PyObject *
_wrap_con_ic_connection_event_get_error(PyGObject *self)
{
    gint ret;

    
    ret = con_ic_connection_event_get_error(CON_IC_CONNECTION_EVENT(self->obj));
    
    return pyg_enum_from_gtype(CON_IC_TYPE_CONNECTION_ERROR, ret);
}

static const PyMethodDef _PyConIcConnectionEvent_methods[] = {
    { "get_status", (PyCFunction)_wrap_con_ic_connection_event_get_status, METH_NOARGS,
      NULL },
    { "get_error", (PyCFunction)_wrap_con_ic_connection_event_get_error, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyConIcConnectionEvent_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "conic.ConnectionEvent",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyConIcConnectionEvent_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- ConIcIap ----------- */

static PyObject *
_wrap_con_ic_iap_get_name(PyGObject *self)
{
    const gchar *ret;

    
    ret = con_ic_iap_get_name(CON_IC_IAP(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_con_ic_iap_get_id(PyGObject *self)
{
    const gchar *ret;

    
    ret = con_ic_iap_get_id(CON_IC_IAP(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_con_ic_iap_get_bearer_type(PyGObject *self)
{
    const gchar *ret;

    
    ret = con_ic_iap_get_bearer_type(CON_IC_IAP(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyConIcIap_methods[] = {
    { "get_name", (PyCFunction)_wrap_con_ic_iap_get_name, METH_NOARGS,
      NULL },
    { "get_id", (PyCFunction)_wrap_con_ic_iap_get_id, METH_NOARGS,
      NULL },
    { "get_bearer_type", (PyCFunction)_wrap_con_ic_iap_get_bearer_type, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyConIcIap_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "conic.Iap",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyConIcIap_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- ConIcStatisticsEvent ----------- */

static PyObject *
_wrap_con_ic_statistics_event_get_time_active(PyGObject *self)
{
    guint ret;

    
    ret = con_ic_statistics_event_get_time_active(CON_IC_STATISTICS_EVENT(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static PyObject *
_wrap_con_ic_statistics_event_get_signal_strength(PyGObject *self)
{
    guint ret;

    
    ret = con_ic_statistics_event_get_signal_strength(CON_IC_STATISTICS_EVENT(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static PyObject *
_wrap_con_ic_statistics_event_get_rx_packets(PyGObject *self)
{
    guint64 ret;

    
    ret = con_ic_statistics_event_get_rx_packets(CON_IC_STATISTICS_EVENT(self->obj));
    
    return PyLong_FromUnsignedLongLong(ret);
}

static PyObject *
_wrap_con_ic_statistics_event_get_tx_packets(PyGObject *self)
{
    guint64 ret;

    
    ret = con_ic_statistics_event_get_tx_packets(CON_IC_STATISTICS_EVENT(self->obj));
    
    return PyLong_FromUnsignedLongLong(ret);
}

static PyObject *
_wrap_con_ic_statistics_event_get_rx_bytes(PyGObject *self)
{
    guint64 ret;

    
    ret = con_ic_statistics_event_get_rx_bytes(CON_IC_STATISTICS_EVENT(self->obj));
    
    return PyLong_FromUnsignedLongLong(ret);
}

static PyObject *
_wrap_con_ic_statistics_event_get_tx_bytes(PyGObject *self)
{
    guint64 ret;

    
    ret = con_ic_statistics_event_get_tx_bytes(CON_IC_STATISTICS_EVENT(self->obj));
    
    return PyLong_FromUnsignedLongLong(ret);
}

static const PyMethodDef _PyConIcStatisticsEvent_methods[] = {
    { "get_time_active", (PyCFunction)_wrap_con_ic_statistics_event_get_time_active, METH_NOARGS,
      NULL },
    { "get_signal_strength", (PyCFunction)_wrap_con_ic_statistics_event_get_signal_strength, METH_NOARGS,
      NULL },
    { "get_rx_packets", (PyCFunction)_wrap_con_ic_statistics_event_get_rx_packets, METH_NOARGS,
      NULL },
    { "get_tx_packets", (PyCFunction)_wrap_con_ic_statistics_event_get_tx_packets, METH_NOARGS,
      NULL },
    { "get_rx_bytes", (PyCFunction)_wrap_con_ic_statistics_event_get_rx_bytes, METH_NOARGS,
      NULL },
    { "get_tx_bytes", (PyCFunction)_wrap_con_ic_statistics_event_get_tx_bytes, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyConIcStatisticsEvent_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "conic.StatisticsEvent",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyConIcStatisticsEvent_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

const PyMethodDef pyconic_functions[] = {
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
pyconic_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_flags_add(module, "IcConnectFlags", strip_prefix, CON_IC_TYPE_CONNECT_FLAGS);
  pyg_enum_add(module, "IcProxyMode", strip_prefix, CON_IC_TYPE_PROXY_MODE);
  pyg_enum_add(module, "IcProxyProtocol", strip_prefix, CON_IC_TYPE_PROXY_PROTOCOL);
  pyg_enum_add(module, "IcConnectionStatus", strip_prefix, CON_IC_TYPE_CONNECTION_STATUS);
  pyg_enum_add(module, "IcConnectionError", strip_prefix, CON_IC_TYPE_CONNECTION_ERROR);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
pyconic_register_classes(PyObject *d)
{
    PyObject *module;

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


#line 820 "conic.c"
    pygobject_register_class(d, "ConIcConnection", CON_IC_TYPE_CONNECTION, &PyConIcConnection_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(CON_IC_TYPE_CONNECTION);
    pygobject_register_class(d, "ConIcEvent", CON_IC_TYPE_EVENT, &PyConIcEvent_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(CON_IC_TYPE_EVENT);
    pygobject_register_class(d, "ConIcConnectionEvent", CON_IC_TYPE_CONNECTION_EVENT, &PyConIcConnectionEvent_Type, Py_BuildValue("(O)", &PyConIcEvent_Type));
    pyg_set_object_has_new_constructor(CON_IC_TYPE_CONNECTION_EVENT);
    pygobject_register_class(d, "ConIcIap", CON_IC_TYPE_IAP, &PyConIcIap_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(CON_IC_TYPE_IAP);
    pygobject_register_class(d, "ConIcStatisticsEvent", CON_IC_TYPE_STATISTICS_EVENT, &PyConIcStatisticsEvent_Type, Py_BuildValue("(O)", &PyConIcEvent_Type));
    pyg_set_object_has_new_constructor(CON_IC_TYPE_STATISTICS_EVENT);
}

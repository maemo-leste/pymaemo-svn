/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 23 "mafw.override"
#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>

#include "mafw-includes.h"
#include "mafw-types.h"

#line 15 "mafw.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGInitiallyUnowned_Type;
#define PyGInitiallyUnowned_Type (*_PyGInitiallyUnowned_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyMafwExtension_Type;
PyTypeObject G_GNUC_INTERNAL PyMafwProxyPlaylist_Type;
PyTypeObject G_GNUC_INTERNAL PyMafwRegistry_Type;
PyTypeObject G_GNUC_INTERNAL PyMafwRenderer_Type;
PyTypeObject G_GNUC_INTERNAL PyMafwSource_Type;

#line 32 "mafw.c"



/* ----------- MafwExtension ----------- */

PyTypeObject G_GNUC_INTERNAL PyMafwExtension_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "mafw.Extension",                   /* tp_name */
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
    (struct PyMethodDef*)NULL, /* tp_methods */
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



/* ----------- MafwProxyPlaylist ----------- */

static int
_wrap_mafw_proxy_playlist_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    PyObject *py_id = NULL;
    guint id = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:MafwProxyPlaylist.__init__", kwlist, &py_id))
        return -1;
    if (py_id) {
        if (PyLong_Check(py_id))
            id = PyLong_AsUnsignedLong(py_id);
        else if (PyInt_Check(py_id))
            id = PyInt_AsLong(py_id);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'id' must be an int or a long");
        if (PyErr_Occurred())
            return -1;
    }
    self->obj = (GObject *)mafw_proxy_playlist_new(id);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create MafwProxyPlaylist object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_mafw_proxy_playlist_get_id(PyGObject *self)
{
    guint ret;

    
    ret = mafw_proxy_playlist_get_id(MAFW_PROXY_PLAYLIST(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static const PyMethodDef _PyMafwProxyPlaylist_methods[] = {
    { "get_id", (PyCFunction)_wrap_mafw_proxy_playlist_get_id, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyMafwProxyPlaylist_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "mafw.ProxyPlaylist",                   /* tp_name */
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
    (struct PyMethodDef*)_PyMafwProxyPlaylist_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_mafw_proxy_playlist_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- MafwRegistry ----------- */

PyTypeObject G_GNUC_INTERNAL PyMafwRegistry_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "mafw.Registry",                   /* tp_name */
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
    (struct PyMethodDef*)NULL, /* tp_methods */
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



/* ----------- MafwRenderer ----------- */

static PyObject *
_wrap_mafw_renderer_emit_buffering_info(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "fraction", NULL };
    double fraction;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"d:MafwRenderer.emit_buffering_info", kwlist, &fraction))
        return NULL;
    
    mafw_renderer_emit_buffering_info(MAFW_RENDERER(self->obj), fraction);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyMafwRenderer_methods[] = {
    { "emit_buffering_info", (PyCFunction)_wrap_mafw_renderer_emit_buffering_info, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyMafwRenderer_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "mafw.Renderer",                   /* tp_name */
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
    (struct PyMethodDef*)_PyMafwRenderer_methods, /* tp_methods */
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



/* ----------- MafwSource ----------- */

PyTypeObject G_GNUC_INTERNAL PyMafwSource_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "mafw.Source",                   /* tp_name */
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
    (struct PyMethodDef*)NULL, /* tp_methods */
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

static PyObject *
_wrap_mafw_playlist_get_type(PyObject *self)
{
    GType ret;

    
    ret = mafw_playlist_get_type();
    
    return pyg_type_wrapper_new(ret);
}

static PyObject *
_wrap_mafw_proxy_playlist_get_type(PyObject *self)
{
    GType ret;

    
    ret = mafw_proxy_playlist_get_type();
    
    return pyg_type_wrapper_new(ret);
}

static PyObject *
_wrap_mafw_registry_get_type(PyObject *self)
{
    GType ret;

    
    ret = mafw_registry_get_type();
    
    return pyg_type_wrapper_new(ret);
}

static PyObject *
_wrap_mafw_registry_get_instance(PyObject *self)
{
    MafwRegistry *ret;

    
    ret = mafw_registry_get_instance();
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_mafw_renderer_get_type(PyObject *self)
{
    GType ret;

    
    ret = mafw_renderer_get_type();
    
    return pyg_type_wrapper_new(ret);
}

const PyMethodDef pymafw_functions[] = {
    { "mafw_playlist_get_type", (PyCFunction)_wrap_mafw_playlist_get_type, METH_NOARGS,
      NULL },
    { "mafw_proxy_playlist_get_type", (PyCFunction)_wrap_mafw_proxy_playlist_get_type, METH_NOARGS,
      NULL },
    { "mafw_registry_get_type", (PyCFunction)_wrap_mafw_registry_get_type, METH_NOARGS,
      NULL },
    { "mafw_registry_get_instance", (PyCFunction)_wrap_mafw_registry_get_instance, METH_NOARGS,
      NULL },
    { "mafw_renderer_get_type", (PyCFunction)_wrap_mafw_renderer_get_type, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
pymafw_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_enum_add(module, "Error", strip_prefix, MAFW_TYPE_ERROR);
  pyg_enum_add(module, "ExtensionError", strip_prefix, MAFW_TYPE_EXTENSION_ERROR);
  pyg_enum_add(module, "PlaylistError", strip_prefix, MAFW_TYPE_PLAYLIST_ERROR);
  pyg_enum_add(module, "RendererError", strip_prefix, MAFW_TYPE_RENDERER_ERROR);
  pyg_enum_add(module, "SourceError", strip_prefix, MAFW_TYPE_SOURCE_ERROR);
  pyg_enum_add(module, "FilterType", strip_prefix, MAFW_TYPE_FILTER_TYPE);
  pyg_enum_add(module, "RendererSeekMode", strip_prefix, MAFW_TYPE_RENDERER_SEEK_MODE);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
pymafw_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
        _PyGInitiallyUnowned_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGInitiallyUnowned_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }


#line 467 "mafw.c"
    pygobject_register_class(d, "MafwExtension", MAFW_TYPE_EXTENSION, &PyMafwExtension_Type, Py_BuildValue("(O)", &PyGInitiallyUnowned_Type));
    pygobject_register_class(d, "MafwProxyPlaylist", MAFW_TYPE_PROXY_PLAYLIST, &PyMafwProxyPlaylist_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pygobject_register_class(d, "MafwRegistry", MAFW_TYPE_REGISTRY, &PyMafwRegistry_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(MAFW_TYPE_REGISTRY);
    pygobject_register_class(d, "MafwRenderer", MAFW_TYPE_RENDERER, &PyMafwRenderer_Type, Py_BuildValue("(O)", &PyMafwExtension_Type));
    pygobject_register_class(d, "MafwSource", MAFW_TYPE_SOURCE, &PyMafwSource_Type, Py_BuildValue("(O)", &PyMafwExtension_Type));
}

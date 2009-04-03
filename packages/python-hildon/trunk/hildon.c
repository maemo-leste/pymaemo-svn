/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#define PY_SSIZE_T_CLEAN
#include <Python.h>




#if PY_VERSION_HEX < 0x02050000
typedef int Py_ssize_t;
#define PY_SSIZE_T_MAX INT_MAX
#define PY_SSIZE_T_MIN INT_MIN
typedef inquiry lenfunc;
typedef intargfunc ssizeargfunc;
typedef intobjargproc ssizeobjargproc;
#endif


#line 23 "hildon.override"
#define NO_IMPORT_PYGOBJECT
#include <pygobject.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <libintl.h>

#include <glib-object.h>

#include "hildon-extra.h"

#line 33 "hildon.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGtkAdjustment_Type;
#define PyGtkAdjustment_Type (*_PyGtkAdjustment_Type)
static PyTypeObject *_PyGtkBin_Type;
#define PyGtkBin_Type (*_PyGtkBin_Type)
static PyTypeObject *_PyGtkButton_Type;
#define PyGtkButton_Type (*_PyGtkButton_Type)
static PyTypeObject *_PyGtkContainer_Type;
#define PyGtkContainer_Type (*_PyGtkContainer_Type)
static PyTypeObject *_PyGtkDialog_Type;
#define PyGtkDialog_Type (*_PyGtkDialog_Type)
static PyTypeObject *_PyGtkEventBox_Type;
#define PyGtkEventBox_Type (*_PyGtkEventBox_Type)
static PyTypeObject *_PyGtkFileFilter_Type;
#define PyGtkFileFilter_Type (*_PyGtkFileFilter_Type)
static PyTypeObject *_PyGtkListStore_Type;
#define PyGtkListStore_Type (*_PyGtkListStore_Type)
static PyTypeObject *_PyGtkMenu_Type;
#define PyGtkMenu_Type (*_PyGtkMenu_Type)
static PyTypeObject *_PyGtkNotebook_Type;
#define PyGtkNotebook_Type (*_PyGtkNotebook_Type)
static PyTypeObject *_PyGtkProgressBar_Type;
#define PyGtkProgressBar_Type (*_PyGtkProgressBar_Type)
static PyTypeObject *_PyGtkScale_Type;
#define PyGtkScale_Type (*_PyGtkScale_Type)
static PyTypeObject *_PyGtkSizeGroup_Type;
#define PyGtkSizeGroup_Type (*_PyGtkSizeGroup_Type)
static PyTypeObject *_PyGtkTextBuffer_Type;
#define PyGtkTextBuffer_Type (*_PyGtkTextBuffer_Type)
static PyTypeObject *_PyGtkToolbar_Type;
#define PyGtkToolbar_Type (*_PyGtkToolbar_Type)
static PyTypeObject *_PyGtkUIManager_Type;
#define PyGtkUIManager_Type (*_PyGtkUIManager_Type)
static PyTypeObject *_PyGtkWindow_Type;
#define PyGtkWindow_Type (*_PyGtkWindow_Type)
static PyTypeObject *_PyGtkWidget_Type;
#define PyGtkWidget_Type (*_PyGtkWidget_Type)
static PyTypeObject *_PyGtkScrolledWindow_Type;
#define PyGtkScrolledWindow_Type (*_PyGtkScrolledWindow_Type)
static PyTypeObject *_PyGtkLabel_Type;
#define PyGtkLabel_Type (*_PyGtkLabel_Type)
static PyTypeObject *_PyPangoFontDescription_Type;
#define PyPangoFontDescription_Type (*_PyPangoFontDescription_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyHildonBanner_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonBreadCrumbTrail_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonBreadCrumb_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonCalendarPopup_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonCalendar_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonCaption_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonCodeDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonColorButton_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonColorChooserDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonColorChooser_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonControlbar_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonDateEditor_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonFindToolbar_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonFontSelectionDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonGetPasswordDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonHVolumebar_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonLoginDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonNote_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonNumberEditor_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonProgram_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonRangeEditor_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonSeekbar_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonSetPasswordDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonSortDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonTimeEditor_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonTimePicker_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonVolumebarRange_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonVolumebar_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonVVolumebar_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonWeekdayPicker_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonWindow_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonWizardDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonFileChooserDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonFileDetailsDialog_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonFileSelection_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonFileSystemModel_Type;
PyTypeObject G_GNUC_INTERNAL PyHildonFileSystemStorageDialog_Type;

#line 122 "hildon.c"



/* ----------- HildonBanner ----------- */

static PyObject *
_wrap_hildon_banner_set_text(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "text", NULL };
    char *text;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonBanner.set_text", kwlist, &text))
        return NULL;
    
    hildon_banner_set_text(HILDON_BANNER(self->obj), text);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_banner_set_markup(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "markup", NULL };
    char *markup;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonBanner.set_markup", kwlist, &markup))
        return NULL;
    
    hildon_banner_set_markup(HILDON_BANNER(self->obj), markup);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_banner_set_fraction(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "fraction", NULL };
    double fraction;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"d:HildonBanner.set_fraction", kwlist, &fraction))
        return NULL;
    
    hildon_banner_set_fraction(HILDON_BANNER(self->obj), fraction);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_banner_set_icon(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "icon_name", NULL };
    char *icon_name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonBanner.set_icon", kwlist, &icon_name))
        return NULL;
    
    hildon_banner_set_icon(HILDON_BANNER(self->obj), icon_name);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_banner_set_icon_from_file(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "icon_file", NULL };
    char *icon_file;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonBanner.set_icon_from_file", kwlist, &icon_file))
        return NULL;
    
    hildon_banner_set_icon_from_file(HILDON_BANNER(self->obj), icon_file);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_banner_set_timeout(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "timeout", NULL };
    PyObject *py_timeout = NULL;
    guint timeout = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonBanner.set_timeout", kwlist, &py_timeout))
        return NULL;
    if (py_timeout) {
        if (PyLong_Check(py_timeout))
            timeout = PyLong_AsUnsignedLong(py_timeout);
        else if (PyInt_Check(py_timeout))
            timeout = PyInt_AsLong(py_timeout);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'timeout' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_banner_set_timeout(HILDON_BANNER(self->obj), timeout);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonBanner_methods[] = {
    { "set_text", (PyCFunction)_wrap_hildon_banner_set_text, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_markup", (PyCFunction)_wrap_hildon_banner_set_markup, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_fraction", (PyCFunction)_wrap_hildon_banner_set_fraction, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_icon", (PyCFunction)_wrap_hildon_banner_set_icon, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_icon_from_file", (PyCFunction)_wrap_hildon_banner_set_icon_from_file, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_timeout", (PyCFunction)_wrap_hildon_banner_set_timeout, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonBanner_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Banner",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonBanner_methods, /* tp_methods */
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



/* ----------- HildonBreadCrumbTrail ----------- */

static int
_wrap_hildon_bread_crumb_trail_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.BreadCrumbTrail.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.BreadCrumbTrail object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_bread_crumb_trail_pop(PyGObject *self)
{
    
    hildon_bread_crumb_trail_pop(HILDON_BREAD_CRUMB_TRAIL(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_bread_crumb_trail_clear(PyGObject *self)
{
    
    hildon_bread_crumb_trail_clear(HILDON_BREAD_CRUMB_TRAIL(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonBreadCrumbTrail_methods[] = {
    { "pop", (PyCFunction)_wrap_hildon_bread_crumb_trail_pop, METH_NOARGS,
      NULL },
    { "clear", (PyCFunction)_wrap_hildon_bread_crumb_trail_clear, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonBreadCrumbTrail_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.BreadCrumbTrail",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonBreadCrumbTrail_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_bread_crumb_trail_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonBreadCrumb ----------- */

static PyObject *
_wrap_hildon_bread_crumb_activated(PyGObject *self)
{
    
    hildon_bread_crumb_activated(HILDON_BREAD_CRUMB(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonBreadCrumb_methods[] = {
    { "activated", (PyCFunction)_wrap_hildon_bread_crumb_activated, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonBreadCrumb_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.BreadCrumb",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonBreadCrumb_methods, /* tp_methods */
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



/* ----------- HildonCalendarPopup ----------- */

static int
_wrap_hildon_calendar_popup_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "year", "month", "day", NULL };
    PyGObject *parent;
    PyObject *py_year = NULL, *py_month = NULL, *py_day = NULL;
    guint year = 0, month = 0, day = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!OOO:HildonCalendarPopup.__init__", kwlist, &PyGtkWindow_Type, &parent, &py_year, &py_month, &py_day))
        return -1;
    if (py_year) {
        if (PyLong_Check(py_year))
            year = PyLong_AsUnsignedLong(py_year);
        else if (PyInt_Check(py_year))
            year = PyInt_AsLong(py_year);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'year' must be an int or a long");
        if (PyErr_Occurred())
            return -1;
    }
    if (py_month) {
        if (PyLong_Check(py_month))
            month = PyLong_AsUnsignedLong(py_month);
        else if (PyInt_Check(py_month))
            month = PyInt_AsLong(py_month);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'month' must be an int or a long");
        if (PyErr_Occurred())
            return -1;
    }
    if (py_day) {
        if (PyLong_Check(py_day))
            day = PyLong_AsUnsignedLong(py_day);
        else if (PyInt_Check(py_day))
            day = PyInt_AsLong(py_day);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'day' must be an int or a long");
        if (PyErr_Occurred())
            return -1;
    }
    self->obj = (GObject *)hildon_calendar_popup_new(GTK_WINDOW(parent->obj), year, month, day);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonCalendarPopup object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_calendar_popup_set_date(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "year", "month", "day", NULL };
    PyObject *py_year = NULL, *py_month = NULL, *py_day = NULL;
    guint year = 0, month = 0, day = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOO:HildonCalendarPopup.set_date", kwlist, &py_year, &py_month, &py_day))
        return NULL;
    if (py_year) {
        if (PyLong_Check(py_year))
            year = PyLong_AsUnsignedLong(py_year);
        else if (PyInt_Check(py_year))
            year = PyInt_AsLong(py_year);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'year' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_month) {
        if (PyLong_Check(py_month))
            month = PyLong_AsUnsignedLong(py_month);
        else if (PyInt_Check(py_month))
            month = PyInt_AsLong(py_month);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'month' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_day) {
        if (PyLong_Check(py_day))
            day = PyLong_AsUnsignedLong(py_day);
        else if (PyInt_Check(py_day))
            day = PyInt_AsLong(py_day);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'day' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_calendar_popup_set_date(HILDON_CALENDAR_POPUP(self->obj), year, month, day);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 66 "hildon.override"
static PyObject *
_wrap_hildon_calendar_popup_get_date (PyGObject *self)
{
   int year, month, day;

   hildon_calendar_popup_get_date(HILDON_CALENDAR_POPUP(self->obj), &year, &month, &day);

   return Py_BuildValue("(iii)", year, month, day);
}

#line 563 "hildon.c"


static const PyMethodDef _PyHildonCalendarPopup_methods[] = {
    { "set_date", (PyCFunction)_wrap_hildon_calendar_popup_set_date, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_date", (PyCFunction)_wrap_hildon_calendar_popup_get_date, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonCalendarPopup_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.CalendarPopup",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonCalendarPopup_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_calendar_popup_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonCalendar ----------- */

static int
_wrap_hildon_calendar_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.Calendar.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.Calendar object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_calendar_select_month(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "month", "year", NULL };
    PyObject *py_month = NULL, *py_year = NULL;
    int ret;
    guint month = 0, year = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:HildonCalendar.select_month", kwlist, &py_month, &py_year))
        return NULL;
    if (py_month) {
        if (PyLong_Check(py_month))
            month = PyLong_AsUnsignedLong(py_month);
        else if (PyInt_Check(py_month))
            month = PyInt_AsLong(py_month);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'month' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_year) {
        if (PyLong_Check(py_year))
            year = PyLong_AsUnsignedLong(py_year);
        else if (PyInt_Check(py_year))
            year = PyInt_AsLong(py_year);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'year' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = hildon_calendar_select_month(HILDON_CALENDAR(self->obj), month, year);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_calendar_select_day(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "day", NULL };
    PyObject *py_day = NULL;
    guint day = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonCalendar.select_day", kwlist, &py_day))
        return NULL;
    if (py_day) {
        if (PyLong_Check(py_day))
            day = PyLong_AsUnsignedLong(py_day);
        else if (PyInt_Check(py_day))
            day = PyInt_AsLong(py_day);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'day' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_calendar_select_day(HILDON_CALENDAR(self->obj), day);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_calendar_mark_day(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "day", NULL };
    PyObject *py_day = NULL;
    int ret;
    guint day = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonCalendar.mark_day", kwlist, &py_day))
        return NULL;
    if (py_day) {
        if (PyLong_Check(py_day))
            day = PyLong_AsUnsignedLong(py_day);
        else if (PyInt_Check(py_day))
            day = PyInt_AsLong(py_day);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'day' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = hildon_calendar_mark_day(HILDON_CALENDAR(self->obj), day);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_calendar_unmark_day(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "day", NULL };
    PyObject *py_day = NULL;
    int ret;
    guint day = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonCalendar.unmark_day", kwlist, &py_day))
        return NULL;
    if (py_day) {
        if (PyLong_Check(py_day))
            day = PyLong_AsUnsignedLong(py_day);
        else if (PyInt_Check(py_day))
            day = PyInt_AsLong(py_day);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'day' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = hildon_calendar_unmark_day(HILDON_CALENDAR(self->obj), day);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_calendar_clear_marks(PyGObject *self)
{
    
    hildon_calendar_clear_marks(HILDON_CALENDAR(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_calendar_set_display_options(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "flags", NULL };
    PyObject *py_flags = NULL;
    HildonCalendarDisplayOptions flags;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonCalendar.set_display_options", kwlist, &py_flags))
        return NULL;
    if (pyg_flags_get_value(HILDON_TYPE_CALENDAR_DISPLAY_OPTIONS, py_flags, (gpointer)&flags))
        return NULL;
    
    hildon_calendar_set_display_options(HILDON_CALENDAR(self->obj), flags);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_calendar_get_display_options(PyGObject *self)
{
    guint ret;

    
    ret = hildon_calendar_get_display_options(HILDON_CALENDAR(self->obj));
    
    return pyg_flags_from_gtype(HILDON_TYPE_CALENDAR_DISPLAY_OPTIONS, ret);
}

static PyObject *
_wrap_hildon_calendar_freeze(PyGObject *self)
{
    
    hildon_calendar_freeze(HILDON_CALENDAR(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_calendar_thaw(PyGObject *self)
{
    
    hildon_calendar_thaw(HILDON_CALENDAR(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonCalendar_methods[] = {
    { "select_month", (PyCFunction)_wrap_hildon_calendar_select_month, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "select_day", (PyCFunction)_wrap_hildon_calendar_select_day, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "mark_day", (PyCFunction)_wrap_hildon_calendar_mark_day, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unmark_day", (PyCFunction)_wrap_hildon_calendar_unmark_day, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "clear_marks", (PyCFunction)_wrap_hildon_calendar_clear_marks, METH_NOARGS,
      NULL },
    { "set_display_options", (PyCFunction)_wrap_hildon_calendar_set_display_options, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_display_options", (PyCFunction)_wrap_hildon_calendar_get_display_options, METH_NOARGS,
      NULL },
    { "freeze", (PyCFunction)_wrap_hildon_calendar_freeze, METH_NOARGS,
      NULL },
    { "thaw", (PyCFunction)_wrap_hildon_calendar_thaw, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonCalendar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Calendar",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonCalendar_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_calendar_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonCaption ----------- */

#line 438 "hildon.override"
static int
_wrap_hildon_caption_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "group", "value", "control", "icon", "flag", NULL };
    PyGObject *py_group = NULL, *py_control = NULL, *py_icon = NULL;
    PyObject *py_flag = NULL;
    GtkSizeGroup *group;
    char *value = NULL;
    GtkWidget *control;
    GtkWidget *icon;
    HildonCaptionStatus flag = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|OsOOO:HildonCaption.__init__", kwlist, &py_group, &value, &py_control, &py_icon, &py_flag))
        return -1;

    if (py_group == NULL || (PyObject*)py_group == Py_None)
	group = NULL;
    else if (pygobject_check(py_group, &PyGtkSizeGroup_Type))
	group = GTK_SIZE_GROUP(py_group->obj);
    else {
        PyErr_SetString(PyExc_TypeError, "group must be a GtkSizeGroup or None");
        return -1;
    }

    if (py_control != NULL && pygobject_check(py_control, &PyGtkWidget_Type))
	control = GTK_WIDGET(py_control->obj);
    else {
        PyErr_SetString(PyExc_TypeError, "control must be a GtkWidget");
        return -1;
    }

    if (py_icon == NULL || (PyObject*)py_icon == Py_None)
	icon = NULL;
    else if (pygobject_check(py_icon, &PyGtkWidget_Type))
	icon = GTK_WIDGET(py_icon->obj);
    else {
        PyErr_SetString(PyExc_TypeError, "icon must be a GtkWidget or None");
        return -1;
    }

    if (pyg_flags_get_value(HILDON_TYPE_CAPTION_STATUS, py_flag, (gint *)&flag))
        return -1;

    self->obj = (GObject *)hildon_caption_new(group, value, control, icon, flag);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonCaption object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}
/* End of fix */
#line 944 "hildon.c"


static PyObject *
_wrap_hildon_caption_get_size_group(PyGObject *self)
{
    GtkSizeGroup *ret;

    
    ret = hildon_caption_get_size_group(HILDON_CAPTION(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_caption_set_size_group(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "new_group", NULL };
    PyGObject *new_group;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonCaption.set_size_group", kwlist, &PyGtkSizeGroup_Type, &new_group))
        return NULL;
    
    hildon_caption_set_size_group(HILDON_CAPTION(self->obj), GTK_SIZE_GROUP(new_group->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_is_mandatory(PyGObject *self)
{
    int ret;

    
    ret = hildon_caption_is_mandatory(HILDON_CAPTION(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_caption_set_status(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "flag", NULL };
    PyObject *py_flag = NULL;
    HildonCaptionStatus flag;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonCaption.set_status", kwlist, &py_flag))
        return NULL;
    if (pyg_enum_get_value(HILDON_TYPE_CAPTION_STATUS, py_flag, (gpointer)&flag))
        return NULL;
    
    hildon_caption_set_status(HILDON_CAPTION(self->obj), flag);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_get_status(PyGObject *self)
{
    gint ret;

    
    ret = hildon_caption_get_status(HILDON_CAPTION(self->obj));
    
    return pyg_enum_from_gtype(HILDON_TYPE_CAPTION_STATUS, ret);
}

static PyObject *
_wrap_hildon_caption_set_icon_position(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "pos", NULL };
    PyObject *py_pos = NULL;
    HildonCaptionIconPosition pos;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonCaption.set_icon_position", kwlist, &py_pos))
        return NULL;
    if (pyg_enum_get_value(HILDON_TYPE_CAPTION_ICON_POSITION, py_pos, (gpointer)&pos))
        return NULL;
    
    hildon_caption_set_icon_position(HILDON_CAPTION(self->obj), pos);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_get_icon_position(PyGObject *self)
{
    gint ret;

    
    ret = hildon_caption_get_icon_position(HILDON_CAPTION(self->obj));
    
    return pyg_enum_from_gtype(HILDON_TYPE_CAPTION_ICON_POSITION, ret);
}

static PyObject *
_wrap_hildon_caption_set_icon_image(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "icon", NULL };
    PyGObject *icon;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonCaption.set_icon_image", kwlist, &PyGtkWidget_Type, &icon))
        return NULL;
    
    hildon_caption_set_icon_image(HILDON_CAPTION(self->obj), GTK_WIDGET(icon->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_get_icon_image(PyGObject *self)
{
    GtkWidget *ret;

    
    ret = hildon_caption_get_icon_image(HILDON_CAPTION(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_caption_set_label(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "label", NULL };
    char *label;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonCaption.set_label", kwlist, &label))
        return NULL;
    
    hildon_caption_set_label(HILDON_CAPTION(self->obj), label);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_get_label(PyGObject *self)
{
    gchar *ret;

    
    ret = hildon_caption_get_label(HILDON_CAPTION(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_set_separator(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "separator", NULL };
    char *separator;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonCaption.set_separator", kwlist, &separator))
        return NULL;
    
    hildon_caption_set_separator(HILDON_CAPTION(self->obj), separator);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_get_separator(PyGObject *self)
{
    gchar *ret;

    
    ret = hildon_caption_get_separator(HILDON_CAPTION(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_set_label_alignment(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "alignment", NULL };
    double alignment;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"d:HildonCaption.set_label_alignment", kwlist, &alignment))
        return NULL;
    
    hildon_caption_set_label_alignment(HILDON_CAPTION(self->obj), alignment);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_get_label_alignment(PyGObject *self)
{
    double ret;

    
    ret = hildon_caption_get_label_alignment(HILDON_CAPTION(self->obj));
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_hildon_caption_set_child_expand(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "expand", NULL };
    int expand;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonCaption.set_child_expand", kwlist, &expand))
        return NULL;
    
    hildon_caption_set_child_expand(HILDON_CAPTION(self->obj), expand);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_caption_get_child_expand(PyGObject *self)
{
    int ret;

    
    ret = hildon_caption_get_child_expand(HILDON_CAPTION(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_caption_set_label_markup(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "markup", NULL };
    char *markup;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonCaption.set_label_markup", kwlist, &markup))
        return NULL;
    
    hildon_caption_set_label_markup(HILDON_CAPTION(self->obj), markup);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonCaption_methods[] = {
    { "get_size_group", (PyCFunction)_wrap_hildon_caption_get_size_group, METH_NOARGS,
      NULL },
    { "set_size_group", (PyCFunction)_wrap_hildon_caption_set_size_group, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_mandatory", (PyCFunction)_wrap_hildon_caption_is_mandatory, METH_NOARGS,
      NULL },
    { "set_status", (PyCFunction)_wrap_hildon_caption_set_status, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_status", (PyCFunction)_wrap_hildon_caption_get_status, METH_NOARGS,
      NULL },
    { "set_icon_position", (PyCFunction)_wrap_hildon_caption_set_icon_position, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_icon_position", (PyCFunction)_wrap_hildon_caption_get_icon_position, METH_NOARGS,
      NULL },
    { "set_icon_image", (PyCFunction)_wrap_hildon_caption_set_icon_image, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_icon_image", (PyCFunction)_wrap_hildon_caption_get_icon_image, METH_NOARGS,
      NULL },
    { "set_label", (PyCFunction)_wrap_hildon_caption_set_label, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_label", (PyCFunction)_wrap_hildon_caption_get_label, METH_NOARGS,
      NULL },
    { "set_separator", (PyCFunction)_wrap_hildon_caption_set_separator, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_separator", (PyCFunction)_wrap_hildon_caption_get_separator, METH_NOARGS,
      NULL },
    { "set_label_alignment", (PyCFunction)_wrap_hildon_caption_set_label_alignment, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_label_alignment", (PyCFunction)_wrap_hildon_caption_get_label_alignment, METH_NOARGS,
      NULL },
    { "set_child_expand", (PyCFunction)_wrap_hildon_caption_set_child_expand, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_child_expand", (PyCFunction)_wrap_hildon_caption_get_child_expand, METH_NOARGS,
      NULL },
    { "set_label_markup", (PyCFunction)_wrap_hildon_caption_set_label_markup, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonCaption_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Caption",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonCaption_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_caption_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonCodeDialog ----------- */

static int
_wrap_hildon_code_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.CodeDialog.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.CodeDialog object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_code_dialog_get_code(PyGObject *self)
{
    const gchar *ret;

    
    ret = hildon_code_dialog_get_code(HILDON_CODE_DIALOG(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_code_dialog_clear_code(PyGObject *self)
{
    
    hildon_code_dialog_clear_code(HILDON_CODE_DIALOG(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_code_dialog_set_help_text(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "text", NULL };
    char *text;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonCodeDialog.set_help_text", kwlist, &text))
        return NULL;
    
    hildon_code_dialog_set_help_text(HILDON_CODE_DIALOG(self->obj), text);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_code_dialog_set_input_sensitive(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "sensitive", NULL };
    int sensitive;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonCodeDialog.set_input_sensitive", kwlist, &sensitive))
        return NULL;
    
    hildon_code_dialog_set_input_sensitive(HILDON_CODE_DIALOG(self->obj), sensitive);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonCodeDialog_methods[] = {
    { "get_code", (PyCFunction)_wrap_hildon_code_dialog_get_code, METH_NOARGS,
      NULL },
    { "clear_code", (PyCFunction)_wrap_hildon_code_dialog_clear_code, METH_NOARGS,
      NULL },
    { "set_help_text", (PyCFunction)_wrap_hildon_code_dialog_set_help_text, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_input_sensitive", (PyCFunction)_wrap_hildon_code_dialog_set_input_sensitive, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonCodeDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.CodeDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonCodeDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_code_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonColorButton ----------- */

static int
_wrap_hildon_color_button_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.ColorButton.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.ColorButton object");
        return -1;
    }
    return 0;
}

#line 493 "hildon.override"
static PyObject *
_wrap_hildon_color_button_get_color(PyGObject *self)
{
    GdkColor color = {0, 0, 0 ,0};
    hildon_color_button_get_color(HILDON_COLOR_BUTTON(self->obj), &color);
    return pyg_boxed_new(GDK_TYPE_COLOR, &color, TRUE, TRUE);
}

#line 1456 "hildon.c"


static PyObject *
_wrap_hildon_color_button_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GdkColor *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonColorButton.set_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GDK_TYPE_COLOR))
        color = pyg_boxed_get(py_color, GdkColor);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GdkColor");
        return NULL;
    }
    
    hildon_color_button_set_color(HILDON_COLOR_BUTTON(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_color_button_get_popup_shown(PyGObject *self)
{
    int ret;

    
    ret = hildon_color_button_get_popup_shown(HILDON_COLOR_BUTTON(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_color_button_popdown(PyGObject *self)
{
    
    hildon_color_button_popdown(HILDON_COLOR_BUTTON(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonColorButton_methods[] = {
    { "get_color", (PyCFunction)_wrap_hildon_color_button_get_color, METH_NOARGS,
      NULL },
    { "set_color", (PyCFunction)_wrap_hildon_color_button_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_popup_shown", (PyCFunction)_wrap_hildon_color_button_get_popup_shown, METH_NOARGS,
      NULL },
    { "popdown", (PyCFunction)_wrap_hildon_color_button_popdown, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonColorButton_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.ColorButton",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonColorButton_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_color_button_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonColorChooserDialog ----------- */

static int
_wrap_hildon_color_chooser_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.ColorChooserDialog.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.ColorChooserDialog object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_color_chooser_dialog_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GdkColor *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonColorChooserDialog.set_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GDK_TYPE_COLOR))
        color = pyg_boxed_get(py_color, GdkColor);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GdkColor");
        return NULL;
    }
    
    hildon_color_chooser_dialog_set_color(HILDON_COLOR_CHOOSER_DIALOG(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_color_chooser_dialog_get_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GdkColor *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonColorChooserDialog.get_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GDK_TYPE_COLOR))
        color = pyg_boxed_get(py_color, GdkColor);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GdkColor");
        return NULL;
    }
    
    hildon_color_chooser_dialog_get_color(HILDON_COLOR_CHOOSER_DIALOG(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonColorChooserDialog_methods[] = {
    { "set_color", (PyCFunction)_wrap_hildon_color_chooser_dialog_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_color", (PyCFunction)_wrap_hildon_color_chooser_dialog_get_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonColorChooserDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.ColorChooserDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonColorChooserDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_color_chooser_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonColorChooser ----------- */

static int
_wrap_hildon_color_chooser_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.ColorChooser.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.ColorChooser object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_color_chooser_set_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GdkColor *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonColorChooser.set_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GDK_TYPE_COLOR))
        color = pyg_boxed_get(py_color, GdkColor);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GdkColor");
        return NULL;
    }
    
    hildon_color_chooser_set_color(HILDON_COLOR_CHOOSER(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_color_chooser_get_color(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GdkColor *color = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonColorChooser.get_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GDK_TYPE_COLOR))
        color = pyg_boxed_get(py_color, GdkColor);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GdkColor");
        return NULL;
    }
    
    hildon_color_chooser_get_color(HILDON_COLOR_CHOOSER(self->obj), color);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonColorChooser_methods[] = {
    { "set_color", (PyCFunction)_wrap_hildon_color_chooser_set_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_color", (PyCFunction)_wrap_hildon_color_chooser_get_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonColorChooser_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.ColorChooser",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonColorChooser_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_color_chooser_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonControlbar ----------- */

static int
_wrap_hildon_controlbar_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.Controlbar.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.Controlbar object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_controlbar_set_value(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonControlbar.set_value", kwlist, &value))
        return NULL;
    
    hildon_controlbar_set_value(HILDON_CONTROLBAR(self->obj), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_controlbar_get_value(PyGObject *self)
{
    int ret;

    
    ret = hildon_controlbar_get_value(HILDON_CONTROLBAR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_controlbar_get_max(PyGObject *self)
{
    int ret;

    
    ret = hildon_controlbar_get_max(HILDON_CONTROLBAR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_controlbar_get_min(PyGObject *self)
{
    int ret;

    
    ret = hildon_controlbar_get_min(HILDON_CONTROLBAR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_controlbar_set_max(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "max", NULL };
    int max;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonControlbar.set_max", kwlist, &max))
        return NULL;
    
    hildon_controlbar_set_max(HILDON_CONTROLBAR(self->obj), max);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_controlbar_set_min(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "min", NULL };
    int min;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonControlbar.set_min", kwlist, &min))
        return NULL;
    
    hildon_controlbar_set_min(HILDON_CONTROLBAR(self->obj), min);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_controlbar_set_range(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "min", "max", NULL };
    int min, max;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:HildonControlbar.set_range", kwlist, &min, &max))
        return NULL;
    
    hildon_controlbar_set_range(HILDON_CONTROLBAR(self->obj), min, max);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonControlbar_methods[] = {
    { "set_value", (PyCFunction)_wrap_hildon_controlbar_set_value, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_value", (PyCFunction)_wrap_hildon_controlbar_get_value, METH_NOARGS,
      NULL },
    { "get_max", (PyCFunction)_wrap_hildon_controlbar_get_max, METH_NOARGS,
      NULL },
    { "get_min", (PyCFunction)_wrap_hildon_controlbar_get_min, METH_NOARGS,
      NULL },
    { "set_max", (PyCFunction)_wrap_hildon_controlbar_set_max, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_min", (PyCFunction)_wrap_hildon_controlbar_set_min, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_range", (PyCFunction)_wrap_hildon_controlbar_set_range, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonControlbar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Controlbar",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonControlbar_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_controlbar_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonDateEditor ----------- */

static int
_wrap_hildon_date_editor_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.DateEditor.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.DateEditor object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_date_editor_set_date(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "year", "month", "day", NULL };
    PyObject *py_year = NULL, *py_month = NULL, *py_day = NULL;
    guint year = 0, month = 0, day = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOO:HildonDateEditor.set_date", kwlist, &py_year, &py_month, &py_day))
        return NULL;
    if (py_year) {
        if (PyLong_Check(py_year))
            year = PyLong_AsUnsignedLong(py_year);
        else if (PyInt_Check(py_year))
            year = PyInt_AsLong(py_year);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'year' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_month) {
        if (PyLong_Check(py_month))
            month = PyLong_AsUnsignedLong(py_month);
        else if (PyInt_Check(py_month))
            month = PyInt_AsLong(py_month);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'month' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_day) {
        if (PyLong_Check(py_day))
            day = PyLong_AsUnsignedLong(py_day);
        else if (PyInt_Check(py_day))
            day = PyInt_AsLong(py_day);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'day' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_date_editor_set_date(HILDON_DATE_EDITOR(self->obj), year, month, day);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 78 "hildon.override"
static PyObject *
_wrap_hildon_date_editor_get_date (PyGObject *self)
{
   int year, month, day;

   hildon_date_editor_get_date(HILDON_DATE_EDITOR(self->obj), &year, &month, &day);
 
   return Py_BuildValue("(iii)", year, month, day);
}

#line 2063 "hildon.c"


static PyObject *
_wrap_hildon_date_editor_set_year(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "year", NULL };
    PyObject *py_year = NULL;
    int ret;
    guint year = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonDateEditor.set_year", kwlist, &py_year))
        return NULL;
    if (py_year) {
        if (PyLong_Check(py_year))
            year = PyLong_AsUnsignedLong(py_year);
        else if (PyInt_Check(py_year))
            year = PyInt_AsLong(py_year);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'year' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = hildon_date_editor_set_year(HILDON_DATE_EDITOR(self->obj), year);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_date_editor_set_month(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "month", NULL };
    PyObject *py_month = NULL;
    int ret;
    guint month = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonDateEditor.set_month", kwlist, &py_month))
        return NULL;
    if (py_month) {
        if (PyLong_Check(py_month))
            month = PyLong_AsUnsignedLong(py_month);
        else if (PyInt_Check(py_month))
            month = PyInt_AsLong(py_month);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'month' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = hildon_date_editor_set_month(HILDON_DATE_EDITOR(self->obj), month);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_date_editor_set_day(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "day", NULL };
    PyObject *py_day = NULL;
    int ret;
    guint day = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonDateEditor.set_day", kwlist, &py_day))
        return NULL;
    if (py_day) {
        if (PyLong_Check(py_day))
            day = PyLong_AsUnsignedLong(py_day);
        else if (PyInt_Check(py_day))
            day = PyInt_AsLong(py_day);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'day' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = hildon_date_editor_set_day(HILDON_DATE_EDITOR(self->obj), day);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_date_editor_get_year(PyGObject *self)
{
    guint ret;

    
    ret = hildon_date_editor_get_year(HILDON_DATE_EDITOR(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static PyObject *
_wrap_hildon_date_editor_get_month(PyGObject *self)
{
    guint ret;

    
    ret = hildon_date_editor_get_month(HILDON_DATE_EDITOR(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static PyObject *
_wrap_hildon_date_editor_get_day(PyGObject *self)
{
    guint ret;

    
    ret = hildon_date_editor_get_day(HILDON_DATE_EDITOR(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static const PyMethodDef _PyHildonDateEditor_methods[] = {
    { "set_date", (PyCFunction)_wrap_hildon_date_editor_set_date, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_date", (PyCFunction)_wrap_hildon_date_editor_get_date, METH_NOARGS,
      NULL },
    { "set_year", (PyCFunction)_wrap_hildon_date_editor_set_year, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_month", (PyCFunction)_wrap_hildon_date_editor_set_month, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_day", (PyCFunction)_wrap_hildon_date_editor_set_day, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_year", (PyCFunction)_wrap_hildon_date_editor_get_year, METH_NOARGS,
      NULL },
    { "get_month", (PyCFunction)_wrap_hildon_date_editor_get_month, METH_NOARGS,
      NULL },
    { "get_day", (PyCFunction)_wrap_hildon_date_editor_get_day, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonDateEditor_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.DateEditor",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonDateEditor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_date_editor_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonFindToolbar ----------- */

static int
_wrap_hildon_find_toolbar_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "label", NULL };
    char *label;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFindToolbar.__init__", kwlist, &label))
        return -1;
    self->obj = (GObject *)hildon_find_toolbar_new(label);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonFindToolbar object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_find_toolbar_highlight_entry(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "get_focus", NULL };
    int get_focus;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonFindToolbar.highlight_entry", kwlist, &get_focus))
        return NULL;
    
    hildon_find_toolbar_highlight_entry(HILDON_FIND_TOOLBAR(self->obj), get_focus);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonFindToolbar_methods[] = {
    { "highlight_entry", (PyCFunction)_wrap_hildon_find_toolbar_highlight_entry, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonFindToolbar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.FindToolbar",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonFindToolbar_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_find_toolbar_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonFontSelectionDialog ----------- */

#line 340 "hildon.override"
static int
_wrap_hildon_font_selection_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "title", NULL };
    PyGObject *parent;
    char *title = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!|s:HildonFontSelectionDialog.__init__", kwlist, &PyGtkWindow_Type, &parent, &title))
        return -1;
    self->obj = (GObject *)hildon_font_selection_dialog_new(GTK_WINDOW(parent->obj), title);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonFontSelectionDialog object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

#line 2357 "hildon.c"


static PyObject *
_wrap_hildon_font_selection_dialog_get_preview_text(PyGObject *self)
{
    gchar *ret;

    
    ret = hildon_font_selection_dialog_get_preview_text(HILDON_FONT_SELECTION_DIALOG(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_font_selection_dialog_set_preview_text(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "text", NULL };
    char *text;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFontSelectionDialog.set_preview_text", kwlist, &text))
        return NULL;
    
    hildon_font_selection_dialog_set_preview_text(HILDON_FONT_SELECTION_DIALOG(self->obj), text);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonFontSelectionDialog_methods[] = {
    { "get_preview_text", (PyCFunction)_wrap_hildon_font_selection_dialog_get_preview_text, METH_NOARGS,
      NULL },
    { "set_preview_text", (PyCFunction)_wrap_hildon_font_selection_dialog_set_preview_text, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonFontSelectionDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.FontSelectionDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonFontSelectionDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_font_selection_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonGetPasswordDialog ----------- */

static int
_wrap_hildon_get_password_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "get_old", NULL };
    PyGObject *parent;
    int get_old;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!i:HildonGetPasswordDialog.__init__", kwlist, &PyGtkWindow_Type, &parent, &get_old))
        return -1;
    self->obj = (GObject *)hildon_get_password_dialog_new(GTK_WINDOW(parent->obj), get_old);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonGetPasswordDialog object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_get_password_dialog_set_message(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "message", NULL };
    char *message;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonGetPasswordDialog.set_message", kwlist, &message))
        return NULL;
    
    hildon_get_password_dialog_set_message(HILDON_GET_PASSWORD_DIALOG(self->obj), message);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_get_password_dialog_set_caption(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "new_caption", NULL };
    char *new_caption;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonGetPasswordDialog.set_caption", kwlist, &new_caption))
        return NULL;
    
    hildon_get_password_dialog_set_caption(HILDON_GET_PASSWORD_DIALOG(self->obj), new_caption);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_get_password_dialog_set_max_characters(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "max_characters", NULL };
    int max_characters;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonGetPasswordDialog.set_max_characters", kwlist, &max_characters))
        return NULL;
    
    hildon_get_password_dialog_set_max_characters(HILDON_GET_PASSWORD_DIALOG(self->obj), max_characters);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_get_password_dialog_get_password(PyGObject *self)
{
    const gchar *ret;

    
    ret = hildon_get_password_dialog_get_password(HILDON_GET_PASSWORD_DIALOG(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonGetPasswordDialog_methods[] = {
    { "set_message", (PyCFunction)_wrap_hildon_get_password_dialog_set_message, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_caption", (PyCFunction)_wrap_hildon_get_password_dialog_set_caption, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_max_characters", (PyCFunction)_wrap_hildon_get_password_dialog_set_max_characters, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_password", (PyCFunction)_wrap_hildon_get_password_dialog_get_password, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonGetPasswordDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.GetPasswordDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonGetPasswordDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_get_password_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonVolumebar ----------- */

static PyObject *
_wrap_hildon_volumebar_get_level(PyGObject *self)
{
    double ret;

    
    ret = hildon_volumebar_get_level(HILDON_VOLUMEBAR(self->obj));
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_hildon_volumebar_set_level(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "level", NULL };
    double level;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"d:HildonVolumebar.set_level", kwlist, &level))
        return NULL;
    
    hildon_volumebar_set_level(HILDON_VOLUMEBAR(self->obj), level);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_volumebar_get_mute(PyGObject *self)
{
    int ret;

    
    ret = hildon_volumebar_get_mute(HILDON_VOLUMEBAR(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_volumebar_set_mute(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "mute", NULL };
    int mute;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonVolumebar.set_mute", kwlist, &mute))
        return NULL;
    
    hildon_volumebar_set_mute(HILDON_VOLUMEBAR(self->obj), mute);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_volumebar_get_adjustment(PyGObject *self)
{
    GtkAdjustment *ret;

    
    ret = hildon_volumebar_get_adjustment(HILDON_VOLUMEBAR(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyHildonVolumebar_methods[] = {
    { "get_level", (PyCFunction)_wrap_hildon_volumebar_get_level, METH_NOARGS,
      NULL },
    { "set_level", (PyCFunction)_wrap_hildon_volumebar_set_level, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_mute", (PyCFunction)_wrap_hildon_volumebar_get_mute, METH_NOARGS,
      NULL },
    { "set_mute", (PyCFunction)_wrap_hildon_volumebar_set_mute, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_adjustment", (PyCFunction)_wrap_hildon_volumebar_get_adjustment, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonVolumebar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Volumebar",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonVolumebar_methods, /* tp_methods */
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



/* ----------- HildonHVolumebar ----------- */

PyTypeObject G_GNUC_INTERNAL PyHildonHVolumebar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.HVolumebar",                   /* tp_name */
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



/* ----------- HildonLoginDialog ----------- */

static int
_wrap_hildon_login_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", NULL };
    PyGObject *parent;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonLoginDialog.__init__", kwlist, &PyGtkWindow_Type, &parent))
        return -1;
    self->obj = (GObject *)hildon_login_dialog_new(GTK_WINDOW(parent->obj));

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonLoginDialog object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_login_dialog_get_username(PyGObject *self)
{
    const gchar *ret;

    
    ret = hildon_login_dialog_get_username(HILDON_LOGIN_DIALOG(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_login_dialog_get_password(PyGObject *self)
{
    const gchar *ret;

    
    ret = hildon_login_dialog_get_password(HILDON_LOGIN_DIALOG(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_login_dialog_set_message(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "msg", NULL };
    char *msg;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonLoginDialog.set_message", kwlist, &msg))
        return NULL;
    
    hildon_login_dialog_set_message(HILDON_LOGIN_DIALOG(self->obj), msg);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonLoginDialog_methods[] = {
    { "get_username", (PyCFunction)_wrap_hildon_login_dialog_get_username, METH_NOARGS,
      NULL },
    { "get_password", (PyCFunction)_wrap_hildon_login_dialog_get_password, METH_NOARGS,
      NULL },
    { "set_message", (PyCFunction)_wrap_hildon_login_dialog_set_message, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonLoginDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.LoginDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonLoginDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_login_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonNote ----------- */

#line 212 "hildon.override"
static int
_wrap_hildon_note_new (PyGObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject* py_tuple;
    const char *note_type;
    static char *kwlist[] = { "note_type", "note_tuple", NULL };
    PyObject* py_obj;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "sO!:HildonNote.__init__", kwlist, &note_type, &PyTuple_Type, &py_tuple))
        return -1;

    if (strcmp (note_type, "confirmation") == 0) {
        PyObject* parent;
        const char* description;
        const char* icon_name;
        
        if (PyTuple_Size (py_tuple) != 3 && PyTuple_Size (py_tuple) != 2) {
            PyErr_SetString(PyExc_RuntimeError, "A \"confirmation\" HildonNote type takes three or two items in its tuple.");
            return -1;
        }
        
        parent = PyTuple_GetItem (py_tuple, 0);
        if (parent == NULL) {
            return -1;
        }
        
        py_obj = PyTuple_GetItem (py_tuple, 1);
        description = PyString_AsString (py_obj);
        if (description == NULL) {
            return -1;
        }

        if (PyTuple_Size (py_tuple) == 3) {
            py_obj = PyTuple_GetItem (py_tuple, 2);
            icon_name = PyString_AsString (py_obj);
            if (icon_name == NULL) {
                return -1;
            }
            self->obj = (GObject *)hildon_note_new_confirmation_with_icon_name (GTK_WINDOW(pygobject_get(parent)), description, icon_name);
        } else {
            /* Use the default icon. */
            self->obj = (GObject *)hildon_note_new_confirmation (GTK_WINDOW(pygobject_get(parent)), description);
        }
        
        if (!self->obj) {
            PyErr_SetString(PyExc_RuntimeError, "could not create HildonNote object");
            return -1;
        }
    } else if (strcmp (note_type, "information") == 0) {
        PyObject* parent;
        const char* description;
        const char* icon_name;
        
        if (PyTuple_Size (py_tuple) != 3 && PyTuple_Size (py_tuple) != 2) {
            PyErr_SetString(PyExc_RuntimeError, "A \"information\" HildonNote type takes three or two items in its tuple.");
            return -1;
        }
        
        parent = PyTuple_GetItem (py_tuple, 0);
        if (parent == NULL) {
            return -1;
        }
        
        py_obj = PyTuple_GetItem (py_tuple, 1);
        description = PyString_AsString (py_obj);
        if (description == NULL) {
            return -1;
        }
        
        if (PyTuple_Size (py_tuple) == 3) {
            py_obj = PyTuple_GetItem (py_tuple, 2);
            icon_name = PyString_AsString (py_obj);
            if (icon_name == NULL) {
                return -1;
            }
            
            self->obj = (GObject *)hildon_note_new_information_with_icon_name (GTK_WINDOW(pygobject_get(parent)), description, icon_name);
        } else {
            /* Use the default icon. */
            self->obj = (GObject *)hildon_note_new_information (GTK_WINDOW(pygobject_get(parent)), description);
        }
        
        if (!self->obj) {
            PyErr_SetString(PyExc_RuntimeError, "could not create HildonNote object");
            return -1;
        }
    } else if (strcmp (note_type, "cancel_with_progress_bar") == 0) {
        PyObject* parent;
        const char* description;
        PyObject* progress_bar;
    
        if (PyTuple_Size (py_tuple) != 3) {
            PyErr_SetString(PyExc_RuntimeError, "A \"cancel_with_progress_bar\" HildonNote type takes exactly three items in its tuple.");
            return -1;
        }
        
        parent = PyTuple_GetItem (py_tuple, 0);
        if (parent == NULL) {
            return -1;
        }
        
        py_obj = PyTuple_GetItem (py_tuple, 1);
        description = PyString_AsString (py_obj);
        if (description == NULL) {
            return -1;
        }
        
        progress_bar = PyTuple_GetItem (py_tuple, 2);
        if (progress_bar == NULL) {
            return -1;
        }
        
        self->obj = (GObject *)hildon_note_new_cancel_with_progress_bar(GTK_WINDOW(pygobject_get(parent)), description, GTK_PROGRESS_BAR(pygobject_get(progress_bar)));
        if (!self->obj) {
            PyErr_SetString(PyExc_RuntimeError, "could not create HildonNote object");
            return -1;
        }
    } else {
        PyErr_SetString(PyExc_RuntimeError, "HildonNote constructor: Unknow note type.");
        return -1;
    }
   
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

#line 3012 "hildon.c"


static PyObject *
_wrap_hildon_note_set_button_text(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "text", NULL };
    char *text;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonNote.set_button_text", kwlist, &text))
        return NULL;
    
    hildon_note_set_button_text(HILDON_NOTE(self->obj), text);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_note_set_button_texts(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "text_ok", "text_cancel", NULL };
    char *text_ok, *text_cancel;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:HildonNote.set_button_texts", kwlist, &text_ok, &text_cancel))
        return NULL;
    
    hildon_note_set_button_texts(HILDON_NOTE(self->obj), text_ok, text_cancel);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonNote_methods[] = {
    { "set_button_text", (PyCFunction)_wrap_hildon_note_set_button_text, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_button_texts", (PyCFunction)_wrap_hildon_note_set_button_texts, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonNote_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Note",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonNote_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_note_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonNumberEditor ----------- */

static int
_wrap_hildon_number_editor_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "min", "max", NULL };
    int min, max;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:HildonNumberEditor.__init__", kwlist, &min, &max))
        return -1;
    self->obj = (GObject *)hildon_number_editor_new(min, max);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonNumberEditor object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_number_editor_set_range(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "min", "max", NULL };
    int min, max;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:HildonNumberEditor.set_range", kwlist, &min, &max))
        return NULL;
    
    hildon_number_editor_set_range(HILDON_NUMBER_EDITOR(self->obj), min, max);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_number_editor_get_value(PyGObject *self)
{
    int ret;

    
    ret = hildon_number_editor_get_value(HILDON_NUMBER_EDITOR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_number_editor_set_value(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonNumberEditor.set_value", kwlist, &value))
        return NULL;
    
    hildon_number_editor_set_value(HILDON_NUMBER_EDITOR(self->obj), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonNumberEditor_methods[] = {
    { "set_range", (PyCFunction)_wrap_hildon_number_editor_set_range, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_value", (PyCFunction)_wrap_hildon_number_editor_get_value, METH_NOARGS,
      NULL },
    { "set_value", (PyCFunction)_wrap_hildon_number_editor_set_value, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonNumberEditor_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.NumberEditor",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonNumberEditor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_number_editor_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonProgram ----------- */

static PyObject *
_wrap_hildon_program_add_window(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "window", NULL };
    PyGObject *window;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonProgram.add_window", kwlist, &PyHildonWindow_Type, &window))
        return NULL;
    
    hildon_program_add_window(HILDON_PROGRAM(self->obj), HILDON_WINDOW(window->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_program_remove_window(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "window", NULL };
    PyGObject *window;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonProgram.remove_window", kwlist, &PyHildonWindow_Type, &window))
        return NULL;
    
    hildon_program_remove_window(HILDON_PROGRAM(self->obj), HILDON_WINDOW(window->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_program_set_can_hibernate(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "can_hibernate", NULL };
    int can_hibernate;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonProgram.set_can_hibernate", kwlist, &can_hibernate))
        return NULL;
    
    hildon_program_set_can_hibernate(HILDON_PROGRAM(self->obj), can_hibernate);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_program_get_can_hibernate(PyGObject *self)
{
    int ret;

    
    ret = hildon_program_get_can_hibernate(HILDON_PROGRAM(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_program_set_common_menu(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "menu", NULL };
    PyGObject *menu;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonProgram.set_common_menu", kwlist, &PyGtkMenu_Type, &menu))
        return NULL;
    
    hildon_program_set_common_menu(HILDON_PROGRAM(self->obj), GTK_MENU(menu->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_program_get_common_menu(PyGObject *self)
{
    GtkMenu *ret;

    
    ret = hildon_program_get_common_menu(HILDON_PROGRAM(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_program_set_common_toolbar(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "toolbar", NULL };
    PyGObject *toolbar;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonProgram.set_common_toolbar", kwlist, &PyGtkToolbar_Type, &toolbar))
        return NULL;
    
    hildon_program_set_common_toolbar(HILDON_PROGRAM(self->obj), GTK_TOOLBAR(toolbar->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_program_get_common_toolbar(PyGObject *self)
{
    GtkToolbar *ret;

    
    ret = hildon_program_get_common_toolbar(HILDON_PROGRAM(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_program_get_is_topmost(PyGObject *self)
{
    int ret;

    
    ret = hildon_program_get_is_topmost(HILDON_PROGRAM(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyHildonProgram_methods[] = {
    { "add_window", (PyCFunction)_wrap_hildon_program_add_window, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "remove_window", (PyCFunction)_wrap_hildon_program_remove_window, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_can_hibernate", (PyCFunction)_wrap_hildon_program_set_can_hibernate, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_can_hibernate", (PyCFunction)_wrap_hildon_program_get_can_hibernate, METH_NOARGS,
      NULL },
    { "set_common_menu", (PyCFunction)_wrap_hildon_program_set_common_menu, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_common_menu", (PyCFunction)_wrap_hildon_program_get_common_menu, METH_NOARGS,
      NULL },
    { "set_common_toolbar", (PyCFunction)_wrap_hildon_program_set_common_toolbar, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_common_toolbar", (PyCFunction)_wrap_hildon_program_get_common_toolbar, METH_NOARGS,
      NULL },
    { "get_is_topmost", (PyCFunction)_wrap_hildon_program_get_is_topmost, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonProgram_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Program",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonProgram_methods, /* tp_methods */
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



/* ----------- HildonRangeEditor ----------- */

static int
_wrap_hildon_range_editor_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.RangeEditor.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.RangeEditor object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_range_editor_set_range(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "start", "end", NULL };
    int start, end;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:HildonRangeEditor.set_range", kwlist, &start, &end))
        return NULL;
    
    hildon_range_editor_set_range(HILDON_RANGE_EDITOR(self->obj), start, end);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 90 "hildon.override"
static PyObject *
_wrap_hildon_range_editor_get_range (PyGObject *self)
{
   int start, end;

   hildon_range_editor_get_range(HILDON_RANGE_EDITOR(self->obj), &start, &end);
 
   return Py_BuildValue("(ii)", start, end);
}

#line 3460 "hildon.c"


static PyObject *
_wrap_hildon_range_editor_set_limits(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "start", "end", NULL };
    int start, end;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ii:HildonRangeEditor.set_limits", kwlist, &start, &end))
        return NULL;
    
    hildon_range_editor_set_limits(HILDON_RANGE_EDITOR(self->obj), start, end);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_range_editor_set_lower(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonRangeEditor.set_lower", kwlist, &value))
        return NULL;
    
    hildon_range_editor_set_lower(HILDON_RANGE_EDITOR(self->obj), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_range_editor_set_higher(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonRangeEditor.set_higher", kwlist, &value))
        return NULL;
    
    hildon_range_editor_set_higher(HILDON_RANGE_EDITOR(self->obj), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_range_editor_get_lower(PyGObject *self)
{
    int ret;

    
    ret = hildon_range_editor_get_lower(HILDON_RANGE_EDITOR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_range_editor_get_higher(PyGObject *self)
{
    int ret;

    
    ret = hildon_range_editor_get_higher(HILDON_RANGE_EDITOR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_range_editor_set_min(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonRangeEditor.set_min", kwlist, &value))
        return NULL;
    
    hildon_range_editor_set_min(HILDON_RANGE_EDITOR(self->obj), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_range_editor_set_max(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonRangeEditor.set_max", kwlist, &value))
        return NULL;
    
    hildon_range_editor_set_max(HILDON_RANGE_EDITOR(self->obj), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_range_editor_get_min(PyGObject *self)
{
    int ret;

    
    ret = hildon_range_editor_get_min(HILDON_RANGE_EDITOR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_range_editor_get_max(PyGObject *self)
{
    int ret;

    
    ret = hildon_range_editor_get_max(HILDON_RANGE_EDITOR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_range_editor_set_separator(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "separator", NULL };
    char *separator;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonRangeEditor.set_separator", kwlist, &separator))
        return NULL;
    
    hildon_range_editor_set_separator(HILDON_RANGE_EDITOR(self->obj), separator);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_range_editor_get_separator(PyGObject *self)
{
    const gchar *ret;

    
    ret = hildon_range_editor_get_separator(HILDON_RANGE_EDITOR(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonRangeEditor_methods[] = {
    { "set_range", (PyCFunction)_wrap_hildon_range_editor_set_range, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_range", (PyCFunction)_wrap_hildon_range_editor_get_range, METH_NOARGS,
      NULL },
    { "set_limits", (PyCFunction)_wrap_hildon_range_editor_set_limits, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_lower", (PyCFunction)_wrap_hildon_range_editor_set_lower, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_higher", (PyCFunction)_wrap_hildon_range_editor_set_higher, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_lower", (PyCFunction)_wrap_hildon_range_editor_get_lower, METH_NOARGS,
      NULL },
    { "get_higher", (PyCFunction)_wrap_hildon_range_editor_get_higher, METH_NOARGS,
      NULL },
    { "set_min", (PyCFunction)_wrap_hildon_range_editor_set_min, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_max", (PyCFunction)_wrap_hildon_range_editor_set_max, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_min", (PyCFunction)_wrap_hildon_range_editor_get_min, METH_NOARGS,
      NULL },
    { "get_max", (PyCFunction)_wrap_hildon_range_editor_get_max, METH_NOARGS,
      NULL },
    { "set_separator", (PyCFunction)_wrap_hildon_range_editor_set_separator, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_separator", (PyCFunction)_wrap_hildon_range_editor_get_separator, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonRangeEditor_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.RangeEditor",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonRangeEditor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_range_editor_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonSeekbar ----------- */

static int
_wrap_hildon_seekbar_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.Seekbar.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.Seekbar object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_seekbar_get_total_time(PyGObject *self)
{
    int ret;

    
    ret = hildon_seekbar_get_total_time(HILDON_SEEKBAR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_seekbar_set_total_time(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "time", NULL };
    int time;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonSeekbar.set_total_time", kwlist, &time))
        return NULL;
    
    hildon_seekbar_set_total_time(HILDON_SEEKBAR(self->obj), time);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_seekbar_get_position(PyGObject *self)
{
    int ret;

    
    ret = hildon_seekbar_get_position(HILDON_SEEKBAR(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_seekbar_set_position(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "time", NULL };
    int time;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonSeekbar.set_position", kwlist, &time))
        return NULL;
    
    hildon_seekbar_set_position(HILDON_SEEKBAR(self->obj), time);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_seekbar_set_fraction(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "fraction", NULL };
    PyObject *py_fraction = NULL;
    guint fraction = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonSeekbar.set_fraction", kwlist, &py_fraction))
        return NULL;
    if (py_fraction) {
        if (PyLong_Check(py_fraction))
            fraction = PyLong_AsUnsignedLong(py_fraction);
        else if (PyInt_Check(py_fraction))
            fraction = PyInt_AsLong(py_fraction);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'fraction' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_seekbar_set_fraction(HILDON_SEEKBAR(self->obj), fraction);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_seekbar_get_fraction(PyGObject *self)
{
    guint ret;

    
    ret = hildon_seekbar_get_fraction(HILDON_SEEKBAR(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static const PyMethodDef _PyHildonSeekbar_methods[] = {
    { "get_total_time", (PyCFunction)_wrap_hildon_seekbar_get_total_time, METH_NOARGS,
      NULL },
    { "set_total_time", (PyCFunction)_wrap_hildon_seekbar_set_total_time, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_position", (PyCFunction)_wrap_hildon_seekbar_get_position, METH_NOARGS,
      NULL },
    { "set_position", (PyCFunction)_wrap_hildon_seekbar_set_position, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_fraction", (PyCFunction)_wrap_hildon_seekbar_set_fraction, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_fraction", (PyCFunction)_wrap_hildon_seekbar_get_fraction, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonSeekbar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Seekbar",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonSeekbar_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_seekbar_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonSetPasswordDialog ----------- */

static int
_wrap_hildon_set_password_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "modify_protection", NULL };
    PyGObject *parent;
    int modify_protection;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!i:HildonSetPasswordDialog.__init__", kwlist, &PyGtkWindow_Type, &parent, &modify_protection))
        return -1;
    self->obj = (GObject *)hildon_set_password_dialog_new(GTK_WINDOW(parent->obj), modify_protection);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonSetPasswordDialog object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_set_password_dialog_get_password(PyGObject *self)
{
    const gchar *ret;

    
    ret = hildon_set_password_dialog_get_password(HILDON_SET_PASSWORD_DIALOG(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_set_password_dialog_get_protected(PyGObject *self)
{
    int ret;

    
    ret = hildon_set_password_dialog_get_protected(HILDON_SET_PASSWORD_DIALOG(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_set_password_dialog_set_message(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "message", NULL };
    char *message;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonSetPasswordDialog.set_message", kwlist, &message))
        return NULL;
    
    hildon_set_password_dialog_set_message(HILDON_SET_PASSWORD_DIALOG(self->obj), message);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonSetPasswordDialog_methods[] = {
    { "get_password", (PyCFunction)_wrap_hildon_set_password_dialog_get_password, METH_NOARGS,
      NULL },
    { "get_protected", (PyCFunction)_wrap_hildon_set_password_dialog_get_protected, METH_NOARGS,
      NULL },
    { "set_message", (PyCFunction)_wrap_hildon_set_password_dialog_set_message, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonSetPasswordDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.SetPasswordDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonSetPasswordDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_set_password_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonSortDialog ----------- */

static int
_wrap_hildon_sort_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", NULL };
    PyGObject *parent;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonSortDialog.__init__", kwlist, &PyGtkWindow_Type, &parent))
        return -1;
    self->obj = (GObject *)hildon_sort_dialog_new(GTK_WINDOW(parent->obj));

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonSortDialog object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_sort_dialog_get_sort_key(PyGObject *self)
{
    int ret;

    
    ret = hildon_sort_dialog_get_sort_key(HILDON_SORT_DIALOG(self->obj));
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_sort_dialog_get_sort_order(PyGObject *self)
{
    gint ret;

    
    ret = hildon_sort_dialog_get_sort_order(HILDON_SORT_DIALOG(self->obj));
    
    return pyg_enum_from_gtype(GTK_TYPE_SORT_TYPE, ret);
}

static PyObject *
_wrap_hildon_sort_dialog_set_sort_key(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    int key;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonSortDialog.set_sort_key", kwlist, &key))
        return NULL;
    
    hildon_sort_dialog_set_sort_key(HILDON_SORT_DIALOG(self->obj), key);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_sort_dialog_set_sort_order(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "order", NULL };
    PyObject *py_order = NULL;
    GtkSortType order;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonSortDialog.set_sort_order", kwlist, &py_order))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_SORT_TYPE, py_order, (gpointer)&order))
        return NULL;
    
    hildon_sort_dialog_set_sort_order(HILDON_SORT_DIALOG(self->obj), order);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_sort_dialog_add_sort_key(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "sort_key", NULL };
    char *sort_key;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonSortDialog.add_sort_key", kwlist, &sort_key))
        return NULL;
    
    ret = hildon_sort_dialog_add_sort_key(HILDON_SORT_DIALOG(self->obj), sort_key);
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_sort_dialog_add_sort_key_reversed(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "sort_key", NULL };
    char *sort_key;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonSortDialog.add_sort_key_reversed", kwlist, &sort_key))
        return NULL;
    
    ret = hildon_sort_dialog_add_sort_key_reversed(HILDON_SORT_DIALOG(self->obj), sort_key);
    
    return PyInt_FromLong(ret);
}

static const PyMethodDef _PyHildonSortDialog_methods[] = {
    { "get_sort_key", (PyCFunction)_wrap_hildon_sort_dialog_get_sort_key, METH_NOARGS,
      NULL },
    { "get_sort_order", (PyCFunction)_wrap_hildon_sort_dialog_get_sort_order, METH_NOARGS,
      NULL },
    { "set_sort_key", (PyCFunction)_wrap_hildon_sort_dialog_set_sort_key, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_sort_order", (PyCFunction)_wrap_hildon_sort_dialog_set_sort_order, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "add_sort_key", (PyCFunction)_wrap_hildon_sort_dialog_add_sort_key, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "add_sort_key_reversed", (PyCFunction)_wrap_hildon_sort_dialog_add_sort_key_reversed, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonSortDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.SortDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonSortDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_sort_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonTimeEditor ----------- */

static int
_wrap_hildon_time_editor_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.TimeEditor.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.TimeEditor object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_time_editor_set_time(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "hours", "minutes", "seconds", NULL };
    PyObject *py_hours = NULL, *py_minutes = NULL, *py_seconds = NULL;
    guint hours = 0, minutes = 0, seconds = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOO:HildonTimeEditor.set_time", kwlist, &py_hours, &py_minutes, &py_seconds))
        return NULL;
    if (py_hours) {
        if (PyLong_Check(py_hours))
            hours = PyLong_AsUnsignedLong(py_hours);
        else if (PyInt_Check(py_hours))
            hours = PyInt_AsLong(py_hours);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'hours' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_minutes) {
        if (PyLong_Check(py_minutes))
            minutes = PyLong_AsUnsignedLong(py_minutes);
        else if (PyInt_Check(py_minutes))
            minutes = PyInt_AsLong(py_minutes);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'minutes' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_seconds) {
        if (PyLong_Check(py_seconds))
            seconds = PyLong_AsUnsignedLong(py_seconds);
        else if (PyInt_Check(py_seconds))
            seconds = PyInt_AsLong(py_seconds);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'seconds' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_time_editor_set_time(HILDON_TIME_EDITOR(self->obj), hours, minutes, seconds);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 102 "hildon.override"
static PyObject *
_wrap_hildon_time_editor_get_time (PyGObject *self)
{
   int hours, minutes, seconds;

   hildon_time_editor_get_time(HILDON_TIME_EDITOR(self->obj), &hours, &minutes, &seconds);
 
   return Py_BuildValue("(iii)", hours, minutes, seconds);
}

#line 4228 "hildon.c"


static PyObject *
_wrap_hildon_time_editor_set_duration_range(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "min_seconds", "max_seconds", NULL };
    PyObject *py_min_seconds = NULL, *py_max_seconds = NULL;
    guint min_seconds = 0, max_seconds = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:HildonTimeEditor.set_duration_range", kwlist, &py_min_seconds, &py_max_seconds))
        return NULL;
    if (py_min_seconds) {
        if (PyLong_Check(py_min_seconds))
            min_seconds = PyLong_AsUnsignedLong(py_min_seconds);
        else if (PyInt_Check(py_min_seconds))
            min_seconds = PyInt_AsLong(py_min_seconds);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'min_seconds' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_max_seconds) {
        if (PyLong_Check(py_max_seconds))
            max_seconds = PyLong_AsUnsignedLong(py_max_seconds);
        else if (PyInt_Check(py_max_seconds))
            max_seconds = PyInt_AsLong(py_max_seconds);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'max_seconds' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_time_editor_set_duration_range(HILDON_TIME_EDITOR(self->obj), min_seconds, max_seconds);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 114 "hildon.override"
static PyObject *
_wrap_hildon_time_editor_get_duration_range (PyGObject *self)
{
   int min_seconds, max_seconds;

   hildon_time_editor_get_duration_range(HILDON_TIME_EDITOR(self->obj), &min_seconds, &max_seconds);
 
   return Py_BuildValue("(ii)", min_seconds, max_seconds);
}

#line 4278 "hildon.c"


static PyObject *
_wrap_hildon_time_editor_set_ticks(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "ticks", NULL };
    PyObject *py_ticks = NULL;
    guint ticks = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonTimeEditor.set_ticks", kwlist, &py_ticks))
        return NULL;
    if (py_ticks) {
        if (PyLong_Check(py_ticks))
            ticks = PyLong_AsUnsignedLong(py_ticks);
        else if (PyInt_Check(py_ticks))
            ticks = PyInt_AsLong(py_ticks);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'ticks' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_time_editor_set_ticks(HILDON_TIME_EDITOR(self->obj), ticks);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_time_editor_get_ticks(PyGObject *self)
{
    guint ret;

    
    ret = hildon_time_editor_get_ticks(HILDON_TIME_EDITOR(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static PyObject *
_wrap_hildon_time_editor_set_show_seconds(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "show_seconds", NULL };
    int show_seconds;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonTimeEditor.set_show_seconds", kwlist, &show_seconds))
        return NULL;
    
    hildon_time_editor_set_show_seconds(HILDON_TIME_EDITOR(self->obj), show_seconds);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_time_editor_get_show_seconds(PyGObject *self)
{
    int ret;

    
    ret = hildon_time_editor_get_show_seconds(HILDON_TIME_EDITOR(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_time_editor_set_show_hours(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "show_hours", NULL };
    int show_hours;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonTimeEditor.set_show_hours", kwlist, &show_hours))
        return NULL;
    
    hildon_time_editor_set_show_hours(HILDON_TIME_EDITOR(self->obj), show_hours);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_time_editor_get_show_hours(PyGObject *self)
{
    int ret;

    
    ret = hildon_time_editor_get_show_hours(HILDON_TIME_EDITOR(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_time_editor_set_duration_mode(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "duration_mode", NULL };
    int duration_mode;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonTimeEditor.set_duration_mode", kwlist, &duration_mode))
        return NULL;
    
    hildon_time_editor_set_duration_mode(HILDON_TIME_EDITOR(self->obj), duration_mode);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_time_editor_get_duration_mode(PyGObject *self)
{
    int ret;

    
    ret = hildon_time_editor_get_duration_mode(HILDON_TIME_EDITOR(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_time_editor_set_duration_min(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "duration_min", NULL };
    PyObject *py_duration_min = NULL;
    guint duration_min = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonTimeEditor.set_duration_min", kwlist, &py_duration_min))
        return NULL;
    if (py_duration_min) {
        if (PyLong_Check(py_duration_min))
            duration_min = PyLong_AsUnsignedLong(py_duration_min);
        else if (PyInt_Check(py_duration_min))
            duration_min = PyInt_AsLong(py_duration_min);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'duration_min' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_time_editor_set_duration_min(HILDON_TIME_EDITOR(self->obj), duration_min);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_time_editor_get_duration_min(PyGObject *self)
{
    guint ret;

    
    ret = hildon_time_editor_get_duration_min(HILDON_TIME_EDITOR(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static PyObject *
_wrap_hildon_time_editor_set_duration_max(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "duration_max", NULL };
    PyObject *py_duration_max = NULL;
    guint duration_max = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonTimeEditor.set_duration_max", kwlist, &py_duration_max))
        return NULL;
    if (py_duration_max) {
        if (PyLong_Check(py_duration_max))
            duration_max = PyLong_AsUnsignedLong(py_duration_max);
        else if (PyInt_Check(py_duration_max))
            duration_max = PyInt_AsLong(py_duration_max);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'duration_max' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_time_editor_set_duration_max(HILDON_TIME_EDITOR(self->obj), duration_max);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_time_editor_get_duration_max(PyGObject *self)
{
    guint ret;

    
    ret = hildon_time_editor_get_duration_max(HILDON_TIME_EDITOR(self->obj));
    
    return PyLong_FromUnsignedLong(ret);
}

static const PyMethodDef _PyHildonTimeEditor_methods[] = {
    { "set_time", (PyCFunction)_wrap_hildon_time_editor_set_time, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_time", (PyCFunction)_wrap_hildon_time_editor_get_time, METH_NOARGS,
      NULL },
    { "set_duration_range", (PyCFunction)_wrap_hildon_time_editor_set_duration_range, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_duration_range", (PyCFunction)_wrap_hildon_time_editor_get_duration_range, METH_NOARGS,
      NULL },
    { "set_ticks", (PyCFunction)_wrap_hildon_time_editor_set_ticks, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_ticks", (PyCFunction)_wrap_hildon_time_editor_get_ticks, METH_NOARGS,
      NULL },
    { "set_show_seconds", (PyCFunction)_wrap_hildon_time_editor_set_show_seconds, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_show_seconds", (PyCFunction)_wrap_hildon_time_editor_get_show_seconds, METH_NOARGS,
      NULL },
    { "set_show_hours", (PyCFunction)_wrap_hildon_time_editor_set_show_hours, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_show_hours", (PyCFunction)_wrap_hildon_time_editor_get_show_hours, METH_NOARGS,
      NULL },
    { "set_duration_mode", (PyCFunction)_wrap_hildon_time_editor_set_duration_mode, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_duration_mode", (PyCFunction)_wrap_hildon_time_editor_get_duration_mode, METH_NOARGS,
      NULL },
    { "set_duration_min", (PyCFunction)_wrap_hildon_time_editor_set_duration_min, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_duration_min", (PyCFunction)_wrap_hildon_time_editor_get_duration_min, METH_NOARGS,
      NULL },
    { "set_duration_max", (PyCFunction)_wrap_hildon_time_editor_set_duration_max, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_duration_max", (PyCFunction)_wrap_hildon_time_editor_get_duration_max, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonTimeEditor_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.TimeEditor",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonTimeEditor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_time_editor_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonTimePicker ----------- */

static int
_wrap_hildon_time_picker_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", NULL };
    PyGObject *parent;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonTimePicker.__init__", kwlist, &PyGtkWindow_Type, &parent))
        return -1;
    self->obj = (GObject *)hildon_time_picker_new(GTK_WINDOW(parent->obj));

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonTimePicker object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_time_picker_set_time(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "hours", "minutes", NULL };
    PyObject *py_hours = NULL, *py_minutes = NULL;
    guint hours = 0, minutes = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:HildonTimePicker.set_time", kwlist, &py_hours, &py_minutes))
        return NULL;
    if (py_hours) {
        if (PyLong_Check(py_hours))
            hours = PyLong_AsUnsignedLong(py_hours);
        else if (PyInt_Check(py_hours))
            hours = PyInt_AsLong(py_hours);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'hours' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    if (py_minutes) {
        if (PyLong_Check(py_minutes))
            minutes = PyLong_AsUnsignedLong(py_minutes);
        else if (PyInt_Check(py_minutes))
            minutes = PyInt_AsLong(py_minutes);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'minutes' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    hildon_time_picker_set_time(HILDON_TIME_PICKER(self->obj), hours, minutes);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 126 "hildon.override"
static PyObject *
_wrap_hildon_time_picker_get_time (PyGObject *self)
{
   int hours, minutes;

   hildon_time_picker_get_time(HILDON_TIME_PICKER(self->obj), &hours, &minutes);
 
   return Py_BuildValue("(ii)", hours, minutes);
}

#line 4623 "hildon.c"


static const PyMethodDef _PyHildonTimePicker_methods[] = {
    { "set_time", (PyCFunction)_wrap_hildon_time_picker_set_time, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_time", (PyCFunction)_wrap_hildon_time_picker_get_time, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonTimePicker_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.TimePicker",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonTimePicker_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_time_picker_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonVolumebarRange ----------- */

static int
_wrap_hildon_volumebar_range_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "orientation", NULL };
    GtkOrientation orientation;
    PyObject *py_orientation = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonVolumebarRange.__init__", kwlist, &py_orientation))
        return -1;
    if (pyg_enum_get_value(GTK_TYPE_ORIENTATION, py_orientation, (gpointer)&orientation))
        return -1;
    self->obj = (GObject *)hildon_volumebar_range_new(orientation);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonVolumebarRange object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_volumebar_range_get_level(PyGObject *self)
{
    double ret;

    
    ret = hildon_volumebar_range_get_level(HILDON_VOLUMEBAR_RANGE(self->obj));
    
    return PyFloat_FromDouble(ret);
}

static PyObject *
_wrap_hildon_volumebar_range_set_level(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "level", NULL };
    double level;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"d:HildonVolumebarRange.set_level", kwlist, &level))
        return NULL;
    
    hildon_volumebar_range_set_level(HILDON_VOLUMEBAR_RANGE(self->obj), level);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonVolumebarRange_methods[] = {
    { "get_level", (PyCFunction)_wrap_hildon_volumebar_range_get_level, METH_NOARGS,
      NULL },
    { "set_level", (PyCFunction)_wrap_hildon_volumebar_range_set_level, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonVolumebarRange_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.VolumebarRange",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonVolumebarRange_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_volumebar_range_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonVVolumebar ----------- */

PyTypeObject G_GNUC_INTERNAL PyHildonVVolumebar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.VVolumebar",                   /* tp_name */
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



/* ----------- HildonWeekdayPicker ----------- */

static int
_wrap_hildon_weekday_picker_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.WeekdayPicker.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.WeekdayPicker object");
        return -1;
    }
    return 0;
}

#line 361 "hildon.override"
static PyObject *
_wrap_hildon_weekday_picker_set_day(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "day", NULL };
    PyObject *py_day = NULL;
    GDateWeekday day;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:HildonWeekdayPicker.set_day", kwlist, &py_day))
        return NULL;
    /* void * */
    if (pyg_enum_get_value(HILDON_TYPE_DATE_WEEKDAY, py_day, (gint *)(void *)&day))
        return NULL;
    hildon_weekday_picker_set_day(HILDON_WEEKDAY_PICKER(self->obj), day);
    Py_INCREF(Py_None);
    return Py_None;
}

#line 4874 "hildon.c"


#line 380 "hildon.override"
static PyObject *
_wrap_hildon_weekday_picker_unset_day(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "day", NULL };
    PyObject *py_day = NULL;
    GDateWeekday day;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:HildonWeekdayPicker.unset_day", kwlist, &py_day))
        return NULL;
    /* void * */
    if (pyg_enum_get_value(HILDON_TYPE_DATE_WEEKDAY, py_day, (gint *)(void *)&day))
        return NULL;
    hildon_weekday_picker_unset_day(HILDON_WEEKDAY_PICKER(self->obj), day);
    Py_INCREF(Py_None);
    return Py_None;
}

#line 4895 "hildon.c"


#line 399 "hildon.override"
static PyObject *
_wrap_hildon_weekday_picker_toggle_day(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "day", NULL };
    PyObject *py_day = NULL;
    GDateWeekday day;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:HildonWeekdayPicker.toggle_day", kwlist, &py_day))
        return NULL;
    /* void * */
    if (pyg_enum_get_value(HILDON_TYPE_DATE_WEEKDAY, py_day, (gint *)(void *)&day))
        return NULL;
    hildon_weekday_picker_toggle_day(HILDON_WEEKDAY_PICKER(self->obj), day);
    Py_INCREF(Py_None);
    return Py_None;
}

#line 4916 "hildon.c"


static PyObject *
_wrap_hildon_weekday_picker_set_all(PyGObject *self)
{
    
    hildon_weekday_picker_set_all(HILDON_WEEKDAY_PICKER(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_weekday_picker_unset_all(PyGObject *self)
{
    
    hildon_weekday_picker_unset_all(HILDON_WEEKDAY_PICKER(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 418 "hildon.override"
static PyObject *
_wrap_hildon_weekday_picker_isset_day(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "day", NULL };
    PyObject *py_day = NULL;
    int ret;
    GDateWeekday day;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O:HildonWeekdayPicker.isset_day", kwlist, &py_day))
        return NULL;
    /* void * */
    if (pyg_enum_get_value(HILDON_TYPE_DATE_WEEKDAY, py_day, (gint *)(void *)&day))
        return NULL;
    ret = hildon_weekday_picker_isset_day(HILDON_WEEKDAY_PICKER(self->obj), day);
    return PyBool_FromLong(ret);

}

#line 4958 "hildon.c"


static const PyMethodDef _PyHildonWeekdayPicker_methods[] = {
    { "set_day", (PyCFunction)_wrap_hildon_weekday_picker_set_day, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unset_day", (PyCFunction)_wrap_hildon_weekday_picker_unset_day, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "toggle_day", (PyCFunction)_wrap_hildon_weekday_picker_toggle_day, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_all", (PyCFunction)_wrap_hildon_weekday_picker_set_all, METH_NOARGS,
      NULL },
    { "unset_all", (PyCFunction)_wrap_hildon_weekday_picker_unset_all, METH_NOARGS,
      NULL },
    { "isset_day", (PyCFunction)_wrap_hildon_weekday_picker_isset_day, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonWeekdayPicker_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.WeekdayPicker",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonWeekdayPicker_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_weekday_picker_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonWindow ----------- */

static int
_wrap_hildon_window_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":hildon.Window.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create hildon.Window object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_hildon_window_add_with_scrollbar(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "child", NULL };
    PyGObject *child;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonWindow.add_with_scrollbar", kwlist, &PyGtkWidget_Type, &child))
        return NULL;
    
    hildon_window_add_with_scrollbar(HILDON_WINDOW(self->obj), GTK_WIDGET(child->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_window_get_menu(PyGObject *self)
{
    GtkMenu *ret;

    
    ret = hildon_window_get_menu(HILDON_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_window_set_menu(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "menu", NULL };
    PyGObject *menu;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonWindow.set_menu", kwlist, &PyGtkMenu_Type, &menu))
        return NULL;
    
    hildon_window_set_menu(HILDON_WINDOW(self->obj), GTK_MENU(menu->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_window_add_toolbar(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "toolbar", NULL };
    PyGObject *toolbar;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonWindow.add_toolbar", kwlist, &PyGtkToolbar_Type, &toolbar))
        return NULL;
    
    hildon_window_add_toolbar(HILDON_WINDOW(self->obj), GTK_TOOLBAR(toolbar->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_window_remove_toolbar(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "toolbar", NULL };
    PyGObject *toolbar;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonWindow.remove_toolbar", kwlist, &PyGtkToolbar_Type, &toolbar))
        return NULL;
    
    hildon_window_remove_toolbar(HILDON_WINDOW(self->obj), GTK_TOOLBAR(toolbar->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_window_get_is_topmost(PyGObject *self)
{
    int ret;

    
    ret = hildon_window_get_is_topmost(HILDON_WINDOW(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyHildonWindow_methods[] = {
    { "add_with_scrollbar", (PyCFunction)_wrap_hildon_window_add_with_scrollbar, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_menu", (PyCFunction)_wrap_hildon_window_get_menu, METH_NOARGS,
      NULL },
    { "set_menu", (PyCFunction)_wrap_hildon_window_set_menu, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "add_toolbar", (PyCFunction)_wrap_hildon_window_add_toolbar, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "remove_toolbar", (PyCFunction)_wrap_hildon_window_remove_toolbar, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_is_topmost", (PyCFunction)_wrap_hildon_window_get_is_topmost, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonWindow_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.Window",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonWindow_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_window_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonWizardDialog ----------- */

#line 138 "hildon.override"
static int
_wrap_hildon_wizard_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "wizard_name", "notebook", NULL };
    PyGObject *parent, *notebook;
    char *wizard_name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OsO!:HildonWizardDialog.__init__", kwlist, &parent, &wizard_name, &PyGtkNotebook_Type, &notebook))
        return -1;
    if (parent == Py_None)
        self->obj = (GObject *)hildon_wizard_dialog_new(NULL, wizard_name, GTK_NOTEBOOK(notebook->obj));
    else if (PyObject_TypeCheck(parent, &PyGtkWindow_Type))
        self->obj = (GObject *)hildon_wizard_dialog_new(GTK_WINDOW(parent->obj), wizard_name, GTK_NOTEBOOK(notebook->obj));
    else
        return -1;

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonWizardDialog object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

#line 5220 "hildon.c"


PyTypeObject G_GNUC_INTERNAL PyHildonWizardDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.WizardDialog",                   /* tp_name */
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
    (initproc)_wrap_hildon_wizard_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonFileChooserDialog ----------- */

#line 181 "hildon.override"
static int
_wrap_hildon_file_chooser_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "action", NULL };
    PyGObject *parent;
    PyObject *py_action = NULL;
    GtkFileChooserAction action;
    PyGILState_STATE state;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O:HildonFileChooserDialog.__init__", kwlist, &PyGtkWindow_Type, &parent, &py_action))
        return -1;
    /* void * */
    if (pyg_enum_get_value(GTK_TYPE_FILE_CHOOSER_ACTION, py_action, (gint *)(void *)&action))
        return -1;
    self->obj = (GObject *)hildon_file_chooser_dialog_new(GTK_WINDOW(parent->obj), action);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonFileChooserDialog object");
        return -1;
    }

    state = pyg_gil_state_ensure();
    g_object_ref(self->obj); /* we don't own the first reference of windows */
    pyg_gil_state_release(state);

    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

#line 5302 "hildon.c"


static PyObject *
_wrap_hildon_file_chooser_dialog_focus_to_input(PyGObject *self)
{
    
    hildon_file_chooser_dialog_focus_to_input(HILDON_FILE_CHOOSER_DIALOG(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_chooser_dialog_set_safe_folder(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "local_path", NULL };
    char *local_path;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFileChooserDialog.set_safe_folder", kwlist, &local_path))
        return NULL;
    
    hildon_file_chooser_dialog_set_safe_folder(HILDON_FILE_CHOOSER_DIALOG(self->obj), local_path);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_chooser_dialog_set_safe_folder_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFileChooserDialog.set_safe_folder_uri", kwlist, &uri))
        return NULL;
    
    hildon_file_chooser_dialog_set_safe_folder_uri(HILDON_FILE_CHOOSER_DIALOG(self->obj), uri);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_chooser_dialog_get_safe_folder(PyGObject *self)
{
    gchar *ret;

    
    ret = hildon_file_chooser_dialog_get_safe_folder(HILDON_FILE_CHOOSER_DIALOG(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_chooser_dialog_get_safe_folder_uri(PyGObject *self)
{
    gchar *ret;

    
    ret = hildon_file_chooser_dialog_get_safe_folder_uri(HILDON_FILE_CHOOSER_DIALOG(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_chooser_dialog_set_show_upnp(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "value", NULL };
    int value;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonFileChooserDialog.set_show_upnp", kwlist, &value))
        return NULL;
    
    hildon_file_chooser_dialog_set_show_upnp(HILDON_FILE_CHOOSER_DIALOG(self->obj), value);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_chooser_dialog_get_show_upnp(PyGObject *self)
{
    int ret;

    
    ret = hildon_file_chooser_dialog_get_show_upnp(HILDON_FILE_CHOOSER_DIALOG(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_chooser_dialog_add_extra(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", NULL };
    PyGObject *widget;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonFileChooserDialog.add_extra", kwlist, &PyGtkWidget_Type, &widget))
        return NULL;
    
    hildon_file_chooser_dialog_add_extra(HILDON_FILE_CHOOSER_DIALOG(self->obj), GTK_WIDGET(widget->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_chooser_dialog_get_extension(PyGObject *self)
{
    gchar *ret;

    
    ret = hildon_file_chooser_dialog_get_extension(HILDON_FILE_CHOOSER_DIALOG(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_chooser_dialog_set_extension(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "extension", NULL };
    char *extension;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFileChooserDialog.set_extension", kwlist, &extension))
        return NULL;
    
    hildon_file_chooser_dialog_set_extension(HILDON_FILE_CHOOSER_DIALOG(self->obj), extension);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonFileChooserDialog_methods[] = {
    { "focus_to_input", (PyCFunction)_wrap_hildon_file_chooser_dialog_focus_to_input, METH_NOARGS,
      NULL },
    { "set_safe_folder", (PyCFunction)_wrap_hildon_file_chooser_dialog_set_safe_folder, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_safe_folder_uri", (PyCFunction)_wrap_hildon_file_chooser_dialog_set_safe_folder_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_safe_folder", (PyCFunction)_wrap_hildon_file_chooser_dialog_get_safe_folder, METH_NOARGS,
      NULL },
    { "get_safe_folder_uri", (PyCFunction)_wrap_hildon_file_chooser_dialog_get_safe_folder_uri, METH_NOARGS,
      NULL },
    { "set_show_upnp", (PyCFunction)_wrap_hildon_file_chooser_dialog_set_show_upnp, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_show_upnp", (PyCFunction)_wrap_hildon_file_chooser_dialog_get_show_upnp, METH_NOARGS,
      NULL },
    { "add_extra", (PyCFunction)_wrap_hildon_file_chooser_dialog_add_extra, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_extension", (PyCFunction)_wrap_hildon_file_chooser_dialog_get_extension, METH_NOARGS,
      NULL },
    { "set_extension", (PyCFunction)_wrap_hildon_file_chooser_dialog_set_extension, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonFileChooserDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.FileChooserDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonFileChooserDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_file_chooser_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonFileDetailsDialog ----------- */

static int
_wrap_hildon_file_details_dialog_new_with_model(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "model", NULL };
    PyGObject *parent, *model;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!O!:HildonFileDetailsDialog.__init__", kwlist, &PyGtkWindow_Type, &parent, &PyHildonFileSystemModel_Type, &model))
        return -1;
    self->obj = (GObject *)hildon_file_details_dialog_new_with_model(GTK_WINDOW(parent->obj), HILDON_FILE_SYSTEM_MODEL(model->obj));

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonFileDetailsDialog object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_hildon_file_details_dialog_set_file_iter(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "iter", NULL };
    PyObject *py_iter;
    GtkTreeIter *iter = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileDetailsDialog.set_file_iter", kwlist, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    hildon_file_details_dialog_set_file_iter(HILDON_FILE_DETAILS_DIALOG(self->obj), iter);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_details_dialog_get_file_iter(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "iter", NULL };
    PyObject *py_iter;
    GtkTreeIter *iter = NULL;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileDetailsDialog.get_file_iter", kwlist, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_details_dialog_get_file_iter(HILDON_FILE_DETAILS_DIALOG(self->obj), iter);
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyHildonFileDetailsDialog_methods[] = {
    { "set_file_iter", (PyCFunction)_wrap_hildon_file_details_dialog_set_file_iter, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_file_iter", (PyCFunction)_wrap_hildon_file_details_dialog_get_file_iter, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonFileDetailsDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.FileDetailsDialog",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonFileDetailsDialog_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_hildon_file_details_dialog_new_with_model,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- HildonFileSelection ----------- */

static PyObject *
_wrap_hildon_file_selection_set_mode(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "mode", NULL };
    HildonFileSelectionMode mode;
    PyObject *py_mode = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileSelection.set_mode", kwlist, &py_mode))
        return NULL;
    if (pyg_enum_get_value(HILDON_TYPE_FILE_SELECTION_MODE, py_mode, (gpointer)&mode))
        return NULL;
    
    hildon_file_selection_set_mode(HILDON_FILE_SELECTION(self->obj), mode);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_get_mode(PyGObject *self)
{
    gint ret;

    
    ret = hildon_file_selection_get_mode(HILDON_FILE_SELECTION(self->obj));
    
    return pyg_enum_from_gtype(HILDON_TYPE_FILE_SELECTION_MODE, ret);
}

static PyObject *
_wrap_hildon_file_selection_set_sort_key(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", "order", NULL };
    PyObject *py_key = NULL, *py_order = NULL;
    HildonFileSelectionSortKey key;
    GtkSortType order;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:HildonFileSelection.set_sort_key", kwlist, &py_key, &py_order))
        return NULL;
    if (pyg_enum_get_value(HILDON_TYPE_FILE_SELECTION_SORT_KEY, py_key, (gpointer)&key))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_SORT_TYPE, py_order, (gpointer)&order))
        return NULL;
    
    hildon_file_selection_set_sort_key(HILDON_FILE_SELECTION(self->obj), key, order);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_set_current_folder_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "folder", NULL };
    char *folder;
    int ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFileSelection.set_current_folder_uri", kwlist, &folder))
        return NULL;
    
    ret = hildon_file_selection_set_current_folder_uri(HILDON_FILE_SELECTION(self->obj), folder, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_get_current_folder_uri(PyGObject *self)
{
    gchar *ret;

    
    ret = hildon_file_selection_get_current_folder_uri(HILDON_FILE_SELECTION(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_get_current_content_iter(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "iter", NULL };
    PyObject *py_iter;
    GtkTreeIter *iter = NULL;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileSelection.get_current_content_iter", kwlist, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_selection_get_current_content_iter(HILDON_FILE_SELECTION(self->obj), iter);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_get_current_folder_iter(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "iter", NULL };
    PyObject *py_iter;
    GtkTreeIter *iter = NULL;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileSelection.get_current_folder_iter", kwlist, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_selection_get_current_folder_iter(HILDON_FILE_SELECTION(self->obj), iter);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_get_active_content_iter(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "iter", NULL };
    PyObject *py_iter;
    GtkTreeIter *iter = NULL;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileSelection.get_active_content_iter", kwlist, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_selection_get_active_content_iter(HILDON_FILE_SELECTION(self->obj), iter);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_content_iter_is_selected(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "iter", NULL };
    PyObject *py_iter;
    GtkTreeIter *iter = NULL;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileSelection.content_iter_is_selected", kwlist, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_selection_content_iter_is_selected(HILDON_FILE_SELECTION(self->obj), iter);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_select_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;
    int ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFileSelection.select_uri", kwlist, &uri))
        return NULL;
    
    ret = hildon_file_selection_select_uri(HILDON_FILE_SELECTION(self->obj), uri, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_unselect_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFileSelection.unselect_uri", kwlist, &uri))
        return NULL;
    
    hildon_file_selection_unselect_uri(HILDON_FILE_SELECTION(self->obj), uri);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_select_all(PyGObject *self)
{
    
    hildon_file_selection_select_all(HILDON_FILE_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_unselect_all(PyGObject *self)
{
    
    hildon_file_selection_unselect_all(HILDON_FILE_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_clear_multi_selection(PyGObject *self)
{
    
    hildon_file_selection_clear_multi_selection(HILDON_FILE_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_set_select_multiple(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "select_multiple", NULL };
    int select_multiple;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonFileSelection.set_select_multiple", kwlist, &select_multiple))
        return NULL;
    
    hildon_file_selection_set_select_multiple(HILDON_FILE_SELECTION(self->obj), select_multiple);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_get_select_multiple(PyGObject *self)
{
    int ret;

    
    ret = hildon_file_selection_get_select_multiple(HILDON_FILE_SELECTION(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_set_column_headers_visible(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "visible", NULL };
    int visible;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:HildonFileSelection.set_column_headers_visible", kwlist, &visible))
        return NULL;
    
    hildon_file_selection_set_column_headers_visible(HILDON_FILE_SELECTION(self->obj), visible);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_get_column_headers_visible(PyGObject *self)
{
    int ret;

    
    ret = hildon_file_selection_get_column_headers_visible(HILDON_FILE_SELECTION(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_set_filter(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "filter", NULL };
    PyGObject *filter;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:HildonFileSelection.set_filter", kwlist, &PyGtkFileFilter_Type, &filter))
        return NULL;
    
    hildon_file_selection_set_filter(HILDON_FILE_SELECTION(self->obj), GTK_FILE_FILTER(filter->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_get_filter(PyGObject *self)
{
    GtkFileFilter *ret;

    
    ret = hildon_file_selection_get_filter(HILDON_FILE_SELECTION(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_file_selection_dim_current_selection(PyGObject *self)
{
    
    hildon_file_selection_dim_current_selection(HILDON_FILE_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_undim_all(PyGObject *self)
{
    
    hildon_file_selection_undim_all(HILDON_FILE_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_get_active_pane(PyGObject *self)
{
    gint ret;

    
    ret = hildon_file_selection_get_active_pane(HILDON_FILE_SELECTION(self->obj));
    
    return pyg_enum_from_gtype(HILDON_TYPE_FILE_SELECTION_PANE, ret);
}

static PyObject *
_wrap_hildon_file_selection_hide_content_pane(PyGObject *self)
{
    
    hildon_file_selection_hide_content_pane(HILDON_FILE_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_show_content_pane(PyGObject *self)
{
    
    hildon_file_selection_show_content_pane(HILDON_FILE_SELECTION(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_move_cursor_to_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFileSelection.move_cursor_to_uri", kwlist, &uri))
        return NULL;
    
    hildon_file_selection_move_cursor_to_uri(HILDON_FILE_SELECTION(self->obj), uri);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_set_current_folder(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "folder", NULL };
    PyObject *py_folder;
    int ret;
    GtkFilePath *folder = NULL;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileSelection.set_current_folder", kwlist, &py_folder))
        return NULL;
    if (pyg_boxed_check(py_folder, GTK_TYPE_FILE_PATH))
        folder = pyg_boxed_get(py_folder, GtkFilePath);
    else {
        PyErr_SetString(PyExc_TypeError, "folder should be a GtkFilePath");
        return NULL;
    }
    
    ret = hildon_file_selection_set_current_folder(HILDON_FILE_SELECTION(self->obj), folder, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_get_current_folder(PyGObject *self)
{
    GtkFilePath *ret;

    
    ret = hildon_file_selection_get_current_folder(HILDON_FILE_SELECTION(self->obj));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(GTK_TYPE_FILE_PATH, ret, TRUE, TRUE);
}

static PyObject *
_wrap_hildon_file_selection_select_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", NULL };
    PyObject *py_path;
    int ret;
    GtkFilePath *path = NULL;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileSelection.select_path", kwlist, &py_path))
        return NULL;
    if (pyg_boxed_check(py_path, GTK_TYPE_FILE_PATH))
        path = pyg_boxed_get(py_path, GtkFilePath);
    else {
        PyErr_SetString(PyExc_TypeError, "path should be a GtkFilePath");
        return NULL;
    }
    
    ret = hildon_file_selection_select_path(HILDON_FILE_SELECTION(self->obj), path, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_selection_unselect_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", NULL };
    PyObject *py_path;
    GtkFilePath *path = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:HildonFileSelection.unselect_path", kwlist, &py_path))
        return NULL;
    if (pyg_boxed_check(py_path, GTK_TYPE_FILE_PATH))
        path = pyg_boxed_get(py_path, GtkFilePath);
    else {
        PyErr_SetString(PyExc_TypeError, "path should be a GtkFilePath");
        return NULL;
    }
    
    hildon_file_selection_unselect_path(HILDON_FILE_SELECTION(self->obj), path);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonFileSelection_methods[] = {
    { "set_mode", (PyCFunction)_wrap_hildon_file_selection_set_mode, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_mode", (PyCFunction)_wrap_hildon_file_selection_get_mode, METH_NOARGS,
      NULL },
    { "set_sort_key", (PyCFunction)_wrap_hildon_file_selection_set_sort_key, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_current_folder_uri", (PyCFunction)_wrap_hildon_file_selection_set_current_folder_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_current_folder_uri", (PyCFunction)_wrap_hildon_file_selection_get_current_folder_uri, METH_NOARGS,
      NULL },
    { "get_current_content_iter", (PyCFunction)_wrap_hildon_file_selection_get_current_content_iter, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_current_folder_iter", (PyCFunction)_wrap_hildon_file_selection_get_current_folder_iter, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active_content_iter", (PyCFunction)_wrap_hildon_file_selection_get_active_content_iter, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "content_iter_is_selected", (PyCFunction)_wrap_hildon_file_selection_content_iter_is_selected, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "select_uri", (PyCFunction)_wrap_hildon_file_selection_select_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unselect_uri", (PyCFunction)_wrap_hildon_file_selection_unselect_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "select_all", (PyCFunction)_wrap_hildon_file_selection_select_all, METH_NOARGS,
      NULL },
    { "unselect_all", (PyCFunction)_wrap_hildon_file_selection_unselect_all, METH_NOARGS,
      NULL },
    { "clear_multi_selection", (PyCFunction)_wrap_hildon_file_selection_clear_multi_selection, METH_NOARGS,
      NULL },
    { "set_select_multiple", (PyCFunction)_wrap_hildon_file_selection_set_select_multiple, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_select_multiple", (PyCFunction)_wrap_hildon_file_selection_get_select_multiple, METH_NOARGS,
      NULL },
    { "set_column_headers_visible", (PyCFunction)_wrap_hildon_file_selection_set_column_headers_visible, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_column_headers_visible", (PyCFunction)_wrap_hildon_file_selection_get_column_headers_visible, METH_NOARGS,
      NULL },
    { "set_filter", (PyCFunction)_wrap_hildon_file_selection_set_filter, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_filter", (PyCFunction)_wrap_hildon_file_selection_get_filter, METH_NOARGS,
      NULL },
    { "dim_current_selection", (PyCFunction)_wrap_hildon_file_selection_dim_current_selection, METH_NOARGS,
      NULL },
    { "undim_all", (PyCFunction)_wrap_hildon_file_selection_undim_all, METH_NOARGS,
      NULL },
    { "get_active_pane", (PyCFunction)_wrap_hildon_file_selection_get_active_pane, METH_NOARGS,
      NULL },
    { "hide_content_pane", (PyCFunction)_wrap_hildon_file_selection_hide_content_pane, METH_NOARGS,
      NULL },
    { "show_content_pane", (PyCFunction)_wrap_hildon_file_selection_show_content_pane, METH_NOARGS,
      NULL },
    { "move_cursor_to_uri", (PyCFunction)_wrap_hildon_file_selection_move_cursor_to_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_current_folder", (PyCFunction)_wrap_hildon_file_selection_set_current_folder, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_current_folder", (PyCFunction)_wrap_hildon_file_selection_get_current_folder, METH_NOARGS,
      NULL },
    { "select_path", (PyCFunction)_wrap_hildon_file_selection_select_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unselect_path", (PyCFunction)_wrap_hildon_file_selection_unselect_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonFileSelection_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.FileSelection",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonFileSelection_methods, /* tp_methods */
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



/* ----------- HildonFileSystemModel ----------- */

static PyObject *
_wrap_hildon_file_system_model_search_local_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", "iter", "start_iter", "recursive", NULL };
    char *path;
    GtkTreeIter *iter = NULL, *start_iter = NULL;
    int recursive, ret;
    PyObject *py_iter, *py_start_iter;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sOOi:HildonFileSystemModel.search_local_path", kwlist, &path, &py_iter, &py_start_iter, &recursive))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    if (pyg_boxed_check(py_start_iter, GTK_TYPE_TREE_ITER))
        start_iter = pyg_boxed_get(py_start_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "start_iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_system_model_search_local_path(HILDON_FILE_SYSTEM_MODEL(self->obj), path, iter, start_iter, recursive);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_system_model_search_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "iter", "start_iter", "recursive", NULL };
    char *uri;
    GtkTreeIter *iter = NULL, *start_iter = NULL;
    int recursive, ret;
    PyObject *py_iter, *py_start_iter;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sOOi:HildonFileSystemModel.search_uri", kwlist, &uri, &py_iter, &py_start_iter, &recursive))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    if (pyg_boxed_check(py_start_iter, GTK_TYPE_TREE_ITER))
        start_iter = pyg_boxed_get(py_start_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "start_iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_system_model_search_uri(HILDON_FILE_SYSTEM_MODEL(self->obj), uri, iter, start_iter, recursive);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_system_model_search_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", "iter", "start_iter", "recursive", NULL };
    PyObject *py_path, *py_iter, *py_start_iter;
    GtkTreeIter *iter = NULL, *start_iter = NULL;
    int recursive, ret;
    GtkFilePath *path = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOOi:HildonFileSystemModel.search_path", kwlist, &py_path, &py_iter, &py_start_iter, &recursive))
        return NULL;
    if (pyg_boxed_check(py_path, GTK_TYPE_FILE_PATH))
        path = pyg_boxed_get(py_path, GtkFilePath);
    else {
        PyErr_SetString(PyExc_TypeError, "path should be a GtkFilePath");
        return NULL;
    }
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    if (pyg_boxed_check(py_start_iter, GTK_TYPE_TREE_ITER))
        start_iter = pyg_boxed_get(py_start_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "start_iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_system_model_search_path(HILDON_FILE_SYSTEM_MODEL(self->obj), path, iter, start_iter, recursive);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_system_model_load_local_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", "iter", NULL };
    char *path;
    GtkTreeIter *iter = NULL;
    int ret;
    PyObject *py_iter;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:HildonFileSystemModel.load_local_path", kwlist, &path, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_system_model_load_local_path(HILDON_FILE_SYSTEM_MODEL(self->obj), path, iter);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_system_model_load_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "iter", NULL };
    char *uri;
    GtkTreeIter *iter = NULL;
    int ret;
    PyObject *py_iter;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:HildonFileSystemModel.load_uri", kwlist, &uri, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_system_model_load_uri(HILDON_FILE_SYSTEM_MODEL(self->obj), uri, iter);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_system_model_load_path(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "path", "iter", NULL };
    PyObject *py_path, *py_iter;
    GtkTreeIter *iter = NULL;
    int ret;
    GtkFilePath *path = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OO:HildonFileSystemModel.load_path", kwlist, &py_path, &py_iter))
        return NULL;
    if (pyg_boxed_check(py_path, GTK_TYPE_FILE_PATH))
        path = pyg_boxed_get(py_path, GtkFilePath);
    else {
        PyErr_SetString(PyExc_TypeError, "path should be a GtkFilePath");
        return NULL;
    }
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_system_model_load_path(HILDON_FILE_SYSTEM_MODEL(self->obj), path, iter);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_file_system_model_new_item(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "stub_name", "extension", NULL };
    PyObject *py_parent;
    GtkTreeIter *parent = NULL;
    char *stub_name, *extension;
    gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Oss:HildonFileSystemModel.new_item", kwlist, &py_parent, &stub_name, &extension))
        return NULL;
    if (pyg_boxed_check(py_parent, GTK_TYPE_TREE_ITER))
        parent = pyg_boxed_get(py_parent, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "parent should be a GtkTreeIter");
        return NULL;
    }
    
    ret = hildon_file_system_model_new_item(HILDON_FILE_SYSTEM_MODEL(self->obj), parent, stub_name, extension);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_system_model_autoname_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;
    gchar *ret;
    GError *error = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:HildonFileSystemModel.autoname_uri", kwlist, &uri))
        return NULL;
    
    ret = hildon_file_system_model_autoname_uri(HILDON_FILE_SYSTEM_MODEL(self->obj), uri, &error);
    
    if (pyg_error_check(&error))
        return NULL;
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_system_model_iter_available(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "iter", "available", NULL };
    PyObject *py_iter;
    GtkTreeIter *iter = NULL;
    int available;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"Oi:HildonFileSystemModel.iter_available", kwlist, &py_iter, &available))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TREE_ITER))
        iter = pyg_boxed_get(py_iter, GtkTreeIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTreeIter");
        return NULL;
    }
    
    hildon_file_system_model_iter_available(HILDON_FILE_SYSTEM_MODEL(self->obj), iter, available);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_system_model_reset_available(PyGObject *self)
{
    
    hildon_file_system_model_reset_available(HILDON_FILE_SYSTEM_MODEL(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyHildonFileSystemModel_methods[] = {
    { "search_local_path", (PyCFunction)_wrap_hildon_file_system_model_search_local_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "search_uri", (PyCFunction)_wrap_hildon_file_system_model_search_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "search_path", (PyCFunction)_wrap_hildon_file_system_model_search_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "load_local_path", (PyCFunction)_wrap_hildon_file_system_model_load_local_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "load_uri", (PyCFunction)_wrap_hildon_file_system_model_load_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "load_path", (PyCFunction)_wrap_hildon_file_system_model_load_path, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "new_item", (PyCFunction)_wrap_hildon_file_system_model_new_item, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "autoname_uri", (PyCFunction)_wrap_hildon_file_system_model_autoname_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "iter_available", (PyCFunction)_wrap_hildon_file_system_model_iter_available, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "reset_available", (PyCFunction)_wrap_hildon_file_system_model_reset_available, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyHildonFileSystemModel_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.FileSystemModel",                   /* tp_name */
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
    (struct PyMethodDef*)_PyHildonFileSystemModel_methods, /* tp_methods */
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



/* ----------- HildonFileSystemStorageDialog ----------- */

static int
_wrap_hildon_file_system_storage_dialog_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "uri_str", NULL };
    PyGObject *parent;
    char *uri_str;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!s:HildonFileSystemStorageDialog.__init__", kwlist, &PyGtkWindow_Type, &parent, &uri_str))
        return -1;
    self->obj = (GObject *)hildon_file_system_storage_dialog_new(GTK_WINDOW(parent->obj), uri_str);

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create HildonFileSystemStorageDialog object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyHildonFileSystemStorageDialog_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "hildon.FileSystemStorageDialog",                   /* tp_name */
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
    (initproc)_wrap_hildon_file_system_storage_dialog_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

static PyObject *
_wrap_hildon_banner_show_information(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", "icon_name", "text", NULL };
    PyGObject *widget;
    char *icon_name = NULL, *text;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!|zs:hildon_banner_show_information", kwlist, &PyGtkWidget_Type, &widget, &icon_name, &text))
        return NULL;
    
    ret = hildon_banner_show_information(GTK_WIDGET(widget->obj), icon_name, text);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_banner_show_information_with_markup(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", "icon_name", "markup", NULL };
    PyGObject *widget;
    char *icon_name = NULL, *markup;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!|zs:hildon_banner_show_information_with_markup", kwlist, &PyGtkWidget_Type, &widget, &icon_name, &markup))
        return NULL;
    
    ret = hildon_banner_show_information_with_markup(GTK_WIDGET(widget->obj), icon_name, markup);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_banner_show_animation(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", "animation_name", "text", NULL };
    PyGObject *widget;
    char *animation_name = NULL, *text;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!|zs:hildon_banner_show_animation", kwlist, &PyGtkWidget_Type, &widget, &animation_name, &text))
        return NULL;
    
    ret = hildon_banner_show_animation(GTK_WIDGET(widget->obj), animation_name, text);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_banner_show_progress(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", "bar", "text", NULL };
    PyGObject *widget, *py_bar = NULL;
    char *text;
    GtkProgressBar *bar = NULL;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!|Os:hildon_banner_show_progress", kwlist, &PyGtkWidget_Type, &widget, &py_bar, &text))
        return NULL;
    if ((PyObject *)py_bar == Py_None)
        bar = NULL;
    else if (py_bar && pygobject_check(py_bar, &PyGtkProgressBar_Type))
        bar = GTK_PROGRESS_BAR(py_bar->obj);
    else if (py_bar) {
        PyErr_SetString(PyExc_TypeError, "bar should be a GtkProgressBar or None");
        return NULL;
    }
    
    ret = hildon_banner_show_progress(GTK_WIDGET(widget->obj), (GtkProgressBar *) bar, text);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_color_button_new_with_color(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "color", NULL };
    PyObject *py_color;
    GdkColor *color = NULL;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:hildon_color_button_new_with_color", kwlist, &py_color))
        return NULL;
    if (pyg_boxed_check(py_color, GDK_TYPE_COLOR))
        color = pyg_boxed_get(py_color, GdkColor);
    else {
        PyErr_SetString(PyExc_TypeError, "color should be a GdkColor");
        return NULL;
    }
    
    ret = hildon_color_button_new_with_color(color);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_get_icon_pixel_size(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "size", NULL };
    PyObject *py_size = NULL;
    int ret;
    GtkIconSize size;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:hildon_get_icon_pixel_size", kwlist, &py_size))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_ICON_SIZE, py_size, (gpointer)&size))
        return NULL;
    
    ret = hildon_get_icon_pixel_size(size);
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_hildon_find_toolbar_new_with_model(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "label", "model", "column", NULL };
    char *label;
    PyGObject *model;
    int column;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO!i:hildon_find_toolbar_new_with_model", kwlist, &label, &PyGtkListStore_Type, &model, &column))
        return NULL;
    
    ret = hildon_find_toolbar_new_with_model(label, GTK_LIST_STORE(model->obj), column);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_get_password_dialog_new_with_default(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "password", "get_old", NULL };
    PyGObject *parent;
    char *password;
    int get_old;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!si:hildon_get_password_dialog_new_with_default", kwlist, &PyGtkWindow_Type, &parent, &password, &get_old))
        return NULL;
    
    ret = hildon_get_password_dialog_new_with_default(GTK_WINDOW(parent->obj), password, get_old);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_helper_set_logical_font(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", "logicalfontname", NULL };
    PyGObject *widget;
    char *logicalfontname;
    gulong ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!s:hildon_helper_set_logical_font", kwlist, &PyGtkWidget_Type, &widget, &logicalfontname))
        return NULL;
    
    ret = hildon_helper_set_logical_font(GTK_WIDGET(widget->obj), logicalfontname);
    
    return PyLong_FromUnsignedLong(ret);

}

static PyObject *
_wrap_hildon_helper_set_logical_color(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", "rcflags", "state", "logicalcolorname", NULL };
    GtkRcFlags rcflags;
    PyObject *py_rcflags = NULL, *py_state = NULL;
    gulong ret;
    char *logicalcolorname;
    PyGObject *widget;
    GtkStateType state;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!OOs:hildon_helper_set_logical_color", kwlist, &PyGtkWidget_Type, &widget, &py_rcflags, &py_state, &logicalcolorname))
        return NULL;
    if (pyg_flags_get_value(GTK_TYPE_RC_FLAGS, py_rcflags, (gpointer)&rcflags))
        return NULL;
    if (pyg_enum_get_value(GTK_TYPE_STATE_TYPE, py_state, (gpointer)&state))
        return NULL;
    
    ret = hildon_helper_set_logical_color(GTK_WIDGET(widget->obj), rcflags, state, logicalcolorname);
    
    return PyLong_FromUnsignedLong(ret);

}

static PyObject *
_wrap_hildon_helper_event_button_is_finger(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "event", NULL };
    GdkEvent *event = NULL;
    PyObject *py_event;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:hildon_helper_event_button_is_finger", kwlist, &py_event))
        return NULL;
    if (pyg_boxed_check(py_event, GDK_TYPE_EVENT))
        event = pyg_boxed_get(py_event, GdkEvent);
    else {
        PyErr_SetString(PyExc_TypeError, "event should be a GdkEvent");
        return NULL;
    }
    
    ret = hildon_helper_event_button_is_finger((GdkEventButton *)event);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_hildon_helper_set_insensitive_message(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", "message", NULL };
    PyGObject *widget;
    char *message;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!s:hildon_helper_set_insensitive_message", kwlist, &PyGtkWidget_Type, &widget, &message))
        return NULL;
    
    hildon_helper_set_insensitive_message(GTK_WIDGET(widget->obj), message);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_helper_set_thumb_scrollbar(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "win", "thumb", NULL };
    PyGObject *win;
    int thumb;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!i:hildon_helper_set_thumb_scrollbar", kwlist, &PyGtkScrolledWindow_Type, &win, &thumb))
        return NULL;
    
    hildon_helper_set_thumb_scrollbar(GTK_SCROLLED_WINDOW(win->obj), thumb);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_login_dialog_new_with_default(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "name", "password", NULL };
    PyGObject *parent;
    char *name, *password;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!ss:hildon_login_dialog_new_with_default", kwlist, &PyGtkWindow_Type, &parent, &name, &password))
        return NULL;
    
    ret = hildon_login_dialog_new_with_default(GTK_WINDOW(parent->obj), name, password);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_note_new_confirmation(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "description", NULL };
    PyGObject *parent;
    char *description;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!s:hildon_note_new_confirmation", kwlist, &PyGtkWindow_Type, &parent, &description))
        return NULL;
    
    ret = hildon_note_new_confirmation(GTK_WINDOW(parent->obj), description);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_note_new_confirmation_with_icon_name(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "description", "icon_name", NULL };
    PyGObject *parent;
    char *description, *icon_name;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!ss:hildon_note_new_confirmation_with_icon_name", kwlist, &PyGtkWindow_Type, &parent, &description, &icon_name))
        return NULL;
    
    ret = hildon_note_new_confirmation_with_icon_name(GTK_WINDOW(parent->obj), description, icon_name);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_note_new_cancel_with_progress_bar(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "description", "progressbar", NULL };
    PyGObject *parent, *progressbar;
    char *description;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!sO!:hildon_note_new_cancel_with_progress_bar", kwlist, &PyGtkWindow_Type, &parent, &description, &PyGtkProgressBar_Type, &progressbar))
        return NULL;
    
    ret = hildon_note_new_cancel_with_progress_bar(GTK_WINDOW(parent->obj), description, GTK_PROGRESS_BAR(progressbar->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_note_new_information(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "description", NULL };
    PyGObject *parent;
    char *description;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!s:hildon_note_new_information", kwlist, &PyGtkWindow_Type, &parent, &description))
        return NULL;
    
    ret = hildon_note_new_information(GTK_WINDOW(parent->obj), description);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_note_new_information_with_icon_name(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "description", "icon_name", NULL };
    PyGObject *parent;
    char *description, *icon_name;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!ss:hildon_note_new_information_with_icon_name", kwlist, &PyGtkWindow_Type, &parent, &description, &icon_name))
        return NULL;
    
    ret = hildon_note_new_information_with_icon_name(GTK_WINDOW(parent->obj), description, icon_name);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_program_get_instance(PyObject *self)
{
    HildonProgram *ret;

    
    ret = hildon_program_get_instance();
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_range_editor_new_with_separator(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "separator", NULL };
    char *separator;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:hildon_range_editor_new_with_separator", kwlist, &separator))
        return NULL;
    
    ret = hildon_range_editor_new_with_separator(separator);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_set_password_dialog_new_with_default(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "password", "modify_protection", NULL };
    PyGObject *parent;
    char *password;
    int modify_protection;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!si:hildon_set_password_dialog_new_with_default", kwlist, &PyGtkWindow_Type, &parent, &password, &modify_protection))
        return NULL;
    
    ret = hildon_set_password_dialog_new_with_default(GTK_WINDOW(parent->obj), password, modify_protection);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_play_system_sound(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "sample", NULL };
    char *sample;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:hildon_play_system_sound", kwlist, &sample))
        return NULL;
    
    hildon_play_system_sound(sample);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_time_editor_get_time_separators(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "hm_sep_label", "ms_sep_label", NULL };
    PyGObject *hm_sep_label, *ms_sep_label;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!O!:hildon_time_editor_get_time_separators", kwlist, &PyGtkLabel_Type, &hm_sep_label, &PyGtkLabel_Type, &ms_sep_label))
        return NULL;
    
    hildon_time_editor_get_time_separators(GTK_LABEL(hm_sep_label->obj), GTK_LABEL(ms_sep_label->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_hildon_file_selection_new_with_model(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "model", NULL };
    PyGObject *model;
    GtkWidget *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:hildon_file_selection_new_with_model", kwlist, &PyHildonFileSystemModel_Type, &model))
        return NULL;
    
    ret = hildon_file_selection_new_with_model(HILDON_FILE_SYSTEM_MODEL(model->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_file_system_create_backend(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "name", "use_fallback", NULL };
    char *name;
    int use_fallback;
    GtkFileSystem *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"si:hildon_file_system_create_backend", kwlist, &name, &use_fallback))
        return NULL;
    
    ret = hildon_file_system_create_backend(name, use_fallback);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_hildon_file_system_storage_dialog_set_uri(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "widget", "uri_str", NULL };
    PyGObject *widget;
    char *uri_str;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!s:hildon_file_system_storage_dialog_set_uri", kwlist, &PyGtkWidget_Type, &widget, &uri_str))
        return NULL;
    
    hildon_file_system_storage_dialog_set_uri(GTK_WIDGET(widget->obj), uri_str);
    
    Py_INCREF(Py_None);
    return Py_None;
}

const PyMethodDef pyhildon_functions[] = {
    { "hildon_banner_show_information", (PyCFunction)_wrap_hildon_banner_show_information, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_banner_show_information_with_markup", (PyCFunction)_wrap_hildon_banner_show_information_with_markup, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_banner_show_animation", (PyCFunction)_wrap_hildon_banner_show_animation, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_banner_show_progress", (PyCFunction)_wrap_hildon_banner_show_progress, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_color_button_new_with_color", (PyCFunction)_wrap_hildon_color_button_new_with_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_get_icon_pixel_size", (PyCFunction)_wrap_hildon_get_icon_pixel_size, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_find_toolbar_new_with_model", (PyCFunction)_wrap_hildon_find_toolbar_new_with_model, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_get_password_dialog_new_with_default", (PyCFunction)_wrap_hildon_get_password_dialog_new_with_default, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_helper_set_logical_font", (PyCFunction)_wrap_hildon_helper_set_logical_font, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_helper_set_logical_color", (PyCFunction)_wrap_hildon_helper_set_logical_color, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_helper_event_button_is_finger", (PyCFunction)_wrap_hildon_helper_event_button_is_finger, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_helper_set_insensitive_message", (PyCFunction)_wrap_hildon_helper_set_insensitive_message, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_helper_set_thumb_scrollbar", (PyCFunction)_wrap_hildon_helper_set_thumb_scrollbar, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_login_dialog_new_with_default", (PyCFunction)_wrap_hildon_login_dialog_new_with_default, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_note_new_confirmation", (PyCFunction)_wrap_hildon_note_new_confirmation, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_note_new_confirmation_with_icon_name", (PyCFunction)_wrap_hildon_note_new_confirmation_with_icon_name, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_note_new_cancel_with_progress_bar", (PyCFunction)_wrap_hildon_note_new_cancel_with_progress_bar, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_note_new_information", (PyCFunction)_wrap_hildon_note_new_information, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_note_new_information_with_icon_name", (PyCFunction)_wrap_hildon_note_new_information_with_icon_name, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_program_get_instance", (PyCFunction)_wrap_hildon_program_get_instance, METH_NOARGS,
      NULL },
    { "hildon_range_editor_new_with_separator", (PyCFunction)_wrap_hildon_range_editor_new_with_separator, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_set_password_dialog_new_with_default", (PyCFunction)_wrap_hildon_set_password_dialog_new_with_default, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_play_system_sound", (PyCFunction)_wrap_hildon_play_system_sound, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_time_editor_get_time_separators", (PyCFunction)_wrap_hildon_time_editor_get_time_separators, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_file_selection_new_with_model", (PyCFunction)_wrap_hildon_file_selection_new_with_model, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_file_system_create_backend", (PyCFunction)_wrap_hildon_file_system_create_backend, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "hildon_file_system_storage_dialog_set_uri", (PyCFunction)_wrap_hildon_file_system_storage_dialog_set_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
pyhildon_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_flags_add(module, "CalendarDisplayOptions", strip_prefix, HILDON_TYPE_CALENDAR_DISPLAY_OPTIONS);
  pyg_enum_add(module, "CaptionStatus", strip_prefix, HILDON_TYPE_CAPTION_STATUS);
  pyg_enum_add(module, "CaptionIconPosition", strip_prefix, HILDON_TYPE_CAPTION_ICON_POSITION);
  pyg_enum_add(module, "NoteType", strip_prefix, HILDON_TYPE_NOTE_TYPE);
  pyg_enum_add(module, "NumberEditorErrorType", strip_prefix, HILDON_TYPE_NUMBER_EDITOR_ERROR_TYPE);
  pyg_enum_add(module, "DateTimeError", strip_prefix, HILDON_TYPE_DATE_TIME_ERROR);
  pyg_enum_add(module, "WindowClipboardOperation", strip_prefix, HILDON_TYPE_WINDOW_CLIPBOARD_OPERATION);
  pyg_enum_add(module, "WizardDialogResponse", strip_prefix, HILDON_TYPE_WIZARD_DIALOG_RESPONSE);
  pyg_enum_add(module, "FileSelectionMode", strip_prefix, HILDON_TYPE_FILE_SELECTION_MODE);
  pyg_enum_add(module, "FileSelectionSortKey", strip_prefix, HILDON_TYPE_FILE_SELECTION_SORT_KEY);
  pyg_enum_add(module, "FileSelectionPane", strip_prefix, HILDON_TYPE_FILE_SELECTION_PANE);
  pyg_enum_add(module, "FileSelectionVisibleColumns", strip_prefix, HILDON_TYPE_FILE_SELECTION_VISIBLE_COLUMNS);
  pyg_enum_add(module, "FileSystemModelItemType", strip_prefix, HILDON_TYPE_FILE_SYSTEM_MODEL_ITEM_TYPE);
  pyg_enum_add(module, "FileSystemModelColumns", strip_prefix, HILDON_TYPE_FILE_SYSTEM_MODEL_COLUMNS);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
pyhildon_register_classes(PyObject *d)
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
    if ((module = PyImport_ImportModule("pango")) != NULL) {
        _PyPangoFontDescription_Type = (PyTypeObject *)PyObject_GetAttrString(module, "FontDescription");
        if (_PyPangoFontDescription_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name FontDescription from pango");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import pango");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkAdjustment_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Adjustment");
        if (_PyGtkAdjustment_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Adjustment from gtk");
            return ;
        }
        _PyGtkBin_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Bin");
        if (_PyGtkBin_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Bin from gtk");
            return ;
        }
        _PyGtkButton_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Button");
        if (_PyGtkButton_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Button from gtk");
            return ;
        }
        _PyGtkContainer_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Container");
        if (_PyGtkContainer_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Container from gtk");
            return ;
        }
        _PyGtkDialog_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Dialog");
        if (_PyGtkDialog_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Dialog from gtk");
            return ;
        }
        _PyGtkEventBox_Type = (PyTypeObject *)PyObject_GetAttrString(module, "EventBox");
        if (_PyGtkEventBox_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name EventBox from gtk");
            return ;
        }
        _PyGtkFileFilter_Type = (PyTypeObject *)PyObject_GetAttrString(module, "FileFilter");
        if (_PyGtkFileFilter_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name FileFilter from gtk");
            return ;
        }
        _PyGtkListStore_Type = (PyTypeObject *)PyObject_GetAttrString(module, "ListStore");
        if (_PyGtkListStore_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name ListStore from gtk");
            return ;
        }
        _PyGtkMenu_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Menu");
        if (_PyGtkMenu_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Menu from gtk");
            return ;
        }
        _PyGtkNotebook_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Notebook");
        if (_PyGtkNotebook_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Notebook from gtk");
            return ;
        }
        _PyGtkProgressBar_Type = (PyTypeObject *)PyObject_GetAttrString(module, "ProgressBar");
        if (_PyGtkProgressBar_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name ProgressBar from gtk");
            return ;
        }
        _PyGtkScale_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Scale");
        if (_PyGtkScale_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Scale from gtk");
            return ;
        }
        _PyGtkSizeGroup_Type = (PyTypeObject *)PyObject_GetAttrString(module, "SizeGroup");
        if (_PyGtkSizeGroup_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name SizeGroup from gtk");
            return ;
        }
        _PyGtkTextBuffer_Type = (PyTypeObject *)PyObject_GetAttrString(module, "TextBuffer");
        if (_PyGtkTextBuffer_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name TextBuffer from gtk");
            return ;
        }
        _PyGtkToolbar_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Toolbar");
        if (_PyGtkToolbar_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Toolbar from gtk");
            return ;
        }
        _PyGtkUIManager_Type = (PyTypeObject *)PyObject_GetAttrString(module, "UIManager");
        if (_PyGtkUIManager_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name UIManager from gtk");
            return ;
        }
        _PyGtkWindow_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Window");
        if (_PyGtkWindow_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Window from gtk");
            return ;
        }
        _PyGtkWidget_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Widget");
        if (_PyGtkWidget_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Widget from gtk");
            return ;
        }
        _PyGtkScrolledWindow_Type = (PyTypeObject *)PyObject_GetAttrString(module, "ScrolledWindow");
        if (_PyGtkScrolledWindow_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name ScrolledWindow from gtk");
            return ;
        }
        _PyGtkLabel_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Label");
        if (_PyGtkLabel_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Label from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }


#line 7356 "hildon.c"
    pygobject_register_class(d, "HildonBanner", HILDON_TYPE_BANNER, &PyHildonBanner_Type, Py_BuildValue("(O)", &PyGtkWindow_Type));
    pygobject_register_class(d, "HildonBreadCrumbTrail", HILDON_TYPE_BREAD_CRUMB_TRAIL, &PyHildonBreadCrumbTrail_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_BREAD_CRUMB_TRAIL);
    pygobject_register_class(d, "HildonBreadCrumb", HILDON_TYPE_BREAD_CRUMB, &PyHildonBreadCrumb_Type, NULL);
    pygobject_register_class(d, "HildonCalendarPopup", HILDON_TYPE_CALENDAR_POPUP, &PyHildonCalendarPopup_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonCalendar", HILDON_TYPE_CALENDAR, &PyHildonCalendar_Type, Py_BuildValue("(O)", &PyGtkWidget_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_CALENDAR);
    pygobject_register_class(d, "HildonCaption", HILDON_TYPE_CAPTION, &PyHildonCaption_Type, Py_BuildValue("(O)", &PyGtkEventBox_Type));
    pygobject_register_class(d, "HildonCodeDialog", HILDON_TYPE_CODE_DIALOG, &PyHildonCodeDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_CODE_DIALOG);
    pygobject_register_class(d, "HildonColorButton", HILDON_TYPE_COLOR_BUTTON, &PyHildonColorButton_Type, Py_BuildValue("(O)", &PyGtkButton_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_COLOR_BUTTON);
    pygobject_register_class(d, "HildonColorChooserDialog", HILDON_TYPE_COLOR_CHOOSER_DIALOG, &PyHildonColorChooserDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_COLOR_CHOOSER_DIALOG);
    pygobject_register_class(d, "HildonColorChooser", HILDON_TYPE_COLOR_CHOOSER, &PyHildonColorChooser_Type, Py_BuildValue("(O)", &PyGtkWidget_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_COLOR_CHOOSER);
    pygobject_register_class(d, "HildonControlbar", HILDON_TYPE_CONTROLBAR, &PyHildonControlbar_Type, Py_BuildValue("(O)", &PyGtkScale_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_CONTROLBAR);
    pygobject_register_class(d, "HildonDateEditor", HILDON_TYPE_DATE_EDITOR, &PyHildonDateEditor_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_DATE_EDITOR);
    pygobject_register_class(d, "HildonFindToolbar", HILDON_TYPE_FIND_TOOLBAR, &PyHildonFindToolbar_Type, Py_BuildValue("(O)", &PyGtkToolbar_Type));
    pygobject_register_class(d, "HildonFontSelectionDialog", HILDON_TYPE_FONT_SELECTION_DIALOG, &PyHildonFontSelectionDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonGetPasswordDialog", HILDON_TYPE_GET_PASSWORD_DIALOG, &PyHildonGetPasswordDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonLoginDialog", HILDON_TYPE_LOGIN_DIALOG, &PyHildonLoginDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonNote", HILDON_TYPE_NOTE, &PyHildonNote_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonNumberEditor", HILDON_TYPE_NUMBER_EDITOR, &PyHildonNumberEditor_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pygobject_register_class(d, "HildonProgram", HILDON_TYPE_PROGRAM, &PyHildonProgram_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_PROGRAM);
    pygobject_register_class(d, "HildonRangeEditor", HILDON_TYPE_RANGE_EDITOR, &PyHildonRangeEditor_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_RANGE_EDITOR);
    pygobject_register_class(d, "HildonSeekbar", HILDON_TYPE_SEEKBAR, &PyHildonSeekbar_Type, Py_BuildValue("(O)", &PyGtkScale_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_SEEKBAR);
    pygobject_register_class(d, "HildonSetPasswordDialog", HILDON_TYPE_SET_PASSWORD_DIALOG, &PyHildonSetPasswordDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonSortDialog", HILDON_TYPE_SORT_DIALOG, &PyHildonSortDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonTimeEditor", HILDON_TYPE_TIME_EDITOR, &PyHildonTimeEditor_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_TIME_EDITOR);
    pygobject_register_class(d, "HildonTimePicker", HILDON_TYPE_TIME_PICKER, &PyHildonTimePicker_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonVolumebarRange", HILDON_TYPE_VOLUMEBAR_RANGE, &PyHildonVolumebarRange_Type, Py_BuildValue("(O)", &PyGtkScale_Type));
    pygobject_register_class(d, "HildonVolumebar", HILDON_TYPE_VOLUMEBAR, &PyHildonVolumebar_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pygobject_register_class(d, "HildonHVolumebar", HILDON_TYPE_HVOLUMEBAR, &PyHildonHVolumebar_Type, Py_BuildValue("(O)", &PyHildonVolumebar_Type));
    pygobject_register_class(d, "HildonVVolumebar", HILDON_TYPE_VVOLUMEBAR, &PyHildonVVolumebar_Type, Py_BuildValue("(O)", &PyHildonVolumebar_Type));
    pygobject_register_class(d, "HildonWeekdayPicker", HILDON_TYPE_WEEKDAY_PICKER, &PyHildonWeekdayPicker_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_WEEKDAY_PICKER);
    pygobject_register_class(d, "HildonWindow", HILDON_TYPE_WINDOW, &PyHildonWindow_Type, Py_BuildValue("(O)", &PyGtkWindow_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_WINDOW);
    pygobject_register_class(d, "HildonWizardDialog", HILDON_TYPE_WIZARD_DIALOG, &PyHildonWizardDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonFileChooserDialog", HILDON_TYPE_FILE_CHOOSER_DIALOG, &PyHildonFileChooserDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonFileDetailsDialog", HILDON_TYPE_FILE_DETAILS_DIALOG, &PyHildonFileDetailsDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
    pygobject_register_class(d, "HildonFileSelection", HILDON_TYPE_FILE_SELECTION, &PyHildonFileSelection_Type, Py_BuildValue("(O)", &PyGtkContainer_Type));
    pygobject_register_class(d, "HildonFileSystemModel", HILDON_TYPE_FILE_SYSTEM_MODEL, &PyHildonFileSystemModel_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(HILDON_TYPE_FILE_SYSTEM_MODEL);
    pygobject_register_class(d, "HildonFileSystemStorageDialog", HILDON_TYPE_FILE_SYSTEM_STORAGE_DIALOG, &PyHildonFileSystemStorageDialog_Type, Py_BuildValue("(O)", &PyGtkDialog_Type));
}

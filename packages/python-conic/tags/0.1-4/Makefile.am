AUTOMAKE_OPTIONS=1.5

INCLUDES = $(PYTHON_INCLUDES) $(FOO_CFLAGS)

# conic module
pyexec_LTLIBRARIES = conicmodule.la
conicmodule_la_LDFLAGS = -module -avoid-version -export-symbols-regex initconic
conicmodule_la_LIBADD = $(ATK_LIBS)
conicmodule_la_SOURCES = conicmodule.c
nodist_conicmodule_la_SOURCES = conic.c
conic.c: conic.defs conic.override
CLEANFILES = conic.c
EXTRA_DIST = conic.override

.defs.c:
	(cd $(srcdir)\
		&& $(PYTHON) codegen/codegen.py \
		--override $*.override \
		--prefix py$* $*.defs) > gen-$*.c \
			&& cp gen-$*.c $*.c \
			&& rm -f gen-$*.c
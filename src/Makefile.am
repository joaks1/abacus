EXTRA_DIST = probability.c probability.h

bin_PROGRAMS = \
	eureject \
	intpart

if USE_GSL
bin_PROGRAMS += dpdraw
dpdraw_SOURCES = \
	dpdraw.c \
	dpdraw.h \
	dpdraw_main.c \
	array_utils.c \
	array_utils.h \
	partition_combinatorics.c \
	partition_combinatorics.h \
	partition_combinatorics_random.c \
	partition_combinatorics_random.h \
	abacus.c \
	abacus.h
dpdraw_LDADD = @GSL_LIBS@
dpdraw_CFLAGS = @GSL_CFLAGS@
endif

intpart_SOURCES = \
	intpart.c \
	intpart.h \
	intpart_main.c \
	array_utils.c \
	array_utils.h \
	partition_combinatorics.c \
	partition_combinatorics.h \
	abacus.c \
	abacus.h

intpart_LDADD = @MATHLDADD@

eureject_SOURCES = \
	eureject.c \
	eureject.h \
	eureject_main.c \
	array_utils.c \
	array_utils.h \
	math_utils.c \
	math_utils.h \
	stats_utils.c \
	stats_utils.h \
	parsing.c \
	parsing.h \
	abacus.c \
	abacus.h

eureject_LDADD = @MATHLDADD@


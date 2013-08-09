dist_noinst_DATA = \
	data/observed_stats_extra_line.txt \
	data/observed_stats.txt \
	data/test_parameter_stat_samples.txt \
	data/test_parameter_stat_samples.missing_cell.txt \
	data/test_parameter_stat_samples2.txt \
	data/test_parameter_stat_samples3.txt \
	data/test_parameter_stat_samples4.txt

TESTS = \
	check_array_utils \
	check_stats_utils \
	check_math_utils \
	check_parsing \
	check_partition_combinatorics \
	check_eureject

check_PROGRAMS = \
	check_array_utils \
	check_stats_utils \
	check_math_utils \
	check_parsing \
	check_partition_combinatorics \
	check_eureject

check_array_utils_SOURCES = \
	check_array_utils.c \
	test_utils.c \
	test_utils.h

check_array_utils_CFLAGS = @CHECK_CFLAGS@
check_array_utils_LDADD =  @CHECK_LIBS@ @MATHLDADD@

check_stats_utils_SOURCES = \
	check_stats_utils.c \
	$(top_builddir)/src/array_utils.c \
	test_utils.c \
	test_utils.h

check_stats_utils_CFLAGS = @CHECK_CFLAGS@
check_stats_utils_LDADD =  @CHECK_LIBS@ @MATHLDADD@

check_math_utils_SOURCES = \
	check_math_utils.c \
	$(top_builddir)/src/array_utils.c \
	test_utils.c \
	test_utils.h

check_math_utils_CFLAGS = @CHECK_CFLAGS@
check_math_utils_LDADD =  @CHECK_LIBS@ @MATHLDADD@

check_parsing_SOURCES = \
	check_parsing.c \
	$(top_builddir)/src/array_utils.c \
	$(top_builddir)/src/stats_utils.c \
	test_utils.c \
	test_utils.h

check_parsing_CFLAGS = @CHECK_CFLAGS@
check_parsing_LDADD =  @CHECK_LIBS@ @MATHLDADD@

check_partition_combinatorics_SOURCES = \
	check_partition_combinatorics.c \
	$(top_builddir)/src/array_utils.c \
	test_utils.c \
	test_utils.h

check_partition_combinatorics_CFLAGS = @CHECK_CFLAGS@
check_partition_combinatorics_LDADD =  @CHECK_LIBS@ @MATHLDADD@

if USE_GSL
TESTS += check_partition_combinatorics_random
check_PROGRAMS += check_partition_combinatorics_random
check_partition_combinatorics_random_SOURCES = \
	check_partition_combinatorics_random.c \
	$(top_builddir)/src/array_utils.c \
	$(top_builddir)/src/partition_combinatorics.c \
	test_rng.c \
	test_rng.h
check_partition_combinatorics_random_CFLAGS = @CHECK_CFLAGS@ @GSL_CFLAGS@
check_partition_combinatorics_random_LDADD =  @CHECK_LIBS@ @GSL_LIBS@
endif

if USE_GSL
TESTS += check_probability
check_PROGRAMS += check_probability
check_probability_SOURCES = \
	check_probability.c \
	$(top_builddir)/src/array_utils.c \
	test_rng.c \
	test_rng.h
check_probability_CFLAGS = @CHECK_CFLAGS@ @GSL_CFLAGS@
check_probability_LDADD =  @CHECK_LIBS@ @GSL_LIBS@
endif

check_eureject_SOURCES = \
	check_eureject.c \
	$(top_builddir)/src/array_utils.c \
	$(top_builddir)/src/stats_utils.c \
	$(top_builddir)/src/math_utils.c \
	$(top_builddir)/src/parsing.c \
	$(top_builddir)/src/abacus.c \
	test_utils.c \
	test_utils.h

check_eureject_CFLAGS = @CHECK_CFLAGS@
check_eureject_LDADD =  @CHECK_LIBS@ @MATHLDADD@


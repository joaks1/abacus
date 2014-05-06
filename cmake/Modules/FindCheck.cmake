# Find Check libraries
# Once done this will define
#
#  CHECK_FOUND - System has check
#  CHECK_INCLUDE_DIRS - The check include directories
#  CHECK_LIBRARIES - The libraries needed to use check

#find_path (CHECK_INCLUDE_DIR
#    "check.h")
#find_library (CHECK_LIBRARY
#    NAMES "check")
#if (CHECK_INCLUDE_DIR AND CHECK_LIBRARY AND EXISTS "${CHECK_LIBRARY}")
#    set (CHECK_FOUND TRUE)
#    set (CHECK_INCLUDE_DIRS "${CHECK_INCLUDE_DIR}")
#    set (CHECK_LIBRARIES "${CHECK_LIBRARY}")
#    message(STATUS "Check library found: ${CHECK_LIBRARIES}")
#else ()
#    message(STATUS "Check library NOT found")
#    set (CHECK_FOUND FALSE)
#    set (CHECK_INCLUDE_DIRS "")
#    set (CHECK_LIBRARIES "")
#endif ()

# Find Check libraries
# Once done this will define
#
# CHECK_FOUND - System has check
# CHECK_INCLUDE_DIRS - The check include directories
# CHECK_LIBRARIES - The libraries needed to use check
# CHECK_DEFINITIONS - Compiler switches required for using check

find_package(PkgConfig)

if ("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}" VERSION_GREATER "2.8.1")
    set(_QUIET QUIET)
endif ()

pkg_check_modules (PC_LIBCHECK ${_QUIET} check)
set (CHECK_DEFINITIONS ${PC_LIBCHECK_CFLAGS_OTHER})

find_path (CHECK_INCLUDE_DIR
    "check.h"
    HINTS ${PC_LIBCHECK_INCLUDEDIR} ${PC_LIBCHECK_INCLUDE_DIRS}
    PATH_SUFFIXES "check"
    )

find_library (CHECK_LIBRARY
    NAMES "check"
    HINTS ${PC_LIBCHECK_LIBDIR} ${PC_LIBCHECK_LIBRARY_DIRS}
    )

set (CHECK_LIBRARIES ${CHECK_LIBRARY})
set (CHECK_INCLUDE_DIRS ${CHECK_INCLUDE_DIR})

include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (check
    DEFAULT_MSG
    CHECK_LIBRARY
    CHECK_INCLUDE_DIR
    )
find_program (PKG_CONFIG_EXECUTABLE pkg-config
    /usr/bin/
    /usr/local/bin
    )
execute_process (
    COMMAND "${PKG_CONFIG_EXECUTABLE}" --cflags check
    OUTPUT_VARIABLE CHECK_CFLAGS
    RESULT_VARIABLE RET
    ERROR_QUIET
    )
if (RET EQUAL 0)
    string (STRIP "${CHECK_CFLAGS}" CHECK_CFLAGS)
    #separate_arguments(CHECK_CFLAGS)
endif (RET EQUAL 0)
execute_process (
    COMMAND "${PKG_CONFIG_EXECUTABLE}" --libs check
    OUTPUT_VARIABLE CHECK_LIBS
    RESULT_VARIABLE RET
    ERROR_QUIET
    )
if (RET EQUAL 0)
    string (STRIP "${CHECK_LIBS}" CHECK_LIBS)
    #separate_arguments(CHECK_LIBS)
endif (RET EQUAL 0)

message(STATUS "CHECK_LIBRARIES: ${CHECK_LIBRARIES}")
message(STATUS "CHECK_INCLUDE_DIRS: ${CHECK_INCLUDE_DIRS}")
message(STATUS "CHECK_DEFINITIONS: ${CHECK_DEFINITIONS}")
message(STATUS "PKG_CONFIG_EXECUTABLE: ${PKG_CONFIG_EXECUTABLE}")
message(STATUS "CHECK_LIBS: ${CHECK_LIBS}")
message(STATUS "CHECK_CFLAGS: ${CHECK_CFLAGS}")

mark_as_advanced (CHECK_INCLUDE_DIR CHECK_LIBRARY)


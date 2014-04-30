# Find Check libraries
# Once done this will define
#
#  CHECK_FOUND - System has check
#  CHECK_INCLUDE_DIRS - The check include directories
#  CHECK_LIBRARIES - The libraries needed to use check

find_path (CHECK_INCLUDE_DIR
    "check.h")
find_library (CHECK_LIBRARY
    NAMES "check")
if (CHECK_INCLUDE_DIR AND CHECK_LIBRARY AND EXISTS "${CHECK_LIBRARY}")
    set (CHECK_FOUND TRUE)
    set (CHECK_INCLUDE_DIRS "${CHECK_INCLUDE_DIR}")
    set (CHECK_LIBRARIES "${CHECK_LIBRARY}")
    message(STATUS "Check library found: ${CHECK_LIBRARIES}")
else ()
    message(STATUS "Check library NOT found")
    set (CHECK_FOUND FALSE)
    set (CHECK_INCLUDE_DIRS "")
    set (CHECK_LIBRARIES "")
endif ()


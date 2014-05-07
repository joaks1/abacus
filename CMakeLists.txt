cmake_minimum_required (VERSION 2.6)

# get local cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

project("abacus" C)

enable_testing()

set(PROJECT_MAJOR_VERSION 0)
set(PROJECT_MINOR_VERSION 1)
set(PROJECT_PATCH_VERSION 0)
set(PROJECT_VERSION
    ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_VERSION})
set(PROJECT_NAME "ABACUS")
set(PROJECT_DESCRIPTION "Approximate BAysian C UtilitieS")
set(PROJECT_AUTHORS "Jamie Oaks")
set(PROJECT_COPYRIGHT "Copyright (C) 2013 Jamie Oaks")
set(PROJECT_LICENSE 
    "ABACUS comes with ABSOLUTELY NO WARRANTY. ABACUS is free software:\n
    you can redistribute and/or modify it under the terms of the GNU GPL\n
    version 3 or later."
    )


# configure a header file to pass CMake settings to source code
configure_file (
    "${PROJECT_SOURCE_DIR}/src/abacus_config.h.in"
    "${PROJECT_SOURCE_DIR}/src/abacus_config.h"
    )

# add binary tree to search path so abacus_config.h can be found
include_directories("${PROJECT_BINARY_DIR}")

# create target for building and running tests
set (CMAKE_CTEST_COMMAND "ctest")
add_custom_target (check COMMAND "${CMAKE_CTEST_COMMAND}")

add_subdirectory(src)
add_subdirectory(test)


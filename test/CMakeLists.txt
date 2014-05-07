#install (DIRECTORY data "${TEST_DIR}/data")
find_package (Check)

if (NOT CHECK_FOUND)
    message(STATUS "Check library not found; skipping unit tests...")
else (NOT CHECK_FOUND)

    enable_testing()
    include_directories ("${CHECK_INCLUDE_DIRS}")
    include_directories("${PROJECT_SOURCE_DIR}/test" "${PROJECT_SOURCE_DIR}/src")

    find_library (MATH_LIBRARY m)
    find_library (RT_LIBRARY rt)
    find_package (Threads)
    
    add_executable (check_array_utils EXCLUDE_FROM_ALL
        check_array_utils.c
        test_utils.c
        test_utils.h
        )
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CHECK_DEFINITIONS}")
    target_link_libraries(check_array_utils
        "${CHECK_LIBRARIES}"
        "${RT_LIBRARY}"
        "${MATH_LIBRARY}"
        )
    add_test(check_array_utils "${CMAKE_CURRENT_BINARY_DIR}/check_array_utils")
    add_dependencies (check check_array_utils)

endif (NOT CHECK_FOUND)

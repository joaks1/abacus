#install (DIRECTORY data "${TEST_DIR}/data")
find_package (Check)

if (NOT CHECK_FOUND)
    message(STATUS "Check library not found; skipping unit tests...")
else (NOT CHECK_FOUND)

    enable_testing()
    #find_package (Check REQUIRED)
    include_directories ("${CHECK_INCLUDE_DIRS}")
    #set (TEST_LIBS "${TEST_LIBS}" "${CHECK_LIBRARIES}")
    include_directories("${PROJECT_SOURCE_DIR}/test" "${PROJECT_SOURCE_DIR}/src")
    
    add_executable (check_array_utils #EXCLUDE_FROM_ALL
        check_array_utils.c
        test_utils.c
        test_utils.h
        )
    #add_dependencies(check check_array_utils)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CHECK_CFLAGS}")
    target_link_libraries(check_array_utils
        ${CHECK_LIBS}
        #"cblas"
        #"m"
        )
    #        "pthread"
    #        "m"
    #        )
    add_test(check_array_utils "${CMAKE_CURRENT_BINARY_DIR}/check_array_utils")
    #check_array_utils_CFLAGS = @CHECK_CFLAGS@
endif (NOT CHECK_FOUND)

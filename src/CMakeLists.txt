find_package (GSL)

include_directories("${PROJECT_SOURCE_DIR}/test" "${PROJECT_SOURCE_DIR}/src")
find_library (MATH_LIBRARY m)

if (ABACUS_STATIC_LINKING)
    set (CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    set (CMAKE_EXE_LINKER_FLAGS "-static")
    set (CMAKE_SKIP_RPATH YES)
endif (ABACUS_STATIC_LINKING)

add_executable (eureject
	eureject.c
	eureject.h
	eureject_main.c
	array_utils.c
	array_utils.h
	math_utils.c
	math_utils.h
	stats_utils.c
	stats_utils.h
	parsing.c
	parsing.h
	abacus.c
	abacus.h
    )
target_link_libraries(eureject
    "${MATH_LIBRARY}"
    )

add_executable(intpart
	intpart.c
	intpart.h
	intpart_main.c
	array_utils.c
	array_utils.h
	partition_combinatorics.c
	partition_combinatorics.h
	abacus.c
	abacus.h
    )
target_link_libraries(intpart
    "${MATH_LIBRARY}"
    )

if (GSL_FOUND)
    include_directories ("${GSL_INCLUDE_DIRS}")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GSL_DEFINITIONS}")

    add_executable(dpdraw
	    dpdraw.c
	    dpdraw.h
	    dpdraw_main.c
	    array_utils.c
	    array_utils.h
	    partition_combinatorics.c
	    partition_combinatorics.h
	    partition_combinatorics_random.c
	    partition_combinatorics_random.h
	    abacus.c
	    abacus.h
        )
    target_link_libraries(dpdraw
        "${GSL_LIBRARIES}"
        "${MATH_LIBRARY}"
        )
    install(TARGETS dpdraw DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
    if (ABACUS_STATIC_LINKING)
        set_target_properties(dpdraw PROPERTIES
            LINK_SEARCH_END_STATIC ON
            )
    endif (ABACUS_STATIC_LINKING)
endif (GSL_FOUND)

if (ABACUS_STATIC_LINKING)
    set_target_properties(eureject intpart PROPERTIES
        LINK_SEARCH_END_STATIC ON
        )
endif (ABACUS_STATIC_LINKING)

install(TARGETS eureject intpart DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")


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
target_link_libraries (eureject "m")

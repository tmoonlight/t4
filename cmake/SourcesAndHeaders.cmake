set(sources
    src/tmp.cpp
	src/ship.cpp
	src/frigate.cpp
	src/leserver.cpp
	src/main.cpp	
	src/keyboard_event.cpp
	
)


set(exe_sources
		src/entry_main.cpp
		src/api.cpp
		${sources}
		
)

set(headers
    include/project/tmp.h
	include/project/ship.h
	include/project/frigate.h
	include/project/idestroyable.h
	include/project/def.h
	include/project/keyboard_event.h
	#include/project/leserver.h
	include/project/api.h
	include/catch.hpp
)

set(test_sources
  src/tmp_test.cpp
)

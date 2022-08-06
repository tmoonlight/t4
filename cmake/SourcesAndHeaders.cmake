set(sources
    src/tmp.cpp
	src/ship.cpp
	src/frigate.cpp
	src/leserver.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
    include/project/tmp.h
	include/project/ship.h
	include/project/frigate.h
	include/project/idestroyable.h
	#include/catch.hpp
)

set(test_sources
  src/tmp_test.cpp
)

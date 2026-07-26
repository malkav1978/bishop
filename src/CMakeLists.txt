add_library(bishop SHARED)
add_library(malko::bishop ALIAS bishop)

target_include_directories(
	bishop
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

set_target_properties(
	bishop
	PROPERTIES VERSION ${PROJECT_VERSION}
)

target_sources(
	bishop
	PRIVATE
	histogram.cpp
	PUBLIC
		FILE_SET HEADERS
		BASE_DIRS
			${CMAKE_SOURCE_DIR}/include
		FILES
			${CMAKE_SOURCE_DIR}/include/prometheus/histogram.hpp
)

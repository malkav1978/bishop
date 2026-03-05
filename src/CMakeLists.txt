add_library(bishop SHARED)
add_library(Prometheus::bishop ALIAS bishop)

target_include_directories(
	bishop
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

target_sources(
	bishop
	PRIVATE
	counter.cpp
	PUBLIC
	${CMAKE_SOURCE_DIR}/include/prometheus/counter.hpp
)

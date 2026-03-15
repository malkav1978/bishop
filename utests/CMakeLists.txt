include(GoogleTest)

find_package(GTest REQUIRED)

add_executable(utests)

target_include_directories(
	utests
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

target_sources(
	utests
	PRIVATE
	utest_counter.cpp
	utest_gauge.cpp
	utest_histogram.cpp
)

target_link_libraries(utests GTest::gtest_main Prometheus::bishop)

gtest_discover_tests(utests)

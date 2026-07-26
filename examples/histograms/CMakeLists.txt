add_executable(histograms)

target_include_directories(
	histograms
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

target_sources(
	histograms
	PRIVATE
	histograms.cpp
)

target_link_libraries(histograms malko::bishop)

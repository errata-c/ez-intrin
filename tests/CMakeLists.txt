cmake_minimum_required(VERSION 3.16)

include("../cmake/check-system.cmake")

find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

add_library(test_interface INTERFACE)
target_link_libraries(test_interface INTERFACE ez::intrin fmt::fmt Catch2::Catch2)
target_compile_definitions(test_interface INTERFACE EZ_INTRIN_$CACHE{EZ_INTRIN_COMPILER})

add_executable(basic_test 
	"basic/main.cpp"
	"basic/bitops.cpp"
)
target_link_libraries(basic_test PRIVATE 
	test_interface
)

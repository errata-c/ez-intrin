cmake_minimum_required(VERSION 3.15)

project(EZ_INTRINSICS
VERSION 1.0.0
LANGUAGES C CXX)

include(GNUInstallDirs)
include("cmake/ez-cmake/install-package.cmake")

option(BUILD_TESTS "Build the test executables" ON)
option(SEPARATE_DIRECTORY "Install the package into its own directory" ON)
set(CONFIG_DIR "${CMAKE_INSTALL_DATAROOTDIR}/ez-intrinsics" CACHE STRING "The relative directory to install package config files.")


set(ez-intrinsics_ROOT "${CMAKE_CURRENT_LIST_DIR}")

# Build the tests once the option is enabled.
if(${BUILD_TESTS})
	add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")
endif()

# Set the proper installation path
set(CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/ez-intrinsics)

install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
	TYPE INCLUDE
	FILES_MATCHING
	PATTERN "*.h" PATTERN "*.hpp"
)
install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib/"
	TYPE LIB
	FILES_MATCHING
	PATTERN "*.c" PATTERN "*.cpp"
)
install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/share/"
	DESTINATION "share"
	FILES_MATCHING
	PATTERN ".cmake"
)
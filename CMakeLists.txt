cmake_minimum_required(VERSION 3.15)

project(EZ_INTRIN
VERSION 1.0.0
LANGUAGES C CXX)

include(GNUInstallDirs)
include(FetchContent)

option(EZ_INTRIN_BUILD_TESTS "Build the test executables" ON)
set(EZ_INTRIN_CONFIG_DIR "${CMAKE_INSTALL_DATAROOTDIR}/ez-intrin" CACHE STRING "The relative directory to install package config files.")

FetchContent_Declare(
	ez-cmake
	GIT_REPOSITORY "https://github.com/errata-c/ez-cmake.git"
	GIT_TAG "main"
)
FetchContent_MakeAvailable(ez-cmake)
ez_is_project_top_level(IS_TOP_LEVEL)

set(SOURCE_FILES "src/fallback.cpp")
if(CMAKE_CXX_COMPILER_ID MATCHES "AppleClang|Clang|XLClang")
	set(SOURCE_FILES "src/clang.cpp")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "ARMClang")
	set(SOURCE_FILES "src/armclang.cpp")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(SOURCE_FILES "src/msvc.cpp")
endif()

add_library(intrin INTERFACE)
target_include_directories(intrin INTERFACE 
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIR}>"
)
add_library(ez::intrin ALIAS intrin)

# Build the tests once the option is enabled.
if(${EZ_INTRIN_BUILD_TESTS})
	add_subdirectory("tests")
endif()

if(IS_TOP_LEVEL)
	install(
		DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
		TYPE INCLUDE
		FILES_MATCHING
		PATTERN "*.h" PATTERN "*.hpp"
	)

	install(TARGETS intrin
		EXPORT intrin-targets
		RUNTIME DESTINATION "bin/$<CONFIG>"
		ARCHIVE DESTINATION "lib/$<CONFIG>"
		LIBRARY DESTINATION "lib/$<CONFIG>"
	)

	install_package(
		NAME "ez-intrin"
		NAMESPACE "ez::"
		EXPORT "intrin-targets"
		VERSION "${EZ_INTRIN_VERSION}"
		COMPATIBILITY "SameMajorVersion"
		DESTINATION "${EZ_INTRIN_CONFIG_DIR}"
		POSTCONFIG "cmake/postconfig.cmake"
		ARCH_INDEPENDENT
	)
endif()
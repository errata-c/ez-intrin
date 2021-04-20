
include_guard(DIRECTORY)
include(CMakeFindDependencyMacro)

get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)

set(SOURCE_LIST
	"$<$<CXX_COMPILER_ID:MSVC>:${_IMPORT_PREFIX}/lib/msvc.cpp>"
	"$<$<CXX_COMPILER_ID:Clang>:${_IMPORT_PREFIX}/lib/clang.cpp>"
	"$<$<CXX_COMPILER_ID:GNU>:${_IMPORT_PREFIX}/lib/gcc.cpp>"
	"$<$<NOT:$<CXX_COMPILER_ID:MSVC,GNU,Clang>>:${_IMPORT_PREFIX}/lib/fallback.cpp>"
)

add_library(ez::intrinsics INTERFACE IMPORTED)
set_target_properties(ez::intrinsics PROPERTIES
  INTERFACE_COMPILE_FEATURES "cxx_std_17"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_SOURCES "${SOURCE_LIST}"
)

# check system, determine capabilities
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(EZ_INTRIN_COMPILER "MSVC" CACHE STRING "" FORCE)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "AppleClang|Clang|XLClang")
	set(EZ_INTRIN_COMPILER "CLANG" CACHE STRING "" FORCE)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(EZ_INTRIN_COMPILER "GNU" CACHE STRING "" FORCE)
else()
	message(WARNING "Unsupported c++ compiler! Intrinsics will fallback to normal c++ functions.")
	set(EZ_INTRIN_COMPILER "FALLBACK" CACHE STRING "" FORCE)
endif()
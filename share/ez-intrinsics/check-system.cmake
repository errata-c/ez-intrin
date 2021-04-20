
# check system, determine capabilities

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	function(preprocess_source IN_FILE OUT_FILE)
		get_filename_component(FILE_EXT "${IN_FILE}" EXT)
		string(TOLOWER FILE_EXT FILE_EXT)

		if("${FILE_EXT}" matches "\\.cpp|\\.cxx")
			set(COMPILER "${CMAKE_CXX_COMPILER}")
		else()
			set(COMPILER "${CMAKE_C_COMPILER}")
		endif()

		execute_process(COMMAND "${COMPILER}"
					"/P"
					"\"${IN_FILE}\""
					"/Fi"
					"\"${OUT_FILE}\"")
	endfunction()

elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	function(preprocess_source IN_FILE OUT_FILE)
		get_filename_component(FILE_EXT "${IN_FILE}" EXT)
		string(TOLOWER FILE_EXT FILE_EXT)

		if("${FILE_EXT}" matches "\\.cpp|\\.cxx")
			set(COMPILER "${CMAKE_CXX_COMPILER}")
		else()
			set(COMPILER "${CMAKE_C_COMPILER}")
		endif()
		
		set(ARGS "")
		if("${CMAKE_CXX_COMPILER_TARGET}")
			list(APPEND ARGS "-target" "${CMAKE_CXX_COMPILER_TARGET}")
		endif()
		list(APPEND ARGS "-E" )

		execute_process(COMMAND "${COMPILER}"
					
					"\"${IN_FILE}\""
					"/Fi"
					"\"${OUT_FILE}\"")
	endfunction()

elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	function(preprocess_source IN_FILE OUT_FILE)
		get_filename_component(FILE_EXT "${IN_FILE}" EXT)
		string(TOLOWER FILE_EXT FILE_EXT)

		if("${FILE_EXT}" matches "\\.cpp|\\.cxx")
			set(COMPILER "${CMAKE_CXX_COMPILER}")
		else()
			set(COMPILER "${CMAKE_C_COMPILER}")
		endif()

		execute_process(COMMAND "${COMPILER}"
					"/P"
					"\"${IN_FILE}\""
					"/Fi"
					"\"${OUT_FILE}\"")
	endfunction()

else()
	message(WARNING "Unsupported c++ compiler! Intrinsics will fallback to normal c++ functions.")
endif()
include("check-system.cmake")

set_target_properties(ez::intrin PROPERTIES
	INTERFACE_COMPILE_DEFINITIONS "EZ_INTRIN_$CACHE{EZ_INTRIN_COMPILER}"
)
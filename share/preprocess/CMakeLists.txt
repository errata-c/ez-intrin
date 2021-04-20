cmake_minimum_required(VERSION 3.15)

project(PREPROCESS 
LANGUAGES C CXX)

# This subproject will be configured and built with the toolchain and settings of the parent project
# However, its output will simply be the preprocessor stage only.
# This allows use to get the exact configuration the parent project is using, and 
#	then apply it to our simple source file.
# Once we have the preprocessed output, we will parse it to find information not directly available within 
#	cmake, such as the target architechture and cpu capabilities

include(TestBigEndian)
test_big_endian(IS_BIG_ENDIAN)
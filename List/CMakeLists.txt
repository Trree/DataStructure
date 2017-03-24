cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project (run)
SET(CMAKE_C_COMPILER "g++") 
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
set (CMAKE_CXX_STANDARD 11) 
# configure a header file to pass some of the CMake settings
# to the source code
#configure_file (
#"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
#"${PROJECT_BINARY_DIR}/TutorialConfig.h"
#
#)
option (USE_MYMATH "Use tutorial provided math implementation" OFF) 
if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory (MathFunctions)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
ADD_DEFINITIONS(-g -W -Wall -pedantic -DTIXML_USE_STL)
# add the executable
add_executable(run list.cpp)

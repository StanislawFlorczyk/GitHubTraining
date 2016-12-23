cmake_minimum_required(VERSION 2.6)
project(Tutorial)

#Basic Configuration
set (Tutorial_VERSION_MAJOR 2)
set (Tutorial_VERSION_MINOR 0)
set (PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/Source)
set (PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}/Header)
set (TUTORIAL_CONFIGURATION_FILES "${CMAKE_HOME_DIRECTORY}/build/conf")
set (TUTORIAL_EXTERNAL_LIBRARIES "${CMAKE_HOME_DIRECTORY}/build/libs")

# configure a header file to pass some of the CMake settings to the source code
configure_file ("${TUTORIAL_CONFIGURATION_FILES}/_Globals.hpp"
					  "${PROJECT_BINARY_DIR}/Globals.hpp")
					  
# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")
include_directories ("${TUTORIAL_EXTERNAL_LIBRARIES}")

# external libraries
add_library(FancyPrintLib "${TUTORIAL_EXTERNAL_LIBRARIES}/FancyPrint.cpp")
 
# add the executable
add_executable(Tutorial ${PROJECT_SOURCE_DIR}/Main.cpp)
target_link_libraries (Tutorial FancyPrintLib)
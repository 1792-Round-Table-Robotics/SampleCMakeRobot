cmake_minimum_required (VERSION 3.0)
project (SampleCMakeRobot)

# Make sure CMake finds our FindWPILib.cmake script
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# Set our C++ standard to C++11
set (CMAKE_CXX_STANDARD 11)

# Add our source files directory to CMake.
add_subdirectory("${PROJECT_SOURCE_DIR}/src")
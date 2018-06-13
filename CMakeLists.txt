cmake_minimum_required (VERSION 3.2)
project (SampleCMakeRobot)

# Make sure CMake finds our FindWPILib.cmake script
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# Export compile_commands.json so VSCode knows the include paths of all the library headers (including WPILib)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)
# Set our C++ standard to C++11
set (CMAKE_CXX_STANDARD 11)

# Create our SOURCES variable with all our C++ source files to compile
set (SOURCES 
    src/Robot.cpp
)

# Find the WPILib files, using FindWPILib.cmake
find_package(wpilib REQUIRED)
# Tell CMake to use the WPILib header files the script found.
include_directories(${WPILib_INCLUDE_DIRS})

# Add our code as an executable
add_executable (SampleCMakeRobot ${SOURCES})
# Make sure our header files (like Robot.h) are included
target_include_directories(SampleCMakeRobot PRIVATE ${PROJECT_SOURCE_DIR}/include)
# Link our executable with the WPILib libraries
target_link_libraries (SampleCMakeRobot ${WPILib_LIBRARIES})
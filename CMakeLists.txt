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

# ------------ Google Test -----------------------------------------------
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Add our code as an executable
add_executable (SampleCMakeRobot ${SOURCES})
# Make sure our header files (like Robot.h) are included
target_include_directories(SampleCMakeRobot PRIVATE ${PROJECT_SOURCE_DIR}/include)
# Link our executable with the WPILib libraries
target_link_libraries (SampleCMakeRobot ${WPILib_LIBRARIES})

# Add our test executable
add_executable(ExampleTest test/ExampleTest.cpp)
# Link with Google Test
target_link_libraries(ExampleTest gtest gtest_main)
# Add the test to cmake.
add_test(NAME example_test COMMAND ExampleTest)
# Find the WPILib files, using FindWPILib.cmake
find_package(wpilib REQUIRED)
# Tell CMake to use the WPILib header files the script found.
include_directories(${WPILib_INCLUDE_DIRS})

# Add our Robot code as an executable
add_executable(TestProject Robot.cpp)
# Link our executable with the WPILib libraries
target_link_libraries(TestProject ${WPILib_LIBRARIES})
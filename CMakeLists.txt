# Server 2 CMake Configuration

# Set the minimum required version of CMake - this ensures compatibility with the features used in the project
cmake_minimum_required(VERSION 3.15)
# Define the project name - this is used to identify the project in CMake
project(server2)

# Set the C++ standard to C++17 - this is required for some features used in the project
set(CMAKE_CXX_STANDARD 17)
# Ensure that the C++ standard is enforced - this prevents the use of older standards and fails the build if the standard is not met
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# create an executable target named 'nes' - this is the main output of the project
# The source files listed here will be compiled to create the executable
# The source files are organized in a 'src' directory, which is a common practice to
# keep the project structure clean and maintainable
add_executable(server2
        src/main.cpp
        src/game.cpp
        src/game.h
        src/Renderer.cpp
        src/Renderer.h
)

# Find the required packages for the project - The only one required here is SDL2
# This is a cross-platform library used for handling graphics, input, and audio
find_package(SDL2 REQUIRED)

# Link the SDL2 library to the 'nes' target - This allows the executable to use the SDL2 functions
# This is set by the find_package command above, which locates the SDL2 library on the system
include_directories(${SDL2_INCLUDE_DIRS})

# Link the SDL2 libraries to the 'nes' target - This is necessary for the executable to use the SDL2 functionality
# This contains the correct .a or .dylib files depending on the platform
target_link_libraries(server2 ${SDL2_LIBRARIES})

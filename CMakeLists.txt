# Minimum required CMake version
cmake_minimum_required(VERSION 3.19)

# Project name
project(ALGOR_TP1)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all .cpp files in the current directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add executable target named "main"
add_executable(main ${SOURCES})

# Link ncurses to the executable
target_link_libraries(main ${CURSES_LIBRARIES})


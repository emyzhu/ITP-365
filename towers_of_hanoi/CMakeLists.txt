# Require CMAKE 3.1 or higher
cmake_minimum_required(VERSION 3.1)

# Project name
project(HW04)

# Build for C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Any source files in this directory
set(SOURCE_FILES main.cpp)

# Where any include files are
include_directories(src)
include_directories(ITPLib)

# Subdirectories to build
add_subdirectory(src)

# Location of files to link
link_directories(ITPLib)

# Name of executable
add_executable(main ${SOURCE_FILES})

# Link main vs the source library
if (WIN32)
	target_link_libraries(main src ITPlib)
elseif (APPLE)
	find_library(COCOA_LIBRARY Cocoa)
	target_link_libraries(main src ITPlib ${COCOA_LIBRARY})
endif()


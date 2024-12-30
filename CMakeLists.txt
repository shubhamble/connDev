# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(connDevProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find FFmpeg libraries
find_package(PkgConfig REQUIRED)
pkg_check_modules(AVFORMAT libavformat REQUIRED)
pkg_check_modules(AVCODEC libavcodec REQUIRED)
pkg_check_modules(AVUTIL libavutil REQUIRED)

# Include directories for FFmpeg
include_directories(${AVFORMAT_INCLUDE_DIRS} ${AVCODEC_INCLUDE_DIRS} ${AVUTIL_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add the executable, now including all source files
add_executable(connDevApp 
    connDev.cpp 
    runtimePoly.cpp
    cModule.c
    media_info.c
)

# Link FFmpeg libraries
target_link_libraries(connDevApp ${AVFORMAT_LIBRARIES} ${AVCODEC_LIBRARIES} ${AVUTIL_LIBRARIES})

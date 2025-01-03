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

# Include GStreamer
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GST_APP REQUIRED gstreamer-app-1.0)
pkg_check_modules(GST_VIDEO REQUIRED gstreamer-video-1.0)

# Include directories for GStreamer
include_directories(${GSTREAMER_INCLUDE_DIRS} ${GST_APP_INCLUDE_DIRS} ${GST_VIDEO_INCLUDE_DIRS})

# Link GStreamer libraries
link_directories(${GSTREAMER_LIBRARY_DIRS})
link_directories(${GST_APP_LIBRARY_DIRS})
link_directories(${GST_VIDEO_LIBRARY_DIRS})

# Add source files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(connDevApp 
    connDev.cpp 
    runtimePoly.cpp
    cModule.c
    media_info.c
    videoPlayer.c
)

# Link FFmpeg libraries
target_link_libraries(connDevApp ${AVFORMAT_LIBRARIES} ${AVCODEC_LIBRARIES} ${AVUTIL_LIBRARIES})

# Link GStreamer libraries
target_link_libraries(connDevApp ${GSTREAMER_LIBRARIES} ${GST_APP_LIBRARIES} ${GST_VIDEO_LIBRARIES})

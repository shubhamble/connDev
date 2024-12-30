connDevProject

Overview

connDevProject is a C++ project that integrates C and C++ modules to demonstrate runtime polymorphism and media file processing using FFmpeg libraries. It supports compilation with CMake and utilizes FFmpeg for extracting media metadata.

Dependencies

CMake (Version 3.10 or later)
FFmpeg Libraries
libavformat
libavcodec
libavutil
GCC/G++ compiler

Build Instructions

1. Clone the repository:
git clone <repo-url>
cd connDevProject

2. Build the project:
chmod +x build.sh
./build.sh

3. Execute the application:
./build/connDevApp <media_file>

Features:
1. Runtime Polymorphism

2. Demonstrates inheritance and virtual functions in runtimePoly.cpp.

3. Media Metadata Extraction

4. Uses FFmpeg to parse and display information about a given media file.

5. C and C++ Integration

6. Shows seamless integration of C modules with C++.

Code Details:
1. connDev.cpp - Main entry point of the application, initializes modules.
2. runtimePoly.cpp - Implements runtime polymorphism concepts.
3. media_info.c - Handles media metadata extraction using FFmpeg.
4. cModule.c - Demonstrates integration of C code with C++.

Example Output
$ ./build/connDevApp sample.mp4
Input #0, mov,mp4,m4a,3gp,3g2,mj2, from 'sample.mp4':
  Duration: 00:00:10.01, start: 0.000000, bitrate: 505 kb/s
    Stream #0:0: Video: h264 (avc1 / 0x31637661), yuv420p, 1280x720, 30 fps

Author:
Shubham Mishra






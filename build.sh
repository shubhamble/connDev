#!/bin/bash

# Set variables
BUILD_DIR="build"

# Check if the build directory exists; if not, create it
if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory..."
    mkdir $BUILD_DIR
fi

# Navigate to the build directory
cd $BUILD_DIR

# Run CMake to generate the Makefiles
echo "Running CMake..."
cmake ..

# Compile the project
echo "Compiling the project..."
make

# Return to the original directory
cd ..

# Print success message
echo "Build completed. Executable is located in the $BUILD_DIR directory."

#!/bin/bash

# Make a build folder if it does not exit.
# If this fails, exit.
[ -d build ] || mkdir build || exit

# Enter the build directory or exit.
pushd build || exit

# Use cmake to build the project.
cmake -GNinja ..
# Build all the library.
ninja

# Run every test in the build directory.
for file in ./*; do
    # A test is an executable file.
    [ -x "$file" ] && [ -f "$file" ] && ./"$file"
done


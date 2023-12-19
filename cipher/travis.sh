#!/bin/bash

# Cmake into build directory
echo "Compiling..."
mkdir build
cd build
CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run student tests
echo "Running tests..."
timeout 60 build/tests/tests [student]

# Run graded tests
echo "Running graded tests..."
timeout 30 build/tests/tests [graded] || exit 1


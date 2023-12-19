#!/bin/bash

# Pull the graded tests
wget "https://drive.google.com/uc?export=download&id=1eUl9m6amXtScnsOdTUJQdqfx01GepDCh" -O hw05.tar.gz
tar xzf hw05.tar.gz

echo "Compiling..."
mkdir build
cd build
RELEASE=ON CC=clang CXX=clang++ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. || exit 1
make || exit 1

#echo "Running clang-tidy..."
#../run-clang-tidy.py -quiet -header-filter=.*/src/.* || exit 1

# Return to root folder (so cwd is correct)
cd ..

# Run graded tests
echo "Running graded tests..."
timeout 30 build/tests/tests [graded] || exit 1

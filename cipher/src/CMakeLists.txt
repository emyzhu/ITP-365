# Require CMAKE 3.1 or higher
cmake_minimum_required(VERSION 3.1)

# If you create new headers files, add them to these list!
set(HEADER_FILES
    srcmain.h
    cypher.h
    fileio.h
)

# If you create new cpp files, add them to these list!
set(SOURCE_FILES
	srcmain.cpp
    cypher.cpp
    fileio.cpp
)

# Don't change this
add_library(src ${SOURCE_FILES} ${HEADER_FILES})


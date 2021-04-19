cmake_minimum_required(VERSION 3.19)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(data_structures
        CharArrayStack.h
        IntArrayQueue.h
        main.cpp
        README.md
        StackApplications.h)

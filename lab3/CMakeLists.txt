cmake_minimum_required(VERSION 3.10)

project(VectorProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main
    src/main.cpp
    include/VectorBase.h
    include/Vector.h
    include/Vector.inl
)

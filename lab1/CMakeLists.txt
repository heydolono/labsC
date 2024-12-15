cmake_minimum_required(VERSION 3.10)

project(DistributedSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(cluster
    main.cpp
    src/GpuSpec.cpp
    src/CpuSpec.cpp
    src/RamSpec.cpp
    src/LanSpec.cpp
    src/ClusterNode.cpp
    src/Cluster.cpp
)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
    tests/test_cluster.cpp
)

target_link_libraries(tests PRIVATE gtest gtest_main)
target_include_directories(tests PRIVATE include)

add_test(NAME AllTests COMMAND tests)

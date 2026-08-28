cmake_minimum_required(VERSION 3.24)

project(
    data_structures
    VERSION 0.1.0
    DESCRIPTION "Data structures and algorithms implemented in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(DATA_STRUCTURES_BUILD_TESTS "Build the test suite" ON)

if(DATA_STRUCTURES_BUILD_TESTS)
    include(CTest)
    include(FetchContent)

    set(BUILD_GMOCK OFF CACHE BOOL "Build GoogleMock" FORCE)
    set(INSTALL_GTEST OFF CACHE BOOL "Install GoogleTest" FORCE)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    )
    FetchContent_MakeAvailable(googletest)
endif()

add_subdirectory(data_structures)

if(DATA_STRUCTURES_BUILD_TESTS)
    add_subdirectory(tests)
endif()

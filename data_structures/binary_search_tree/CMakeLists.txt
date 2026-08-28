add_library(binary_search_tree STATIC src/binary_search_tree.cpp)

target_compile_features(binary_search_tree PUBLIC cxx_std_17)

target_include_directories(
    binary_search_tree
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

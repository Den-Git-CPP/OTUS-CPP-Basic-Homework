cmake_minimum_required(VERSION 3.10)

project(container CXX)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# Build googletest
add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest" 
    "googletest"
)
# Main target
add_executable(container 
                Container.cpp)
target_include_directories(container PRIVATE include)

# Test target
add_executable(container_list
    test/containers_test.cpp
    test/dblst_test_list.cpp
    test/vctr_test_list.cpp
)
# Add src to the include directories for the test target
target_include_directories(
    container_list PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
# Link test target against gtest libraries
target_link_libraries(
    container_list PRIVATE
    gtest gtest_main
)

if (MSVC)
    target_compile_options(
        container PRIVATE
        /W4
    )
    target_compile_options(
        container_list PRIVATE
        /W4
    )
else ()
    target_compile_options(
        container PRIVATE
        -Wall 
        -Wextra 
        -pedantic 
        -Werror
    )
    target_compile_options(
        container_list PRIVATE
        -Wall 
        -Wextra 
        -pedantic 
        -Werror
    )
endif()
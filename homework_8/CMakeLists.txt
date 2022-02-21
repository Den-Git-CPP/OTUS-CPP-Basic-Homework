cmake_minimum_required(VERSION 3.10)

project(asn CXX)

find_package(Threads REQUIRED)

add_executable(asn async.cpp)

target_include_directories(asn PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(asn PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -Wno-unused-parameter
        -pedantic
    )
    target_link_libraries(asn PUBLIC Threads::Threads)

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(asn PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()
target_compile_features(asn PUBLIC cxx_std_17)


cmake_minimum_required(VERSION 3.10)

project(Statistics CXX)

add_executable(stat
        statistics.cpp
	    src/Max.cpp
	    src/Mean.cpp
        src/Min.cpp
	    src/Std.cpp
)

target_include_directories(stat PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(stat PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(stat PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(stat PUBLIC cxx_std_17)

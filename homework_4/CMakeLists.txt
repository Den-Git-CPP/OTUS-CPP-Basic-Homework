cmake_minimum_required(VERSION 3.10)

project(calc CXX)

add_executable(calc
        main.cpp 
	     src/add.cpp
         src/astnode.cpp
         src/div.cpp
         src/lexer.cpp
         src/mul.cpp
         src/number.cpp
         src/parser.cpp
         src/sub.cpp
         src/variable.cpp
)

target_include_directories(calc PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(calc PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(calc PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(calc PUBLIC cxx_std_17)

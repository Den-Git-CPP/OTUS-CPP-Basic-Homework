cmake_minimum_required(VERSION 3.5)

project (homework_3)

add_executable(homework_3 
check_value.h 
check_value.cpp
main.cpp
)

set_target_properties(
    homework_3 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    )

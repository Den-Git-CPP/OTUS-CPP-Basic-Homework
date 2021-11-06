cmake_minimum_required(VERSION 3.5)

project (homework_3)

add_executable(homework_3 
check_value.h 
check_value.cpp

work_with_result.h
work_with_result.cpp

save_table_score.h
save_table_score.cpp

print_table_score.h
print_table_score.cpp

main.cpp
)

set_target_properties(
    homework_3 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    )

cmake_minimum_required(VERSION 3.16)
project(discrete_math C)

set(CMAKE_C_STANDARD 23)

add_subdirectory(include)
add_subdirectory(./libs/alg)

add_executable(lab1_task5 ./lab1/task5/main.c)
target_link_libraries(lab1_task5 alg)

add_executable(lab1_task8 ./lab1/task8/main.c)
target_link_libraries(lab1_task8 alg)

add_executable(lab2_task2 ./lab2/task2/main.c)
target_link_libraries(lab2_task2 alg)

add_executable(lab2_task3 ./lab2/task3/main.c)
target_link_libraries(lab2_task3 alg)

add_executable(lab3_task1 ./lab3/main.c)
target_link_libraries(lab3_task1 alg)

add_executable(lab4_task1 ./lab4/main.c)
target_link_libraries(lab4_task1 alg)

add_executable(lab5_task2 ./lab5/task2/main.c)
target_link_libraries(lab5_task2 alg)

add_executable(lab5_task3 ./lab5/task3/main.c)
target_link_libraries(lab5_task3 alg)

add_executable(lab6_task5 ./lab6/task5/main.c)
target_link_libraries(lab6_task5 alg)

add_executable(lab6_task6 
./lab6/task6/main.c )
target_include_directories(lab6_task6 PUBLIC ./include/alg)

add_executable(lab7_task2 ./lab7/task2/main.c)
target_link_libraries(lab7_task2 alg)

add_executable(lab7_task3 ./lab7/task3/main.c)
target_link_libraries(lab7_task3 alg)

# Zero library
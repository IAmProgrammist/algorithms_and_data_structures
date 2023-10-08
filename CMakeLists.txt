cmake_minimum_required(VERSION 3.16)
project(discrete_math C)

set(CMAKE_C_STANDARD 23)

add_subdirectory(./libs/alg)

add_executable(lab1_task5 ./lab1/task5/main.c)
target_link_libraries(lab1_task5 alg)

add_executable(lab1_task8 ./lab1/task8/main.c)
target_link_libraries(lab1_task8 alg)

add_executable(lab2_task2 ./lab2/task2/main.c)
target_link_libraries(lab2_task2 alg)

add_executable(lab2_task3 ./lab2/task3/main.c)
target_link_libraries(lab2_task3 alg)

add_executable(t ./lab3/main.c)
target_link_libraries(t alg)

# Zero library
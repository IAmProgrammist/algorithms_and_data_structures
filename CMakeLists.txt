cmake_minimum_required(VERSION 3.16)
project(discrete_math C)

set(CMAKE_C_STANDARD 23)

add_subdirectory(./libs/alg)

add_executable(lab1_task5 ./lab1/task5/main.c)
target_link_libraries(lab1_task5 alg)

add_executable(lab1_task8 ./lab1/task8/main.c)
target_link_libraries(lab1_task8 alg)

add_executable(test ./lab2/test.c)
target_link_libraries(test alg)

# Zero library
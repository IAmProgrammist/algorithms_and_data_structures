cmake_minimum_required(VERSION 3.16)
project(discrete_math C)

set(CMAKE_C_STANDARD 23)

add_subdirectory(./libs/alg)

add_executable(lab1_task5 ./lab1/task5/main.c)
target_link_libraries(lab1_task5 alg)

# Zero library
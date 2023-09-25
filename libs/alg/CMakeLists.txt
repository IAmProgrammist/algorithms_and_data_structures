SET (lab1funcs ./lab1/task5.c ./lab1/task7.c)
SET (lab2funcs ./lab2/task2.c ./lab2/task3.c)

add_library(alg ${lab1funcs} ${lab2funcs})

target_link_libraries(alg m)
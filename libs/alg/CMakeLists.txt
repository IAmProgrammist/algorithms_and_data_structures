SET (lab1funcs ./lab1/task5.c ./lab1/task7.c)

add_library(alg ${lab1funcs})

target_link_libraries(alg m)
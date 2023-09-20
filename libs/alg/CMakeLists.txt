SET (lab1funcs ./lab1/task5.c)

add_library(alg ${lab1funcs})

target_link_libraries(alg m)
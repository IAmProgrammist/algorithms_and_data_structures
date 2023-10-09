SET (lab1funcs ./lab1/task5.c ./lab1/task7.c)
SET (lab2funcs ./lab2/task2.c ./lab2/task3.c)
SET (lab3funcs ./lab3/utility.c 
./lab3/insertionsort.c 
./lab3/selectionsort.c
./lab3/bubblesort.c
./lab3/bubblesortmod1.c
./lab3/bubblesortmod2.c
./lab3/shellsort.c
./lab3/hoarsort.c
./lab3/pyramidsort.c)

add_library(alg ${lab1funcs} ${lab2funcs} ${lab3funcs})

target_link_libraries(alg m)
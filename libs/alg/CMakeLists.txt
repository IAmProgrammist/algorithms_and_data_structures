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
./lab3/heapsort.c)
SET (lab4funcs ./lab4/utility.c
./lab4/linearsearch.c
./lab4/linearquicksearch.c
./lab4/orderedlinearquicksearch.c
./lab4/binarysearch.c
./lab4/blocksearch.c)
SET (lab5funcs ./lab5/task2.c)
SET (lab6funcs ./lab6/stack.c ./lab6/queue.c)
SET (lab7funcs ./lab7/tree.c)

if(TARGET lab8_task2)
    SET (lab8funcs ./lab8/table.c)
endif()


if(TARGET lab8_task2)
    add_library(alg ${lab1funcs} ${lab2funcs} ${lab3funcs} ${lab4funcs} ${lab5funcs} ${lab6funcs} ${lab7funcs} ${lab8funcs})
else()
    add_library(alg ${lab1funcs} ${lab2funcs} ${lab3funcs} ${lab4funcs} ${lab5funcs} ${lab6funcs} ${lab7funcs})
endif()

target_include_directories(alg PUBLIC ../../include/alg)

target_link_libraries(alg m)
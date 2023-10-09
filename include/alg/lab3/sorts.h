#ifndef SORTS
#define SORTS

#include <stdbool.h>

typedef void (*SortingFunction)(int*, int, int*);

#define INC_COMPARES(comps) ((!comps || ++(*comps)))

void swap(int* a, int* b);
bool isOrdered(int* a, int size);
bool isOrderedBackwards(int* a, int size);
void genOrdered(int *a, int size);
void genOrderedBackwards(int *a, int size);
void genRandom(int *a, int size);

void insertionSort(int* data, int size, int* comps);
void selectionSort(int* data, int size, int* comps);
void bubbleSort(int* data, int size, int* comps);
void bubbleSortMod1(int* data, int size, int* comps);
void bubbleSortMod2(int* data, int size, int* comps);
void shellSort(int* data, int size, int* comps);
void hoarSort(int* data, int size, int* comps);
void heapSort(int* data, int size, int* comps);

void comparesExperiment(SortingFunction function, char *sortingFunctionName, int low, int high, int step);

#endif
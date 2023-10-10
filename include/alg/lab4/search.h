#ifndef SEARCH
#define SEARCH

#include <lab3/sorts.h>

#include <stdbool.h>

typedef int (*SearchingFunction)(int*, int, int, int*);
typedef int (*OrderedSearchingFunction)(int*, int, int, int*);

int linearSearch(int* a, int size,  int searchElement, int* comps);
int linearQuickSearch(int* a, int size,  int searchElement, int* comps);
int orderedLinearQuickSearch(int* a, int size,  int searchElement, int* comps);
int orderedBinarySearch(int* a, int size,  int searchElement, int* comps);
int orderedBlockSearch(int* a, int size,  int searchElement, int* comps);

void comparesSearchExperiment(SearchingFunction function, char *searchingFunctionName, int low, int high, int step);
void comparesOrderedSearchExperiment(SearchingFunction function, char *searchingFunctionName, int low, int high, int step);

#endif
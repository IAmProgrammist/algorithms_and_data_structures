#include <lab4/search.h>

int linearSearch(int* a, int size,  int searchElement, int* comps) {
    int i = 0;
    while (INC_COMPARES(comps) && i < size && INC_COMPARES(comps) && a[i] != searchElement)
        i++;

    return i;
}
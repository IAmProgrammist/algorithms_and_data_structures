#include <lab4/search.h>

int linearQuickSearch(int* a, int size,  int searchElement, int* comps) {
    int i = 0;
    a[size] = searchElement;
    while (INC_COMPARES(comps) && a[i] != searchElement)
        i++;

    return i;
}
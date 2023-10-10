#include <lab4/search.h>

int orderedLinearQuickSearch(int* a, int size,  int searchElement, int* comps) {
    int i = 0;
    while (INC_COMPARES(comps) && i < size && INC_COMPARES(comps) && a[i] != searchElement) {
        if (INC_COMPARES(comps) && a[i] > searchElement)
           i = size - 1;
        
        i++;
    }

    return i;
}
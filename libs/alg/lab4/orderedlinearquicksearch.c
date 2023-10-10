#include <lab4/search.h>

int orderedLinearQuickSearch(int* a, int size,  int searchElement, int* comps) {
    int i = 0;
    while (INC_COMPARES(comps) && i < size) {
        if (INC_COMPARES(comps) && a[i] > searchElement)
           return size;

        if (INC_COMPARES(comps) && a[i] == searchElement)
           return i;
        
        i++;
    }

    return size;
}
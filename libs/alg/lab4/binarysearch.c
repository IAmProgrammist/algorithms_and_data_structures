#include <lab4/search.h>

int orderedBinarySearch(int* a, int size, int searchElement, int* comps) {
    int left = 0, right = size - 1;

    while (INC_COMPARES(comps) && left <= right) {
        int middle = left + (right - left) / 2;

        if (INC_COMPARES(comps) && a[middle] < searchElement) 
            left = middle + 1;
        else if (INC_COMPARES(comps) && a[middle] > searchElement)
            right = middle - 1;
        else
            return middle;
    }
    
    return size;
}
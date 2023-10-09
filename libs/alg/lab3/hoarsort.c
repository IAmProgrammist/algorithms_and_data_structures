#include "sorts.h"

#include <malloc.h>

void hoarSort(int *data, int size, int *comps) {
    if (INC_COMPARES(comps) && size <= 1) return;

    int i = 0, j = size - 1;
    int midElement = data[size / 2];
    while (INC_COMPARES(comps)) {
        if (INC_COMPARES(comps) && data[i] < midElement) {
            i++;
            continue;
        }

        if (INC_COMPARES(comps) && data[j] > midElement) {
            j--;
            continue;
        }

        if (INC_COMPARES(comps) && i >= j)
            break;

        swap(data + (i++), data + (j--));
    }

    hoarSort(data, i, comps);
    hoarSort(data + i, size - i, comps);
}
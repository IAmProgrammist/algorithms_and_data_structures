#include "sorts.h"

#include <malloc.h>

void hoarSort(int *data, int size, int *comps) {
    if (size <= 1) return;

    int i = 0, j = size - 1;
    int midElement = data[size / 2];
    while (1) {
        if (++(*comps) && data[i] < midElement) {
            i++;
            continue;
        }

        if (++(*comps) && data[j] > midElement) {
            j--;
            continue;
        }

        if (i >= j)
            break;

        swap(data + (i++), data + (j--));
    }

    hoarSort(data, i, comps);
    hoarSort(data + i, size - i, comps);
}
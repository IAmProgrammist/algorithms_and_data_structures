#include "sorts.h"

void selectionSort(int* data, int size, int* comps) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (INC_COMPARES(comps) && data[j] < data[minIndex])
                minIndex = j;
        }

        swap(data + i, data + minIndex);
    }
}
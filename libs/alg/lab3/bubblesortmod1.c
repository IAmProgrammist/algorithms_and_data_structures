#include "sorts.h"

#include <stdbool.h>

void bubbleSortMod1(int* data, int size, int* comps) {
    for (int i = 0; i < size; i++) {
        bool anyCompsDone = false;

        for (int j = size - 1; j > i; j--) {
            if (++(*comps) && data[j] < data[j - 1]) {
                swap(data + j, data + j - 1);
                anyCompsDone = true;
            }
        }

        if (!anyCompsDone)
            break;
    }
}
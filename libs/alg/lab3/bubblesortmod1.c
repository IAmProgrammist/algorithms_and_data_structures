#include "sorts.h"

#include <stdbool.h>

void bubbleSortMod1(int* data, int size, int* comps) {
    for (int i = 0; INC_COMPARES(comps) && i < size; i++) {
        bool anyCompsDone = false;

        for (int j = size - 1; INC_COMPARES(comps) && j > i; j--) {
            if (INC_COMPARES(comps) && data[j] < data[j - 1]) {
                swap(data + j, data + j - 1);
                anyCompsDone = true;
            }
        }

        if (!anyCompsDone)
            break;
    }
}
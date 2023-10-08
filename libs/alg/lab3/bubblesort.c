#include "sorts.h"

void bubbleSort(int* data, int size, int* comps) {
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (++(*comps) && data[j] < data[j - 1])
                swap(data + j, data + j - 1);
        }
    }
}
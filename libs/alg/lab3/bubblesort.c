#include <lab3/sorts.h>

void bubbleSort(int* data, int size, int* comps) {
    for (int i = 0; INC_COMPARES(comps) && i < size; i++) {
        for (int j = size - 1; INC_COMPARES(comps) && j > i; j--) {
            if (INC_COMPARES(comps) && data[j] < data[j - 1])
                swap(data + j, data + j - 1);
        }
    }
}
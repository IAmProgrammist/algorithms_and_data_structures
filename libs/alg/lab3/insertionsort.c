#include <lab3/sorts.h>

#include <string.h>

void insertionSort(int* data, int size, int* comps) {
    for (int i = 1; INC_COMPARES(comps) && i < size; i++) {
        int j = i - 1;
        while (INC_COMPARES(comps) && j >= 0 && INC_COMPARES(comps) && data[j] > data[i])
            j--;

        int element = data[i];
        memcpy(data + j + 2, data + j + 1, (i - j - 1) * sizeof(int));
        data[j + 1] = element;
    }
}
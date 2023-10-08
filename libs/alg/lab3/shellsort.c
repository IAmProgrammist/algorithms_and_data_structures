#include "sorts.h"

#include <math.h>

void shellSort(int* data, int size, int* comps) {
    int t = log2(size) / log2(3) - 1;
    t = t < 0 ? 0 : t;

    int h = 1;
    for (int i = 0; i < t; i++) 
        h = h * 3 + 1;

    while (h >= 1) {
        for (int i = h; i < size; i++) {
            int j = i;
            
            while (j - h >= 0 && ++(*comps) && data[j - h] > data[j]) {
                swap(data + j - h, data + j);
                j -= h;
            }
        }

        h = (h - 1) / 3;
    }
}
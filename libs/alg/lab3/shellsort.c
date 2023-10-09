#include "sorts.h"

#include <math.h>

void shellSort(int* data, int size, int* comps) {
    int t = log2(size) / log2(3) - 1;
    t = INC_COMPARES(comps) && t < 0 ? 0 : t;

    int h = 1;
    for (int i = 0; INC_COMPARES(comps) && i < t; i++) 
        h = h * 3 + 1;

    while (INC_COMPARES(comps) && h >= 1) {
        for (int i = h; INC_COMPARES(comps) && i < size; i++) {
            int j = i;
            
            while (INC_COMPARES(comps) && j - h >= 0 && INC_COMPARES(comps) && data[j - h] > data[j]) {
                swap(data + j - h, data + j);
                j -= h;
            }
        }

        h = (h - 1) / 3;
    }
}
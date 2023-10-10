#include <lab4/search.h>

#include <math.h>

int orderedBlockSearch(int* a, int size, int searchElement, int* comps) {
    int blockSize = sqrtl(size);
    int blocksAmount = size / blockSize + size % blockSize;
    for (int i = 0; INC_COMPARES(comps) && i < blocksAmount; i++) {
        int blockBeginIndex = i * blockSize;
        int blockEndIndex = (i + 1) * blockSize;
        blockEndIndex = INC_COMPARES(comps) && blockEndIndex > size ? size : blockEndIndex;

        if (INC_COMPARES(comps) && a[blockEndIndex - 1] < searchElement) continue;

        int j = blockBeginIndex;
        while (INC_COMPARES(comps) && j < blockEndIndex && INC_COMPARES(comps) && a[j] != searchElement) {
            if (INC_COMPARES(comps) && a[j] > searchElement)
                j = size - 1;
            
            j++;
        }

        return j;
    }

    return size;
}
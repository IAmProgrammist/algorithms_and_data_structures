#include "../libs/alg/algc.h"

#include <assert.h>
#include <time.h>
#include <stdio.h>

int main() {
    srand(time(0));

    int d[10] = {1, 7, 5, 42, -9, 12, 4, 11, 90, 42};
    int comps = 0;
    heapSort(d, 10, &comps);
    assert(isOrdered(d, 10));

    int a[10];
    genOrdered(a, 10);
    comps = 0;
    heapSort(a, 10, &comps);
    assert(isOrdered(a, 10));

    int b[10];
    genOrderedBackwards(b, 10);
    comps = 0;
    heapSort(b, 10, &comps);
    assert(isOrdered(b, 10));

    int c[10];
    genRandom(c, 10);
    comps = 0;
    heapSort(c, 10, &comps);
    assert(isOrdered(c, 10));

    printf("Done!");
    return 0;
}
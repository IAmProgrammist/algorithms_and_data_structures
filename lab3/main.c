#include "../libs/alg/algc.h"

#include <assert.h>
#include <time.h>
#include <stdio.h>

int main() {
    srand(time(0));

    int a[10];
    genOrdered(a, 10);
    int comps = 0;
    hoarSort(a, 10, &comps);
    assert(isOrdered(a, 10));

    int b[10];
    genOrderedBackwards(b, 10);
    comps = 0;
    hoarSort(b, 10, &comps);
    assert(isOrdered(b, 10));

    int c[10];
    genRandom(c, 10);
    comps = 0;
    hoarSort(c, 10, &comps);
    assert(isOrdered(c, 10));

    printf("Done!");
    return 0;
}
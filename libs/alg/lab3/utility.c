#include "sorts.h"

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

bool isOrdered(int* a, int size) {
    for (int i = 0; i < size - 1; i++)
        if (a[i] > a[i + 1]) return false;

    return true;
}

bool isOrderedBackwards(int* a, int size) {
    for (int i = 0; i < size - 1; i++) 
        if (a[i] < a[i + 1]) return false;
    
    return true;
}

void genOrdered(int *a, int size) {
    int current = INT_MIN;

    for (int i = 0; i < size; i++) {
        a[i] = current;
        current += rand() % RAND_MAX;
    }
}

void genOrderedBackwards(int *a, int size) {
    int current = INT_MAX;

    for (int i = 0; i < size; i++) {
        a[i] = current;
        current -= rand() % RAND_MAX;
    }
}

void genRandom(int *a, int size) {
    for (int i = 0; i < size; i++)
        a[i] = rand() % RAND_MAX;
}
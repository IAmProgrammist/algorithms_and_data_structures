#include <lab3/sorts.h>

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

void comparesExperiment(SortingFunction function, char *sortingFunctionName, int low, int high, int step) {
    printf("==============================================\n\n");
    printf("Launching comparing experiment for function %s\n", sortingFunctionName);

    printf("\nOrdered array results:\n");
    for (int i = low; i <= high; i += step) {
        int* array = malloc(i * sizeof(int));
        genOrdered(array, i);
        int compares = 0;
        function(array, i, &compares);
        assert(isOrdered(array, i));
        printf("For %3d elements: %7d compares\n", i, compares);
    }

    printf("\nOrdered backwards array results:\n");
    for (int i = low; i <= high; i += step) {
        int* array = malloc(i *sizeof(int));
        genOrderedBackwards(array, i);
        int compares = 0;
        function(array, i, &compares);
        assert(isOrdered(array, i));
        printf("For %3d elements: %7d compares\n", i, compares);
    }

    printf("\nRandom order array results:\n");
    for (int i = low; i <= high; i += step) {
        int* array = malloc(i * sizeof(int));
        genRandom(array, i);
        int compares = 0;
        function(array, i, &compares);
        assert(isOrdered(array, i));
        printf("For %3d elements: %7d compares\n", i, compares);
    }

    printf("\n");
}
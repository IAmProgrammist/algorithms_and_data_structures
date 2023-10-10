#include <lab4/search.h>

#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void comparesSearchExperiment(SearchingFunction function, char *searchingFunctionName, int low, int high, int step) {
    printf("==============================================\n\n");
    printf("Launching comparing experiment for function %s\n\n", searchingFunctionName);

    for (int i = low; i <= high; i += step) {
        int sumCompares = 0;
        int maxCompares = INT_MIN;
        for (int j = 0; j < SEARCH_UTILITY_EXPERIMENT_ITERATIONS_AMOUNT; j++) {
            int* array = malloc((i + 1) * sizeof(int));
            genRandom(array, i);
            int compares = 0;
            int randomIndex = rand() % i;
            int foundIndex = function(array, i, array[randomIndex], &compares);
            sumCompares += compares;
            maxCompares = compares > maxCompares ? compares : maxCompares;
            assert(array[foundIndex] == array[randomIndex]);
            free(array);
        }

        int avgCompares = sumCompares / SEARCH_UTILITY_EXPERIMENT_ITERATIONS_AMOUNT;
        printf("For %3d elements. Average: %7d compares; maximum: %7d compares\n", i, avgCompares, maxCompares);
    }

    printf("\n");
}

void comparesOrderedSearchExperiment(SearchingFunction function, char *searchingFunctionName, int low, int high, int step) {
    printf("==============================================\n\n");
    printf("Launching comparing experiment for function %s\n\n", searchingFunctionName);

    for (int i = low; i <= high; i += step) {
        int sumCompares = 0;
        int maxCompares = INT_MIN;
        for (int j = 0; j < SEARCH_UTILITY_EXPERIMENT_ITERATIONS_AMOUNT; j++) {
            int* array = malloc((i + 1) * sizeof(int));
            genOrdered(array, i);
            int compares = 0;
            int randomIndex = rand() % i;
            int foundIndex = function(array, i, array[randomIndex], &compares);
            sumCompares += compares;
            maxCompares = compares > maxCompares ? compares : maxCompares;
            assert(array[foundIndex] == array[randomIndex]);
            free(array);
        }

        int avgCompares = sumCompares / SEARCH_UTILITY_EXPERIMENT_ITERATIONS_AMOUNT;
        printf("For %3d elements. Average: %7d compares; maximum: %7d compares\n", i, avgCompares, maxCompares);
    }

    printf("\n");
}
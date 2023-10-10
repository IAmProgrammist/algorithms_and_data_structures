#include <lab4/search.h>

#include <limits.h>

void comparesSearchExperiment(SearchingFunction function, char *searchingFunctionName, int low, int high, int step) {
    printf("==============================================\n\n");
    printf("Launching comparing experiment for function %s\n", searchingFunctionName);

    for (int i = low; i <= high; i += step) {
        int sum = 0;
        int maxComps = INT_MIN;
        for (int i = 0; i < 1000; i++) {
            int* array = malloc(i * sizeof(int));
            genRandom(array, i);
            int compares = 0;
            int index = function(array, i, array[rand() % i], &compares);
            assert(array[index]);
        }
        printf("For %3d elements: %7d compares\n", i, compares);
    }

    printf("\n");
}
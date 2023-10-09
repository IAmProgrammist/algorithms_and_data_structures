#include "../libs/alg/algc.h"

#include <assert.h>
#include <time.h>
#include <stdio.h>

#define LOW 5
#define HIGH 45
#define STEP 5

int main() {
    srand(time(0));

    comparesExperiment(insertionSort, "insertion sort", LOW, HIGH, STEP);
    comparesExperiment(selectionSort, "selection sort", LOW, HIGH, STEP);
    comparesExperiment(bubbleSort, "bubble sort", LOW, HIGH, STEP);
    comparesExperiment(bubbleSortMod1, "bubble sort first modification", LOW, HIGH, STEP);
    comparesExperiment(bubbleSortMod2, "bubble sort second modification", LOW, HIGH, STEP);
    comparesExperiment(shellSort, "shell sort", LOW, HIGH, STEP);
    comparesExperiment(hoarSort, "quick sort", LOW, HIGH, STEP);
    comparesExperiment(heapSort, "heap sort", LOW, HIGH, STEP);

    return 0;
}
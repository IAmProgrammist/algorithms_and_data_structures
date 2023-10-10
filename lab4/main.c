#include <time.h>

#include <algc.h>

#define LOW 50
#define HIGH 450
#define STEP 50

int main() {
    srand(time(0));

    comparesSearchExperiment       (linearSearch,             "linear search",                          LOW, HIGH, STEP);
    comparesSearchExperiment       (linearQuickSearch,        "quick linear search",                    LOW, HIGH, STEP);
    comparesOrderedSearchExperiment(orderedLinearQuickSearch, "quick linear search for ordered arrays", LOW, HIGH, STEP);
    comparesOrderedSearchExperiment(orderedBinarySearch,      "binary search",                          LOW, HIGH, STEP);
    comparesOrderedSearchExperiment(orderedBlockSearch,       "block search",                           LOW, HIGH, STEP);

    return 0;
}
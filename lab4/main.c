#include <lab4/search.h>

#include <assert.h>

int main() {
    comparesSearchExperiment       (linearSearch,             "linear search",                          50, 450, 50);
    comparesSearchExperiment       (linearQuickSearch,        "quick linear search",                    50, 450, 50);
    comparesOrderedSearchExperiment(orderedLinearQuickSearch, "quick linear search for ordered arrays", 50, 450, 50);
    comparesOrderedSearchExperiment(orderedBinarySearch,      "binary search",                          50, 450, 50);
    comparesOrderedSearchExperiment(orderedBlockSearch,       "block search",                           50, 450, 50);

    return 0;
}
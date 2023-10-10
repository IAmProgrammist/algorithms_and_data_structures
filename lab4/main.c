#include <lab4/search.h>

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    orderedBinarySearch(a, 10, 3, 0);

    comparesSearchExperiment       (linearSearch,             "linear search",                          50, 450, 50);
    comparesSearchExperiment       (linearQuickSearch,        "quick linear search",                    50, 450, 50);
    comparesOrderedSearchExperiment(orderedLinearQuickSearch, "quick linear search for ordered arrays", 50, 450, 50);
    comparesOrderedSearchExperiment(orderedBinarySearch,      "binary search",                          50, 450, 50);
    //comparesOrderedSearchExperiment(orderedBlockSearch,       "block search",                           50, 450, 50);

    return 0;
}
#include <stdio.h>

#include "../../libs/alg/algc.h"

typedef enum {red, yellow, green} colors;

int main() {
    char charVarA = -12;
    PrintVar(&charVarA, sizeof(charVarA));
    printf("\n");
    char charVarB = 55;
    PrintVar(&charVarB, sizeof(charVarB));
    printf("\n");
    printf("\n");

    float floatVarA = 12.5;
    PrintVar(&floatVarA, sizeof(floatVarA));
    printf("\n");
    float floatVarB = -431.75;
    PrintVar(&floatVarB, sizeof(floatVarB));
    printf("\n");
    printf("\n");

    colors colorsVarA = red;
    PrintVar(&colorsVarA, sizeof(colorsVarA));
    printf("\n");
    colors colorsVarB = green;
    PrintVar(&colorsVarB, sizeof(colorsVarB));
    printf("\n");

    return 0;
}

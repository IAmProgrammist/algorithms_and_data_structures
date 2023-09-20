#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../../libs/alg/algc.h"

int main() {
    assert(strByteToSignedChar("11110100") == -12);
    assert(strByteToSignedChar("00110111") == 55);
    assert(strByteToFloat("01000001010010000000000000000000") == 12.5);
    assert(strByteToFloat("11000011110101111110000000000000") == -431.75);
    assert(strByteToEnumColors("00000000000000000000000000000000") == red);
    assert(strByteToEnumColors("00000000000000000000000000000010") == green);
    printf("Tests done!");

    return 0;
}
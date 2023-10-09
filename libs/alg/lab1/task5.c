#include <stdio.h>

#include <algc.h>

void PrintByte(unsigned char *a) {
    for (int bitIndex = 7; bitIndex >= 0; bitIndex--) {
        int bit = ((*a) >> bitIndex) & 1;
        printf("%d", bit);
    }
}

void PrintVar(void *a, unsigned int size) {
    for (int i = size - 1; i >= 0; i--) {
        PrintByte(a + i);
        printf(" ");
    }
}
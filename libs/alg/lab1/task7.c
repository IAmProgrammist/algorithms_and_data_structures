#include <stdlib.h>

#include <algc.h>

char strByteToSignedChar(char *in) {
    char *dat = strByteToByteArray(in);
    char val = *((char*)dat);

    free(dat);

    return val;
}

float strByteToFloat(char *in) {
    char *dat = strByteToByteArray(in);
    float val = *((float*)dat);

    free(dat);

    return val;
}

colors strByteToEnumColors(char *in) {
    char *dat = strByteToByteArray(in);
    colors val = *((colors*)dat);

    free(dat);

    return val;
}

char *strByteToByteArray(char *S) {
    int len = 0;
    int input;
    while (S[len] != '\0') {
        len++;
    }
    
    int bitSize = len;
    int byteSize = (bitSize) / 8 + ((bitSize) % 8 != 0);
    char *B = malloc(byteSize);
    for (int i = 0; i < bitSize; i++) {
        B[byteSize - 1 - (i / 8)] |= ((S[i] == '1') << (8 - 1 - (i % 8)) );
    }
    
    return B;
}
#ifndef ALG_AND_DATA_STRUCTURES_ALGC_H
#define ALG_AND_DATA_STRUCTURES_ALGC_H

#ifdef __cplusplus
extern "C"
{
#endif

    void PrintByte(unsigned char *a);

    void PrintVar(void *a, unsigned int size);

    typedef enum
    {
        red,
        yellow,
        green
    } colors;

    char strByteToSignedChar(char *in);

    float strByteToFloat(char *in);

    colors strByteToEnumColors(char *in);

    char *strByteToByteArray(char *in);

    #include <lab2/string.h>
    #include <lab3/sorts.h>
    #include <lab4/search.h>
    #include <lab5/singlyconnectedlist.h>
    #include <lab6/stack.h>
    #include <lab6/queue.h>

#ifdef __cplusplus
}
#endif

#endif // ALG_AND_DATA_STRUCTURES_ALGC_H

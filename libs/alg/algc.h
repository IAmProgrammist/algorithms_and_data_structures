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

    #define OK 0
    #define BUFFER_OVERFLOW 1
    #define INVALID_FORMAT 2
    #define OUT_OF_BOUNDS 3

    int StrError; // Переменная ошибок

    typedef char string1[256];

    // Признак конца строки - символ '\0'
    void WriteToStr(string1 st, char *s);
    void WriteFromStr(char *s, string1 st);
    void InputStr(string1 s);
    void OutputStr(string1 s);
    int Comp(string1 s1, string1 s2);
    void Delete(string1 s, unsigned Index, unsigned Count);
    void Insert(string1 Subs, string1 s, unsigned Index);
    unsigned Length(string1 s);
    void Concat(string1 s1, string1 s2, string1 srez);
    void Copy(string1 s, unsigned Index, unsigned Count, string1 Subs);
    unsigned Pos(string1 SubS, string1 s);
    unsigned StrCSpn(string1 s, string1 s1);
#ifdef __cplusplus
}
#endif

#endif // ALG_AND_DATA_STRUCTURES_ALGC_H

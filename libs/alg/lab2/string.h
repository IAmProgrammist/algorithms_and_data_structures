#ifndef STRING
#define STRING

extern const int OK;
extern const int BUFFER_OVERFLOW;
extern const int INVALID_FORMAT;
extern const int OUT_OF_BOUNDS;

extern int StrError; // Переменная ошибок

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

#endif
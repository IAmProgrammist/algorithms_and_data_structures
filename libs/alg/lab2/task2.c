#include "../algc.h"

#include <stdio.h>

unsigned Length(string1 s) {
    for (unsigned i = 0; i < sizeof(string1); i++) {
        if (s[i] == '\0')
            return i;
    }

    StrError = INVALID_FORMAT;
}

// Признак конца строки - символ '\0'
void WriteToStr(string1 st, char *s) {
    for (int i = 0; i < sizeof(string1); i++) {
        st[i] = s[i];

        if (s[i] == '\0') {
            StrError = OK;
            return;
        }
    }

    // В случае, если s окажется слишком большим, будем укорачивать строку 
    // до размера буфера.
    StrError = BUFFER_OVERFLOW;
    st[sizeof(string1) - 1] = '\0';
}

void WriteFromStr(char *s, string1 st) {
    for (int i = 0; i < sizeof(string1); i++) {
        s[i] = st[i];

        if (st[i] == '\0') {
            StrError = OK;
            return;
        }
    }

    // В исходной строке st не было ноль-символа, что говорит о
    // некорректном формате строки. В строку s, куда пишем информацию,
    // запишем ноль-символ для предоствращения дальнейших ошибок.
    StrError = INVALID_FORMAT;
    s[sizeof(string1) - 1] = '\0';
}

void InputStr(string1 s) {
    for (int i = 0; i < sizeof(string1); i++) {
        int input = getchar();

        if (input == '\n') {
            s[i] = '\0';
            StrError = OK;
            return;
        } else s[i] = input;
    }
    
    s[sizeof(string1) - 1] = '\0';
    StrError = BUFFER_OVERFLOW;
}

void OutputStr(string1 s) {
    for (int i = 0; i < sizeof(string1); i++) {
        if (s[i] == '\0') {
            StrError = OK;
            return;
        }

        putc(s[i], stdout);
    }
    
    // Строка не содержит конца, поэтому присваиваем ошибку
    StrError = INVALID_FORMAT;
}

int Comp(string1 s1, string1 s2) {
    for (int i = 0; i < sizeof(string1); i++) {
        if (s1[i] != s2[i] || (s1[i] == '\0' || s2[i] == '\0')) {
            StrError = OK;
            return s1[i] - s2[i];
        }
    }

    // Строки не содержат конца
    StrError = INVALID_FORMAT;
    return 0;
}

void Delete(string1 s, unsigned Index, unsigned Count) {
    int strlen = Length(s);
    if (StrError != OK)
        return;

    if (Index >= strlen) {
        StrError = OUT_OF_BOUNDS;
        return;
    }

    // +1 для нуль-символа
    for (int i = Index; i < Index + strlen - Count + 1; i++) {
        s[i] = s[i] + Count;
    }
}

void Insert(string1 Subs, string1 s, unsigned Index) {
    int substrlen = Length(Subs);
    if (StrError != OK)
        return;

    int strlen = Length(s);
    if (StrError != OK)
        return;

    if (Index > strlen) {
        StrError = OUT_OF_BOUNDS;
        return;
    }

    if (strlen + substrlen + 1 > sizeof(string1)) {
        StrError = BUFFER_OVERFLOW;
        return;
    }
    
    for (int i = strlen + substrlen; i >= (Index + substrlen); i--) {
        s[i] = s[i - substrlen];
    }

    for (int i = 0; i < substrlen; i++) {
        s[Index + i] = Subs[i];
    }
}
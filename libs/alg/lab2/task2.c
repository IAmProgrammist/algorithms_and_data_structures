#include "string.h"

#include <stdio.h>
#include <stdbool.h>

const int OK = 0;
const int BUFFER_OVERFLOW = 1;
const int INVALID_FORMAT = 2;
const int OUT_OF_BOUNDS = 3;

int StrError = OK;

unsigned Length(string1 s)
{
    for (unsigned i = 0; i < sizeof(string1); i++)
    {
        if (s[i] == '\0')
        {
            StrError = OK;
            return i;
        }
    }

    StrError = INVALID_FORMAT;
}

// Признак конца строки - символ '\0'
void WriteToStr(string1 st, char *s)
{
    for (int i = 0; i < sizeof(string1); i++)
    {
        st[i] = s[i];

        if (s[i] == '\0')
        {
            StrError = OK;
            return;
        }
    }

    // В случае, если s окажется слишком большим, будем укорачивать строку
    // до размера буфера.
    StrError = BUFFER_OVERFLOW;
    st[sizeof(string1) - 1] = '\0';
}

void WriteFromStr(char *s, string1 st)
{
    for (int i = 0; i < sizeof(string1); i++)
    {
        s[i] = st[i];

        if (st[i] == '\0')
        {
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

void InputStr(string1 s)
{
    for (int i = 0; i < sizeof(string1); i++)
    {
        int input = getchar();

        if (input == '\n')
        {
            s[i] = '\0';
            StrError = OK;
            return;
        }
        else
            s[i] = input;
    }

    s[sizeof(string1) - 1] = '\0';
    StrError = BUFFER_OVERFLOW;
}

void OutputStr(string1 s)
{
    for (int i = 0; i < sizeof(string1); i++)
    {
        if (s[i] == '\0')
        {
            StrError = OK;
            return;
        }

        putc(s[i], stdout);
    }

    // Строка не содержит конца, поэтому присваиваем ошибку
    StrError = INVALID_FORMAT;
}

int Comp(string1 s1, string1 s2)
{
    for (int i = 0; i < sizeof(string1); i++)
    {
        if (s1[i] != s2[i] || (s1[i] == '\0' || s2[i] == '\0'))
        {
            StrError = OK;
            int diff = s1[i] - s2[i];
            return diff > 0 ? 1 : diff < 0 ? -1
                                           : 0;
        }
    }

    // Строки не содержат конца
    StrError = INVALID_FORMAT;
    return 0;
}

void Delete(string1 s, unsigned Index, unsigned Count)
{
    if (Count == 0)
    {
        StrError = OK;
        return;
    }

    int strlen = Length(s);
    if (StrError != OK)
        return;

    if (Index + Count - 1 >= strlen)
    {
        StrError = OUT_OF_BOUNDS;
        return;
    }

    // +1 для нуль-символа
    for (int i = Index; i < Index + strlen - Count + 1; i++)
    {
        s[i] = s[i + Count];
    }

    StrError = OK;
}

void Insert(string1 Subs, string1 s, unsigned Index)
{
    int substrlen = Length(Subs);
    if (StrError != OK)
        return;

    int strlen = Length(s);
    if (StrError != OK)
        return;

    if (Index > strlen)
    {
        StrError = OUT_OF_BOUNDS;
        return;
    }

    if (strlen + substrlen + 1 > sizeof(string1))
    {
        StrError = BUFFER_OVERFLOW;
        return;
    }

    for (int i = strlen + substrlen; i >= (int)Index + substrlen; i--)
    {
        s[i] = s[i - substrlen];
    }

    for (int i = 0; i < substrlen; i++)
    {
        s[Index + i] = Subs[i];
    }
}

void Concat(string1 s1, string1 s2, string1 srez)
{
    unsigned s1len = Length(s1);
    if (StrError != OK)
        return;

    int i;
    for (i = 0; i < s1len; i++)
    {
        srez[i] = s1[i];
    }

    for (int j = 0; i < sizeof(string1); i++, j++)
    {
        srez[i] = s2[j];
        if (srez[i] == '\0')
        {
            StrError = OK;
            return;
        }
    }

    srez[i] = '\0';
    StrError = BUFFER_OVERFLOW;
}

void Copy(string1 s, unsigned Index, unsigned Count, string1 Subs)
{
    if (Count >= sizeof(string1))
    {
        StrError = BUFFER_OVERFLOW;
        return;
    }

    int strlen = Length(s);
    if (StrError != OK)
        return;

    if (Index + Count > strlen && Count != 0)
    {
        StrError = OUT_OF_BOUNDS;
        return;
    }

    for (int i = 0; i < Count; i++)
    {
        Subs[i] = s[i + Index];
    }

    Subs[Count] = '\0';
}

unsigned Pos(string1 SubS, string1 s)
{
    int strlen = Length(s);
    if (StrError != OK)
        return -1;

    if (SubS[0] == '\0')
    {
        StrError = OK;
        return 0;
    }

    for (int i = 0; i < strlen; i++)
    {
        for (int j = 0; j < sizeof(string1); j++)
        {
            if (SubS[j] == '\0')
            {
                StrError = OK;
                return i;
            }
            else if (s[j + i] == '\0')
            {
                // Дальнейший поиск не имеет смысла, рассматриваемая подстрока больше
                // строки, в которой выполняется поиск.

                StrError = OK;
            }
            else if (s[j + i] != SubS[j])
            {
                break;
            }
        }
    }

    StrError = OK;
    return -1;
}
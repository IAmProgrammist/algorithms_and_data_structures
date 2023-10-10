#include <lab2/string.h>

unsigned StrCSpn(string1 s, string1 s1) {
    int sLen = Length(s);
    int count = 0;
    if (StrError) return 0;

    for (int i = 0; i < sLen; i++) {
        string1 search;
        search[0] = s[i];
        search[1] = '\0';

        if (Pos(search, s1) == -1 && !StrError)
            count++;
    }

    return count;
}
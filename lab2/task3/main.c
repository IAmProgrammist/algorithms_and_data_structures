#include "../../libs/alg/algc.h"

#include <stdio.h>

int main()
{
    do
    {
        string1 input;
        do
        {
            printf("Enter origin string: ");
            fflush(stdout);
            InputStr(input);
        } while (StrError != OK);

        string1 filter;
        do
        {
            printf("Enter filter string: ");
            fflush(stdout);
            InputStr(filter);
        } while (StrError != OK);

        int left = StrCSpn(input, filter);
        switch (StrError)
        {
        case OK:
            printf("Characters left after filter: %d", left);
            fflush(stdout);
            break;
        case BUFFER_OVERFLOW:
            printf("An error accured during execution: buffer was overflown.\n");
            fflush(stdout);
            break;
        case INVALID_FORMAT:
            printf("An error accured during execution: invalid format.\n");
            fflush(stdout);
            break;
        case OUT_OF_BOUNDS:
            printf("An error accured during execution: out of bounds.\n");
            fflush(stdout);
            break;
        }
    } while(StrError != OK);

    return 0;
}
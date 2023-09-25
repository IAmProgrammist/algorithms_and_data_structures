#include "../libs/alg/algc.h"

int main() {
    string1 str;
    string1 substr;

    WriteToStr(str, "Radio Tapok");
    WriteToStr(substr, "");

    Insert(substr, str, 0);

    OutputStr(str);
}
#include <algc.h>
#include <ctype.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

int main() {
    InitTree(TreeBufferSize);
    Tree fromBrackets = CreateRoot();
    int res = BuildTree(fromBrackets, "(A(B(C)(D))(e(F)(G)(H)))");

    if (res == -1) {
        printf("unable to parse");
        return 1;
    }

    Tree secondRoot = CreateRoot();
    CopyTree(secondRoot, fromBrackets);
    assert(CompTree(fromBrackets, secondRoot));

    return 0;
}
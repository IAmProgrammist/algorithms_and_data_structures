#include <algc.h>
#include <ctype.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#define NAME_BUFFER_SIZE 100

int _BuildTree(Tree T, char* input) {
    char* startInput = input;
    while (isspace(*input))
        input++;
    
    if (*input != '(')
        return -1;
    
    input++;

    char *buffer = calloc(NAME_BUFFER_SIZE, sizeof(char));
    int bufferIndex = 0;
    bool shouldWriteData = true;
    bool anyChild = false;

    while (*input != ')') {
        if (*input == '\0')
            return -1;
        else if (*input == '(') {
            if (shouldWriteData) {
                WriteDataTree(T, buffer);
                shouldWriteData = false;
            }

            size_t newIndex = NewMem();
            if (!anyChild) { 
                anyChild = true;
                MemTree[T].RSon = newIndex;
            } else 
                MemTree[T].LSon = newIndex;

            int res = _BuildTree(newIndex, input);
            if (res == -1) return -1;

            input += res + 1;
            T = newIndex;
        } else if (shouldWriteData)
            buffer[bufferIndex] = *(input++);
        else input++;
    }

    if (shouldWriteData) WriteDataTree(T, buffer);

    return input - startInput;
}

void BuildTree(Tree T) {
    char brackets[] = "(A(B(C)(D))(e(F)(G)(H)))";
    int res = _BuildTree(T, brackets);
    if (res == -1) {
        printf("Unable to parse\n");
    }
}

int main() {
    Tree root = CreateRoot();
    InitTree(root, 1);
    BuildTree(MoveToRSon(root));
}
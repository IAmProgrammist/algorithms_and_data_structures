#include <algc.h>
#include <stdbool.h>
#include <stdlib.h>

Element MemTree[TreeBufferSize];
int TreeError = TreeOk;
size_t Size = 0;

Tree InitTree(unsigned size) {
    if (size < 1) {
        TreeError = TreeUnder;
        return 0;
    }

    if (size > TreeBufferSize) {
        TreeError = TreeNotMem;
        return 0;
    }
    Size = size;

    TreeError = TreeOk;
    InitMem();

    return 0;
}

void InitMem() {
    TreeError = TreeOk;
    if (Size < 1) {
        TreeError = TreeUnder;
        return;
    }

    if (Size > TreeBufferSize) {
        TreeError = TreeNotMem;
        return;
    }
    
    for (PtrEl i = 0; i < Size - 1; i++) {
        MemTree[i].LSon = i + 1;
    }

    MemTree[Size - 1].LSon = 0;
}

Tree CreateRoot() {
    TreeError = TreeOk;
    size_t newInd = NewMem();
    if (TreeError != TreeOk) return 0;

    MemTree[newInd].RSon = 0;
    MemTree[newInd].LSon = 0;

    return newInd;
} 


int EmptyMem() {
    TreeError = TreeOk;
    return MemTree[0].LSon == 0;
}

size_t NewMem() {
    TreeError = TreeOk;
    PtrEl result = MemTree[0].LSon;
    if (result == 0) {
        TreeError = TreeNotMem;
        return 0;
    }

    MemTree[0].LSon = MemTree[result].LSon;
    return result;
}

void DisposeMem(size_t n) {
    TreeError = TreeOk;
    if (n == 0) return;

    PtrEl oldElement = MemTree[0].LSon;
    MemTree[0].LSon = n;
    MemTree[n].LSon = oldElement;
}

void WriteDataTree(Tree T, TreeBaseType E) {
    TreeError = TreeOk;
    MemTree[T].data = E;
}

TreeBaseType ReadDataTree(Tree T) {
    TreeError = TreeOk;
    return MemTree[T].data;
}

int IsLSon(Tree T) {
    TreeError = TreeOk;
    return MemTree[T].LSon != 0;
}

int IsRSon(Tree T) {
    TreeError = TreeOk;
    return MemTree[T].RSon != 0;
}

Tree MoveToLSon(Tree T) {
    if (IsLSon(T)) return MemTree[T].LSon;

    TreeError = TreeUnder;
    return 0;
}

Tree MoveToRSon(Tree T) {
    if (IsRSon(T)) return MemTree[T].RSon;

    TreeError = TreeUnder;
    return 0;
}

int IsEmptyTree(Tree T) {
    TreeError = TreeOk;
    return MemTree[T].RSon == 0 && MemTree[T].LSon == 0;
}

void DelTree(Tree T) {
    TreeError = TreeOk;
    // Please do not the important
    if (T == 0)
        return;

    DelTree(MemTree[T].RSon);
    DelTree(MemTree[T].LSon);

    DisposeMem(T);
}

#define NAME_BUFFER_SIZE 100

int BuildTree(Tree T, char* input) {
    MemTree[T].RSon = 0;
    MemTree[T].LSon = 0;
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

            int res = BuildTree(newIndex, input);
            if (res == -1) return -1;

            input += res + 1;
            T = newIndex;
            MemTree[T].LSon = 0;
        } else if (shouldWriteData)
            buffer[bufferIndex] = *(input++);
        else input++;
    }

    if (shouldWriteData) WriteDataTree(T, buffer);

    return input - startInput;
}

void CopyTree(Tree dst, Tree src) {
    WriteDataTree(dst, ReadDataTree(src));
    if (TreeError != TreeOk) return;

    Tree RSon;
    if ((RSon = MoveToRSon(src)) && TreeError == TreeOk) {
        Tree newTree = NewMem();
        if (TreeError != TreeOk)
            return;
        MemTree[dst].RSon = newTree;

        CopyTree(newTree, RSon);
    }

    Tree LSon;
    if ((LSon = MoveToLSon(src)) && TreeError == TreeOk) {
        Tree newTree = NewMem();
        if (TreeError != TreeOk)
            return;
        MemTree[dst].LSon = newTree;

        CopyTree(newTree, LSon);
    }
}

bool CompTree(Tree T1, Tree T2) {
    return ((ReadDataTree(T1) == ReadDataTree(T2)) && TreeError == TreeOk) && 
    (IsRSon(T1) == IsRSon(T2) ? !IsRSon(T1) || CompTree(MemTree[T1].RSon, MemTree[T2].RSon) : false ) && 
    (IsLSon(T1) == IsLSon(T2) ? !IsLSon(T1) || CompTree(MemTree[T1].LSon, MemTree[T2].LSon) : false );
}
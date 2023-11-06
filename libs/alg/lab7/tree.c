#include <algc.h>
#include <stdbool.h>
#include <stdlib.h>

Element MemTree[TreeBufferSize];
int TreeError = TreeOk;
size_t Size = 0;

#define TAKEN_ELEMENTS ((bool *)MemTree[1].data)

Tree InitTree(unsigned size) {
    if (size < 2) {
        TreeError = TreeUnder;
        return 0;
    }

    if (size > TreeBufferSize) {
        TreeError = TreeNotMem;
        return 0;
    }
    Size = size;

    InitMem();
    
    TreeError = TreeOk;
    MemTree[0].data = NULL;
    MemTree[0].LSon = 1;
    MemTree[0].RSon = 0;
    TAKEN_ELEMENTS[0] = true;

    return 0;
}

void InitMem() {
    if (Size < 2) {
        TreeError = TreeUnder;
        return;
    }

    if (Size > TreeBufferSize) {
        TreeError = TreeNotMem;
        return;
    }
    
    bool *takenElements = calloc(Size, sizeof(bool));

    MemTree[1].LSon = 0;
    MemTree[1].RSon = 0;
    MemTree[1].data = takenElements;
    TAKEN_ELEMENTS[1] = true;
}

Tree CreateRoot() {
    size_t newInd = NewMem();
    if (TreeError != TreeOk) return 0;

    TAKEN_ELEMENTS[newInd] = true;
    MemTree[newInd].data = NULL;
    MemTree[newInd].RSon = 0;
    MemTree[newInd].LSon = 0;

    return newInd;
} 


int EmptyMem() {
    TreeError = TreeOk;

    for (size_t i = 0; i < Size; i++)
        if (!TAKEN_ELEMENTS[i]) return false;

    return true;
}

size_t NewMem() {
    TreeError = TreeOk;
    for (size_t i = 0; i < Size; i++) {
        if (!TAKEN_ELEMENTS[i]) {
            TAKEN_ELEMENTS[i] = true;
            MemTree[i].data = NULL;
            MemTree[i].LSon = 0;
            MemTree[i].RSon = 0;

            return i;
        };
    }

    TreeError = TreeNotMem;
    return 0;
}

void DisposeMem(size_t n) {
    TreeError = TreeOk;
    TAKEN_ELEMENTS[n] = false;
}

void WriteDataTree(Tree T, TreeBaseType E) {
    if (!TAKEN_ELEMENTS[T]) {
        TreeError = TreeUnder;
        return;
    }

    TreeError = TreeOk;
    MemTree[T].data = E;
}

TreeBaseType ReadDataTree(Tree T) {
    if (!TAKEN_ELEMENTS[T]) {
        TreeError = TreeUnder;
        return NULL;
    }

    TreeError = TreeOk;
    return MemTree[T].data;
}

int IsLSon(Tree T) {
    if (!TAKEN_ELEMENTS[T]) {
        TreeError = TreeUnder;
        return false;
    }

    TreeError = TreeOk;
    return MemTree[T].LSon != 0 && TAKEN_ELEMENTS[MemTree[T].LSon];
}

int IsRSon(Tree T) {
    if (!TAKEN_ELEMENTS[T]) {
        TreeError = TreeUnder;
        return false;
    }

    TreeError = TreeOk;
    return MemTree[T].RSon != 0 && TAKEN_ELEMENTS[MemTree[T].RSon];
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

    return MemTree[T].RSon == 0;
}

void _DelSubTree(Tree T) {
    if (!TAKEN_ELEMENTS[T]) {
        TreeError = TreeUnder;
        return;
    }

    if (IsRSon(T))
        _DelSubTree(MemTree[T].RSon);
    MemTree[T].RSon = 0;
        
    if (IsLSon(T))
        _DelSubTree(MemTree[T].LSon);
    MemTree[T].LSon = 0;
    MemTree[T].data = NULL;
    
    DisposeMem(T);
}

void DelTree(Tree T) {
    TreeError = TreeOk;
    // Please do not the important
    if (T == 0 || T == 1)
        return;

    if (!TAKEN_ELEMENTS[T]) {
        TreeError = TreeUnder;
        return;
    }

    if (IsRSon(T)) {
        _DelSubTree(MemTree[T].RSon);
        MemTree[T].RSon = 0;
    }

    if (IsLSon(T)) {
        _DelSubTree(MemTree[T].LSon);
        MemTree[T].LSon = 0;
    }
    DisposeMem(T);
}

#define NAME_BUFFER_SIZE 100

int BuildTree(Tree T, char* input) {
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
#include <algc.h>
#include <stdbool.h>
#include <stdlib.h>

Element MemTree[TreeBufferSize];
int TreeError = TreeOk;
size_t Size = 0;

#define TAKEN_ELEMENTS ((bool *)MemTree[1].data)

Tree CreateRoot() {
    if (TreeBufferSize < 2) {
        TreeError = TreeNotMem;
        return 0;
    }

    Size = 2;
    TreeError = TreeOk;
    MemTree[0].data = NULL;
    MemTree[0].LSon = 1;
    MemTree[0].RSon = 0;

    MemTree[1].LSon = 0;
    MemTree[1].RSon = 0;
    bool *takenElements = calloc(TreeBufferSize, sizeof(bool));
    takenElements[0] = true;
    takenElements[1] = true;
    MemTree[1].data = takenElements;

    return 0;
} 

void InitTree(Tree T, unsigned size) {
    // Лист должен существовать, кроме того он должен быть именно листом, а не деревом
    if (!TAKEN_ELEMENTS[T] || IsRSon(T)) {
        TreeError = TreeUnder;
        return;
    }

    // Невозможно выделить столько листов
    if (Size + size > TreeBufferSize) {
        TreeError = TreeNotMem;
        return;
    }

    Size += size;

    // Ничего не делаем
    if (size == 0) {
        TreeError = TreeOk;
        return;
    }

    size_t ind = NewMem();
    MemTree[T].RSon = ind;
    size--;
    Tree currentTree = ind;
    MemTree[currentTree].data = NULL;
    MemTree[currentTree].RSon = 0;
    MemTree[currentTree].LSon = 0;
    TreeError = TreeOk;

    while (size != 0) {
        ind = NewMem();
        if (TreeError != TreeOk) break;

        MemTree[currentTree].LSon = ind;
        currentTree = ind;
        MemTree[currentTree].data = NULL;
        MemTree[currentTree].RSon = 0;
        MemTree[currentTree].LSon = 0;

        size--;
    }
}


int EmptyMem() {
    TreeError = TreeOk;
    return Size == TreeBufferSize;
}

size_t NewMem() {
    if (EmptyMem()) {
        TreeError = TreeNotMem;
        return 0;
    }

    TreeError = TreeOk;
    for (size_t i = 0; i < TreeBufferSize; i++) {
        if (!TAKEN_ELEMENTS[i]) {
            TAKEN_ELEMENTS[i] = true;
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

    return 0;
}

Tree MoveToRSon(Tree T) {
    if (IsRSon(T)) return MemTree[T].RSon;

    return 0;
}

int IsEmptyTree(Tree T) {
    if (!TAKEN_ELEMENTS[T]) {
        TreeError = TreeUnder;
        return false;
    }

    TreeError = TreeOk;
    return !IsRSon(T);
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
    
    TAKEN_ELEMENTS[T] = false;
}

void DelTree(Tree T) {
    TreeError = TreeOk;
    if (!TAKEN_ELEMENTS[T]) {
        TreeError = TreeUnder;
        return;
    }

    _DelSubTree(MemTree[T].RSon);
    MemTree[T].RSon = 0;
}

void InitMem() {
    TreeError = TreeOk;
    for (size_t i = 2; i < TreeBufferSize; i++)
        TAKEN_ELEMENTS[i] = false;

    MemTree[0].RSon = 0;
}
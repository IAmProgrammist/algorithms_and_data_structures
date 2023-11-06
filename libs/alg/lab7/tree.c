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
} 

void InitTree(Tree T, unsigned size) {
    // Лист должен существовать, кроме того он должен быть именно листом, а не деревом
    if (TAKEN_ELEMENTS[T] && !TAKEN_ELEMENTS[MemTree[T].RSon]) {
        TreeError = TreeUnder;
        return;
    }

    // Невозможно выделить столько листов
    if (Size + size > TreeBufferSize) {
        TreeError = TreeNotMem;
        return;
    }

    // Ничего не делаем
    if (size == 0) {
        TreeError = TreeOk;
        return;
    }

    size_t ind = NewMem();
    Tree currentTree;
    TreeError = TreeOk;
    
    while (TreeError == TreeOk) {
        if (TAKEN_ELEMENTS[MemTree[T].RSon])
            MemTree[currentTree].LSon = ind;
        else
            MemTree[T].RSon = ind;

        currentTree = ind;

        size--;
        if (size == 0) break;

        ind = NewMem();
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
        if (!TAKEN_ELEMENTS[i]) return i;
    }

    TreeError = TreeNotMem;
    return 0;
}
void DisposeMem(size_t n) {
    TreeError = TreeOk;
    TAKEN_ELEMENTS[n] = false;
}

/*void WriteDataTree(Tree T, TreeBaseType E) //запись данных
TreeBaseType ReadDataTree(Tree T)//чтение
int IsLSon(Tree T)//1 — есть левый сын, 0 — нет
int IsRSon(Tree T)//1 — есть правый сын, 0 — нет
Tree MoveToLSon(Tree T)// перейти к левому сыну, где T — адрес ячейки, содержащей адрес текущей вершины, TS — адрес ячейки, содержащей адрес корня левого поддерева(левого сына)
Tree MoveToRSon(Tree T)//перейти к правому сыну
int IsEmptyTree(Tree T)//1 — пустое дерево,0 — не пустое
void DelTree(Tree T)//удаление листа
void InitMem() /*связывает все элементы массива в список свободных
элементов*/
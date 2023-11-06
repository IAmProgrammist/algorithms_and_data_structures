#ifndef TREE
#define TREE

#include <stdint.h>

#define TreeBufferSize 1000

#define TreeOk 0
#define TreeNotMem 1
#define TreeUnder 2

typedef void* TreeBaseType;
typedef size_t PtrEl;

typedef struct {
    TreeBaseType data;
    PtrEl LSon;
    PtrEl RSon;
} Element;

typedef PtrEl Tree;

extern Element MemTree[TreeBufferSize];
extern int TreeError;
extern size_t Size;
// инициализация дерева
void InitTree(Tree T, unsigned size);

// создание корня
Tree CreateRoot(); 

//запись данных
void WriteDataTree(Tree T, TreeBaseType E); 

//чтение
TreeBaseType ReadDataTree(Tree T);

//1 — есть левый сын, 0 — нет
int IsLSon(Tree T);

//1 — есть правый сын, 0 — нет
int IsRSon(Tree T);

// перейти к левому сыну, где T — адрес ячейки, содержащей адрес текущей вершины, TS — адрес ячейки, содержащей адрес корня левого поддерева(левого сына)
Tree MoveToLSon(Tree T);

//перейти к правому сыну
Tree MoveToRSon(Tree T);

//1 — пустое дерево,0 — не пустое
int IsEmptyTree(Tree T);

//удаление листа
void DelTree(Tree T);

/*связывает все элементы массива в список свободных
элементов*/
void InitMem(); 

/*возвращает 1, если в массиве нет свободных элемен-
тов,0 — в противном случае*/
int EmptyMem(); 

/*возвращает номер свободного элемента и ис-
ключает его из ССЭ*/
size_t NewMem(); 

/*делает n-й элемент массива свободным и
включает его в ССЭ*/
void DisposeMem(size_t n);

#endif 
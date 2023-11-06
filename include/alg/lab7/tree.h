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

void InitTree(Tree T, unsigned size);// инициализация дерева
Tree CreateRoot(); //создание корня
void WriteDataTree(Tree T, TreeBaseType E); //запись данных
TreeBaseType ReadDataTree(Tree T);//чтение
int IsLSon(Tree T);//1 — есть левый сын, 0 — нет
int IsRSon(Tree T);//1 — есть правый сын, 0 — нет
Tree MoveToLSon(Tree T);// перейти к левому сыну, где T — адрес ячейки, содержащей адрес текущей вершины, TS — адрес ячейки, содержащей адрес корня левого поддерева(левого сына)
Tree MoveToRSon(Tree T);//перейти к правому сыну
int IsEmptyTree(Tree T);//1 — пустое дерево,0 — не пустое
void DelTree(Tree T);//удаление листа
void InitMem(); /*связывает все элементы массива в список свободных
элементов*/
int EmptyMem(); /*возвращает 1, если в массиве нет свободных элемен-
тов,0 — в противном случае*/
size_t NewMem(); /*возвращает номер свободного элемента и ис-
ключает его из ССЭ*/
void DisposeMem(size_t n);/*делает n-й элемент массива свободным и
включает его в ССЭ*/

#endif 
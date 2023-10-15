#ifndef SINGLY_CONNECTED_LIST
#define SINGLY_CONNECTED_LIST

const int ListOk = 0;
const int ListNotMem = 1;
const int ListUnder = 2;
const int ListEnd = 3;

typedef int BaseType;

typedef struct element *ptrel;
typedef struct element {
    BaseType data;
    ptrel next;
};

typedef struct List {
    ptrel Start;
    ptrel ptr;
    unsigned int N;
}

extern int ListError;

void InitList(List *L);
void PutList(List *L, BaseType E);
void GetList(List *L, BaseType *E);
void ReadList(List *L,BaseType *E);
int FullList(List *L);
int EndList(List *L);
unsigned int Count(List *L);
void BeginPtr(List *L);
void EndPtr(List *L);
void MovePtr(List *L);
void MoveTo(List *L, unsigned int n);
void DoneList(List *L);
void CopyList(List *L1,List *L2);

#endif
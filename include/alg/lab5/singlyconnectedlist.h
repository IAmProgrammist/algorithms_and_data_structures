#ifndef SINGLY_CONNECTED_LIST
#define SINGLY_CONNECTED_LIST

#define ListOk 0
#define ListNotMem 1
#define ListUnder 2
#define ListEnd 3

typedef int BaseType;

typedef struct element_ {
    BaseType data;
    struct element_ * next;
} element;
typedef element* ptrel;

typedef struct {
    ptrel Start;
    ptrel ptr;
    unsigned int N;
} List;

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
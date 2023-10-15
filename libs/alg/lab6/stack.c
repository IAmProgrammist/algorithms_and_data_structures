#include <lab5/singlyconnectedlist.h>
#include <lab6/stack.h>

const int StackOk = 0;
const int StackUnder = ListUnder;
const int StackOver = ListEnd;
int StackError = StackOk;

void InitStack(Stack *s) {
    List l;
    InitList(&l);

    StackError = ListError;
}

void PutStack(Stack *s, BaseType E) {
    PutList(s, E);

    StackError = ListError;
}

void GetStack(Stack *s, BaseType *E) {
    GetList(s, E);

    StackError = ListError;
} 
int EmptyStack(Stack s) {
    StackError = StackOk;

    return s.N == 0;
}

void ReadStack(Stack s, BaseType *E) {
    ReadStack(s, E);

    StackError = ListError;
} 

void DoneStack(Stack *s) {
    DoneList(s);

    StackError = ListError;
} 
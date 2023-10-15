#ifndef STACK
#define STACK

#define SINGLY_CONNECTED_LIST_CUSTOM_BASE_TYPE

#ifndef CUSTOM_BASE_TYPE
typedef int BaseType;
#endif

#include <lab5/singlyconnectedlist.h>

#define StackOk ListOk
#define StackUnder ListUnder
#define StackOver ListNotMem

extern int StackError;

typedef List Stack;

void InitStack(Stack *s);
void PutStack(Stack *s, BaseType E); 
void GetStack(Stack *s, BaseType *E); 
int EmptyStack(Stack s); 
void ReadStack(Stack *s, BaseType *E); 
void DoneStack(Stack *s); 

#endif
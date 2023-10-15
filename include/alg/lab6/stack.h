#ifndef STACK
#define STACK

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
void ReadStack(Stack s, BaseType *E); 
void DoneStack(Stack *s); 

#endif
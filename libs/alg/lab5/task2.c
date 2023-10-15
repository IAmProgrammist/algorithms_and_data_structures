#include <lab5/singlyconnectedlist.h>

#include <stddef.h>
#include <malloc.h>

int ListError = ListOk;

void InitList(List *L) {
    ptrel newElement = malloc(sizeof(element));
    if (newElement == NULL) {
        ListError = ListNotMem;
        return;
    }
    newElement->next = NULL;

    L->Start = newElement;
    L->ptr = newElement;
    L->N = 0;
}

void PutList(List *L, BaseType E) {
    ptrel newElement = malloc(sizeof(element));
    if (newElement == NULL) {
        ListError = ListNotMem;
        return;
    }

    newElement->data = E;
    newElement->next = NULL;

    ptrel currentElement = L->ptr;
    ptrel nextElement = currentElement->next;
    currentElement->next = newElement;
    newElement->next = nextElement;
    L->N++;
    ListError = ListOk;
}

void GetList(List *L, BaseType *E) {
    if (Count(L) == 0) {
        ListError = ListUnder;
        return;
    }

    if (EndList(L)) {
        ListError = ListEnd;
        return;
    }

    ptrel currentElement = L->ptr;
    *E = currentElement->next->data;
    L->N--;
    ptrel nextNextElement = currentElement->next->next;
    free(currentElement->next);
    currentElement->next = nextNextElement;
    ListError = ListOk;
}

void ReadList(List *L,BaseType *E) {
    if (Count(L) == 0) {
        ListError = ListUnder;
        return;
    }

    if (EndList(L)) {
        ListError = ListEnd;
        return;
    }

    ptrel currentElement = L->ptr;
    *E = currentElement->next->data;
    ListError = ListOk;
}

// Зачем эта функция???
int FullList(List *L) {
    ListError = ListOk;
    return 0;
}

int EndList(List *L) {
    ListError = ListOk;
    return L->ptr->next == NULL;
}

unsigned int Count(List *L) {
    ListError = ListOk;
    return L->N;
}

void BeginPtr(List *L) {
    ListError = ListOk;
    L->ptr = L->Start;
}

void EndPtr(List *L) {
    L->ptr = L->Start;

    while (L->ptr->next != NULL) {
        L->ptr = L->ptr->next;
    }
    ListError = ListOk;
}

void MovePtr(List *L) {
    if (EndList(L)) {
        ListError = ListEnd;
        return;
    }

    L->ptr = L->ptr->next;
    ListError = ListOk;
}

void MoveTo(List *L, unsigned int n) {
    BeginPtr(L);

    for (int i = 0; i < n + 1; i++) {
        if (L->ptr->next == NULL) {
            ListError = ListEnd;
            return;
        }

        MovePtr(L);
    }
    ListError = ListOk;
}

static void freeElement(ptrel element) {
    if (element == NULL)
        return;
    
    freeElement(element->next);
    free(element);
}

void DoneList(List *L) {
    EndPtr(L);
    if (ListError != ListOk)
        return;
    
    freeElement(L->Start);
    L->Start = NULL;
    L->ptr = NULL;
    L->N = 0;
    ListError = ListOk;
}

void CopyList(List *L1,List *L2) {
    do 
    {
        PutList(L2, L1->ptr->data);
        if (EndList(L1)) break;

        MovePtr(L1);
    } while (ListError == ListOk);    
}
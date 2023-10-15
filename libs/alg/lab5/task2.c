#include <lab5/singlyconnectedlist.h>

#include <stddef.h>
#include <malloc.h>

const int ListOk = 0;
const int ListNotMem = 1;
const int ListUnder = 2;
const int ListEnd = 3;

int ListError = ListOk;

void InitList(List *L) {
    L->Start = NULL;
    L->ptr = NULL;
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

    if (Count(L) == 0) {
        L->Start = newElement;
        L->ptr = newElement;
        L->N = 1;
        ListError = ListOk;
        return;
    } 

    if (L->ptr == NULL) {
        L->ptr = L->Start;

        if (L->ptr == NULL) {
            L->N = 0;
            PutList(L, E);
        }
    }

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

    if (Count(L) == 1) {
        *E = L->Start->data;
        L->Start = NULL;
        L->ptr = NULL;
        L->N = 0;
        ListError = ListOk;
        return;
    }

    ptrel currentElement = L->ptr;
    if (currentElement == NULL) {
        ListError = ListEnd;
        return;
    }    

    if (EndList(L)) {
        ListError = ListEnd;
        return;
    }

    *E = currentElement->next->data;
    L->N--;
    currentElement = currentElement->next->next;
    ListError = ListOk;
}

void ReadList(List *L,BaseType *E) {
    if (Count(L) == 0) {
        ListError = ListUnder;
        return;
    }

    if (Count(L) == 1) {
        *E = L->Start->data;
        ListError = ListOk;
        return;
    }

    ptrel currentElement = L->ptr;
    if (currentElement == NULL) {
        ListError = ListUnder;
        return;
    }    

    if (EndList(L)) {
        ListError = ListUnder;
        return;
    }

    *E = currentElement->next->data;
    ListError = ListOk;
}
int FullList(List *L) {
    return 0;
}
int EndList(List *L) {
    if (L->ptr == NULL) {
        if (Count(L) == 0) {
            ListError = ListOk;
            return 1;
        } else {
            ListError = ListUnder;
            return 0;
        }
    }

    return L->ptr->next == NULL;
}
unsigned int Count(List *L) {
    return L->N;
}
void BeginPtr(List *L) {
    L->ptr = L->Start;
}
void EndPtr(List *L) {
    L->ptr = L->Start;
    if (L->ptr == NULL) {
        ListError = ListUnder;
        return;
    }

    while (L->ptr->next != NULL) {
        L->ptr = L->ptr->next;
    }
    ListError = ListOk;
}
void MovePtr(List *L) {
    if (L->ptr == NULL || EndList(L)) {
        ListError = ListUnder;
        return;
    }

    L->ptr = L->ptr->next;
    ListError = ListOk;
}
void MoveTo(List *L, unsigned int n) {
    L->ptr = L->Start;
    if (L->ptr == NULL) {
        ListError = ListUnder;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (L->ptr->next == NULL) {
            ListError = ListEnd;
            return;
        }

        L->ptr = L->ptr->next;
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
#include "../../../include/alg/lab8/table.h"

#include <stddef.h>

int TableError = TableOk;

Table InitTable() {
    TableError = TableOk;
    Table result;
    InitList(&result);

    return result;
}

bool EmptyTable(Table *T) {
    TableError = TableOk;
    bool result = (Count(T) == 0);

    if (ListError == ListNotMem) TableError = TableNotMem;
    if (ListError == ListUnder) TableError = TableUnder;

    return result;
}

bool PutTable(Table *T, BaseType E) {
    TableError = TableOk;
    BeginPtr(T);
    while (!EndList(T) && T->ptr->next->data.Key < E.Key)
        MovePtr(T);
    
    if (T->ptr->next->data.Key == E.Key) {
        return false;
    }

    PutList(T, E);

    if (ListError == ListNotMem) {
        TableError = TableNotMem;
        return false;
    }

    return true;
}

bool GetTable(Table *T, BaseType *E, T_Key Key) {
    TableError = TableOk;
    BeginPtr(T);
    while (!EndList(T) && T->ptr->next->data.Key < Key)
        MovePtr(T);

    if (T->ptr->next->data.Key == Key) {
        GetList(T, E);

        return true;
    }

    return false;
}

bool ReadTable(Table *T, BaseType *E, T_Key Key) {
    TableError = TableOk;
    BeginPtr(T);
    while (!EndList(T) && T->ptr->next->data.Key < Key)
        MovePtr(T);

    if (T->ptr->next->data.Key == Key) {
        ReadList(T, E);

        return true;
    }

    return false;
}

bool WriteTable(Table *T, BaseType E) {
    TableError = TableOk;
    BeginPtr(T);
    while (!EndList(T) && T->ptr->next->data.Key < E.Key)
        MovePtr(T);

    if (T->ptr->next->data.Key == E.Key) {
        MovePtr(T);
        T->ptr->data = E;

        return true;
    }

    return false;
}

void DoneTable(Table *T) {
    TableError = TableOk;
    DoneList(T);
}
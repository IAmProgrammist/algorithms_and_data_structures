#ifndef TABLE
#define TABLE

#ifndef CUSTOM_TYPES_TABLE
typedef int T_Key;
typedef int T_Value;
#endif

typedef struct {
    T_Key Key;
    T_Value Value;
} TableElement;

#define CUSTOM_BASE_TYPE
typedef TableElement BaseType;

#include <lab5/singlyconnectedlist.h>

#include <stdbool.h>

#define TableOk 0
#define TableNotMem 1
#define TableUnder 2

extern int TableError;

typedef List Table;

Table InitTable();

bool EmptyTable(Table *T);

bool PutTable(Table *T, BaseType E);

bool GetTable(Table *T, BaseType *E, T_Key Key);

bool ReadTable(Table *T, BaseType *E, T_Key Key);

bool WriteTable(Table *T, BaseType E);

void DoneTable(Table *T);

#endif
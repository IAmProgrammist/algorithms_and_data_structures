#include "../../libs/alg/lab8/table.c"

#include <assert.h>

void testInitTable() {
    Table t = InitTable();
    assert(TableError == TableOk);
}

void testEmptyTable() {
    Table t = InitTable();
    
    assert(EmptyTable(&t) && TableError == TableOk);

    PutTable(&t, (BaseType){42, 42});
    assert(!EmptyTable(&t) && TableError == TableOk);
}

void testPutTable() {
    Table t = InitTable();
    assert(PutTable(&t, (BaseType){42, 42}) && TableError == TableOk && !EmptyTable(&t) && TableError == TableOk);

    BaseType an;
    assert(GetTable(&t, &an, 42) && TableError == TableOk && an.Key == 42 && an.Value == 42 );
    PutTable(&t, (BaseType){42, 42});
    assert(!PutTable(&t, (BaseType){42, 42}));

    PutTable(&t, (BaseType){39, 39});
    PutTable(&t, (BaseType){41, 41});
    PutTable(&t, (BaseType){40, 40});
    PutTable(&t, (BaseType){38, 38});
    BeginPtr(&t);
    assert(t.ptr->next->data.Key == 38 && t.ptr->next->data.Value == 38);
    MovePtr(&t);
    assert(t.ptr->next->data.Key == 39 && t.ptr->next->data.Value == 39);
    MovePtr(&t);
    assert(t.ptr->next->data.Key == 40 && t.ptr->next->data.Value == 40);
    MovePtr(&t);
    assert(t.ptr->next->data.Key == 41 && t.ptr->next->data.Value == 41);
    MovePtr(&t);
    assert(t.ptr->next->data.Key == 42 && t.ptr->next->data.Value == 42);
}

void testGetTable() {
    Table t = InitTable();
    PutTable(&t, (BaseType){42, 42});
    PutTable(&t, (BaseType){39, 39});
    PutTable(&t, (BaseType){41, 41});
    PutTable(&t, (BaseType){40, 40});
    PutTable(&t, (BaseType){38, 38});

    BaseType an;
    assert(GetTable(&t, &an, 41) && an.Key == 41 && an.Value == 41 && TableError == TableOk);
    assert(!GetTable(&t, &an, 41));
    assert(!GetTable(&t, &an, 90));
}

void testReadTable() {
    Table t = InitTable();
    PutTable(&t, (BaseType){42, 42});
    PutTable(&t, (BaseType){39, 39});
    PutTable(&t, (BaseType){41, 41});
    PutTable(&t, (BaseType){40, 40});
    PutTable(&t, (BaseType){38, 38});

    BaseType an;
    assert(ReadTable(&t, &an, 40) && TableError == TableOk && an.Key == 40 && an.Value == 40);
    assert(ReadTable(&t, &an, 40) && TableError == TableOk && an.Key == 40 && an.Value == 40);
    assert(!ReadTable(&t, &an, 90) && TableError == TableOk);
}

void testWriteTable() {
    Table t = InitTable();
    PutTable(&t, (BaseType){42, 42});
    PutTable(&t, (BaseType){39, 39});
    PutTable(&t, (BaseType){41, 41});
    PutTable(&t, (BaseType){40, 40});
    PutTable(&t, (BaseType){38, 38});

    BaseType an;
    assert(WriteTable(&t, (BaseType){40, 55}) && TableError == TableOk);
    assert(ReadTable(&t, &an, 40) && TableError == TableOk && an.Key == 40 && an.Value == 55);
    assert(!WriteTable(&t, (BaseType){123, 55}) && TableError == TableOk);
}

void test() {
    testInitTable();
    testEmptyTable();
    testPutTable();
    testGetTable();
    testReadTable();
    testWriteTable();
}

int main() {
    test();
}
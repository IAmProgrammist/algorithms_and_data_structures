#include <lab8/table.h>

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

void test() {
    testInitTable();
    testEmptyTable();
}

int main() {
    test();
}
#include <algc.h>

#include <stdio.h>
#include <assert.h>
#include <string.h>

void testPutList() {
    List t1;
    InitList(&t1);
    PutList(&t1, 1);
    assert(ListError == ListOk && 
    t1.N == 1 && 
    t1.Start->data == 1 &&
    t1.Start == t1.ptr);

    PutList(&t1, 2);
    assert(ListError == ListOk && 
    t1.N == 2 && 
    t1.Start->data == 1 && 
    t1.Start->next->data == 2);

    MovePtr(&t1);
    PutList(&t1, 3);
    assert(ListError == ListOk && 
    t1.N == 3 && 
    t1.Start->data == 1 && 
    t1.Start->next->data == 2 &&
    t1.Start->next->next->data == 3);
}

void testGetList() {
    List t1;
    InitList(&t1);
    PutList(&t1, 1);
    PutList(&t1, 2);
    MovePtr(&t1);
    PutList(&t1, 3);

    
}

void test() {
    testPutList();
}

int main() {
    test();
    
    return 0;
}
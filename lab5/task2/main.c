#include <algc.h>

#include <stdio.h>
#include <assert.h>
#include <string.h>

void testPutList() {
    List t1;
    InitList(&t1);
    PutList(&t1, 1);
    int e;
    ReadList(&t1, &e);
    assert(ListError == ListOk && 
    t1.N == 1 && 
    e == 1);

    PutList(&t1, 2);
    ReadList(&t1, &e);
    assert(ListError == ListOk && 
    t1.N == 2 && 
    e == 2);

    MovePtr(&t1);
    MovePtr(&t1);
    PutList(&t1, 3);
    ReadList(&t1, &e);
    assert(ListError == ListOk && 
    t1.N == 3 && 
    e == 3);

    DoneList(&t1);
}

void testGetList() {
    List t1;
    InitList(&t1);
    PutList(&t1, 1);
    MovePtr(&t1);
    PutList(&t1, 2);
    MovePtr(&t1);
    PutList(&t1, 3);
    int e;

    EndPtr(&t1);
    GetList(&t1, &e);
    assert(ListError == ListEnd);

    BeginPtr(&t1);
    MovePtr(&t1);
    MovePtr(&t1);
    GetList(&t1, &e);
    assert(ListError == ListOk && e == 3);

    BeginPtr(&t1);
    MovePtr(&t1);
    GetList(&t1, &e);
    assert(ListError == ListOk && e == 2);

    BeginPtr(&t1);
    GetList(&t1, &e);
    assert(ListError == ListOk && e == 1);

    GetList(&t1, &e);
    assert(ListError == ListUnder || ListError == ListEnd);

    DoneList(&t1);
}

void testReadList() {
    List t1;
    InitList(&t1);
    PutList(&t1, 1);
    MovePtr(&t1);
    PutList(&t1, 2);
    MovePtr(&t1);
    PutList(&t1, 3);
    int e;

    EndPtr(&t1);
    ReadList(&t1, &e);
    assert(ListError == ListEnd);

    BeginPtr(&t1);
    MovePtr(&t1);
    MovePtr(&t1);
    ReadList(&t1, &e);
    assert(ListError == ListOk && e == 3);

    BeginPtr(&t1);
    MovePtr(&t1);
    ReadList(&t1, &e);
    assert(ListError == ListOk && e == 2);

    BeginPtr(&t1);
    ReadList(&t1, &e);
    assert(ListError == ListOk && e == 1);
    
    DoneList(&t1);
}

void testEndList() {
    List t1;
    InitList(&t1);
    EndList(&t1);
    assert(ListError == ListOk);

    PutList(&t1, 1);
    PutList(&t1, 2);
    PutList(&t1, 3);
    BeginPtr(&t1);
    assert(ListError == ListOk && !EndList(&t1));
    MovePtr(&t1);
    assert(ListError == ListOk && !EndList(&t1));
    MovePtr(&t1);
    assert(ListError == ListOk && !EndList(&t1));
    MovePtr(&t1);
    assert(ListError == ListOk && EndList(&t1));
    
    DoneList(&t1);
}

void testCount() {
    List t1;
    InitList(&t1);
    assert(Count(&t1) == 0 && ListError == ListOk);
    PutList(&t1, 1);
    assert(Count(&t1) == 1 && ListError == ListOk);
    PutList(&t1, 2);
    assert(Count(&t1) == 2 && ListError == ListOk);
    PutList(&t1, 3);
    assert(Count(&t1) == 3 && ListError == ListOk);
    
    DoneList(&t1);
}

void testBeginPtr() {
    List t1;
    InitList(&t1);
    PutList(&t1, 1);
    PutList(&t1, 2);
    MovePtr(&t1);
    PutList(&t1, 3);
    BeginPtr(&t1);

    assert(t1.ptr == t1.Start && ListError == ListOk);
    
    DoneList(&t1);
}

void testEndPtr() {
    List t1;
    InitList(&t1);

    PutList(&t1, 1);
    MovePtr(&t1);
    PutList(&t1, 2);
    MovePtr(&t1);
    PutList(&t1, 3);
    EndPtr(&t1);

    assert(t1.ptr->data == 3 && ListError == ListOk);
    
    DoneList(&t1);
}

void testMovePtr() {
    List t1;
    InitList(&t1);
    MovePtr(&t1);
    assert(ListError == ListEnd);

    PutList(&t1, 1);
    MovePtr(&t1);
    assert(ListError == ListOk && t1.ptr->data == 1);
    PutList(&t1, 2);
    MovePtr(&t1);
    assert(ListError == ListOk && t1.ptr->data == 2);

    PutList(&t1, 3);
    MovePtr(&t1);
    assert(ListError == ListOk && t1.ptr->data == 3);

    DoneList(&t1);
}

void testMoveTo() {
    List t1;
    InitList(&t1);
    MoveTo(&t1, 177);
    assert(ListError == ListEnd);

    PutList(&t1, 1);
    MovePtr(&t1);
    PutList(&t1, 2);
    MovePtr(&t1);
    PutList(&t1, 3);

    MoveTo(&t1, 0);
    assert(ListError == ListOk && t1.ptr->data == 1);
    MoveTo(&t1, 2);
    assert(ListError == ListOk && t1.ptr->data == 3);
    MoveTo(&t1, 1);
    assert(ListError == ListOk && t1.ptr->data == 2);

    DoneList(&t1);
}

void test() {
    testPutList();
    testGetList();
    testReadList();
    testEndList();
    testCount();
    testBeginPtr();
    testEndPtr();
    testMovePtr();
    testMoveTo();
}

int main() {
    test();
    
    return 0;
}
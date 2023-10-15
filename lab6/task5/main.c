#include <algc.h>

#include <stdio.h>
#include <assert.h>
#include <string.h>

void testPutStack() {
    Stack s1;
    InitStack(&s1);

    PutStack(&s1, 1);
    assert(StackError == StackOk);
    PutStack(&s1, 2);
    assert(StackError == StackOk);
    PutStack(&s1, 3);
    assert(StackError == StackOk);

    int e;
    GetStack(&s1, &e);
    assert(e == 3);
    GetStack(&s1, &e);
    assert(e == 2);
    GetStack(&s1, &e);
    assert(e == 1);

    DoneStack(&s1);
}

void testGetStack() {
    Stack s1;
    InitStack(&s1);
    int e;
    GetStack(&s1, &e);
    assert(StackError == StackUnder);


    PutStack(&s1, 1);
    PutStack(&s1, 2);
    PutStack(&s1, 3);

    GetStack(&s1, &e);
    assert(e == 3 && StackError == StackOk);
    GetStack(&s1, &e);
    assert(e == 2 && StackError == StackOk);
    GetStack(&s1, &e);
    assert(e == 1 && StackError == StackOk);
    GetStack(&s1, &e);
    assert(StackError == StackUnder);

    DoneStack(&s1);
}

void testStack() {
    testPutStack();
    testGetStack();
}

void testQueue() {

}

void test() {
    testStack();
    testQueue();
}

int main() {
    test();

    return 0;
}
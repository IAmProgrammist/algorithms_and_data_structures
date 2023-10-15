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

void testEmptyStack() {
    Stack s1;
    InitStack(&s1);

    assert(EmptyStack(s1) && StackError == StackOk);

    PutStack(&s1, 1);
    assert(!EmptyStack(s1) && StackError == StackOk);

    PutStack(&s1, 2);
    assert(!EmptyStack(s1) && StackError == StackOk);

    PutStack(&s1, 3);
    assert(!EmptyStack(s1) && StackError == StackOk);

    DoneStack(&s1);
}

void testReadStack() {
    Stack s1;
    InitStack(&s1);
    int e;
    ReadStack(&s1, &e);
    assert(StackError == StackUnder);


    PutStack(&s1, 1);
    ReadStack(&s1, &e);
    assert(e == 1 && StackError == StackOk);

    PutStack(&s1, 2);
    ReadStack(&s1, &e);
    assert(e == 2 && StackError == StackOk);
    
    PutStack(&s1, 3);
    ReadStack(&s1, &e);
    assert(e == 3 && StackError == StackOk);

    DoneStack(&s1);
}

void testStack() {
    testPutStack();
    testGetStack();
    testEmptyStack();
    testReadStack();
}

void testPutQueue() {
    Queue q1;
    InitQueue(&q1);

    PutQueue(&q1, 1);
    assert(QueueError == QueueOk);
    PutQueue(&q1, 2);
    assert(QueueError == QueueOk);
    PutQueue(&q1, 3);
    assert(QueueError == QueueOk);
    int e;
    GetQueue(&q1, &e);
    GetQueue(&q1, &e);
    GetQueue(&q1, &e);

    for (int i = 0; i < QueueSize; i++) {
        PutQueue(&q1, 1);
        assert(QueueError == QueueOk);
    }

    PutQueue(&q1, 1);
    assert(QueueError == QueueOver);
}

void testGetQueue() {
    Queue q1;
    InitQueue(&q1);
    int e;
    GetQueue(&q1, &e);
    assert(QueueError == QueueUnder);

    PutQueue(&q1, 1);
    PutQueue(&q1, 2);
    PutQueue(&q1, 3);
    GetQueue(&q1, &e);
    assert(QueueError == QueueOk && e == 1);
    GetQueue(&q1, &e);
    assert(QueueError == QueueOk && e == 2);
    GetQueue(&q1, &e);
    assert(QueueError == QueueOk && e == 3);
}

void testEmptyQueue() {
    Queue q1;
    InitQueue(&q1);
    assert(EmptyQueue(&q1) && QueueError == QueueOk);

    for (int i = 0; i < 1000; i++) {
        PutQueue(&q1, 1);
        assert(!EmptyQueue(&q1) && QueueError == QueueOk);
    }
}

void testReadQueue() {
    Queue q1;
    InitQueue(&q1);
    int e;
    ReadQueue(&q1, &e);
    assert(QueueError == QueueUnder);

    PutQueue(&q1, 1);
    ReadQueue(&q1, &e);
    assert(QueueError == QueueOk && e == 1);
    PutQueue(&q1, 2);
    ReadQueue(&q1, &e);
    assert(QueueError == QueueOk && e == 1);
}

void testQueue() {
    testPutQueue();
    testGetQueue();
    testEmptyQueue();
    testReadQueue();
}

void test() {
    testStack();
    testQueue();
}

int main() {
    test();

    return 0;
}
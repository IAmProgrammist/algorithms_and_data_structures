#include <lab6/queue.h>

void InitQueue(Queue* f) {
    f->Uk1 = 0;
    f->Uk2 = 0;
    f->N = 0;

    QueueError = QueueOk;
}

void PutQueue(Queue *f, BaseType E) {
    if (f->N >= QueueSize) {
        QueueError = QueueOver;
        return;
    }

    QueueError = QueueOk;
    f->Buf[f->Uk2 = (f->Uk2 + 1) % QueueSize] = E;
}

void GetQueue(Queue *f, BaseType *E) {
    if (f->N <= 0) {
        QueueError = QueueUnder;
        return;
    }

    QueueError = QueueOk;
    *E = f->Buf[f->Uk1];
    f->Uk1 = (f->Uk1 + 1) % QueueSize;
}

void ReadQueue(Queue *f, BaseType *E) {
    if (f->N <= 0) {
        QueueError = QueueUnder;
        return;
    }

    QueueError = QueueOk;
    *E = f->Buf[f->Uk1];
}

int EmptyQueue(Queue *f) {
    QueueError = QueueOk;
    
    return f->N == 0;
}
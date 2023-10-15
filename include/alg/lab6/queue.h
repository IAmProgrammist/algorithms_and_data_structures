#ifndef QUEUE
#define QUEUE

#define QueueSize 1000

#define QueueOk 0
#define QueueUnder 1
#define QueueOver 2

extern int QueueError;

typedef int BaseType; 

typedef struct {
    BaseType Buf[QueueSize];
    unsigned Uk1; // Голова
    unsigned Uk2; // Хвост
    unsigned N;
} Queue;

void InitQueue(Queue* f);
void PutQueue(Queue *f, BaseType E); 
void GetQueue(Queue *f, BaseType *E);
void ReadQueue(Queue *f, BaseType *E); 
int EmptyQueue(Queue *f);

#endif
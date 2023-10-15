#ifndef QUEUE
#define QUEUE

#define QUEUE_SIZE 1000

extern const int QueueOk;
extern const int QueueUnder;
extern const int QueueOver;
extern int QueueError;

typedef int BaseType; 

typedef struct {
    BaseType Buf[QUEUE_SIZE];
    unsigned Uk1; 
    unsigned Uk2;
    unsigned N;
} Queue;

void InitQueue(Queue* f);
void PutQueue(Queue *f, BaseType E); 
void GetQueue(Queue *f, BaseType *E);
void ReadQueue(Queue *f, BaseType *E); 
int EmptyQueue(Queue *f);

#endif
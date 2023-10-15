typedef struct {
    char Name[10]; // имя запроса
    unsigned Time; // время обслуживания
    char T; // тип задачи 1 — Т1, 2 — Т2
} TInquiry;

#define CUSTOM_BASE_TYPE
typedef TInquiry BaseType;

#define TInquiryType1 1
#define TInquiryType2 2

#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include <algc.h>
#include "../../libs/alg/lab5/task2.c"
#include "../../libs/alg/lab6/queue.c"
#include "../../libs/alg/lab6/stack.c"

void gen(Queue *F1, Queue *F2) {
    char tmp;
    printf("Input first task type amount (leave -1 for random from 1 to 5): ");
    int f1Amount;
    scanf("%d", &f1Amount);
    if (f1Amount < 0) {
        f1Amount = 1 + rand() % 5;
        printf("%d tasks\n", f1Amount);
    }
    gets(&tmp);

    for (int i = 0; i < f1Amount; i++) {
        printf("Input task name (leave blank for random): ");
        TInquiry f1Task;
        f1Task.T = TInquiryType1;
        gets(f1Task.Name);
        if (!f1Task.Name[0]) {
            int j = 0;
            while (j < sizeof(f1Task.Name) - 1 && rand() % 10 < 7)
                f1Task.Name[j++] = 'a' + rand() % ('z' - 'a');

            f1Task.Name[j] = '\0';
            
            printf("Task name: %s\n", f1Task.Name);
        }

        printf("Input task time (leave 0 for random from 1 to 7): ");
        scanf("%d", &f1Task.Time);
        gets(&tmp);
        if (f1Task.Time == 0) {
            f1Task.Time = 1 + rand() % 7;
            
            printf("Task time: %d\n", f1Task.Time);
        }

        PutQueue(F1, f1Task);
    }
    
    printf("Input second task type amount (leave -1 for random from 1 to 5): ");
    int f2Amount;
    scanf("%d", &f2Amount);
    if (f2Amount < 0) {
        f2Amount = 1 + rand() % 5;
        printf("%d tasks\n", f2Amount);
    }
    gets(&tmp);

    for (int i = 0; i < f2Amount; i++) {
        printf("Input task name (leave blank for random): ");
        TInquiry f2Task;
        f2Task.T = TInquiryType2;
        gets(f2Task.Name);
        if (!f2Task.Name[0]) {
            int j = 0;
            while (j < sizeof(f2Task.Name) - 1 && rand() % 10 < 7)
                f2Task.Name[j++] = 'a' + rand() % ('z' - 'a');

            f2Task.Name[j] = '\0';
            
            printf("Task name: %s\n", f2Task.Name);
        }

        printf("Input task time (leave 0 for random from 1 to 7): ");
        scanf("%d", &f2Task.Time);
        gets(&tmp);
        if (f2Task.Time == 0) {
            f2Task.Time = 1 + rand() % 7;
            
            printf("Task time: %d\n", f2Task.Time);
        }

        PutQueue(F2, f2Task);
    }
}

void outputTInquiry(TInquiry t) {
    printf("=========================\n\n");
    printf("Name: %s\n", t.Name);
    printf("Time: %u\n", t.Time);
    printf("Type: %s\n", t.T == TInquiryType1 ? "1" : t.T == TInquiryType2 ? "2" : "unknown");
    printf("\n");
}

int main() {
    srand(time(0));

    Stack S;
    InitStack(&S);

    Queue F1, F2;
    InitQueue(&F1);
    InitQueue(&F2);
    gen(&F1, &F2);

    TInquiry *P1 = NULL, *P2 = NULL;

    while (1) {
        if (P1 != NULL) {
            P1->Time--;

            if (!P1->Time) {
                free(P1);
                P1 = NULL;
            }
        }
        
        if (P2 != NULL) {
            P2->Time--;

            if (!P2->Time) {
                free(P2);
                P2 = NULL;
            }
        }

        if (!EmptyQueue(&F1)) {
            if (P1 == NULL) {
                P1 = malloc(sizeof(TInquiry));
                GetQueue(&F1, P1);
            } else if (P1->T == 2 && P2 == NULL) {
                P2 = malloc(sizeof(TInquiry));
                P2 = P1;
                GetQueue(&F1, P1);
            } else {
                TInquiry t;
                GetQueue(&F1, &t);
                PutStack(&S, t);
            }
        } else if (P1 == NULL && P2 != NULL && !EmptyStack(S)){
            P1 = malloc(sizeof(TInquiry));
            GetStack(&S, P1);
        }
        if (!EmptyQueue(&F2)) {
            if (P2 == NULL) {
                P2 = malloc(sizeof(TInquiry));
                GetQueue(&F2, P2);
            } else if (P1 == NULL && EmptyQueue(&F1)) {
                P1 = malloc(sizeof(TInquiry));
                GetQueue(&F2, P1);
            }
        } else if (P2 == NULL && !EmptyStack(S)) {
            P2 = malloc(sizeof(TInquiry));
            GetStack(&S, P2);
        }

        printf("Tasks in first queue:\n");
        for (int i = F1.Uk1; i != F1.Uk2; i = (i + 1) % QueueSize) {
            TInquiry t = F1.Buf[i];
            outputTInquiry(t);
        }

        printf("Tasks in second queue:\n");
        for (int i = F2.Uk1; i != F2.Uk2; i = (i + 1) % QueueSize) {
            TInquiry t = F1.Buf[i];
            outputTInquiry(t);
        }
        
        if (P1 == NULL) {
            printf("P1 is not busy.\n");
        } else {
            printf("P1 current task:\n");
            outputTInquiry(*P1);
        }

        if (P2 == NULL) {
            printf("P2 is not busy.\n");
        } else {
            printf("P2 current task:\n");
            outputTInquiry(*P2);
        }

        
        printf("Tasks in stack:\n");
        ptrel stackTask = S.Start->next;
        while (stackTask != NULL) {
            outputTInquiry(stackTask->data);

            stackTask = stackTask->next;
        }
        

        while (1) {
            printf("Type g to add more tasks, n for next iteration, e to exit program\n");
            int input = getchar();

            if (input == 'g') {
                gen(&F1, &F2);
            } else if (input == 'n') {
                break;
            } else if (input == 'e') {
                return 0;
            }
        }
    }

    return 0;
}
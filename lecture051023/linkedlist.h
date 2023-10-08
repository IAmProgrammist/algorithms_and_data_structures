#ifndef LIST_H
#define LIST_H

const int ListOk = 0;
const int ListEmpty = 1;
const int ListNotMem = 2;
const int ListEnd = 3;
extern int ListError;

typedef int BaseType;

typedef struct
{
    BaseType data;
    element* link;
} element;

typedef struct {
    element* start;
    element* ptr;
} LinkedList;

void ListInit(LinkedList *list) {
    *list = {nullptr, nullptr};
}

void ListPut(LinkedList *list, BaseType E) {
    // Определяем вспомогательную переменную putr
    // Сгенерировать элемент списка в динамической памяти, используя в putr
    // Если операция прошла нормально, заполнить поле дата
    // Иначе присвоить переменной ошибки ListNotMem
    // Если список пустой, включить элемент (list->start = pntr, 
    // list->ptr = pntr - не совсем уверен, зачем это нужно, ну ладно, pntr -> link = null)
    // Если список не пустой, то включить его по выше указанному в лекции алгоритму в нотации Си
}

void ListGet(LinkedList *list, BaseType *E) {
    // Если рабочий указатель в конце списка, ListError = ListEnd и выход
    // Если список пустой, ListError = ListEmpty и выход.
    // Если в списке один элемент, то Е = L->start.data, free(l->ptr)
    // Если общий случай, то алгоритм, который рассмотрим в обобщённом примере, в нотации Си
}

void ListMove(LinkedList *list);//list->ptr = list->ptr.link. Если list->ptr.link == nullptr, падаем с ошибкой.
void ListDone(LinkedList *list);
bool ListEmpty(LinkedList *list);
// Доп. операции
void ListPtrBegin(LinkedList *L);
void ListPtrEnd(LinkedList *L);
#endif
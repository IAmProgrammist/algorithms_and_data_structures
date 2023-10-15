#include <algc.h>

#include <stdio.h>

int main() {
    List l;
    InitList(&l);
    if (ListError != ListOk) {
        printf("An error occured trying to init a list, code: %d", ListError);
        return ListError;
    }

    int amount;
    printf("Enter elements amount: ");
    scanf("%d", &amount);
    printf("Enter elements: ");
    for (int i = 0; i < amount; i++) {
        int element;
        scanf("%d", &element);

        PutList(&l, element);
        if (ListError != ListOk) {
            printf("An error occured trying to insert an element in list, code: %d", ListError);
            return ListError;
        }
        
        MovePtr(&l);
        if (ListError != ListOk) {
            printf("An error occured trying to insert an element in list, code: %d", ListError);
            return ListError;
        }
    }
    
    int step;
    printf("Enter step: ");
    scanf("%d", &step);

    int previousElement;
    BeginPtr(&l);
    GetList(&l, &previousElement);
    if (ListError != ListOk) {
        printf("An error occured trying to get an element in list, code: %d", ListError);
        return ListError;
    }

    for (int i = 1; i < amount; i++) {
        int currentElement;
        GetList(&l, &currentElement);
        if (ListError != ListOk) {
            printf("An error occured trying to get an element in list, code: %d", ListError);
            return ListError;
        }

        if (currentElement - previousElement != step) {
            printf("A condition is breached with elements %d and %d", previousElement, currentElement);
            return 0;
        }

        previousElement = currentElement;
    }

    
    printf("A condition is fulfilled");

    return 0;
}
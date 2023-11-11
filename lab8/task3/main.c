#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CUSTOM_TYPES_TABLE

// C не позволяет сравнивать через == статические массивы
// Поэтому ключ будет 32-битным числом, что позволит нам хранить
// 4 символа, что вполне достаточно для элементов периодической таблицы 
typedef int32_t T_Key;
typedef float T_Value;

#include "../../libs/alg/lab8/table.c"

Table loadPeriodicTable(char* path) {
    Table result = InitTable();

    FILE *fptr = fopen(path, "r");
    if (fptr == NULL) {
        return result;
    }

    while (!feof(fptr)) {
        char name[4] = {0};
        float val;
        fscanf(fptr, "%s %f", name, &val);

        BaseType element;
        memcpy(&element.Key, name, sizeof(uint32_t));
        element.Value = val;

        PutTable(&result, element);
    }

    return result;
}

int main() {
    Table periodicTable = loadPeriodicTable("../lab8/task3/periodic.txt");
    FILE *fptr = fopen("../lab8/task3/formula.txt", "r");

    int amount = 0;
    char name[4] = {0};
    int nameCurrentIndex = 0;
    float weight = 0;
    while (!feof(fptr)) {
        int input = fgetc(fptr);

        if (isupper(input)) {
            if (nameCurrentIndex == 0) {
                name[nameCurrentIndex++] = input;
                continue;
            }

            if (amount == 0) {
                amount = 1;
            }
            
            uint32_t elementName;
            memcpy(&elementName, name, 4);

            BaseType element;
            if (!ReadTable(&periodicTable, &element, elementName)) {
                fprintf(stderr, "Unable to parse");
                return 1;
            }

            weight += amount * element.Value;
            elementName = 0;
            memcpy(name, &elementName, 4);
            amount = 0;
            name[0] = input;
            nameCurrentIndex = 1;
        } else if (islower(input)) {
            if (amount != 0 || nameCurrentIndex == 3) {
                fprintf(stderr, "Unable to parse");
                return 1;
            }

            name[nameCurrentIndex++] = input;
        } else if (isdigit(input)) {
            if (name[0] == '\0') {
                fprintf(stderr, "Unable to parse");
                return 1;
            }

            amount += amount * 10 + input - '0';
        }
    }    

    if (amount == 0) 
        amount = 1;

    uint32_t elementName;
    memcpy(&elementName, name, 4);

    BaseType element;
    if (!ReadTable(&periodicTable, &element, elementName)) {
        fprintf(stderr, "Unable to parse");
        return 1;
    }

    weight += amount * element.Value;

    printf("%f", weight);

    return 0;
}
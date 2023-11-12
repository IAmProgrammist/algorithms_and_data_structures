#include <stdint.h>

#define CUSTOM_TYPES_TABLE
typedef uint64_t T_Key;
typedef float T_Value;

#include "../../libs/alg/lab8/table.c"
#include "../../libs/alg/lab6/stack.c"

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define TOKEN_BUFFER_SIZE sizeof(T_Key)

bool isStringFloat(const char *s) {
    int len;
    float ignore;
    int ret = sscanf(s, "%f %n", &ignore, &len);
    return ret == 1 && !s[len];
}

int main() {
    Stack tokens;
    InitStack(&tokens);
    Table tokenValues = InitTable();
    char formula[1024];
    int fIndex = 0;
    gets(formula);

    int input;
    char buffer[TOKEN_BUFFER_SIZE] = {0};
    int bufferCurrentIndex;
    while (1) {
        input = formula[fIndex++];

        if (input == ' ' || input == '\0') {
            if (isStringFloat(buffer)) {
                int val = atof(buffer);
                PutStack(&tokens, (BaseType) {0, val});
            } else if (!strcmp(buffer, "+") || !strcmp(buffer, "-") || !strcmp(buffer, "*") || !strcmp(buffer, "/")) {
                BaseType leftOperand, rightOperand;
                GetStack(&tokens, &leftOperand);
                if (StackError != StackOk) {
                    fprintf(stderr, "Unable to parse");
                    return 1;
                }

                GetStack(&tokens, &rightOperand);
                if (StackError != StackOk) {
                    fprintf(stderr, "Unable to parse");
                    return 1;
                }

                if (!strcmp(buffer, "+"))
                    PutStack(&tokens, (BaseType){0, leftOperand.Value + rightOperand.Value});
                else if (!strcmp(buffer, "-"))
                    PutStack(&tokens, (BaseType){0, rightOperand.Value - leftOperand.Value}); 
                else if (!strcmp(buffer, "*"))
                    PutStack(&tokens, (BaseType){0, leftOperand.Value * rightOperand.Value}); 
                else if (!strcmp(buffer, "/"))
                    PutStack(&tokens, (BaseType){0, rightOperand.Value / leftOperand.Value}); 
            } else if (!strcmp(buffer, "sin") || !strcmp(buffer, "cos") || !strcmp(buffer, "arctan") || 
                       !strcmp(buffer, "abs") || !strcmp(buffer, "exp") || !strcmp(buffer, "ln") ||
                       !strcmp(buffer, "sqr") || !strcmp(buffer, "sqrt")) {
                BaseType operand;
                GetStack(&tokens, &operand);
                if (StackError != StackOk) {
                    fprintf(stderr, "Unable to parse");
                    return 1;
                }

                if (!strcmp(buffer, "sin"))
                    PutStack(&tokens, (BaseType){0, sinf(operand.Value)});
                if (!strcmp(buffer, "cos"))
                    PutStack(&tokens, (BaseType){0, cosf(operand.Value)});
                if (!strcmp(buffer, "arctan"))
                    PutStack(&tokens, (BaseType){0, atanf(operand.Value)});
                if (!strcmp(buffer, "abs"))
                    PutStack(&tokens, (BaseType){0, fabs(operand.Value)});
                if (!strcmp(buffer, "exp"))
                    PutStack(&tokens, (BaseType){0, expf(operand.Value)});
                if (!strcmp(buffer, "ln"))
                    PutStack(&tokens, (BaseType){0, log2f(operand.Value) / log2f(expf(1))});
                if (!strcmp(buffer, "sqr"))
                    PutStack(&tokens, (BaseType){0, operand.Value * operand.Value});
                if (!strcmp(buffer, "sqrt"))
                    PutStack(&tokens, (BaseType){0, sqrtf(operand.Value)});
            } else {
                T_Key key;
                memcpy(&key, buffer, sizeof(T_Key));

                BaseType token = (BaseType) {key, 0};
                if (!GetTable(&tokenValues, &token, key)) {
                    printf("Input value of variable %s: ", buffer);
                    scanf("%f", &token.Value);

                    PutTable(&tokenValues, token);
                }

                PutStack(&tokens, token);
            }

            memset(buffer, 0, TOKEN_BUFFER_SIZE);
            bufferCurrentIndex = 0;

            if (input == '\0') break;
        } else {
            if (bufferCurrentIndex >= TOKEN_BUFFER_SIZE - 1) {
                fprintf(stderr, "Unable to parse. You can use only 7 symbols long varialbes.");
                return 1;
            }

            buffer[bufferCurrentIndex++] = input;
        }
    }

    BaseType result;
    GetStack(&tokens, &result);
    if (StackError != StackOk || !EmptyStack(tokens)) {
        fprintf(stderr, "Unable to parse");
        return 1;
    }
    
    printf("Result: %f", result.Value);

    return 0;
}
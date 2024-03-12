#include <math.h>
#include "number.h"

static FieldInfo* INT_FIELD_INFO = NULL; // Скрытая глобальная переменная

FieldInfo* GetIntFieldInfo() {
    if (INT_FIELD_INFO == NULL) {
        INT_FIELD_INFO = (FieldInfo*)malloc(sizeof(FieldInfo));
        INT_FIELD_INFO->typeName = "int";
        INT_FIELD_INFO->elementSize = sizeof(int);
        INT_FIELD_INFO->printElement = numberPrint;
    }
    return INT_FIELD_INFO;
}


void numberPrint(const void* el) {
    printf("%d ", *(const int*)el);
}

void numberMapAbs(const void* el, void* res) {
    *(int*)res = abs(*(const int*)el);
} 

void numberMapLen(const void* el, void* res) {
    int i = 0;
    int copy = abs(*(const int*)el);
    while (copy > 0) {
        copy = copy / 10;
        i++;
    }
    *(int*)res = i;
}


int numberCheckPos(const void* el) {
    return *(int*)el > 0;
}

int numberCheckEven(const void* el) {
    return *(int*)el % 2 == 0;
}

void numberSum(const void* el1, const void* el2, void* res) {
    *(int*)res = (*(int*)el1 + *(int*)el2);
}

void numberMult(const void* el1, const void* el2, void* res) {
    *(int*)res = (*(int*)el1 * *(int*)el2);
}

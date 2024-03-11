#ifndef NUMBER_H
#define NUMBER_H
#include <stdio.h>
#include <stdlib.h>
#include "fieldInfo.h"

FieldInfo* GetIntFieldInfo();
void numberPrint(const void* el);
void numberMapAbs(const void* el, void* res);
void numberMapLen(const void* el, void* res);

int numberCheckPos(const void* el);
int numberCheckEven(const void* el);

void numberSum(const void* el1, const void* el2, void* res);
void numberMult(const void* el1, const void* el2, void* res);
#endif /*NUMBER_H*/

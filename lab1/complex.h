#ifndef CUSTOM_TYPE_H
#define CUSTOM_TYPE_H
#include <stdio.h>
#include "fieldInfo.h"

/*
    ’эдер, представл€ющий интерфейс дл€ работы с комплексными числами
*/

typedef struct {
    int real;
    int imag;
} Complex;

//начинаем названи€ функций с имени хэдера, чтобы было пон€тно, какую библиотеку используем
FieldInfo* GetComplexFieldInfo();
void complexPrint(const void* elem);
void complexMapOpposite(const void* elem, void* res);
void complexMapReverse(const void* elem, void* res);

int complexCheckPosReal(const void* elem);
int complexCheckImagNotNull(const void* elem);

void complexSum(const void* elem1, const void* elem2, void* res);
void complexMult(const void* elem1, const void* elem2, void* res);
#endif

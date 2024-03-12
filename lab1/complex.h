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

FieldInfo* GetComplexFieldInfo();
void complexPrint(const void* elem); //вывод комплексного числа

void complexMapOpposite(const void* elem, void* res); // Xr+Yi -> Xr-Yi (получение обратного комплексного числа)
void complexMapReverse(const void* elem, void* res); // Xr + Yi -> Yr + Xi

int complexCheckPosReal(const void* elem); //проверка на положительную действительную часть
int complexCheckImagNotNull(const void* elem); // проверка на ненулевую мнимую часть

void complexSum(const void* elem1, const void* elem2, void* res); // сложение компексных чисел
void complexMult(const void* elem1, const void* elem2, void* res); //произведение комплексных чисел
#endif

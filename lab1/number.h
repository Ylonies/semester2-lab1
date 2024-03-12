#ifndef NUMBER_H
#define NUMBER_H
#include <stdio.h>
#include <stdlib.h>
#include "fieldInfo.h"

/*
    Хэдер, представляющий интерфейс для работы с целыми числами
*/

FieldInfo* GetIntFieldInfo();
void numberPrint(const void* el); //вывод целого числа

void numberMapAbs(const void* el, void* res); //получение модуля целого числа
void numberMapLen(const void* el, void* res); //получение количество разрядов целого числа

int numberCheckPos(const void* el); // проверка на положительное целое число 
int numberCheckEven(const void* el); //проверка на четное целое число

void numberSum(const void* el1, const void* el2, void* res); //сложение целых чисел
void numberMult(const void* el1, const void* el2, void* res); //произведение целых чисел
#endif /*NUMBER_H*/

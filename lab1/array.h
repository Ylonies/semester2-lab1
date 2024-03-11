#ifndef ARRAY_H
#define ARRAY_H
#include "fieldInfo.h"

typedef struct {
	void* data;
	FieldInfo* typeInfo;
	size_t size;
}Array;

typedef struct {
    char name[20]; // Имя вектора
    Array arr; // Сам вектор
} NamedArray;

typedef struct {
    NamedArray* arrs; // Динамический массив именованных векторов
    size_t size;
} ArrayCollection;


Array* arrayInit(FieldInfo* typeInfo);
void arrayPushBack(Array* arr, void* item);
void arrayFree(Array* arr);
void arrayPrint(Array* arr);
Array* arrayMap(MapElement mapElement, Array* arr);
Array* arrayFilter(CheckElement checkElement, Array* arr);
void arrayReduce(ReduceElements reduceElements, Array* arr, int NumberElem, void* res);

Array* arrayAddToCollection(ArrayCollection* collection, char* name, FieldInfo* typeInfo);
Array* arrayFindInCollection(ArrayCollection* collection, const char* name);
#endif ;
#ifndef ARRAY_H
#define ARRAY_H
#include "fieldInfo.h"

/*
    ’эдер, представл€ющий интерфейс дл€ работы с динамическим массивом
*/

typedef struct {
	void* data; //ссылка на первый элемент
	FieldInfo* typeInfo; //информаци€ о типе элементов
	size_t size; //количество элементов
}Array; //динамический массив

typedef struct {
    char name[20]; // »м€ вектора
    Array arr; // —ам вектор
} NamedArray;

typedef struct {
    NamedArray* arrs; // ƒинамический массив именованных векторов
    size_t size;
} ArrayCollection;


Array* arrayInit(FieldInfo* typeInfo); //инициализаци€ array
void arrayPushBack(Array* arr, void* item); //добавление элемента в конец array
void arrayFree(Array* arr); //освобождение пам€ти, занимаемой array
void arrayPrint(Array* arr); //вывод элементов array
Array* arrayMap(MapElement mapElement, Array* arr); //получение нового массива путем преобразовани€
                                                   // каждого элемента arr функцией mapElements
Array* arrayFilter(CheckElement checkElement, Array* arr); 
//получение нового массива состо€щего из элементов arr, удовлетвор€ющих checkElements
void arrayReduce(ReduceElements reduceElements, Array* arr, int NumberElem, void* res); 
// обединение элементов arr функцией reduceElements


Array* arrayAddToCollection(ArrayCollection* collection, char* name, FieldInfo* typeInfo); //добавление массива в коллекцию
Array* arrayFindInCollection(ArrayCollection* collection, const char* name); //поиск ссылки на массив из коллекции по имени 
#endif ;
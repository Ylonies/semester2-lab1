#ifndef ARRAY_H
#define ARRAY_H
#include "fieldInfo.h"

/*
    Хэдер, представляющий интерфейс для работы с динамическим массивом
*/

typedef struct {
	void* data; //ссылка на первый элемент
	FieldInfo* typeInfo; //информация о типе элементов
	size_t size; //количество элементов
}Array; //динамический массив

typedef struct {
    char name[20]; // Имя вектора
    Array arr; // Сам вектор
} NamedArray;

typedef struct {
    NamedArray* arrs; // Динамический массив именованных векторов
    size_t size;
} ArrayCollection;


Array* arrayInit(FieldInfo* typeInfo); //инициализация array
void arrayPushBack(Array* arr, void* item); //добавление элемента в конец array
void arrayFree(Array* arr); //освобождение памяти, занимаемой array
void arrayPrint(Array* arr); //вывод элементов array
Array* arrayMap(MapElement mapElement, Array* arr); //получение нового массива путем преобразования
                                                   // каждого элемента arr функцией mapElements
Array* arrayFilter(CheckElement checkElement, Array* arr); 
//получение нового массива состоящего из элементов arr, удовлетворяющих checkElements
void arrayReduce(ReduceElements reduceElements, Array* arr, int NumberElem, void* res); 
// обединение элементов arr функцией reduceElements


Array* arrayAddToCollection(ArrayCollection* collection, char* name, FieldInfo* typeInfo); //добавление массива в коллекцию
Array* arrayFindInCollection(ArrayCollection* collection, const char* name); //поиск ссылки на массив из коллекции по имени 
#endif ;

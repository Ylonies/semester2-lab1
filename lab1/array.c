#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "fieldInfo.h"

Array* arrayInit(FieldInfo* typeInfo) {
	Array* arr = (Array*)malloc(sizeof(Array));
	arr->data = NULL;
	arr->size = 0;
	arr->typeInfo = typeInfo;
	return arr;
}


void arrayPushBack(Array* arr, void* item) {
	size_t elemSize = arr->typeInfo->elementSize;
	arr->data = realloc(arr->data, (arr->size + 1) * elemSize);
	memcpy((char*)arr->data + arr->size * elemSize, item, elemSize);
	arr->size++;
}


void arrayFree(Array* arr) {
	free(arr->data);
	arr->data = NULL;
	arr->size = 0;
}

void arrayPrint(Array* arr) {
	for (size_t i = 0; i < arr->size; i++) {
		arr->typeInfo->printElement((const char*)arr->data + i * arr->typeInfo->elementSize);
	}
	printf("\n");
};



Array* arrayMap(MapElement mapElem, Array* arr) {
	Array* res_arr = arrayInit(arr->typeInfo);
	for (size_t i = 0; i < arr->size; i++) {
		const void* elem1 = (const char*)arr->data + i * arr->typeInfo->elementSize;
		void* res_elem = malloc(arr->typeInfo->elementSize);
		mapElem(elem1, res_elem);
		arrayPushBack(res_arr, res_elem);
		free(res_elem);
	}
	return res_arr;
};

Array * arrayFilter(CheckElement checkElement, Array* arr) {
	Array* res_arr = arrayInit(arr->typeInfo);
	for (size_t i = 0; i < arr->size; i++) {
		void* el = (const char*)arr->data + i * arr->typeInfo->elementSize;
		if (checkElement(el)) {
			arrayPushBack(res_arr, el);
		}
	}
	return res_arr;
};

void arrayReduce(ReduceElements reduceElements, Array* arr,  int NumberElem, void* res) {
	if (arr->size <= 1) {
		memcpy(res, arr->data, arr->typeInfo->elementSize);
	}
	else{
		const char* el1 = (const char*)arr->data + NumberElem * arr->typeInfo->elementSize;
		if (arr->size - NumberElem == 2) {
			reduceElements(el1, el1 + arr->typeInfo->elementSize, res);
		}
		else {
			arrayReduce(reduceElements, arr, NumberElem + 1, res);
			reduceElements(el1, res, res);
		}
	}
}
Array* arrayAddToCollection(ArrayCollection* collection, char* name, FieldInfo* typeInfo) {
	collection->arrs = realloc(collection->arrs, (collection->size + 1) * sizeof(NamedArray));
	NamedArray* newArr = &collection->arrs[collection->size];
	strncpy(newArr->name, name, sizeof(newArr->name));
	memcpy(&newArr->arr, arrayInit(typeInfo), sizeof(Array));
	collection->size++;
	return &newArr->arr;
}

Array* arrayFindInCollection(ArrayCollection* collection, const char* name)
{
	for (size_t i = 0; i < collection->size; i++)
	{
		if (strcmp(collection->arrs[i].name, name) == 0)
		{
			return &collection->arrs[i].arr;
		}
	}
	return NULL; // Не найден
}
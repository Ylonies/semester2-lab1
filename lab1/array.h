#ifndef ARRAY_H
#define ARRAY_H
#include "fieldInfo.h"

/*
    �����, �������������� ��������� ��� ������ � ������������ ��������
*/

typedef struct {
	void* data; //������ �� ������ �������
	FieldInfo* typeInfo; //���������� � ���� ���������
	size_t size; //���������� ���������
}Array; //������������ ������

typedef struct {
    char name[20]; // ��� �������
    Array arr; // ��� ������
} NamedArray;

typedef struct {
    NamedArray* arrs; // ������������ ������ ����������� ��������
    size_t size;
} ArrayCollection;


Array* arrayInit(FieldInfo* typeInfo); //������������� array
void arrayPushBack(Array* arr, void* item); //���������� �������� � ����� array
void arrayFree(Array* arr); //������������ ������, ���������� array
void arrayPrint(Array* arr); //����� ��������� array
Array* arrayMap(MapElement mapElement, Array* arr); //��������� ������ ������� ����� ��������������
                                                   // ������� �������� arr �������� mapElements
Array* arrayFilter(CheckElement checkElement, Array* arr); 
//��������� ������ ������� ���������� �� ��������� arr, ��������������� checkElements
void arrayReduce(ReduceElements reduceElements, Array* arr, int NumberElem, void* res); 
// ���������� ��������� arr �������� reduceElements


Array* arrayAddToCollection(ArrayCollection* collection, char* name, FieldInfo* typeInfo); //���������� ������� � ���������
Array* arrayFindInCollection(ArrayCollection* collection, const char* name); //����� ������ �� ������ �� ��������� �� ����� 
#endif ;
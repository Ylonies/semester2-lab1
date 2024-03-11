#ifndef CUSTOM_TYPE_H
#define CUSTOM_TYPE_H
#include <stdio.h>
#include "fieldInfo.h"

/*
    �����, �������������� ��������� ��� ������ � ������������ �������
*/

typedef struct {
    int real;
    int imag;
} Complex;

//�������� �������� ������� � ����� ������, ����� ���� �������, ����� ���������� ����������
FieldInfo* GetComplexFieldInfo();
void complexPrint(const void* elem);
void complexMapOpposite(const void* elem, void* res);
void complexMapReverse(const void* elem, void* res);

int complexCheckPosReal(const void* elem);
int complexCheckImagNotNull(const void* elem);

void complexSum(const void* elem1, const void* elem2, void* res);
void complexMult(const void* elem1, const void* elem2, void* res);
#endif

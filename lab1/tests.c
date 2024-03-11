#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "number.h"
#include "complex.h"
#include "fieldInfo.h"

//проверка на равенство array и массива целых чисел
int EqualIntArr(Array *arr1, int *data, int len) {
    if (arr1->size != len) {
        return -1;
    }
    for (size_t i = 0; i < arr1->size; i++) {
        char *el1 = (char*)arr1->data + i * arr1->typeInfo->elementSize;
        
        if (*(int*)el1 != *(data+i)) {
            return -1;
        }
    }
    return 0;
}

//проверка на равенство array и массива комплексных чисел
int EqualComplexArr(Array* arr1, Complex* data, int len) {
    if (arr1->size != len) {
        return -1;
    }
    for (size_t i = 0; i < arr1->size; i++) {
        Complex* el1 = (char*)arr1->data + i * arr1->typeInfo->elementSize;
        if (el1->real != (data + i)->real || el1->imag != (data + i)->imag) {
            return -1;
        }
    }
    return 0;
}


int testIntArray()
{
    int response = 0;
    ArrayCollection collection = { NULL, 0 };
    FieldInfo* IntFieldInfo = GetIntFieldInfo();
    arrayAddToCollection(&collection, "first", IntFieldInfo);
    if (collection.size != 1)
    {
        printf("arrayAddToCollection Int does not work!\n");
        response = -1;
    }
    Array* arr = arrayFindInCollection(&collection, "first");
    if (!arr) {
        printf("arrayFindInCollection Int  does not work!\n");
        response = -1;
    }
    else {
        int el[3] = { 1, -2, 33};
        arrayPushBack(arr, (void*)el);
        if (*(int*)arr->data != el[0]) {
            printf("arrayPushBack Int does not work!\n");
        }
        arrayPushBack(arr, (void*)(el + 1));
        arrayPushBack(arr, (void*)(el + 2));

        Array* arr1 = malloc(sizeof(Array));
        arr1 = arrayMap(numberMapAbs, arr);
        int data1[3] = {1, 2, 33};
        if (EqualIntArr(arr1, data1, 3) == -1) {
            printf("arrayMap numberMapAbs does not work\n");
            response = -1;
        }
        free(arr1);

        arr1 = arrayMap(numberMapLen, arr);
        int data2[3] = {1, 1, 2};
        if (EqualIntArr(arr1, data2, 3) == -1) {
            printf("arrayMap numberMapLen does not work\n");
            response = -1;
        }
        free(arr1);

        arr1 = arrayFilter(numberCheckPos, arr);
        int data3[2] = { 1, 33 };
        if (EqualIntArr(arr1, data3, 2) == -1) {
            printf("arrayfilter numbercheckpos does not work\n");
            response = -1;
        }
        free(arr1);

        arr1 = arrayFilter(numberCheckEven, arr);
        int data4[1] = { -2 };
        if (EqualIntArr(arr1, data4, 1) == -1) {
            printf("arrayFilter numberCheckEven does not work\n");
            response = -1;
        }
        free(arr1);

        int numberRes1;
        arrayReduce(numberSum, arr, 0, (void*)&numberRes1);
        if (numberRes1 != el[0]+el[1]+el[2]) {
            printf("arrayReduce numberSum does not work\n");
            response = -1;
        }

        int numberRes2;
        arrayReduce(numberMult, arr, 0, (void*)&numberRes2);
        if (numberRes2 != el[0]*el[1]*el[2]) {
            printf("arrayReduce numberMult does not work\n");
            response = -1;
        }
    }

// освобождение ресурсов
    for (size_t i = 0; i < collection.size; i++)
    {
        arrayFree(&collection.arrs[i].arr);
    }
    free(collection.arrs);
    return response;
}


int testComplexArray() {
    int response = 0;
    ArrayCollection collection = { NULL, 0 };
    FieldInfo* ComplexFieldInfo = GetComplexFieldInfo();
    arrayAddToCollection(&collection, "first", ComplexFieldInfo);
    if (collection.size != 1)
    {
        printf("arrayAddToCollection Complex does not work!\n");
        response = -1;
    }
    Array* arr = arrayFindInCollection(&collection, "first");
    if (!arr) {
        printf("arrayFindInCollection Complex does not work!");
        response = -1;
    }
    else {
        Complex el1 = {10, -2};
        Complex el2 = { 2, 3 };
        Complex elements[2] = {el1, el2};
        int len = 2;
        for (int i = 0; i < len; i++) {
            arrayPushBack(arr, (void*)(elements + i));
        }
        if (EqualComplexArr(arr, elements, 2)==-1) {
            printf("arrayPushBack Int does not work!\n");
        }

        Array *arr1 = arrayMap(complexMapOpposite, arr);
        Complex elements2[2] = { (Complex) { 10, 2 }, (Complex) { 2, -3 } };
        if (EqualComplexArr(arr1, elements2, 2) == -1) {
            printf("arrayMap complexMapOpposite does not work");
            response = -1;
        }
        free(arr1);
        arr1 = arrayMap(complexMapReverse, arr);
        Complex elements3[2] = { (Complex) { -2, 10 }, (Complex) { 3, 2 } };
        if (EqualComplexArr(arr1, elements3, 2) == -1) {
            printf("arrayMap complexMapReverse does not work");
            response = -1;
        }
        free(arr1);


        arr1 = arrayFilter(complexCheckImagNotNull, arr);
        if (EqualComplexArr(arr1, elements, 2) == -1) {
            printf("arrayFilter  complexCheckImagNotNull does not work");
            response = -1;
        }

        arr1 = arrayFilter(complexCheckPosReal, arr);
        if (EqualComplexArr(arr1, elements, 2) == -1) {
            printf("arrayFilter  complexCheckImagNotNull does not work");
            response = -1;
        }


        Complex numberRes1;
        arrayReduce(complexSum, arr, 0, (void*)&numberRes1);
        if (numberRes1.real != 12 || numberRes1.imag != 1) {
            printf("arrayReduce complexSum does not work");
            response = -1;
        }

        Complex numberRes2;
        arrayReduce(complexMult, arr, 0, (void*)&numberRes2);
        if (numberRes2.real!=26 || numberRes2.imag!=26) {
            printf("arrayReduce complexMult does not work");
            response = -1;
        }


    }
     /*освобождение ресурсов*/
    for (size_t i = 0; i < collection.size; i++)
    {
        arrayFree(&collection.arrs[i].arr);
    }
    free(collection.arrs);
    return response;
}

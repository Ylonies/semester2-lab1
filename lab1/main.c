#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "number.h"
#include "complex.h"
#include "fieldInfo.h"
#include "tests.h"



void printMenu()
{
    printf("\n_________Menu__________\n");
    printf("0. Show all arrays\n");
    printf("1. Print array\n");
    printf("_______________________\n");
    printf("2. Create int array\n");
    printf("3. Add element to int array\n");
    printf("4. Map Int Array\n");
    printf("5. Filter Int Array\n");
    printf("6. Reduce Int Array\n");
    printf("_______________________\n");
    printf("7. Create complex array\n");
    printf("8. Add element to complex array\n");
    printf("9. Map Complex Array\n");
    printf("10. Filter Complex Array\n");
    printf("11. Reduce Complex Array\n");
    printf("_______________________\n");
    printf("Enter 'STOP' for finish.\n");
    printf("Choose action: ");
}



int main()
{
    FieldInfo* IntFieldInfo = GetIntFieldInfo();
    FieldInfo* ComplexFieldInfo = GetComplexFieldInfo();

    // модульное тестирование перед переходом в меню
    if (testIntArray() == -1)
    {
        // нет смысла выполнять основной код, так как в тестах уже ошибка
        return -1;
    }
    if (testComplexArray() == -1)
    {
        return -1;
    }
    printf("All tests completed successfully!\n");

    ArrayCollection collection = { NULL, 0 }; //коллекция всех массивов
    while (1)
    {
        char input[20];
        printMenu();
        scanf("%19s", input);

        if (strcmp(input, "STOP") == 0)
        {
            break;
        }

        int action = atoi(input);
        switch (action)
        {
        case 0: //Show all arrays
        {
            char name[20];
            printf("All arrays: ");
            for (size_t i = 0; i < collection.size; i++)
            {
                printf("%s ", collection.arrs[i].name);
            }
            break;
        }
        case 1: //Print array
        {
            char name[20];
            printf("Enter array name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr) {
                arrayPrint(arr);
            }
            else {
                printf("Array not found.\n");
            }
            break;
        }
        case 2: //Create int array
        {
            char name[20];
            printf("Enter int  name: ");
            scanf("%19s", name);
            arrayAddToCollection(&collection, name, IntFieldInfo);
            break;
        }
        case 3: //Add element to int array
        {
            char name[20];
            printf("Enter int array name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr)
            {
                if (arr->typeInfo == IntFieldInfo)
                {
                    int value;
                    printf("Enter integer to add to int array: ");
                    scanf("%d", &value);
                    arrayPushBack(arr, &value);
                    arrayPrint(arr);
                }
                else {
                    printf("Not int array\n");
                }
            }
            else
            {
                printf("Array not found.\n");
            }
            break;
        }
        case 4: //Map Int Array
        {
            char name[30];
            printf("Enter Int Array name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr) {
                if (arr->typeInfo == IntFieldInfo) 
                {
                    printf("Choose the option:\n");
                    printf("0. Number-> abs(number)\n");
                    printf("1. Number-> len(number)\n");
                    int option;
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 0:
                    {
                        strcat(name, "_map0");
                        Array* arr1 = arrayAddToCollection(&collection, name, IntFieldInfo);
                        memmove(arr1, arrayMap(numberMapAbs, arr), sizeof(Array));
                        printf("%s: ", name);
                        arrayPrint(arr1);
                        break;
                    }
                    case 1:
                    {
                        strcat(name, "_map1");
                        Array* arr1 = arrayAddToCollection(&collection, name, IntFieldInfo);
                        memmove(arr1, arrayMap(numberMapLen, arr), sizeof(Array));
                        printf("%s: ", name);
                        arrayPrint(arr1);
                        break;
                    }
                    }
                }
                else 
                {
                    printf("Not Int Array\n");
                }
            }
            else {
                printf("Array not found.\n");
            }
            break;
        }
        case 5: //Filter Int Array
        {
            char name[30];
            printf("Enter Int Array name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr) 
            {
                if (arr->typeInfo == IntFieldInfo) 
                {
                    printf("Choose the option:\n");
                    printf("0. Find Possitive Numbers\n");
                    printf("1. Find Even Numbers\n");
                    int option;
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 0:
                    {
                        strcat(name, "_filt0");
                        Array* arr1 = arrayAddToCollection(&collection, name, IntFieldInfo);
                        memmove(arr1, arrayFilter(numberCheckPos, arr), sizeof(Array));
                        printf("%s: ", name);
                        arrayPrint(arr1);
                        break;
                    }
                    case 1:
                    {
                        strcat(name, "_filt1");
                        Array* arr1 = arrayAddToCollection(&collection, name, IntFieldInfo);
                        memmove(arr1, arrayFilter(numberCheckEven, arr), sizeof(Array));
                        printf("%s: ", name);
                        arrayPrint(arr1);
                        break;
                    }
                    }
                }
                else
                {
                    printf("Not Int Array\n");
                }
            }
            else 
            {
                printf("Array not found.\n");
            }
            break;
        }
        case 6: // Reduce Int Array
        {
            char name[30];
            printf("Enter Int Array name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr) {
                if (arr->typeInfo == IntFieldInfo) 
                {
                    printf("Choose the option:\n");
                    printf("0. Sum all numbers\n");
                    printf("1. Multiply all numbers\n");
                    int option;
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 0:
                    {
                        int numberRes = malloc(sizeof(int));
                        arrayReduce(numberSum, arr, 0, (void*)&numberRes);
                        printf("Result: %d", numberRes);
                        break;
                    }
                    case 1:
                    {
                        int numberRes = malloc(sizeof(int));
                        arrayReduce(numberMult, arr, 0, (void*)&numberRes);
                        printf("Result: %d", numberRes);
                        break;
                    }
                    }
                }
                else {
                    printf("Not Int Array\n");
                }
            }
            else {
                printf("Array not found.\n");
            }
            break;
        }

        case 7: //Create complex array
        {
            char name[20];
            printf("Enter Complex Array Name: ");
            scanf("%19s", name);
            arrayAddToCollection(&collection, name, ComplexFieldInfo);
            break;
        }
        case 8: //Add element to complex array
        {
            char name[20];
            printf("Enter complex vector name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr)
            {
                if (arr->typeInfo = ComplexFieldInfo) 
                {
                    int real;
                    int imag;
                    printf("Enter two int numbers like this '3 4' to \
                    \ncreate complex '3r+4i' and add it to complex array: ");
                    scanf("%d %d", &real, &imag);

                    Complex complex = { real, imag };
                    arrayPushBack(arr, &complex);
                }
                else {
                    printf("Not Complex array\n");
                }
         
            }
            else
            {
                printf("Array not found.\n");
            }
            break;
        }
        case 9: //Map Complex Array
        {
            char name[30];
            printf("Enter Complex Array name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr) {
                if (arr->typeInfo == ComplexFieldInfo)
                {
                    printf("Choose the option:\n");
                    printf("0. Complex-> Opposite Complex (3r+2i->3r-2i)\n");
                    printf("1. Complex-> Reversed Complex (3r+2i->2r+3i)\n");
                    int option;
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 0:
                    {
                        strcat(name, "_map0");
                        Array* arr1 = arrayAddToCollection(&collection, name, IntFieldInfo);
                        memmove(arr1, arrayMap(complexMapOpposite, arr), sizeof(Array));
                        printf("%s: ", name);
                        arrayPrint(arr1);
                        break;
                    }
                    case 1:
                    {
                        strcat(name, "_map1");
                        Array* arr1 = arrayAddToCollection(&collection, name, IntFieldInfo);
                        memmove(arr1, arrayMap(complexMapReverse, arr), sizeof(Array));
                        printf("%s: ", name);
                        arrayPrint(arr1);
                        break;
                    }
                    }
                }
                else {
                    printf("Not Complex Array\n");
                }
            }
            else {
                printf("Array not found.\n");
            }
            break;
        }
        case 10: //Filter Сomplex Array
        {
            char name[30];
            printf("Enter Complex Array name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr) {
                if (arr->typeInfo == ComplexFieldInfo) {
                    printf("Choose the option:\n");
                    printf("0. Filter Complex with Possitive Real Part\n");
                    printf("1. Filter Complex with Not Null Imaginary Part\n");
                    int option;
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 0:
                    {
                        strcat(name, "_filt0");
                        Array* arr1 = arrayAddToCollection(&collection, name, IntFieldInfo);
                        memmove(arr1, arrayFilter(complexCheckPosReal, arr), sizeof(Array));
                        printf("%s: ", name);
                        arrayPrint(arr1);
                        break;
                    }
                    case 1:
                    {
                        strcat(name, "_filt1");
                        Array* arr1 = arrayAddToCollection(&collection, name, IntFieldInfo);
                        memmove(arr1, arrayFilter(complexCheckImagNotNull, arr), sizeof(Array));
                        printf("%s: ", name);
                        arrayPrint(arr1);
                        break;
                    }
                    }
                }
                else {
                    printf("Not Complex Array\n");
                }

            }
            else {
                printf("Array not found.\n");
            }
            break;
        }
        case 11: //Reduce Complex Array
        {
            char name[30];
            printf("Enter Complex Array name: ");
            scanf("%19s", name);
            Array* arr = arrayFindInCollection(&collection, name);
            if (arr) {
                if (arr->typeInfo == ComplexFieldInfo) {
                    printf("Choose the option:\n");
                    printf("0. Sum all Complex numbers\n");
                    printf("1. Multiply all Complex numbers\n");
                    int option;
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 0:
                    {
                        Complex* complexRes = malloc(sizeof(Complex));
                        arrayReduce(complexSum, arr, 0, (void*)complexRes);
                        complexPrint((void*)complexRes);
                        break;
                    }
                    case 1:
                    {
                        Complex* complexRes = malloc(sizeof(Complex));
                        arrayReduce(complexMult, arr, 0, (void*)complexRes);
                        complexPrint((void*)complexRes);
                        break;
                    }
                    }
                }
                else {
                    printf("Not Complex Array\n");
                }
            }
            else {
                printf("Array not found.\n");
            }
            break;
        }

        default:
        {
            printf("Unknown command.\n");
            break;
        }
        }
    }
 
}

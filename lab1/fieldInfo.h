#include <stdio.h>
#ifndef FIELD_INFO_H
#define FIELD_INFO_H

typedef void(*PrintElement)(const void* el);
typedef void(*MapElement)(const void* el, void* res);
typedef int(*CheckElement)(const void* el);
typedef void*(*ReduceElements)(const void* el1, const void* el2);

typedef struct FieldInfo {
    char* typeName;
    size_t elementSize;
    PrintElement printElement;
} FieldInfo;

#endif

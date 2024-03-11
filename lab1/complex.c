#include <stdlib.h>
#include "complex.h"
#include <math.h>

static FieldInfo* COMPLEX_FIELD_INFO = NULL;

FieldInfo* GetComplexFieldInfo() {
    if (COMPLEX_FIELD_INFO == NULL) {
        COMPLEX_FIELD_INFO = (FieldInfo*)malloc(sizeof(FieldInfo));
        COMPLEX_FIELD_INFO->typeName= "Complex";
        COMPLEX_FIELD_INFO->elementSize = sizeof(Complex);
        COMPLEX_FIELD_INFO->printElement = complexPrint;
    }
    return COMPLEX_FIELD_INFO;
}


void complexPrint(const void* elem) {
    const Complex* complexElem = (const Complex*)elem;
    int imag = complexElem->imag;
    if (imag >= 0) { 
        printf("%dr+%di, ", complexElem->real, imag);
    }
    else{
        printf("%dr-%di, ", complexElem->real, abs(imag));
    }
}

void complexMapOpposite(const void* elem, void* res) {
    const Complex* complexElem = (const Complex*)elem;
    Complex* complexRes = (const Complex*)res;
    complexRes->real = complexElem->real;
    complexRes->imag = (complexElem->imag)*(-1);
}

void complexMapReverse(const void* elem, void* res) {
    const Complex* complexElem = (const Complex*)elem;
    Complex* complexRes = (Complex*)res;
    complexRes->real = complexElem->imag;
    complexRes->imag = complexElem->real;
}

int complexCheckPosReal(const void* elem) {
    const Complex* complexElem = (const Complex*)elem;
    return complexElem->real > 0;
}

int complexCheckImagNotNull(const void* elem) {
    const Complex* complexElem = (const Complex*)elem;
    return complexElem->imag != 0;
}

void complexSum(const void* elem1, const void* elem2, void* res) {
    const Complex* complexElem1 = (const Complex*)elem1;
    const Complex* complexElem2 = (const Complex*)elem2;
    Complex* complexRes = (Complex*)res;
    complexRes->real = complexElem1->real + complexElem2->real;
    complexRes->imag = complexElem1->imag + complexElem2->imag;
}

void complexMult(const void* elem1, const void* elem2, void* res) {
    const Complex* complexElem1 = (const Complex*)elem1;
    const Complex* complexElem2 = (const Complex*)elem2;
    Complex* complexRes = (Complex*)res;
    complexRes->real = complexElem1->real * complexElem2->real - complexElem1->imag * complexElem2->imag;
    complexRes->imag = complexElem1->imag * complexElem2->real + complexElem1->real * complexElem2->imag;
}
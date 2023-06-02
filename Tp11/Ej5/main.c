#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "complexADT.h"

#define EPSILON 0.0000000001

int main() {
    // Crea dos números complejos para las pruebas
    complexADT c1 = newComplex(2.0, 3.0);
    complexADT c2 = newComplex(1.0, 4.0);

    // Verifica que las partes reales e imaginarias son correctas
    assert(fabs(getReal(c1) - 2.0) < EPSILON);
    assert(fabs(getImaginary(c1) - 3.0) < EPSILON);
    assert(fabs(getReal(c2) - 1.0) < EPSILON);
    assert(fabs(getImaginary(c2) - 4.0) < EPSILON);

    printf("Parte real de c1: %f\n", getReal(c1));
    printf("Parte imaginaria de c1: %f\n", getImaginary(c1));
    printf("Parte real de c2: %f\n", getReal(c2));
    printf("Parte imaginaria de c2: %f\n", getImaginary(c2));

    // Suma c1 y c2
    complexADT sum = addComplex(c1, c2);

    // Verifica que la suma es correcta
    assert(fabs(getReal(sum) - 3.0) < EPSILON);
    assert(fabs(getImaginary(sum) - 7.0) < EPSILON);

    printf("Parte real de la suma: %f\n", getReal(sum));
    printf("Parte imaginaria de la suma: %f\n", getImaginary(sum));

    // Libera la memoria de los números complejos
    freeComplex(c1);
    freeComplex(c2);
    freeComplex(sum);

    return 0;
}

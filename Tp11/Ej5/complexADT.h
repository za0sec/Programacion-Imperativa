#ifndef COMPLEX_H
#define COMPLEX_H


typedef struct complexCDT * complexADT;

complexADT newComplex(double realNum, double imagNum);

double getReal(complexADT num);

double getImaginary(complexADT num);

void freeComplex(complexADT num);

complexADT addComplex(complexADT num1, complexADT num2);

#endif /* COMPLEX_H */

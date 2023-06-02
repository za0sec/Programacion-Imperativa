#include "complexADT.h"
#include <stddef.h>
#include <stdlib.h>


typedef struct complexCDT{

  double real;
  double im;

}Tcomplex;

complexADT addComplex(complexADT num1, complexADT num2){

  complexADT sum = malloc(sizeof(Tcomplex));

  sum->real = num1->real + num2->real;
  sum->im = num1->im + num2->im;

  return sum;
}

double getReal(complexADT num){

  return num->real;

}

double getImaginary(complexADT num){

  return num->im;

}

complexADT newComplex(double realNum, double imagNum){

  complexADT new = malloc(sizeof(Tcomplex));
  
  new->real = realNum;
  new->im = imagNum;


  return new;
}

void freeComplex(complexADT num){

  if (num != NULL)
    free(num);

}

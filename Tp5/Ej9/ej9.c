#include <stdio.h>
#include <math.h>
#include "../../libreria/getnum.h"
#define EPSILON 0.0000000001

double funcion(double i){

  return sin(i);

}


void roots(double i, double top){


  int sign, num2 = funcion(i) > 0 ? 1 : -1;

  for (; i <= top; i+=0.001  ){
    
    sign = funcion(i) > 0 ? 1 : -1; 

    if( ( fabs(funcion(i)) < EPSILON ) || ( sign != num2 ) ){



      printf("En %f hay raiz\n", i);


    }
    
    num2 = sign; 

  }

}

int main(){

  double i = -50.0;
  double top = 50.0;

  roots(i, top);

}



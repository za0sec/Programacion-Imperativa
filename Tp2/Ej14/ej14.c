#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int a = getint("Ingrese el primer numero: ");
  printf("Gracias!\n");
  int b = getint("Ingrese el segundo numero: ");

  float prom = (a + b)/(float)2;
  int sum = a + b;
  if ( a < b ){
    
    printf("La suma es: %d\n", sum);
    printf("El promedio es: %.1f\n", prom);
    printf("El menor es: %d\n", a);
    printf("El mayor es: %d\n", b);
    printf("No son iguales\n");

  }else if ( b < a ){


    printf("La suma es: %d\n", sum);
    printf("El promedio es: %1.f\n", prom);
    printf("El menor es: %d\n", b);
    printf("El mayor es: %d\n", a); 
    printf("No son iguales\n");

  }else{

    printf("son iguales\n");

  }

  


}

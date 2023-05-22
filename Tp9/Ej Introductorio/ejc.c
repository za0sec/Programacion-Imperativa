#include <stdio.h>
#include <stdlib.h>


int main(){
  
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;

  printf("Ingrese el valor de a: ");
  scanf("%d", &a);
  printf("Ingrese el valor de b: ");
  scanf("%d", &b);
  printf("Ingrese el valor de c: ");
  scanf("%d", &c);
  printf("Ingrese el valor de d: ");
  scanf("%d", &d);
  printf("Ingrese el valor de e: ");
  scanf("%d", &e);

  int resultado = a + b + c + d + e;
  printf("El resultado es: %d\n", resultado);

  return 0;
  
  
  
}

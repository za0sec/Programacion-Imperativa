/*

Escribir una función recursiva que reciba como parámetros de entrada un vector de enteros y su dimensión, 
y que devuelva en su nombre la suma de todos sus elementos.

*/

#include <stdio.h>
#include <stdlib.h>

int sum(int *v, int dim);
  
int main(){

  int v[] = {2,5,7,23,2,3,4,5};
  
  int dim = sizeof(v)/sizeof(v[0]);

  printf("%d", sum(v, dim));

}

int sum(int *v, int dim){

  if (dim == 0)
    return 0;

  return (*v) + sum(v+1, dim-1);

}

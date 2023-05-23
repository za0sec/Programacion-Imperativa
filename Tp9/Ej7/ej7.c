/*
Escribir una función recursiva busquedaBinaria que reciba como únicos parámetros:

datos: un vector de enteros ordenados en forma ascendente.
dim: la dimensión del mismo
num: un número entero

Dicha función debe devolver 1 si num es un elemento de datos y 0 en caso contrario. 
La búsqueda del elemento se debe realizar utilizando el algoritmo de búsqueda binaria. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int busquedaBinaria(int *datos, int dim, int num);


int main(void) {

  int v[] = {-10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45};

  assert(busquedaBinaria(v, 0, -10)==0);
  assert(busquedaBinaria(v, 1, -10)==1);
  assert(busquedaBinaria(v, 2, -10)==1);
  assert(busquedaBinaria(v, 2, -5)==1);
  assert(busquedaBinaria(v, 2, 0)==0);

  assert(busquedaBinaria(v+1, 2, -10)==0);
  assert(busquedaBinaria(v+1, 2, -5)==1);
  assert(busquedaBinaria(v+1, 2, 0)==1);
  
  for(int i=0; i < 12; i++)
    assert(busquedaBinaria(v, 12, v[i])==1);
    
  for(int i=0; i < 11; i++)
    assert(busquedaBinaria(v, 11, v[i])==1);


  printf ("OK!\n");
  return 0;
}

int busquedaBinaria(int *datos, int dim, int num){

  if (dim == 0)
    return 0;

  if (datos[dim/2] == num)
    return 1;

  return (datos[dim/2] >num) ? busquedaBinaria(datos, (dim/2)-1, num) : busquedaBinaria(datos+(dim/2)+1, dim-(dim/2)-1, num);


}


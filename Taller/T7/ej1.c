#include <stdio.h>
#include <stdlib.h>

int main(){

  // 1

  int * arr;
  
  arr = malloc(TAM * sizeof(int));

  for (i=0; i<TAM; i++)
    arr[i] = 0;

  mostrarArreglo(arr, TAM);

  free(arr);


  // 2

  int * arr = NULL;

  arr = realloc(arr, TAM*sizeof(int));

  for (i=0; i<TAM; i++)
    arr[i] = 0;

  mostrarArreglo(arr, TAM);

  free(arr);


  // 3
  
  arr = calloc(TAM, sizeof(int));

  mostrarArreglo(arr, TAM);

  free(arr);

}




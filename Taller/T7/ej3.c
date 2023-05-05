#include <stdio.h>
#include <stdlib.h>
#include "../../libreria/getnum.h"
#define BLOQUE 10

int * leerNumero(int * dim);

int pertenece(int n, int * v, int dim);

int main(){

  int dim;

  int * str = NULL;

  str = leerNumero(&dim);

  for (int i=0; i<dim; i++){

    printf("%d", str[i]);
  
  }

  free(str);

}

int * leerNumero(int * dim){

  int n, tam=0;
  int * aux = NULL;
  
  while(!pertenece(n = getint(""), aux, tam)){

    if (tam % BLOQUE == 0){
      aux = realloc(aux, sizeof(int)*tam*BLOQUE);
    }

    aux[tam++] = n;

  }

  aux = realloc(aux, tam*sizeof(int));
  
  *dim = tam;

  return aux;


}

int pertenece(int n, int * v, int dim){

  int found = 0;
  for(int i=0; i<dim && !found; i++){

    if (v[i] == n){
      found = 1;
    }

  }

  return found;


}


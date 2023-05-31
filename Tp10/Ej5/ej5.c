//Escribir la función recursiva restaList que reciba únicamente 
//dos listas de enteros ordenadas en forma ascendente y sin repetidos, 
//y retorne una nueva lista ordenada y sin repetidos 
//con los elementos de la primer lista que no están en la segunda lista.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../libreria/utillist.h"

TList restaList(TList lista1, TList lista2);

#define ELEMS 200

int main(void) {

  int pares[ELEMS], impares[ELEMS];

  for(int i=1; i <= ELEMS; i++) {
    pares[i-1] = i * 2 ;
    impares[i-1] = i * 2 - 1;
  }

  TList lPar = fromArray(pares, ELEMS);
  TList lImpar = fromArray(impares, ELEMS);

  TList lPar2 = restaList(lPar, lImpar);
  assert(checkElems(lPar2, pares, ELEMS));
  // Verificamos ademas que no sean los mismos nodos
  assert(lPar2 != lPar);
  assert(lPar2->tail != lPar->tail);
  freeList(lPar2);
  freeList(lPar);
  freeList(lImpar);

  int all[ELEMS * 2];
  for(int i=1, j=0; i <= ELEMS; i++) {
    all[j++] = i * 2 - 1;
    all[j++] = i * 2 ;
  }
  TList lAll = fromArray(all, ELEMS * 2);
  lPar = fromArray(pares, ELEMS);
  TList lImpar2 = restaList(lAll, lPar);
  assert(checkElems(lImpar2, impares, ELEMS));
  freeList(lPar);

  lPar = restaList(lAll, lImpar2);
  assert(checkElems(lPar, pares, ELEMS));
  freeList(lPar);
  freeList(lAll);
  
  lPar = NULL;
  lImpar = fromArray(impares, ELEMS);
  TList aux = restaList(lPar, lImpar);
  assert(aux == NULL);
  freeList(lImpar);

  aux = restaList(lImpar2, lImpar2);
  assert(aux == NULL);
  freeList(lImpar2);

  printf ("OK!\n");
  return 0;
}

TList restaList(TList lista1, TList lista2){

  if (lista1 == NULL){
    return NULL;
  }
  
  if (lista2 == NULL){
    TList aux = malloc(sizeof(TNode));
    aux->elem = lista1->elem;
    aux->tail = restaList(lista1->tail, NULL);
    return aux;
  }


 if (lista1->elem == lista2->elem){
    return restaList(lista1->tail, lista2->tail);
  }else if (lista1->elem > lista2->elem){
    return restaList(lista1, lista2->tail);
  }else{
    TList aux = malloc(sizeof(TNode));
    aux->elem = lista1->elem;
    aux->tail = restaList(lista1->tail, lista2);
    return aux;
  }
}

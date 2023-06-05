//Escribir una función recursiva deleteDupl que reciba 
//como único parámetro una lista ordenada pero con repetidos 
//y elimine de la misma las repeticiones.

//Por ejemplo si la lista es {1, 3, 3, 3, 4, 5, 5, 6, 6, 6} la lista quede {1, 3, 4, 5, 6}

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../libreria/utillist.h"

/*
** En esta versiรณn dejamos el primer elemento de una secuencia de repetidos
** Puede ser void porque el head de la lista no cambia
*/
void deleteDupl (TList list);

/*
** Dejamos el ultimo de la secuencia, por lo que la lista puede cambiar
*/ 
TList deleteDupl2 (TList list);


int main(void) {

  // Secuencias sin repetir, cantidad par e impar de repetidos
  // Probar repetidos en el medio, al principio y al final
  // En realidad no hace falta que esten ordenados, deberia funcionar igual
  int v[] = {1, 2, 3, 3, 4, 4, 4, 5, 6, 6, 7, 7, 7, 7, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6,  7, 8};

  TList l1 = fromArray(v, 16);
  deleteDupl(l1);
  assert(checkElems(l1, w, 8));
  freeList(l1);

  l1 = fromArray(v, 16);
  l1 = deleteDupl2(l1);
  assert(checkElems(l1, w, 8));
  freeList(l1);

  l1 = fromArray(v, 1);
  deleteDupl(l1);
  assert(checkElems(l1, w, 1));
  freeList(l1);

  l1 = fromArray(v, 1);
  l1 = deleteDupl2(l1);
  assert(checkElems(l1, w, 1));
  freeList(l1);

  l1 = fromArray(v, 2);
  deleteDupl(l1);
  assert(checkElems(l1, w, 2));
  freeList(l1);

  l1 = fromArray(v, 2);
  l1 = deleteDupl2(l1);
  assert(checkElems(l1, w, 2));
  freeList(l1);

  l1 = fromArray(v, 4);
  deleteDupl(l1);
  assert(checkElems(l1, w, 3));
  freeList(l1);

  l1 = fromArray(v, 4);
  l1 = deleteDupl2(l1);
  assert(checkElems(l1, w, 3));
  freeList(l1);

  l1 = fromArray(v+2, 5);
  deleteDupl(l1);
  assert(checkElems(l1, w+2, 2));
  freeList(l1);

  l1 = fromArray(v+2, 5);
  l1 = deleteDupl2(l1);
  assert(checkElems(l1, w+2, 2));
  freeList(l1);

  printf ("OK!\n");
  return 0;
}

void deleteDupl (TList list){

  if (list == NULL || list->tail == NULL){
    return;
  }

  deleteDupl(list->tail);

  if (list->elem == list->tail->elem){    
    TList aux = list->tail;
    list->tail = list->tail->tail;
    free(aux);
  }

}



TList deleteDupl2(TList list) {
  if (list == NULL) {
    return NULL;
  }

  TList aux = list->tail;  

  if (list->tail != NULL && list->elem == aux->elem) {
    free(list); 
    return deleteDupl2(aux);
  } else {
    list->tail = deleteDupl2(aux); 
  }

  return list;
}


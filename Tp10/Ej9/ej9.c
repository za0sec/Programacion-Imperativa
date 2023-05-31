//Escribir la función recursiva comprimeList que reciba una lista 
//ordenada donde cada elemento es menor o igual al siguiente (puede tener repetidos), 
//y retorne una nueva lista de tipo TListBrief ordenada donde en cada nodo se indica 
//la cantidad de veces que aparece el elemento.

//Ejemplo:
//Si la lista original  tiene los elementos [1, 2, 2, 2, 5, 6, 6, 7, 7, 7, 7, 7]
//debe retornar una lista con los nodos  {1,1}, {2,3}, {5,1}, {6,2}, {7,5}


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../libreria/utillist.h"

typedef struct nodeBrief * TListBrief; 

typedef struct nodeBrief {
		int elem;
		size_t count;
		struct nodeBrief * tail;
} TNodeBrief;


TListBrief comprimeList(const TList list);

// Auxiliar para que pase el test con sanitizer
void freeListBrief(TListBrief lb) {
   if ( lb == NULL)
     return;
   freeListBrief(lb->tail);
   free(lb);
}

int main(void) {

  int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
  TList list = fromArray(v, sizeof(v)/sizeof(v[0]));
  TListBrief bf = comprimeList(list);

  TListBrief aux = bf;
  assert(aux->elem ==1 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==2 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==3 && aux->count == 5);

  aux = aux->tail;
  assert(aux->elem ==10 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==100 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==998 && aux->count == 1);

  aux = aux->tail;
  assert(aux == NULL);

  freeList(list);
  freeListBrief(bf);
  
  printf ("OK!\n");
  return 0;
}

TListBrief comprimeList(const TList list){

  if (list == NULL)
    return NULL;

  TListBrief aux = malloc(sizeof(TNodeBrief));

  aux->elem = list->elem;

  if (list->tail == NULL || list->tail->elem != list->elem){
    aux->count = 1;
    aux->tail = comprimeList(list->tail);
  }else{
    TListBrief second = comprimeList(list->tail);
    aux->count = 1 + second->count;
    aux->tail = second->tail;
    free(second);
  }

  return aux;

}  

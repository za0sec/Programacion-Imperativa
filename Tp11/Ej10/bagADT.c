#include "bagADT.h"
#include <stdlib.h>


typedef struct node * TList;

typedef struct node{

  elemType head;
  struct node * tail;


}TNode;

typedef struct bagCDT{

  TList first;
  size_t size;
  int (*compare)(elemType, elemType);

}bagCDT;


bagADT newBag( int (*compare)(elemType, elemType) ){

  bagADT bag = calloc(1, sizeof(bagCDT));

  bag->compare = compare;

  return bag;
}


static TList addRec(TList list, elemType elem, size_t * cant, int (*compare)(elemType, elemType)){

  if (list == NULL || compare(list->head, elem) > 0){

    TList aux = malloc(sizeof(TNode));
    aux->head = elem;
    aux->tail = list;
    return aux;
    
  }

  if (!compare(list->head, elem)){
    (*cant)++;
  }

  list->tail = addRec(list->tail, elem, cant, compare);
  return list;

}

size_t add(bagADT bag, elemType elem){

  size_t cant = 1;

  bag->first = addRec(bag->first, elem, &cant, bag->compare);

  (bag->size)++;

  return cant;

}

void countRec(TList list, elemType elem, size_t * cant, int (*compare)(elemType, elemType)){

  int act = compare(list->head, elem);
  
  if (list == NULL || act > 0)
    return;
  
  if (!act)
    (*cant)++;

  countRec(list->tail, elem, cant);
}

size_t count(const bagADT bag, elemType elem){

  size_t cant = 0;

  countRec(bag->first, elem, &cant, bag->compare);

  return cant;

}

size_t size(const bagADT bag){
  
  return bag->size;
  
}

elemType mostPopular(bagADT bag){
  
  
  
}


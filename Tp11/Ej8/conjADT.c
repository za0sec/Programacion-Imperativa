#include "conjADT.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node * TList;

typedef struct node{

  elemType head;
  struct node * tail;

}TNode;


typedef struct conjCDT{

  TList first;
  int (*f)(elemType, elemType);
  size_t size;

}conjCDT;

int f (elemType elem1, elemType elem2) {
   return elem1 - elem2;
}


void printConj(conjADT conj) {
    TList current = conj->first;

    while(current != NULL) {
        printf("%d ", current->head);
        current = current->tail;
    }

    printf("\n");
}


conjADT newConj(int (*f)(elemType, elemType)) {
  
  conjADT newConj = malloc(sizeof(conjCDT));
  
  newConj->first = NULL; 
  
  newConj->f = f;
  
  newConj->size = 0;
  
  return newConj;
}

static TList addElemRec(TList list, elemType elem, size_t *size, int (*f)(elemType, elemType)) {
    if (list == NULL || f(elem, list->head) < 0 ){
        TList aux = malloc(sizeof(TNode));
        aux->head = elem;
        aux->tail = list;
        (*size)++; 
        return aux;
    }

    if (list->head == elem){
        return list;
    }

    list->tail = addElemRec(list->tail, elem, size);
    return list;
}

int addElem(conjADT conj, elemType elem) {
  TList old_first = conj->first;
  conj->first = addElemRec(conj->first, elem, &(conj->size), conj->f);
  return (old_first != conj->first);
}

static TList deleteElemRec(TList list, elemType elem, int (*f)(elemType, elemType)){

  if (list == NULL){
    return NULL;
  }

  if ( !(f(elem, list->head)) ){
    TList aux = list->tail;
    free(list);
    return aux;
  }

  list->tail = deleteElemRec(list->tail, elem);
  return list;
}


int deleteElem(conjADT conj, elemType elem){
    
  conj->first = deleteElemRec(conj->first, elem, conj->f);
    
  if (conj->first != NULL){
    (conj->size)--;
    return 1;
  }

  return 0;

}


static TList unionRec(TList list1, TList list2, int (*f)(elemType, elemType)){

  if (list1 == NULL && list2 == NULL)
    return NULL;

   TList aux = malloc(sizeof(TNode));

  if (list1 == NULL || f(list1->head, list2->head) > 0){
    aux->head = list2->head;
    aux->tail = unionRec(list1, list2->tail);
    return aux;

  }
  if (list2 == NULL || f(list1->head, list2->head) < 0){
    aux->head = list1->head;
    aux->tail = unionRec(list1->tail, list2);
    return aux;

  }

  aux->head = list1->head; 
  aux->tail = unionRec(list1->tail, list2->tail);
  return aux;

}


conjADT unionConj(conjADT conj1, conjADT conj2){

  conjADT conjOut = malloc(sizeof(conjCDT));

  conjOut->first = unionRec(conj1->first, conj2->first, conj1->f);

  conjOut->size = (conj1->size) + (conj2->size);

  return conjOut;

}

static TList interRec(TList list1, TList list2, size_t * size, int (*f)(elemType, elemType)){

  if (list1 == NULL || list2 == NULL)
    return NULL;

  
  if ( !(f(list1->head, list2->head)) ){

    TList aux = malloc(sizeof(TNode));
    (*size)++;
    aux->elem = list1->elem;
    aux->tail = interRec(list1->tail, list2->tail, size);
    return aux;
    
  }

  if (f(list1->head, list2->head) > 0){
  
    return interRec(list1, list2->tail, size);

  }

  return interRec(list1->tail, list2, size);

}




conjADT interConj(conjADT conj1, conjADT conj2){

  conjADT conjOut = malloc(sizeof(conjCDT));

  conjOut->size = 0;

  conjOut->first = interRec(conj1->first, conj2->first, &(conjOut->size), conj1->f);

  conjOut->f = conj1->f;

  return conjOut;
  
}


TList differenceRec(TList list1, TList list2, size_t * size, int (*f)(elemType, elemType)){

  if (list1 == NULL)
    return NULL;


  if (list2 == NULL || f(list1->head, list2->head) < 0){
    TList aux = malloc(sizeof(TNode));
    (*size)++;
    aux->head = list1->head;
    aux->tail = differenceRec(list1->tail, list2, size);
    return aux;
  }

  if (f(list1->head, list2->head) > 0){
    return differenceRec(list1, list2->tail, size);
  }

  return differenceRec(list1->tail, list2->tail, size);

}

conjADT difference(conjADT conj1, conjADT conj2){

  conjADT conjOut = malloc(sizeof(conjCDT));

  conjOut->size = 0;

  conjOut->first = differenceRec(conj1->first, conj2->first, &(conjOut->size), conj1->f);

  conjOut->f = conj1->f;

  return conjOut;


}

void freeConj(conjADT conj) {

    TList actual = conj->first;
    TList next;
    
    while (actual != NULL) {
        next = actual->tail;
        free(actual);
        actual = next;
    }
    
    free(conj);
}

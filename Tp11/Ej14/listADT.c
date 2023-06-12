#include "listADT.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node * TList;

typedef struct node{

    elemType elem;
    struct node * tail;
    
    

}TNode;

typedef struct listCDT{

    TList firstNot;
    TList firstAsc;
    TList lastNot;
    TList iteratorNot;
    TList iteratorAsc;
    int (*compare)(elemType, elemType);

}listCDT;

void toBegin(listADT list){
    
    list->iteratorNot = list->firstNot;
    
}


listADT newList(int (*compare) (elemType e1, elemType e2)){

    listADT aux = calloc(1, sizeof(listCDT));
    aux->compare = compare;
    return aux;
}



static TList addRec(TList l, elemType elem, int (*compare)(elemType, elemType)){

    
    if (l == NULL || compare(l->elem, elem) > 0){
        TList aux = malloc(sizeof(TNode));
        aux->elem = elem;
        aux->tail = l;
        return aux;
    }

    if (compare(l->elem, elem) < 0){
        l->tail = addRec(l->tail, elem, compare);
    }

    return l;
}


void add(listADT list, elemType elem){
    
    TList aux = calloc(1, sizeof(TNode));
    aux->elem = elem;

    if (list->firstNot == NULL){
        list->firstNot = aux;
    }else{
        list->lastNot->tail = aux;
    }

    list->lastNot = aux;

    list->firstAsc = addRec(list->firstAsc, elem, list->compare);
    
}

int hasNext(listADT list){

   return list->iteratorNot != NULL;

}

elemType next(listADT list){
    
    if (hasNext(list)){
        elemType element = list->iteratorNot->elem;
        list->iteratorNot = list->iteratorNot->tail;
        return element;
    }else {
        fprintf(stderr, "No existe tal elemento!\nAborting...");
        exit(1);
    }
}

void toBeginAsc(listADT list){
    list->iteratorAsc = list->firstAsc;
}

int hasNextAsc(listADT list){
    return list->iteratorAsc != NULL;
}

elemType nextAsc(listADT list){
    if (hasNextAsc(list)){
        elemType element = list->iteratorAsc->elem;
        list->iteratorAsc = list->iteratorAsc->tail;
        return element;
    }else {
        fprintf(stderr, "No existe tal elemento!\nAborting...");
        exit(1);
    }
}

void freeList(listADT list){

    TList actual = list->firstAsc;
    TList next;

    while(actual != NULL){
        next = actual->tail;
        free(actual);
        actual = next;
    }

    actual = list->firstNot;

    while(actual != NULL){
        next = actual->tail;
        free(actual);
        actual = next;
    }

    free(list);
}

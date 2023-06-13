#include <stdlib.h>
#include "moveToFrontADT.h"

typedef struct node * TList;

typedef struct node{
    elemType elem;
    struct node * tail;

}TNode;

typedef struct moveToFrontCDT{

    TList first;
    TList iterator;
    size_t size;

}moveToFrontCDT;

moveToFrontADT newMoveToFront(){

    return calloc(1, sizeof(moveToFrontCDT));

}

static TList addRec(TList list, elemType elem, size_t * size){
    

    if (list == NULL){
        TList aux = malloc(sizeof(TNode));
        aux->elem = elem;
        aux->tail = NULL;
        (*size)++;
        return aux;
    }

    if (compare(list->elem, elem)){
        list->tail = addRec(list->tail, elem, size);
    }
    
    return list;
    
} 

unsigned int add(moveToFrontADT moveToFront, elemType elem){

    size_t aux = moveToFront->size;

    moveToFront->first = addRec(moveToFront->first, elem, &(moveToFront->size));

    if (aux != moveToFront->size)
        return 1;

    return 0;

}

unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->size;
}

void toBegin(moveToFrontADT moveToFront){
    moveToFront->iterator = moveToFront->first;
}

int hasNext(moveToFrontADT moveToFront){
    return moveToFront->iterator != NULL;
}

elemType next(moveToFrontADT moveToFront){
   if (hasNext(moveToFront)){
        elemType element = moveToFront->iterator->elem;
        moveToFront->iterator = moveToFront->iterator->tail;
        return element;
    }

    exit(1);
}

static TList deleteGet(TList list, elemType elem, size_t * flag){

    if (list == NULL){
        return NULL;
    }

    if (!compare(list->elem, elem)){
        TList aux = list->tail;
        free(list);
        (*flag) = 1;
        return aux;
    }
    
    list->tail = deleteGet(list->tail, elem, flag);
    return list;
} 

elemType * get(moveToFrontADT moveToFront, elemType elem){

    if (!compare(moveToFront->first->elem, elem)) {
        return &(moveToFront->first->elem);
    }

    size_t flag = 0;

    TList aux = deleteGet(moveToFront->first, elem, &flag);
    
    if (flag){
        moveToFront->first->elem = elem;
        moveToFront->first->tail = aux; 
        elemType * element = malloc(sizeof(elemType));
        *element = moveToFront->first->elem;
        return element;
    }

    return NULL;

} 

void freeMoveToFront(moveToFrontADT moveToFront){

    TList actual = moveToFront->first;
    TList next;

    while (actual != NULL){
        next = actual->tail;
        free(actual);
        actual = next;
    }

    free(moveToFront);
}

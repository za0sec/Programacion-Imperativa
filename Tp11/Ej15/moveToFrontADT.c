#include <stdlib.h>
#include "moveToFrontADT.h"

typedef struct node * TList;

typedef struct node{
    elemType elem;
    struct node * tail;

}TNode;

typedef struct moveToFrontCDT{

    TList first;
    TList last;
    TList iterator;
    size_t size;

}moveToFrontCDT;




moveToFrontADT newMoveToFront(){

    return calloc(1, sizeof(moveToFrontCDT));

}

    

static int belongsRec(TList list, elemType elem){

    if (list == NULL){
        return 1;
    }

    if (!compare(list->elem, elem)){
        return 0;
    }
    
    if (compare(list->elem, elem) < 0){
        return belongsRec(list->tail, elem);
    }
    
    return 1;
} 


unsigned int add(moveToFrontADT moveToFront, elemType elem){

    if (belongsRec(moveToFront->first, elem)){

        TList aux = calloc(1, sizeof(TNode));
        aux->elem = elem;

        if (moveToFront->first == NULL){
            moveToFront->first = aux;
        }else{
            moveToFront->last->tail = aux;
        }

        moveToFront->last = aux;
       
        (moveToFront->size)++;

        return 1;

    }else{
        return 0;
    }
}


unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->size;
}


void toBegin(moveToFrontADT moveToFront){
    moveToFront->iterator = moveToFront->first;
}


int hasNext(moveToFrontADT moveToFront){
    return moveToFront->iterator->tail != NULL;
}

elemType next(moveToFrontADT moveToFront){
   if (hasNext(moveToFront->iterator)){

    }

    return NULL;
}


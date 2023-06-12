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
    
    return belongsRec(list->tail, elem);
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
    return moveToFront->iterator != NULL;
}

elemType next(moveToFrontADT moveToFront){
   if (hasNext(moveToFront->iterator)){
        elemType element = moveToFront->iterator->elem;
        moveToFront->iterator = moveToFront->iterator->tail;
        return element;
    }

    exit(1);
}



static TList belongsGet(TList list, elemType elem){

    if (list == NULL){
        return NULL;
    }

    if (!compare(list->elem, elem)){
        TList aux = list->tail;
        free(list);
        return aux;
    }
    
    list->tail = belongsGet(list->tail, elem);

    return list;
} 




elemType * get(moveToFrontADT moveToFront, elemType elem){
    

    if (compare(moveToFront->last->elem, elem)){
        TList aux = belongsGet(moveToFront->first, elem);
        moveToFront->first->elem = elem;
        moveToFront->first->tail = aux; 
    }else{
        TList aux = malloc(sizeof(TNode));
        
        aux->elem = 
        moveToFront->first->elem = elem;
        moveToFront->first->tail = moveToFront->first; 
    }

} 


static TList getLast(TList list){

    if (list == NULL || list->tail == NULL)
        return NULL;

    if(list->tail->tail == NULL){
        last = list;
        free(list->tail);
    }

    return getLast(list->tail);

}

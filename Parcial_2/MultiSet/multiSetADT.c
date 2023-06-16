#include <stdlib.h>
#include <stdio.h>
#include "multiSetADT.h" 


typedef struct element{

    elemType value;
    size_t used;

}element;

typedef struct node * TList;

typedef struct node{

    element elem;
    struct node * tail;

}TNode;

typedef struct multiSetCDT{

    TList first;
    size_t count;
    size_t usedCount;
    

}multiSetCDT;


multiSetADT newMultiSet(void){
    
    return calloc(1, sizeof(multiSetCDT));
    
}

static TList addRec(TList list, elemType elem, size_t * count, size_t * flag){

    if (list == NULL || compare(list->elem.value, elem) > 0){
        TList new = calloc(1, sizeof(TNode));
        new->elem.value = elem;
        new->elem.used++;
        (*count) = new->elem.used;
        new->tail = list;
        return new;
    }
    
    if (!compare(list->elem.value, elem)){
        (*flag) = 1;
        list->elem.used++;
        (*count) = list->elem.used;
        return list;
    }

    list->tail = addRec(list->tail, elem, count, flag);
    return list;


}


unsigned int add(multiSetADT multiSet, elemType elem){

    size_t count;
    size_t flag = 0;

    multiSet->first = addRec(multiSet->first, elem, &count, &flag);
    multiSet->usedCount++;
    if (!flag){
        multiSet->count++;
    }

    return count;
}

static size_t countRec(TList list, elemType elem){

    if (list == NULL){
        return 0;
    }

    if (list->elem.used && !compare(list->elem.value, elem)){
        return list->elem.used;
    }

    return countRec(list->tail, elem);
}


unsigned int count (const multiSetADT multiSet, elemType elem){
    
   return countRec(multiSet->first, elem);

}

unsigned int size( const multiSetADT multiSet){
    return multiSet->count;
}




static TList removeOneRec(TList list, elemType elem, size_t * count, int * flag){

    if (list == NULL){
        return list;
    }

    if (!compare(list->elem.value, elem)){
        if (!list->elem.used){
            TList aux = list->tail;
            free(list);
            list = aux;
            (*flag) = 2;
        } else {
            list->elem.used--;
            if (list->elem.used == 0) {
                TList aux = list->tail;
                free(list);
                list = aux;
                (*flag) = 2;
            } else {
                (*flag) = 1;
            }
        }
        if (list != NULL) {
            (*count) = list->elem.used;
        }
    
        return list;
    }

    
    if (compare(list->elem.value, elem) < 0){
        list->tail = removeOneRec(list->tail, elem, count, flag);
    }
    
    return list;

}

int removeOne( multiSetADT multiSet, elemType elem ){

    size_t count = 0;

    int flag = 0;

    multiSet->first = removeOneRec(multiSet->first, elem, &count, &flag);

    if (!flag){
        multiSet->usedCount--;
    }else if (flag == 2){
        multiSet->count--;
    }

    return (int)count;
}


static TList removeAllRec(TList list, elemType elem, int * flag, int *removedCount){

    if (list == NULL){
        return NULL;
    }

    if (!compare(list->elem.value, elem)){
        *removedCount = list->elem.used;
        list->elem.used = 0;
        (*flag) = 1;
        TList aux = list->tail;
        free(list);
        list = aux;
        return list;
    }
    
    if (compare(list->elem.value, elem) < 0){
        list->tail = removeAllRec(list->tail, elem, flag, removedCount);
    }

    return list;

}


void removeAll( multiSetADT multiSet , elemType elem ){
    
    int flag = 0;
    int removedCount = 0;

    multiSet->first = removeAllRec(multiSet->first, elem, &flag, &removedCount);
    
     if (flag) {
        multiSet->count--;
        multiSet->usedCount -= removedCount;
    }

}


static elemType * minElemRec(TList list, int * dim, elemType * aux, int count){

    if (list == NULL){
        return aux;
    }
    
    if (list->elem.used < count || count == -1){
        count = list->elem.used;
        aux = malloc(sizeof(elemType));
        (*dim) = 1;
        aux[(*dim)-1] = list->elem.value;
    }else if (list->elem.used == count){
        (*dim)++;
        aux = realloc(aux, (*dim)*sizeof(elemType));
        aux[(*dim)-1] = list->elem.value;
    }

    return minElemRec(list->tail, dim, aux, count);

}

elemType * minElements( const multiSetADT multiSet , int *dim){

    elemType * aux = NULL;

    int count = -1;

    aux = minElemRec(multiSet->first, dim, aux, count);

    return aux;
    
}


void freeMultiSet(multiSetADT multiSet){

    TList actual = multiSet->first;
    TList next;

    while(actual != NULL){
        next = actual->tail;
        free(actual);
        actual = next;
    }

    free(multiSet);
}


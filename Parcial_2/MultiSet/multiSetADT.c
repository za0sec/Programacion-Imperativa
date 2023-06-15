#include <stdlib.h>
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
    if (!flag){
        multiSet->usedCount++;
    }else{
        multiSet->count++;
        multiSet->usedCount++;
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
            (*flag)=2;
        }

        list->elem.used--;
        if (*flag != 2)
            (*flag) = 1;
        
        (*count) = list->elem.used;
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

    if (flag == 1){
        multiSet->usedCount--;
    }else if (flag == 2){
        multiSet->count--;
    }
    return (int)count;
}


static TList removeAllRec(TList list, elemType elem, int * flag){

    if (list == NULL){
        return NULL;
    }

    if (!compare(list->elem.value, elem)){
        while(list->elem.used){
            list->elem.used--;
            (*flag) = 1;
        }
        list->elem.used--;
        TList aux = list->tail;
        free(list);
        list = aux;
        return list;
    }

    if (compare(list->elem.value, elem) < 0){
        list->tail = removeAllRec(list->tail, elem, flag);
    }

    return list;

}


void removeAll( multiSetADT multiSet , elemType elem ){
    
    int flag = 0;

    multiSet->first = removeAllRec(multiSet->first, elem, &flag);
    
    if (flag)
        multiSet->usedCount++;
}


static elemType * minElemRec(TList list, int * dim, elemType * aux, int count){

    if (list == NULL){
        return aux;
    }
    
    if (list->elem.used < count || count == -1){
        count = list->elem.used;
        aux = realloc(aux, sizeof(elemType));
        (*dim) = 1;
        aux[(*dim)-1] = list->elem.value;
    }

    if (list->elem.used == count){
        (*dim)++;
        aux = realloc(aux, (*dim)*sizeof(elemType));
        aux[(*dim)-1] = list->elem.value;
        return minElemRec(list->tail, dim, aux, count);
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


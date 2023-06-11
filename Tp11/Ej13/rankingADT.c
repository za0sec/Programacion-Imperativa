#include "rankingADT.h"
#include <stdlib.h>


#define CHUNK 10

#define SWAP(a, b)  {\
    elemType z = (a);\
    (a) = (b);\
    (b) = (z);\
}

typedef struct rankingCDT{

    elemType * vec;
    size_t dim; //Decirle dim a esto esta mal porque en realidad lo estoy llamando como la cantidad de elementos dentro del vector que no necesariamente es la dim.
    int (*compare)(elemType, elemType);


}rankingCDT;


rankingADT newRanking(elemType elems[], size_t dim, int (*compare)(elemType source, elemType target)){

    rankingADT rank = calloc(1, sizeof(rankingCDT));
    rank->compare = compare;
    if (dim > 0){
        size_t initialSize = dim + CHUNK - (dim % CHUNK);
        (rank->vec) = malloc(initialSize*sizeof(elemType));
        for (int i=0; i<dim; i++){
            (rank->vec)[i] = elems[i];
        }
        rank->dim = dim;
    }
    return rank;

}

void addRanking(rankingADT ranking, elemType elem){

    if (contains(ranking, elem)){
        return;
    }else{
        if ( !(ranking->dim%CHUNK) ){
            ranking->vec = realloc(ranking->vec, (ranking->dim + CHUNK) * sizeof(elemType) );
        }

        (ranking->vec)[(ranking->dim)] = elem;
        (ranking->dim)++;

    }


}

size_t size(const rankingADT ranking){
    return ranking->dim;
}


int getByRanking(rankingADT ranking, size_t n, elemType *elem)
{
    if (contains(ranking, *elem))
    {
        (*elem) = ranking->vec[n - 1];
        if (n > 1)                   
        {
            SWAP(ranking->vec[n - 1], ranking->vec[n - 2]);
        }
        return 1;
    }
    return 0;
}

elemType * getTopRanking(const rankingADT ranking, size_t * top){

    if (ranking == NULL){
        (*top) = 0;
        return NULL;
    }

    size_t maxSize = (*top) < ranking->dim ? (*top) : ranking->dim;
    elemType *ret = malloc(maxSize * sizeof(elemType));

    for (int i = 0; i < maxSize; i++)
    {
        ret[i] = ranking->vec[i];
    }

    return ret;
}


int contains(rankingADT ranking, elemType elem){    
    
    for (int i=0; i<ranking->dim; i++){
        if (!ranking->compare((ranking->vec)[i], elem)){
            if (i)
                SWAP((ranking->vec)[i], (ranking->vec)[i-1]);
           
            return 1;
        }
    }
    return 0;
}

void downByRanking(rankingADT ranking, size_t n){

    if (ranking == NULL || n >= ranking->dim)
        return;

    SWAP((ranking->vec)[n-1], (ranking->vec)[n]);

}

void freeRanking(rankingADT r){

    free(r->vec);
    free(r);
}

#include "./rankingADT.h"

#define CHUNK 10

#define SWAP(a, b) ( elemType z = (a); (a) = (b); (b) = (z); )

typedef struct rankingCDT{

    elemType * vec;
    size_t dim; //Decirle dim a esto esta mal porque en realidad lo estoy llamando como la cantidad de elementos dentro del vector que no necesariamente es la dim.
    int (*compare)(elemType, elemType);


}rankingCDT;


rankingADT newRanking(elemType elems[], size_t dim, int (*compare)(elemType source, elemType target)){

    rankingADT rank = calloc(1, sizeof(rankingCDT));
    rank->compare = compare;
    if (dim > 0){
        (rank->vec) = malloc(dim*sizeof(elemType));
        for (int i=0; i<dim; i++){
            (rank->vec)[i] = elems[i];
        }
        rank->dim = dim;
    }
    return rank;

}

static int belongs(elemType * vec, elemType elem, size_t dim, int (*compare)(elemType, elemType)){

    for (int i=0; i<dim; i++){
        if (!compare(vec[i], elem))
            return i;
    }
    return 0;

}

void addRanking(rankingADT ranking, elemType elem){

    int idx;

    if ( idx = belongs(rankning->vec, elem, ranking->dim, ranking->compare) && idx > 0){
        SWAP((ranking->vec)[idx], (ranking->vec)[idx-1]);
    }else{
        if ( !(dim%CHUNK) ){
            ranking->vec = realloc( (ranking->dim + CHUNK) * sizeof(elemType) );
        }

        (ranking->vec)[dim++] = elem;

    }


}

size_t size(const rankingADT ranking){
    return ranking->dim;
}


int getByRanking(rankingADT ranking, size_t n, elemType * elem){
    
    if (n < dim && n > 0){
        (*elem) = (ranking->vec)[n];
        SWAP((ranking->vec)[n], (ranking->vec)[n-1]);
        return 1;
    }
    
    
    
}


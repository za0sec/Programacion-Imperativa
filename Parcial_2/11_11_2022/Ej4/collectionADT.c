

typedef struct element{

    elemType elem;
    size_t used;

}element;

typedef struct collectionCDT{

    element * vec;
    size_t dim;
    int (*compare)(elemType, elemType);
    size_t countUsed;
    
}collectionCDT;


collectionADT newCollection( int (*compare)(elemType target, elemType source) ){

    collectionADT col = calloc(1, sizeof(collectionCDT));

    col->compare = compare; 

    return col;
}

void putElement(collectionADT c, elemType elem, size_t pos){

    if (c->vec == NULL){
        c->vec = malloc(pos * sizeof(element));
        c->dim = pos+1;
    }

    if (c->dim <= pos){
        c->vec = realloc(c->vec, pos * sizeof(element));
        c->dim = pos+1;
    }

    if (!(c->vec)[pos].used)
        c->countUsed++;
    
    (c->vec)[pos].elem = elem;
    (c->vec)[pos].used = 1;
}

int getPosition(collectionADT c, elemType elem){
    
    for(int i=0; i<c->dim; i++){
        if (!compare((c->vec)[i].elem, elem))
            return i+1;
    }
    return -1;

}

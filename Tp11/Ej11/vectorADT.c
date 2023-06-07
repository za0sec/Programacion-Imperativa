#include "vectorADT.h"
#include <stdlib.h>

#define CHUNK 10

typredef struct vectorCDT{

  elemType * vec;
  size_t dim;
  int (*compare)(elemType source, elemType target);

}vectorCDT;

vectorADT newVector(int (*compare)(elemType source, elemType target)){

  vectorADT newVec = malloc(sizeof(vectorCDT));

  newVec->vec = malloc(CHUNK * sizeof(elemType));
  
  newVec->dim = 0;

  newVec->compare = compare;

  return newVec;

}

void putRec(elemType * vec, elemType * elems, size_t dim, size_t index){
  
  if (!dim)

  
  
  
}



size_t put(vectorADT v, elemType * elems, size_t dim, size_t index){
  
  if ( !(v->dim) || !index){
    
    putRec(v->vec, elems, dim, index);
    return v->dim;
    
  }
    
  if ( dim == 0 ){
    return 0;
  }

  putRec(v->vec, elems, dim, index);
  return v->dim;

}


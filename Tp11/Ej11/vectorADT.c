#include "vectorADT.h"
#include <stdlib.h>

#define CHUNK 10

typedef struct vectorCDT{

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

static void putRec(elemType *vec, size_t dimVec, elemType *elems, size_t dim, size_t index, size_t * count, int (*compare)(elemType source, elemType target) ) {

    if (!dim) {
        return;
    }

    if ( index == dimVec ) {
        vec[index] = elems[(*count)];
        (*count)++;
        dimVec++;
    }

    putRec(vec, dimVec, elems, dim-1, index + 1, count, compare);
}

size_t put(vectorADT v, elemType *elems, size_t dim, size_t index) {

  size_t count = 0;

  if (index + dim > v->dim) {
    v->vec = realloc(v->vec, index + dim + CHUNK);
  }

  putRec(v->vec, v->dim, elems, dim, index, &count, v->compare);

  return count;

}

int getIdx(vectorADT v, elemType elem){

  int flag = -1;

  for(int i=0;  i<(v->dim) && flag == -1; i++){

    if ( !(v->compare)((v->vec)[i], elem) ){
      flag = i;
    }

  } 


  return flag;

}

void freeVector(vectorADT v){

  free(v->vec);
    
  free(v);

}

int elementCount(vectorADT v){
  return v->dim; 
}

void deleteElement(vectorADT v, size_t index){

  if (index < v->dim && index > 0){
    for (size_t i=index; i<(v->dim)-1; i++){
      (v->vec)[i] = (v->vec)[i+1];
    }
  }

}


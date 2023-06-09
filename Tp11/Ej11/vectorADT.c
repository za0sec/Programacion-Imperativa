#include "vectorADT.h"
#include <stdlib.h>

#define CHUNK 10


typedef struct element{
  elemType elem;
  int used;
}element;

typedef struct vectorCDT{

  element * vec;
  size_t dim;
  int (*cmp)(elemType, elemType);
  size_t count;

}vectorCDT;

vectorADT newVector(int (*compare)(elemType source, elemType target)){

  vectorADT newVec = calloc(1, sizeof(vectorCDT));

  newVec->cmp = compare;

  return newVec;

}


static void putRec(element *vec, elemType *elems, size_t dim, size_t index, size_t * added, size_t * count){

    if (!dim) {
        return;
    }

    if (!(vec[index].used)) {
      vec[index].elem = elems[(*added)];
      vec[index].used = 1;
      (*added)++;
      (*count)++;
    }
  
  putRec(vec, elems, dim-1, index + 1, added, count);

}

size_t put(vectorADT v, elemType *elems, size_t dim, size_t index) {

  size_t added = 0;

  if (index + dim > v->dim) {
    v->vec = realloc(v->vec, (index + dim + CHUNK) * sizeof(element));
  
    for (size_t i = v->dim; i < index + dim + CHUNK; i++) {
      v->vec[i].used = 0;
    } 

    v->dim = index + dim + CHUNK;
  }

  putRec(v->vec, elems, dim, index, &added, &(v->count));

  return added;

}

int getIdx(vectorADT v, elemType elem){

  int flag = -1;

  for(size_t i=0;  i<(v->dim); i++){
    if ((v->vec)[i].used && !(v->cmp)((v->vec)[i].elem, elem)){
      return i;
    }
}  


  return flag;

}

void freeVector(vectorADT v){

  free(v->vec);
    
  free(v);

}

int elementCount(vectorADT v){
  return v->count; 
}


void deleteElement(vectorADT v, size_t index){
  if (index < v->dim && index >= 0 && v->vec[index].used){
    v->vec[index].used = 0;
    (v->count)--;
  }
}


#include "vectorADT.h"
#include <stdlib.h>

#define CHUNK 10

<<<<<<< HEAD
typedef struct vectorCDT{
=======
>>>>>>> eb72f3e (Ej11 TERMINADO)

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

<<<<<<< HEAD
static void putRec(elemType *vec, size_t dimVec, elemType *elems, size_t dim, size_t index, size_t * count, int (*compare)(elemType source, elemType target) ) {
=======
static void putRec(element *vec, elemType *elems, size_t dim, size_t index, size_t * added, size_t * count){
>>>>>>> eb72f3e (Ej11 TERMINADO)

    if (!dim) {
        return;
    }
<<<<<<< HEAD

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
=======

    if (!(vec[index].used)) {
      vec[index].elem = elems[(*added)];
      vec[index].used = 1;
      (*added)++;
      (*count)++;
    }
    
  putRec(vec, elems, dim-1, index + 1, added, count);
>>>>>>> eb72f3e (Ej11 TERMINADO)

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

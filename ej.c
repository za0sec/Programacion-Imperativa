#include <stdio.h>
#include "./libreria/getnum.h"
#define DIM 50

int readArray(float v[], unsigned int max){

  int n = 0;
  float aux;

  while ( ((n<max && (aux = getfloat("Decime un numero hasta que uno sea negativo: ")) >= 0))){
     v[n++] = aux;
  }
  return n;
}

int main(){



  float v[DIM];


  printf("%d", readArray(v, DIM));


}

#include <stdio.h>
#include "../../libreria/random.h"

void shuffle(int vec[], unsigned int dim);

int main(){

  randomize();
  int vec[] = {1,3,4,5,7,8,12};
  int dim = sizeof(vec)/sizeof(vec[0]);

    shuffle(vec, dim);

}

void shuffle(int vec[], unsigned int dim){

  int i;

  for ( i = 0; i<dim; i++ ){

    int a = randInt(0,dim-1);

    int t = vec[i];

    vec[i] = vec[a];
    vec[a] = t;


  }

    for ( i=0; i<dim; i++ )
      printf("%d,", vec[i]);

}

#include <stdio.h>
#include "../../libreria/random.h"

int randArray(int ){

  int i, t, g;

  for ( i=0; i<dimA; i++ ){

  t = randInt(0, dimA-1);

      g = v[i];

    v[i] = v[t];
    v[t] = g;
    
  }

}


int main(){

  randomize();

  int v[] = {3,5,7,9,15};
  int dimA = 5;

  

  for ( i=0; i<dimA; i++ ){
    printf("%d,", v[i]);
  }

}

#include <stdio.h>

int eliminaRepetidos(const int vec[], unsigned int dim, int vec2[]);

int main(){

  int vec[] = {1,2,2,3,4,5,5,5,7,8,8,9,12,12,12,12,12,34,56,56,67,67,67,89}; //22
  int dim = sizeof(vec)/sizeof(vec[0]);
  int vec2[dim];

  printf("%d", eliminaRepetidos(vec, dim, vec2));

}

int eliminaRepetidos(const int vec[], unsigned int dim, int vec2[]){

  int j = 0;

  for ( int i = 0; i<dim; i++ ){

    if ( vec[i] != vec[i+1] ){

      vec2[j++] = vec[i];

    }


  }

  return j;


}

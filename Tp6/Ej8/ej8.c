/*
 *Repetir el ejercicio anterior, teniendo en cuenta que los arreglos de entrada
 *pueden tener elementos repetidos, pero el de salida NO debe tener repeticiones. 
*/

#include <stdio.h>


int merge(const int vec[], unsigned int dim, const int vec1[], unsigned int dim1, int vec2[]);


int main(){

  int vec[] = {1,2,3,7,5,8,9,4};
  int dim = sizeof(vec)/sizeof(vec[0]);
  int vec1[] = {4,3,6,2,1,7};
  int dim1 = sizeof(vec1)/sizeof(vec1[0]);

  int vec2[dim > dim1 ? dim : dim1];

  int j = merge(vec, dim, vec1, dim1, vec2);

  for ( int i = 0; i<j; i++ )
    printf("%d,", vec2[i]);

}


int merge(const int vec[], unsigned int dim, const int vec1[], unsigned int dim1, int vec2[]){

  int j = 0;

  for ( int i = 0; i<dim; i++ ){

    int cont = 0;

    for ( int k=0; k<dim1; k++ ){

      if ( vec[i] == vec1[k] )
        cont++;

    }

    if ( cont == 1 )
      vec2[j++] = vec[i];
      

  }


  return j;

}

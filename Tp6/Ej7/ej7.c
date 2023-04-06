/*Hacer una función que reciba dos parámetros de entrada representando arreglos de números enteros positivos,
 *ordenados en forma ascendente y sin elementos repetidos. El último elemento de cada arreglo es -1. 
 La función debe devolver en un tercer parámetro de salida un arreglo ordenado con la unión de los dos primeros, también terminado en -1.

	Ejemplo: Dados v1 y v2 arreglos de enteros, se espera que la unión sea:
		v1 = {1,2,3,-1} y v2 = {2,3,4,-1}  →  unión = {1,2,3,4,-1}.
		v1 = {1,2,3,-1} y v2 = {1,2,3,-1}  →  unión = {1,2,3,-1}.
 */
#include <stdio.h>


int merge(const int vec[], unsigned int dim, const int vec1[], int vec2[]);


int main(){

  int vec[] = {1,2,3,7,8,9,-1};
  int dim = sizeof(vec)/sizeof(vec[0]);
  int vec1[] = {2,4,6,7,8,-1};
  int dim = sizeof(vec1)/sizeof(vec1[0]);
  int vec2[dim];

  int j = merge(vec, dim, vec1, vec2);

  for ( int i = 0; i<j; i++ )
    printf("%d,", vec2[i]);

}


int merge(const int vec[], unsigned int dim, const int vec1[], int vec2[]){

  int j = 0;

  dim = 

  for ( int i = 0, k = 0; vec1[k] > 0; i++ ){

    if ( vec[i] == vec1[k] ){

      vec2[j++] = vec[i];
      k++;

    }else if ( vec[i] > vec1[k] ){

      k++;
      i--;
    }


  }


  return j;

}

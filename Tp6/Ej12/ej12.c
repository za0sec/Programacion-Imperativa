/*Escribir una función que cambie una matriz cuadrada por su traspuesta, recibiendo sólo los siguientes 2 parámetros:
la matriz cuadrada 
un número entero positivo que indique la dimensión de la matriz
 	Dicha función debe hacer la conversión sobre la misma matriz recibida, sin usar vectores auxiliares.
*/

#include <stdio.h>
#include "../../libreria/random.h"
#define DIM 5


void transpose(int mat[][DIM], size_t dim);

void generateMat(int mat[][DIM], size_t dim);

void printMat(int mat[][DIM], size_t dim);

int main(void){

  randomize();

  int dim = 5;
  int mat[dim][dim];

  generateMat(mat, dim);
  
  printMat(mat, dim);

  transpose(mat, dim);

  puts("\nSu matriz traspuesta es: ");

  printMat(mat, dim);


}

void transpose(int mat[][DIM], size_t dim){

  int temp;

  for ( int i=0; i<dim; i++ ){

    for ( int j=i+1; j<dim; j++ ){


      temp = mat[i][j];
      mat[i][j] = mat[j][i];
      mat[j][i] = temp;

    }

  }



}


void generateMat(int mat[][DIM], size_t dim){


  for (int i=0; i<dim; i++){

    for (int j=0; j<dim; j++){

      mat[i][j] = randInt(0,40);

    }

  }

}

void printMat(int mat[][DIM], size_t dim){

  puts(" ");

  for (int i=0; i<dim; i++){

    for (int j=0; j<dim; j++){

      printf("%d\t", mat[i][j]);
    }

    puts(" ");

  }



}

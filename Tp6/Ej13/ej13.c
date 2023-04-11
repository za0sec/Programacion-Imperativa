#include <stdio.h>
#include "../../libreria/random.h"
#define DIM 5


void generateMat(int mat[][DIM], size_t dim);

void printMat(int mat[][DIM], size_t dim);

void multMat(int mat1[][DIM], int mat2[][DIM], int mat3[][DIM], size_t dim);

int suMat(int mat1[][DIM], int mat2[][DIM], size_t dim, size_t fil, size_t col);



int main(){
  
  randomize();

  int dim = 5;
  int mat1[dim][dim];
  int mat2[dim][dim];
  int mat3[dim][dim];

  puts("\nMatriz N1: ");

  generateMat(mat1, dim);
  printMat(mat1, dim);

  puts("\nMatriz N2: ");

  generateMat(mat2, dim);
  printMat(mat2, dim);

  puts("\nMat1 x Mat2 =  "); 

  multMat(mat1, mat2, mat3, dim);

  printMat(mat3, dim);

}


int suMat(int mat1[][DIM], int mat2[][DIM], size_t dim, size_t fil, size_t col){

  int num = 0;

  for ( int i=0; i<dim; i++ ){

    num += mat1[fil][i] * mat2[i][col];

  }

  return num;

}



void multMat(int mat1[][DIM], int mat2[][DIM], int mat3[][DIM], size_t dim){


  for (int i=0; i<dim; i++){

    for (int j=0; j<dim; j++){

      mat3[i][j] = suMat(mat1, mat2, dim, i, j);

    }

  }

}


void printMat(int mat[][DIM], size_t dim){

  puts(" ");

  for( int i=0; i<dim; i++ ){

    for( int j=0; j<dim; j++){

      printf("%d\t",mat[i][j]);

    }

    puts(" ");

  }



}

void generateMat(int mat[][DIM], size_t dim){

  
  for( int i=0; i<dim; i++ ){

    for( int j=0; j<dim; j++){

      mat[i][j] = randInt(0,10);

    }

  }



}


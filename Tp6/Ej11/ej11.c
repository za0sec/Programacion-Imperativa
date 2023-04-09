/*Escribir una función que ordene las filas de una matriz de cualquier tamaño, 
 *según el valor de una determinada columna. La función recibirá como parámetros la matriz, 
 *la cantidad de filas, la cantidad de columnas y el número de columna a tomar como clave de ordenación, 
 *teniendo en cuenta que la primera columna es la columna 1 (uno).
*/

#include <stdio.h>
#include "../../libreria/random.h"
#include "../../libreria/getnum.h"
#define COL 5
#define FIL 5

void order(int mat[][COL], size_t fil, size_t col, size_t numCol);

void printMat(int mat[][COL], size_t fil, size_t col);

void swap(int mat[][COL], size_t fil1, size_t fil2, size_t col);

void generateMat(int mat[][COL], size_t fil, size_t col);



int main(){

  randomize();

  int mat[FIL][COL];
  int fil = FIL;
  int col = COL;

  generateMat(mat, fil, col);
  
  puts("Su matriz generada aleatoriamente es la siguiente: ");

  printMat(mat, fil, col);

  order(mat, fil, col, getint("Columna a ordenar de menor a mayor: "));
  
  printMat(mat, fil, col);

}




void generateMat(int mat[][COL], size_t fil, size_t col){

  for( int i=0; i<fil; i++ ){

    for( int j=0; j<col; j++ ){

      mat[i][j] = randInt(0,50);

    }

  }

}

void order(int mat[][COL], size_t fil, size_t col, size_t numCol){

  int j = numCol -1;
  int save = 0;

  for( int i=0; i<fil; i++  ){


    save = i;

    for ( int k=(i+1); k<fil; k++ ){

      if( mat[save][j] > mat[k][j] ){

      save = k;

      }

    }
    
    swap(mat, i, save, col);
  
  }

}


void swap(int mat[][COL], size_t fil1, size_t fil2, size_t col){


  for( int i=0; i<col; i++ ){

    int temp = mat[fil1][i];
    mat[fil1][i] = mat[fil2][i];
    mat[fil2][i] = temp;


  }


}

void printMat(int mat[][COL], size_t fil, size_t col){

  puts(" ");

  for(int i=0; i<fil; i++){

    for(int j=0; j<col; j++){

      printf("%d\t", mat[i][j]);

    }
  
    puts(" ");

  }


}

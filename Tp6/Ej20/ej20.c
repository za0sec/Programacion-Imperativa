#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define DIM 9
#define SIMPLENUM(num) ( (num) >= 1 && (num)<=9 )



int isSolution(int mat[][DIM]);

bool isSquare(int mat[][DIM]); //Vector auxiliar.

bool isSubSquare(int mat[][DIM], int t, int k);

bool isRowCol(int mat[][DIM]);


int main(void) {
  // Una matriz vacía no es solución
  int sudoku[DIM][DIM] = {{0}};

  assert(isSolution(sudoku)==0);

  int sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(isSolution(sudoku2)==1);
  
  int sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(isSolution(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  int sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };

  assert(isSolution(sudoku4)==0);

  int sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(isSolution(sudoku5)==0);

  puts("OK");

  return 0;
}

int isSolution(int mat[][DIM]){

    if ( isSquare(mat) ){
      if ( isRowCol(mat) ){
        return 1;
      }else{
        return 0;
      }
    }else{
      return 0;
    }
}
  

bool isSquare(int mat[][DIM]){

  for (int i=0; i<=DIM-3; i+=3){
    for (int j=0; j<=DIM-3; j+=3){
      if (!isSubSquare(mat, i, j) )
        return false; 
    }
  }
  return true;
}

bool isSubSquare(int mat[][DIM], int t, int k){

  int vec[9] = {0};

  for(int i = t; i<t+3; i++){
    for (int j = k; j<k+3; j++ ){
      int elem = mat[i][j];

      if ( SIMPLENUM(elem) && vec[elem-1] != elem ) {
        vec[elem-1] = elem;
      }else{
        return false;
      }
    }
  }
  return true;
}

bool isRowCol(int mat[][DIM]){

  for (int i=0; i<DIM; i++){
    int vec1[9] = {0};
    int vec2[9] = {0};

    for (int j=0; j<DIM; j++){
      int elem1 = mat[i][j];
      int elem2 = mat[j][i]; 
     if ( vec1[elem1-1] != elem1 && vec2[elem2-1] != elem2) {
        vec1[elem1-1] = elem1;
        vec2[elem2-1] = elem2;
      }else{
        return false;
      }    
    }
  }
  return true;
}


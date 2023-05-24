//Escribir una función que reciba cuatro parámetros: 
//Matrix:  parámetro de entrada-salida que representa una matriz cuadrada booleana 
//Dim: parámetro de entrada de tipo entero que representa la dimensión de la matriz 
//Fila: parámetro de entrada de tipo entero que representa un número de fila de la matriz
//Columna: parámetro de entrada de tipo entero que representa un número de columna de la matriz
//
// 	La función se encargará de devolver dicha matriz cambiada de la siguiente forma:  el elemento de la fila y columna indicada y todos los de las dos diagonales que pasen por él se reemplazarán por su negación booleana, los demás elementos de la matriz quedan igual .
//   	
//Esta función deberá ser recursiva o deberá invocar a otra función auxiliar recursiva para realizar lo pedido.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 10

void reemplazo(int matriz[][MAX], int dim, int row, int col);

void reemplazo_aux(int matriz[][MAX], int dim, int row, int col , int nRow, int nCol);

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}

void reemplazo(int matriz[][MAX], int dim, int row, int col){

  matriz[row][col] = !matriz[row][col];

  int mod[2] = {-1, 1};

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
        reemplazo_aux(matriz, dim, row, col, mod[i], mod[j]);
    }
  }
}


void reemplazo_aux(int matriz[][MAX], int dim, int row, int col, int nRow, int nCol){

  if (col < 0 || row < 0 || col == dim || row == dim)
    return;

  reemplazo_aux(matriz, dim, row + nRow, col + nCol, nRow, nCol);

   matriz[row][col] = !matriz[row][col];


}

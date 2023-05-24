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

#define MAX 10

void reemplazo(int matriz[][MAX], int dim, int fil, int col);

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

void reemplazo(int matriz[][MAX], int dim, int fil, int col){

  


}


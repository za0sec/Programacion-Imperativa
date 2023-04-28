/*Escribir una función que, dada una matriz de N filas y N columnas determine si es un “cuadrado
mágico”.
Una matriz es cuadrado mágico cuando:
● es cuadrada (NxN) (donde N es una constante simbólica)
● tiene todos los números del 1 al N2
● la suma de los elementos de cualquier fila es igual a la suma de los elementos de cualquier
columna*/

#include <stdio.h>
#include <assert.h>

#define MAGIC 1
#define NOT_MAGIC 0

#define N 4

#define BETWEN(a) ((a)>0 && (a)<=((N)*(N)) )


int check(int f, int c, int vecAp[], int sumFil, int sumCol, int modelo, int i);

int isMagic(const int mat[][N]);

int main(){


  const int m1[N][N] = {
      {16, 4, 5, 10},
      {5, 10, 11, 8},
      {9, 6, 7, 12},
      {4, 15, 14, 1}
  };

  assert(isMagic(m1) == 0);

  const int m2[N][N] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
  };

  assert(isMagic(m2) == 1);

  puts("OK!");




}




int isMagic(const int mat[][N]){

  int vecAp[N*N] = {0};
  int sumFil, sumCol, modelo=0; 

  for (int i=0; i<N; i++){

    sumFil=0;
    sumCol=0;

    for (int j=0; j<N ; j++){

      int f = mat[i][j];
      int c =mat[j][i];

      if(!check(f, c, vecAp, sumFil, sumCol, modelo, i))
        return NOT_MAGIC;


    }
    
    if (modelo != sumFil || modelo != sumCol)
      return NOT_MAGIC;

  }

  return MAGIC;

}

int check(int f, int c, int vecAp[], int * sumFil, int * sumCol, int modelo, int i){


  if ( BETWEN(f) ){
    
    if (!vecAp[f-1]){
      vecAp[f-1] = 1;
    }else{
      return NOT_MAGIC;
    }
    if (i==0)
      modelo += f;

    sumFil += f;
    sumCol += c;


  }else{
    return NOT_MAGIC;
  }

  return MAGIC;

}

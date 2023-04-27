#include <stdio.h>
#include <assert.h>
#define COL 4

int isScal(const int mat[][COL], size_t fil);



int main(){

  int fil = 4;

 const int m1[][COL] = {{1,1,1,1},
                         {1,2,1,1},
                         {1,1,2,2},
                         {1,1,2,3}};

  assert(isScal(m1, fil) == 1);
  
  const int m2[][COL] = {{1,1,1,1},
                         {1,2,1,1},
                         {1,1,5,2},
                         {1,1,2,3}};

  assert(isScal(m2, fil) == 0);

  const int m3[][COL] = {{7,1,1,1},
                         {1,8,1,1},
                         {1,1,9,1},
                         {1,1,1,10}};

  assert(isScal(m3, fil) == 1);

  puts("OK!");
}

int isScal(const int mat[][COL], size_t fil){


  int Col0=0, Fil0=0, sumCol, sumFil;

  for (int i=0; i<fil; i++){

    sumCol=0;
    sumFil=0;

    for (int j=0; j<COL; j++){

      int col = mat[j][i];
      int fila = mat[i][j];

      if (!i){
        Col0+=mat[j][i];
        Fil0+=mat[i][j];
      }else{
        sumFil += fila;
        sumCol += col;
      }



    }

    if (i && !(sumFil == (Fil0+i) && sumCol == (Col0+i)) )
      return 0;

  }


  return 1;



}


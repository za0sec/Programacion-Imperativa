#include <stdio.h>
//#include "../../libreria/random.h"
#include <assert.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define ANCHO 5
#define ALTO 6

void suavizar(unsigned char mat[ALTO][ANCHO], int w);

int sumSuav(unsigned char mat[ALTO][ANCHO], int fil, int col, int w);

void printMat(int mat[][ANCHO]);

void generateMat(int mat[][ANCHO]);

void copyMat(unsigned char mat2[ALTO][ANCHO], unsigned char mat[ALTO][ANCHO]);



int equals(unsigned int cols, unsigned char m1[][cols], unsigned char m2[][cols], unsigned int rows) {
  for (int i=0; i < rows; i++) {
     for(int j=0; j < cols; j++) {
         if ( m1[i][j] != m2[i][j]) {
            return 0;
         }
     }
  }
  return 1;  
}

int main(void) {
  unsigned char bmp[ALTO][ANCHO] =    {
      {10,10,20,23,24},
      {10,12,18,25,23},
      {12,14,18,26,22},
      {12,14,19,20,22},
      {13,16,19,20,22},
      {14,14,19,21,23}};
 
  
  suavizar(bmp, 3);
  unsigned char suave[ALTO][ANCHO] =    {
      {10,13,18,22,23},
      {11,13,18,22,23},
      {12,14,18,21,23},
      {13,15,18,20,22},
      {13,15,18,20,21},
      {14,15,18,20,21}};

  assert(equals(ANCHO, bmp, suave, ALTO));

  // Ahora una con w=5
  unsigned char suave5[ALTO][ANCHO] =    {
	{14,16,17,19,20},
	{14,16,17,18,20},
	{14,16,17,18,20},
	{15,16,17,18,20},
	{15,16,17,18,20},
	{15,16,17,18,19}};

   suavizar(bmp, 5);
   assert(equals(ANCHO, bmp, suave5, ALTO));

  puts("OK!");
  return 0;
}


void copyMat(unsigned char mat2[ALTO][ANCHO], unsigned char mat[ALTO][ANCHO]){


  for (int i = 0; i<ALTO; i++){

    for (int j=0; j<ANCHO; j++){

      mat2[i][j] = mat[i][j];

    }

  }

}


void suavizar(unsigned char mat[][ANCHO], int w){

  unsigned char mat2[ALTO][ANCHO];
  copyMat(mat2, mat);

  if ( w >= 3 && (w%2) ==1 ){

    for ( int i=0; i<ALTO; i++ ){

      for ( int j=0; j<ANCHO; j++ ){


       mat[i][j] = sumSuav(mat2, i, j, w);

      }

    }

  }

}

int sumSuav(unsigned char mat[][ANCHO], int fil, int col, int w){
  
  int nW = (w-1)/2;

  int nF = MAX(0,fil-nW);
  int nC = MAX(0,col-nW);


  int num = 0, cont = 0;
  int lim1 = MIN(ALTO-1,fil+nW);
  int lim2 = MIN(ANCHO-1,col+nW);


  for ( int i=nF; i<=lim1; i++ ){

    for ( int j=nC; j<=lim2; j++ ){

      num += mat[i][j];
      cont++;
    }

  }

  return (num/cont);
}

#include <stdio.h>
//#include "../../libreria/random.h"
#include <assert.h>
#define ANCHO 5
#define ALTO 6

void suavizar(unsigned char mat[ALTO][ANCHO], size_t w);

int sumSuav(unsigned char mat[ALTO][ANCHO], size_t fil, size_t col, size_t w);

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


void suavizar(unsigned char mat[][ANCHO], size_t w){

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

int sumSuav(unsigned char mat[][ANCHO], size_t fil, size_t col, size_t w){
  
  int nF = fil-((w-1)/2);
  int nC = col-((w-1)/2);

  while (nF < 0){
    nF++;
  }
  while (nC < 0){
    nC++; 
  }

  int num = 0, cont = 0;
  int lim1 = fil+((w-1)/2); //8
  int lim2 = col+((w-1)/2); //8

  while (lim1 >= ALTO){

    lim1--;

  }
  while (lim2 >= ANCHO){

    lim2--;

  }


  for ( int i=nF; i<=lim1; i++ ){

    for ( int j=nC; j<=lim2; j++ ){

      num += mat[i][j];
      cont++;
    }

  }

  return (num/cont);
}

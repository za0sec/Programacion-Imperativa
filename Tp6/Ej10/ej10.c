
#include <stdio.h>
#include "../../libreria/random.h"
#define FILAS 10
#define COLUMNAS 30

void graficar(int matBi[][COLUMNAS], int i, int j );
int sumIntensity(int matBi[][COLUMNAS], int i, int j);

int
main (void) {
	int cielo1[FILAS][COLUMNAS] = {{0}};

	puts("A continuación debe mostrar 8 filas en blanco");

	graficar(cielo1, FILAS, COLUMNAS);
	puts("-----------------------------");

	
	int cielo2[FILAS][COLUMNAS] = {
		{10, 17, 6, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 11, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 13, 11, 3, 9, 20},
		{18, 17, 6, 5, 6, 7, 8, 9, 11, 12, 13, 5, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 13, 11, 3, 9, 20},
		{10, 15, 16, 15, 6, 17, 8, 19, 11, 12, 13, 1, 8, 10, 11, 1, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{12, 2, 6, 5, 16, 7, 8, 9, 1, 12, 13, 15, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{8, 5, 4, 15, 6, 7, 8, 9, 12, 12, 13, 5, 8, 10, 11, 13, 14, 15, 18, 20, 11, 8, 12, 3, 12, 23, 11, 3, 9, 20},
		{20, 19, 18, 15, 16, 7, 8, 9, 11, 12, 13, 15, 18, 10, 11, 13, 14, 15, 18, 20, 11, 8, 12, 3, 12, 23, 11, 3, 9, 20},
		{10, 9, 9, 15, 16, 7, 8, 9, 12, 12, 13, 11, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 13, 12, 23, 11, 3, 9, 20},
		{10, 12, 9, 6, 16, 7, 8, 9, 15, 12, 13, 15, 18, 10, 11, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{10, 7, 9, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 1, 10, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{10, 17, 16, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 11, 3, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
	};

	puts("A continuación su función debe mostrar esto:");
	puts(" **     **      *****    *");
 	puts(" *              *****   ***");
	puts("         *      *****   ***");
	puts("   *     ****  ******   ***");
	puts(" ****    ***   ******   ***");
	puts(" ****   *****  ******   ***");
	puts("   *    *****   *****   ***");
	puts(" **     *****   *****   ***");

	puts("-----------------------------");
	puts("Y muestra esto:");
	graficar(cielo2, FILAS, COLUMNAS);
	puts("-----------------------------");

	return 0;
}
void graficar(int matBi[][COLUMNAS], int fil, int col ){
  
  int sum;

    for ( int i = 1; i<fil-1; i++ ){

      for ( int j = 1; j<col-1; j++ ){

        sum = (matBi[i][j] + sumIntensity(matBi, i, j))/9;

        if ( sum > 10.0 ){
 
            printf("*");

        }else{

           printf(" ");

        }

        }

    puts(" ");

  }

}  
  

int sumIntensity(int matBi[][COLUMNAS], int i, int j){

  int sum;

    sum = matBi[i-1][j-1] + matBi[i+1][j+1] + matBi[i-1][j+1] + matBi[i+1][j-1] + matBi[i][j-1] + matBi[i-1][j] + matBi[i+1][j] + matBi[i][j+1]; 

  return sum;


}

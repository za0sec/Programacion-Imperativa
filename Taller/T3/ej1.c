#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int suma =0;
  int num = getint("Dame un numero:");
  
  while ( num != 0 ){

    suma += (num % 10);
    num = num/10;

  }
  printf("la suma de sus cifras es igual a %d\n", suma);
  return 0;
}


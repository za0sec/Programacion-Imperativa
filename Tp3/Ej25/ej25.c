#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int resto, i, uno = 0, numDado = getint("Dame un numero entero y positivo: ");

  for ( i=1; numDado>=1; i++ ){

    resto = numDado%2;

    if ( resto == 1 ){
      
      uno++;
    }

    numDado /= 2;
  }

  printf("%d", uno);


}




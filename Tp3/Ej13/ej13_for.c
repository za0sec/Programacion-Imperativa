#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int p=0, i, a = getint("Decime el tamano del cuadrado: "); 

  for ( i=1; i<=a; i++ ){
    
    printf("*");
    
    if ( i==a ){

      puts(" ");
      i = 0;
      p++;
    }

    if ( p == a ){

      break;

    }

  }

}

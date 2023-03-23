#include <stdio.h>
#include "../../libreria/getnum.h"
int main() {
  int i, cero=0, uno=0, digito, var, binario = 1, numDecimal = getint("Dame un numero decimal: "); 
    while (numDecimal>=1){
      digito = numDecimal % 2;
   
      if ( digito == 0 ){
        
        binario *=10; 

    } else if ( var == 1 && binario != 1 ) {

      binario += 1;

    }else if ( digito == 1 ){
      
      binario += 1;
      binario *= 10;

    }
      var = digito;
      numDecimal /= 2;


    }

  //binario = 110
  //numDecimal = 1;
  //var = 1









    printf("\nEl equivalente binario es: %d\n", binario);
    return 0;
}

//digito = 0
//binario = 1
//cero = 1
//uno = 0
//numDecimal = 3


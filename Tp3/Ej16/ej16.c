#include <stdio.h>
#include "../../libreria/getnum.h"
int main() {
  int i, cero=0, uno=0, digito, var, binario = 0, numDecimal = getint("Dame un numero decimal: "); 
    while (numDecimal>=1){
      digito = numDecimal % 2;
      (digito == 1) ? ((binario = (binario+1)), uno++) : ((binario*=10), cero++);
      if ( ((binario%10) == 1) && (numDecimal != 1) ){
        binario*=10;
      }
      if ( ((var == 0) && ( digito == 1 )) || ((var == 0) && ( digito == 0 ))  ){
        binario *=10;
      }
      var = digito;
      numDecimal /= 2;
     printf("%d,", digito);
    }
  // if ( uno == 1 ){
    //   for ( i=1; i<=cero; i++ ){
      //    binario *= 10; 
       // }
     // }
    printf("\nEl equivalente binario es: %d\n", binario);
    return 0;
}

//digito = 0
//binario = 1
//cero = 1
//uno = 0
//numDecimal = 3


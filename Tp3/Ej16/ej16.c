#include <stdio.h>
#include "../../libreria/getnum.h"

int main() {

  int numDecimal = getint("Dame un numero decimal: ");
  int binario = 0, digito, base = 1;
    
  while (numDecimal > 0) {
    digito = numDecimal % 2;
    binario += digito * base;
    numDecimal /= 2;
    base *= 10;
    }
  printf("\nEl equivalente binario es: %d\n", binario);
  return 0;
}

//digito = 0
//binario = 1
//cero = 1
//uno = 0
//numDecimal = 3


#include <stdio.h>
#include "../../libreria/getnum.h"

int main() {
  int i, digito, decimal = 0, numBinario = getint("Dame un numero binario: ");

    for (i=1; numBinario > 0; i*=2) {
      digito = numBinario % 10;
      if ((digito == 1) || (digito == 0)){
        decimal += digito * i;
        numBinario /= 10;
      }else {
        numBinario = getint("Ese no es un numero binario\nDame un numero binario: ");
      }
    }
    printf("El equivalente decimal es: %d\n", decimal);
    return 0;
}


#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int varGuardada = 1, i, numPedido = getint("Ingrese un numero: ");
  if ( numPedido < 0 ){
    numPedido = getint("No se admiten numeros negativos\nPor favor ingrese otro numero (entero y positivo): ");
  }

  for ( i=1; i<=numPedido; i++ ){
    varGuardada *= i;
  }
  printf("El factorial de %d es %d\n", numPedido, varGuardada);
}

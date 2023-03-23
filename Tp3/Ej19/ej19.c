#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){
  int var, numPedido, cont = 0; 
  numPedido = getint("Ingrese un numero entero: ");
  while ( numPedido >= 1  ){       
    var = numPedido % 10;
    if ( var == 5 ){
      cont++;
    }
    numPedido /= 10;
  }
  printf("El numero ingresado tiene %d digitos que son numeros 5\n", cont);
}

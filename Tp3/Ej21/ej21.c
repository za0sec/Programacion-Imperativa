#include <stdio.h> 
#include "../../libreria/getnum.h"

int main (){
  
  //Guardo en una variable el numero pedido para asi despues poder modificarlo y que no haya problemas.
  int numReves = 0, numPedido = getint("Dame un numero: "), numPedido2 = numPedido;
  
  //Doy vuelta el numero y me fijo cuantos digitos tiene.
  while ( numPedido != 0 ){
    numReves *= 10;
    numReves += (numPedido % 10);
    numPedido /= 10;
  }
  
  numPedido = numPedido2;

  //Me fijo si el numero normal y el que esta dado vuelta si son iguales y si lo son, el numero es capicua.
  printf("%d%s es capicua\n", numPedido, numPedido == numReves ? "" : " no");


  return 0;

}

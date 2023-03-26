#include <stdio.h> 
#include "../../libreria/getnum.h"

int main (){
  
  //Guardo en una variable el numero pedido para asi despues poder modificarlo y que no haya problemas.
  int comp = 0, i, numReves = 0, cant = 0, numPedido = getint("Dame un numero: "), numPedido2 = numPedido;
  
  //Doy vuelta el numero y me fijo cuantos digitos tiene.
  while ( numPedido != 0 ){
    numReves = (numReves+numPedido %10)*10;
    numPedido /= 10;
    cant++;
  }
  

  numReves /= 10;
  
  numPedido = numPedido2;

  //Me fijo digito por digito en el numero normal y en el que esta dado vuelta si son iguales y si lo son le agrego 1 al contador
  for ( i=1; i<=cant; i++ ){
    numPedido2%10 == numReves%10 ? comp++ : printf(" ");
  }

  //Comparo ambos contadores para ver si son iguales, si lo son, el numero es capicua.
  comp == cant ?  printf("%d es capicua\n", numPedido) : printf("%d no es capicua\n", numPedido);

  return 0;

}

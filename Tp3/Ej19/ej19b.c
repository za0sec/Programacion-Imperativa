#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){
  int var, cont = 0; 
  double numPedido = getdouble("Ingrese un numero entero: ");
  printf("%f", numPedido*10);
  //  while ( numPedido >= 1  ){       
//    var = numPedido % 10;

//    if ( var == 5 ){
 //     cont++;
  //  }
  //  numPedido /= 10;
 // }
  printf("El numero ingresado tiene %d digitos que son numeros 5\n", cont);
}

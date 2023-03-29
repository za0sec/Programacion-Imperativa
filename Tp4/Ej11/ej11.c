#include <stdio.h>
#include "../../libreria/getnum.h"

int mayor(int a, int b, int c){

  return ((a>=b) && (a>=c)) ? (a) : (((b>=a) && (b>=c)) ? (b) : (c));

}

int main (){

printf("%d", mayor(9, 5, 2));

}

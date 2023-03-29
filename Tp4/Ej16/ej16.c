#include <stdio.h>
#include "../../libreria/getnum.h"
#define DIVISOR(a, b)  ((b)!=0 && ((a)<0 ? -(a) : (a)) % ((b)<0 ? -(b) : (b)) ==0   )


int main(){

  int a = getint("Dame un numero: "), b = getint("Dame otro numero: ") ,c;

  c = DIVISOR(a,b);

printf("%s divisor", c == 1 ? "Es" :"No es");

  return 0;
}

#include <stdio.h>
#include "../../libreria/getnum.h"

#define MAXIMO2(a, b, c) { c = (a > b) ? a : b; }
#define MAXIMO3(d, c, max){ max = (d > c) ? d : c; }

int main (){

  int a = getint("Dame un numero: "), b = getint("\nDame otro numero: "), d = getint("\nDame el ultimo numero: "), c, max;

  MAXIMO2(a, b, c);
  MAXIMO2(d, c, max);

  printf("El mas mas grande = %d\n", max);



}

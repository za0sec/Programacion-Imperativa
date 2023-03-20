#include <stdio.h>
#include "../../libreria/getnum.h"
int main(){
  double a;
  do
    a = getdouble("Cuanto vendiste esta semana?");
  while( a < 0 );
  a <= 1000 ? (a = 300) : (a > 1000 && a <= 2000) ? (a = ((a * 0.05) + 300.00)) : (a > 2000 && a<= 4000) ? (a = ((a*0.07) + 300.00)) : (a = ((a*0.09) + 300.00));
  printf("Tu ganancia es de $%.2f\n", a);
  return 0;
}

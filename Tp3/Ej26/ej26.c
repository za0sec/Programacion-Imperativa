#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int a = getint("Ingrese un número entero:");
  
  if ( a > 0 ){
    printf("Es mayor que cero\n");
  }else if ( a < 0 ){
    printf("Es menor que cero\n");
  }else{
   printf("Es igual a cero\n");
  }
}

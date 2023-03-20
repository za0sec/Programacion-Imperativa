#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int p, i, a = getint("Decime el largo del cuadrado:");
  
  for ( i=1; i<=a; i++ ){

    printf("\n");
    for ( p=1; p<=a; p++ ){

      printf("*");

    } 

  }
puts(" ");

}

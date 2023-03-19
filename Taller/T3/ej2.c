#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  int c, suma = 0, point = 0;

  while ( (c = getchar()) != '\n' && ((c >= '0' && c <= '9') || (c == '.')) ){
  
    if (point == 1){
    
      suma += c - '0'; 
    
    }else{
    c='.' ? point=1 : puts
    }
  }
  printf("la suma de sus cifras es igual a %d\n", suma);
  return 0;
}


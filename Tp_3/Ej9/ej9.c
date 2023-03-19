#include <stdio.h>

int main(){

  int i, p, new, tabs, Blank;
  


  for ( i=1; i!=EOF; i++; ){
 
    p = getchar();

    if ( p == '\n' ){

    new++; 

    }
  }

  printf("Tenes %d saltos de lineas", new);


}

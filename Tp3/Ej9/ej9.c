#include <stdio.h>

int main(){

  int i, new=0, tabs=0, blank=0;
  while ( (i=getchar()) != EOF ){
    if ( i == '\n' ){
      new++; 
    }else if ( i == '\t' ){
      tabs++;
    }else if ( i == ' ' ){
      blank++;
    }
  }
  printf("Tenes %d saltos de lineas\nTenes %d tabs\nTenes %d espacios en blanco", new, tabs, blank);
  return 0;
}

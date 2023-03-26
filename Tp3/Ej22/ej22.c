#include <stdio.h>

int main(){

  int c, varGuardada, cont = 0;

  while ( (c = getchar()) != EOF ){

  
    printf("%c", (c==' ' && varGuardada==' ') ? 0 : c );

    varGuardada = c;

  }
}

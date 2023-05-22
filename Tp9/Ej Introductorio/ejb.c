#include <stdio.h>

int strLEN(char * s);

int main(){

  char * s  = "Hello World";

  int dim = strLEN(s);

  printf("%d\n", dim);

return 0;

}

int strLEN(char * s){

  if ((*s) == '\0')
    return 0;

  return 1 + strLEN(s+1);

}

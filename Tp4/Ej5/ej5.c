#include <stdio.h>
#define MAXIMO2(a, b, c) { c = (a > b) ? a : b; }

int main(){
  
  int a = 10, b = 25, c;

  MAXIMO2(a, b, c);

  printf("%d", c);

  return 0;
}

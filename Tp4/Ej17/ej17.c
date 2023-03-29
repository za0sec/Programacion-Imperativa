#include <stdio.h>
#define ELAPSED(h1, m1, h2, m2) (( ((h1) * 60 + (m1)) - ((h2)*60 + (m2))) < 0 ? -(((h1) * 60 + (m1)) - ((h2)*60 + (m2))) : (((h1) * 60 + (m1)) - ((h2)*60 + (m2))) )

int main(){

  int minutos;


  minutos = ELAPSED(3, 15, 2, 10);
  printf("%d\n", minutos);

  return 0;

}

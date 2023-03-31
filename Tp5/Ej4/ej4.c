#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../libreria/getnum.h"


int random(int a, int b){
  
return (rand() % (b - a - 1)+1) + a;
  

}

int main(){
  
  int a = 9;
  int b  = 15;

  srand(time(NULL));
  printf("%d\n", random(a,b));

  return 0;
}

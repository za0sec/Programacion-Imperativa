#include <stdio.h>
#define swap(t,x,y) {t c = x; x=y; y=c; }


int main(){

  float x = 2.45;
  float y = 6.65; 

  
  swap (float,x,y);

  printf("%f %f", x, y);

}

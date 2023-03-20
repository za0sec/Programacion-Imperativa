#include <stdio.h>

int main(){

  int i;

  printf("\na) ");

  for ( i=3; i<=23; i+=5){
    
    printf("%d,", i);

  }
  printf("\nb) ");

  for ( i=20; i>=-10; i-=6){
    
    printf("%d,", i);

  }

  printf("\nc) ");

  for ( i=19; i<=51; i+=8){

  printf("%d,", i);

  }
}

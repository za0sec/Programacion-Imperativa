#include <stdio.h>

int main(){

  int a = getchar();
  int b = getchar();

  int g = "3" + '4';

  printf("%d", g);
  if ( a == b ){

    printf("Son iguales!");
        

  }else if ( a < b ){

    printf("El primero es menor al segundo");

  }else{

    printf("El segundo es menor al primero");    

  }

}

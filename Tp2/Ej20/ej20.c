#include <stdio.h>

int main(){

  int a = getchar();  

//  printf("Hello World!\z\n");


  if ( a != EOF ){

    printf("Es igual a 0");
    printf("EOF es igual a %d\n ", EOF);
  }else {
  
    printf("Es igual a 1\n");
    printf("'a' es = a %d", a);
  }

  return 0;

}

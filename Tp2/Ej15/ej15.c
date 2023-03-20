#include <stdio.h>

int main(){
  
  
  printf("Dame una letra: ");
  int a = getchar();

  a += ('A'-'a');

  printf("El caracter en mayuscula es: %c", a);

}

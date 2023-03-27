#include <stdio.h>
#define isdigit(c) ( ((c) >= '0' && (c) <= '9') ? 1 : 0 )

int main(){

  printf("Dame un numero: ");
  int a = getchar();

  if ( isdigit(a) ){

    printf("Es un digito");

  }




}

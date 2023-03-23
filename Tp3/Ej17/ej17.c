#include <stdio.h>
int main(){

  int i;
    for (i=10; i>=10; i+=10){ 
      printf("%d,", i);
    }
  return 0;
}
// Lo que sucede es que ademas de que el programa va a ser infinito (porque escribir todos los multiplos de 10 es una cifra infinita de numeros),
// aparte, va a llegar un numero en el que va a haber desbordamiento de enteros.

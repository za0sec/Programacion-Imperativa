/*Escribir una función "palotes" que reciba un entero cant sin signo y envíe en forma recursiva a la salida estándar cant  "palotes". Si recibió cero, no imprime nada, si recibió 4, la salida debe ser "||||"  (las comillas no deben imprimirse)
*/

#include <stdio.h>

void palotes(int cant);

int main(){

  palotes(10);
  puts("");
  
  return 0;

}

void palotes(int cant){

  if (cant == 0) 
    return;
  
  palotes(cant-1);

  printf("|");

}

//En muchos supermercados se ordena la mercadería de manera especial, para capturar la atención del comprador.  
//Un ejemplo concreto es el de ordenar latas en forma de "pirámide", de manera tal que arriba de todo haya una sola lata, debajo 4, luego 9 y así sucesivamente.	

//Escribir la función recursiva piramide  que regrese toda la información a través de dos parámetros de entrada-salida,  a saber:
//latas, que representa la cantidad de latas que no se llegaron a apilar. Inicialmente representa la cantidad total de latas.
//altura, que representa la cantidad de niveles con que se puede construir la pirámide. Inicialmente se encuentra en 0.

//El cuerpo de la función piramide no debe superar las 8 líneas de código
//No usar funciones auxiliares

//Ejemplos:
//Si se invoca a la función pirámide con 10 latas y altura 0, al terminar la recursividad el parámetro latas debe quedar en 5 y altura en 2.
//Si se invoca a la función pirámide con 55 latas y altura 0, al terminar la recursividad el parámetro latas debe quedar en 0 y altura en 5.
//Si se invoca a la función pirámide con 1 lata y altura 0, al terminar la recursividad el parámetro latas debe quedar en 0 y altura en 1.


#include <stdio.h>
#include <assert.h>
#include <math.h>

void piramide(int *latas, int *h);

int main(void) {

  int h=0, latas=0;
  piramide(&latas, &h);
  assert(latas==0 && h==0);

  h=0, latas=10;
  piramide(&latas, &h);
  assert(latas==5 && h==2);

  h=0, latas=55;
  piramide(&latas, &h);
  assert(latas==0 && h==5);

  h=0, latas=1;
  piramide(&latas, &h);
  assert(latas==0 && h==1);

  h=0, latas=2;
  piramide(&latas, &h);
  assert(latas==1 && h==1);

  h=0, latas=3;
  piramide(&latas, &h);
  assert(latas==2 && h==1);

  h=0, latas=4;
  piramide(&latas, &h);
  assert(latas==3 && h==1);

  h=0, latas=5;
  piramide(&latas, &h);
  assert(latas==0 && h==2);

  printf ("OK!\n");
  return 0;
}


void piramide(int * latas, int * h){


  (*h)++;

  if (*latas < pow(*h, 2)) {
    (*h)--;
    return;
  }


  (*latas)-=(int)pow(*h, 2);

  piramide(latas, h);
}


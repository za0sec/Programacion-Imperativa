/*Una partícula realiza un camino aleatorio dentro de un círculo de acuerdo a la siguientes reglas :
En tiempo t = 0 la partícula está en el centro ( x = 0, y = 0).
La partícula hace un paso aleatorio en una de las cuatro direcciones dada por
x = x - 1
x = x + 1
y = y - 1
y = y + 1
La caminata termina cuando se sale fuera del círculo ( x2 + y2>= r2 ).

	Considerando cada punto como una estructura de componentes cartesianas y teniendo en cuenta que el tiempo se mide con un contador que se incrementa  en cada paso de la partícula, escribir un programa que para distintos tamaños de círculos determine experimentalmente la relación entre el tiempo requerido para terminar la caminata y el valor del radio.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../libreria/random.h"

#define MAX_CIRC 9 



typedef struct tPoint{

  int x;
  int y;

}tPoint;

int movimiento(tPoint * puntos, int r);



int main(){

  randomize();

  tPoint puntos;

  int t;

  int r[] = {1,2,3,4,5,6,7,8,9};

  puts("\tRADIO | TIEMPO");

  for (int i=0; i<MAX_CIRC; i++){
    puntos.x = 0;
    puntos.y = 0;
    t = movimiento(&puntos, r[i]);
    printf("\t%d | %d\n", r[i], t); 
  }

}

int movimiento(tPoint * puntos, int r){

  
  int direcc[] = {-1,0,1};

  int movX, movY, t=0;

  while(pow(puntos->x,2) + pow(puntos->y,2) < pow(r,2) ){

    movX = direcc[randInt(0,2)];
    movY = direcc[randInt(0,2)];

    t++;
    puntos->x += movX;
    puntos->y += movY;

  }

  return t;

}

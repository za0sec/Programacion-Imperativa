/*Una partícula realiza un camino aleatorio dentro de un círculo de acuerdo a la siguientes reglas :
En tiempo t = 0 la partícula está en el centro ( x = 0, y = 0).
La partícula hace un paso aleatorio en una de las cuatro direcciones dada por
x = x - 1
x = x + 1
y = y - 1
y = y + 1
La caminata termina cuando se sale fuera del círculo ( x2 + y2>= r2 ).

Considerando cada punto como una estructura de componentes cartesianas y teniendo en cuenta que el tiempo se mide con un contador que se incrementa  en cada paso de la partícula, escribir un programa que para distintos tamaños de círculos determine experimentalmente la relación entre el tiempo requerido para terminar la caminata y el valor del radio.

Mostrar los valores hallados mediante una tabla cuyas columnas sean:
Radio
Tiempo
Relación (radio / tiempo )
*/

#include <stdio.h>
#include "../../libreria/random.h"
#include <math.h>


typedef struct tPoint{

  int x;
  int y;

}tPoint;

void movement(tPoint * particle, int * t);

int main(){

  randomize();
  
  int r[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int t = 0; 

  tPoint particle;

  particle.x = 0;
  particle.y = 0;

  for (int i=0; i<10; i++){
    while( (pow(particle.x, 2) + pow(particle.y, 2)) < r[i]){
      movement(&particle, &t); 
    }
    printf("%d\t%d\t%f\n", r[i], t, (float)r[i]/t);
  }
}

void movement(tPoint * particle, int * t){
  
  
  int increment[] = {-1, 1}; 
  
  (*t)++;

  int moveX = randInt(0, 1);
  int moveY = randInt(0, 1);
  
  particle->x += increment[moveX];
  particle->y += increment[moveY];
  
}

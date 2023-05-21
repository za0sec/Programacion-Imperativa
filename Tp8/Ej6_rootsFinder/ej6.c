/*
Escribir un programa para hallar las raíces de una función matemática en un intervalo cerrado, recorriéndolo de forma tal que el intervalo quede dividido en 100000 (cien mil) particiones o subintervalos. Ejemplo: si el intervalo es [1, 50000] deberá evaluar la función en los puntos 1, 1.5, 2, etc. (también se tomarán como válidos los puntos 1, 1.49999, etc ).
El programa deberá solicitar los extremos del intervalo, imprimiendo los resultados en la salida estándar. La función a evaluar recibe y devuelve un valor real y está dada por la macro FUNCION.
La función que realice la búsqueda de las raíces debe recibir como parámetros una estructura que represente al intervalo,  regresando en su nombre una estructura que empaquete un arreglo con aquellas particiones donde haya raíces y la dimensión de dicho arreglo.
Para detectar una raíz se deben considerar dos casos:
Que la función cambie de signo entre dos puntos: En ese caso se agrega al arreglo una partición con ambos puntos.
Que la función se haga cero en un punto (considerando un error de EPSILON): En ese caso la partición que se agrega al arreglo de resultados está formada por el punto anterior al que se detectó como raíz y el próximo que no lo sea.
*/


#include <stdio.h>
#include <stdlib.h>
#include "../../libreria/getnum.h"

#define FUNCTION(x) ( (2*x*x) - (4*x) )

#define EPSILON 0.00001

#define CHUNK 20

typedef struct result{
    double (*roots)[2];
    int count;
} result;


typedef struct intervalo_t{
  double a;
  double b;
} intervalo_t;

double interval(intervalo_t * inter);

result rootsFinder(intervalo_t inter, double step);

void printResult(result rootFound);


int main(){
  
  intervalo_t inter;
  double step = interval(&inter);

  result rootFound = rootsFinder(inter, step);

  printResult(rootFound);


}

void printResult(result rootFound){

  int i;

  for (i=0; i<rootFound.count; i++){
    printf("Raiz en [%f, %f]\n", rootFound.roots[i][0], rootFound.roots[i][1]);
  }

}

result rootsFinder(intervalo_t inter, double step){

  int i, t;

  int signActual, signNext;
  double actualF, nextF;

  result rootFound;
  
  rootFound.roots = NULL;
  
  double next = (inter.a) + step;
  double actual = inter.a;


  for (i=t=0; actual <= inter.b; i++){

    if (!(t%CHUNK)){
      rootFound.roots = realloc(rootFound.roots, (t+CHUNK) * 2 * sizeof(double[2]));
    }

    actualF = FUNCTION(actual);
    nextF = FUNCTION(next);
  
    signActual = actualF < 0 ? -1 : 1;
    signNext = nextF < 0 ? -1 : 1;


    if ( ( actualF <=EPSILON && nextF >= -EPSILON) || (signActual * signNext < 0) ){
    
      rootFound.roots[t][0] = actual;
      rootFound.roots[t++][1] = next;

    }

    actual += step;
    next += step;

  }

  rootFound.count = t;

  return rootFound;

}

double interval(intervalo_t * inter){

  double step;  

  inter->a = getdouble("Ingrese el extremo izquierdo del intervalo: ");
  
  do{
  inter->b = getdouble("Ingrese el extremo derecho del intervalo: ");
  }while(inter->b <= inter->a);
  
  step = (inter->b - inter->a)/100000.0;

  return step;
}

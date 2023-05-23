/*
 El método de Newton-Raphson para aproximar la raíz cuadrada de un número positivo
 se puede calcular aplicando sucesivamente los siguientes pasos un cierto número de veces  ITER:

                  valor_aprox[n] + (x / valor_aprox[n])
valor_aprox[n+1] = ---------------------------------
                                    2

donde el valor original conveniente para comenzar este ciclo suele ser X/2.

Escribir una función recursiva raizCuadrada que regrese en su nombre el valor aproximado de la raíz cuadrada de un número, 
recibiendo tres parámetros de entrada:

valorAnterior: real (representa el valor  hasta ahora  candidato como raíz cuadrada)

iter: entero  que  representa  la cantidad  de iteraciones que  deben realizarse  para aproximar la raíz cuadrada.

x:  real al que se le quiere calcular la raíz cuadrada.

Ejemplo: 
	Si valorAnterior = 4,  iter= 3,  x= 8,  entonces  la función  devolverá 2.8333 (los valores sucesivos obtenidos son: 4, 3, 2.833 ) 

*/

#include <stdio.h>
#include <assert.h>
#include <math.h>

double raizNR(double vA, int iter, double x);

#define EPSILON 0.01

int main(void){

    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);
    
    printf("OK!\n");
}

double raizNR(double vA, int iter, double x){

  if (iter == 0)
    return vA;

  return raizNR((vA + (x/vA))/2, iter-1, x);


}

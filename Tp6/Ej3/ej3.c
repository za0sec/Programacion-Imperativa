/* Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es cero, escribir una función para obtener la mayor
 * diferencia entre dos elementos consecutivos. (En no más de 5 líneas). Tener en cuenta que los números pueden ser negativos.
 * En caso de que el3 vector tenga un solo elemento deberá retornar como diferencia el valor cero.
*/

#include <stdio.h>
#include <math.h>


double difference(const double real[], unsigned int dim);


int main(){


  double real[] = {1.4,5.3,4.5,8.6,15.5,5.5,0};

  int dim = sizeof(real)/sizeof(real[0]);
  
  printf("%f", difference(real, dim));
  
}


double difference(const double real[], unsigned int dim){
  
  double dif, dif2 = 0;
  
  for ( int i=1; real[i] != 0; i++ ){

    double realAbs1 = fabs(real[i]), realAbs2 = fabs(real[i-1]);

    dif = realAbs1 > realAbs2 ? (realAbs1 - realAbs2) : (realAbs2 - realAbs1);

    if ( dif > dif2 ){

      dif2 = dif;

    }
  
  }
  
  return dim == 1 ? dif = 0 : dif2;
  
  
  
  
  
}

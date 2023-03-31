/*Escribir una función potencia, que reciba en dos parámetros de entrada la base (de tipo double) y el exponente (entero),
 y devuelva el valor de dicha potencia (En no más de 10 líneas).
 Por ejemplo, potencia(2,-4) debe devolver 0.0625. En caso de no poder calcularse el resultado debe devolver –1.
 */
#include <stdio.h>
#include "../../libreria/getnum.h"

double potencia(double a, int b){
    
  double t = 1/a;
  double l = a;

  if ( b < 0 ){

    for (int i=-1; i>b; i-- ){

      t *= 1/a;

    }

  }else if ( b > 0 ){

    for (int i=1; i<b; i++ ){

      l *=a;

    }
  
  }

  return (b<0) ? t : ((b>0) ? l : 1);  

} 

int main(){

  double a = getdouble("Ingresa un numero (Cualquier tipo de numero): ");
  int b = getint("elevado a? (Numero entero) ");

  printf("%f", potencia(a, b));
  
  return 0;

}

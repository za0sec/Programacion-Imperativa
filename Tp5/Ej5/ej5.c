#include <stdio.h>
#include "../../libreria/getnum.h"

double potencia(double a, int b){
    
  double t = 1/a;
  double l = a;

  if ( b < 0 ){

    for (int i=-1; i>b; i-- ){
      
      (a == 0.0) ? (t = -1) : (t *= 1/a);

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

  printf("%f\n", potencia(a, b));
  
  return 0;

}

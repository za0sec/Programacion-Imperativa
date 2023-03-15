#include <math.h>
#include <stdio.h>
#include "../../libreria/getnum.h"

int main(){

  double a = getdouble("Escribi el primer coeficiente de la cuadratica:");
  double b = getdouble("Escribi el segundo coeficiente de la cuadratica:");
  double c = getdouble("Escribi el tercer coeficiente de la cuadratica:");

  if ( ((b*b)-4*a*c) < 0 ){
  
    printf("Los coeficientes ingresados dan resultados complejos");

  }else if ( ((b*b)-4*a*c) == 0 ){
    
    double t = ((-b)/2*a);

    printf("Los coeficientes ingresados devuelven una unica raiz y es: %f", t);

  }else{

  

    double r = ((-b) + sqrt(((b*b)-4*a*c)))/(2*a);
    double p = ((-b) - sqrt(((b*b)-4*a*c)))/(2*a);
  
    printf("Los resultados de la cuadratica son: %f %f", r, p);
  }

  return 0;
}

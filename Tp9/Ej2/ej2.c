/*Escribir la función recursiva suma que reciba un único
 *parámetro de entrada de tipo integer y devuelva en su nombre la suma de sus dígitos.
  
 *Por ejemplo,  suma( 3498 ) devuelve 24
*/

#include <stdio.h>

int sum(int n);

int main(){


 printf("%d\n", sum(3498)); 


  return 0;

}

int sum(int n){
  
  if (n == 0)
    return 0;
  

  return (n%10) + sum(n/10);

}

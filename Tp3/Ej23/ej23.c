#include <stdio.h>
#include "../../libreria/getnum.h"
#include <ctype.h>

int main(){

  int n,c;


  /* al salir del ciclo n debe ser un número par mayor que cero */
  do
	  n = getint("dame un numero: ");
  while( ((n%2) == 1) || (n<0) );

//  printf("%d", n);

		
  /* este ciclo debe incluir la lectura de caracteres y debe ejecutarse  
  * mientras no sea fin de archivo y los caracteres sean  dígitos o minúsculas
  */
  while ( ((c = getchar()) != EOF) && (isdigit(c) || islower(c))  )
    
 	  putchar(c);
}

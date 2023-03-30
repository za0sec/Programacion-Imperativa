#include <stdio.h>
#include "../../libreria/getnum.h"
#include <math.h>

int lugar (int num, int pos);


int
main( void )
{
	int boleto, esCapicua=1;
	int  j, cont = 0;
	
	boleto = getint("Ingrese un número de cualquier cantidad de dígitos: ");
  //Guardo boleto en otra variable para poder modificarlo sin problemas.
  int boleto2 = boleto;

  for ( j=0; boleto2!=0; j++ ){

    cont++;
    boleto2/=10;
  }


	for (j=1; j<=2; j++)
		if ( lugar(boleto, j) != lugar(boleto,cont-j+1))
		{	
 			esCapicua=0;
			break;
		}


  if ( esCapicua ){
	  printf("El boleto es capicúa");
	return 1;
  }else{

    printf("El boleto no es capicúa");
    return 0;
  }


}


int 
lugar( int num, int pos )
{	
return (num / (int)pow(10, pos-1)) % 10;
}


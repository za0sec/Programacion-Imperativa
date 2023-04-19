#include <stdio.h>
#include "../../libreria/getnum.h"
#include <math.h>



int mcd(int *num, int *den){

  int temp;
  while (den != 0) {

    temp = num % den;
    num = den;
    den = temp;

  }
  
  return *num;

}

void simplify(int *num, int *den){


  
  int div = mcd(&num, &den);

  *num /= *div;
  *den /= *div;

}

void sum(int num, int den, int num2, int den2){
    
  int dcm = (mcd(den, den2));

  if ( dcm == den && dcm == den2 ){

    num += num2;
    simplify(num, den);

  }else if ( dcm == 1 ){

    int neonum = ((num*den2) + (num2*den));
    den *= den2;

    simplify(neonum, den);

  }else{


    simplify( ((num*den2) + (num2*den)), (den*den2));


  }
  

  


}


int menu(){


  unsigned int selection;

  do
    selection = getint("\tElija una opcion:\n\n\tSimpificar una fraccion.\n\tSumar dos fracciones.\n\tTerminar la ejecucion.\n\n");
  while (selection != 1 && selection != 2 && selection != 3 && selection !=4);


  return selection;

}

int main(){

  int num, num2, den, den2;

  switch (menu()){
    case 1:
      num = getint("Ingrese un numerador: ");
      den = getint("Ingrese un denominador: "); 
      simplify(&num, &den);
      printf("La fraccion simplificada es %d/%d", num, den);
      break;
    case 2:
      num = getint("Ingrese un numerador (primer fraccion): ");
      den = getint("Ingrese un denominador (primer fraccion): "); 
      num2 = getint("Ingrese un numerador (segunda fraccion): ");
      den2 = getint("Ingrese un denominador (segunda fraccion): "); 
      sum(num, den, num2, den2);
      break;
    case 3:
      return 0;
  }


}

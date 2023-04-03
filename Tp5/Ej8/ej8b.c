#include <stdio.h>
#include "../../libreria/getnum.h"
#include <math.h>

double redondeo(double num, int Dec){

  double h = 1;

  for ( int i = 1; i <= Dec; i++ ){

    num *= 10;

    h *= 10;
  }

  return ( ((int)(num+0.5)) / h );

}


int roundInt(double num){

  redondeo(num, 2);

  int num3 = (int)(num*100)%10;
  int num2 = (int)(num*10)%10;

  if ( ( num2 >= 5 &&  num3 > 0 ) ){

   return (printf("%d\n", (int)ceil(num)));
    
  }else{

    return (printf("%d\n", (int)floor(num)));

  }

}

int roundDec(double num){

  redondeo(num, 2);

  int num3 = ((int)num)%10;
  int num2 = (int)(num*10)%10;

  if ( ( num3 >= 5 &&  num2 > 0) || ( num3 > 5 &&  num2 >= 0) ){

   return (printf("%d\n", ((int)num+10-num3)));
    
  }else{

    return (printf("%d\n", (int)(num-num3)));

  }

}

int roundCent(double num){

  redondeo(num, 2);

  int num4 = (int)(num/10)%10;
  int num3 = ((int)num)%10;
  int num2 = (int)(num*10)%10;

  if ( ((int)num/100)%10 <= 5 && ((int)num/100)%10 != 0 ){

    return (printf("%d\n", 100));

  }else{

    if ( ( num4 == 5 &&  (num3 > 0 || num2 > 0) ) || ( num4 > 5 ) ){

      return (printf("%d\n", ((int)num+100-(num4*10+num3))));
    
    }else{

      return (printf("%d\n", (int)(num-(num4*10+num3))));

    }
  }

}

int roundMil(double num){

  redondeo(num, 2);

  int num4 = (int)(num/100)%10;
  int num3 = ((int)num/10)%10;
  int num2 = (int)(num)%10;
  int num5 = (int)(num*10)%10;

    if ( ( num4 == 5 &&  (num3 > 0 || num2 > 0 || num5 > 0 ) ) || ( num4 > 5 ) ){

      return (printf("%d\n", ((int)num+1000-(num4*100+num3*10+num2))));
    
    }else{

      return (printf("%d\n", (int)(num-(num4*100+num3*10+num2))));

    }
      
    
  }




int menu(){
  
int selec = getint("\tElija una de las siguientes opciones:\n\n\
          \tRedondeo al entero más cercano. (1)\n\
          \tRedondeo a la décima más cercana. (2)\n\
          \tRedondeo a la centésima más cercana. (3)\n\
          \tRedondeo a la milésima más cercana. (4)\n");
  
  return selec;

}





int main() {


  double num = getdouble("Ingrese un numero: "); 

  int selec = menu();

  switch (selec) {
    case 1:
      roundInt(num);
      break;    
    case 2:
      roundDec(num);
      break;
    case 3:
      roundCent(num);
      break;
    case 4:
      roundMil(num);
      break;
  }


  return 0;

}


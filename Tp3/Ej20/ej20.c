#include <stdio.h>
#define EPSILON 0.00001

int main(){

  int i, varGuardada, factorial = 1; 
  float e, a = 1.0;

  puts("\t\tN\t|\te\n\t-----------------------------------");

  for ( i=0; (a>EPSILON); i++ ){

    if (i==0){

      e=1.0;
      printf("\t\t%d\t|\t%f\n", (i+1), e);

    }else{

      factorial *= i;
      
      a = (1.0/(float)factorial);
      e += a;

      printf("\t\t%d\t|\t%.20f\n", (i+1), e);
    
    }
    varGuardada = e;
    
  }


}

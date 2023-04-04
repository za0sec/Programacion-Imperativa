#include <stdio.h>
#include <math.h>
#define EPSILON 0.03

int fact(int r){

  int i, l =1;

  for ( i = 1; i<=r; i++ ){

    l *= i;

  }
  
  return l;

}


double taylor(int x){

  int i;
  double l = 0;

  for ( i=0; i<13; i++ ){

    l += (double)(pow(x,i))/(double)(fact(i));

  }

  return l;
}



int main(){

  printf("%f\n", taylor(7));
  printf("%f\n", exp(7));

}

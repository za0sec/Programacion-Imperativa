#include <stdio.h>
#include <math.h>
#define EPSILON 0.03

double fact(int r){

  int i, l =1;

  for ( i = 1; i<=r; i++ ){

    l *= i;

  }
  
  return l;

}


double taylor(double x, double epsilon){

  int i;
  double l = 1, t = 0;


  for ( i=1; (l-t) > epsilon; i++ ){

    t = l;
    l += (double)(pow(x,i))/(double)(fact(i));

  }

  return l;
}



int main(){

  //printf("%d", fact(10));

  printf("%f\n", taylor(7, 0.0001));
  printf("%f\n", exp(7));

}

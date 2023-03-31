#include <stdio.h>
#include <math.h>


int fact(int r){

  int i;

  for ( i = 1; i<r; i++ ){

    i*=i;

  }
  
  return i;

}


int expo(x){

  int i;

  for ( i=1; i<10; i++ ){

  int l = (pow(i,x))/(fact(i));

  }

}



int main(){

  printf("%d", fact(5));


}

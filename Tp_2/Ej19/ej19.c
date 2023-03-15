#include <stdio.h>

int main(){

//  int c1 = getchar();
//  int c2 = getchar();

//  printf ("%c es mayor\n", c1 > c2 ? c1 : c2);
  javito();

}

int javito(){

  int c1, c2;

  printf ("%c es mayor", (c1 = getchar()) > (c2 = getchar()) ? c1 : c2);
 


}

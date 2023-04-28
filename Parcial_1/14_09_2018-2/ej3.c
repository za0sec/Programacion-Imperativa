#include <stdio.h>

#define TO_UPPER(a) ( ((a)>= 'a' && (a)<= 'z') ? (a) + 'A'-'a' : (a) )


int main(){


  int c = 'd';
  char a = '5';

  c = TO_UPPER(c);
  a = TO_UPPER(a);

  printf("%c, %c", c, a);



}

#include <stdio.h>
#include "../../libreria/getnum.h"
int main(){
int c, p = 'z', may = 0, min = 0;
  while ((c= getchar()) != EOF && ((c >= 'A' && c<= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' )){
    if ( isupper(c) && c != ' ' ){
      may++;
      if ( c<=(p-' ') ){
        p = c;
      }
    }else if ( c != ' ' ){
      min++;
      if ( (isupper(p)) &&  (c <= (p + ' ')) ){
          p = c;
        }else if ((islower(p)) && (c<=p) ){
          p = c;
        }
    }
}
  printf("%c\n", p);
  printf("Hay %d Mayusculas y %d Minusculas\n", may, min);
}

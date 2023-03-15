#include <stdio.h>
int main(){
  char a = getchar();
  char b = getchar();
  a == b ? printf("\n%c es igual a %c\n", a, b) : ( a > b ? printf("%c es mayor a %c\n", a, b) : printf("%c es mayor a %c\n", b, a));
return 0;
}

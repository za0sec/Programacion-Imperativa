#include <stdio.h>


int main (){

  char a, b, num, ahex, bhex;
  printf("Brindame un numero:");
  a = getchar();
  b = getchar();

  if ( '0'<=a<='9' && '0'<=b<='9' ){
    
      a -= '0';
      b -= '0';
      num = (a*10) + b ;
      printf("Tu numero es %d\n", num);
      ahex = num/16;
      ahex = (ahex >= 10)?'A'+ahex-10:'0'+ahex;
      bhex = num%16;
      bhex = (bhex >= 10)?'A'+bhex-10:'0'+bhex;
      printf("ahex:%c\n", ahex);
      printf("bhex:%c", bhex);

  }else{

    printf("No es un numero.");

  }

return 0;
}

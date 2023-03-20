#include <stdio.h>

int main(){

  int i;
  


  while ( (i=getchar()) != EOF ){

    if ( i != ' ' ){

      printf("%c", i);


    }else{

      printf("\n");

    }

  }


  return 0;

}

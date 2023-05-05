#include <stdio.h>
#include <stdlib.h>

int main(){


  char c;
  int i=0, tam=0;


  char * sVector = NULL;

  while((c = getchar()) != '\n'){
  

    if ( i%10 == 0){

      i++;
      sVector = realloc(sVector, 10*i*sizeof(char));
    }
    sVector[tam++] = c;

  }

  for (int j=0; j<tam; j++){

    printf("%c", sVector[j]);

  }

  free(sVector);

  return 0;

}

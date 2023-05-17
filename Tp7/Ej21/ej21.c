#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char * TAlumnos[]; 
#define BLOQUE 5

void liberaAprobados(char ** apr);

char ** aprobados(TAlumnos alumnos, int notas[]);

int main(void){

    TAlumnos alumnos = {"Juan", "Pedro", "Martin", ""};
    int notas[] = {1, 4, 10, 2, 10, 11};
    
    char ** apr = aprobados(alumnos, notas);
    if(apr == NULL){
        printf("No hay suficiente memoria!\n");
        return 1;
    }
    assert(!strcmp(alumnos[1], apr[0]) && !strcmp(alumnos[2], apr[1]) && !strcmp(alumnos[3], apr[2]));

    puts("OK!");

    liberaAprobados(apr);

    return 0;
}

void liberaAprobados(char ** apr){
  free(apr);
}

char ** aprobados(TAlumnos alumnos, int notas[]){

  
  char ** apr = NULL;

  int t, i;

  for (i=t=0; alumnos[i][0]; i++){

    

    if (notas[i] >= 4){
      
      if (t%BLOQUE == 0){
        apr = realloc(apr, (BLOQUE+t) * sizeof(char*));
      } 

      apr[t++] = alumnos[i]; 
    }
  }

  apr = realloc(apr, (t+1)*sizeof(char*));

  apr[t] = "";

  return apr;


}

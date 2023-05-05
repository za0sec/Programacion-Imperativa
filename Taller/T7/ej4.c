#include <stdio.h>
#include <stdlib.h>

int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], int notas[]);

void mostrarNombres(char * aprobados[], int tam);

int main(void) {

  char * arrNombres[] = {"anita","pepe","fabi","carlos","tere"};
  
  char * aprobados[5];
  
  int notas[] = {3,4,8,10,1};
  
  int tam, tamApro;

  tam = sizeof(arrNombres) / sizeof(char*);
  
  mostrarNombres(arrNombres, tam);
  
  tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
  
  printf("Aprobados:\n");

  mostrarNombres(aprobados, tamApro);
  
  return 0;

}


int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], int notas[]){
  
  int i,j;
  
 for (i=j=0; i<tam; i++){

    if (notas[i] >= 4){

     aprobados[j++] = arrNombres[i];

    }

  } 
  
  return j;

}

void mostrarNombres(char * aprobados[], int tam){

  for (int i=0; i<tam; i++){

    printf("%s ", aprobados[i]);
    
  }

}

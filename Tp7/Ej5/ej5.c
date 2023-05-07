#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 4 

// Cambiar de acuerdo al tipo elegido 
// Si usan "matriz" de chars debe quedar
// typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];   

// Si usan vector de punteros a char debe quedar
// typedef char * TAlumnos[MAX_ALUMNOS];



typedef char * TAlumnos[MAX_ALUMNOS];
typedef char TCurso[MAX_ALUMNOS + 1];

void separaCursos(char * alumnos[], char curso[], char * cursoG[], char * cursoH[]);


int main(void){

    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso={'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

    alumnos[0]=""; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}


void separaCursos(char * alumnos[], char curso[], char * cursoG[], char * cursoH[]){

  int i, j, k;

  for (i=j=k=0; alumnos[i][0] != '\0'; i++){

    if (curso[i] == 'H'){
      cursoH[j++] = alumnos[i];
    
    }else if (curso[i] == 'G'){
      cursoG[k++] = alumnos[i];
    
    }
  
  }


  cursoH[j] = "";
  cursoG[k] = "";
  
}


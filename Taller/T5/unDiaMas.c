#include <stdio.h>
#include <assert.h>
#define OK 1
#define ERROR !OK
enum meses 


int unDiaMas(int * dia, int * mes, int * ano);

static int bisiesto(int);
static int invalidoAnio(int);
static int invalidoMes(int);
static int invalidoDia(int, int, int);
 
int
main(void) {
    int dia, mes, anio;
 
    dia = 9, mes = 4, anio = 2021;
    printf("Fecha actual: %d/%d/%d\n", dia, mes, anio);
    if (unDiaMas(&dia, &mes, &anio))
        printf("Fecha con un dia mas: %d/%d/%d\n", dia, mes, anio);
    else
        printf("Error en los datos\n");
 
    dia = 1, mes = 1, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 2 && mes == 1 && anio == 2021);
 
    dia = 31, mes = 3, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 4 && anio == 2021);
 
    dia = 31, mes = 12, anio = 2020;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 1 && anio == 2021);
 
    printf("OK!\n");
    return 0;
}

int invalidoMes(int dia, int mes, int anio){

 
  


}




 
int unDiaMas(int * dia, int * mes, int * anio){
  

    if (invalidoDia(*dia, *mes, *anio ) || invalidoMes(*mes) || invalidoAnio(*anio))
      return 0;


     int daytab[2][12] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};


    int bis = esBisiesto(*anio);

    if ((*dia + 1) > daytab[bis][*mes-1]){

      *dia = 1;
      if ((*mes + 1) > 12){

        *mes = 1;
        (*anio)++;

      }else
        (*mes)++;


    }else{
      (*dia)++;
    }

  return 1;


  }
  
  
}

static int bisiesto(int anio) {
    int esb=0;
    if((anio%4 == 0 && anio%100!= 0) || anio%400 == 0)
        esb=1;
    return esb;
}

/*Escribir una función que reciba un string con el formato 'dd/mm/yyyy' que representa una fecha
* y devuelva en tres parámetros de salida el número de día, el número del mes y el año.
* En caso de que la fecha no sea correcta retorna el valor cero y no altera los parámetros recibidos,
* caso contrario retorna 1. (Ninguna función debe superar las 8 líneas).
*/
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LONG 10
enum meses { ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE };



int intFecha( const char * str, unsigned int * dia, unsigned int * mes, unsigned int * anio );

bool bisiesto(unsigned int anio);
bool noYear(int anio);
bool noMonth(int mes);
bool noDay(int dia, int mes, int anio);


int main(void) {
  unsigned int d=100, m=200, a=300;
  int res;
  res = intFecha("", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = intFecha("29/02/1999", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = intFecha("30/14/2020", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = intFecha("12/12/", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = intFecha("1/1/2000", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = intFecha("12/01/2000", &d, &m, &a);
  assert(res==1);
  assert(d==12);
  assert(m==1);
  assert(a==2000);

  res = intFecha("29/02/1900", &d, &m, &a);
  assert(res==0);
  assert(d==12);
  assert(m==1);
  assert(a==2000);

  res = intFecha("29/02/2000", &d, &m, &a);
  assert(res==1);
  assert(d==29);
  assert(m==2);
  assert(a==2000);

  printf("OK");
  return 0;
}

bool bisiesto(unsigned int anio) {
  bool esb=false;
    
  if((anio%4 == 0 && anio%100!= 0) || anio%400 == 0)
    esb=true;

  return esb;
}

int intFecha( const char * str, unsigned int * dia, unsigned int * mes, unsigned int * anio ){

  if (strlen(str) != LONG ){
    return 0;
  }

    int temp_dia = atoi(str);
    int temp_mes = atoi(str + 3);
    int temp_anio = atoi(str + 6);

  if ( noYear(temp_anio) && noMonth(temp_mes) && noDay(temp_dia, temp_mes, temp_anio) ){

  *dia = temp_dia;
  *mes = temp_mes;
  *anio = temp_anio;

  return 1;

  }

  return 0;


}

bool noMonth(int mes){

  return (mes >= ENERO && mes <= DICIEMBRE) ? true : false;

}

bool noYear(int anio){


  return ((anio) >= 0) ? true : false;

}

bool noDay(int dia, int mes,int anio){

  int daytab[2][12] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};

  int isBis = bisiesto(anio) ? 1 : 0;

  if ( (dia) > 0 && (dia) <= daytab[isBis][(mes)-1] ){

    return true;


  }
  
  return false;

}


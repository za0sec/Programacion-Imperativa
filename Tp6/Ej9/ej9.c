#include <stdio.h>
#include <math.h>
#include <assert.h>
#define EPSILON 0.0001

double desviation(const int intArray[], size_t dimArray);

double media(const int intArray[], size_t dimArray);

void enteros(const unsigned char bytes[], size_t dimBytes, int intArray[]);

int main(void) {
  double d;
  int intArray[10];
  unsigned char arreglo2[] = { 0x33, 0x33, 0x33, 0x33, 0x33 };
  enteros(arreglo2, 5, intArray);
  for(int i=0; i <= 10; i++)
    //printf("%f\t", desviation(intArray, i));
    assert(desviation(intArray, i)==0);
  

  unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
  enteros(arreglo, 5, intArray);
  assert(desviation(intArray, 1)==0);
  assert(desviation(intArray, 2)==2.0);

  assert(desviation(intArray, 3) > 4.98 && desviation(intArray, 3) < 4.99);

  assert(desviation(intArray, 10) > 5.6071 && desviation(intArray, 3) < 5.6072);

  puts("OK!");
}
void enteros(const unsigned char bytes[], size_t dimBytes, int intArray[]){

  int cont = 0;

  for ( int i = 0; i<dimBytes; i++ ){

    //byte de arriba
    intArray[cont++] = (bytes[i] & 0xF0) >> 4;
    //byte de abajo
    intArray[cont++] = (bytes[i] & 0x0F);

  }


}

double media(const int intArray[], size_t dimArray){
  
  int sum = 0;

  for ( int i=0; i<dimArray; i++ ){
    
    sum += intArray[i];
    
  }
  
  double med = (double)sum/(double)dimArray;
  
  return med;
}

double desviation(const int intArray[], size_t dimArray){


  double med = media(intArray,dimArray), desv, diferencia, varianza, prom = 0;
   
  if ( dimArray < EPSILON ){

    desv = 0;

  }else{

    for ( int i = 0; i<dimArray; i++ ){

  
      diferencia = (med > intArray[i]) ? pow(med-intArray[i], 2) : pow(intArray[i]-med, 2);
    
      prom += diferencia;

    }

    varianza = (prom / dimArray);

    desv = sqrt(varianza);
  }

  return desv;
}

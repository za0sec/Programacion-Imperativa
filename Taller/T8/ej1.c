#include <stdio.h>
#include <stdlib.h>
#include "../../libreria/getnum.h"
  
#define TOTAL_ITEMS 5
#define MAX_LONG 10
 
typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;
 
typedef tItem tFactura[TOTAL_ITEMS];
 
void cargar(tFactura f, int cant);
float importe(tFactura f, int cant);
tItem leerItem();

int main(void) {
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("%.2f", importe(f, TOTAL_ITEMS));
    return 0;
}



void cargar(tFactura f, int cant){
  
  for (int i=0; i<cant; i++){
    printf("Ingrese los datos de la factura N%d\n", i+1);
    f[i] = leerItem();
  }  
  
}

float importe(tFactura f, int cant){

  float sum = 0.0;

  for(int i=0; i<cant; i++)
    sum += f[i].precio;

    
  return sum;


}


tItem leerItem(){

  tItem item;

  item.codigo = getint("Ingrese codigo: ");
  
  printf("Ingrese descripcion: ");
  
  fgets(item.desc, MAX_LONG, stdin);

  item.precio = getfloat("Ingrese precio: ");

  return item;

}

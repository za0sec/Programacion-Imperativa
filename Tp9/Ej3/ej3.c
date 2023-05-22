/*Escribir una función recursiva productoEsc que reciba tres parámetros de entrada
 *representando dos vectores de números reales de igual tamaño y su dimensión. 
  La función debe regresar en su nombre el producto escalar de los vectores recibidos.
*/
#include <stdio.h>

int productoEsc(int * vector1, int * vector2, int dim);

int main(){

  int vector1[5] = {1,2, 9};
  int vector2[5] = {1,2, 2};
  int dimension = 3;

  printf("%d\n", productoEsc(vector1, vector2, dimension));

  return 0;
}

int productoEsc(int vector1[], int vector2[], int dim){

 if (dim == 0)
    return 0;

  return ((*vector1) * (*vector2)) + productoEsc(vector1+1, vector2+1, dim-1);


}

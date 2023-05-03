/*Escribir una función que reciba dos vectores de enteros y la dimensión de cada uno y retorne:
• 1 si todos los elementos del primer vector están en el segundo
• 2 si todos los elementos del segundo vector están en el primero
• 0 en caso contrario*/
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool belongs(int target, int v[], size_t dim);

int isHere(int v1[], size_t dim1, int v2[], size_t dim2);

int main(void) {

  int v1[] = {1,6,5,3,2};
  int v2[] = {1,2};
  assert(isHere(v1, 5, v2, 2)==2);
  assert(isHere(v2, 2, v1, 5)==1);
  assert(isHere(v1, 1, v2, 2)==1);
  assert(isHere(v1, 0, v2, 2)==1);
  assert(isHere(v1, 5, v2, 0)==2);
  
  int v3[] = {1,2,3,4,5,6};
  assert(isHere(v1, 5, v3, 6)==1);

  int cnt = isHere(v1, 0, v3, 0);
  assert(cnt ==1 || cnt==2);

  int v4[] = { 10, 20, 30, 1, 2};
  assert(isHere(v2, 2, v4, 4)==0);
  assert(isHere(v2, 2, v4, 5)==1);
  assert(isHere(v4, 5, v2, 2)==2);

  int v5[] = {1,1,1,1,1,2,1,2};
  int v6[] = {1,2,3};
  assert(isHere(v5, 8, v6, 3)==1);
  assert(isHere(v6, 3, v5, 8 )==2);

  printf("OK!\n");
  return 0;
}


bool belongs(int target, int v[], size_t dim){

  for (int i=0; i<dim; i++)
    if(target == v[i])
      return true;

  return false;

}



int isHere(int v1[], size_t dim1, int v2[], size_t dim2){

  int cont1=0;
  int cont2=0;

  for (int i=0; i<dim1; i++){
    if (belongs(v1[i], v2,dim2))
      cont1++;
  }
 
  if (cont1 == dim1)
    return 1;

 
  for (int i=0; i<dim2; i++){
    if (belongs(v2[i], v1,dim1))
      cont2++;
  }

  if (cont2 == dim2)
    return 2;

  return 0;

}

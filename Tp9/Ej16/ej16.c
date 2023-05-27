//Escribir la función recursiva orden que recibe como único parámetro un vector constante 
//de enteros mayores a cero, donde el final del mismo está marcado con el valor -1.
//	
//La función debe retornar:
//1: si el vector está ordenado en forma ascendente (cada elemento es mayor que el anterior)
//-1: si el vector está ordenado en forma descendente (cada elemento es menor al anterior)
//0 en cualquier otro caso
//
//Si no tiene elementos o tiene un único elemento se considera que no está ordenado.

#include <stdio.h>
#include <assert.h>

int orden(const int v[]);

int ordenRec(const int v[], int flag);



int main(void) {

  int v[] = {-1};
  assert(orden(v)==0);

  int v2[] = {1,-1};
  assert(orden(v2)==0);

  int v3[] = {1,2,-1};
  assert(orden(v3)==1);

  int v4[] = {1,2,3,10,100,999,2345,-1};
  assert(orden(v4)==1);

  int v5[] = {100,29,23,19,18,5,4,0,-1};
  assert(orden(v5)==-1);

  int v6[] = {1,2,3,10,100,999,998,-1};
  assert(orden(v6)==0);

  int v7[] = {1,2,3,10,1000,999,1998,-1};
  assert(orden(v7)==0);
  
  int v8[] = {1,1,1,10,1000,1999,2998,-1};
  assert(orden(v8)==0);

  printf ("OK!\n");
  return 0;
}


int orden(const int v[]){

  if (v[0] == -1 || v[1] == -1)
    return 0;
  
  return ordenRec(v, 0);

}

int ordenRec(const int v[], int flag){

  if (v[0] < v[1] && flag != 2){
    if (v[2] == -1){
      return 1;
    }
    return ordenRec(v+1, 1);
  }

  if (v[0] > v[1] && flag != 1){
    if (v[2] == -1){
      return -1;
    }
    return ordenRec(v+1, 2);
  }

  return 0;

}


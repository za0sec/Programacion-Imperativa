/*Escribir una función que reciba un vector desordenado de números enteros 
 *y su dimensión, y construya otro vector eliminando los valores repetidos.
 *La función deberá retornar en su nombre la dimensión del nuevo vector (La función solicitada  no debe superar las 10 líneas). */

#include <stdio.h>
#include <assert.h>

int eliminaRepetidos(const int vec[], unsigned int dim, int vec2[]);

int main(void) {
  int v[] = { 3, 5, 1, 3, -3, 3, 5, 1};
  int res[20];
  int dimRes;

  dimRes = eliminaRepetidos(v, 0, res);
  assert(dimRes==0);

  dimRes = eliminaRepetidos(v, 1, res);
  assert(dimRes==1);
  assert(res[0]==3);

  dimRes = eliminaRepetidos(v, 2, res);
  assert(dimRes==2);
  assert(res[0]==3);
  assert(res[1]==5);

  dimRes = eliminaRepetidos(v, 4, res);
  assert(dimRes==3);
  assert(res[0]==3);
  assert(res[1]==5);
  assert(res[2]==1);


  dimRes = eliminaRepetidos(v, 8, res);
  assert(dimRes==4);
  assert(res[0]==3);
  assert(res[1]==5);
  assert(res[2]==1);
  assert(res[3]==-3);

  for (int i=0; i < 8; i++)
     v[i] =10;
  dimRes = eliminaRepetidos(v, 8, res);
  assert(dimRes==1);
  assert(res[0]==10);

  for (int i=0; i < 8; i++)
     v[i] =i;
  dimRes = eliminaRepetidos(v, 8, res);
  assert(dimRes==8);
  for (int i=0; i < 8; i++)
    assert(res[i]==i);

  puts("\nOK!");
  return 0;
}


int eliminaRepetidos(const int vec[], unsigned int dim, int vec2[]){
  
  int j = 0;

  for ( int i=0; i<dim; i++ ){

    int cont = 0;

    for ( int k = 0; k<i && cont == 0; k++ ){

      if ( vec[i] == vec[k] ){

        cont++;

      }

    }
  
    if (cont == 0){

      vec2[j++] = vec[i];
    }

  }

  return j;

}

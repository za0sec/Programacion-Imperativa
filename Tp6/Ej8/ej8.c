/*
Repetir el ejercicio anterior, teniendo en cuenta que los arreglos de entrada 
pueden tener elementos repetidos, pero el de salida NO debe tener repeticiones.
*/

#include <stdio.h>
#include <assert.h>
#define END -1

int merge(const int vec[], const int vec1[], int res[]);

void check(const int v1[], const int v2[]) {
  int i;
  for(i=0; v1[i] != -1; i++)
     assert(v1[i]==v2[i]);
  assert(v1[i]==-1);
  assert(v2[i]==-1);
}

int main(void) {
  int v1[] = { 1, 5, 15, 15, 30, 35, 35, 35, 35, 35, 45, 55, -1};
  int v2[] = {-1};
  int v3[] = { 1, 1, 1, 1, 1, 1, -1};
  int v4[] = { 2, 3, 15, 16, 33, 35, 45, 65, -1};
  int dimRes;
  int res[30];

  int v1_v2[] = {1, 5, 15, 30, 35, 45, 55, -1};
  
  merge(v1, v2, res);
  check(v1_v2, res);

  merge(v2, v2, res);
  check(v2, res);

  merge(v1, v1, res);
  check(v1_v2, res);

  merge(v1, v3, res);
  check(v1_v2, res);

  int expected[] = {1, 2, 3, 5, 15, 16, 30, 33, 35, 45, 55, 65, -1};
  merge(v1, v4, res);
  check(expected, res);

  puts("OK!");
  return 0;
}


int merge(const int vec[], const int vec1[], int res[]){

  int j = 0, k = 0, i = 0;
  
  while (vec[i] != END || vec1[k] != END){

    while (vec[i] == vec[i+1]){

      i++;

    }
    
    while (vec1[k] == vec1[k+1]){

      k++;

    }

    if (vec[i] == END) {
    
      res[j++] = vec1[k++];

    } else if (vec1[k] == END) {
    
      res[j++] = vec[i++];
    
    } else if (vec[i] == vec1[k]){
    
      res[j++] = vec[i++];
      
      k++;
    
    } else if (vec[i] > vec1[k]){
    
      res[j++] = vec1[k++];
    
    } else if (vec[i] < vec1[k]){
    
      res[j++] = vec[i++];
    
    }
    
   
  }

  res[j] = END; 

//  for (int i=0; i<=j; i++ )
// printf("%d,", res[i] );

    return j;

}

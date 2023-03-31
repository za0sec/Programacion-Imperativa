#include <stdio.h>

int intersection(const int v1[], const int v2[], int v3[], unsigned int dim1, unsigned int dim2 ){

  int j = 0, k = 0;

  for ( int i=0; i<dim1 && k<dim2; i++ ){

    if ( v1[i] == v2[k] ){
    
        v3[j] = v1[i];
        j++;
        k++;
    }

  }
  return j;
}


int main(){

  int v1[] = {1,2,3,4,5,6,7,45,70,80};
  int dim1 = 10;
  int v2[] = {2,3,5,7,8,9,45};
  int dim2 = 7;

  int v3[dim1];

  int j = intersection(v1, v2, v3, dim1, dim2);

  for ( int i = 0; i<j; i++ ){
  printf("%d,", v3[i]);
  }
  puts("");
}

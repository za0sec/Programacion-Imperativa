#include <stdio.h>

int intersection(const int v1[], const int v2[], int v3[], unsigned int dim1, unsigned int dim2 ){

  int j = 0;

  for ( int i=0; i<dim1; i++ ){

    int flag = 0;

    for ( int k = 0; k<dim2 && flag == 0; k++  ){

      if ( v1[i] == v2[k] ){

        v3[j] = v1[i];
        j++;
        flag = 1;
      }

    }

  }
  return j;
}


int main(){

  int v1[] = {1,2,3,7,5,8,9};
  int dim1 = sizeof(v1)/sizeof(v1[0]);
  int v2[] = {4,3,6,2,1,7};
  int dim2 = sizeof(v2)/sizeof(v2[0]);

  int v3[dim1];

  int j = intersection(v1, v2, v3, dim1, dim2);

  for ( int i = 0; i<j; i++ ){
  printf("%d,", v3[i]);
  }
}

#include <stdio.h>

int intersection(const int v1[], const int v2[], int v3[], unsigned int dim1, unsigned int dim2 ){

  int j = 0, k = 0;

  for ( int i=0; (i<dim1 && k<dim2); i++ ){

    if ( v1[i] == v2[k] ){
    
        v3[j] = v1[i];
        j++;
        k++;
    }else if( v2[k] < v1[i] ){

      k++;
      i--;
    }

  }
  return j;
}


int main(){

  int v1[] = {2,3,5,7,8,9,45,50,54,56,57,58,59,70,71,73,75,80};
  int v2[] = {1,2,3,4,5,6,7,45,70,80};
  int dim1 = sizeof(v1)/sizeof(v1[0]);
  int dim2 = sizeof(v2)/sizeof(v2[0]);

  int v3[dim1];

  int j = intersection(v1, v2, v3, dim1, dim2);

  for ( int i = 0; i<j; i++ ){
  printf("%d,", v3[i]);
  }
  puts("");
}

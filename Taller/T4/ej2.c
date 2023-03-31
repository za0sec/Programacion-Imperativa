#include <stdio.h>


int dondeEsta(const int v[], unsigned int dim, int search, int pos[]){

  int j, i;

  for (i=0, j=0; i<dim && v[i] <= search; i++ ){

    if ( v[i] == search ){

      pos[j] = i;
      j++;
    }

  }
  
  
  return j;  
  
}


int main(){

  int v[] = {1,2,2,2,2,2,3,4,5,6,8};
  int search = 2;
  int dim = sizeof(v)/sizeof(v[0]);
  int pos[dim];
  

  int dimPos = dondeEsta(v, dim ,search, pos);

  for (int i=0; i<dimPos; i++){
    printf("%d,", pos[i]);
  }

}

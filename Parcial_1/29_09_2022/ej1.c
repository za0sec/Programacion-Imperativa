#include <stdio.h>
#include <assert.h>
#define N 4

int requirments(int mat[][N]);

int main(){

  int mat[N][N] = {{3,4,1,2},{8,7,6,5},{9,10,11,12},{15,16,13,14}};

  assert(requirments(mat)==1);

  int mat2[N][N] = {{3,1,1,2},{8,7,6,5},{9,10,11,12},{15,16,13,14}};

  assert(requirments(mat2)==0);

  int mat3[N][N] = {{3,1,4,2},{8,7,6,5},{9,10,11,12},{15,16,13,11}};

  assert(requirments(mat3)==0);

  puts("OK!");
  return 0;
}

int requirments(int mat[][N]){

  int vecAp[N*N] = {0};


  for(int i=0; i<N; i++){


    for (int j=0; j<N; j++){

      
      vecAp[mat[i][j]-1] = 1;
      
    }

    int sum=0;

    for (int t=i*N; t<(N*(i+1)); t++)
      sum += vecAp[t];

    if (sum != (N))
      return 0;


  }

   return 1;

}



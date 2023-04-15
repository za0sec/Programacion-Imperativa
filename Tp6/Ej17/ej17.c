#include <stdio.h>
#include <assert.h>
#include <math.h>

#define N 4
#define M 5


int armaFilas(int mat[][M], int vec[]);


int main(void)
{
     int m1[N][M] = { { 1,2,3,4,5},
                { 1,2,13,4,5},
                { 1,2,4,4,5},
                { 1,2,-3,4,5}};
    int vec[N];
    int n = armaFilas(m1, vec);
    assert(n==2);
    assert(vec[0]==12345);
    assert(vec[1]==12445);

    int m2[N][M] = { { 1,0,3,4,5},
                { 0,2,1,4,5},
                { 9,9,9,9,9},
                { 0,0,1,4,5}};
     n = armaFilas(m2, vec);
    assert(n==4);
    assert(vec[0]==10345);
    assert(vec[1]==2145);
    assert(vec[2]==99999);
    assert(vec[3]==145);


    int m3[N][M] = { { 11,0,3,4,5},
                { 0,2,1,14,5},
                { 9,9,9,91,9},
                { 0,0,1,14,5}};
     n = armaFilas(m3, vec);
    assert(n==0);
    

    printf("OK!\n");
    return 0;
}


int armaFilas(int mat[N][M], int vec[]){

 int nN = 0, num, j;
  

  for (int i=0; i<N; i++){

    num = 0;
  
    for (j=0; j<M && mat[i][j] < 10 && mat[i][j] >= 0; j++){
      
      num *= 10;
      num += (mat[i][j]);


    }
   

      if ( j == M )
        vec[nN++] = num;
      
  }

  return nN;

}



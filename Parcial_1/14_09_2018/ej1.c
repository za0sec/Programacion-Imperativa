#include <stdio.h>
#define M 5
#define N 4
#include <assert.h>
int returnFila(int mat[][M]);



int main(void)
{
     int m1[N][M] = { { 1,2,3,4,5},
                { 1,2,13,4,5},
                { 1,2,4,4,5},
                { 1,2,-3,4,5}};
    int n = returnFila(m1);
    assert(n == 12445);

    int m2[N][M] = { { 1,0,3,4,5},
                { 0,2,1,4,5},
                { 9,9,9,9,9},
                { 0,0,1,4,5}};
     n = returnFila(m2);
    assert(n==99999);


    int m3[N][M] = { { 11,0,3,4,5},
                { 0,2,1,14,5},
                { 9,9,9,91,9},
                { 0,0,1,14,5}};
     n = returnFila(m3);
    assert(n==-1);
    

    printf("OK!\n");
    return 0;
}


int returnFila(int mat[][M]){

  int max = 0, num, cont=0;
  //verifico los numeros:
  for (int i=0; i<N; i++){

    num=0;

    for (int j=0; j<M; j++){

      if (mat[i][j] >=0 && mat[i][j] <=9){

        num *=10; 
        num += mat[i][j];

      }else{

        cont++;

      }
        

    }

  if (max < num)
    max = num;

  }

  if (cont == N)
    return -1;
  else
    return max;

}

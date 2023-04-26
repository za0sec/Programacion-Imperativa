#include <stdio.h>
#define DIM 3

int esAscendente(int mat[][DIM], int vec[]);

int main(void){
  

  int vec[DIM*DIM];


    int m1[][DIM] = {
		{-6,-5,2},
		{7,9,9},
		{21,32,45}
	}; // m1 es ascendente

 int n = esAscendente(m1, vec);
	
  if (n)
    for(int i=0; i<n; i++)
      printf("%d ", vec[i]);
  else
    puts("\nla mat no es ascendente");

  puts("");

  int m2[][DIM] = {
		{1,1,1},
		{1,1,1},
		{1,1,1}
	}; // m2 es descendente

  n = esAscendente(m2, vec);
	
  if (n)
    for(int i=0; i<n; i++)
      printf("%d ", vec[i]);
  else
    puts("\nla mat no es ascendente");


  return 0;
}

int esAscendente(int mat[][DIM], int vec[]){

  int i, j, t;

  for(i=t=0; i<DIM; i++){


    for (j=0; (j<DIM); j++){

      
      if (j==DIM-1 && i == (DIM-1) && mat[i][j] < mat[i][j-1])
        return 0;

      if ((j == (DIM -1) && i < (DIM-1) && mat[i][j] > mat[i+1][0]) || (mat[i][j] > mat[i][j+1] && i+j !=(DIM+DIM-2)) ){
        
        return 0;
        
      }

      

        if (mat[i][j] != mat[i][j+1]){

          vec[t++] = mat[i][j];

        }

    }


  }

    return t;

}


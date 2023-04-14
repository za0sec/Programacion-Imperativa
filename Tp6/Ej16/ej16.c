#include <stdio.h>
#include <assert.h>
enum codes {ASC=1, DESC, NOTHING};

#define FILS 3
#define COLS 4

int check(int mat[FILS][COLS], int i, int j);

int ordered(int mat[FILS][COLS]);

int main(void){
    int m1[][COLS] = {
		{-6,-5,2,6},
		{7,9,9,14},
		{21,32,45,46}
	}; // m1 es ascendente

  assert(ordered(m1)==1);
	int m2[][COLS] = {
		{19,13,12,8},
		{7,7,5,-1},
		{-6,-10,-14, -16}
	}; // m2 es descendente
assert(ordered(m2)==-1);

	int m3[][COLS] = {
		{-6,-5,-6,6},
		{7,9,10,14},
		{21,32,45,46}
	}; // m3 no es ascendente ni descendente
  assert(ordered(m3)==0);
	
	int m4[][COLS] = {
		{19,13,18,8},
		{7,5,2,-1},
		{-6,-10,-14}
	}; // m4 no es ascendente ni descendente
  assert(ordered(m4)==0);

int m5[][COLS] = {
		{1,1,1,1},
		{1,1,1,1},
		{1,1,1,1}
	}; // m5 es ascendente y descendente. La funciÃ³n podrÃ­a devolver 1 Ã³ -1
  int respM5 =  ordered(m5);
  assert(respM5==1 || respM5 == -1);
  
  int m6[][COLS] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,10}
	}; 
  int respM6 =  ordered(m6);
  assert(respM6 == 0);
  
  int m7[][COLS] = {
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
	}; 
  int respM7 =  ordered(m7);
  assert(respM7 == 0);

  
	int m8[][COLS] = {
		{19,19,12,8},
		{7,7,5,-1},
		{-6,-10,-14, -16}
	}; // m2 es descendente
    assert(ordered(m8)==-1);

   int m9[][COLS] = {
		{-6,-6,-6,6},
		{7,9,9,14},
		{21,32,45,46}
	}; 
	   assert(ordered(m9)==1);
	   
    puts("OK");
    return 0;
}




int ordered(int mat[FILS][COLS]){

  int contA = 0, contD = 0;

  for ( int i=0; i<FILS; i++ ){

    for ( int j=0; j<COLS; j++ ){

      switch (check(mat, i, j)){

        case ASC:
          contA++;
          break;
        case DESC:
          contD++;
          break;
        case NOTHING:
          contA++;
          contD++;
          break;
      }

    }

  }

  if ( contA == (COLS*FILS) )
    return 1;
  else if ( contD == (COLS*FILS) )
    return -1;
  else{
    return 0;
  }

}

int check(int mat[FILS][COLS], int i, int j){


  int nI = (j == COLS-1 && i != FILS-1) ? i+1 : i;
  int nJ = (j == COLS-1 ) ? 0 : j+1;
    
  if ( i == FILS-1 && j == COLS-1 ){  
    nJ = j;
  }

  if ( mat[i][j] < mat[nI][nJ] )
    return ASC;
  else if ( mat[i][j] > mat[nI][nJ] )
    return DESC;
  else
    return NOTHING;

}

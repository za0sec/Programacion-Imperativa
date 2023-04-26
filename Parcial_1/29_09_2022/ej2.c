#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define N 6

int palEnMat(const char mat[][N], int fil, int col, char * str);

bool esString(const char mat[][N], int posI, int posJ, int incI, int incJ, char * s, int c);

int main(){


  const char mat[][N] = {
        {'L', 'O', 'B', 'R', 'A', 'Z'},
        {'F', 'H', 'R', 'G', 'O', 'R'},
        {'C', 'O', 'S', 'A', 'D', 'A'},
        {'R', 'L', 'A', 'H', 'N', 'N'},
        {'W', 'A', 'O', 'Y', 'U', 'T'},
        {'Q', 'S', 'G', 'S', 'M', 'A'}};

  char str[] = {"SAL"};
  assert(palEnMat(mat, 5, 1, str)==1);
  
  char str2[] = {"COSA"};
  assert(palEnMat(mat, 2, 0, str2)==1);

  char str3[] = {"CHB"};
  assert(palEnMat(mat, 2, 0, str3)==1);

  char str4[] = {"CLOS"};
  assert(palEnMat(mat, 2, 0, str4)==1);

  char str5[] = {""};
  assert(palEnMat(mat, 2, 0, str5)==1);

  char str6[] = {"C"};
  assert(palEnMat(mat, 2, 0, str6)==1);

  char str7[] = {"sal"};
  assert(palEnMat(mat, 5, 1, str7)==0);

  char str8[] = {"SALA"};
  assert(palEnMat(mat, 5, 1, str8)==0);

  char str9[] = {"COSADAS"};
  assert(palEnMat(mat, 2, 0, str9)==0);

  char str10[] = {"SALA"};
  assert(palEnMat(mat, 6, 1, str10)==0);

  puts("OK!");

}



int palEnMat(const char mat[][N], int fil, int col, char * str){


  int matPos[2][8] = {{0, -1, -1, -1, 0, 1, 1, 1},
                      {1, 1, 0, -1, -1, -1, 0, 1}};

  int c = strlen(str);

  for (int j=0; j<8; j++){

    
    if (esString(mat, fil, col, matPos[0][j], matPos[1][j], str, c))
      return 1;

  }

  return 0;
}



bool esString(const char mat[][N], int posI, int posJ, int incI, int incJ, char * s, int c){

  int i,j, t=0;

  for (i=posI, j=posJ; i>=0 && i<N && j>=0 && j<N && c!=t; i+=incI, j+=incJ ){

    if (s[t] == mat[i][j]){
      t++;
    }else{
      return false;
    }
      
  }
  
  if (t == c) 
    return true;

  return false;

}

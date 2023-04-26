#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5

int elimVocales(char * s, int mat[][5], int fil);

int fillMat(int mat[][5], int fil, int vec[5], int pos, int upper, const char * str);

int main(void) {
  int m[6][CANT_VOCAL];
  char s[] = "las buenas ideas escasean, si";
  assert(elimVocales(s, m, 6)==EXITO);
  assert(strcmp(s, "ls bns ds scsn, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == 23);
  assert(m[5][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  strcpy(s, "las buenas ideas escasean, si");
  assert(elimVocales(s, m, 1)==ERROR);
  assert(strcmp(s, "las buenas ideas escasean, si")==0);
  assert(m[0][0]==-1);
  assert(m[0][1]==-1);
  assert(m[0][2]==-1);
  assert(m[0][3]==-1);
  assert(m[0][4]==-1);
  assert(elimVocales(s, m, 5)==ERROR);
  assert(strcmp(s, "ls bns ds scsan, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  printf("OK!\n");
  return 0;
}
int elimVocales(char * s, int mat[][5], int fil){
 
  int error=0, i, j;
  
  //inicializo en -1 la mat para sacar basura y no tener que recorrer la ultima fila de cada columna.
  for (int i=0; i<fil; i++)
    for(int j=0; j<5; j++)
      mat[i][j] = -1;

  int vec[5] = {0};
  char str[] = {"AEIOU"};

  for (i=0, j=0; s[i] != '\0'; i++){
    int upper = toupper(s[i]);

    if (upper == 'A' || upper == 'E' || upper == 'I' || upper == 'O' || upper == 'U' ){

      if (fillMat(mat, fil, vec, i, upper, str)){
        s[j++] = s[i];
        error = 1;
      }
    }else {
      s[j++] = s[i];
    }
  }

  s[j] = '\0';
  
  if (error) {
    return ERROR;
  } else {
    return EXITO;
  }  
}


int fillMat(int mat[][5], int fil, int vec[5], int pos, int upper, const char * str){

  for (int i=0; i<5; i++){
    if (upper == str[i]){
      if (vec[i] < fil-1){
        mat[vec[i]++][i] = pos;
     }else{
        return 1;
      }
    }
  }
  return 0;
}


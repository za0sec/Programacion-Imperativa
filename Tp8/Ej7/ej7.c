#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define COLS 7
#define FILS 6

#define CHUNK 10


typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
};

struct posicion * resolverSopa(char * word[], char mat[][COLS]);

int isLetter(char mat[][COLS], char * word , int * f, int * c, Tdireccion * direction);

int isWord(char mat[][COLS], char * word, int i, int j, Tdireccion * direction);

void directions(Tdireccion dir, int * i, int * j);


// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra se busca en la sopa de 
//       letras.
//.      Si en vez de hacerlo así recorren la matriz y por cada letra buscan si hay una palabra en el diccionario
//       que empiece con esa letra, tienen que cambiar el testeo para que coincida con el orden en que se encuentran.


int main(void) {
  char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
   
  char sopa[FILS][COLS] =
     {{'X','X','X','O','X','X','X'},
      {'A','P','A','C','Y','Y','O'},
      {'Z','E','Z','R','Z','C','X'},
      {'E','R','R','O','R','X','X'},
      {'X','R','I','O','I','E','X'},
      {'X','O','X','X','O','X','X'}};
  
  struct posicion * res = resolverSopa(diccionario, sopa);
  // La cantidad de palabras encontradas debe ser 9
  int expected = 9;
  int count = 0;
  while ( res[count].palabra != NULL)
     printf("%s\n", res[count++].palabra);
  assert(count == expected);

  assert(strcmp(res[0].palabra,"ARRE")==0);
  assert(res[0].fila==1);
  assert(res[0].columna==2);
  assert(res[0].direccion==D_AB);

  assert(strcmp(res[3].palabra,"ORCO")==0);
  assert(res[3].fila==3);
  assert(res[3].columna==3);
  printf("%d\n", res[3].direccion);
  assert(res[3].direccion==ARR);
  
  assert(strcmp(res[4].palabra,"ORCO")==0);
  assert(res[4].fila==4);
  assert(res[4].columna==3);
  assert(res[4].direccion==D_AR);

  assert(strcmp(res[6].palabra,"REA")==0);
  assert(res[6].fila==3);
  assert(res[6].columna==2);
  assert(res[6].direccion==I_AR);

  free(res);

  puts("OK");
  return 0;
}


struct posicion * resolverSopa(char * word[], char mat[][COLS]){

  struct posicion * res = NULL;  
  int f=0, c=0, k=0;

  Tdireccion direction;

  for (int i=0; word[i][0]; i++){

    if(k%CHUNK == 0){
      res = realloc(res, (k+CHUNK)*sizeof(struct posicion));
    }

    if ( isLetter(mat, word[i], &f, &c, &direction) ){
      res[k].palabra = word[i];
      res[k].fila = f;
      res[k].columna = c;
      res[k].direccion = direction;
      k++; 
    }

  }

  res[k].palabra = NULL;

  res = realloc(res, (k+1)*sizeof(struct posicion));

  return res; 

}

int isLetter(char mat[][COLS], char * word , int * f, int * c, Tdireccion * direction){

  for (int i=0; i<FILS; i++){

    for (int j = 0; j < COLS; j++) {
    
      if (mat[i][j] == word[0] && isWord(mat, word, i, j, direction)) {
        *f = i;
        *c = j;
        return 1;
      }
    }
  }

  return 0;

}

int isWord(char mat[][COLS], char * word, int i, int j, Tdireccion * direction) {
  int nI, nJ, k;
  int dim = strlen(word);
  for (Tdireccion dir = DER; dir <= D_AB; dir++) {
    k = 0;
    nI = i;
    nJ = j;
    
   
while (nI >= 0 && nI < FILS && nJ >= 0 && nJ < COLS && word[k] == mat[nI][nJ] && k < dim){
  directions(dir, &nI, &nJ);
  k++;
}
    
    if (k == dim){
      *direction = dir;
      return 1;
    }
    
  }

  return 0;
}
void directions(Tdireccion dir, int * i, int * j){

  switch (dir) {
    case DER:
      (*j)++;
      break;
    case IZQ:
      (*j)--;
      break;
    case ABA:
      (*i)++;
      break;
    case ARR:
      (*i)--;
      break;
    case I_AR:
      (*i)--;
      (*j)--;
      break;
    case I_AB:
      (*i)++;
      (*j)--;
      break;
    case D_AR:
      (*i)--;
      (*j)++;
      break;
    case D_AB:
      (*i)++;
      (*j)++;
      break;
  }

}

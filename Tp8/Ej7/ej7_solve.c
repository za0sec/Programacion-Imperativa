#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define COLS 20
#define FILS 20

#define CHUNK 10


typedef enum {DER=1, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

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
  char * diccionario[] = {
    "ANDADOR", "APELAR", "APENAS", "CUELLO", "EGRESAR", "ESBELTO", 
    "GUIAR", "HABLA", "ISLETA", "LICOR", "PACTO", "PORTERA", 
    "POSE", "PUERTORRIQUENO", "REALCE", "RIZO", "TALLO", "TENSO", 
    "UNICO", "UNISONO", ""
  };
   
  char sopa[FILS][COLS] = {
    {'K', 'A', 'W', 'O', 'S', 'Q', 'C', 'U', 'E', 'L', 'L', 'O', 'L', 'A', 'O', 'H', 'G', 'Q', 'E', 'U'},
    {'O', 'R', 'F', 'B', 'A', 'A', 'I', 'O', 'Z', 'J', 'C', 'O', 'K', 'S', 'W', 'T', 'B', 'S', 'S', 'O'},
    {'Y', 'H', 'O', 'O', 'U', 'R', 'T', 'I', 'F', 'X', 'W', 'K', 'L', 'E', 'I', 'Y', 'O', 'E', 'B', 'G'},
    {'D', 'A', 'A', 'D', 'H', 'N', 'E', 'U', 'N', 'I', 'S', 'O', 'N', 'O', 'X', 'P', 'S', 'D', 'T', 'X'},
    {'H', 'B', 'K', 'T', 'A', 'U', 'I', 'T', 'A', 'H', 'H', 'H', 'M', 'U', 'F', 'U', 'S', 'R', 'Q', 'O'},
    {'U', 'L', 'X', 'X', 'T', 'D', 'D', 'C', 'R', 'J', 'E', 'L', 'K', 'E', 'O', 'E', 'G', 'H', 'C', 'L'},
    {'E', 'A', 'Z', 'K', 'X', 'A', 'N', 'G', 'O', 'O', 'E', 'O', 'X', 'A', 'G', 'R', 'H', 'E', 'I', 'I'},
    {'D', 'F', 'P', 'D', 'S', 'R', 'O', 'A', 'L', 'A', 'P', 'R', 'D', 'A', 'T', 'T', 'I', 'T', 'D', 'C'},
    {'R', 'A', 'I', 'U', 'G', 'O', 'W', 'R', 'S', 'A', 'E', 'H', 'K', 'J', 'A', 'O', 'A', 'E', 'E', 'O'},
    {'Q', 'A', 'T', 'E', 'L', 'S', 'I', 'K', 'P', 'A', 'E', 'E', 'S', 'P', 'P', 'R', 'Z', 'N', 'A', 'R'},
    {'W', 'I', 'E', 'Z', 'J', 'I', 'N', 'E', 'L', 'Z', 'U', 'Z', 'A', 'X', 'E', 'R', 'X', 'S', 'S', 'W'},
    {'L', 'X', 'G', 'D', 'V', 'B', 'N', 'C', 'M', 'K', 'U', 'C', 'N', 'N', 'L', 'I', 'F', 'O', 'O', 'A'},
    {'U', 'H', 'R', 'O', 'S', 'A', 'E', 'Q', 'G', 'H', 'T', 'Y', 'X', 'T', 'A', 'Q', 'I', 'F', 'U', 'R'},
    {'B', 'E', 'E', 'F', 'S', 'Q', 'Y', 'A', 'G', 'O', 'Y', 'U', 'U', 'R', 'R', 'U', 'W', 'Z', 'I', 'Q'},
    {'B', 'T', 'S', 'T', 'B', 'A', 'U', 'K', 'U', 'Y', 'R', 'U', 'U', 'X', 'D', 'E', 'Y', 'Z', 'X', 'S'},
    {'U', 'K', 'A', 'C', 'K', 'W', 'T', 'G', 'O', 'J', 'U', 'R', 'J', 'T', 'Y', 'X', 'O', 'U', 'V', 'A'},
    {'R', 'X', 'R', 'E', 'Z', 'A', 'A', 'E', 'Y', 'E', 'X', 'I', 'L', 'I', 'I', 'O', 'W', 'V', 'U', 'L'},
    {'X', 'C', 'U', 'A', 'K', 'M', 'L', 'I', 'E', 'A', 'N', 'X', 'E', 'A', 'Z', 'L', 'O', 'U', 'U', 'N'},
    {'D', 'P', 'Z', 'A', 'I', 'P', 'L', 'F', 'K', 'T', 'V', 'R', 'C', 'S', 'U', 'M', 'N', 'X', 'Z', 'H'},
    {'Q', 'F', 'D', 'U', 'J', 'D', 'O', 'L', 'O', 'A', 'K', 'E', 'S', 'B', 'E', 'L', 'T', 'O', 'O', 'Z'}
};  

  struct posicion * res = resolverSopa(diccionario, sopa);
  
  int expected = 19; 
  int count = 0;
  while (res[count].palabra != NULL) {
    printf("Palabra: %s, Fila: %ld, Columna: %ld, Direccion: %d\n",
           res[count].palabra,
           res[count].fila+1,
           res[count].columna+1,
           res[count].direccion);
    count++;
  }
  assert(count == expected);

  free(res);

  puts("OK");
  return 0;
}




struct posicion * resolverSopa(char * word[], char mat[][COLS]){

  struct posicion * res = NULL;  
  int * f = calloc(CHUNK, sizeof(int)); 
  int * c = calloc(CHUNK, sizeof(int)); 
  int k=0, counter = 0, j;

  Tdireccion * direction = calloc(CHUNK, sizeof(int));

  for (int i=0; word[i][0]; i++){

    counter = isLetter(mat, word[i], f, c, direction);

    for (j=0; j<counter; j++){

      if(k%CHUNK == 0){
        res = realloc(res, (k+CHUNK)*sizeof(struct posicion));
        f = realloc(f, (k+CHUNK)*sizeof(int));
        c = realloc(c, (k+CHUNK)*sizeof(int));
        direction = realloc(direction, (k+CHUNK)*sizeof(Tdireccion));
      }

      res[k].palabra = word[i];
      res[k].fila = f[j];
      res[k].columna = c[j];
      res[k].direccion = direction[j];
      k++; 
    }

  }

  res[k].palabra = NULL;

  res = realloc(res, (k+1)*sizeof(struct posicion));
  f = realloc(f, (j+1)*sizeof(int));
  c = realloc(c, (j+1)*sizeof(int));
  direction = realloc(direction, (j+1)*sizeof(Tdireccion));

  free(f);
  free(c);
  free(direction);
  

  return res; 

}

int isLetter(char mat[][COLS], char * word , int * f, int * c, Tdireccion * direction){

  int count=0, dir;

  for (int i=0; i<FILS; i++){

    for (int j = 0; j < COLS; j++) {
    
      if (mat[i][j] == word[0] && (dir = isWord(mat, word, i, j, direction)) ) {
        f[count] = i;
        c[count] = j;
        direction[count] = dir;
        count++;
      }
    }
  }

  return count;

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
      return dir;
    }
    
  }

  return 0;
}

//Esta funcion no se hace asi simplemente queria probar otra forma de hacerlo y el chelo me la tiro abajo.
//Se hace con vector de direcciones.
//Ahora me da paja cambiarlo.
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

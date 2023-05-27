#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define COLS 25
#define FILS 25

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
    "ELECTROCARDIOGRAMA", "INTERNACIONALIZACION", "INCONSTITUCIONALIDAD", "OTORRINOLARINGOLOGIA", "ELECTRODOMESTICOS", 
    "INCONMENSURABILIDAD", "PARALELEPIPEDO", "INTRANSIGENTE", "DESOXIRRIBONUCLEICO", "IDIOSINCRASICO", 
    "FILOSOFIA", "JEROGLIFICO", "POLIURETANO", "INSUSTITUIBLE", "ELECTROQUIMICA", "RADIOTRANSMISOR",
    "ZOOGEOGRAFIA", "PERPENDICULARIDAD", "ANTICONSTITUCIONAL", "NEUROFISIOLOGIA", "MULTIDIMENSIONAL", 
    "IMPRESCINDIBLE", "INSUPERABLE", ""
};
   
  char sopa[FILS][COLS] = {
  {'L', 'A', 'N', 'O', 'I', 'C', 'U', 'T', 'I', 'T', 'S', 'N', 'O', 'C', 'I', 'T', 'N', 'A', 'S', 'N', 'P', 'O', 'E', 'L', 'A'},
  {'Z', 'Z', 'E', 'L', 'T', 'P', 'D', 'Z', 'R', 'K', 'W', 'I', 'O', 'N', 'G', 'S', 'Z', 'M', 'O', 'Y', 'W', 'T', 'T', 'U', 'C'},
  {'I', 'I', 'N', 'C', 'O', 'N', 'S', 'T', 'I', 'T', 'U', 'C', 'I', 'O', 'N', 'A', 'L', 'I', 'D', 'A', 'D', 'O', 'N', 'J', 'I'},
  {'W', 'D', 'O', 'N', 'A', 'T', 'E', 'R', 'U', 'I', 'L', 'O', 'P', 'P', 'R', 'C', 'C', 'S', 'P', 'S', 'X', 'R', 'E', 'W', 'M'},
  {'E', 'I', 'I', 'F', 'I', 'F', 'E', 'A', 'A', 'H', 'X', 'C', 'R', 'O', 'B', 'A', 'V', 'B', 'H', 'A', 'U', 'R', 'G', 'C', 'I'},
  {'N', 'L', 'E', 'O', 'G', 'N', 'Q', 'A', 'A', 'X', 'X', 'F', 'S', 'Q', 'Z', 'M', 'L', 'G', 'F', 'I', 'O', 'I', 'I', 'P', 'U'},
  {'M', 'Q', 'B', 'N', 'S', 'B', 'S', 'F', 'L', 'G', 'Q', 'I', 'I', 'I', 'I', 'A', 'M', 'U', 'J', 'G', 'Q', 'N', 'S', 'E', 'Q'},
  {'B', 'O', 'P', 'I', 'J', 'I', 'M', 'U', 'S', 'E', 'M', 'Z', 'L', 'M', 'N', 'R', 'T', 'X', 'L', 'O', 'E', 'O', 'N', 'R', 'O'},
  {'P', 'L', 'D', 'M', 'U', 'A', 'N', 'P', 'P', 'S', 'F', 'A', 'E', 'O', 'C', 'G', 'M', 'I', 'H', 'L', 'B', 'L', 'A', 'P', 'R'},
  {'V', 'R', 'Z', 'E', 'I', 'T', 'F', 'C', 'N', 'E', 'N', 'L', 'I', 'T', 'Y', 'O', 'F', 'R', 'E', 'O', 'G', 'A', 'R', 'E', 'T'},
  {'B', 'W', 'C', 'P', 'P', 'M', 'I', 'A', 'R', 'O', 'R', 'S', 'O', 'C', 'U', 'I', 'U', 'C', 'S', 'I', 'H', 'R', 'T', 'N', 'C'},
  {'A', 'C', 'T', 'R', 'B', 'I', 'R', 'T', 'I', 'A', 'N', 'A', 'S', 'J', 'C', 'D', 'T', 'K', 'R', 'S', 'X', 'I', 'N', 'D', 'E'},
  {'I', 'Y', 'G', 'T', 'F', 'T', 'P', 'C', 'S', 'E', 'S', 'E', 'B', 'O', 'Z', 'R', 'N', 'J', 'S', 'I', 'U', 'N', 'I', 'I', 'L'},
  {'I', 'W', 'P', 'J', 'O', 'V', 'A', 'E', 'M', 'U', 'B', 'I', 'C', 'L', 'O', 'A', 'F', 'C', 'R', 'F', 'Y', 'G', 'S', 'C', 'E'},
  {'J', 'O', 'Y', 'I', 'J', 'N', 'O', 'I', 'L', 'L', 'S', 'Q', 'C', 'D', 'E', 'C', 'I', 'D', 'N', 'O', 'F', 'O', 'B', 'U', 'M'},
  {'N', 'R', 'D', 'O', 'R', 'A', 'D', 'T', 'I', 'E', 'U', 'N', 'O', 'O', 'V', 'O', 'L', 'G', 'U', 'R', 'M', 'L', 'N', 'L', 'J'},
  {'J', 'A', 'V', 'E', 'P', 'I', 'Q', 'Q', 'B', 'T', 'L', 'M', 'I', 'F', 'S', 'R', 'O', 'Q', 'G', 'U', 'R', 'O', 'Y', 'A', 'B'},
  {'R', 'R', 'T', 'E', 'T', 'A', 'Z', 'R', 'I', 'D', 'E', 'A', 'Z', 'Q', 'Q', 'T', 'S', 'E', 'V', 'E', 'Z', 'G', 'G', 'R', 'O'},
  {'B', 'N', 'W', 'L', 'F', 'S', 'Y', 'Q', 'P', 'S', 'X', 'A', 'R', 'O', 'W', 'C', 'O', 'E', 'N', 'N', 'C', 'I', 'F', 'I', 'G'},
  {'I', 'G', 'U', 'Q', 'W', 'L', 'O', 'F', 'T', 'B', 'B', 'N', 'L', 'A', 'A', 'E', 'F', 'L', 'L', 'F', 'G', 'A', 'N', 'D', 'P'},
  {'I', 'M', 'P', 'R', 'E', 'S', 'C', 'I', 'N', 'D', 'I', 'B', 'L', 'E', 'P', 'L', 'I', 'M', 'C', 'P', 'Y', 'I', 'A', 'A', 'G'},
  {'L', 'D', 'B', 'K', 'W', 'I', 'C', 'J', 'K', 'P', 'J', 'F', 'I', 'D', 'F', 'E', 'A', 'E', 'X', 'V', 'T', 'W', 'L', 'D', 'O'},
  {'L', 'Z', 'G', 'D', 'M', 'O', 'D', 'A', 'D', 'I', 'L', 'I', 'B', 'A', 'R', 'U', 'S', 'N', 'E', 'M', 'N', 'O', 'C', 'N', 'I'},
  {'S', 'X', 'D', 'E', 'S', 'O', 'X', 'I', 'R', 'R', 'I', 'B', 'O', 'N', 'U', 'C', 'L', 'E', 'I', 'C', 'O', 'K', 'T', 'P', 'V'},
  {'Z', 'O', 'O', 'G', 'E', 'O', 'G', 'R', 'A', 'F', 'I', 'A', 'X', 'H', 'O', 'N', 'O', 'X', 'O', 'M', 'V', 'C', 'U', 'H', 'M'}
  };  

  struct posicion * res = resolverSopa(diccionario, sopa);
  
  int expected = 23; 
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

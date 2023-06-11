#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "rankingADT.h"


static int compare(char * source, char * target) {
   return strcmp(source, target);
}

// Utilizamos char * como elemType strcmp como compare
int main(void) {
  rankingADT r = newRanking(NULL, 0, compare);
  addRanking(r, "Footloose");
  addRanking(r, "Yesterday");
  addRanking(r, "La bamba");
  addRanking(r, "Sucio y desprolijo");
  addRanking(r, "Ride of the Valkyries");
  addRanking(r, "Yesterday");
  addRanking(r, "Ride of the Valkyries");

  char * aux = "default";
  int n;
  n = getByRanking(r, 6, &aux);
  assert( n == 0 && !strcmp(aux, "default") );

  n = getByRanking(r, 1, &aux); 
  assert( n == 1 && !strcmp(aux, "Yesterday") );

  n = getByRanking(r, 0, &aux); 
  assert( n == 0 && !strcmp(aux, "Yesterday") );

  n = getByRanking(r, 2, &aux); 
  assert( n == 1 && !strcmp(aux, "Footloose") );

  n = getByRanking(r, 1, &aux); 
  assert( n == 1 && !strcmp(aux, "Footloose") );
 
  assert( contains(r, "Ride of the Valkyries") ); 
  assert( contains(r, "Sucio y desprolijo") ); 
  assert( contains(r, "Desarma y sangra") == 0 );

  size_t dimTop = 10;
  char ** top = getTopRanking(r, &dimTop);
  assert(dimTop == 5 && !strcmp(top[0], "Footloose") && !strcmp(top[1], "Yesterday"));
  assert(!strcmp(top[2], "Ride of the Valkyries") && !strcmp(top[3], "Sucio y desprolijo"));
  assert(strcmp(top[4], "La bamba") == 0);
  free(top);

  downByRanking(r, 1);
  dimTop = 2;
  top = getTopRanking(r, &dimTop);
  assert( dimTop == 2 && !strcmp(top[0], "Yesterday") && !strcmp(top[1], "Footloose") );

  free(top);
  freeRanking(r);
  puts("OK!");
  return 0;
}

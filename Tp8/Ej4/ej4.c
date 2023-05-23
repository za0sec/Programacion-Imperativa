/*Simular un juego de naipes de 52 cartas, en el cual se mezcle el mazo y se tomen las 5 primeras cartas, 
 *indicando si se obtuvo alguna de las siguientes configuraciones:
PAR:  hay sólo dos de las cinco cartas con igual valor
PIERNA:  hay sólo tres de las cinco cartas de igual valor
POKER: hay cuatro cartas con igual valor
*/

#include <stdio.h>
#include "../../libreria/random.h"
#include <string.h>

#define MAX_CARDS 13
#define PALO 4
#define CHOSEN 5

enum TYPE {PAR=1, PIERNA, POKER};


typedef struct tCards{

  int palo;
  int valor;

}tCards;

int check(tCards * cartas);




tCards * shuffle(tCards * deck);

int main(){

  randomize();
  
  tCards card;

  char * palito[] = {"Diamante", "Corazon", "Trebol", "Picas"};

  char *num[] = {"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "Jota", "Reina", "Rey"};

  tCards deck[PALO*MAX_CARDS];

  for (int i=0; i<PALO; i++){
    for (int j=0; j<MAX_CARDS; j++){
      card.palo = i;
      card.valor = j;
      deck[i*MAX_CARDS+j] = card;
    }
  }

  tCards * cartas = shuffle(deck);

  int whatIs = check(cartas);

  for(int i=0; i<CHOSEN; i++)
    printf("%s de %s\n", num[cartas[i].valor], palito[cartas[i].palo]);

  return whatIs;

}



int check(tCards * cartas){
  
  int ret=0;

  int vecAp[MAX_CARDS] = {0};
  
  for (int i=0; i<CHOSEN; i++){

    vecAp[cartas[i].valor]++;

  }
  
  for (int i=0; i<MAX_CARDS; i++){
    if (vecAp[i] == 2)
      ret = PAR;
    else if (vecAp[i] == 3)
      ret = PIERNA;
    else if (vecAp[i] >= 4)
      ret = POKER;
  }

  return ret;
  
}


tCards * shuffle(tCards * deck){
  
  tCards * cartas = malloc(CHOSEN*sizeof(tCards));
  
  int nI, nJ;

  for (int i=0; i<CHOSEN; i++){
    do {
      nI = randInt(0,PALO-1);
      nJ = randInt(0,MAX_CARDS-1);
    } while(deck[nI * MAX_CARDS + nJ].valor == -1);

    cartas[i] = deck[nI * MAX_CARDS + nJ];
    deck[nI * MAX_CARDS + nJ].valor = -1;
  }
  return cartas;
}


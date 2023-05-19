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
#define PLAYERS 2

enum TYPE {PAR=1, PIERNA, POKER};


typedef struct tCards{

  int palo;
  int valor;

}tCards;

int check(tCards * cartas);

tCards * shuffle(tCards * deck);

void print(tCards * cartas1, tCards * cartas2);



int main(){
  
  
  randomize();
  
  tCards card;

  
  tCards deck[PALO*MAX_CARDS];

  for (int i=0; i<PALO; i++){
    for (int j=0; j<MAX_CARDS; j++){
      card.palo = i;
      card.valor = j;
      deck[i*MAX_CARDS+j] = card;
    }
  }

  int n = 0;
  char c;

  while(!n){
   
    play(deck); 
    puts("Presione enter para seguir jugando, Presione n para cortar.");
    
    if ( (c =getchar()) == 'n')
      n = 1;

  }

  
  //free(cartas1);
  //free(cartas2);



  return 0;

}

int play(tCards deck[]){

  tCards * cartas1;

  int cont1=0, cont2=0;

  tCards * cartas2;
  
  int whatIs1, whatIs2;

  cartas1 = shuffle(deck);

  cartas2 = shuffle(deck);
  
  whatIs1 = check(cartas1);
  whatIs2 = check(cartas2);

  print(cartas1, cartas2);

  if (whatIs1 > whatIs2){
    cont1++;
    printf("El jugador 1 va %d puntos.\n", cont1);
  }else if (whatIs2> whatIs1){
    cont2++;
    printf("El jugador 2 va %d puntos.\n", cont2);
  }

  return cont1 >= cont2 ? cont1 : cont2;

}

void print(tCards * cartas1, tCards * cartas2){

  char * palito[] = {"Diamante", "Corazon", "Trebol", "Picas"};

  char *num[] = {"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "Jota", "Reina", "Rey"};

  for(int i=0; i<CHOSEN; i++)
    printf("%s de %s\n", num[cartas1[i].valor], palito[cartas1[i].palo]);

  puts("");

  for(int i=0; i<CHOSEN; i++)
    printf("%s de %s\n", num[cartas2[i].valor], palito[cartas2[i].palo]);




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

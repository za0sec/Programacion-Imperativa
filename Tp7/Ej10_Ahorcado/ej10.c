#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../libreria/random.h"
#define TRYS 6
#define MAX_WORDS 50
#define MAX_LETTERS 26

char * chooseWord(char * words[]);

int isLetter(char * chosenWord, char c, int active[], int * cont);

void updateBoard(char * chosenWord, int active[], int errors, int letters[]);

int play(char * chosenWord);

int main(){

  randomize();

  char * words[MAX_WORDS] = {"calefon", "suerte", "amigos", "persona", "ahorcado", "hipopotamo", "avion", "legumbres", "problemas", "programacion", "biblioteca", "algoritmo", "murcielago", "tiempo", "trabajo", "computadora", "inteligencia", "pelicula", "libro", "escritorio", "naranja", "banana", "telefono", "colegio", "facultad", "estudiante", "profesor", "ciudad", "campo", "rascacielos", "caramelo", "chocolate", "reloj", "guitarra", "piano", "automovil", "bicicleta", "avestruz", "elefante", "jirafa", "leopardo", "cocodrilo", "peligroso", "asombroso", "fantastico", "maravilloso", "excepcional", "increible", "extraordinario", "sillon"};

  char * chosenWord = chooseWord(words);

  play(chosenWord);

}

int play(char * chosenWord){

  int ganador = 0, cont = 0, errors = 0, c, t=0;

  int letters[MAX_LETTERS] = {0};


  int largo = strlen(chosenWord);

  int * active = calloc(largo, sizeof(int));

  updateBoard(chosenWord, active, errors, letters);

  while(errors != TRYS && !ganador){

    printf("Ingrese una letra: ");

    do{
      c = getchar();
    }while (!isalpha(c));

    letters[t++] = c;
    
    puts("");

    if ( !isLetter(chosenWord, c, active, &cont) )
      errors++;

    updateBoard(chosenWord, active, errors, letters);
  
    if (cont == largo){
      printf("\nFelicitaciones, la palabra era \"%s\" y la adivinaste!\n", chosenWord);
      ganador = 1;
    }else if (errors == TRYS){
      printf("Mala suerte! La palabra era \"%s\"\n", chosenWord);
    }
  } 

  free(active);

  return 0;

}




char * chooseWord(char * words[]){

  int i = randInt(0, MAX_WORDS-1);

  return words[i];

}

int isLetter(char * chosenWord, char c, int active[], int * cont){
 
  int this = 0;

  for(int i=0; chosenWord[i]; i++){
    if (chosenWord[i] == c && !active[i]){
        active[i] = 1;
        (*cont)++;
        this = 1;
      }
    }

  return this;

}

void updateBoard(char * chosenWord, int active[], int errors, int letters[]){

  printf("     _______\t\tLetras utilizadas: ");
  
  for(int i=0; i<MAX_LETTERS; i++){
    if ( letters[i] )
      printf("%c ", letters[i]);
  }

  if (errors == 0)
    printf("\n    |/      |\n    |\n    |\n    |\n    |\n    |\n   _|_\t");
  else if (errors == 1)
    printf("\n    |/      |\n    |      (_)\n    |\n    |\n    |\n    |\n   _|_\t");
  else if (errors == 2)
    printf("\n    |/      |\n    |      (_)\n    |       |\n    |       |\n    |\n    |\n   _|_\t");
  else if (errors == 3)
    printf("\n    |/      |\n    |      (_)\n    |      /|\n    |       |\n    |\n    |\n   _|_\t");
  else if (errors == 4)
    printf("\n    |/      |\n    |      (_)\n    |      /|\\ \n    |       |\n    |\n    |\n   _|_\t");
  else if (errors == 5)
    printf("\n    |/      |\n    |      (_)\n    |      /|\\ \n    |       |\n    |      /\n    |\n   _|_\t");
  else if (errors == 6)
    printf("\n    |/      |\n    |      (_)\n    |      /|\\ \n    |       |\n    |      / \\ \n    |\n   _|_\t");
  



  for (int i=0; chosenWord[i]; i++){
    if (active[i])
      printf(" %c", chosenWord[i]);
    else
      printf(" _");
  }


  puts("\n");

}

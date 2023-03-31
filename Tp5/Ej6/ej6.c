#include <stdio.h>
#include "../../libreria/getnum.h"
#define DIFFMAY 'a'-'A'
#define DIFFCIRC 'z'-'a'

int toUp(int character){
  
  if (  )
  return character -= DIFFMAY;
  
}

int toLow(int character){

  return character += DIFFMAY;

}

int nextCharacter(int character){

  return character += 1;

}

int nextLetter(int character){

  if ( character == 'z' || character == 'Z' ){

    return character -= DIFFCIRC;

  }else{

   return character += 1;

  }

}

int options(){

  int selection;

  do{
    selection = getint("\nSeleccione una de las siguientes opciones:\n\n-Convertir de mayúscula a minúscula (1).\
    \n-Convertir de minúscula a mayúscula (2).\n-Imprimir el carácter siguiente (3).\
    \n-Imprimir la siguiente letra en forma circular (4)\n");

  }
  while (selection != 1 && selection != 2 && selection != 3 && selection != 4);


  return selection;

}



int main(){

  printf("Ingrese un caracter: ");
  int character = getchar();

  int selection = options();

   if ( selection == 1 && (character <='Z' && character >= 'A')){

    printf("Tu caracter es: %c\n", toLow(character));

  }else if ( selection == 2 && (character <='z' && character >= 'a') ){
    
    printf("Tu caracter es: %c\n", toUp(character));

  }else if ( selection == 3 ){
    
    printf("Tu caracter es: %c\n", nextCharacter(character));

  }else if ( selection == 4 && ((character <='z' && character >= 'a') || (character <='Z' && character >= 'A') )){

    printf("Tu caracter es: %c\n", nextLetter(character));

  }else{

    puts("Opcion Incorrecta");

  }

  return 0;
  
}


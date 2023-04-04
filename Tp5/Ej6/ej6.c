#include <stdio.h>
#include "../../libreria/getnum.h"
#define DIFFMAY 'a'-'A'
#define DIFFCIRC 'z'-'a'

int toUp(int ch){
  
  if ( ch <= 'z' && ch >= 'a' ){
  
    return ch -= DIFFMAY;
  
  }else{
    
    return ch;
     

  }
}

int toLow(int ch){

  if ( ch <='Z' && ch >= 'A' ){

    return ch += DIFFMAY;
  
  }else{

    return ch;
    

  }

}

int nextCharacter(int ch){

  return ch += 1;

}

int nextLetter(int ch){

  if ( ch == 'z' || ch == 'Z' ){

    return ch -= DIFFCIRC;

  }

   return ( (ch < 'z' && ch >= 'a') || (ch < 'Z' && ch >= 'A') ) ? ch += 1 : ch;


}

int options(){

    
    int selection = getint("\nSeleccione una de las siguientes opciones:\n\n-Convertir de mayúscula a minúscula (1).\
    \n-Convertir de minúscula a mayúscula (2).\n-Imprimir el carácter siguiente (3).\
    \n-Imprimir la siguiente letra en forma circular (4)\n");




  return selection;

}


int main(){

  printf("Ingrese un caracter: ");
  int character = getchar();

  int selection = options();

  switch (selection) {
    case 1:
      printf("%c\n",toLow(character));
      break;
    case 2:
      printf("%c\n",toUp(character));
      break;
    case 3:
      printf("%c\n",nextCharacter(character));
      break;
    case 4:
      printf("%c\n",nextLetter(character));
  }
  
  return 0;
  
}


#include <stdio.h>

int toUp(int character){

  return character -= ' ';
  
}

int toLow(int character){

  return character += ' ';

}

int nextCharacter(int character){

  return character += 1;

}

int nextLetter(int character){

  if ( character == 'z' || character == 'Z' ){

    return character -= 25;

  }else{

   return character += 1;

  }

}



int main(){

  printf("Ingrese un caracter: ");
  int character = getchar(), selection = getchar();
  

  do{
    printf("\nSeleccione una de las siguientes opciones:\n\n-Convertir de mayúscula a minúscula (a).\
    \n-Convertir de minúscula a mayúscula (b).\n-Imprimir el carácter siguiente (c).\
    \n-Imprimir la siguiente letra en forma circular (d)\n");
    selection = getchar();

  }
  while (selection != 'a' && selection != 'b' && selection != 'c' && selection != 'd');

  if ( selection == 'a' ){

    printf("Tu caracter es: %c\n", toLow(character));

  }else if ( selection == 'b' ){
    
    printf("Tu caracter es: %c\n", toUp(character));

  }else if ( selection == 'c' ){
    
    printf("Tu caracter es: %c\n", nextCharacter(character));

  }else{

    printf("Tu caracter es: %c\n", nextLetter(character));

  }

  return 0;
}

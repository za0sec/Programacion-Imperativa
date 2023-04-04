#include <stdio.h>
#include <ctype.h>


int main(){


  int a,b,c;
  a = getchar();
  b = getchar();
  c = getchar();

  if ( isupper(a) && (a != 'A' && a != 'E' && a != 'I' && a != 'O' && a != 'U') ){

    printf("El caracter %c es una consonante mayúscula \n", a);

  }else {

    if ( islower(a) && (a != 'a' && a != 'e' && a != 'i' && a != 'o' && a != 'u') ){

      printf("El caracter %c es una consonante minúscula \n", a);

    }else{

      int a2 = toupper(a);

      if (  a2 == 'A' || a2 == 'E' || a2 == 'I' || a2 == 'O' || a2 == 'U' ){

        printf("El caracter %c es una vocal \n", a);

      }else{

        printf("El caracter %c no es una letra \n", a);

      }

    }

  }

  if (b%2 == 0){

    printf("El valor ASCII de %c es par \n", b);

  }

  if ( (isdigit(b))%2 == 0 ){

    printf("El caracter %c representa un dígito par \n", b);

  }

  int c2 = toupper(c);

  if ( isupper(c) || c2 == 'A' || c2 == 'E' || c2 == 'I' || c2 == 'O' || c2 == 'U' ){

    printf("El caracter %c es una vocal o es mayúscula \n", c);

  }

  if ( !isalpha(c) && (c2 == 'A' || c2 == 'E' || c2 == 'I' || c2 == 'O' || c2 == 'U') ){

    printf("El caracter %c no es una vocal pero es letra \n", c);


  }


}

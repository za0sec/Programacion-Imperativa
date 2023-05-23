/*
  Escribir una función que reciba como parámetro de entrada un string 
  y retorne 1 si el mismo es palíndromo y 0 en caso contrario. 
  Resolver el problema en forma recursiva
*/

#include <stdio.h>
#include <string.h>

int esPalindromo(const char* s);

int esPalindromoRec(const char * s, int dim);

int main(){


  char * s = "HoalaloaH";
  

  printf("%d\n", esPalindromo(s));

}


int esPalindromo(const char* s) {
    
  if (s == NULL)
    return 1;
    
  int dim = strlen(s);
    
  return esPalindromoRec(s, dim);
}

int esPalindromoRec(const char * s, int dim){

  if (dim == 1)
    return 1;

  if (s[0] != s[dim-1] )
    return 0;


  return esPalindromoRec(s+1, dim-2);

}

/*
  Escribir una función que reciba como parámetro de entrada un string 
  y retorne 1 si el mismo es palíndromo y 0 en caso contrario. 
  Resolver el problema en forma recursiva
*/

#include <stdio.h>
#include <string.h>

int esPalindromo(const char* s);

int esPalindromoRec(const char * s, int dim);

#include <assert.h>


int main(void) {

  assert(esPalindromo("a")==1);
  assert(esPalindromo("")==1);
  assert(esPalindromo("neuquen")==1);
  assert(esPalindromo("abba")==1);
  assert(esPalindromo("12345654321")==1);

  assert(esPalindromo("abab")==0);
  assert(esPalindromo("123456")==0);
  

  printf ("OK!\n");
  return 0;
}


int esPalindromo(const char* s) {
 
  if (!(*s))
    return 1;

  if (s == NULL)
    return 1;
    
  int dim = strlen(s);
    
  return esPalindromoRec(s, dim);
}

int esPalindromoRec(const char * s, int dim){

  if (dim <= 1)
    return 1;

  if (s[0] != s[dim-1] )
    return 0;


  return esPalindromoRec(s+1, dim-2);

}

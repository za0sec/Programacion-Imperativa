#include <stdio.h>
#include <ctype.h>
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

int countStr(char * s, int * words, int * longestW);


int main(){


  int words, longestW;

  char str[] = "hola que tal javito como andas, la verdad que yo muy bien por suerte!!";
  
  printf("%d\n", countStr(str, &words, &longestW));
  
  printf("La palabra mas larga tenia %d letras\nLa cantidad de palabras era %d", longestW, words);
  
  
}



int countStr(char * s, int * words, int * longestW){

  *words = 0;
  *longestW = 0;

  int count = 1, i;
    
  for (i=0; s[i]; i++){

    int a = s[i];
    int n = s[i+1];

    if (isalpha(a) && !isalpha(n))
      (*words)++;
  
    if (isalpha(a) && isalpha(n))
      count++;
    else
      count = 1;

    *longestW = MAX(*longestW, count);

  }



  return i;




}

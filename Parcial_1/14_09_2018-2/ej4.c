#include <stdio.h>

#define MAX_CHAR 256


void elimina(char * s1, const char * s2);

int main(){

  char s[] = "Un string. Con diversas letras y simbolos!!";

  elimina(s,"aeiou");
  printf("%s", s);
  elimina(s, "!.");
  printf("%s", s);
  elimina(s, "aeiou");
  printf("%s", s);

  return 0;
}


void elimina(char * s1, const char * s2){

  int vecAp[MAX_CHAR] = {0};

  for (int i=0; s2[i]; i++)
    vecAp[s2[i]] = 1;

  int t=0;

  for (int i=0; s1[i]; i++){

    if (!vecAp[s1[i]])
      s1[t++] = s1[i];
  }


  s1[t] = '\0'; 

}

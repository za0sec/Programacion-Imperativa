#include <stdio.h>
#include <ctype.h>


#define LETRAS ('Z' - 'A' + 1)

void letras (const char * s1, char * s2);


int main(){


  char s[LETRAS + 1];

  letras("1x234zxz56 ()0x", s);

  printf("%s", s);    



}




void letras (const char * s1, char * s2){

  int vecAp[26] = {0}; 

  for (int i=0; s1[i]; i++){

    if (isalpha(s1[i])){
      int c = toupper(s1[i]);
      vecAp[c-'A'] = 1;
    }

  }

  int t=0;

  for (int i=0; i<26; i++){

    if (vecAp[i])
      s2[t++] = i + 'A';

  }

  s2[t] = '\0'; 



}


#include <stdio.h>

#define MAX_CHAR 256

void elimina(char * s);

int main(){


  char s[] = "abcbc.cba";
  elimina(s); // s es ahora ".cba"
  printf("%s\n", s);
  char t[] = "123456654321";
  elimina(t); // t es ahora "654321"
  printf("%s\n", t);
  elimina(t); // t no cambia
  printf("%s\n", t);
  char u[] = "Abc123aBC";
  elimina(u); // u no cambia
  printf("%s\n", u);




}


void elimina(char * s){

  int vecAp[MAX_CHAR] = {0};  

  for (int i=0; s[i]; i++)
    vecAp[s[i]]++;

  int t=0;

  for (int i=0; s[i]; i++){

    if (vecAp[s[i]] > 1){
      vecAp[s[i]]--;
    }else if (vecAp[s[i]] == 1){

      s[t++] = s[i];

    }
  }

  s[t] = '\0';

}

#include <stdio.h>

void elim(char * s1, char * s2) ;

int main(){

  char s1[] = "Hello";
  char s2[] = "World!";


  elim(s1, s2);

  printf("%s\n", s1);
  printf("%s\n", s2);

}



void elim(char * s1, char * s2){

  int t=0, p=0, i=0, l=0;

  while (s1[i] != '\0' || s2[l] != '\0'){
    
    if (s1[i] != s2[l]){
      if (s1[i] != '\0')
        s1[t++] = s1[i];
      if (s2[l] != '\0')
        s2[p++] = s2[l];
    }
    
    if (s2[l] != '\0')
      l++;
    if (s1[i] != '\0')
      i++;
  }

  s1[t] = '\0';
  s2[p] = '\0';

}

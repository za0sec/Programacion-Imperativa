#include <stdio.h>
#include <ctype.h>

void supCharacter(char * s1, const char * s2);


int main(){

  char s1[] = "habia una vez un pez";
  const char s2[] = "al que madruga dios le ayuda";

  supCharacter(s1, s2);
  
  printf("%s", s1);

}


void supCharacter(char * s1, const char * s2){


  char c = toupper(s2[0]);

  int t=0;

  for (int i=0; s1[i] != '\0'; i++){

    if (toupper(s1[i]) != c){
      s1[t++] = s1[i];
    }

  }


  s1[t] = '\0';

}

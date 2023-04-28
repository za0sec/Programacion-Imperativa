#include <stdio.h>

void normalizar(char * s);

int main(){



  char s[] = "12.33,3.43,1.00,5.00,7.1";

  normalizar(s);

  printf("%s", s);



}

void normalizar(char * s){

  char c = '.';
  int t=0, i=0, band=0;

  while (s[i] != '\0'){

    if (c == s[i]){
      s[t++] = s[i];
      i++;

      for(int j=0;s[i] != ',' && s[i] != '\0'; j++){
        if (j<2)
          s[t++] = s[i];
        
        i++;
        
      }

    }else{
      s[t++] = s[i];
    }

    if (s[i] == ',')
      s[t++] = s[i];

    i++;

  }

  s[t] = '\0';

}

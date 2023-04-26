#include <stdio.h>
#include <ctype.h>


void eliminaN(char * s, char l, int n);


int main(){

  char s[] = "La calle esta dura";
  char letra = 'l';
  int n = 3;

  eliminaN(s, letra, n);
  printf("%s", s);

}

void eliminaN(char * s, char l, int n){
  
  int t=0, i=0, band=0;

  while ( s[i] != '\0' ){
  
    
    char c = toupper(s[i]);
    l = toupper(l);

    if (c == l){
      for (int j=0; j<=n; j++){
        i++;
        band=1;
      }
    }else{
      s[t++] = s[i];
    }
     if (!band)
      i++;
    
    band=0;
   
  }
 
  s[t] = '\0';

}

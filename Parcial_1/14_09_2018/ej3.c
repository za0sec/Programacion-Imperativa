#include <stdio.h>


void elimina(char * s, const char * c);


int main(){

  char s[] = "Un string. Con diversas letras y simbolos!!";
  elimina(s, "aeiou"); // s es ahora "Un strng. Cn dvrss ltrs y smbls!!"
  printf("%s\n", s);
  elimina(s, " !."); // s es ahora "UnstrngCndvrssltrsysmbls"
  printf("%s\n", s);
  elimina(s, "aeiou");
  printf("%s\n", s);




}



void elimina(char * s, const char * c){

  int t, i, j, band; 

  for (i=0, t=0; s[i]!='\0'; i++){

    band=0;


    for(j=0; c[j] != '\0'; j++){

      if(c[j] == s[i]){

          band=1;

        }   

    } 
    
    if (!band){

      s[t++] = s[i];

    }


  }

  s[t] = '\0';


}

/*Se desea eliminar de un texto todas las vocales, siempre y cuando no sean vocales "sueltas", 
 * esto es, para eliminarlas deben tener al menos una letra antes o una letra después (y que no sea vocal).
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int isVocal(char c);

void eliminaVoc(char * s);

int main(){

  char s[] = {"aholoaaa"};
  
  eliminaVoc(s);

  printf("%s", s);



if (i==0)
      modelo += f;

    sumFil += f;
    sumCol += c;
}

int isVocal(char c){

  static char vocales[] = "AEIOU";

  char * p = strchr(vocales, toupper(c));

  return p != NULL;

}



void eliminaVoc(char * s){

  char l = 'A';

  int t=0;

  for (int i=0; s[i] != '\0'; i++){

    char a= s[i];
    char n= s[i+1];
  

    if ( !(isVocal(a) && ( ( (isalpha(n) && !isVocal(n) ) ) || ( isalpha(l) && !isVocal(l))) )  )
        s[t++] = s[i]; 
    
    l = a;
    
  }


  s[t] = '\0';


}

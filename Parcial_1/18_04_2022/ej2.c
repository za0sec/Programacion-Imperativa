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



}

int isVocal(char c){

  char vocales[] = {"AEIOU"};

  char * p = strchr(vocales, c);

  if (p == NULL)
    return 0;

  return 1;

}



void eliminaVoc(char * s){

  char l;

  int t=0;

  for (int i=0; s[i] != '\0'; i++){

    char a= toupper(s[i]);
    char n= toupper(s[i+1]);
  
    
    if(i==0){
      l = 'A'; 
    }

    if (isVocal(a) && ( ( (isalpha(n) && !isVocal(n) ) ) || ( isalpha(l) && !isVocal(l)) )  ){
        s[t] = s[i]; 
    }else{
      s[t++] = s[i];
    }
    
    l = a;
    
  }


  s[t] = '\0';


}
